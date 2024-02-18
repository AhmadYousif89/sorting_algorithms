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
 * Return: the pivot index
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
 * quick_sort - The quick sorting algorithm
 * @arr: pointer to the array
 * @size: size of the array
 */
void quick_sort(int *arr, size_t size)
{
	size_t pivot_idx;

	if (arr == NULL || size < 2)
		return;

	pivot_idx = partition(arr, size, 0, size - 1);
	/* First half to the pivot*/
	quick_sort(arr, pivot_idx);
	/* Second half after the pivot */
	quick_sort(arr + pivot_idx + 1, size - pivot_idx - 1);
}
