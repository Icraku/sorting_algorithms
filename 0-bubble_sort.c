#include "sort.h"

/**
 * bubble_sort - sort elements of an array in ascending order of values
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t pos, ind, tempo = 0;

	if (size < 2)
		return;
	for (pos = 0; pos < size; i++)
	{
		for (ind = 0; ind < size; ind++)
		{
			if (array[ind] > array[ind + 1] && array[ind + 1])
			{
				tempo = array[ind];
				array[ind] = array[ind + 1];
				array[ind + 1] = tempo;
				print_array(array, size);
			}
		}
	}
}
