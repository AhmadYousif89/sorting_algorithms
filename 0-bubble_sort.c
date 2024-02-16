#include "sort.h"

/**
 * bubble_sort - The bubble sorting algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, n;

	if (array == NULL)
		return;

	for (n = size; n > 0; n--)		   /* O(n) */
		for (i = 0; i < size - 1; i++) /* O(n) */
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
} /* O(n^2) */
