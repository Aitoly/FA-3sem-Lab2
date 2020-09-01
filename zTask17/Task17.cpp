#pragma warning(disable:4996)

#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<math.h>
#include<time.h>

#include<stdarg.h>

#define N	2

void final_fraction(int base, int n, int* res, ...)
{
	double in;
	int i, j;
	va_list args;
	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		in = va_arg(args, double);

		for (j = 0; j < 20; j++)
		{
			if (in >= 1)
			{
				//printf("<%d>%lf\n", j, in);
				in -= (int)(in + 0.5);
				//printf("<%d>%lf\n", j, in);
			}
			if (in < 0)
			{
				in *= -1;
			}
			if (in < 0.00000001)
			{
				break;
			}
			in *= base;
		}

		if (in < 0.00000001)
		{
			*res++ = 1;
			//printf("%lf is final fraction in base %d\n", out, base);
		}
		else
		{
			*res++ = 0;
			//printf("%lf isn`t final fraction in base %d\n", out, base);
		}
	}
	va_end(args);
}

int main()
{
	int arr[N];

	final_fraction(10, N, arr, 1.0 / 3.0, 1.0 / 2.0);

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}