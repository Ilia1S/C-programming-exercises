// Сколько различных трехзначных чисел можно получить из заданного натурального N, вычеркивая цифры из его десятичной записи?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[102];
unsigned short array[1000];
unsigned short i = 0, j = 0, k = 0, len = 0, a1 = 0, a2 = 0, a3 = 0, q = 0;

int main(void)
{
    scanf("%s[^\n]", string);
    len = strlen(string);
    if (len < 3)
    {
        q = 0;
        printf("%u\n", q);
        return 0;
    }
    else
    {
        for (i=0; i<len-2; i++)
        {
            a1 = string[i] - 48;
            if (a1 == 0)
                continue;
            for (j=i+1; j<len-1; j++)
            {
                a2 = string[j] - 48;
                for (k=j+1; k<len; k++)
                {
                    a3 = string[k] - 48;
                    a3 = a1*100 + a2*10 + a3;
                    if (array[a3] == 0)
                    {
                        q++;
                        array[a3]++;
                    }
                }
            }
        }
    }
    printf("%u\n", q);
    return 0;
}
