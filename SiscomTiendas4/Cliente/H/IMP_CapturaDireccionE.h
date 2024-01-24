
#ifndef __IMP_CAPTURADIRECCIONE_H__
#define __IMP_CAPTURADIRECCIONE_H__
#include <UIC_H_CapturaDireccionE.h>
class SiscomDatCom;
class CQSisDireccionE;
class QCapturaDireccionE:public CapturaDireccionE
{
 Q_OBJECT
public:
	QCapturaDireccionE(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaDireccionE();
	CQSisDireccionE *DireccionE();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotPasaFocoLinea2();
	void SlotPasaFocoLinea3();
	void SlotPasaFocoAceptar();
	void SlotAceptar();
};
#endif
