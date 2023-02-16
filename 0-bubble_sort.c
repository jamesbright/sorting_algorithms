#include "sort.h"

/**
 * bubble_sort - function implements bubble sort algorithm
 * @array: pointer to array that will be sorted
 * @size: size of the array
 */

void bubble_sort(int *array, size_t size)
{
int i, j, swapped, temp;

for (i = 0; i < size; i++)
{
swapped = 0;

for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
temp = array[j];
array[j] = array[j + 1];
array[j + 1] = temp;
swapped = 1;
print_array(array, sizw);
}
}
if (swapped = 0)
break;
}
}
