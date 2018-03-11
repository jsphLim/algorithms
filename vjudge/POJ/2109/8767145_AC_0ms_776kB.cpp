#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main()
{
    double n,p;

    while(cin>>n>>p)
        printf("%d\n",(int)(pow(p,1.0/n)+0.5));
    return 0;
}