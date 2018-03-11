#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		long n,a,b,c;
		scanf("%ld%ld%ld%ld",&n,&a,&b,&c);
		n=4-(n%4);
		long min=0;
		switch(n){
			case 1:
					min=a<(b+c)?a:(b+c);
					min=3*c<min?3*c:min;
					break;
			case 2:
					min=b<2*a?b:2*a;
					min=2*c<min?2*c:min;
					break;
			case 3:
					min=c<(a+b)?c:(a+b);
					min=(3*a)<min?(3*a):min;
					break;
		}
		printf("%ld\n",min);
	}
}
