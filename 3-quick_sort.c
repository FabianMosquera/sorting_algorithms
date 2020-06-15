#include "sort.h"
/**
 * swap - swap values
 * @array: data sort input
 * @first: first
 * @second: second
 * @size: size
 */
void swap(int *array, int first, int second, int size)
{
	int tmp;

	if (array[first] != array[second])
	{
		tmp = array[first];
		array[first] = array[second];
		array[second] = tmp;
		print_array(array, size);
	}
}
/**
 * partition - part to a pivot
 * @array: data sort input
 * @l: l
 * @r: r
 * @size: size
 * Return: New pivot
 */
int partition(int *array, int l, int r, size_t size)
{
	int i = l;
	int j, pivot = array[r];

	for (j = l; j <= r; j++)
	{
		if (array[j] < pivot)
		{
			swap(array, i, j, size);
			i++;
		}
	}
	swap(array, i, r, size);
	return (i);
}
/**
 * _quicksort -  quick sort algorithm
 *
 * @array: data to sort
 * @l: left pivot
 * @r: right pivot
 * @size: size input
 */
void _quicksort(int *array, int l, int r, size_t size)
{
	int pivot;

	if (l < r)
	{
		pivot = part(array, l, r, size);
		_quicksort(array, l, pivot - 1, size);
		_quicksort(array, pivot + 1, r, size);
	}
}
/**
 * quick_sort -  quick sort algorithm
 *
 * @array: sort data
 * @size: size input
 *
 * Return: No Return
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	_quicksort(array, 0, size - 1, size);
}
