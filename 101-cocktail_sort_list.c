#include "sort.h"

/**
 * _swap - Swaps two nodes of doubly linked lists in file
 *
 * @node: node base to change
 * @list: double link list head
 *
 * Return: No Return
 */
void _swap(listint_t **node, listint_t **list)
{
	listint_t *tmp1 = *node, *tmp2, *tmp3;


	if (!(*node)->prev)
		*list = (*node)->next;

	tmp1 = tmp3 = *node;
	tmp2 = tmp1->next;

	tmp1->next = tmp2->next;
	tmp3 = tmp1->prev;
	tmp1->prev = tmp2;
	tmp2->next = tmp1;
	tmp2->prev = tmp3;

	if (tmp2->prev)
		tmp2->prev->next = tmp2;


	if (tmp1->next)
		tmp1->next->prev = tmp1;

	*node = tmp2;

}
/**
 * cocktail_sort_list - functions that sorts a doubly linked list
 * of integers in ascending order using the Cocktail shakes sort algorithm
 *
 * @list: head of list to be sorted(Double Linked List)
 *
 * Return: No Return
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *aux;
	int s = 0, n = -1, m = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (m >= n)
	{
		n++;
		while (head->next && s != m)
		{
			if (head->n > head->next->n)
			{
				aux = head;
			       _swap(&aux, list);
			       print_list(*list);
			       head = aux;
			}

			s++;
			head = head->next;
		}

		if (n == 0)
			m = s;
		m--;
		while (head->prev && s >= n)
		{
			if (head->n < head->prev->n)
			{
				aux = head->prev;
				_swap(&aux, list);
				print_list(*list);
				head = aux->next;
			}
			s--;
			head = head->prev;
		}
	}
}
