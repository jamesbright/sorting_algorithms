#include "sort.h"


/**
 * partition - function to find the partion position
 * @array: array to look into
 * @size: size of array
 * @low: low section of array
 * @high: high section of array
 *
 * Return: the partition position
 */

int partition(int *array, int low, int high, size_t size)
{
int i, j, pivot, tmp;
pivot = array[high];

i = low;

for (j = low; j < high; ++j)
{
if (array[j] < pivot)
{

tmp = array[i];
array[i] = array[j];
array[j] = tmp;

if (tmp != array[j])
print_array(array, size);
++i;
}
}
tmp = array[i];
array[i] = array[high];
array[high] = tmp;

if (tmp != array[i])
print_array(array, size);

return (i);
}

/**
 * find_pivot - does sorting action
 * @array: array to sort
 * @size: size of array
 * @low: lower boundary
 * @high: higher boundary
 *
 * Return: Nothing
 */


void find_pivot(int *array, int low, int high, size_t size)
{
int pvt = 0;
if (low < high)
{
pvt = partition(array, low, high, size);
find_pivot(array, low, pvt - 1, size);
find_pivot(array, pvt + 1, high, size);
}
}
/**
 * quick_sort - sorts an array using quick sort
 * @array: array to sort
 * @size: size of the array
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;
find_pivot(array, 0, size - 1, size);
}
