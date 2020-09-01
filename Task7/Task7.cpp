#pragma warning(disable:4996)

#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<math.h>
#include<time.h>

#include<stdarg.h>

double middle_geometric(int n, ...)
{
	double out = 1;
	va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++)
	{
		out *= va_arg(args, int);
	}
	va_end(args);

	return pow(out, 1.0 / n);
}

int main()
{
	printf("middle_geometric = %lf\n", middle_geometric(3, 3, 9, 27));

	system("pause");
	return 0;
}