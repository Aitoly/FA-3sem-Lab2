#pragma warning(disable:4996)

#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include<stdarg.h>

double polynomial(int x, int power, ...)
{
	va_list args;
	va_start(args, power);

	double result = 0;

	for (int i = power; i >= 0; i--)
	{
		int a = va_arg(args, int);
		result += a * pow(x, i);
	}

	va_end(args);

	return result;
}

int main()
{
	double y = polynomial(1, 3, 5, 4, 3, 2);

	printf("%lf\n", y);

	system("pause");
	return 0;
}