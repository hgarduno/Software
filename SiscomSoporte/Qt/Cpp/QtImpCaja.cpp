#include <QtCorteCaja.h>
#include <QtImpCaja.h>

QtImpCaja::QtImpCaja(const QString &pQStrEncabezado,
		     QtCorteCaja *pQtCorteCaja,
		     int pintFila, 
		     int pintColumna):
		QtCoCaja(pQtCorteCaja),
		intFila(pintFila),
		intColumna(pintColumna)
		 
{
   Encabezado(pQStrEncabezado); 
}

void QtImpCaja::Encabezado(const QString &pQStrTexto)
{
}

int QtImpCaja::Fila()
{
  return intFila;
}
int QtImpCaja::Columna()
{
  return intColumna;
}
