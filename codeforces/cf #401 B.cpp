#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;

char a[N], b[N];

int main ()
{
	int n, i;
	scanf("%d %s %s", &n, a, b);
	sort(a, a+n); sort(b, b+n);
	i = 0;
	for(int j = 0; j < n; j++){
		if(b[j] >= a[i])
			i++;
	}
	printf("%d\n", n-i);
	
	i = 0;
	for(int j = 0; j < n; j++){
		if(b[j] > a[i])
			i++;
	}
	printf("%d\n", i);
	
	return 0;
}
