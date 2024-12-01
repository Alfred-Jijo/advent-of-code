#include <stdio.h>
#include <stdlib.h>

#include <common.h>

int
compare (const void *, const void *);

int
calc_total_distance (int *left, int *right, int size);

int
main(int argc, char **argv) {
	if (argc < 2) {
		printf("Usage: main.exe <puzzle_input> \n");
	}

	int left [] = { 3, 4, 2, 1, 3, 3 };
	int right[] = { 4, 3, 5, 3, 9, 3 };
	int size = sizeof(left) / sizeof(left[0]);

	printf("T: %d\n", calc_total_distance(left, right, size));

	return 0;
}

int
compare (const void *a, const void *b) {
	return (int *)a - (int *)b;
}

int
calc_total_distance (int *left, int *right, int size) {
	qsort(left, size, sizeof(int), compare);
	qsort(right, size, sizeof(int), compare);

	int total_distance, i;
	total_distance = 0;

	for (i = 0; i < size; i++) { 
		total_distance += abs(left[i] - right[i]); 
	}
	return total_distance;
}
