#include<bits/stdc++.h>
using namespace std;
const int MAX=27;
struct Trie {
	Trie *next[MAX];
	int v; //根据需要变化
};
Trie *root;
void createTrie(char *str) {
	int len = strlen(str);
	Trie *p = root, *q;
	for(int i=0; i<len; ++i) {
		int id = str[i]-'a';
		if(p->next[id] == NULL) {
			q = (Trie *)malloc(sizeof(Trie));
			q->v = 1; //初始v==1
			for(int j=0; j<MAX; ++j)
				q->next[j] = NULL;
			p->next[id] = q;
			p = p->next[id];
		} else {
			p->next[id]->v++;
			p = p->next[id];
		}
	}
}
int findTrie(char *str) {
	int len = strlen(str);
	Trie *p = root;
	for(int i=0; i<len; ++i) {
		int id = str[i]-'a';
		p = p->next[id];
		if(p == NULL) //若为空集，表示不存以此为前缀的串
			return 0;
	}
	return p->v; //此串是字符集中某串的前缀
}
int dealTrie(Trie* T) {
	int i;
	if(T==NULL)
		return 0;
	for(i=0; i<MAX; i++) {
		if(T->next[i]!=NULL)
			dealTrie(T->next[i]);
	}
	free(T);
	return 0;
}
int main() {
	int t,n;
		while(~scanf("%d",&n)){
		root = (Trie *) malloc (sizeof(Trie));
		for(int i=0; i<27; ++i)
			root->next[i] = NULL;
		int flag=0;
		char a[25];
		for(int i=1; i<=n; i++) {
			scanf("%s",a);
			createTrie(a);
		}
		int m;
		cin>>m;
		while(m--){
			char b[25];
			scanf("%s",b);
			int ans = findTrie(b);
			cout<<ans<<endl;
	}
		dealTrie(root);
	}
}
