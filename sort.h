#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#define INCREMENT 1
#define DECREMENT -1

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void radix_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *node);
listint_t *get_dlistint_lelem(listint_t *h);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
int getCantRep(int num);
void sort_alg(int *arr, int left, int right, size_t size);
int split(int *arr, int left, int right, size_t size);
void swap(listint_t **head, listint_t *node1, listint_t *node2);
void heap_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
#endif /** END _SORT_H_ **/
