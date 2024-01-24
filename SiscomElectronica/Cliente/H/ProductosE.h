#ifndef __PRODUCTOS_H__
#define __PRODUCTOS_H__
#include <SISCOMComunicaciones++.h>
#include <qptrlist.h>
#include <qwidget.h>
class QTextEdit;
class QComboBox;
class TipoPrecio;
class ComprasE;
class Familia;
class Unidad;
class ProductoE:public SiscomInformacion
{
public:
	ProductoE(const char *,
		 const char *,
		 const char *,
		 const char *,
		 const char *pchrPtrPrecio="",
		 const char *pchrPtrNmbPrecio="",
		 const char *pchrPtrCantidad="",
		 const char *pchrPtrExistencia="",
		 const char *pchrPtrIdCliente="",
		 const char *pchrPtrIdExpendio="",
		 const char *pchrPtrImporte="",
		 const char *pchrPtrSePuedeVender="",
		 const char *pchrPtrNumJuegos="1",
		 const char *pchrPtrIdProveedor="",
		 const char *pchrPtrProveedor="",
		 const char *pchrPtrNumFactura="",
		 const char *pchrPtrFechaPago="",
		 const char *pchrPtrEdoRegistro="",
		 const char *pchrPtrIdPractica="",
		 const char *pchrPtrNmbUnidad="",
		 const char *pchrPtrAbreviatura="",
		 const char *pchrPtrNmbFamilia="",
		 const char *pchrPtrPrecioIVA="",
		 const char *pchrPtrClienteFrecuente="",
		 const char *pchrPtrPorDescuento="",
		 const char *pchrPtrRFC="",
		 const char *pchrPtrExistenciaMinima="",
		 const char *pchrPtrIdCaja="",
		 const char *pchrPtrRecibi="",
		 const char *pchrPtrCambio="",
		 const char *pchrPtrIdEscuela="IdEscuela",
		 const char *pchrPtrIdBodega="",
		 const char *pchrPtrExisBodega="",
		 const char *pchrPtrPorDescuentoCaja="0",
		 const char *pchrPtrPorDescuentoCajaOrden="0",
		 const char *pchrPtrOrdenACaja="0",
		 const char *pchrPtrCantidadValida="Si",
		 const char *pchrPtrIdOrigenCompra="0",
		 /* Lunes 16 de Noviembre del 2015
		  * Se agrego el soporte para el TipoProducto
		  * Este flag aplicara para el caso de la 
		  * practica de igual forma
		  */
		 const char *pchrPtrEsKit="0",
		 const char *pchrPtrCveKit="0",
		 const char *pchrPtrTipoCotizacion="ParaPrecio",
		 const char *pchrPtrIdProductoKit="",
		 const char *pchrPtrCantidadKit="1",
		 const char *pchrPtrImporteKit="1.0",
		 const char *pchrPtrIdTipoProducto="0",
		 const char *pchrPtrCantidadTransfiereZacatenco="1");
	ProductoE(ProductoE *);
	Familia *ObtenFamilia();
	Unidad *ObtenUnidad();
};
class ProductosE:public QPtrList<ProductoE>
{
public:
	ProductosE();
	ProductosE &operator <<(ProductoE *);
	ProductosE &operator+=(ProductosE &);
	ProductoE *operator[](int);

};

class ConsultaProductosE
{
public:
	ConsultaProductosE();
	ConsultaProductosE(SiscomDatCom *);
	ConsultaProductosE(SiscomDatCom *,
			  const char *,
			  const char *,
			  const char *,
			  const char *,
			  ProductosE &);
	void ObtenDatosProducto(SiscomDatCom *,
				        ProductoE *,
					ProductosE &);
	void ObtenDatosProducto(const char *,
				const char *,
				const char *,
				ProductosE &);
	void ActualizaExistenciaMinima(ProductosE &);
	/*
	void ObtenProductosPorFamilia(SiscomDatCom *,
					     const char *,
					     ProductosE &);

	*/
	void ObtenProductosPorcentajeExistenciaMinima(const char *,
						      const char *,
						      const char *,
						      ProductosE &);
	void ObtenProductosSimilares(const char *,const char *,ProductosE &);
	void ObtenProductosPorDescripcion(const char *,const char *,ProductosE &);
	void ObtenPrecioProducto(TipoPrecio *,ProductoE *,ProductosE &);
	void ActualizaDatosProductos(ProductosE &);
	void RegistraProductos(ProductosE &);
	void ActualizaPrecio(TipoPrecio *,ProductoE *,const char *);
	void ConsultaUltimaCompra(TipoPrecio *,ProductoE *,const char *,ComprasE *);
	
private:
	SiscomDatCom *SisDatCom;
	ProductosE PProductos;
private:
	void GeneraProductos(const SiscomComunicaSrv *,ProductosE &);
	void AsignaDatosUltimaCompra(const SiscomComunicaSrv *,ComprasE *);
};

class QManProductos:public QWidget
{
Q_OBJECT
public:
	QManProductos(SiscomDatCom *,
		      const char *,
		      QComboBox *,
		      QLineEdit *,
		      QTextEdit *,
		      QWidget *,
		      const char *);

	const ProductosE &ObtenProductos();
	void setFocus();
private:
	SiscomDatCom *SisDatCom;
	QComboBox *QCBProductos;
	QLineEdit *QLECProductos;
	QTextEdit *QLEDescripcion;
	ProductosE PProductos;
private:
	void LlenaComboProductos(const char *);
	void ConectaSlots();
	int EsParteLista(const char *);
private slots:
	void S_SeleccionandoProducto(int);
	void S_SeleccionoProducto();
	void S_SeleccionandoProducto(const QString &);
signals:
	void SignalProducto(ProductoE *);
	void SignalNoEstaClave(const char *);
};
#endif
