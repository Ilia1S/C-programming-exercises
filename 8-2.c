// Для заданных натуральных чисел N и K требуется вычислить количество чисел от 1 до N, имеющих в двоичной записи ровно K нулей. Например, если N=8 и K=1, то мы можем записать все числа от 1 до 8 в двоичной системе счисления: 1, 10, 11, 100, 101, 110, 111 и 1000. Откуда видно, что только числа 10, 101 и 110 имеют ровно один ноль в записи, т.е. правильный ответ – 3.

#include <stdio.h>
#include <stdint.h>

int main(int argc, const char * argv[])
{
    uint16_t N, K, z = 0, q = 0, m;
    uint8_t binaryArray[16];
    scanf("%hu %hu", &N, &K);
    for (uint16_t i = 1; i <= N; i++)
    {
        m = i;
        for (uint16_t j = 0; m > 0; j++)
        {
            binaryArray[j] = m % 2;
            m /= 2;
            if (binaryArray[j] == 0)
                z++;
        }
        if (z == K)
            q++;
        z = 0;
    }
    printf("%u\n", q);
    return 0;
}