#include<cstdio>  
#include<cstdlib>  
#include<cstring>  
#include<algorithm>  
#include<cmath>  
#define inf 0x3f3f3f3f  
using namespace std;  
const int maxn=110;  
int map[maxn][maxn];  
void floyd(int n){  
    for(int k=1;k<=n;++k){  
        for(int i=1;i<=n;++i){  
            for(int j=1;j<=n;++j){  
                map[i][j]=min(map[i][j],map[i][k]+map[k][j]);  
            }  
        }  
    }  
}  
int main()  
{  
    int a,b,n,i,j,k,m;  
    while(scanf("%d%d%d",&n,&a,&b)!=EOF){  
        memset(map,0x3f,sizeof(map));  
        for(int i=1;i<=n;++i){  
            scanf("%d",&k);  
            int falg=1;  
            while(k--){  
                scanf("%d",&m);  
                if(falg)map[i][m]=0;  
                else map[i][m]=1;  
                falg=0;  
            }  
        }  
        floyd(n);  
        if(map[a][b]<inf){  
            printf("%d\n",map[a][b]);  
        }  
        else {  
            printf("-1\n");  
        }  
    }  
    return 0;  
}  
