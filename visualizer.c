#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// OS specific stuff

#ifdef linux
#include <unistd.h>
#endif

#include "visualizer.h"

#define NC      "\033[00m"	// NC     = ANSI code for white text
#define RED     "\033[31m"	// RED    = ANSI code for red text
#define GREEN   "\033[32m"	// GREEN  = ANSI code for green text
#define YELLOW  "\033[33m"	// YELLOW = ANSI code for yellow text
#define BLUE    "\033[34m"	// BLUE   = ANSI code for blue text

int get_biggest_value(int array[], int size)
{
	int biggest_value = array[0];

	for (int i = 1; i < size; i++)
	{
		if (array[i] > biggest_value)
		{
			biggest_value = array[i];
		}
	}
	return biggest_value;
}

void display_array(int array[], int size, int a, int b)
{
	int biggest_value = get_biggest_value(array, size);

	char buffer[3200];

	strcpy(buffer, "\033[25A");
	strcat(buffer, "\r");

	//printf("\nBiggest value: %d\n\n", biggest_value);

	for (int i = 0; i < biggest_value; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i < biggest_value - array[j])
			{
				strcat(buffer, "   ");
			}
			else
			{
				if (j == a || j == b) {
					strcat(buffer, RED);
				}
				else {
					strcat(buffer, NC);
				}
				strcat(buffer, "\xE2\x96\x88\xE2\x96\x88 ");
			}
		}

		strcat(buffer, "\n");
	}
	printf(buffer);
}

void sleep2(int milliseconds) {
#ifdef _WIN32
	Sleep(milliseconds);
#endif

#ifdef linux
	sleep(milliseconds);
#endif
}

void swap(int array[], int size, int a, int b)
{
	//printf("\n\n -- swapping nigga -- \n");
	//printf(" a = %d\n", array[a]);
	//printf(" b = %d", array[b]);
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;

	display_array(array, size, a, b);
	printf("\n- Sorting -");
	sleep2(10);
}

void finish_animation(int array[], int size)
{
	int biggest_value = get_biggest_value(array, size);

	for (int h = 0; h < size; h++)
	{
		char buffer[3200];

		strcpy(buffer, "\033[25A");
		strcat(buffer, "\r");

		//printf("\nBiggest value: %d\n\n", biggest_value);
		for (int i = 0; i < biggest_value; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i < biggest_value - array[j])
				{
					strcat(buffer, "   ");
				}
				else
				{
					if (j <= h) {
						strcat(buffer, GREEN);
					}
					else {
						strcat(buffer, NC);
					}
					strcat(buffer, "\xE2\x96\x88\xE2\x96\x88 ");
				}
			}
			strcat(buffer, "\n");
		}
		printf(buffer);
	}

	sleep2(10);
}

void display_sort(int array[], int size, void(*f)(int[], int, void (*swapfunction)(int[], int, int, int)))
{
	(*f)(array, size, swap);
	finish_animation(array, size);
}

void shuffle(int array[], int size) {
	int num_of_shuffles = size;

	for (int i = 0; i < num_of_shuffles; i++)
	{
		int a = rand() % size;
		int b = rand() % size;

		int temp = array[a];
		array[a] = array[b];
		array[b] = temp;
	}
}