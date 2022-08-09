#include "SortingAlgs.h"

static void MergeSortRec(int_array* ints, int* buffer)
{
	ZoneScoped;
	if (ints->size == 1)
	{
		return;
	}
	/*In theory not necessary but way faster than going through all the other code*/
	if (ints->size == 2)
	{
		/*Swap if wrong order*/
		if (ints->integers[0] > ints->integers[1])
		{
			int temp = ints->integers[0];
			ints->integers[0] = ints->integers[1];
			ints->integers[1] = temp;
		}
		return;
	}

	/*Split up the input array and pass them down*/
	int_array split1 = { ints->integers,  ints->size / 2 };
	int_array split2 = { ints->integers + ints->size / 2,  ints->size - (ints->size / 2) };
	MergeSortRec(&split1, buffer);
	MergeSortRec(&split2, buffer);
	/*Make copy of array to read from*/
	int_array ints_copy = { buffer, ints->size / 2 };
	int_array ints_copy2 = { ints_copy.integers + (ints->size / 2), ints->size - (ints->size / 2) };
	memcpy(ints_copy.integers, ints->integers, sizeof(int) * ints->size);
	/*Logic for sorting array bigger 2*/
	int i1 = 0;
	int i2 = 0;
	for (int i = 0; i < ints->size; i++)
	{
		/*User number from second half if either all numbers from first already used or if second split smaller and not used up */
		if (i1 == ints_copy.size || (i2 != ints_copy2.size && ints_copy2.integers[i2] < ints_copy.integers[i1]))
		{
			ints->integers[i] = ints_copy2.integers[i2];
			i2++;
		}
		/*Otherwise use number from first half*/
		else 
		{
			ints->integers[i] = ints_copy.integers[i1];
			i1++;
		}
	}
}

void MergeSort(int_array* ints)
{
	ZoneScoped;
	/*Allocate memory outside of recursion so we only need to alloc once + don't need to check every recursion if buffer already created*/
	int* buffer = (int*)malloc(sizeof(int) * ints->size);
	MergeSortRec(ints, buffer);
	free(buffer);
}