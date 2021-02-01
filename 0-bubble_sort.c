#include "sort.h"


/**
 * bubble_sort - bubble sort algorithm
 * @array: array to be sorted in place
 * @size: size of the array
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int aux, swapped;

	if (array == NULL || size < 2)
		return;
	do {
		swapped = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				aux = array[i - 1];
				array[i - 1] = array[i];
				array[i] = aux;
				swapped = 1;
				print_array(array, size);
			}
		}
	} while (swapped);
}
