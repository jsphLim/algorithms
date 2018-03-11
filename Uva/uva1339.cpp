#include<iostream>
#include<string.H>
#include<algorithm>
using namespace std;
#define maxn 100 + 10

bool cmp(const int a, const int b)
{
    return a<b;
}

int main()
{
    string a,b;
    while(cin >> a >> b)
    {
        int len = a.length();
        int cnt1[26],cnt2[26];
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));

        for(int i=0; i < len; i++)
        {
            cnt1[a[i] - 'A']++;
            cnt2[b[i] - 'A']++;
        }

        //ÅÅÐò
        sort(cnt1,cnt1+26,cmp);
        sort(cnt2,cnt2+26,cmp);

        for(int i=0; i < 26; i++)
        {
            if(cnt1[i] != cnt2[i])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
    }

    return 0;
}
