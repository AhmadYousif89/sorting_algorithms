#include "sort.h"

/**
 * swap - Swap two numbers
 * @a: pointer the 1st number
 * @b: pointer the 2nd number
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - The bubble sorting algorithm
 * @array: pointer to the array
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;

	if (array == NULL)
		return;

	for (n = size; n > 0; n--)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(&array[i], &array[i + 1]);
				print_array(array, size);
			}
		}
	}
}
