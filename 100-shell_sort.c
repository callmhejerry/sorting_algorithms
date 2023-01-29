#include "sort.h"

void print_array(const int *array, size_t size);

/**
 * shell_sort - shell sort using the Knuth sequence
 * @array: pointer to int, defines array to be sorted
 * @size: countof elements to be sorted
 * Return: void, sorted array
 */
void shell_sort(int *array, size_t size)
{
	size_t out, inner;
	int insertValue;

	/*initialise and define the gap interval, gap*/
	size_t gap = 1;

	if (array  == NULL || size <= 1)
		return;

	while (gap <= size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		/*compare gap elements and swap if neccessary*/
		for (out = gap; out < size; out++)
		{
			insertValue = *(array + out);
			inner = out;

			while (inner > gap - 1 && *(array + (inner - gap)) >= insertValue)
			{
				*(array + inner) = *(array + (inner - gap));
				inner -= gap;
			}
			*(array + inner) = insertValue;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
