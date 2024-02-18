#include "sort.h"

/**
 * selection_sort - The selection sorting algorithm
 * @arr: pointer to the array
 * @size: size of the array
 */
void selection_sort(int *arr, size_t size)
{
	size_t i, j_min, j;

	if (arr == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		/* assuming the element with the min value is at the 2nd index */
		j_min = i;
		/* update the index of j_min if it has greater value than index j */
		for (j = i + 1; j < size; j++)
			if (arr[j] < arr[j_min])
				j_min = j;

		if (arr[i] > arr[j_min])
		{ /* arithmatic swap */
			arr[i] = arr[i] + arr[j_min];
			arr[j_min] = arr[i] - arr[j_min];
			arr[i] = arr[i] - arr[j_min];
			print_array(arr, size);
		}
	}
}
