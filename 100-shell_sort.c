#include "sort.h"

/**
 * gap_size - Calculate the gap size between the elements
 * @size: the size of the array
 *
 * Description: Using the Knuth sequence to calculate the gap.
 * Return: the gap
 */
size_t gap_size(size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = gap * 3 + 1; /* Get max gap size */

	return ((gap - 1) / 3); /* Get required gap size */
}

/**
 * shell_sort - The Shell sort algorithm, using the Knuth sequence
 * @arr: pointer to the array
 * @size: the size of the array
 */
void shell_sort(int *arr, size_t size)
{
	size_t gap, i, j;
	int tmp;

	for (gap = gap_size(size); gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = arr[i];
			for (j = i; j > gap - 1 && tmp < arr[j - gap]; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = tmp;
		}
		print_array(arr, size);
	}
}
