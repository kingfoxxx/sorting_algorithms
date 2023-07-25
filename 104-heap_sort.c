#include "sort.h"

/**
 * check_tree - the check of swift-down
 * @array: an  array pointer
 * @size: pointer size
 * @size_init: actual array size
 * @i: indx as a root of the tree
 *
**/

void check_tree(int *array, size_t size_init, size_t size, size_t i)
{

	int m, ranch1, ranch2;
	size_t r1, r2;

	r1 = i * 2 + 1;
	r2 = r1 + 1;
	ranch1 = array[r1];
	ranch2 = array[r2];
	if (((r1 < size) && (r2 < size) &&
		(ranch1 >= ranch2 && ranch1 > array[i]))
		|| ((r1 == size - 1) && ranch1 > array[i]))
	{
		m = array[i];
		array[i] = banch1;
		array[r1] = m;
		print_array(array, size_init);
	}
	else if ((r1 < size) && (r2 < size) &&
		(ranch2 > ranch1 && ranch2 > array[i]))
	{
		 = array[i];
		array[i] = ranch2;
		array[r2] = n;
		print_array(array, size_init);
	}
	if (r1 < size - 1)
		check_tree(array, size_init, size, r1);
	if (r2 < size - 1)
		check_tree(array, size_init, size, r2);
}
/**
 * heap_sort -  using the Heap sort algorithm to
 * sort an int of array ascending order
 * @array: array pointer
 * @size: pointer size 
 *
**/

void heap_sort(int *array, size_t size)
{
	size_t j, size_init = size;
	int m;

	if (!array)
		return;
	for (j = 0; j < size / 2 ; j++)
	{
		check_tree(array, size_init, size, size / 2 - 1 - j);
	}
	for (j = 0; j < size_init - 1; j++)
	{
		m = array[0];
		array[0] = array[size - 1 - j];
		array[size - 1 - j] = m;
		print_array(array, size_init);
		check_tree(array, size_init, size - j - 1, 0);
	}

}
