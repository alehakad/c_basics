#include <stdio.h>
#include <limits.h>



int main()
{
int i,n,t=0;
float a;
float s = 0,s_tmp = 0;
scanf("%d",&n);
for(i =1; i <= n;i++)
{
    scanf("%f",&a);

    if(a==1)
        {s+=s_tmp;
        printf("s %f \n",s);
        if(t==1)
            s_tmp=1;
        t=1;}
    else
        if(t==1)
        {s_tmp+=a;
        printf("s_tmp %f \n",s_tmp);}



    }




printf("%f",s);





return 0;
}
