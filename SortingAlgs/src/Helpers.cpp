#include "SortingAlgs.h"

void print_int_array(int_array* ints)
{
	ZoneScoped;
	for (size_t i = 0; i < ints->size; i++)
	{
		printf("%i ,", ints->integers[i]);
	}
	printf("\n");
}