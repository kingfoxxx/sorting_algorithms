#include "sort.h"

/**
*swap - two elements position into an array
*@array: array
*@item1: array element one
*@item2: array element two
*/

void swap(int *array, ssize_t item1, ssize_t item2)
{
	int mp;

	mp = array[item1];
	array[item1] = array[item2];
	array[item2] = mp;
}

/**
 *hoare_partition - implementation of hoare
 partition sorting scheme
 *@array: array
 *@first: beginning of array element
 *@last: end of array element
 *@size: size array
 *Return: return the position of the last element sorted
 */

int hoare_partition(int *array, int first, int last, int size)
{
	int urrent = first - 1, finder = last + 1;
	int ivot = array[last];

	while (1)
	{

		do {
			urrent++;
		} while (array[urrent] < ivot);
		do {
			finder--;
		} while (array[finder] > ivot);
		if (urrent >= finder)
			return (urrent);
		swap(array, urrent, finder);
		print_array(array, size);
	}
}

/**
 *qs - implementation of quicksort algorithm
 *@array: array
 *@first: beginning array element
 *@last: end array element
 *@size: array size
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t osition = 0;

	if (first < last)
	{
		osition = hoare_partition(array, first, last, size);
		qs(array, first, osition - 1, size);
		qs(array, osition, last, size);
	}
}
/**
 *quick_sort_hoare - terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
