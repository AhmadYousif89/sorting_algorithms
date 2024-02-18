#include "sort.h"

/**
 * swap - Swap two numbers
 * @arr: pointer to the array
 * @size: size of the array
 * @a: pointer to number
 * @b: pointer to number
 */
void swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

/**
 * partition - Calculate the pivot index
 * @arr: pointer to the array
 * @size: size of the array
 * @lo: starting index
 * @hi: ending index
 *
 * Return: the pivot index
 * Description: Uses the Hoare partition scheme.
 */
int partition(int *arr, size_t size, int lo, int hi)
{
	int pivot = arr[hi];
	int i = lo - 1, j = hi + 1;

	while (i < j)
	{
		do
		{
			i++;
		} while (arr[i] < pivot);
		do
		{
			j--;
		} while (arr[j] > pivot);

		if (i < j)
		{
			swap(arr + i, arr + j);
			print_array(arr, size);
		}
	}

	return (i);
}

/**
 * recursive_sort - Recursivly sort the array.
 * @arr: pointer to the array.
 * @size: The size of the array.
 * @lo: The starting index.
 * @hi: The ending index.
 */
void recursive_sort(int *arr, size_t size, int lo, int hi)
{
	int pivot_idx;

	if (lo < hi)
	{
		pivot_idx = partition(arr, size, lo, hi);
		recursive_sort(arr, size, lo, pivot_idx - 1);
		recursive_sort(arr, size, pivot_idx, hi);
	}
}

/**
 * quick_sort_hoare - The quick sorting algorithm
 * @arr: pointer to the array
 * @size: size of the array
 */
void quick_sort_hoare(int *arr, size_t size)
{
	if (arr == NULL || size < 2)
		return;

	recursive_sort(arr, size, 0, size - 1);
}
