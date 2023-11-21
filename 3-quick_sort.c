#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Array to be partitioned
 * @low: Lower index of the partition
 * @high: Higher index of the partition
 * @size: Size of the array
 *
 * Return: Index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                /* Swap array[i] and array[j] */
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }

    /* Swap array[i + 1] and array[high] (pivot) */
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    print_array(array, size);

    return (i + 1);
}

/**
 * quicksort - Recursive function to perform quicksort
 * @array: Array to be sorted
 * @low: Lower index of the partition
 * @high: Higher index of the partition
 * @size: Size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pi = lomuto_partition(array, low, high, size);

        quicksort(array, low, pi - 1, size);
        quicksort(array, pi + 1, high, size);
    }
}

/**
 * quick_sort - Sort an array of integers in ascending order using Quick sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1, size);
}
