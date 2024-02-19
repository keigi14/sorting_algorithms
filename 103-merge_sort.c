#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - Sort a subaray of integers.
 * @subarr: A subarray of an aray of integers to sort.
 * @buff: A buffer to store th sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index o the array.
 * @back: The back index of he array.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t v, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (v = front, j = mid; v < mid && j < back; k++)
		buff[k] = (subarr[v] < subarr[j]) ? subarr[v++] : subarr[j++];
	for (; v < mid; v++)
		buff[k++] = subarr[v];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (v = front, k = 0; v < back; v++)
		subarr[v] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store de sorted result.
 * @front: The front index of de subarray.
 * @back: The back index of de subarray.
 */
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mido;

	if (back - front > 1)
	{
		mido = front + (back - front) / 2;
		merge_sort_recursive(subarr, buff, front, mido);
		merge_sort_recursive(subarr, buff, mido, back);
		merge_subarr(subarr, buff, front, mido, back);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 * order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
