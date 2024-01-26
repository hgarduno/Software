#ifndef __QTIMPPAGOSDOCUMENTOSPAGAR_H__
#define __QTIMPPAGOSDOCUMENTOSPAGAR_H__
#include <PagosDocumentosPagar.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zRelacionChequesPagar;
class QtImpPagosDocumentosPagar:public PagosDocumentosPagar
{
Q_OBJECT
public:
	QtImpPagosDocumentosPagar(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;
	zRelacionChequesPagar *zLstRelacion;
private:
private slots:
	void SlotImprimir();	
};

#endif
