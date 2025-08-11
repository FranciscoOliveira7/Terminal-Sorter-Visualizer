#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

#ifdef linux
#include <unistd.h>
#endif

#include "visualizer.h"

#define ARRAY_SIZE 20

void display_array(int array[], int size, int a, int b);

void swap(int array[], int size, int a, int b);

void display_sort(int array[], int size, void(*f)(int[], int, void (*swapfunction)(int[], int, int, int)));

void bubble_sort(int array[], int size, void(*swap)(int[], int, int, int))
{
	int sorted = 0;

	while (!sorted)
	{
		sorted = 1;

		for (int i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				(*swap)(array, size, i, i + 1);
				sorted = 0;
			}
		}
	}
}

int main(void) {
	setlocale(LC_ALL, "en_US.UTF-8");

	int array[ARRAY_SIZE];

	for (int i = 0; i < ARRAY_SIZE; i++) {
		array[i] = i + 1;
	}

	shuffle(array, ARRAY_SIZE);

	display_array(array, ARRAY_SIZE, -1, -1);
	getchar();
	display_sort(array, ARRAY_SIZE, bubble_sort);
	printf("\r-- Done --");
	getchar();

	return 69;
}
