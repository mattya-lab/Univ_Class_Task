#include <stdio.h>
//--------------------------------------------------
void run(char c, int length){
    while (length > 0) {
        putchar(c);
        length--;
    }
}
//--------------------------------------------------
int main(void){
  int i, n;

  while(1){
    printf("Positive number: "); scanf("%d", &n);
    if(n>0)
      break;
  }

  for(i=0; i<n; i++){
    printf("%2d:", i+1);
    run(' ', i);
    run('*', n-i );
    printf("\n");
  }

  return 0;
}
