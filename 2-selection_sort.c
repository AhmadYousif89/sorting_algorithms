#include "sort.h"

/**
 * selection_sort - The selection sorting algorithm
 * @array: pointer to int
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j_min, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		/* assuming the element with the min value is at the 2nd index */
		j_min = i;
		/* update the index of j_min if it has greater value than index j */
		for (j = i + 1; j < size; j++)
			if (array[j] < array[j_min])
				j_min = j;

		if (array[i] > array[j_min])
		{
			tmp = array[i];
			array[i] = array[j_min];
			array[j_min] = tmp;
			print_array(array, size);
		}
	}
}
