#include <stdio.h>
#include <limits.h>



int main()
{
    int i,n;
    int max = INT_MIN,n_max = 0;
    int a;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(a>= max)
        {
            max = a;
            n_max = n-i;
        }

        }






printf("%d",n_max);

return 0;
}




