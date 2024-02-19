#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**i
 * counting_sort - Sort an array of integers in ascending order
 * using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sortid, maxi_, i;

	if (array == NULL || size < 2)
		return;

	sortid = malloc(sizeof(int) * size);
	if (sortid == NULL)
		return;
	maxi_ = get_max(array, size);
	count = malloc(sizeof(int) * (maxi_ + 1));
	if (count == NULL)
	{
		free(sortid);
		return;
	}

	for (i = 0; i < (maxi_ + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (maxi_ + 1); i++)
		count[i] += count[i - 1];
	print_array(count, maxi_ + 1);

	for (i = 0; i < (int)size; i++)
	{
		sortid[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sortid[i];

	free(sortid);
	free(count);
}
