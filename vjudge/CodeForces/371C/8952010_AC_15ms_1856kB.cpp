
#include<stdio.h>
int main()
{
    char str[200];
    int a[4],val[4],b,s,c,i,buy,flagb,flags,flagc;
    __int64 r,sum,price;
    while(scanf("%s",str)!=EOF)
    {
        b=s=c=0;
        for(i=0;str[i]!='\0';i++)
        {
            if(str[i]=='B')
                b++;
            else if(str[i]=='S')
                s++;
            else
                c++;
        }
        for(i=1;i<=3;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=3;i++)
            scanf("%d",&val[i]);
        scanf("%I64d",&r);
        price=b*val[1]+s*val[2]+c*val[3];
        sum=0; flagb=flags=flagc=0;
        while(r)
        {
            if((a[1]||a[2]||a[3]))
            {
                
				if(flagb==0&&b==0)//注意这里的判断条件，很重要的。
				{
					a[1]=0;
					flagb=1;
				}
				else
				{
					if(a[1]>=b)
						a[1]-=b;
					else
					{
						buy=b-a[1];
						if(r>=buy*val[1])
						{
							r-=buy*val[1];
							a[1]=0;
						}
						else
							break;
					}
				}
				if(flags==0&&s==0)
				{
					a[2]=0;
					flags=1;
				}
				else
				{
					if(a[2]>=s)
						a[2]-=s;
					else
					{
						buy=s-a[2];
						if(r>=buy*val[2])
						{
							r-=buy*val[2];
							a[2]=0;
						}
						else
							break;
					}
				}
				if(flagc==0&&c==0)
				{
					flagc=1;
					a[3]=0;
				}
				else
				{
					if(a[3]>=c)
						a[3]-=c;
					else
					{
						buy=c-a[3];
						if(r>=buy*val[3])
						{
							r-=buy*val[3];
							a[3]=0;
						}
						else
							break;
					}
				}
                sum++;
            }
            else
            {
                sum+=r/price;
                break;
            }
        }
        printf("%I64d\n",sum);
    }
    return 0;
	
}

/*下面这种方法用到了两个很巧妙的地方，值得学习：

#include<stdio.h>
int main()
{
    char str[200];
    int b,s,c,i,ts,tx,a[4],val[4],buy;
    __int64 price ,sum,r;
    while(scanf("%s",str)!=EOF)
    {
            b=s=c=0;
            for(i=0;str[i]!='\0';i++)
            {
                if(str[i]=='B')
                    b++;
                else if(str[i]=='S')
                    s++;
                else
                    c++;
            }
            for(i=1;i<=3;i++)
                scanf("%d",&a[i]);
            for(i=1;i<=3;i++)
                scanf("%d",&val[i]);
            scanf("%I64d",&r);
            ts=(b>0)+(s>0)+(c>0);//关键点，很巧妙的地方
            price=b*val[1]+s*val[2]+c*val[3];
            sum=0;int flag=0;
            while(r)
            {
                if((a[1]||a[2]||a[3])&&flag==0)
                {
                   if(a[1]>=b)
                        a[1]-=b;
                   else
                   {
                       buy=b-a[1];
                       if(r>=buy*val[1])
                       {
                           r-=buy*val[1];
                           a[1]=0;
                       }
                       else
                        break;
                   }
                   if(a[2]>=s)
                        a[2]-=s;
                   else
                   {
                       buy=s-a[2];
                       if(r>=buy*val[2])
                       {
                           r-=buy*val[2];
                           a[2]=0;
                       }
                       else
                        break;
                   }
                   if(a[3]>=c)
                        a[3]-=c;
                   else
                   {
                       buy=c-a[3];
                       if(r>=buy*val[3])
                       {
                           r-=buy*val[3];
                           a[3]=0;
                       }
                       else
                        break;
                   }
                   sum++;
                   tx=(a[1]==0)+(a[2]==0)+(a[3]==0);//关键点，很巧妙的地方
                   if(tx==ts)
                    flag=1;
                }
                else
                {
                    sum+=r/price;
                    break;
                }
            }
            printf("%I64d\n",sum);
    }
    return 0;
}
*/