#include <iostream>
#include "SortingAlgs.h"
#include "MergeSort.h"
#include "Helpers.h"


int main()
{
	ZoneScoped;
	srand(time(NULL));

	int asize;
	int randmax;
	int iter;
	printf("Array size:");
	scanf("%d", &asize);
	printf("Max num:");
	scanf("%d", &randmax);
	printf("Iterations:");
	scanf("%d", &iter);

	for (int i = 0; i < iter; i++)
	{
		int_array ints = { (int*)malloc(sizeof(int) * asize), asize };
		for (size_t i = 0; i < ints.size; i++)
		{
			ints.integers[i] = 1 + rand() % randmax;
		}

		printf("Unsorted list:\n");
		print_int_array(&ints);
		MergeSort(&ints);
		printf("Sorted list:\n");
		print_int_array(&ints);
		free(ints.integers);
	}
	return 0;
}
