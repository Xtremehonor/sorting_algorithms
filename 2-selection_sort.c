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
 * selection_sort - Sort an array using the selection sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 **/
void selection_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    for (size_t i = 0; i < size; i++)
    {
        size_t min_index = i;

        for (size_t j = i + 1; j < size; j++)
        {
            if (array[min_index] > array[j])
                min_index = j;
        }

        if (min_index != i)
        {
            swap_integers(&array[i], &array[min_index]);
            print_array(array, size);
        }
    }
}
