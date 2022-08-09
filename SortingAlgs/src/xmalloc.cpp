#include <stdlib.h>
#include "Tracy.hpp"

void* xmalloc(int size)
{
	ZoneScoped;
	void* memory = malloc(size);

	if (!memory)
	{
		perror("memory alloc fails");
		exit(1);
	}
	TracyAlloc(memory, size);
	return memory;
}

void xfree(void* ptr)
{
	ZoneScoped;
	TracyFree(ptr);
	free(ptr);
}