#ifndef SORT_H
#define SORT_H


#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/**
 * struct listint_s - Doubly linked list nodes
 *
 * @n: Integers stored in the node
 * @prev: Pointer to the previous element of the lists
 * @next: Pointer to the next element of the lists
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Print Functions */

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);


/* Sorting Algorithm Functions */

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);


/*Advanced Tasks*/
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
