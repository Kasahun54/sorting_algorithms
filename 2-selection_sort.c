#include "sort.h"

/**
  * swap - exchange integer in an array
  * @i: integer one
  * @j: integer two
  */
void swap(int *i, int *j)
{
	int tmp;

	tmp = *i;
	*i = *j;
	*j = tmp;
}

/**
  * selection_sort - sort arrays using selection sort.
  * @array: integer array
  * @size: array size
  * 
  * Return: Nothing
  */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, min_index;

	if (size < 2)
		return;
	i = 0;
	while (i < size)
	{
		min = array[i];
		j = i;
		while (j < size)
		{
			if (array[j] < min)
			{
				min = array[j];
				min_index = j;
			}
			j++;
		}
		swap(&array[i], &array[min_index]);
		print_array(array, size);
		i++;
	}
}
