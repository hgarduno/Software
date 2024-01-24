#ifndef __IMP_VENTAS_H__
#define __IMP_VENTAS_H__
#include <IMP_VentasPedidos.h>
class Empresa;
class CSISCOMDatComunicaciones;
class QVentas:public QVentasPedidos
{
Q_OBJECT
	public:
		QVentas(CSISCOMDatComunicaciones *,QWidget *,const char *,int );
private:
	CSISCOMDatComunicaciones *CSisDatCom;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void S_RealizaVenta();	
};

extern "C" QVentas *InstanciaVentas(void *,void *,const char *,int);
#endif
