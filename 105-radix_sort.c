#include "sort.h"


/**
 * getMax - A function to get the maximum integer in
 * an array
 * @arr: the array where the integers are stored
 * @n: the size of the array
 * Return: the maximum integer
 */
int getMax(int *arr, long n)
{
	int max = arr[0];
	long i;

	for (i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/**
 * countSort - A function to sort the array using the
 * counting sort algorithm
 * @arr: the array to sort
 * @n: the size of the array
 * @exp: the significant digit for sorting
 * Return: void
 */
void countSort(int *arr, int n, int exp)
{
	int *output, i;
	int count[10] = {0};

	output = (int *)malloc(sizeof(int) * n);

	if (output == NULL)
		return;

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
	free(output);
}

/**
 * radix_sort - A function that sorts an array
 * of integers in ascending order using the radix sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	max = getMax(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, (long) size, exp);
		print_array(array, size);
	}
}
