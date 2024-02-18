#include "sort.h"

/**
 * swap - Swap two numbers
 * @arr: pointer to the array
 * @size: size of the array
 * @a: pointer to number
 * @b: pointer to number
 */
void swap(int *arr, size_t size, int *a, int *b)
{
	if (*a != *b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array(arr, size);
	}
}

/**
 * partition - Calculate the pivot index
 * @arr: pointer to the array
 * @size: size of the array
 * @lo: starting index
 * @hi: ending index
 *
 * Return: the pivot index
 * Description: Uses the Lomuto partition scheme.
 */
size_t partition(int *arr, size_t size, size_t lo, size_t hi)
{
	int pivot = arr[hi];
	size_t pivot_idx, j;

	for (pivot_idx = j = lo; j < hi; j++)
		if (arr[j] < pivot)
			swap(arr, size, &arr[j], &arr[pivot_idx++]);

	swap(arr, size, &arr[pivot_idx], &arr[hi]);

	return (pivot_idx);
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
		recursive_sort(arr, size, pivot_idx + 1, hi);
	}
}

/**
 * quick_sort - The quick sorting algorithm
 * @arr: pointer to the array
 * @size: size of the array
 */
void quick_sort(int *arr, size_t size)
{
	if (arr == NULL || size < 2)
		return;

	recursive_sort(arr, size, 0, size - 1);
}
