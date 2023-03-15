// Необходимо вычислить выражение написанное в обратной польской записи.
// На вход подается строка состоящая из целых, не отрицательных чисел и
// арифметических символов. В ответ единственное целое число - результат.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string;
char *pstring;
unsigned short *stack;
unsigned short i = 0, j = 0;

int main(void)
{
    string = malloc(sizeof(char)*1001);
    stack = malloc(sizeof(short)*300);
    for (i=0; (string[i]=getchar())!='.'; i++);
    j = 0;
    for (i=0; string[i]!='.'; i++)
    {
        switch(string[i])
        {
            case ' ':
                continue;
                break;
            case '+':
                stack[j-2] = stack[j-2] + stack[j-1];
                j--;
                break;
            case '-':
                stack[j-2] = stack[j-2] - stack[j-1];
                j--;
                break;
            case '*':
                stack[j-2] = stack[j-2] * stack[j-1];
                j--;
                break;
            case '/':
                stack[j-2] = stack[j-2] / stack[j-1];
                j--;
                break;
            default:
                stack[j] = strtol(string+i, NULL, 10);
                if (10 <= stack[j] && stack[j] <= 99)
                    i++;
                else if (100 <= stack[j] && stack[j] <= 999)
                    i+=2;
                else if (1000 <= stack[j] && stack[j] <= 9999)
                    i+=3;
                j++;
                break;
        }
    }
    printf("%u\n", stack[j-1]);
    free(string);
    free(stack);
    return 0;
}
