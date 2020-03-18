#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define ARRAY_SIZE (3)

typedef int matrix_t[ARRAY_SIZE][ARRAY_SIZE];
matrix_t MA, MB, MC;

typedef struct {
  int id;
  int size;
  int Arow;
  int Bcol;
  matrix_t *MA, *MB, *MC;
}package_t;

void mult(int size, int row, int column, matrix_t MA, matrix_t MB, matrix_t MC);
void *mult_worker(void *arg);

package_t *p;

/* 
 * Main: allocate matrix, assigns values, computes the results
 */
int main(int argc, char **argv) 
{
  int size, row, column, num_threads, i;
  pthread_t *threads;
  //unsigned long thread_stack_size;
  //pthread_attr_t *pthread_attr_p, pthread_custom_attr;

  /* Currently size hardwired to ARRAY_SIZE size. */
  size = ARRAY_SIZE;

  /* One thread will be created for each element of the matrix. */
  threads = (pthread_t *)malloc(size * size * sizeof(pthread_t));

  /* Fill in matrix values, currently values are hardwired. */
  MA[0][0] = 1; MA[0][1] = 2; MA[0][2] = 3; 
  MA[1][0] = 4; MA[1][1] = 5; MA[1][2] = 6; 
  MA[2][0] = 7, MA[2][1] = 8; MA[2][2] = 9;

  MB[0][0] = 1; MB[0][1] = 0; MB[0][2] = 0;
  MB[1][0] = 0; MB[1][1] = 1; MB[1][2] = 0;
  MB[2][0] = 0; MB[2][1] = 0; MB[2][2] = 1;

  MC[0][0] = 0; MC[0][1] = 0; MC[0][2] = 0;
  MC[1][0] = 0; MC[1][1] = 0; MC[1][2] = 0;
  MC[2][0] = 0; MC[2][1] = 0; MC[2][2] = 0;

  /* Process Matrix, by row, column, Create a thread to process
     each element in the resulting matrix. */
  num_threads = 0;
  for (row = 0; row < size; row++){
    for (column = 0; column < size; column++){
      p = (package_t *)malloc(sizeof(package_t));
      p->id = num_threads;
      p->size = size;
      p->Arow = row;
      p->Bcol = column;
      (p->MA) = &MA; 
      (p->MB) = &MB;
      (p->MC) = &MC;

      pthread_create(&threads[num_threads], NULL, mult_worker, (void *) p);
      num_threads++;
      sleep(1);
    }
  }
 
  /* Synchronize on the completion of the element in each thread. */
  for(i = 0; i < (size*size); i++){
    pthread_join(threads[i], NULL);
  } 

  /* Print results */
  printf("MATRIX: The resulting matrix C is;\n");
  for (row = 0; row < size; row++){           
    for (column = 0; column < size; column++){ 
      printf("%5d ", MC[row][column]);
    }
    printf("\n");
  }

  return 0;
}

/*
 * Rotine to multiply a row by a column and place element in
 * resulting matrix.
 */
void mult(int size, int row, int column, matrix_t MA, matrix_t MB, matrix_t MC)
{
  int position; 
  MC[row][column] = 0;
  for(position = 0; position < size; position++)
    MC[row][column] = MC[row][column] + (MA[row][position] * MB[position][column]);
}

/*
 * Routine to start off a worker thread.
 */
void *mult_worker(void *arg)                  
{ 
  package_t *work_orderp = (package_t *)arg;
  mult(p->size, p->Arow, p->Bcol, *(p->MA), *(p->MB), *(p->MC));
  free(work_orderp);
  return(NULL);
}

