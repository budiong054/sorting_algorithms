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
	
	_qsort(array, 0, size - 1);
}

void _qsort(int *array, ssize_t low_index, ssize_t high_index)
{
	int pivot, temp;
	ssize_t p;	/* partition */
	ssize_t j;
	ssize_t size;

	size = sizeof(*array) / sizeof(array[0]);

	if (low_index >= high_index || low_index < 0)
		return;

	pivot = array[high_index];
	
	p = low_index - 1;

	for (j = low_index; j < high_index - 1; j++)
	{
		if (array[j] <= pivot)
		{
			p++;
			temp = array[j];
			array[j] = array[p];
			array[p] = temp;
			print_array(array, size);
		}
	}
	p++;
	temp = array[p];
	array[p] = array[high_index];
	array[high_index] = temp;

	_qsort(array, low_index, p - 1);
	_qsort(array, p + 1, high_index);
}
