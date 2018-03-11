/*#include<bits/stdc++.h>
using namespace std;
long long comb(long long x){
	long long ret=1;
	for(int i=2;i<=x;i++) ret*=i;
	return ret;
}
long long comb1(long long m,long long n){
	if(m==0||n==0) return 1;
    return comb(m)/comb(n)/comb(m-n); 	
} 
int main(){
	long long n,m,k,t;
	long long prime;
	long long sum;
	scanf("%lld",&t);
	while(t--){
		sum=1;
		scanf("%lld%lld%lld",&m,&n,&k);
		for(int i=0;i<k;i++){
			scanf("%lld",&prime);
			sum*=prime;
		}
		long long l=comb1(m/sum,n/sum)*comb1(m%sum,n%sum)%sum;
		cout<<l<<endl;
	}
}*/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<stack>
#include<vector>
#define LL long long
#define MAXN 1000010
using namespace std;
const  int N=20;//ģ������ 
LL a[N],mod[N];
LL mul(LL a,LL b,LL mod)//a*b%mod
{
	LL ans=0;
	while(b){
		if(b&1)
			ans=(ans+a)%mod;
		b>>=1;
		a=(a+a)%mod;
	}
	return ans;
}

LL quick_mod(LL a,LL b,LL m)//a^b%m 
{
	LL ans=1;
	a%=m;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a%m;
		}			
		b>>=1;
		a=a*a%m;
	}
	return ans;
}

LL getC(LL n,LL m,int cur)//C(n,m)%mod[cur]
{
	LL p=mod[cur];
	if(m>n)
		return 0;
	if(m>n-m)
		m=n-m;
	LL ans=1;
	for(int i=1;i<=m;i++)
	{
		LL a=(n+i-m)%p;
		LL b=i%p;
		//ans=mul(ans,mul(a,quick_mod(b,p-2,p),p),p);//pΪ������i��p����Ԫ���Բ�������ŷ����ý������  re=i^(P-2) 
		ans = ans * (a * quick_mod(b, p-2,p) % p) % p;  
	}
	return ans; 
}

LL Lucas(LL n,LL k,int cur)//��C(n,k)%mod[cur] 
{
	LL p=mod[cur];
	if(k==0)
		return 1%p;
	//return getC(n%p,k%p,cur)*Lucas(n/p,k/p,cur)%p;
	return getC(n % p, k % p,cur) * Lucas(n / p, k / p,cur) % p;  
}

void extend_Euclid(LL a,LL b,LL &x,LL &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return;
	}
	extend_Euclid(b,a%b,x,y);
	LL tmp=x;
	x=y;
	y=tmp-a/b*y;
}

LL CRT(LL a[],LL m[],int k)//��C(n,m)%M,����M=(m0*m2*��*m(k-1)),miΪ������������a[i]�洢ģ����C(n,m)%mi,
{                           //m[]�洢������������mi��k��ʾ�ܹ���k��ģ���̣�����C(n,m)%M��ֵ 
	LL M=1;
	LL ans=0;
	for(int i=0;i<k;i++)
		M*=mod[i];
	for(int i=0;i<k;i++)
	{
		LL x,y,tmp;
		LL Mi=M/m[i];
		extend_Euclid(Mi,m[i],x,y);
		if(x<0)
		{
			x=-x;
			tmp=mul(Mi,x,M);
			tmp=mul(tmp,a[i],M);
			tmp=-tmp;
		}
		else
		{
			tmp=mul(Mi,x,M);
			tmp=mul(tmp,a[i],M);
		}
		ans=(ans+tmp)%M;
	}
	while(ans<0)
		ans+=M;
	return ans;
}

int main()
{
	//freopen("D:\\in.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		LL n,m;
		int k;
		scanf("%lld%lld%d",&n,&m,&k);
		//k=1;
		for(int i=0;i<k;i++)
			scanf("%lld",&mod[i]);
		for(int i=0;i<k;i++)
			a[i]=Lucas(n,m,i)%mod[i];
		//printf("%I64d\n",a[0]);
		printf("%lld\n",CRT(a,mod,k)); 
	}
  	return 0;
}
