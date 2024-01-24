
#ifndef __IMP_CAMBIAELIMINACLAVEPRODUCTO_H__
#define __IMP_CAMBIAELIMINACLAVEPRODUCTO_H__
#include <UIC_H_CambiaEliminaClaveProducto.h>
class SiscomDatCom;
class SiscomRegistro3;
class QCambiaEliminaClaveProducto:public CambiaEliminaClaveProducto
{
 Q_OBJECT
public:
	QCambiaEliminaClaveProducto(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCambiaEliminaClaveProducto();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Producto;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotProducto(SiscomRegistro3 *pSisReg3Producto);
	void SlotCambiaClave();
	void SlotPasaFocoCambiaClave();
	void SlotEliminaProducto();
};
#endif
