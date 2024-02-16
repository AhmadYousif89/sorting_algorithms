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
	size_t i, new_size;

	while (size > 0)
	{
		new_size = 0;
		for (i = 1; i < size; i++)
		{
			if (array[i - 1] > array[i])
			{
				swap(&array[i - 1], &array[i]);
				new_size = i;
				print_array(array, size);
			}
		}
		size = new_size;
	}
}
