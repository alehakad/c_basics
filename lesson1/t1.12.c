#include <stdio.h>




int main()
{
int i,n;
float tmp,a,max;
int s=0;
scanf("%d",&n);
scanf("%f",&tmp);
for(i =1; i < n;i++)
{
    scanf("%f",&a);
    if(tmp>a)
    {
       printf("%f \n",tmp);
       tmp=a;
       s+=1;


    }


}

printf("Quantity = %d",s);





return 0;
}
