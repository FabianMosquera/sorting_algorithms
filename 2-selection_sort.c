#include "sort.h"
/**
 * selection_sort - sort array using  selection sort
 * @array: pointer
 * @size: size
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min = 0;
	int tmp = 0;

	if (!array)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
