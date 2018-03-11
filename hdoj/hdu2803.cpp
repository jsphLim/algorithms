#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a[105];
    int n;
    while(cin>>n,n)
    {
    	for(int i=0;i<n;i++) cin>>a[i];
    	sort(a,a+n);
		cout<<a[n-1]*(2010-n)+accumulate(a,a+n-1,0)<<endl;
	}
}
