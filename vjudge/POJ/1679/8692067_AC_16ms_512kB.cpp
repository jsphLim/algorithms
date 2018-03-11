#include<cstdio>  
#include<algorithm>  
#include<cstring>  
using namespace std;  
int n,m;  
struct node{  
    int x,y,w;  
};  
node s[10100];//读入的数组   
int fa[110],ss[110][110];//fa是并查集 ss是最小生成树中任意两点之间经过的路径的边的最大值   
bool p[10100];//p[i]判断第i条边是否在最小生成树内   
bool cmp(node x,node y){  
    return x.w<=y.w;  
}  
int dfs(int h){  
    if(fa[h]==h)return h;//并查集   
    return fa[h]=dfs(fa[h]);//路径压缩   
}  
int main(){  
    int i,j,k,t,r;  
    scanf("%d",&t);  
    for(k=1;k<=t;k++){  
        scanf("%d%d",&n,&m);  
        int ans=0;  
        memset(p,0,sizeof(p));  
        for(i=1;i<=n;i++){  
            for(j=1;j<=n;j++){  
                ss[i][j]=999999999;  
            }  
            ss[i][i]=0;  
        }//一开始将任意两点之间的边的最大距离设为无限大 自己与自己的最大距离为0   
        for(i=1;i<=m;i++){  
            scanf("%d%d%d",&s[i].x,&s[i].y,&s[i].w);  
        }  
        sort(s+1,s+m+1,cmp);  
        for(i=1;i<=n;i++)fa[i]=i;//未连边之前 每个点都是一个独立的集合   
        int f=1;  
        for(i=0;i<n-1;f++){//一共有n个点 所以需要连接n-1条边 循环n-1次 f指现在搜索到第f条边了   
            if(dfs(s[f].x)!=dfs(s[f].y)){  
                fa[dfs(s[f].x)]=s[f].y;  
                ans+=s[f].w;  
                ss[s[f].x][s[f].y]=s[f].w;//更新第f条边连接的两个点之间的距离   
                ss[s[f].y][s[f].x]=s[f].w;  
                p[f]=1;  
                i++;  
            }  
        }//之前基本就是KRUSCAL   
        for(r=1;r<=n;r++){//思想类似与floyd 不会的看我博客   
            for(i=1;i<=n;i++){  
                for(j=1;j<=n;j++){  
                    if(ss[i][j]==999999999 && ss[i][r]<999999999 && ss[j][r]<999999999 && i!=j){//一定要判断ss[i][j] 不然会被多余的替换 第一次替换的肯定是正确值 之后还会继续替换 越来越大 一开始就wa在这里了   
                        ss[i][j]=max(ss[i][r],ss[j][r]);  
                    }  
                }  
            }  
        }//这里用的爆搜是O（n^3） 貌似可以用LCA优化到O(n)今天困了没写 想学的看我博客  
        for(i=1;i<=m;i++){  
            if(!p[i] && ss[s[i].x][s[i].y]==s[i].w){  
                printf("Not Unique!\n");  
                ans=-1;  
                break;  
            }  
        }  
        if(ans==-1)continue;  
        printf("%d\n",ans);  
    }  
    return 0;  
}  