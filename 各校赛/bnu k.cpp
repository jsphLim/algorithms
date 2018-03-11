#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <queue>  
#include <map>  
using namespace std;  
map<string,int>mp;  
string s[100007];  
int main(){  
    int t;  
    cin>>t;  
    while(t--){  
        int n;  
        string cur;  
        mp.clear();  
        queue <string> q;  
        while(!q.empty()){  
            q.pop() ;  
        }     
        cin>>n;  
        int ans=0;  
        for(int i=1;i<=n;i++){  
            cin>>cur;  
            cin>>s[i];  
            if(cur == "in"){  
                q.push(s[i]);   
            }  
            else{  
                while(mp[q.front()] == 1)  
                  q.pop() ;  
                if(s[i] == q.front() )  
                  ans++;  
                mp[s[i]] = 1;  
            }  
        }  
        cout<<ans<<endl;   
    }  
    return 0;  
}  
