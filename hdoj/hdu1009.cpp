#include<stdio.h>
double a[1000];
double b[1000];
double c[1000];
int main()
{
    int N;
    double M;
    double ans;
    while(scanf("%lf%d",&M,&N))
    {
        if(M==-1&&N==-1) break;
        for(int i=0;i<N;i++)
        {
           scanf("%lf%lf",&a[i],&b[i]);
           c[i]=a[i]/b[i];
        }    
        for(int i=0;i<N;i++){
        	for(int j=0;j<N-i-1;j++){
        		if(c[j]<c[j+1]){
        			double t=c[j];
        			c[j]=c[j+1];
        			c[j+1]=t;
        	        t=a[j];
        			a[j]=a[j+1];
        			a[j+1]=t;
        			t=b[j];
        			b[j]=b[j+1];
        			b[j+1]=t;
				}
			}
		}
        ans=0;
        for(int i=0;i<N;i++)
        {
            if(M>=b[i])
            {
                ans=ans+a[i];
                M=M-b[i];
            }    
            else 
            {
                ans+=c[i]*M;
                break;
            }    
        }   
        printf("%.3lf\n",ans); 
    }    
    return 0;
}    
