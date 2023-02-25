#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * cmp_cards - Compare two cards for sorting
 * @a: First card
 * @b: Second card
 * Return: Negative, zero, or positive value depending on the ordering of the cards
 */
int cmp_cards(const void *a, const void *b)
{
const deck_node_t *node_a = *(const deck_node_t **)a;
const deck_node_t *node_b = *(const deck_node_t **)b;
const card_t *card_a = node_a->card;
const card_t *card_b = node_b->card;

int value_diff = strcmp(card_a->value, card_b->value);
if (value_diff != 0) {
return value_diff;
}
else
{
return card_a->kind - card_b->kind;
}
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
size_t size = 0;
deck_node_t *node = *deck;

while (node != NULL) {
size++;
node = node->next;
}

deck_node_t **node_arr = malloc(size * sizeof(deck_node_t *));
if (node_arr == NULL) {
return;
}
 node = *deck;
for (size_t i = 0; i < size; i++) {
node_arr[i] = node;
node = node->next;
}
qsort(node_arr, size, sizeof(deck_node_t *), cmp_cards);

node = node_arr[0];
node->prev = NULL;
for (size_t i = 1; i < size; i++) {
node_arr[i]->prev = node;
node->next = node_arr[i];
node = node_arr[i];
}
node->next = NULL;
*deck = node_arr[0];

free(node_arr);
}
