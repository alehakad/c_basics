#include <stdio.h>
#include <limits.h>
#include <math.h>


int main()
{
int i =1;
double s = 1,p=1,t=1,eps;
scanf("%lf",&eps);
while(t>=eps)
{

p=p*i;
t = 1/p;
s+=t;
i+=1;


}
printf("%.20f",s);

return 0;
}
