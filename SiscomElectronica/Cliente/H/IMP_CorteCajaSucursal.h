
#ifndef __IMP_CORTECAJASUCURSAL_H__
#define __IMP_CORTECAJASUCURSAL_H__
#include <UIC_H_CorteCajaSucursal.h>
class SiscomDatCom;
class zSiscomConexion;
class QCorteCajaSucursal:public CorteCajaSucursal
{
 Q_OBJECT
public:
	QCorteCajaSucursal(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCorteCajaSucursal();

	
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
private:
	void ConectaSlots();
	void IniciaVariables();
	void CalculandoCorteCaja();
	void AgregaGasto(int,int);
private slots:
	void SlotCapturoCantidad();
	void SlotActualizaCorteCaja();
};
extern "C" QCorteCajaSucursal *InstanciaCorteCajaSucursal(void *,char **,void *,const char *,int);
#endif
