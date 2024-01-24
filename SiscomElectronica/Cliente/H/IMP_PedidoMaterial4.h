#ifndef __IMP_PEDIDOMATERIAL4_H__
#define __IMP_PEDIDOMATERIAL4_H__
#include <UIC_H_PedidoMaterial4.h>


#include <zPedidoExpendio.h>

class SiscomDatCom;
class zSiscomConexion;
class zSiscomRegistro;

class zProductoPedido;
class QPedidoMaterial4:public PedidoMaterial4
{
 Q_OBJECT
public:
	QPedidoMaterial4(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPedidoMaterial4();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zPedidoExpendio zPedExpendio;
	zSiscomRegistro *zSisRegProducto;

	int intProductoSeleccionado;

	int intActualizando;
	int intActualizandoObsPedido;
	
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoPedidoHoy();
	void MuestraPedidoHoy();
	int ConsultaPedidoHoy();
	void ProductoSeleccionado();
	void AnexandoProducto();
	void ProductoAPedidoExpendio();
	void IniciandoPedidoExpendioHoy();
	void IniciaPedidoExpendioHoy();
	void MuestraPedido();
	void MuestraProductos();
	void Producto(zProductoPedido *);
	void ReIniciaCaptura();
	void  HabilitaEliminar();
	void HabilitaActualizar();
	void EliminandoProducto();
	void InterfazActualizandoProducto(bool pbActualizando);
	void PreparaCantidadParaActualizar();
	void ActualizaProducto();
	void RegistrandoPedido();
	void InterfazActualizandoObsPedido(bool pbEstado);
	void ActualizandoObservacionesPedido();	
private slots:
	void SlotSeleccionoProducto(zSiscomRegistro *);
	void SlotFocoAAnexar();
	void SlotAnexarProducto();
	void SlotSeleccionaProducto(int,int,int,const QPoint &);
	void SlotEliminaProducto();
	void SlotActualizaProducto();
	void SlotRegistraPedido();
	void SlotActualizaObservacionesPedido();
	void SlotActualizaObsProducto(int,int);
};
extern "C" QPedidoMaterial4 *InstanciaPedidoMaterial4(void *,char **,void *,const char *,int);

#endif
