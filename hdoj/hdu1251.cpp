#include <iostream>
#include<malloc.h>
#include<string.h>
#include<cstdio>
using namespace std;

struct Trie{    //�ֵ�������
    Trie* next[26];
    int num;    //�Ե�ǰ�ַ���Ϊǰ׺�ĵ��ʵ�����
    Trie()    //���캯��
    {
        int i;
        for(i=0;i<26;i++){
            next[i] = NULL;
        }
        num=0;
    }
};
Trie root;
void Insert(char word[])    //���ַ���word���뵽�ֵ�����
{
    Trie *p = &root;
    int i;
    for(i=0;word[i];i++){    //����word��ÿһ���ַ�
        if(p->next[word[i]-'a']==NULL)    //������ַ�û�ж�Ӧ�Ľڵ�
            p->next[word[i]-'a'] = new Trie;    //����һ��
        p = p->next[word[i]-'a'];
        p->num++;
    }
}
int Find(char word[])    //�������ַ���wordΪǰ׺�ĵ��ʵ�����
{
    Trie *p = &root;
    int i;
    for(i=0;word[i];i++){    //���ֵ����ҵ��õ��ʵĽ�βλ��
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
    while(cin.getline(word,12)){    //���뵥��
        if(strlen(word)==0 || word[0]==' ')    //��������ַ����ĳ���Ϊ0�����ǿո�˵��������ǿ���
            break;
        Insert(word);
    }
    while(scanf("%s",word)!=EOF){
        printf("%d\n",Find(word));    //����wordΪǰ׺�ĵ��ʵ�����
    }
    return 0;
}
