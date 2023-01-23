#include "sort.h"

/**
 * swap - swap index of array
 * @first: pointer to first index
 * @second: pointer to second index
 * Return: nothing
 */
void swap(int *first, int *second)
{
	int ram = *first;

	*first = *second;
	*second = ram;
}

/**
 * divide_sort - sorting function that applies divide and conquer
 * in recorsion pattern
 * @array: input arrray
 * @low: index for the first element
 * @high: index for the last element
 * @size: size of the array to enable us print
 * Return: nothing
 */
void divide_sort(int *array, int low, int high, int size)
{
	int p, w, i;

	if (low < high)
	{
		p = high;
		w = low;
		for (i = low; i < high; i++)
		{

			if (array[i] < array[p])
			{
				if (i != w)
				{
					swap(&array[w], &array[i]);
					print_array(array, size);
				}
				w++;
			}
		}
		if (w != p && array[w] != array[p])
		{
			swap(&array[w], &array[p]);
			print_array(array, size);
		}
		divide_sort(array, low, w - 1, size);
		divide_sort(array, w + 1, high, size);
	}
}

/**
 * quick_sort - function that sorts an array
 * of integers in ascending order using the
 * quick sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 * Return: no return
 */
void quick_sort(int *array, size_t size)
{
	divide_sort(array, 0, size - 1, size);
}
