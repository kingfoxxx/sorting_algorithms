#include "sort.h"

/**
 * swap_items - two items will be swapped inside an array.
 * @array:  Array modified.
 * @l:  left item indx.
 * @r: right item indx.
 */

void swap_items(int *array, size_t l, size_t r)
{
	int mp;

	if (array != NULL)
	{
		mp = array[l];
		array[l] = array[r];
		array[r] = mp;
	}
}


/**
 * quick_sort_range_lomuto - sub array sorted by using d
 * quick sort algor and Lomuto's partition scheme.
 * @array:the sub-array inside an array.
 * @low: sub-array starting position.
 * @high: The end of the sub-array.
 * @size: The array length.
 */

void quick_sort_range_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t j, l;
	int pi;

	if ((low >= high) || (array == NULL))
		return;
	pi = array[high];
	j = low;
	for (l = low; l < high; l++)
	{
		if (array[l] <= pi)
		{
			if (j != l)
			{
				swap_items(array, j, l;
				print_array(array, size);
			}
			j++;
		}
	}
	if (j != high)
	{
		swap_items(array, j, high);
		print_array(array, size);
	}
	if (j - low > 1)
		quick_sort_range_lomuto(array, low, j - 1, size);
	if (high - j > 1)
		quick_sort_range_lomuto(array, j + 1, high, size);
}

/**
 * quick_sort - array to be Sorted by using d  quick sort algor
 * and Lomuto's partition scheme.
 * @array: sort array.
 * @size: Array length.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quick_sort_range_lomuto(array, 0, size - 1, size);
	}
}
