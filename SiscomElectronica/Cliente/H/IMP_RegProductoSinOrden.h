
#ifndef __IMP_REGPRODUCTOSINORDEN_H__
#define __IMP_REGPRODUCTOSINORDEN_H__
#include <UIC_H_RegProductoSinOrden.h>
class SiscomDatCom;
class SiscomRegistro3;
class QRegProductoSinOrden:public RegProductoSinOrden
{
 Q_OBJECT
public:
	QRegProductoSinOrden(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QRegProductoSinOrden();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Producto;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	
	void SlotSeleccionando(SiscomRegistro3 *);
	void SlotSelecciono(SiscomRegistro3 *);
	void SlotPasaFocoRegistrar();
	void SlotRegistrar();
};
#endif
