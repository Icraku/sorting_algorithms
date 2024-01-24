#include "sort.h"

/**
 * bubble_sort - Sort elements of an array in ascending order of values.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tempo, swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
        swapped = 0;

        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                tempo = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tempo;
                print_array(array, size);
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}
