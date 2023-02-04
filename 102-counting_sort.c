#include "sort.h"
#include <string.h>

/**
 * counting_sort - sorts array in ascending order
 * @array: array to be sorted
 * @size: size of array to be sorted
 */

void counting_sort(int *array, size_t size)
{
	/*determine the upper limit of the elements in array*/
	size_t i, m, p;

	int *count;
	int *sort;

	int k, n, l = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	/*count the occurence of the elements in array*/
	/*populate this in a new array, count, of size k+1*/
	count = (int*)malloc((k + 1) * sizeof(int)); 

	/*intialise the count array to zero*/
	/*memset(count, 0, (k + 1) * sizeof(count[0]));*/
	for (m = 0; m < size; m++)
		++count[array[m]];

	/*sum up the elements in count*/
	for (n = 1; n < k + 1; n++)
		count[n] = count[n] + count[n - 1];

	/*print the count array*/
	print_array(count, k + 1);

	/*create new array for the sorted array, sort*/
	/*update this array using the element of array and index of count*/
	sort = (int*)malloc(size * sizeof(int));

	/*memset(sort, 0, size * sizeof(sort[0]));*/
	for (l = size - 1; l >= 0; l--)
		sort[--count[array[l]]] = array[l];

	/*copy sort to array*/
	for (p = 0; p < size; p++)
		array[p] = sort[p];
}
