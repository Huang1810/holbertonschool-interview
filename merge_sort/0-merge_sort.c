#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - merges two sorted subarrays
 * @array: the original array
 * @left: pointer to left subarray
 * @l_size: size of left subarray
 * @right: pointer to right subarray
 * @r_size: size of right subarray
 */
void merge(int *array, int *left, size_t l_size, int *right, size_t r_size)
{
    size_t i = 0, j = 0, k = 0;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, l_size);
    printf("[right]: ");
    print_array(right, r_size);

    while (i < l_size && j < r_size)
    {
        if (left[i] <= right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }
    while (i < l_size)
        array[k++] = left[i++];
    while (j < r_size)
        array[k++] = right[j++];

    printf("[Done]: ");
    print_array(array, l_size + r_size);
}

/**
 * merge_sort_recursive - helper recursive function
 * @array: array to sort
 * @size: size of the array
 * @buffer: allocated buffer array
 */
void merge_sort_recursive(int *array, size_t size, int *buffer)
{
    size_t mid, i;
    int *left, *right;

    if (size < 2)
        return;

    mid = size / 2;
    left = buffer;
    right = buffer + mid;

    for (i = 0; i < mid; i++)
        left[i] = array[i];
    for (i = mid; i < size; i++)
        right[i - mid] = array[i];

    merge_sort_recursive(left, mid, array);
    merge_sort_recursive(right, size - mid, array + mid);

    merge(array, left, mid, right, size - mid);
}

/**
 * merge_sort - sorts array of integers using merge sort
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
    int *copy;
    size_t i;

    if (array == NULL || size < 2)
        return;

    copy = malloc(sizeof(int) * size);
    if (!copy)
        return;

    for (i = 0; i < size; i++)
        copy[i] = array[i];

    merge_sort_recursive(array, size, copy);

    free(copy);
}
