#include <stdio.h>
#include <stdlib.h>

// Constant declartion 
#define UNPLACED (-1)
#define EDGE_TILES (5)
#define NUM_TILES (EDGE_TILES * EDGE_TILES)

// Prototype declartion
int put_germ(int size);
int check_position(int foot, int size, int already);
int put_foot(int size, int already);
int judge_infection(int left, int right, int germ);
void draw_feet(int left, int right, int germ);
void draw_line(void);
void fill_position(int row, int left, int right, int germ);

// Global variables
int l = 0;

int main(void) {

    int germ, right, left;
    int matrix_germ[NUM_TILES] = {};
    int i = 0, n = 0, flag;

    germ = put_germ(NUM_TILES);
    printf("Left foot ");  left = put_foot(NUM_TILES, UNPLACED);
    printf("Right foot ");  right = put_foot(NUM_TILES, left); 

    while (matrix_germ[n - 1] < NUM_TILES) {
        matrix_germ[n] = (n + 1) * germ;
        n++;
    }

    for (i = 0; i < n; i++) {
        if (judge_infection(left, right, matrix_germ[i]) == 1) flag = 1;
    }

    if (flag == 1)
        printf("Infected.");
    else
        printf("It is safe. ");

    printf("The bacteria was in Tile");
    for (i = 0; i < n - 1; i++)
        printf(" %2d", matrix_germ[i]);
    printf("\n");

    draw_feet(left, right, matrix_germ, n - 1);

    return 0;
}

int put_germ (int size)
{
  char key;  int location;
  printf("Input 1 character:"); scanf("%c", &key);
  printf("The input character value is 0x%x in hexadecimal, choose the bacteria's position and put bacterias\n", key);
  srand((unsigned int)key);
  location = rand() % size/*NUM_TILES(5)*/ + 1;
  return location;
}
int check_position(int foot, int size, int already){
  if((foot < 1) || (size < foot)){
      printf("Tile you can put the feet is from 1 to %d\n", size);
      return 0;
  }else if(already == foot){
      printf("Tile %d have already been put another feet.\n", already);
      return 0;
  }else
      return 1;
}
int put_foot(int size, int already){
  int position;
  do{
    printf("position[1-%d]:", size); scanf("%d", &position);
  }while(check_position(position, size, already)==0);
  return position;
}
int judge_infection(int left, int right, int germ){
  if((germ-left) * (germ-right) == 0)
    return 1; 
  else
    return 0; 
}


void draw_line(void){
  printf("+--+--+--+--+--+");
}

void fill_position(int row, int left, int right, int matrix_germ[], int k){
  int i, j;
  for(i = EDGE_TILES-1; i >= 0; i--){
    printf("|");
    j = EDGE_TILES * row - i; 
    if(j == matrix_germ[l]){
      printf(" @");
      l++;
    }
    else if(j==left){
      printf(" L");
    }
    else if(j==right){
      printf(" R");
    }
    else{
      printf("%2d", j);
    }
  }
  printf("|");
}


void draw_feet(int left, int right, int matrix_germ[], int k){
  int i;

  for(i = 1; i <= EDGE_TILES/*(5)*/; i++){    
    draw_line(); 
    printf("\n");
    fill_position(i, left, right, matrix_germ/*germ*/, k);
    printf("\n");
  }
  draw_line();
  printf("\n");
}

