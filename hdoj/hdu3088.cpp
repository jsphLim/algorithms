#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
string ch;
int l;
struct Node
{
    string s;
    int step;
    friend bool operator <(Node a, Node b)
    {
        return a.step>b.step;
    }
};
void BFS()
{
    priority_queue<Node> Q;
	map<string,int> my;
    Node p,q;
    int i,k,flag;
	p.s=ch;
    p.step=0;
    Q.push(p);
    while(!Q.empty())
    {
        p=Q.top();
        Q.pop();
		if(my[p.s])
		{
			continue;
		}
		my[p.s]=1;
		flag=0;
		for(i=1;i<l;i++)
		{
			if(p.s[i]!=p.s[i-1])
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			printf("%d\n",p.step);
			return ;
		}

        for(k=1;k<l;k++)
        {
			q.s=p.s;
			q.step=p.step;
			if(q.s[k]!=q.s[k-1])
			{
				if(q.s[k]=='r'&&q.s[k-1]=='b'||(q.s[k-1]=='r'&&q.s[k]=='b'))
				{
					q.s[k]='g';
					q.s[k-1]='g';
				}
				else if(q.s[k]=='r'&&q.s[k-1]=='g'||(q.s[k-1]=='r'&&q.s[k]=='g'))
				{
					q.s[k]='b';
					q.s[k-1]='b';
				}
				else
				{
					q.s[k]='r';
					q.s[k-1]='r';
				}
				q.step++;
				Q.push(q);
			}	
        }
    }
    printf("No solution!\n");
}
int main()
{
    int i,j;
    int T;
    scanf("%d",&T);
    while(T--)
    {
		cin>>ch;
		l=ch.length();

        BFS();
    }
    return 0;
}
