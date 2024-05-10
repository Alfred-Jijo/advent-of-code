#include <stdio.h>
#include <string.h>

int main() {
	FILE *puzzle_input = fopen("puzzle_input.txt", "r");
	char c;
	int floor = 0;
	int cn;

	while ((c=fgetc(puzzle_input)) != EOF) {
		if (c == '(') floor += 1;
		if (c == ')') floor -= 1;
		cn++;
		if (floor == -1) printf("Floor: %d, char#: %d\n", floor, cn);
	}

	printf("Floor: %d\n", floor);
}

