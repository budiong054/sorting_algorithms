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
	int fswap; /* swap_flag */
	size_t n = size;

	if (size < 2)
		return;

	while (1)
	{
		fswap = 0; /* false */
		for (j = 1; j < n; j++)
		{
			if (array[j - 1] > array[j])
			{
				swap(&array[j - 1], &array[j]);
				fswap = 1; /* true */
				print_array(array, size);
			}
		}

		if (!fswap)
			break;
		n--;
	}
}

/**
 * swap - Swaps the position of two numbers
 * @a: The first integer
 * @b: The Second integer
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
