#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str1;
char *str2;
char *newstr1;
char *newstr2;
char *newstr3;
char *newstr4;

unsigned short kmp = 0, kmp2 = 0, i = 0, len1 = 0, len2 = 0, lenmin = 0,
                flag = 0, flag2 = 0, breakready = 0, breakready2 = 0;

int main(void)
{
    str1 = malloc (sizeof(char)*10000);
    str2 = malloc (sizeof(char)*10000);
    newstr1 = malloc (sizeof(char)*10000);
    newstr2 = malloc (sizeof(char)*10000);
    newstr3 = malloc (sizeof(char)*10000);
    newstr4 = malloc (sizeof(char)*10000);
    scanf("%10000s[^\n]", str1);
    scanf("%10000s[^\n]", str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    lenmin = (len1 < len2) ? len1 : len2;
    for (i=1; i<=lenmin; i++)
    {
        snprintf(newstr1, i+1, "%s", str1);
        newstr2 = &str2[len2-i];
        newstr3 = &str1[len1-i];
        snprintf(newstr4, i+1, "%s", str2);
        if (!breakready)
        {
            if (strcmp(newstr1, newstr2) && flag == 1)
                breakready = 1;
            else if (!strcmp(newstr1, newstr2))
            {
                kmp = strlen(newstr1);
                flag = 1;
            }
        }
        if (!breakready2)
        {
            if (strcmp(newstr3, newstr4) && flag2 == 1)
                breakready2 = 1;
            else if (!strcmp(newstr3, newstr4))
            {
                kmp2 = strlen(newstr3);
                flag2 = 1;
            }
        }
        if (breakready && breakready2)
            break;
    }
    printf("%u %u\n", kmp, kmp2);
    free(str1);
    free(str2);
    return 0;
}
