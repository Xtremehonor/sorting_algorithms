#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    unsigned int i, j, min;

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
            /* Swap the elements */
            int tmp = array[i];
            array[i] = array[min];
            array[min] = tmp;

            /* Print the array after each swap */
            print_array(array, size);
        }
    }
}
