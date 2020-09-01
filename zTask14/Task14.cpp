#pragma warning(disable:4996)

#include<stdlib.h>
#include<stdio.h>
#include<math.h>

/////////////////////////////////////////////////////////////////////////
double DichotomyMethod(double(*func)(double), double a, double b, double e)
{
	double x;

	while (fabs(a - b) >= e)
	{
		x = (a + b) / 2;
		if (func(a) * func(x) > 0) { a = x; }
		else { b = x; }
	}
	return x;
}

///////////////////////////////////////////////////////////////////////
double func(double x)
{
	return exp(x) + sqrt(1 + exp(2 * x)) - 2;
}
///////////////////////////////////////////////////////////////////////////
int main()
{
	printf("exp(x)+sqrt(1+exp(2*x))-2\n");
	printf("%.8f\n", DichotomyMethod(func, -1, 0, 0.00000001));
	return 0;
}
