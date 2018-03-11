#include<bits/stdc++.h>
using namespace std;
bool visit[100005];
int prime[100010];        
int num = 0;
void getprime(int n)
    {
        memset(visit, false, sizeof(visit));

        for (int i = 2; i <= n; ++i)
        {
            if ( !visit[i] )  prime[num++] = i;
            for (int j = 0; j <= num && i * prime[j] <= n ;  j++)
            {
                visit[ i  *  prime[j] ]  =  true;
                if (i % prime[j] == 0) break;
    }
}
}
int main(){
	getprime(10050);
	int m,a,b;
	int t,pp,qq;
		while(scanf("%d%d%d",&m,&a,&b)&&(a+b+m)){
		int MIN=99999999;
	for(int i=num-1;i>=0;i--)
		for(int j=i;j>=0;j--){
			if(prime[i]*prime[j]>m||(double)a/b>1.0*prime[j]/prime[i]) continue;
			if(abs(m-prime[i]*prime[j])<MIN){
				qq=prime[i];
				pp=prime[j];
				MIN=m-prime[j]*prime[i];
			//	cout<<MIN<<" ";
			}
		}
		cout<<min(pp,qq)<<" "<<max(qq,pp)<<endl;
	}
	
}
