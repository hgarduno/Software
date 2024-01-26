#ifndef __QTIMPCAPTURACAMIONES_H__
#define __QTIMPCAPTURACAMIONES_H__
#include <cstddef>
#include <CapturaCamiones.h>

class zSiscomConexion;
class zSiscomRegistro;
class zCamion;
class QtImpCapturaCamiones:public CapturaCamiones
{
Q_OBJECT
public:
	QtImpCapturaCamiones(QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false);
	zCamion *Camion();

private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	zCamion *FormaCamion();
private:
	zSiscomConexion *zSisConexion;
	zCamion *zDatCamion;
private slots:
	void reject();
	void SlotCrear();
	void SlotCancelar();
	void SlotFocoANombre();
	void SlotFocoAMarca();
	void SlotFocoATipo();
	void SlotFocoAModelo();
	void SlotFocoAPlacas();
	void SlotFocoACrear();
};



#endif
