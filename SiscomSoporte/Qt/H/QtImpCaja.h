#ifndef __QTIMPCAJA_H__
#define __QTIMPCAJA_H__

class QtCorteCaja;
class QtImpCaja
{
public:
	QtImpCaja(const QString &pQStrEncabezado,
		 QtCorteCaja *,
		 int pintFila,
		 int pintColumna);
private:
	void Encabezado(const QString &);
	int Fila();
	int Columna();
private:
	QtCorteCaja *QtCoCaja;;
	int intFila;
	int intColumna;
};


#endif
