#ifndef __QTCUENTACORTES_H__
#define __QTCUENTACORTES_H__
#include <qtable.h>
class zEncabezadosCaja;

class QtCuentaCortes:public QTable
{
Q_OBJECT
public:
	QtCuentaCortes(QWidget *,const char *);
	int Columna();
	int Fila();
	void Columna(int );
	void Fila(int );
	void IniciaVariables();
private:
	void CeldaGris(int,int,const QString &);
	void CeldaColor(int,int,const char *,const QString &);
	zEncabezadosCaja *Encabezados();
	void MuestraEncabezados();
private:
	void EncabezadosDatosCortes();
private:
	int intColumna;
	int intFila;

	zEncabezadosCaja *zEsCaja;
};

#endif
