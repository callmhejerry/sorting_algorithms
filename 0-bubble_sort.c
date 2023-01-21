#include "sort.h"

/**
 * bubble_sort - A function that sorts an array
 * of integers in ascending order using the bubble sort algorithm
 * @array: the array of integers to sort
 * @size: the size of the array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t sorted, i, j, k;
	int temp;

	if (array == NULL || size <= 1)
		return;

	/* sorted is a boolean with 1 or 0 to know if an array is sorted*/
	sorted = 0;
	for (k = 0; k < size; k++)
	{
		for (i = 0, j = 1; j < size - k; i++, j++)
		{
			if (array[i] > array[j])
			{
				/*swap if the prev is bigger than*/
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
				continue;
			}
			if (j + 1 == size - k)
				sorted = 1;
		}
		if (sorted)
			break;
	}
}
