#include "deck.h"

/**
 * get_value - Get the numerical value of a card.
 * @deck: A pointer to a deck node.
 *
 * Return: The numerical value of the card.
 */
int get_value(deck_node_t *deck)
{
	int i, size;
	const char *values[] = {
		"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen"};

	size = sizeof(values) / sizeof(values[0]);
	for (i = 0; i < size; i++)
		if (strcmp(deck->card->value, values[i]) == 0)
			return (i);

	return (i + 1); /* Default value for unknown cards */
}

/**
 * swap_nodes - Swap two nodes in a doubly-linked list.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 * @a: First node to swap (previous to current node).
 * @b: Second node to swap (current node).
 */
void swap_nodes(deck_node_t **deck, deck_node_t *a, deck_node_t *b)
{
	a->next = b->next;

	if (b->next)
		b->next->prev = a;

	b->prev = a->prev;
	b->next = a;

	if (a->prev)
		a->prev->next = b;
	else
		*deck = b;

	a->prev = b;
}

typedef int (*compare_t)(deck_node_t *, deck_node_t *, int);
/**
 * insertion_sort_deck - Sort a deck using insertion sort.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 * @compare: Pointer to the comparison function for sorting.
 * @sort_flag: Sorting flag (1 for sorting by kind, 0 for sorting by value).
 */
void insertion_sort_deck(deck_node_t **deck, compare_t compare, int sort_flag)
{
	deck_node_t *current = (*deck)->next, *insert, *next;

	while (current)
	{
		next = current->next;
		insert = current->prev;
		while (insert && compare(insert, current, sort_flag) > 0)
		{
			swap_nodes(deck, insert, current);
			insert = current->prev;
		}
		current = next;
	}
}

/**
 * compare - Compare two nodes based on the specified sorting strategy.
 * @a: First node to compare.
 * @b: Second node to compare.
 * @sort_flag: Sorting flag (1 for sorting by kind, 0 for sorting by value).
 *
 * Return: Positive if a > b, negative if a < b, 0 if equal.
 */
int compare(deck_node_t *a, deck_node_t *b, int sort_flag)
{
	if (sort_flag)
		return (a->card->kind - b->card->kind);

	if (a->card->kind == b->card->kind)
		return (get_value(a) - get_value(b));

	return (0);
}

/**
 * sort_deck - Sort a deck of cards.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck(deck, compare, 1); /* Sort kinds first */
	insertion_sort_deck(deck, compare, 0); /* Sort values second */
}
