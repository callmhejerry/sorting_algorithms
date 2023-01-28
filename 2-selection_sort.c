#include "sort.h"

/**
 * selection_sort - A function that sorts an array of integers in
 * ascending order using the selection sort algorithm
 * @array: the array of integers to sort
 * @size: the size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int temp, smallest, swapped;
	size_t i, j, idx;

	swapped = 0;
	for (i = 0; i < size; i++)
	{
		smallest = array[i];
		temp = smallest;
		for (j = i; j < size; j++)
		{
			if (array[j] < smallest)
			{
				smallest = array[j];
				idx = j;
				swapped = 1;
			}
		}
		/*check if we found a number smaller*/
		if (swapped)
		{
			array[i] = smallest;
			array[idx] = temp;
			print_array(array, size);
			swapped = 0;
		}
	}
}
