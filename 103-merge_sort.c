#include "sort.h"

/**
 * merge_sorted_arrays - Sort and print sub-arrays.
 * @arr: pointer to the original array
 * @start: the index of the left array
 * @mid: the middle index of the sub-arrays
 * @end: the index of the right array
 * @temp: pointer to the temp array
 */
void merge_sorted_arrays(int arr[], int start, int mid, int end, int temp[])
{
	int i, m = mid, s = start;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(arr + start, mid - start);
	printf("[right]: ");
	print_array(arr + mid, end - mid);
	/* Compare values */
	for (i = start; i < end; i++)
	{
		if (s < mid && (m >= end || temp[s] <= temp[m]))
			arr[i] = temp[s++];
		else
			arr[i] = temp[m++];
	}

	printf("[Done]: ");
	print_array(arr + start, end - start);
}

/**
 * merge_sort_recurtion - Divide an array into sub-arrays to be sorted.
 * @arr: pointer to the original array
 * @start: the index of the left array
 * @end: the index of the right array
 * @temp: pointer to the temp array
 */
void merge_sort_recurtion(int arr[], int start, int end, int temp[])
{
	int mid = start + (end - start) / 2; /* prevent potential int overflow */

	if (end - start < 2)
		return;

	merge_sort_recurtion(temp, start, mid, arr);
	merge_sort_recurtion(temp, mid, end, arr);

	merge_sorted_arrays(arr, start, mid, end, temp);
}

/**
 * merge_sort - Sort an array using the merge sort algorithm.
 * @array: pointer to the array
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	/* copy elements from (array) to (temp) */
	for (i = 0; i < size; i++)
		temp[i] = array[i];

	merge_sort_recurtion(array, 0, size, temp);
	free(temp);
}
