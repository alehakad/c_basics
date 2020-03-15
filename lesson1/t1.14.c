#include <stdio.h>
#include <limits.h>



int main()
{
    int i,n;
    int min1 = INT_MAX,min2 = INT_MAX;
    int a;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a<min2)
        {
            if(a<min1)
            {
                min2 = min1;
                min1 = a;
            }
            else
                min2=a;
            }
        }






printf("%d %d",min1,min2);

return 0;
}

