#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t j;
	int swap;
	size_t n = size;
	int temp;

	if (size < 2)
		return;

	while (1)
	{
		swap = 0; /* false */
		for (j = 1; j < n; j++)
		{
			if (array[j - 1] > array[j])
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				swap = 1; /* true */
				print_array(array, size);
			}
		}

		if (!swap)
			break;
		n--;
	}
}
