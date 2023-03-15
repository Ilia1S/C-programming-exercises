// Необходимо реализовать функцию, которой на входе передаётся 
// вещественное число в типе float, она возвращает порядок который 
// хранится в поле EXP в виде десятичного целого числа.

#include <stdio.h>
#include <stdint.h>

int extractExp(float);

int main(void)
{
	float x;
	scanf("%f", &x);
	printf ("%d", extractExp(x));
	return 0;
}
int extractExp(float x)
{
	union floatbit
	{
		float z;
		struct
		{
			uint32_t MANT:23;
			uint32_t EXP:8;
			uint32_t SIGN:1;
		} bit;
	}f;
	f.z = x;
	return f.bit.EXP;
}
