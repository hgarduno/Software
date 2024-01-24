#ifndef __PUNTOSHORAS_H__
#define __PUNTOSHORAS_H__
#include <qptrlist.h>
class QPuntoHora
{
public:
	QPuntoHora(const char *,
		   int ,
		   int);
	int operator==(const char *);
	void ActualizaPunto(int,int);
	int ObtenX();
	int ObtenY();
private:
	char chrArrHora[12];
	int intX;
	int intY;
};
class QPuntosHoras:public QPtrList<QPuntoHora>
{
public:
	QPuntosHoras();
	QPuntosHoras &operator<<(QPuntoHora *);
	QPuntoHora *operator[](const char *);
};

class QPuntosDia
{
public:
	QPuntosDia(const char *);
	void AgregaPunto(QPuntoHora *);	
	QPuntoHora *operator[](const char *);
	int operator==(const char *);
private:
	const char *chrPtrDia;
	QPuntosHoras QPsHora;
};
class QPuntosSemana:public QPtrList<QPuntosDia>
{
public:
	QPuntosSemana();
	QPuntosSemana &operator<<(QPuntosDia *);
	QPuntosDia *operator[](const char *);

};
class QLinea
{
public:
	QLinea(int,int,int,int);	
	int X();
	int Y();
	int X1();
	int Y1();
	int ObtenDistanciaX();
	int ObtenDistanciaY();
private:
	int intX;
	int intY;
	int intX1;
	int intY1;
};
#endif
