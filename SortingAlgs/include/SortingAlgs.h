#pragma once

#include <iostream>
#include "Tracy.hpp"
#include "xmalloc.h"

#define malloc xmalloc
#define free xfree

typedef struct int_array {
	int* integers;
	size_t size;
} int_array;

void print_int_array(int_array);