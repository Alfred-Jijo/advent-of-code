#include <stdio.h>
#include <stdlib.h>

#include <common.h>

int 
compare(const void *, const void *);

int 
calc_total_distance (int *, int *, int);

int main() {
    FILE *file;
    int *left = NULL, *right = NULL;
    int size = 0, capacity = 10;

    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Allocate initial memory for arrays
    left = malloc(capacity * sizeof(int));
    right = malloc(capacity * sizeof(int));
    if (left == NULL || right == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return 1;
    }

    int l, r;
    while (fscanf(file, "%d %d", &l, &r) == 2) {
        if (size == capacity) {
            capacity *= 2;
            left = realloc(left, capacity * sizeof(int));
            right = realloc(right, capacity * sizeof(int));
            if (left == NULL || right == NULL) {
                printf("Memory reallocation failed.\n");
                free(left);
                free(right);
                fclose(file);
                return 1;
            }
        }
        left[size] = l;
        right[size] = r;
        size++;
    }

    fclose(file);

    printf("Total Distance: %d\n", calc_total_distance(left, right, size));

    free(left);
    free(right);

    return 0;
}

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int
calc_total_distance (int *left, int *right, int size) {
    qsort(left, size, sizeof(int), compare);
    qsort(right, size, sizeof(int), compare);

    int totalDistance = 0;
    for (int i = 0; i < size; i++) {
        totalDistance += abs(left[i] - right[i]);
    }

}
