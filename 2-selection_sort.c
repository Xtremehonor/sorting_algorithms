#include "sort.h"

/**
 * swap_integers - Swap two integers
 * @a: First integer
 * @b: Second integer
 **/
void swap_integers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * selection_sort - sort array using selection sort algorithm
 * @array: array
 * @size: array size
 **/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
			swap_integers(&array[i], &array[min]);
			print_array(array, size);
		}
	}

}
