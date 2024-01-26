#ifndef __QTIMPCANCELARFOLIO_H__
#define __QTIMPCANCELARFOLIO_H__
#include <CancelarFolio.h>


class zSiscomConexion;
class zSiscomRegistro;
class zVenta;

class QtImpCancelarFolio:public CancelarFolio
{
Q_OBJECT
public:
	QtImpCancelarFolio(zVenta *pzVenta,
			  QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  bool pbModal=false,
			  WFlags pWFlags=false);
	int Aceptar();
private:
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
	void IniciaVariables();
	void ObtenFolio();
	void AplicarCancelacion();
private:
	int intAceptar;
	zVenta *zVentaDat;
	zSiscomConexion *zSisConexion;
private slots:
	void reject();
	void SlotAceptar();
	void SlotCancelar();
	void SlotRegistrarCancelacion();

};
#endif
