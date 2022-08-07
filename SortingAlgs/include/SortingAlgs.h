#pragma once

#include <iostream>

typedef struct int_array {
	int* integers;
	size_t size;
} int_array;

void print_int_array(int_array);