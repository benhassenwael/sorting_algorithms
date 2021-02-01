#include "sort.h"


/**
 * partition - partition part of array around pivot using
 * Lomuto method
 * @array: array to partition
 * @low: starting point of the part to partition
 * @hi: the end point of the part to partition
 * @size: size of the array
 *
 * Return: pivot index after sort
 */
int partition(int *array, int low, int hi, size_t size)
{
	int aux, pivot, i, j;

	pivot = array[hi];
	i = low - 1;
	for (j = low; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i == j)
				continue;
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			print_array(array, size);
		}
	}
	if (array[hi] <= array[i + 1])
	{
		i++;
		if (i == hi)
			return (i);
		aux = array[i];
		array[i] = array[hi];
		array[hi] = aux;
		print_array(array, size);
	}
	return (i);
}

/**
 * sort - quick sort part of the array
 * @array: array to be sort part of
 * @low: starting point of the part to sort
 * @hi: the end point of the part to sort
 * @size: size of the array
 */
void sort(int *array, int low, int hi, size_t size)
{
	int p;

	if (low < hi)
	{
		p = partition(array, low, hi, size);
		sort(array, low, p - 1, size);
		sort(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - quick sort algorithm
 * @array: array to be sorted in place
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	sort(array, 0, size - 1, size);
}
