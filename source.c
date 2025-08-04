#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdio.h>

#ifdef linux
#include <unistd.h>
#endif

#include "visualizer.h"

void display_array(int array[], int size);

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

	int array3[20];
	srand(0);

	for (int i = 0; i < 20; i++) {
		array3[i] = (rand() % 10) + 1; // Gera números aleatórios entre 0 e 99
	}

	int array[] = { 1, 2, 3, 4, 5 };
	int array2[] = { 5, 2, 1, 4, 3 };


	getchar();
	display_sort(array3, 20, bubble_sort);

	return 69;
}
