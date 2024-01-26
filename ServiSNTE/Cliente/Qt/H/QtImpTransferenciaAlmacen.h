#ifndef __QTIMPTRANSFERENCIAALMACEN_H__
#define __QTIMPTRANSFERENCIAALMACEN_H__
#include <cstddef>
#include <TransferenciaAlmacen.h>
#include <zSiscomRegistros.h>
#include <zProductos.h>
class zSiscomConexion;
class zSiscomRegistro;
class zTransferencia;
class zProductoTransferencia;
class QtImpTransferenciaAlmacen:public TransferenciaAlmacen
{
Q_OBJECT
public:
	QtImpTransferenciaAlmacen(QWidget *pQWParent,
			  const char *pchrPtrName);
private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaControles();
	void IniciaVariables();
    	void RegistrandoTransferencia();
	int SeTransfiereAPiso();
	void MarcaComoStock();
	void ActualizandoCantidad(int pintNProducto,const char *pchrPtrCantidad);
	void ActualizandoObservaciones(int pintNProducto,const char *pchrPtrObservaciones);
	void GeneraListaCodigoBarras(QString &);
	void MuestraTransferencia();
	void ReInicia();
	void EliminaProductos();
	void ImporteTransferencia();
	void ImprimeTransferencia();
	void PorClaveProveedor();
private:
    zSiscomConexion *zSisConexion;
	zTransferencia *pzTransferencia;
	zSiscomRegistro *zSiscomTiendasEntrega;
	zSiscomRegistro *zSiscomAlmacenista;
	zSiscomRegistro *zSiscomChofer;
	zSiscomRegistro *zSiscomCamion;
    	zSiscomRegistro *zSisIdTransferencia;
	const char *chrPtrTransfiereAPiso;
	zProductoTransferencia *zProdTransferencia;
	zProductos zProdsTransferencia;
	int intEsStock;
	int intPorClaveProveedor;
private slots:
    void SlotTienda(zSiscomRegistro *pzSiscomTiendasEntrega);
    void SlotAlmacenista(zSiscomRegistro *pzSiscomVendedor);
    void SlotChofer(zSiscomRegistro *pzSiscomChofer);
    void SlotCamion(zSiscomRegistro *pzSiscomCamion);
    void SlotMuestraProductos(zSiscomRegistros *pzSiscomProductos);
    void SlotRegistraTransferencia();
    void SlotImprimeTransferencia();
    void SlotCapturaCantidad(int pintFila,int,int,const QPoint &);
    void SlotAStock();
    void SlotSeleccionaProveedor(zSiscomRegistro *pzSisRegProveedor);
    void SlotTransfiereAPiso();

    void SlotEsStock();
    void SlotCopiar();
    void SlotAgregarProducto();
    void SlotEliminar();
    void SlotCambiandoCodigoBarras(const QString &);
protected:
	void keyPressEvent(QKeyEvent *);
};
#endif
