#include "sort.h"
#include <stdio.h>


/**
 * bitonic_sort - bitonic sort algorithm
 * @array: array to sort
 * @size: size of `array`
 */
void bitonic_sort(int *array, size_t size)
{
	int k, j, i, l, aux;

	for (k = 2; (size_t)k <= size; k *= 2)
	{
		for (j = k / 2; j > 0; j /= 2)
		{
			for (i = 0; (size_t)i < size; i++)
			{
				l = i ^ j;
				if (l > i)
				{
					if (((( i & k) == 0) &&
					    (array[i] > array[l])) ||
					    (((i & k) != 0) &&
					    (array[i] < array[l])))
					{
						aux = array[i];
						array[i] = array[l];
						array[l] = aux;
						print_array(array, size);
					}
				}
			}
		}
	}
}
