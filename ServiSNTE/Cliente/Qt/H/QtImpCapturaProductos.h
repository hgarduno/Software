#ifndef __QTIMPCAPTURAPRODUCTOS_H__
#define __QTIMPCAPTURAPRODUCTOS_H__
#include <cstddef>
#include <CapturaProductos.h>
#include <zCostos.h>
#include <zDescuentos.h>

class zSiscomConexion;
class zSiscomRegistro;

class zCosto;
class zDescuento;
class zProducto;
class QTable;

class QtImpCapturaProductos:public CapturaProductos
{
Q_OBJECT
public:
	QtImpCapturaProductos(QWidget *pQWParent,
			  const char *pchrPtrName);

public:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaControles();
	void SeleccionaProducto();
	void MuestraProducto();
	void AnexaCosto(const char *pchrPtrCampos[],QTable *pQTabla,
			zSiscomRegistro *pzSisRegistro,
			zCostos *pzCostos);
  	zCosto *Costo(const QString &pQSCantidad);
  	zCosto *Costo(const QString &pQSCantidad,const QString &pQSIva);

	void RegistraPrecios();

	void ActivaControlesCrea();

	void ConectaSlotsCrear();
	void ConectaSlotsConsultar();
	void Creando();
	void Creado();

	void Consultando();
	void ControlesParaConsultar();
	zProducto *CreaProducto();
	void RegistraProducto(zProducto *);
	void ReIniciaCaptura();
	void CapturaIvaCostoBruto(int pintNFila);
	void MuestraCostos(const char *pchrPtrCampos[],QTable *pQTDatos,zCostos *pzCostos);
	void MuestraCostos();
	void MuestraDescuentos();

	zSiscomRegistro *PrecioGeneral(zCosto *pzCosto);
	zSiscomRegistro *PrecioForaneo(zCosto *pzCosto);
	zSiscomRegistro *CostoBruto(zCosto *pzCosto);

	void CalculandoCostoProveedor(zCosto *pzCosto);
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisProveedor;
	zSiscomRegistro *zSisProducto;
	zSiscomRegistro *zSisDepartamento;
	zCostos zCostosBruto;
	zCostos zCostosGeneral;
	zCostos zCostosForaneo;
	zDescuentos zDescuentosDesc;

	zDescuento *zDescuentoP;
	zCosto *zCostoP;
	zProducto *zProdPrecios;
	int intCreando;
	int intConsultando;
private:
	int ConsultaProducto();
	void ConsultandoProducto();
	void LimpiandoInterfaz();
private slots:
	void SlotProveedor(zSiscomRegistro *);
	void SlotConsulta();
	void SlotCCBruto();
	void SlotCPGeneral();
	void SlotCPForaneo();
	void SlotCDescuento();

	void SlotAgregarPrecios();

	void SlotCrear();
	void SlotProveedorCrear(zSiscomRegistro *);
	void SlotDepartamentoCrear(zSiscomRegistro *);

	void SlotFocoModelo();
	void SlotFocoDepartamento();

	/*void SlotCapturaDatoCostoBruto(int pintNFila,int ,int,const QPoint &); */


	void SlotFocoANombre();
};

#endif
