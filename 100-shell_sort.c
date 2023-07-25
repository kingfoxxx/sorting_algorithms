#include "sort.h"
#include <stdio.h>

/**
 * _swap - swaped 2 value
 * @array: the array for swap him value
 * @i: First index
 * @j: Second index
 * Return: Nothing
 */

void _swap(int *array, int i, int j)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

/**
 * shell_sort - sort the list and print the changes in files
 * @array: The array to sort.
 * @size: Size of the array
 * Return: Nothing
 */

void shell_sort(int *array, size_t size)
{
	size_t z = 0,  i, j;

	if (size < 2)
		return;

	while (z <= size / 3)
		z = z * 3 + 1;

	while (z >= 1)
	{
		for (i = z; i < size; i++)
			for (j = i; j >= z && array[j] < array[j - z]; j -= z)
				_swap(array, j, j - z);
		z /= 3;
		print_array(array, size);
	}
}
