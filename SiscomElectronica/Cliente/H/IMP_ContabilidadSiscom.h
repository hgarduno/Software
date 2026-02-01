#ifndef __IMP_CONTABILIDADSISCOM_H__
#define __IMP_CONTABILIDADSISCOM_H__
#include <QtContabilidadSiscom.h> 
#include <zFactura.h>

class zSiscomConexion;

class SiscomDatCom;

class QContabilidadSiscom:public QtContabilidadSiscom
{
Q_OBJECT
public:
	QContabilidadSiscom(SiscomDatCom *pSiscomDatCom,
			    char **pchrPtrArgumentos,
			    QWidget *pQWParent,
			    const char *pchrPtrName,
			    WFlags pWFlags);
	~QContabilidadSiscom();
private:
	void ConectaSlots();
	void IniciaVariables();
private:
	void OrdenesPagoElectronico();
	void FacturaPublicoEnGeneralPE();
	zSiscomConexion *Conexion();
	const zFactura &Factura();

private:
	zFactura zFacPublicoGPe;
};


#endif

extern "C" QContabilidadSiscom *InstanciaContabilidadSiscom(void *,char **,void *,const char *,int);
