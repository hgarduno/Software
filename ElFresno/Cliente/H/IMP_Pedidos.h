#ifndef __IMP_PEDIDOS_H__
#define __IMP_PEDIDOS_H__
#include <IMP_VentasPedidos.h>
class CSISCOMDatComunicaciones;
class SiscomDatCom;
class Empresa;
class QPedidos:public QVentasPedidos
{
Q_OBJECT
	public:
		QPedidos(CSISCOMDatComunicaciones *,QWidget *,const char *,int );
private:
	CSISCOMDatComunicaciones *CSisDatCom;
	Empresa *E_Matriz;
private:
	void IniciaVariables();
	void ObtenDatosMatriz();
	void ConectaSlotsPedidos();
private slots:
	void S_RegistraPedido();
};

extern "C" QPedidos *InstanciaPedidos(void *,void *,const char *,int);
#endif
