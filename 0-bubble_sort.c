#include "sort.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm in the file
 * @array: The array of integers to sort algorithm
 * @size: Number elements of array.
 * Return: Sorts new array.
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, z, l;
	size_t aux = size - 1;
	size_t x;

	if (!array || !size || size <= 0)
		return;
	l = 0;
	for (z = 0; z < aux; z++)
	{
		for (i = 0; i < aux - l; i++)
		{
			if (array[i] > array[i + 1])
			{
				x = array[i];
				array[i] = array[i + 1];
				array[i + 1] = x;
				print_array(array, size);
			}
		}
		l++;
	}
}
