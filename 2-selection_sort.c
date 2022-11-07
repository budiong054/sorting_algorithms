#include "sort.h"

/***
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: The array to be sorted
 * @size: size of the array
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	size_t min_index; /* index of the mininum value */
	int temp;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			print_array(array, size);
		}
	}
}
