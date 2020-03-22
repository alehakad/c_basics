#include <stdio.h>

int count_digits(char *s)
{
    int i=0,n=0;
    while(s[i]!='\0')
    {
        if(s[i]>='0' && s[i]<='9')
            n+=1;
        i+=1;
    }

    return n;
}
int main()
{
    char s[] = "He110!";
    printf("%d",count_digits(s));

    return 0;
}






