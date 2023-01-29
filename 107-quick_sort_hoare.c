#include "sort.h"


void hoare(int *array, long low, long high, size_t size);
long partition(int *array, long low, long high, size_t size);

/**
 * quick_sort_hoare - A function that sorts an array of integers
 * in ascending order using the the quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare(array, 0, (long) size - 1, size);
}

/**
 * hoare - A function that recursively sorts an array
 * @array: the array to partiotion
 * @low: the lowest index of the array
 * @high: the the highest index of the array
 * @size: the size of the array
 * Return: void
 */
void hoare(int *array, long low, long high, size_t size)
{
	long p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		hoare(array, low, p - 1, size);
		hoare(array, p, high, size);
	}
}


/**
 * partition - A function that partitions an array
 * into two
 * @array: the array to partition
 * @low: the lowest index of the array
 * @high: the highest index of the array
 * @size: the size of the array
 * Return: middle of the array
 */
long partition(int *array, long low, long high, size_t size)
{
	int pivot, temp;
	long i, j;

	pivot = array[high];
	i = low - 1;
	j = high + 1;
	while (1)
	{
		i++;
		j--;
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i >= j)
		{
			return (i);
		}
		else
		{
			/*swaps*/
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
