#include <stdio.h>
#include <limits.h>
#include <math.h>
int main()
{
int a,s=0;
scanf("%d",&a);
while(a/10>0)
{
if(a%10==7)
s+=1;
a=a/10;

};
if(a==7)
s+=1;
printf("%d",s);

return 0;
}
