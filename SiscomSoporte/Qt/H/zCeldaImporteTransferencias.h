#ifndef __ZCELDAIMPORTETRANSFERENCIAS_H__
#define __ZCELDAIMPORTETRANSFERENCIAS_H__
#include <zSiscomRegistro.h>

class zCeldaImporteTransferencias:public zSiscomRegistro
{
public:
	zCeldaImporteTransferencias(int,int,const char *pchrPtrColor="gray");
	void Importe(const char *pchrPtrImporte);
	int Fila();
	int Columna();

friend bool operator==(zCeldaImporteTransferencias &pzCImporteT1,
		       zCeldaImporteTransferencias &pzCImporteT2);

private:
	int intFila;
	int intColumna;
};


#endif
