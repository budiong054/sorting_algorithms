#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	_qsort(array, 0, size - 1, size);
}

/**
 * _qsort - Sort the array recursively
 * @array: The array to be sorted
 * @lb: The lower bound of the index
 * @ub: The upper bound of the index
 * @size: The size of the array
 * Return: Nothing
 */

void _qsort(int *array, ssize_t lb, ssize_t ub, size_t size)
{
	size_t p;	/* piovt index */

	if (lb >= ub)
		return;

	p = partition(array, lb, ub, size);

	_qsort(array, lb, p - 1, size);
	_qsort(array, p + 1, ub, size);
}

/**
 * partition - Partition the array into two part
 * @array: The array to be partition
 * @lb: The lower bound of the index
 * @ub: The upper bound of the index
 * @size: The size of the array
 * Return: The right index of the pivot element
 */

size_t partition(int *array, size_t lb, size_t ub, size_t size)
{
	int pivot;
	size_t i, j;

	pivot = array[ub];
	i = lb - 1; /* temporary pivot index */

	for (j = lb; j < ub; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	i++;
	swap(&array[i], &array[ub]);
	print_array(array, size);
	return (i); /* index of the pivot elemenet */
}

/**
 * swap - Swaps the position of two numbers
 * @a: The first integer
 * @b: The second integer
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
