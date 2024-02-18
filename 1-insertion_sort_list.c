#include "sort.h"

/**
 * insertion_sort_list - The insertion sorting algorithm
 * @list: pointer to the head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insert_n;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* start from the second node */
	current = (*list)->next;
	while (current)
	{
		insert_n = current->prev;
		while (insert_n && insert_n->n > current->n)
		{
			insert_n->next = current->next;
			/* update prev pointer on last node to link with the inserted node */
			if (current->next)
				current->next->prev = insert_n;

			/* current node will point to the node before the inserted node */
			current->prev = insert_n->prev;
			/* current node will point to the inserted node */
			current->next = insert_n;

			/* the node before the inserted node will point to the current node */
			/* if the inserted node had a node before it */
			if (insert_n->prev)
				insert_n->prev->next = current;
			else
				*list = current;

			/* update inserted node's prev pointer to point to the current node */
			insert_n->prev = current;
			/* update inserted node to be to the node before the current node */
			insert_n = current->prev;

			print_list(*list);
		}
		/* move to next unsorted node */
		current = current->next;
	}
}
