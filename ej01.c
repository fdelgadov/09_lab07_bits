#include <stdio.h>

int bis(int x, int m){
  return x | m;
}

void main(){
  printf("%d\n", bis(10, 5));
}