#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "deck.h"

/**
 * cardcmp - compares two card
 * @p1: card 1
 * @p2: card 2
 * Return: result of comparison
 */


int cardcmp(const void *p1, const void *p2)
{
const card_t *card1, *card2;
int cmp;

card1 = ((deck_node_t *)p1)->card;
card2 = ((deck_node_t *)p2)->card;
cmp = strcmp(card1->value, card2->value);
if (cmp != 0)
{
return cmp;
}
else
{
return card1->kind - card2->kind;
}
}

/**
 * sort_deck - sorts a deck of card with qsort
 * @deck: deck of card to sort
 * Return: Nothing
 */

void sort_deck(deck_node_t **deck)
{
deck_node_t *node, *temp;
deck_node_t *sorted_deck = NULL;
while (*deck)
{
node = *deck;
*deck = node->next;
node->prev = NULL;
node->next = NULL;

if (sorted_deck == NULL)
{
sorted_deck = node;
continue;
}

temp = sorted_deck;
while (temp != NULL && cardcmp(&node, &temp) > 0)
{
temp = temp->next;
}

if (temp == NULL)
{
deck_node_t *last = sorted_deck;
while (last->next != NULL)
{
last = last->next;
}
last->next = node;
node->prev = last;
}
else
{
if (temp->prev == NULL)
{
sorted_deck = node;
}
else
{
temp->prev->next = node;
}
node->prev = temp->prev;
temp->prev = node;
node->next = temp;
}
}

*deck = sorted_deck;
}
