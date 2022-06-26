#include <stdio.h>

int bis(int x, int m){
  char ax[] = "00000000000000000000000000000000";
  char am[] = "00000000000000000000000000000000";

  for(int i = 0; i < 32 && x > 0; i++){
    if(x % 2 == 0)
      ax[31 - i] = '0';
    else
      ax[31 - i] = '1';
    x = x / 2;
  }

  for(int i = 0; i < 32 && m > 0; i++){
    if(m % 2 == 0)
      am[31 - i] = '0';
    else
      am[31 - i] = '1';
    m = m / 2;
  }
  printf("%s\n", ax);
  printf("%s\n", am);

  for(int i = 0; i < 32; i++){
    if(am[i] == '1')
      ax[i] = '1';
  }

  int res = 0;
  for(int i = 0, tmp = 1; i < 32; i++, tmp = tmp * 2){
    if(ax[31 - i] == '1')
      res += tmp;
  }

  printf("%s\n%d\n", ax, res);
}

void main(){
  bis(10, 6);
}
