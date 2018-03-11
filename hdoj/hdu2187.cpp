#include<stdio.h>
int arr[1000];
int brr[1000];
int main(){
	int t;
	scanf("%d",&t);
	int m,n;
	int i,j;
	double ans=0;
	while(t--){
		scanf("%d%d",&m,&n);
		for(i=0;i<n;i++){
			scanf("%d",&arr[i]);
			scanf("%d",&brr[i]);
		}
		for(i=0;i<n;i++)
		for(j=0;j<n-i-1;j++){
			if(arr[i]>arr[i+1]){
				
				int t=arr[i];
				arr[i+1]=arr[i];
				arr[i+1]=t;
				t=brr[i];
				brr[i+1]=brr[i];
				brr[i+1]=t;
			}
		}
		
	    ans=0;
		for(i=0;i<n;i++){
			while(m-arr[i]>=arr[i]&&brr[i]>0){
				m=m-arr[i];
				ans++;
				brr[i]--;
			}
			
		}
					if(m>0)
					ans=ans+1.0*m/arr[n-1];
                     printf("%.2f",ans);
                 
             
    }
}
			
		


