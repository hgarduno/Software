
#ifndef __IMP_ORDENESREGISTRADAS_H__
#define __IMP_ORDENESREGISTRADAS_H__
#include <QtOrdenesRegistradas.h>
#include <zDevolucion.h>
class SiscomDatCom;
class zSiscomConexion;
class zOrdenes;
class zOrdenVenta;
class zExpendio;
class QOrdenesRegistradas:public QtOrdenesRegistradas
{
 Q_OBJECT
public:
	QOrdenesRegistradas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QOrdenesRegistradas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zOrdenes *zOrdsRegistradas;

	zDevolucion zDevOrden;
private:

	void Consultando();
	void Consulta();
	

	 void ImprimeTicketOrden();
	 void VendeOrden();

	 void Devolucion();
	 void Devuelve(); 
	 void ActivaBotones(bool pbModal);
	 void YaSeReflejoTransferencia();

private slots:
	 void SlotConsulta();
	void SlotImprimir();
	void SlotVender();
	void SlotDevolucion();
	void SlotSeReflejo();
};
extern "C" QOrdenesRegistradas *InstanciaOrdenesRegistradas(void *,char **,void *,const char *,int);
#endif
