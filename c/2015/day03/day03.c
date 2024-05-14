#include <stdio.h>
#include <stdlib.h>


struct house {
	long x;
	long y;
	struct house *next;
};

char AddHouse(long, long, struct house *);
void RemoveHouses(struct house *hous);


int main(void) {

	struct house *current = (struct house *) malloc(sizeof(struct house));
	*current = (struct house) { 0, 0, NULL };
	
	FILE *file = fopen("puzzle_input", "r");
	if (!file) { perror ("Line 20 @ day03.c"); }


	char c;
	long x = 0, y = 0;
	unsigned long houses = 1;
	int flag = 0;	
	while ((c = fgetc(file)) != EOF) {
		
		if (flag == 0) {
			printf("Santa\n");
			flag = 1;
			
			switch (c) {
			case '^':
				y++;
				break;
			case 'v':
				y--;
				break;
			case '>':
				x++;
				break;
			case '<':
				x--;
				break;
			default:
				printf("Unknown character input: %c.\n", c);
				break;
			}
			houses += AddHouse( x, y, current);
		}

		if (flag == 1) {
			printf("Robo-Santa\n");
			flag = 0;

			switch (c) {
			case '^':
				y++;
				break;
			case 'v':
				y--;
				break;
			case '>':
				x++;
				break;
			case '<':
				x--;
				break;
			default:
				printf("Unknown character input: %c.\n", c);
				break;
			}
		houses += AddHouse( x, y, current);
		}

	}

	printf("Houses visited: %lu\n", houses);
	RemoveHouses(current);
	fclose(file);
	return 0;
}

char AddHouse(long x, long y, struct house *hous) {
	while ( hous->x != x || hous->y != y) {
		if (hous->next) {
			hous = hous->next;
		} else {
			hous->next = (struct house *) malloc(sizeof(struct house));
			*(hous->next) = (struct house) { x, y, NULL};
			
			return 1;
		}
	}
	
	return 0;
}

void RemoveHouses(struct house *hous) {
	
	struct house *curr, *old;
	curr = old = hous;

	while(curr->next) {

		old = curr ;
		curr = curr->next;

		free(old);
	}

	return;
}
