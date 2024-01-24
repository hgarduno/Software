
#ifndef __IMP_CAPTURANUMFACTURA_H__
#define __IMP_CAPTURANUMFACTURA_H__
#include <UIC_H_CapturaNumFactura.h>
class SiscomDatCom;
class SiscomRegistro3;
class QCapturaNumFactura:public CapturaNumFactura
{
 Q_OBJECT
public:
	QCapturaNumFactura(SiscomRegistro3 *pSisReg3Factura,
			SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaNumFactura();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Factura;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ActualizaNumeroFactura();
private slots:
	void SlotPasaFocoAceptar();
	void SlotAceptar();

};
#endif
