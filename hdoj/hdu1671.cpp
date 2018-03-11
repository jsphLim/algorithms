#include<bits/stdc++.h>
using namespace std;
const int MAX=10;
struct Trie   
{   
    Trie *next[MAX];   
    int v;   //������Ҫ�仯
};   
 
Trie *root;
void createTrie(char *str)
{
    int len = strlen(str);
    Trie *p = root, *q;
    for(int i=0; i<len; ++i)
    {
        int id = str[i]-'0';
        if(p->next[id] == NULL)
        {
            q = (Trie *)malloc(sizeof(Trie));
            q->v = 1;    //��ʼv==1
            for(int j=0; j<MAX; ++j)
                q->next[j] = NULL;
            p->next[id] = q;
            p = p->next[id];
        }
        else
        {
            p->next[id]->v++;
            p = p->next[id];
        }
    }
    p->v = -1;   //��Ϊ��β����v�ĳ�-1��ʾ
}
int findTrie(char *str)
{
    int len = strlen(str);
    Trie *p = root;
    for(int i=0; i<len; ++i)
    {
        int id = str[i]-'0';
        p = p->next[id];
        if(p == NULL)   //��Ϊ�ռ�����ʾ�����Դ�Ϊǰ׺�Ĵ�
            return 0;
        if(p->v == -1)   //�ַ��������д��Ǵ˴���ǰ׺
            return -1;
    }
    return -1;   //�˴����ַ�����ĳ����ǰ׺
}
int dealTrie(Trie* T)
{
    int i;
    if(T==NULL)
        return 0;
    for(i=0;i<MAX;i++)
    {
        if(T->next[i]!=NULL)
            dealTrie(T->next[i]);
    }
    free(T);
    return 0;
}
int main(){
	int t,n;
	cin>>t;
	while(t--){
		scanf("%d",&n);
		root = (Trie *) malloc (sizeof(Trie));
        for(int i=0; i<10; ++i)
        root->next[i] = NULL;
		int flag=0;
		char a[15];
		for(int i=1;i<=n;i++) {
		scanf("%s",a);
		if(findTrie(a)==-1){flag=1;}
		createTrie(a);
	}

	if(flag) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	dealTrie(root);
}
}
		 
