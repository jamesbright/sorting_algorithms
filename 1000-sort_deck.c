#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * compare_cards - compares cards to sort
 * @a: card a
 * @b: card b
 * Return: result of comparison
 */

static int compare_cards(const void *a, const void *b)
{
const card_t *card_a = (*(const deck_node_t **)a)->card;
const card_t *card_b = (*(const deck_node_t **)b)->card;

/* Sort by kind first, then by value */
if (card_a->kind != card_b->kind)
return card_a->kind - card_b->kind;
else
return strcmp(card_a->value, card_b->value);
}

/**
 * sort_deck - sorts a deck of card
 * @deck:deck of cards
 * Return: Nothing
 */

void sort_deck(deck_node_t **deck)
{
int i;
deck_node_t *node_array[52];
deck_node_t *current;

/* Create an array of pointers to the deck nodes */
current = *deck;
for (i = 0; i < 52; i++) {
node_array[i] = current;
current = current->next;
}

/* Sort the array of pointers using qsort */
qsort(node_array, 52, sizeof(deck_node_t *), compare_cards);

/* Re-link the deck nodes in the new order */
for (i = 0; i < 52; i++) {
node_array[i]->prev = (i == 0) ? NULL : node_array[i-1];
node_array[i]->next = (i == 51) ? NULL : node_array[i+1];
}
*deck = node_array[0];
}
