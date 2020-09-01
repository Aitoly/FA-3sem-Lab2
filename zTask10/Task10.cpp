#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include <iostream>
#include <ctype.h>

void CountOfAlphas(FILE* in, FILE* out)
{
	if (!in || !out)
		return;

	char c;

	int numberOfString = 1, countOfSymbols = 0;

	while (!feof(in))
	{
		c = getc(in);

		if (isalpha(c))
		{
			countOfSymbols++;
		}

		if (c == '\n')
		{
			fprintf(out, "Строка номер: %d, количество букв: %d\n", numberOfString, countOfSymbols);
			countOfSymbols = 0;
			numberOfString++;
		}
	}

	if (countOfSymbols > 0)
	{
		fprintf(out, "Строка номер: %d, количество букв: %d\n", numberOfString, countOfSymbols);
	}
}

int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc == 1)
	{
		printf("Не достаточно аргуметов коммандной строки!\n");
		return 0;
	}

	FILE* in, * out;

	in = fopen(argv[1], "r");
	if (!in)
	{
		printf("Не могу открыть файл %s\n", argv[1]);
		return 0;
	}

	out = fopen("out.txt", "w");
	if (!out)
	{
		printf("Не могу открыть файл out.txt\n");
		fclose(in);
		return 0;
	}

	CountOfAlphas(in, out);

	fclose(in);
	fclose(out);

	printf("Успешно\n");
	return 0;
}