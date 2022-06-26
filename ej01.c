#include <stdio.h>
#include <stdlib.h>

char* int2bin(int n){
  char* res = malloc(sizeof(char) * 33);

  unsigned un = (unsigned) n;
  //printf("%d %u\n", n, un);
  //printf("%u %d\n", n, un);

  for(int i = 0; i < 32; i++)
    res[i] = '0';
  res[32] = 0;

  for(int i = 0; i < 32 && un > 0; i++){
    if(un % 2 == 0)
      res[31 - i] = '0';
    else
      res[31 - i] = '1';
    un = un / 2;
  }

  return res;
}

int bis(int x, int m){
  char* ax = int2bin(x);
  char* am = int2bin(m);

  for(int i = 0; i < 32; i++){
    if(am[i] == '1')
      ax[i] = '1';
  }

  int res = 0;
  for(int i = 0, tmp = 1; i < 32; i++, tmp = tmp * 2){
    if(ax[31 - i] == '1')
      res += tmp;
  }

  //printf("%s\n%d\n", ax, res);
  free(ax);
  free(am);

  return res;
}

int bic(int x, int m){
  char* ax = int2bin(x);
  char* am = int2bin(m);

  for(int i = 0; i < 32; i++){
    if(am[i] == '1')
      ax[i] = '0';
  }

  int res = 0;
  for(int i = 0, tmp = 1; i < 32; i++, tmp = tmp * 2){
    if(ax[31 - i] == '1')
      res += tmp;
  }

  //printf("%s\n%d\n", ax, res);
  free(ax);
  free(am);

  return res;
}

int bool_or(int x, int y){
  int resultado = bis(x, y);

  return resultado;
}

void main(){
  printf("%s\n", int2bin(-2147483648));
  printf("%s\n", int2bin(2147483647));
}
