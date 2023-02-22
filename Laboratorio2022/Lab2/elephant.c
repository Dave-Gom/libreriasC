#include<stdio.h>
int calc_pasos(int );

int main(){

  int x, pos =0, pasos = 0;
  scanf("%d", &x);
  pasos = calc_pasos(x);
  printf("%d", pasos);
  system("pause");

  return 0;
}

int calc_pasos(int dist){
  int pos = 0, pasos = 0 ,x = dist;

  while (pos != x)
  {
    if(pos+5 <= x){
      pasos++;
      pos+=5;
      continue;
    }
    if(pos+4 <= x){
      pasos++;
      pos+=4;
      continue;
    }
    if(pos+3 <= x){
      pasos++;
      pos+=3;
      continue;
    }
    if(pos+2 <= x){
      pasos++;
      pos+=2;
      continue;
    }
    if(pos+1 <= x){
      pasos++;
      pos+=1;
      continue;
    }
  }

  return pasos;
}