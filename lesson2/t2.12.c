#include <stdio.h>
#include <stdlib.h>


int str_len(char *c)
{
    int i =0;
    while(c[i]!='\0')
        i++;
    return i;
}

char *concat(char *s1,char *s2)
{
    int n = str_len(s1);
    int m = str_len(s2);
    int i;
    char *cst= malloc(n+m);

    for(i=0;i<n;i++)
    {
        cst[i] = s1[i];
    }
    for(i=0;i<m;i++)
    {
        cst[n+i] = s2[i];
    }

    return cst;
}
int main()
{
    char s[40];
    char str[40];
    char *res;

    scanf("%39s",s);
    scanf("%39s",str);

    res = concat(s,str);

    printf("%s",res);

    free(res);

    return 0;
}






