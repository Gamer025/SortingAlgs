#include "SortingAlgs.h"

using namespace std;

void MergeSort(int_array* ints)
{
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

	int_array split1 = { ints->integers,  ints->size / 2 };
	int_array split2 = { ints->integers + ints->size / 2,  ints->size / 2 };
	MergeSort(&split1);
	MergeSort(&split2);
	int_array ints_copy = { (int*)malloc(sizeof(int) * ints->size), ints->size / 2 };
	int_array ints_copy2 = { ints_copy.integers + (ints->size / 2),  ints->size / 2 };
	memcpy(ints_copy.integers, ints->integers, sizeof(int) * ints->size);
	size_t i1 = 0;
	size_t i2 = 0;
	for (; i1 + i2 < ints->size; i1++)
	{
		if (i2 >= ints_copy2.size || (i1 < ints_copy.size && ints_copy.integers[i1] < ints_copy2.integers[i2]))
		{
			ints->integers[i1 + i2] = ints_copy.integers[i1];
			continue;
		}
		for (; i2 < ints_copy2.size; i2++)
		{
			ints->integers[i1 + i2] = ints_copy2.integers[i2];
			i2++;
			i1--;
			break;
		}
	}
	free(ints_copy.integers);
}