#ifndef __QTMANEJADORORDEN_H__
#define __QTMANEJADORORDEN_H__
#include <zSiscomDesarrollo4.h>
class QManejadorOrden;
class ManejadorOrden;

class zConexionExpendio;
class zOrdenVenta;
class QtManejadorOrden
{
public:
	QtManejadorOrden(ManejadorOrden *pManOrden,
			 QManejadorOrden *pQManOrden);
	void SeleccionandoOrden();
	void ComoSePaga();

	zOrdenVenta *Orden();


private:
	QManejadorOrden *QManOrden;
	ManejadorOrden *ManOrden;
	zOrdenVenta *zOrdVenta;

private:
	void AsignaOrdenCotizacion();
	void SeleccionaOrden();
	void FormaPago();
};

#define LogConexionExpendio(pzConExpendio) 			\
	zSiscomDesarrollo4::Log(__FILE__,			\
			        __FUNCTION__,			\
				__LINE__,			\
				"Servidor (%s:%d)",		\
				pzConExpendio->DireccionIp(),	\
				pzConExpendio->PuertoInt())	\




#endif
