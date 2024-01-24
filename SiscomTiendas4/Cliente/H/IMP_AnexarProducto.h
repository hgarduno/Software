
#ifndef __IMP_ANEXARPRODUCTO_H__
#define __IMP_ANEXARPRODUCTO_H__
#include <UIC_H_AnexarProducto.h>
class SiscomDatCom;
class SiscomRegistro3;
class CQSisPaqueteProducto;
class QAnexarProducto:public AnexarProducto
{
 Q_OBJECT
public:
	QAnexarProducto(SiscomDatCom *,
	    char **,
	    const char *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QAnexarProducto();
	CQSisPaqueteProducto *Producto();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	const char *chrPtrIdPaquete;
	SiscomRegistro3 *SisReg3Producto;
	CQSisPaqueteProducto *CQSPaqueteProd;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotSeleccionandoProducto(SiscomRegistro3 *);
	void SlotProducto(SiscomRegistro3 *);
	void SlotPasaFocoAnexarProducto();
	void SlotAnexar();
};
#endif
