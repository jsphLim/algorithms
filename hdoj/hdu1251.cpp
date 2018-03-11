#include <iostream>
#include<malloc.h>
#include<string.h>
#include<cstdio>
using namespace std;

struct Trie{    //字典树定义
    Trie* next[26];
    int num;    //以当前字符串为前缀的单词的数量
    Trie()    //构造函数
    {
        int i;
        for(i=0;i<26;i++){
            next[i] = NULL;
        }
        num=0;
    }
};
Trie root;
void Insert(char word[])    //将字符串word插入到字典树中
{
    Trie *p = &root;
    int i;
    for(i=0;word[i];i++){    //遍历word的每一个字符
        if(p->next[word[i]-'a']==NULL)    //如果该字符没有对应的节点
            p->next[word[i]-'a'] = new Trie;    //创建一个
        p = p->next[word[i]-'a'];
        p->num++;
    }
}
int Find(char word[])    //返回以字符串word为前缀的单词的数量
{
    Trie *p = &root;
    int i;
    for(i=0;word[i];i++){    //在字典树找到该单词的结尾位置
        if(p->next[word[i]-'a']==NULL)
            return 0;
        p = p->next[word[i]-'a'];
    }
    return p->num;
}
int dealTrie(Trie* T) {
	int i;
	if(T==NULL)
		return 0;
	for(i=0; i<26; i++) {
		if(T->next[i]!=NULL)
			dealTrie(T->next[i]);
	}
	free(T);
	return 0;
}

int main()
{
    char word[11];
    while(cin.getline(word,12)){    //输入单词
        if(strlen(word)==0 || word[0]==' ')    //如果读入字符串的长度为0或者是空格，说明读入的是空行
            break;
        Insert(word);
    }
    while(scanf("%s",word)!=EOF){
        printf("%d\n",Find(word));    //返回word为前缀的单词的数量
    }
    return 0;
}
