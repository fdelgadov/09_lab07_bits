#include <stdio.h>

int bis(int x, int m){
  char* byte = (char*) &x;
  for(int i = 0; i < 4; i++){
    printf("%d\n", *(byte + i));
  }
}

void main(){
  bis(400, 6);
}
