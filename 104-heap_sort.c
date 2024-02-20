#include "sort.h"

/**
 * swap - Swap two numbers.
 * @a: first number.
 * @b: second number.
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * sift_down - Implement the sift-down operation in a heap sort algorithm.
 * @arr: An array of integers representing the binary heap.
 * @size: The total number of elements in the array.
 * @end: The index indicating the end of the heap (exclusive).
 * @index: The index of the element to be sifted down.
 */
void sift_down(int arr[], size_t size, size_t end, size_t index)
{
	size_t largest = index;		  /* Largest element on the tree */
	size_t child = 2 * index + 1; /* Left Child */

	if (child < end && arr[child] > arr[largest])
		largest = child;

	child = 2 * index + 2; /* Right Child */
	if (child < end && arr[child] > arr[largest])
		largest = child;

	if (largest != index) /* if largest is not the current element */
	{
		swap(&arr[index], &arr[largest]);
		print_array(arr, size);
		sift_down(arr, size, end, largest);
	}
}

/**
 * heap_sort - The heap sort algorithm of array of integers in ascending order.
 * @array: A pointer to an array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	/* build the heap */
	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, &array[i]);
		print_array(array, size);
		sift_down(array, size, i, 0);
	}
}
