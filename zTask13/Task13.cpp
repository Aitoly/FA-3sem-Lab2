#pragma warning(disable:4996)

#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include<stdarg.h>

#include<stdarg.h>
#include<Windows.h>

bool convex_figure(int n, ...)
{
	double x[BUFSIZ];
	double y[BUFSIZ];
	int flag = 2, i, j;
	double t;
	va_list args;
	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		x[i] = va_arg(args, double);
		y[i] = va_arg(args, double);

		printf("[%d]\t(%lf ; %lf)\n", i, x[i], y[i]);
	}
	printf("\n");
	va_end(args);

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j != i && j != i - 1)
			{
				t = (x[j] - x[i - 1]) * (y[i] - y[i - 1]) - (y[j] - y[i - 1]) * (x[i] - x[i - 1]);
				printf("[%d][%d][%d]\t%lf\n", i - 1, i, j, t);
				//printf("(%lf - %lf) * (%lf-%lf)	- (%lf - %lf) * (%lf - %lf)\n",x[j],x[i-1],y[i],y[i-1],y[j],y[i-1],x[i], x[i-1]);
				if (t < 0)
				{
					if (flag == 2)
					{
						flag = -1;
					}
					else if (flag > 0)
					{
						return false;
					}
				}
				else
				{
					if (flag == 2)
					{
						flag = 1;
					}
					else if (flag < 0)
					{
						return false;
					}
				}
			}
		}
	}

	return true;
}

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool b = convex_figure(5,
		1.0, 1.0,
		2.0, 2.0,
		1.0, 3.0,
		3.0, 3.0,
		3.0, 1.0);

	if (b)
	{
		printf("Да, является выпуклым.\n");
	}
	else
	{
		printf("Нет, не является выпуклым.\n");
	}

	return 0;
}
