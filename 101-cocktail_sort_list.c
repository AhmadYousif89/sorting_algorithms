#include "sort.h"

/**
 * swap_forwards - Swap nodes from head to tail.
 * @list: pointer to the head of the list.
 * @tail: pointer to the tail of the list.
 * @current: pointer to the current swapping node.
 */
void swap_forwards(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->next;

	if ((*current)->prev)
		(*current)->prev->next = temp;
	else
		*list = temp;

	temp->prev = (*current)->prev;
	(*current)->next = temp->next;

	if (temp->next)
		temp->next->prev = *current;
	else
		*tail = *current;

	(*current)->prev = temp;
	temp->next = *current;
	*current = temp;
	print_list(*list);
}

/**
 * swap_backwards - Swap nodes from tail to head.
 * @list: pointer to the head of the list.
 * @tail: pointer to the tail of the list.
 * @current: pointer to the current swapping node.
 */
void swap_backwards(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *temp = (*current)->prev;

	if ((*current)->next)
		(*current)->next->prev = temp;
	else
		*tail = temp;

	temp->next = (*current)->next;
	(*current)->prev = temp->prev;

	if (temp->prev)
		temp->prev->next = *current;
	else
		*list = *current;

	(*current)->next = temp;
	temp->prev = *current;
	*current = temp;
	print_list(*list);
}

/**
 * cocktail_sort_list - Sort a doubly-linked list.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 *
 * Description: Sort using the cocktail shaker algorithm.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *tail;
	int swapped;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	tail = *list;
	while (tail->next)
		tail = tail->next;

	do {
		swapped = 0;
		/* move forward to the tail pointer (last node) */
		for (head = *list; head != tail; head = head->next)
			if (head->n > head->next->n) /* compare and swap */
				swap_forwards(list, &tail, &head), swapped = 1;

		/* move backward to the list pointer (first node) */
		for (head = head->prev; head != *list; head = head->prev)
			if (head->prev->n > head->n) /* compare and swap */
				swap_backwards(list, &tail, &head), swapped = 1;

	} while (swapped);
}
