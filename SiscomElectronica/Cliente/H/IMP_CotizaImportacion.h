
#ifndef __IMP_COTIZAIMPORTACION_H__
#define __IMP_COTIZAIMPORTACION_H__
#include <UIC_H_CotizaImportacion.h>
#include <zProductosCotImp.h>
class SiscomDatCom;
class zSiscomConexion;
class zSiscomRegistro;
class zCotizacionImportacion;
class zProductoCotImp;
class QCotizaImportacion:public CotizaImportacion
{
 Q_OBJECT
public:
	QCotizaImportacion(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCotizaImportacion();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProveedor;
	zCotizacionImportacion *zCotImportacion;
	zSiscomRegistro *zSisRegProducto;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Cotizando();
	void Consultando();
	void Consulta();
	void ContinuaCotizacion();
	void MuestraProductos();
	void MuestraDatosCotizacion();

	void ConsultandoPeso();
	int ConsultaPeso(char *);
	void MuestraPeso(char *);
	void ContinuaCaptura(bool );
	void AnexaProducto();
	void RegistraProducto();
	void ActualizandoProducto(int pintNProducto);
	void SeActivaEliminaProducto();
	void EliminaProductos();
	void TextoDatosCotizacion(char *);
	void MuestraCotizacion();
	void closeEvent(QCloseEvent *);
	void RegistraOtraCotizacion();
	void SeleccionaOtraCotizacion();
	void SeAnexoProducto();
private slots:
	void SlotRegistra();
	void SlotFocoAProveedor();
	void SlotProveedor(zSiscomRegistro *);
	void SlotConsulta();
	void SlotProducto(zSiscomRegistro *);
	void SlotCapturandoCantidad(const QString &);
	void SlotCapturandoPrecio(const QString &);
	void SlotFocoAPrecio();
	void SlotFocoAAnexar();
	void SlotAnexar();
	void SlotSeleccionoProducto(int,int,int,const QPoint &);
	void SlotSeleccionandoProducto(int,int,int,const QPoint &);
	void SlotCambioLaSeleccion();
	void SlotEliminar();
};
extern "C" QCotizaImportacion *InstanciaCotizaImportacion(void *,char **,void *,const char *,int);
#endif
