#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int N=8010;

int num[4],money[4]={0,1,2,5};
int c1[N],c2[N];

int main(){
    while(~scanf("%d%d%d",&num[1],&num[2],&num[3])){
        if(num[1]==0 && num[2]==0 && num[3]==0)
            break;
        for(int i=0;i<N;i++){
            c1[i]=0;
            c2[i]=0;
        }
        c1[0]=1;
        int maxx=0;
        for(int i=1;i<=3;i++){
            maxx+=num[i]*money[i];
            for(int j=0;j<=maxx;j++)
                for(int k=0;k<=num[i] && j+k*money[i]<=maxx;k++)
                    c2[j+k*money[i]]+=c1[j];
            for(int j=0;j<=maxx;j++){
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        for(int i=1;;i++)
            if(c1[i]==0){
                printf("%d\n",i);
                break;
            }
    }
    return 0;
}
