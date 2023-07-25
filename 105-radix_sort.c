#include <stdlib.h>
#include "sort.h"

/**
 * csort2 - radix sort auxiliary func.
 *
 * @array:  data of an array to be sorted
 * @buff: buff malloc 
 * @size:data size
 * @lsd: Less signi digit.
 *
 * Return: No Return
 */

void csort2(int *array, int **buff, int size, int lsd)
{
	int k, l, csize = 10, um;
	int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int arr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (k = 0; k < size; k++)
	{
		um = array[k];
		for (l = 0; l < lsd; l++)
			if (l > 0)
				um = um / 10;
		um = um % 10;
		buff[um][arr[um]] = array[k];
		arr[um] += 1;
	}

	for (k = 0, l = 0; k < csize; k++)
	{
		while (arr[k] > 0)
		{
			array[l] = buff[k][arr2[k]];
			arr2[k] += 1, arr[k] -= 1;
			l++;
		}
	}

	print_array(array, size);
}

/**
 * csort - radix sort aux func.
 *
 * @array: data of an array to be sorted
 * @size: data size
 * @lsd: Less signifi digit
 *
 * Return: No Return
 */

void csort(int *array, int size, int lsd)
{
	int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int k, l, um, csize = 10, **buff;

	for (k = 0; k < size; k++)
	{
		um = array[k];
		for (l = 0; l < lsd; l++)
			if (l > 0)
				um = um / 10;
		um = um % 10;
		arr[um] += 1;
	}

	if (arr[0] == size)
		return;

	buff = malloc(sizeof(int *) * 10);
	if (!buff)
		return;

	for (k = 0; k < csize; k++)
		if (arr[k] != 0)
			buff[k] = malloc(sizeof(int) * arr[k]);


	csort2(array, buff, size, lsd);

	csort(array, size, lsd + 1);

	for (k = 0; k < csize; k++)
		if (carr[k] > 0)
			free(buff[k]);
	free(buff);
}
/**
 * radix_sort - using the radix sort algorithm
 * to sorts an array of integers in ascending order
 *
 * @array: data of an array to be sorted
 * @size: size of data
 *
 * Return: No Return
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	csort(array, size, 1);
}
