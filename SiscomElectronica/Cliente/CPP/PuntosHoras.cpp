#include <PuntosHoras.h>
#include <string.h>
#include <stdio.h>
QPuntoHora::QPuntoHora(const char *pchrPtrHora,
		       int pintX,
		       int pintY):
		   intX(pintX),
		   intY(pintY)
{
	strcpy(chrArrHora,pchrPtrHora);

}
int QPuntoHora::operator==(const char *pchrPtrHora)
{
	return !strcmp(chrArrHora,pchrPtrHora);
}
int QPuntoHora::ObtenX()
{
	return intX;
}
int QPuntoHora::ObtenY()
{
	return intY;
}
void QPuntoHora::ActualizaPunto(int pintX,int pintY)
{
	intX=pintX;
	intY=pintY;
}
QPuntosHoras::QPuntosHoras()
{
}

QPuntosHoras &QPuntosHoras::operator<<(QPuntoHora *pQPHora)
{
	append(pQPHora);
	return *this;
}
QPuntoHora *QPuntosHoras::operator[](const char *pchrPtrHora)
{
QPuntoHora *lQPHora;
	for(lQPHora=first();
	    lQPHora;
	    lQPHora=next())
	if((*lQPHora)==pchrPtrHora)
	return lQPHora;
return 0;
}

QPuntosDia::QPuntosDia(const char *pchrPtrDia):
	chrPtrDia(pchrPtrDia)
{

}
void QPuntosDia::AgregaPunto(QPuntoHora *pQPHora)
{
	QPsHora << pQPHora;

}
QPuntoHora *QPuntosDia::operator[](const char *pchrPtrHora)
{
	return QPsHora[pchrPtrHora];
}
int QPuntosDia::operator==(const char *pchrPtrDia)
{
	return !strcmp(chrPtrDia,pchrPtrDia);
}
QPuntosSemana::QPuntosSemana()
{

}
QPuntosSemana &QPuntosSemana::operator<<(QPuntosDia *pQPDias)
{
	append(pQPDias);
	return *this;
}
QPuntosDia *QPuntosSemana::operator[](const char *pchrPtrDia)
{
QPuntosDia *lQPDia;
	for(lQPDia=first();
	    lQPDia;
	    lQPDia=next())
	if((*lQPDia)==pchrPtrDia)
	 return lQPDia;
  return 0;
}
QLinea::QLinea(int pintX,
	       int pintY,
	       int pintX1,
	       int pintY1):
	    intX(pintX),
	    intY(pintY),
	    intX1(pintX1),
	    intY1(pintY1)
{


}
int QLinea::X()
{
	return intX;
}
int QLinea::Y()
{
	return intY;
}
int QLinea::X1()
{
	return intX1;
}
int QLinea::Y1()
{
	return intY1;
}
int QLinea::ObtenDistanciaX()
{
	return intX1-intX;
}
int QLinea::ObtenDistanciaY()
{
	return intY1-intY;
}
