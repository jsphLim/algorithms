/*************************************************************************
	> File Name: milkingTIme.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月20日 星期一 16时28分29秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
struct node{
    int begin;
    int end;
    int value;
};
bool cmp(node a,node b){
    if(a.begin==b.begin) return a.end<b.end;
    else return a.begin<b.begin;
}
node point[1005];
int dp[20000];
int main(){
    //freopen("1.txt","r",stdin);
    int n,m,d;
    while(cin>>n>>m>>d){
        for(int i=0;i<m;i++){
           scanf("%d%d%d",&point[i].begin,&point[i].end,&point[i].value);
            point[i].end+=d;
        }
        sort(point,point+m,cmp);
        memset(dp,0,sizeof(dp));

        for(int i=0;i<m;i++){
            dp[i]=point[i].value;
            for(int j=0;j<i;j++){
                if(point[i].begin>=point[j].end){
                    dp[i]=max(dp[i],dp[j]+point[i].value);
                }
            }
        }
        int ans=-11111111;
        for(int i=0;i<m;i++){
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
}
