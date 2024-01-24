
#ifndef __IMP_CAPTURAPESOPRODUCTO_H__
#define __IMP_CAPTURAPESOPRODUCTO_H__
#include <UIC_H_CapturaPesoProducto.h>
class SiscomDatCom;
class zSiscomConexion;
class zSiscomRegistro;
class QCapturaPesoProducto:public CapturaPesoProducto
{
 Q_OBJECT
public:
	QCapturaPesoProducto(
	    zSiscomRegistro *pzSisRegProducto,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaPesoProducto();
	int Regreso(char *pchrPtrPeso);
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProducto;
	int intRegreso;
private:
	void ConectaSlots();
	void IniciaVariables();
	void RegistrandoPeso();
	int RegistraPeso();
private slots:
	void SlotFocoARegistrar();
	void SlotRegistrar();
	void SlotTerminar();
};
#endif
