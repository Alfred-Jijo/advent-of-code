#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void extract_dimensions(char *str, int *length, int *width, int *height) {
    char *token = strtok(str, "x");
    *length = atoi(token);

    token = strtok(NULL, "x");
    *width = atoi(token);

    token = strtok(NULL, "x");
    *height = atoi(token);
}

int calc_area(int *length, int *width, int *height) {
    int l = *length;
    int w = *width;
    int h = *height;
    return ((2*l*w) + (2*w*h) + (2*h*l));
}

int main(void) {
    FILE *f = fopen("puzzle_input.txt", "r");
    if(f == NULL) {
        perror("Unable to open file!");
        exit(1);
    }

    char input[100];
    int length, width, height, total, sq_ft;

    while(fgets(input, sizeof(input), f) != NULL) {
        extract_dimensions(input, &length, &width, &height);
        /* printf("Length: %d, Width: %d, Height: %d\n", length, width, height); */
        sq_ft = calc_area(&length, &width, &height);
        total += sq_ft;
    }
    printf("Total Sqaure Feet: %d", total);
}
