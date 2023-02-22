#include<stdio.h>

int is_beautifull_year(int);

int main(){
  int anio, digDis;

  scanf("%d", &anio);
  anio = anio+1;
  while (anio <= 9012)
  {
    if(is_beautifull_year(anio) == -1)
    {
      anio++;
    }
    else
    {
      break;
    }
  }

  printf("%d", anio);
  system("pause");
  return 0;
} 

int is_beautifull_year(int anio){
  int unid, dec, cent, uni_mil, ret = 0;

  unid = anio%10;
  dec = ((anio%100) - unid)/10;
  cent = ((anio %1000)- dec*10 - unid)/100;
  uni_mil = ((anio%10000) - cent*100 - dec*10 - unid)/1000;

  if( unid == dec)
    ret = -1;

  if( unid == cent)
    ret = -1;

  if( unid == uni_mil)
    ret = -1;

  if( cent == dec)
    ret = -1;

  if( uni_mil == dec)
    ret = -1;

  if( uni_mil == cent)
    ret = -1;

  return ret;
}