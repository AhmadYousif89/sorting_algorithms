#include "sort.h"

/**
 * get_max - Get the max number in the array
 * @array: pointer to the aaray
 * @size: size of the array
 *
 * Return: the max number
 */
size_t get_max(int *array, size_t size)
{
	size_t i = 0, max = array[0];

	for (; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * counting_sort - Sort an array using the counting sort algorithm.
 * @array: pointer to the array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	size_t i, k;

	if (array == NULL || size < 2)
		return;

	k = get_max(array, size);
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;
	memset(count, 0, sizeof(int) * (k + 1)); /* Fill with zeros */

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}

	/* Update count array with the n of occurrences of each element in array */
	for (i = 0; i < size; i++)
		count[array[i]] += 1;
	/* Modify the count array to store the cumulative count */
	for (i = 1; i <= k; i++)
		count[i] += count[i - 1];
	print_array(count, k + 1);
	/* Place the elements in their correct sorted order in the output array */
	for (i = size - 1; i < size; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	/* Copy the sorted elements from the output array back to the array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
