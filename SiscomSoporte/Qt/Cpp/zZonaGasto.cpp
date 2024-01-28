#include <zZonaGasto.h>

zZonaGasto::zZonaGasto(int pintFila,int pintColumna):intFila(pintFila),
						     intColumna(pintColumna)
{

}
int zZonaGasto::Fila()
{
   return intFila;
}
int zZonaGasto::Columna()
{
  return intColumna;
}

bool operator==(zZonaGasto &pzZoGasto,zZonaGasto &pzZoGasto1)
{
 return pzZoGasto.Columna()==pzZoGasto1.Columna() &&
        pzZoGasto1.Fila()>=pzZoGasto.Fila();
    
}
