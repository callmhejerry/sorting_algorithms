#include "sort.h"


void recursive_qsort(int *array, long low, long high, size_t size);
long partition(int *array, long low, long high, size_t size);
void swap(int *array, long first, long second, size_t size);

/**
 * quick_sort - A function that sorts an array of integers
 * in ascending order using the quick sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursive_qsort(array, 0, (long)size - 1, size);
}

/**
 * recursive_qsort - A fucntion that recursively sorts the upper and
 * lower partitions of an array
 * @array: the array to sort
 * @low: the lower bound of the partition
 * @high: the upper bound of the partition
 * @size: the size of the array
 * return: void
 */
void recursive_qsort(int *array, long low, long high, size_t size)
{
	long p;

	if (low < high)
	{
		p = partition(array, low, high, size);

		/*left side*/
		recursive_qsort(array, 0, p - 1, size);
		/*right side*/
		recursive_qsort(array, p + 1, high, size);
	}
}

/**
 * partition - A function that divides an array in two partition
 * @array: the array to partition
 * @low: the lower bound of the array
 * @high: the upper bound of the array
 * @size: the size of the array
 * Return: The mid point of the partion
 */
long partition(int *array, long low, long high, size_t size)
{
	long j, i;
	int pivot; /* swapped;*/

	pivot = array[high];
	i = low - 1;
	/*swapped = 0;*/

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(array, i, j, size);
			/*swapped = 1;*/
		}
	}
	swap(array, i + 1, high, size);
	return (i + 1);
}

/**
 * swap - A function that swaps two items in an array
 * @array: the array where the items are stored
 * @first: the first item to swap
 * @second: the second item to swap
 * @size: the size of the array
 * Return: void
 */
void swap(int *array, long first, long second, size_t size)
{
	int temp;

	if (first == second)
		return;
	temp = array[second];
	array[second] = array[first];
	array[first] = temp;
	print_array(array, size);
}
