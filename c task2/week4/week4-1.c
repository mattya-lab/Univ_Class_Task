#include <stdio.h>

void swap(int x,int y);

int main(){
    int x = 2, y = 5;
    swap(x,y);
    printf("x = %d, y = %d\n",x,y);

  return 0;
}

void swap(int x,int y){
    int temp = x;
    x = y;
    y = temp;

}
