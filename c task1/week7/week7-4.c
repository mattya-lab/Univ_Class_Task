#include <stdio.h>
#include <stdlib.h>

// Const declaration
#define UNPLACED (-1)
#define EDGE_TILES (3)
#define NUM_TILES (EDGE_TILES * EDGE_TILES)

// Prototype declaration
int put_germ(int size);
int check_position(int foot, int size, int already);
int put_foot(int size, int already);
int judge_infection(int left, int right, int germ);
void draw_feet(int left, int right, int germ);
void draw_line(void);
void fill_position(int row, int left, int right, int germ);

int main(void)
{
    int germ, right, left;

    germ = put_germ(NUM_TILES);
    printf("Left foot ");
    left = put_foot(NUM_TILES, UNPLACED);
    printf("Right foot ");
    right = put_foot(NUM_TILES, left);

    if (judge_infection(left, right, germ) == 1)
        printf("Infected.");
    else
        printf("It is Safe．");

    printf("The Bacteria was in Tile %d.\n", germ);
    draw_feet(left, right, germ);

    return 0;
}

int put_germ(int size) {
    char key;
    int location;

    printf("Input 1 character: "); scanf("%c", &key);
    printf("The input character value is 0x%x in hexadecimal, choose the bacteria's position and put bacteria\n",
        key);
    srand((unsigned int)key);
    location = rand() % size/*NUM_TILES(3)*/ + 1;
    return location;
}

int check_position(int foot, int size, int already) {
    if ((foot < 1) || (size < foot)) {
        printf("Tile you can put the feet is from 1 to %d.\n", size);
        return 0;
    }
    else if (already == foot) {
        printf("Tile %d have already been put another feet.\n", already);
        return 0;
    }
    else
        return 1;
}

int put_foot(int size, int already) {
    int position;

    do {
        printf("position[1-%d]:", size); scanf("%d", &position);
    } while (check_position(position, size, already) == 0);

    return position;
}

int judge_infection(int left, int right, int germ) {
    if ((germ - left) * (germ - right) == 0)//Reason for judgement?
        return 1;
    else
        return 0;
}

void draw_feet(int left, int right, int germ) {
    int i;

    for (i = 1; i <= 3; i++) {
        draw_line(); 
        printf("\n");
        fill_position(i, left, right, germ);
        printf("\n");
    }
    draw_line();
    printf("\n");
}

void draw_line(void) {
    printf("+-+-+-+");
}

void fill_position(int row, int left, int right, int germ) {
    int i, j;

    for (i = 2; i >= 0; i--) {
        printf("|");
        j = 3 * row - i;
        if (j == left) {
            printf("L");
        }
        else if (j == right) {
            printf("R");
        }
        else if (j == germ) {
            printf("@");
        }
        else {
            printf("%d", j);
        }
    }
    printf("|");
}
