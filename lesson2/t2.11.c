#include <stdio.h>
#include <stdlib.h>


int str_len(char *c)
{
    int i =0;
    while(c[i]!='\0')
        i++;
    return i;
}

char *ds(char *s)
{
    int n = str_len(s);
    int i;
    char *dbst=malloc(n*2);

    for(i=0;i<n;i++)
    {
        dbst[i] = s[i];
    }
    for(i=0;i<n;i++)
    {
        dbst[n+i] = s[i];
    }
    return dbst;
}
int main()
{
    char s[] = "He110!";

    printf("%s",ds(s));

    return 0;
}






