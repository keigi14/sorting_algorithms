#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * using the selection sort algorithm.
 * @array: An array of ints.
 * @size: The size of the ar
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	int *mini_;
	size_t v, j;

	if (array == NULL || size < 2)
		return;

	for (v = 0; v < size - 1; v++)
	{
		mini_ = array + v;
		for (j = v + 1; j < size; j++)
			mini_ = (array[j] < *mini_) ? (array + j) : mini_;

		if ((array + v) != mini_)
		{
			swap_ints(array + v, mini_);
			print_array(array, size);
		}
	}
}
