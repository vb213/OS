#include "insert.h"

#include <stdlib.h>
#include <string.h>

#include <stdio.h>

/*
 * Reminder: insert() function from the tutorial that does not manage capacity.
 */
void insert_tut(int *a, size_t *length, int z)
{
	int *p = a;
	int *end = a + *length;
	while ((p < end) && (*p < z)) { ++p; }
	memmove(p + 1, p, (end - p) * sizeof(int));
	*p = z;
	(*length)++;
}

/*
 * New insert() function that reallocates if the array is full.
 */
void insert(int **array, size_t *length, size_t *capacity, int z)
{
	const int increment = 10;

	int *a = *array;
	if(*length == *capacity) {
		*capacity = *length + increment;
		//printf("%ld\n", *capacity);

		a = malloc(*capacity * sizeof(int));
		memcpy(a, *array, *capacity);
	}
	printf("length: %ld; capacity: %ld; z: %d\n", *length, *capacity, z);

	insert_tut(a, length, z);
}
