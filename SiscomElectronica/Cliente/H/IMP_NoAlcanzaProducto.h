
#ifndef __IMP_NOALCANZAPRODUCTO_H__
#define __IMP_NOALCANZAPRODUCTO_H__
#include <UIC_H_NoAlcanzaProducto.h>
class zSiscomRegistros;
class QNoAlcanzaProducto:public NoAlcanzaProducto
{
 Q_OBJECT
public:
	QNoAlcanzaProducto(
	    zSiscomRegistros *pzSisRegDefProducto,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QNoAlcanzaProducto();
private:
	zSiscomRegistros *zSisRegsDefProducto;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraInformacionProducto();
	void reject();
	void ColoreaNoAlcanza();
	void CualesNoAlcanzan(int *);
private slots:
	void SlotAceptar();
};
#endif
