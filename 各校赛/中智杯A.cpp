#include<bits/stdc++.h> 
  using namespace std;
#define max(a,b) a>b?a:b  
  
int calc_result(int block, int *p,int len)  
{  
    unsigned __int64 result_mid=1;  
    unsigned __int64 result_mid_big=1;  
  
    for (int i = 1; i <= block; i++)  
    {  
        int sum=0;  
        result_mid_big=result_mid_big*i;  
        for (int j = 2; j <= len; j++)  
        {  
            sum+=*(p+j);  
            if (*(p+j)==0)  
            {  
                continue;         
            }  
            if (result_mid_big%j==0)  
            {  
                result_mid_big=result_mid_big/j;  
                (*(p+j))--;  
            }  
        }  
        if (sum==0)  
        {  
            if (result_mid_big>1000000007)  
            {  
                result_mid_big=result_mid_big%1000000007;  
            }  
        }  
    }  
    return (int)result_mid_big;  
}  
int palindrome(const char *s)  
{  
    int len = strlen(s);  
    if (len > 100)  
    {  
        printf("Strings too long");  
        return 0;  
    }  
    int num[26]={0};    
    int flag_len = len % 2;  
    int flag_bit,flag=0;  
    int num_bit[26]={0};  
    int MAX=0;  
    for (int i = 0; i < len; i++)  
    {  
        num[*(s+i)-'a']++; //统计出每个字母出现的个数         
    }  
    for (int i = 0; i < 26; i++)  
    {  
        flag_bit = num[i] % 2;  
        if (flag_bit==1)  
        {  
            flag++;  
        }  
        if ((flag_len == 0 && flag_bit == 1) || (flag_len == 1 && flag > 1))        //字符串长度为偶数，但是有出现基数词的字符，则不可能是回文字符  
        {  
            return 0;  
        }  
        num_bit[i] = num[i]/2;    
        MAX = max(MAX,num_bit[i]);  
    }  
    int *p_num = new int[MAX+1]();  
    for (int i = 0; i < 26; i++)  
    {         
        if (num_bit[i]<=1)  
        {  
            continue;         
        }  
        for (int j = 2; j <= num_bit[i]; j++)  
        {  
            (*(p_num+j))++;  
        }  
    }  
    int block = len/2;  
    int result=calc_result(block,p_num,MAX);  
    printf("Result is %d \n",result);  
    delete[] p_num;  
    return result;  
}  
int main()  
{  
    char str[101];
	while(scanf("%s",str)){
    palindrome(str);  
}
    return 0;  
}  
