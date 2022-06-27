#include <inttypes.h>
#include <stdio.h>

int mult_ok(int64_t x, int64_t y){
  if(x == 0 || y == 0)
    return 1;
  
  if(x < 0 && y < 0){
    return x * y > x && x * y > y;
  }

  if(x < 0 || y < 0){
    return x * y <= x && x * y <= y;
  }

  return x * y >= x || x * y >= y;
}

void main(){
  int64_t x = (int64_t) 9223372036854775807;
  int64_t y = -1;
  printf("%d\n", mult_ok(x, y));
}