#include "sort.h"

/**
 * swap_index - swap list index with next item index
 * @my_list: array
 * @swap_index: index of array to be swapped
 * Return: NULL
 */

void swap_index(int *my_list, size_t swap_index)
{
	int ram = *(my_list + swap_index);
	*(my_list + swap_index) = *(my_list + swap_index + 1);
	*(my_list + swap_index + 1) = ram;
}


/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array of data to be sorted
 * @size: size_t size of array
 * Return: NULL
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, loops = 1;
	int did_swap = 0;

	if (size < 2)
		return;

	if (array == NULL)
		return;

	for (j = 0; j < size - 1; j++)
	{
		for (i = 0; i < size - loops; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_index(array, i);
				print_array(array, size);
				did_swap = 1;
			}
		}


		loops++;
		if (did_swap)
			did_swap = 0;
		else
			return;
	}
}
