#include "sort.h"
#include <stdio.h>



/**
 * insertion_sort_list -  DLL integers to be sorted in ascending
 * order by using d insertion sort algorithm
 *
 * @list: double linked list
 * Return: no return
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tr, *mp;

	if (!list)
		return;

	tr = *list;

	while (tr)
	{
		while (tr->next && (tr->n > tr->next->n))
		{
			mp = tr->next;
			tr->next = mp->next;
			mp->prev = tr->prev;

			if (tr->prev)
				tr->prev->next = mp;

			if (mp->next)
				mp->next->prev = tr;

			tr->prev = mp;
			mp->next = tr;

			if (mp->prev)
				tr = mp->prev;
			else
				*list = mp;

			print_list(*list);
		}
		tr = tr->next;
	}
}
