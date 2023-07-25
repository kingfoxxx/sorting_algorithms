#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - array of integers
 *
 * @array: printed array
 * @size: elements in @array
 */

void print_array(const int *array, size_t size)
{
    size_t j;

   j = 0;
    while (array && j < size)
    {
        if (j > 0)
            printf(", ");
        printf("%d", array[j]);
        ++j;
    }
    printf("\n");
}
