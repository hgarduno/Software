#ifndef __QTIMPCAPTURAABONOAPARTADO_H__
#define __QTIMPCAPTURAABONOAPARTADO_H__
#include <cstddef>
#include <CapturaAbonoApartado.h>

class zReciboApartado;
class zSiscomConexion;
class QtImpCapturaAbonoApartado:public CapturaAbonoApartado
{
Q_OBJECT
public:
	QtImpCapturaAbonoApartado(
			zSiscomConexion *pzSisConexion,	
			QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false);
	int Aceptar();
	void Cantidad(zReciboApartado *pzRecibo);
private:
	void ConectaSlots();
	void IniciaVariables();
	void ObtenFolio();
private:
	int intAceptar;
	zSiscomConexion *zSisConexion;
private slots:
	void reject();
	void SlotAceptar();
	void SlotCancelar();
	void SlotCantidad();
	void SlotFocoACantidad();

};
#endif
