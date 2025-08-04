
#ifdef VISUALIZER_H_
#define VISUALIZER_H_

void display_array(int array[], int size);

void swap(int array[], int size, int a, int b);

void display_sort(int array[], int size, void(*f)(int[], int, void (*swapfunction)(int[], int, int, int)));

void Sleep2(int milliseconds);

void ClearScreen(void);

#endif // VISUALIZER_H_
