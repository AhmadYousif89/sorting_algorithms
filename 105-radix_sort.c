#include "sort.h"
#define Base 10

/**
 * get_max - Find the maximum value in an array of integers.
 * @array: The array to find the maximum value from.
 * @size: The size of the array.
 *
 * Return: The maximum value in the array.
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * count_sort - Perform counting sort on an array based on the given exponent.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exponent: The exponent representing the current significant place.
 */
void count_sort(int *array, size_t size, int exponent)
{
	size_t i;
	int j, *output = malloc(sizeof(int) * size);
	int count[Base] = {0};

	if (output == NULL)
		return;

	/* Count the occurrences of each digit at the current significant place */
	for (i = 0; i < size; i++)
		count[(array[i] / exponent) % Base]++;

	/* Update count[i] to store the position of the digit in output[] */
	for (i = 1; i < Base; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (j = size - 1; j >= 0; j--)
	{
		output[count[(array[j] / exponent) % Base] - 1] = array[j];
		count[(array[j] / exponent) % Base]--;
	}

	/* Copy the output array to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sort an array of integers using the LSD Radix Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int exponent, max;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	/* Perform counting sort for every significant place */
	for (exponent = 1; max / exponent > 0; exponent *= 10)
	{
		count_sort(array, size, exponent);
		print_array(array, size);
	}
}
