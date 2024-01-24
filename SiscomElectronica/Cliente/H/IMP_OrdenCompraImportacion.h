
#ifndef __IMP_ORDENCOMPRAIMPORTACION_H__
#define __IMP_ORDENCOMPRAIMPORTACION_H__
#include <UIC_H_OrdenCompraImportacion.h>
class SiscomDatCom;
class zSiscomConexion;
class zSiscomRegistro;


class zProductoCompraImportacion;
class QOrdenCompraImportacion:public OrdenCompraImportacion
{
 Q_OBJECT
public:
	QOrdenCompraImportacion(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QOrdenCompraImportacion();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProducto;
	zSiscomRegistro *zSisRegProveedor;

	zProductoCompraImportacion *zProdComImp;
private:
	void ConectaSlots();
	void IniciaVariables();
	void SeleccionaProveedor();
	void ObteniendoProducto();
	void ConsultaProducto();
	void MuestraProducto();

	void MuestraDatosProducto();
	void MuestraUltimaCompra();
	void PasandoFocoCantidad();
	void PasandoFocoAPrecio();

	void HabilitandoAnexar();
	void CalculandoPesoImporteTotal();
	void CalculaPesoImporteTotal();
	void MuestraPesoImporteTotal();
	void AsignaPrecio();
	void AsignaCantidad();
private slots:
	void SlotProveedor(zSiscomRegistro *);
	void SlotProducto(zSiscomRegistro *);
	void SlotFocoAPrecio();
	void SlotFocoAAnexar();
	void SlotCapturandoCantidad(const QString &);
	void SlotCapturandoPrecio(const QString &);
};
extern "C" QOrdenCompraImportacion *InstanciaOrdenCompraImportacion(void *,char **,void *,const char *,int);
#endif
