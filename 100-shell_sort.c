#include "sort.h"

/**
 * gap_size - Calculate the gap size between the elements
 * @size: the size of the array
 *
 * Description: Using the Knuth sequence to calculate the gap.
 * Return: the gap
 */
size_t gap_size(size_t size)
{
	size_t gap = 1;

	while (gap < size)	   /* if size = 8 */
		gap = gap * 3 + 1; /* max gap = 13 */

	return ((gap - 1) / 3); /* actual gap: (13 -1) / 3 = 4 */
}

/**
 * shell_sort - The Shell sort algorithm, using the Knuth sequence
 * @arr: pointer to the array
 * @size: the size of the array
 */
void shell_sort(int *arr, size_t size)
{
	size_t i, j, gap = gap_size(size);
	int temp;
	/* if size = 8 | pass 1: gap = 4 | pass 2: gap = 1 */
	while (gap > 0)
	{
		/* pass 1: 4 ... 8 | 5 ... 8 | 6 ... 8 | 7 ... 8 */
		for (i = gap; i < size; i++)
		{
			temp = arr[i]; /* temp = value at idx [4]*/
			for (j = i; j > gap - 1 && temp < arr[j - gap]; j -= gap)
				arr[j] = arr[j - gap]; /* place value at idx [0] in idx [4] etc.. */
			arr[j] = temp;			   /* place value at idx [4] in idx [0] etc.. */
		}
		print_array(arr, size);
		/* pass 2: 1 ... 8 | 2 ... 8 | 3 ... 8 | 4 ... 8 */
		gap = (gap - 1) / 3;
	}
}
