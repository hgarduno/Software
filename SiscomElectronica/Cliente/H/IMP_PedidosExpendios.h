
#ifndef __IMP_PEDIDOSEXPENDIOS_H__
#define __IMP_PEDIDOSEXPENDIOS_H__
#include <CQSisPedidoMaterial.h>
#include <UIC_H_PedidosExpendios.h>
#include <TransfiereProducto.h>
class SiscomDatCom;
class SiscomRegistros2Pro;
class zSiscomConexion;
class zSiscomRegistro;
class QPedidosExpendios:public PedidosExpendios
{
 Q_OBJECT
public:
	QPedidosExpendios(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPedidosExpendios();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisPedidoMaterial CQSPedidosExps;
	RegsProductoTransfiere RegsProTransfiere;
	int intPedidoSeleccionado;
	int intProductoSeleccionado;

	int intEstadoPedido;
	zSiscomConexion *zSisConexion;

	int intDesactivaValidacionCantidad;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Muestra();
	void MuestraProductosPedido(SiscomRegistrosPro2 *pSisRegsPro2,
				    SiscomRegistro3Lst *pSisReg3LstProductos);
	void Consulta();
	int TransfierePedido();
	int EstadoTransferencia(const char *pchrPtrEdoConexion);
	void ActualizaEstadoPedido(const char *pchrPtrIdEstado);
	int CambiaCantidad(int pintProducto);
	int ValidaCantidadExistencia(const char *pchrPtrCveProducto,char *pchrPtrCantidad);
	void Imprime();
	int SiAlcanza(SiscomRegistrosPro2 *pSisReg2Pro,SiscomRegistro3 *pSisReg3Producto);
	void EliminaTablaProductos();
	int HabilitaEnvio(const char *pchrPtrIdEstado);
	void Colorea(const QMemArray<int> &pQMNoAlcanza,int pintNProductos);
	void ColoreaBlanco();

	int ValidaExistencia();
	void ActualizaInventario();
	void ProductoCantidad(int pintPedido,int pintNProducto,const char **,const char **);
	void DesactivaValidacionCantidad();

	int EstadoValidacionCantidad();
	const char *TextoEstadoValidacionCantidad();
	void TransfiereBodegaAExpendio();
	void TraspasandoExistenciaBodegaAExpendio();
	int TransfiereBodegaAExpendio(const char *pchrPtrCantidad,
				      const char *pchrPtrCveProducto,
				      zSiscomRegistro **pzSisRegRegreso);
	void TransfiriendoBodegaAExpendio();

	void ExistenciaQueQuedaBodegaAExpendio(const char *pchrPtrCveProducto,
					  zSiscomRegistro *pzSisRegRegreso);

	void HabilitaTransfiereEInventario(bool );
private slots:
	void SlotSeleccionandoPedido(int,int,int,const QPoint &);
	void SlotTransfierePedido();
	void SlotConsultaPedidos();
	void SlotSeleccionoProducto(int,int,int,const QPoint &);
	void SlotImprime();
	void SlotFocoAFechaFin();
	void SlotFocoAConsultar();
	void SlotActualizaInventario();
	void SlotDesactivaValCantidad();
	void SlotTranBodegaExpendio();
};
extern "C" QPedidosExpendios *InstanciaPedidosExpendios(void *,char **,void *,const char *,int);
#endif
