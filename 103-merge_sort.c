#include "sort.h"


void topDownSplitMerge(int *array, int *tempArray, long iBegin, long iEnd);
void topDownMerge(int *array, int *tempArray,
long iBegin, long iMiddle, long iEnd);
void copyArray(int *array, int *tempArray, long iBegin, long iEnd);
void print_merging(int *tempArray, long iBegin, long iEnd);

/**
 * merge_sort - A function that sorts an array of integers in
 * ascending order using the Merge sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *tempArray;

	tempArray = (int *)malloc(sizeof(int) * size);

	if (tempArray == NULL)
		return;
	copyArray(array, tempArray, 0, (long)size - 1);
	topDownSplitMerge(array, tempArray, 0, (long)size - 1);
	free(tempArray);
}

/**
 * topDownSplitMerge - A function that splits an array into halves
 * @array: the original array to be sorted
 * @tempArray: the temp copy of the original array
 * @iBegin: the index of the start of the array
 * @iEnd: the index of the end of the array
 * Return: void
 */
void topDownSplitMerge(int *array, int *tempArray, long iBegin, long iEnd)
{
	long iMiddle;

	if (iBegin >= iEnd)
		return;

	iMiddle = (iEnd + iBegin + 1) / 2;

	/*divide left side*/
	topDownSplitMerge(array, tempArray, iBegin, iMiddle - 1);
	/*divide right side*/
	topDownSplitMerge(array, tempArray, iMiddle, iEnd);

	topDownMerge(array, tempArray, iBegin, iMiddle, iEnd);
	copyArray(array, tempArray, iBegin, iEnd);
}

/**
 * topDownMerge - A function that merges the
 * left side and the right side of the array
 * @array: the original array
 * @tempArray: the temporary array
 * @iBegin: the start of the left side
 * @iMiddle: the start of the middle side
 * @iEnd: the end of the left side
 * Return: void
 */
void topDownMerge(int *array, int *tempArray, long iBegin,
long iMiddle, long iEnd)
{
	long k, i, j;

	printf("Merging...\n");
	printf("[left]: ");
	print_merging(tempArray, iBegin, iMiddle - 1);
	printf("[right]: ");
	print_merging(tempArray, iMiddle, iEnd);
	for (k = iBegin, i = iBegin, j = iMiddle; k <= iEnd; k++)
	{
		if (i < iMiddle && (j > iEnd || tempArray[i] <= tempArray[j]))
		{
			array[k] = tempArray[i];
			i++;
		}
		else
		{
			array[k] = tempArray[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_merging(array, iBegin, iEnd);
}


/**
 * copyArray - A function that copies an array to a
 * temporary array
 * @array: the original array
 * @tempArray: the temporary array to copy to
 * @iBegin: the start of the original array
 * @iEnd: the end of the orginal array
 * Result: void
 */
void copyArray(int *array, int *tempArray, long iBegin, long iEnd)
{
	long k;

	for (k = iBegin; k <= iEnd; k++)
		tempArray[k] = array[k];
}


/**
 * print_merging - A function that prints the process
 * of merging
 * @tempArray: A temporary array
 * @iBegin: the start of the array
 * @iEnd: the end of the array
 * Return: void
 */
void print_merging(int *tempArray, long iBegin, long iEnd)
{
	long i;

	for (i = iBegin; i <= iEnd; i++)
	{
		printf("%i", tempArray[i]);
		if (i != iEnd)
			printf(", ");
		else
			printf("\n");
	}
}
