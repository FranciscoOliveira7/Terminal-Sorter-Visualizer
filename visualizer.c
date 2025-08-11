#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// OS specific stuff

#ifdef linux
#include <unistd.h>
#endif

#include "visualizer.h"

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

void display_array(int array[], int size)
{
	int biggest_value = get_biggest_value(array, size);

	char buffer[1500];

	strcpy(buffer, "\033[11A");
	strcat(buffer, "\033[60D");

	//printf("\nBiggest value: %d\n\n", biggest_value);

	for (int i = 0; i < biggest_value; i++)
	{
		//char* row = malloc((2 * size) * sizeof(char));
		//row = "";
		//char *row = malloc(size * sizeof(char));


		//row[0] = '\0';   // ensures the memory is an empty string

		for (int j = 0; j < size; j++)
		{
			if (i < biggest_value - array[j])
			{
				strcat(buffer, "   ");
				//printf("\xE2\x96\x92 ");
				//printf("   ");
			}
			else
			{
				strcat(buffer, "\xE2\x96\x88\xE2\x96\x92 ");
				//printf("\xE2\x96\x88\xE2\x96\x88 ");
			}
		}


		strcat(buffer, "\n");
	}
	printf(buffer);
}

void Sleep2(int milliseconds) {
#ifdef _WIN32
	Sleep(milliseconds);
#endif

#ifdef linux
	sleep(milliseconds);
#endif
}

void ClearScreen(void) {
#ifdef _WIN32
	system("cls");
#endif

#ifdef linux
	system("clear");
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

	//ClearScreen();
	display_array(array, size);
	printf("\n- Sorting -");
	Sleep2(500);
}

void display_sort(int array[], int size, void(*f)(int[], int, void (*swapfunction)(int[], int, int, int)))
{
	(*f)(array, size, swap);
}
