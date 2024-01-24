
#ifndef __IMP_ESTADOSPEDIDO_H__
#define __IMP_ESTADOSPEDIDO_H__
#include <UIC_H_EstadosPedido.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;

class zOrdenes;

class QEstadosPedido:public EstadosPedido
{
 Q_OBJECT
public:
	QEstadosPedido(
		zSiscomConexion *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QEstadosPedido();
private:
	zOrdenes *zOrdenesS;
private:
	zSiscomConexion *zSisConexion;
	void ConsultandoPedidos();
	void Consulta();
	void Muestra();
private:
	void ConectaSlots();
	void IniciaVariables();
	void reject();
private slots:
	void SlotConsulta();
};
#endif
