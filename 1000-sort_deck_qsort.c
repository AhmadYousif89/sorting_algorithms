#include "deck.h"

/**
 * get_value - Get the numerical value of a card.
 * @deck: A pointer to a deck node.
 *
 * Return: The numerical value of the card.
 */
int get_value(const deck_node_t *deck)
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
 * compare_cards - Compare two cards based on the specified sorting strategy.
 * @a: Pointer to the first card.
 * @b: Pointer to the second card.
 *
 * Return: Negative if a < b, positive if a > b, 0 if equal.
 */
int compare_cards(const void *a, const void *b)
{
	int kind_diff;

	const deck_node_t *card_a = *(const deck_node_t **)a;
	const deck_node_t *card_b = *(const deck_node_t **)b;

	kind_diff = card_a->card->kind - card_b->card->kind;
	if (kind_diff != 0)
		return (kind_diff);

	return (get_value(card_a) - get_value(card_b));
}

/**
 * sort_deck - Sort a deck of cards using qsort.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	size_t i, deck_size = 0;
	deck_node_t *current;
	deck_node_t **deck_array;

	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	for (current = *deck; current; current = current->next)
		deck_size++;

	deck_array = malloc(deck_size * sizeof(deck_node_t *));
	if (deck_array == NULL)
		return;

	current = *deck;
	for (i = 0; i < deck_size; current = current->next)
		deck_array[i++] = current;

	qsort(deck_array, deck_size, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < deck_size - 1; i++)
	{
		deck_array[i]->next = deck_array[i + 1];
		deck_array[i + 1]->prev = deck_array[i];
	}

	deck_array[0]->prev = NULL;
	deck_array[deck_size - 1]->next = NULL;

	*deck = deck_array[0];

	free(deck_array);
}
