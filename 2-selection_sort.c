#include "sort.h"
#include <stdio.h>


/**
 * selection_sort - sorts an array using some
 * selection sort algorithm.
 * @array: a given array.
 * @size: size of the array in file
 **/

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 1, aux = 0, min = 0, limit = size - 1;

	if (size < 2)
		return;

	while (i < limit)
	{
		if (j == size)
		{
			if (i != min)
			{
				aux = array[i];
				array[i] = array[min];
				array[min] = aux;
				print_array(array, size);
			}

			++i;
			min = i;
			j = i + 1;
			continue;
		}

		if (array[min] > array[j])
			min = j;

		++j;
	}
}
