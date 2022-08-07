#include <iostream>
#include "SortingAlgs.h"
#include "MergeSort.h"
#include "Helpers.h"


int main()
{
	srand(time(NULL));
	int_array ints = { (int*)malloc(sizeof(int) * 64), 64 };
	for (size_t i = 0; i < ints.size; i++)
	{
		ints.integers[i] = 1 + rand() % 100;
	}

	printf("Unsorted list: ");
	print_int_array(&ints);
	MergeSort(&ints);
	printf("Sorted list: ");
	print_int_array(&ints);

	return 0;
}
