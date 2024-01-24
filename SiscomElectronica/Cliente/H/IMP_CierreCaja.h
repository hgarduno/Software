
#ifndef __IMP_CIERRECAJA_H__
#define __IMP_CIERRECAJA_H__
#include <UIC_H_CierreCaja.h>
#include <zCierreCaja.h>
class SiscomDatCom;

class zSiscomConexion;
class QCierreCaja:public CierreCaja
{
 Q_OBJECT
public:
	QCierreCaja(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCierreCaja();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;

	 zSiscomConexion *zSisConexion;
	 zCierreCaja zCCaja;
private:
	void ConectaSlots();
	void IniciaVariables();
	void CierreHoy();
private slots:
};
extern "C" QCierreCaja *InstanciaCierreCaja(void *,char **,void *,const char *,int);
#endif
