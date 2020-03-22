#include <stdio.h>

char* str_chr(char *s,char c)
{
    int i=0;
    while(s[i]!=c && s[i]!='\0')
    {
        i+=1;
    }
    return &s[i];
}
int main()
{
    char s[] = "He110!";
    char c = 'e';
    printf("%d",str_chr(s,c));

    return 0;
}






