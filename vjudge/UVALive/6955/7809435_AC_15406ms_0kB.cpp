#include<bits/stdc++.h>
using namespace std;
const int N=100000+10;
int x[N],y[N];
bool check(int a,int b,int c){
  return (x[b]-x[a])*(y[c]-y[a])==(y[b]-y[a])*(x[c]-x[a]);
}

int main(){
    int n,p;
    while(~scanf("%d%d",&n,&p)){
        int ans=n*p;
        for(int i=0;i<n;i++){
            scanf("%d%d",&x[i],&y[i]);
        }
        if(n<=2){
            printf("possible\n");
            continue;
        }
        srand(time(0));
        int ok=0;
        for(int i=1;i<10000;i++){
            int u=rand()%n,v=rand()%n,cnt=2;
            while(v==u) v=rand()%n;
            for(int j=0;j<n;j++){
                if(j!=v&&j!=u&&check(u,v,j)) cnt++;
            }
            if(cnt*100>=ans) {ok=1;break;}
        }
        printf("%s\n",ok==1?"possible":"impossible");
    }
}