#pragma warning(disable:4996)

#include<stdio.h>
#include<iostream>
#include<ctype.h>
#include<math.h>
#include<time.h>
#include<stdarg.h>

int find_part_of_string(const char* part, const char* string)
{
	int current_ok = 0;
	int max_ok = strlen(part);
	int current_position = 1;

	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == part[current_ok])
		{
			current_ok++;
			if (current_ok == max_ok)
			{
				printf("I find \"%s\" from position %d\n", part, current_position - max_ok);
				return current_position - max_ok;
			}
		}
		else
		{
			current_ok = 0;
		}

		current_position++;
	}

	return -1;
}


void find_string_in_file(const char* string, int n, ...)
{
	va_list args;
	va_start(args, n);
	for (int i = 0; i < n; i++)
	{
		char* name = va_arg(args, char*);
		printf("%s\n", name);

		FILE* f;
		f = fopen(name, "r");
		if (!f)
		{
			printf("\tI can`t open file \"%s\"\n", name);
			continue;
		}

		char c = ' ';
		int current_ok = 0;
		int max_ok = strlen(string);
		int current_string = 1;
		int current_position = 1;
		while (!feof(f))
		{
			c = getc(f);

			if (c == '\n')
			{
				current_string++;
				current_position = 1;
			}

			if (c == string[current_ok])
			{
				current_ok++;
				if (current_ok == max_ok)
				{
					printf("\tI find \"%s\" in file \"%s\" in string %d, position %d\n", string, name, current_string, current_position - max_ok);
				}
			}
			else
			{
				current_ok = 0;
			}

			current_position++;
		}

		fclose(f);
	}

	va_end(args);
}

int main()
{
	find_string_in_file("eo", 3, "one.txt", "two.txt", "three.txt");

	printf("==========================\n");

	find_part_of_string("eof", "file eof give");

	find_part_of_string("eof", "file feofile give");

	find_part_of_string("eof", "file e of give");

	system("pause");
	return 0;
}