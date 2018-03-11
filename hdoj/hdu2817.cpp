#include<iostream>
using namespace std;
const int N=200907;
long long fun(long long a,long long b)
{
    long long res=1;
    a%=N;
    while(b)
    {
        if(b&1)
            res=res*a%N;
        a=a*a%N;
        b>>=1;
    }
    return res%N;
}
int main(){
	int t;
	long long a,b,c,f;
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&f);
		if(a==b &&b==c )
        {
            cout<<a%N<<endl;
            continue;
        }
		if(b-a==c-b){
			int d=b-a;
			if(f==1) cout<<a%N<<endl;
			else if(f==2) cout<<b%N<<endl;
			else if(f==3) cout<<c%N<<endl;
			else{
			cout<<(a+(f-1)*d)%N<<endl;
		}
	}
		else{
			
				if(f==1) cout<<a%N<<endl;
			else if(f==2) cout<<b%N<<endl;
			else if(f==3) cout<<c%N<<endl;
			else{
			long long p=b/a;
				cout<<(a%N*fun(p,f-1))%N<<endl;
			}
		}
	}
}
