#include "sort.h"
/**
 * swap - swap the node to the last node
 * @node: node swapped
 */
void swap(listint_t *node)
{
	listint_t *i, *j, *next;

	if (node->prev == NULL)
		return;
	i = (*node).prev;
	j = (*i).prev;
	next = (*node).next;
	if (j != NULL)
		(*j).next = node;
	(*node).prev = j;
	(*node).next = i;
	(*i).prev = node;
	(*i).next = next;
	if (next != NULL)
		(*next).prev = i;
}
/**
 * insertion_sort_list - sort doubly linked list
 * @list: double pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *current;

	if (!list || !*list)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		if ((*current).prev->n > (*current).n)
		{
			tmp = (*current).next;
			while ((*current).prev != NULL)
			{
				if ((*current).n < (*current).prev->n)
				{
					swap(current);
					while ((*list)->prev != NULL)
						(*list) = (*list)->prev;
					print_list(*list);
				}
				else
					break;
			}
			current = tmp;
		}
		else
			current = (*current).next;
	}
}
