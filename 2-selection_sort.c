#include "sort.h"

/**
 * selection_sort - sorts array of integers with selection sort
 * @array: array of integers to be sorted
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
if (size < 2)
return;
size_t i, j;
int minidx, temp;

for (i = 0; i < size; i++)
{
minidx = i;
for (j = i + 1; j < size; j++)
{
if (array[minidx] > array[j])
minidx = j;
}
temp = array[i];
array[i] = array[minidx];
array[minidx] = temp;
print_array(array, size);
}

}
