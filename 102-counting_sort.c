#include "sort.h"

/**
 * counting_sort - sort an array of integers in ascending
 * order using the sort algorithm
 * @array: pointer to array
 * @size: size of the array
 **/
void counting_sort(int *array, size_t size)
{
	int x, j, *count_array, *aux;
	size_t i;

	if (!array || size < 2)
		return;
	x = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > x)
			x = array[i];
	}
	count_array = calloc((x + 1), sizeof(int));
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]++;
	}
	for (j = 1; j < x; j++)
	{
		count_array[j + 1] += count_array[j];
	}
	print_array(count_array, x + 1);
	aux = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]--;
		aux[count_array[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = aux[i];
	}
	free(aux);
	free(count_array);
}

