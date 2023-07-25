#include "sort.h"
#include <stdio.h>

/**
 * swap - changing of  two values in an
 * ascending or descending order
 * @arr: array
 * @item1: first item
 * @item2: second item
 * @order: 1: ascending , 0 descending
 */

void swap(int arr[], int item1, int item2, int order)
{
	int emp;

	if (order == (arr[item1] > arr[item2]))
	{
		emp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = emp;
	}
}
/**
 * merge - bitonic sequences sorting in both orders
 * @arr: array
 * @low:element one
 * @nelemnt: elements figure
 * @order: 1: ascending , 0 descending
 */
void merge(int arr[], int low, int nelemnt, int order)
{
	int id, j;

	if (nelemnt > 1)
	{
		id = nelemnt / 2;
		for (j = low; j < low + id; j++)
			swap(arr, i, j + id, order);
		merge(arr, low, id, order);
		merge(arr, low + id, id, order);
	}
}

/**
 * bitonicsort -  sort algorithm implements
 * @arr: array
 * @low: element one
 * @nelemnt: figure of elements
 * @order: 1: ascending , 0 descending
 * @size: lenght of array
 */

void bitonicsort(int arr[], int low, int nelemnt, int order, int size)
{
	int id;

	if (nelemnt > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		id = nelemnt / 2;
		bitonicsort(arr, low, id, 1, size);
		bitonicsort(arr, low + id, id, 0, size);
		merge(arr, low, nelemnt, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}
/**
 * bitonic_sort - preparation of the
 * terrain to bitonic sort algorithm
 * @array: array
 * @size: lenght of array
 */

void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
