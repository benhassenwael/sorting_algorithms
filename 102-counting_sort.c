#include "sort.h"


/**
 * counting_sort - counting sort algorithm
 * @array: array to be sorted in place
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i, max, *count, *output;

	if (array == NULL || size < 2)
		return;
	max = array[0];
	for (i = 1; (size_t)i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = malloc(sizeof(int) * (max + 1));
	output = malloc(sizeof(int) * size);
	if (!count || !output)
		return;

	for (i = 0; i <= max; ++i)
		count[i] = 0;

	for (i = 0; (size_t)i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; (size_t)i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
