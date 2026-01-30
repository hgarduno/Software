#ifndef __QTMANEJADORORDEN_H__
#define __QTMANEJADORORDEN_H__
#include <zSiscomDesarrollo4.h>
class QTextEdit;
class QManejadorOrden;
class ManejadorOrden;

class zConexionExpendio;
class zOrdenVenta;
class zExistenciaExpendios;
class zExistenciaExpendio;
class QtManejadorOrden
{
public:
	QtManejadorOrden(ManejadorOrden *pManOrden,
			 QManejadorOrden *pQManOrden);
	int SeleccionandoOrden();
	void ComoSePaga();

	zOrdenVenta *Orden();
	zExistenciaExpendios *EsEx();
	void ExistenciaExpendios(zExistenciaExpendios *);
	void MuestraExistenciaExpendios();
	void MuestraExistenciaExpendio(zExistenciaExpendio *);
	QTextEdit *TextoCliente();
	void TextoCliente(QTextEdit *);

private:
	QManejadorOrden *QManOrden;
	ManejadorOrden *ManOrden;
	zOrdenVenta *zOrdVenta;
	zExistenciaExpendios *zExisExpendios;
	QTextEdit *QTEClienteA;

private:
	int SeleccionaOrden();
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
