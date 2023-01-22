#include "sort.h"

/**
 * swap - switch indexes of array items
 * @array: array to swap
 * @first: index of first item
 * @second: index of second item
 * Return: void
 */
void swap(int *array, size_t first, size_t second)
{
	int ram;

	ram = *(array + first);
	*(array + first) = *(array + second);
	*(array + second) = ram;
}

/**
 * selection_sort - sort an erroy using selection_sort technique
 * @array: The array to be sorted
 * @size: size of array to be sorted
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, index_low;
	int need_swap = 0;

	if (size < 2)
		return;
	if(array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		index_low = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index_low])
			{
				need_swap = 1;
				index_low = j;
			}
		}
		if (need_swap)
		{
			swap(array, i, index_low);
			print_array(array, size);
			need_swap = 0;
		}
	}

}
