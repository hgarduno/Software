/*#ifndef __QTIMPCANCELARFOLIOABONO_H__
#define __QTIMPCANCELARFOLIOABONO_H__
#include <CancelarFolioAbono.h>


class zSiscomConexion;
class zSiscomRegistro;
class zReciboApartado;

class QtImpCancelarFolioAbono:public CancelarFolioAbono
{
Q_OBJECT
public:
	QtImpCancelarFolioAbono(zVenta *pzVenta,
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
#endif*/
