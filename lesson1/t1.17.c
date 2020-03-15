#include <stdio.h>
#include <limits.h>



int main()
{
    int i,n;
    int max = INT_MIN;
    int a,s=0,s_tmp=0,t = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a> max)
        {
            max = a;
            s=0;
            s_tmp = 0;
            t=0;
        }
        else
            {if(a==max)
            {
                t=1;
                s+=s_tmp;
                s_tmp=1;

                }
            else
                s_tmp+=1;
            }


        }
if(t==1)
    printf("%d",s);
else
    printf("One maximal element");








return 0;
}




