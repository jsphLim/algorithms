#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
int a[1000010];
int main()
{
	int P,i,n;
	while(scanf("%d",&P)!=EOF)
	{
		set<int>s;
		for(i=0;i<P;++i)
		{
			scanf("%d",&a[i]);
			s.insert(a[i]);
		}
		n=s.size();//记录知识点的个数 
		int start=0,end=0,num=0,ans=P;
		map<int,int>mp;//对应每个知识点出现的次数 
		while(1)
		{
			while(end<P&&num<n)
			{
				if(mp[a[end]]==0)
					num++;
				mp[a[end]]++;
				end++;
			}
			if(num<n)
				break;
			ans=min(ans,end-start);
			if(--mp[a[start]]==0)//有一个知识点出现的次数为0了，就是减少了一个知识点 
				num--;
			start++;
		}
		printf("%d\n",ans);
	}
	return 0;
}