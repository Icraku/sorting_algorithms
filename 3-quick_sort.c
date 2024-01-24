#include "sort.h"

/**
 * swap - Swap two elements in an array.
 * @array: The array of integers.
 * @item1: Index of the first element.
 * @item2: Index of the second element.
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quicksort.
 * @array: The array of integers.
 * @first: The starting index of the partition.
 * @last: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}

	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}

	return (current);
}

/**
 * lomuto_sort - Recursive function to sort an array using Lomuto partition.
 * @array: The array of integers.
 * @first: The starting index of the partition.
 * @last: The ending index of the partition.
 * @size: The size of the array.
 */
void lomuto_sort(int *array, ssize_t first, ssize_t last, size_t size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);

		lomuto_sort(array, first, position - 1, size);
		lomuto_sort(array, position + 1, last, size);
	}
}

/**
 * quick_sort - Quicksort algorithm using the Lomuto partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, 0, size - 1, size);
}

