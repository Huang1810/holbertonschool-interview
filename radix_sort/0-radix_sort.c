#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * get_max - Returns the maximum value in an array
 * @array: The array to search
 * @size: The number of elements in the array
 * Return: The maximum integer in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - Performs counting sort based on a specific digit
 * @array: The array to sort
 * @size: The number of elements in the array
 * @exp: The digit position (exponent)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output, count[10] = {0};
	size_t i;

	output = malloc(size * sizeof(int));
	if (!output)
		return;

	/* Count occurrences of each digit */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Change count[i] so that it contains actual position */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array (stable sort) */
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy output array to original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers using LSD Radix sort algorithm
 * @array: The array to sort
 * @size: The number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	/* Sort for each digit, starting from least significant */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}
