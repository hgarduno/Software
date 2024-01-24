#ifndef __IMP_PEDIDOSPENDIENTES_H__
#define __IMP_PEDIDOSPENDIENTES_H__
#include <UIC_H_PedidosPendientes.h>
#include <SiscomRegistros3.h>
class SiscomDatCom;
class SiscomRegistro3;
class SiscomRegistro3Lst;
class QPedidosPendientes:public PedidosPendientes
{
 Q_OBJECT
public:
	QPedidosPendientes(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QPedidosPendientes();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	SiscomRegistro3Lst SisReg3LstPedidos;
	SiscomRegistro3 *SisReg3Pedido;
	
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void Muestra();

	void ConsultandoDetallePedido(SiscomRegistro3 *pSisReg3Pedido);
	void ConsultaDetallePedido(SiscomRegistro3 *pSisReg3Pedido,SiscomRegistro3Lst *pSisReg3LstDetallePedido);
	void MuestraDetallePedido(SiscomRegistro3Lst *pSisReg3LstDetallePedido);

	void EnviarAMatriz();

private slots:
	void SlotSeleccionoPedido(int,int,int,const QPoint &);
	void SlotEnviarAMatriz();

};
#endif
