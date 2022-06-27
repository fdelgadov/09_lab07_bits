#include <inttypes.h>
#include <stdio.h>

int mult_ok(int64_t x, int64_t y){
  int64_t tmp = 2;
  int i = 0;
  int j = 0;

  while(tmp <= x && i < 64){
    i++;
    tmp = tmp * 2;
  }

  tmp = 2;
  while(tmp <= y && j < 64){
    j++;
    tmp = tmp * 2;
  }

  printf("i: %d j: %d\n", i, j);

  if(i + j > 64)
    return 0;

  return 0;
}

void main(){
  int64_t x = (int64_t) 9223372036854775807;
  int64_t y = 3;
  printf("%d\n", mult_ok(x, y));
}