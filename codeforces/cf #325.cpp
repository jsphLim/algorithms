#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int vis[1000005];
int prime[80000];
ll prime2[80000];
int nprime;

void getprime(){
    nprime = 0;
    memset(vis,0,sizeof(vis));
    for(int i = 2; i <= 1000000; i++){
        int t = 1000000/i;
        for(int j = 2; j <=t; j++)
            vis[i*j] = 1;
    }
    for(int i = 2; i <= 1000000; i++){
        if(!vis[i]){
            prime[nprime] = i;
            prime2[nprime++] = (ll)i*i;
        }
    }
}

int main(){
    getprime();
    //cout<<nprime<<endl;
    ll n;
    while(~scanf("%lld",&n)){
        for(int i = 0; i < nprime; i++){
            if(n % prime2[i] == 0){
                while(n % prime2[i] == 0)
                    n /= prime[i];
            }
        }
        printf("%lld\n",n);
    }
    return 0;
}

