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

int calc_area(int length, int width, int height) {
    int lw = length * width;
    int wh = width * height;
    int hl = height * length;
    return 2 * (lw + wh + hl);
}

int calc_extra(int length, int width, int height) {
    int lw = length * width;
    int wh = width * height;
    int hl = height * length;
    int smallest_side;
    if (lw < wh) {
        if (lw < hl) {
            smallest_side = lw;
        } else {
            smallest_side = hl;
        }
    } else {
        if (wh < hl) {
            smallest_side = wh;
        } else {
            smallest_side = hl;
        }
    }
    return smallest_side;
}

int calc_ribbon_length(int length, int width, int height) {
    int smallest_perimeter;
    if (length <= width && length <= height) {
        if (width <= height) {
            smallest_perimeter = 2 * (length + width);
        } else {
            smallest_perimeter = 2 * (length + height);
        }
    } else if (width <= length && width <= height) {
        if (length <= height) {
            smallest_perimeter = 2 * (width + length);
        } else {
            smallest_perimeter = 2 * (width + height);
        }
    } else {
        if (length <= width) {
            smallest_perimeter = 2 * (height + length);
        } else {
            smallest_perimeter = 2 * (height + width);
        }
    }
    int volume = length * width * height;
    return smallest_perimeter + volume;
}

int main(void) {
    FILE *f = fopen("puzzle_input.txt", "r");
    if (f == NULL) {
        perror("Unable to open file!");
        exit(1);
    }

    char input[100];
    int length, width, height, total_sq_ft = 0, total_ribbon_length = 0;

    while (fgets(input, sizeof(input), f) != NULL) {
        extract_dimensions(input, &length, &width, &height);
        int area = calc_area(length, width, height);
        int extra = calc_extra(length, width, height);
        total_sq_ft += (area + extra);
        int ribbon_length = calc_ribbon_length(length, width, height);
        total_ribbon_length += ribbon_length;
    }
    printf("Total Square Feet of Wrapping Paper: %d\n", total_sq_ft);
    printf("Total Feet of Ribbon: %d\n", total_ribbon_length);

    fclose(f);
    return 0;
}
