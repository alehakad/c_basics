#include <stdio.h>
#include <limits.h>



int main()
{
    int i,n;
    int min = INT_MAX,n_min = 0;
    int max = INT_MIN,n_max = 0;
    int a;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a<min)
        {
            min = a;
            n_min = i-1;
        }
        if(a>= max)
        {
            max = a;
            n_max = i-1;
        }

        }






printf("%d %d",n_min,n_max);

return 0;
}
