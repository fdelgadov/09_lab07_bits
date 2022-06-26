#include <stdio.h>
#include <stdlib.h>

char* int2bin(int n){
  char* res = malloc(sizeof(char) * 33);
  for(int i = 0; i < 32; i++)
    res[i] = '0';
  res[32] = 0;

  for(int i = 0; i < 32 && n > 0; i++){
    if(n % 2 == 0)
      res[31 - i] = '0';
    else
      res[31 - i] = '1';
    n = n / 2;
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
  printf("%d\n", bool_or(10, 6));
}
