#ifndef __CQSISMANEJOPROMOCIONES_H__
#define __CQSISMANEJOPROMOCIONES_H__
#include <SiscomRegistros3.h>
#include <qmemarray.h>
class CQSisManejoPromociones
{
public:
	CQSisManejoPromociones();
	void FilasMaximas(int pintFilas);
	void Agrega(SiscomRegistro3 *pSisReg3Promocion,
			     int pintNFila);
	const SiscomRegistro3Lst &Promociones();
	const QMemArray<int> &Filas();
	void ReInicia();
	void Elimina(SiscomRegistro3 *pSisReg3Promocion,int pintFila);
private:
	SiscomRegistro3Lst SisReg3LstPromociones;
	QMemArray<int> QMAFilas;
	int intContador;
};

#endif
