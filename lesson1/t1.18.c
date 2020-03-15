#include <stdio.h>
#include <limits.h>



int main()
{
    int i,n,a;
    int min = INT_MAX;
    int k_min=1,k_tmp=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a<min)
        {
            if(k_tmp>k_min)
                k_min = k_tmp;
            min=a;
            k_tmp=1;
        }
        else
        {
            if(a==min)
                k_tmp+=1;
            else
            {
                if(k_tmp>k_min)
                    k_min = k_tmp;
                k_tmp=0;
            }


        }


        }
if(k_tmp>k_min)
    k_min = k_tmp;


printf("%d",k_min);




return 0;
}




