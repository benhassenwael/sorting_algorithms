#include "sort.h"


/**
 * swap - function to swap two nodes in a doubly linked list
 * @left: left node to swap
 * @right: right node to swap
 */
void swap(listint_t *left, listint_t *right)
{
	if (left->prev != NULL)
		left->prev->next = right;
	if (right->next != NULL)
		right->next->prev = left;
	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
}

/**
 * cocktail_sort_list - cocktail sort algorithm on a list
 * @list: list to be sorted
 *
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *i;

	do {
		swapped = 0;
		i = *list;
		while (i->next)
		{
			if (i->n > (i->next)->n)
			{
				if (i == *list)
					*list = i->next;
				swap(i, i->next);
				print_list(*list);
				swapped = 1;
			}
			else
				i = i->next;
		}
		i = i->prev;
		if (!swapped)
			break;
		swapped = 0;
		while (i)
		{
			if (i->n > (i->next)->n)
			{
				if (i == *list)
					*list = i->next;
				swap(i, i->next);
				print_list(*list);
				swapped = 1;
			}
			i = i->prev;
		}
	} while (swapped);
}
