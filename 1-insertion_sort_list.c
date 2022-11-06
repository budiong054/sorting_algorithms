#include "sort.h"

/**
 * len_list - Return the length of the list
 * @list: The list
 * Return: The length of the list
 */
int len_list(listint_t *list)
{
	int len = 0;
	while (list)
	{
		len++;
		list = list->next;
	}
	return (len);
}


/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the insertion sort algorithm
 * @list: The list to be sorted
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *temp;
	listint_t *prev_element;
	int len;

	len = len_list(*list);
	if (len < 2)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		current = current->next;
		while (temp->prev && (temp->prev->n > temp->n))
		{
			prev_element = temp->prev;
			prev_element->next = temp->next;
			if (temp->next)
				temp->next->prev = prev_element;
			temp->next = prev_element;
			temp->prev = prev_element->prev;
			if (prev_element->prev)
				prev_element->prev->next = temp;
			prev_element->prev = temp;
			if (prev_element == *list)
				*list = temp;
			print_list(*list);
		}
	}
}
