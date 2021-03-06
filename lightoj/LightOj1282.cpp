#include<stdio.h>  
#include<math.h>  
#define ll long long 
ll Mod(ll a,ll b,ll mod) { //快速幂算法  
    ll ans=1;  
    if(!b)      return 1;  
    ans=Mod(a*a%mod,b/2,mod);  
    if(b&1)     ans=ans*a%mod;  
    return ans;  
}  
  
int main() {  
    int t,cont=0;  
    scanf("%d",&t);  
    while(t--){  
        ll n,k;  
        scanf("%lld%lld",&n,&k);  
        int strat=(int)pow(10.0,2.0+fmod(k*log10(n*1.0),1.0));//前三位  
        int end=(int)Mod(n,k,1000);//后三位  
        printf("Case %d: %d %lld\n",++cont,strat,end);// ll 输出就溢出！   
    }//忽略了后三位的首位是 0 的情况  
    return 0;  
}  
