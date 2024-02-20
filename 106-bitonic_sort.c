#include "sort.h"

/**
 * swap - Swaps two numbers based on the direction.
 * @arr: Array of integers.
 * @i: Index of the first element to swap.
 * @j: Index of the second element to swap.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void swap(int *arr, size_t i, size_t j, int dir)
{
	if ((arr[i] > arr[j] && dir == 1) || (arr[i] < arr[j] && dir == 0))
	{
		arr[i] = arr[i] + arr[j];
		arr[j] = arr[i] - arr[j];
		arr[i] = arr[i] - arr[j];
	}
}

/**
 * bitonic_merge - Performs the merging step of the Bitonic Sort algorithm.
 * @arr: Array of integers.
 * @idx: Starting index for merging.
 * @size: Size of the array or subarray.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *arr, size_t idx, size_t size, int dir)
{
	size_t k = size / 2, i;

	if (size > 1)
	{
		for (i = idx; i < idx + k; i++)
			swap(arr, i, i + k, dir);

		bitonic_merge(arr, idx, k, dir);
		bitonic_merge(arr, idx + k, k, dir);
	}
}

/**
 * bitonic_recursive - Recursively sorts a Bitonic sequence.
 * @arr: Array of integers.
 * @cnt: Current size of the subarray.
 * @idx: Starting index for sorting.
 * @size: Total size of the array.
 * @dir: Sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_recursive(int *arr, size_t cnt, size_t idx, size_t size, int dir)
{
	size_t new_size = cnt / 2;
	char *s = (dir == 1) ? "UP" : "DOWN";

	if (cnt > 1)
	{
		/* Print the merging phase */
		printf("Merging [%lu/%lu] (%s):\n", cnt, size, s);
		print_array(arr + idx, cnt);

		/* Sort & Merge*/
		bitonic_recursive(arr, new_size, idx, size, 1);
		bitonic_recursive(arr, new_size, idx + new_size, size, 0);
		bitonic_merge(arr, idx, cnt, dir);

		/* Print the result phase */
		printf("Result [%lu/%lu] (%s):\n", cnt, size, s);
		print_array(arr + idx, cnt);
	}
}

/**
 * bitonic_sort - Sorts an array using the Bitonic Sort algorithm.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Start the Bitonic Sort with initial ascending direction */
	bitonic_recursive(array, size, 0, size, 1);
}
