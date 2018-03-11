#include <bits/stdc++.h>
#define  N 100010
#define  INF 99999999999
using namespace std;
int n;
bool is_pr[N];
vector<int>vec;
void init() {
    vec.clear();
    memset(is_pr,0,sizeof is_pr);
    is_pr[0]=is_pr[1]=1;
    for(int i=2; i<N; i++) {
        if(!is_pr[i]) {
            vec.push_back(i);
            for(int j=i+i; j<N; j+=i)
                is_pr[j]=1;
        }
    }
}

int main() {
    int t;
    cin>>t;
    init();
    while(t--) {
        scanf("%d",&n);
        long long x;
        long long fmin=INF,smin=INF;
        for(int i=0; i<n; i++) {
            scanf("%lld",&x);
            for(int j=0; j<vec.size()&&x>=vec[j]; j++) {
                if(x==1)break;
                if(x%vec[j]==0) {
                    while(x%vec[j]==0) {
                        if(fmin>vec[j]) {
                            smin=fmin;
                            fmin=vec[j];
                        }
                        else if(smin>vec[j]) {
                            smin=vec[j];
                        }
                        x/=vec[j];
                    }
                }
            }
            if(x!=1) {
                if(fmin>x) {
                    smin=fmin;
                    fmin=x;
                } else if(smin>x) {
                    smin=x;
                }
            }
        }
        //cout<<fmin<<' '<<smin<<endl;
        if(smin==INF)printf("-1\n");
        else printf("%lld\n",fmin*smin);
    }
    return 0;
}

