#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<Windows.h>
#include <ctime>

#define SIZE 20

struct Element
{
	int val;
	int i;
};

void Replace(int* min, int* max)
{
	int t = *max;

	*max = *min;
	*min = t;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(0));

	int arr[SIZE];
	struct Element min = { INT_MAX, 0 };
	struct Element max = { -1, 0 };
	int currentElement = -1;

	printf("Исходный массив: ");
	for (int i = 0; i < SIZE; ++i)
	{
		currentElement = rand() % 100;
		arr[i] = currentElement;

		if (currentElement < min.val)
			min = { currentElement, i };

		if (currentElement > max.val)
			max = { currentElement, i };

		printf("%d ", currentElement);
	}
	printf("\n");

	printf("Минимальный элемент: %d(%d)\n", min.val, min.i);
	printf("Максимальный элемент: %d(%d)\n", max.val, max.i);

	Replace(&arr[min.i], &arr[max.i]);

	printf("Массив после перестановки: ");
	for (int i = 0; i < SIZE; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}