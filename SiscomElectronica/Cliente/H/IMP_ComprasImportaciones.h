
#ifndef __IMP_COMPRASIMPORTACIONES_H__
#define __IMP_COMPRASIMPORTACIONES_H__
#include <UIC_H_ComprasImportaciones.h>
#include <zCompraImportacion.h>
class SiscomDatCom;

class zSiscomConexion;
class zSiscomRegistro;
class zProductoImportado;
class zProductoImportadoInf;
class SiscomRegistro3;

class QRegistroParcialComImp;

class zCompraParcialImportacion;
class QComprasImportaciones:public ComprasImportaciones
{
 Q_OBJECT
public:
	QComprasImportaciones(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QComprasImportaciones();
	void CompraImportacion(zCompraImportacion *);
	void MuestraCompraImportacion();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	/*
	zSiscomRegistro *zSisRegEmpresa;
	*/
	zEmpresa *zEmpresaA;
	zCompraImportacion zComImportacion;
	zProductoImportado *zProdImportado;
	zProductosImportados *zProdsImportados;
	zProductoImportadoInf *zProdImportadoInf;
	int intProductoSeleccionado;
	int intSeGuardaComo;

	int intCapturaSinGuardar;
 	
	SiscomRegistro3 *SisReg3Bodega;
	QRegistroParcialComImp *QRegParComImp;
	QWidget *QWParent;
	zCompraParcialImportacion *zComParcialI;
private:

	zProductoImportado *ProductoImportado(int);
	void ActualizaPrecioUnitario(const char *pchrPtrPrecio,zProductoImportado *);
	void ActualizaPeso(const char *,zProductoImportado *);
	void ActualizaPeso(zProductoImportado *);
	void RegistrandoParcialmenteCompra();
	

	void ConectaSlots();
	void IniciaVariables();
	void PesoRegistrado();
	void NoEstaElPesoRegistrado();
	void AnexandoProducto(zSiscomRegistro *pzSisRegProducto);
	void Calculando();
	int EnviaDatos(char *);
	void MostrandoCalculos();
	void MuestraProductos();
	void RegistraCompra();
	bool ValidandoNumeroPartidas();
	void EliminaCompraActual();
	void EliminaProducto();
	bool ValidaDatosEnvio();
	bool ValidaDatosProducto();
	bool ValidandoDatos();
	void ProductosPorFiltro();
	void ConsultandoProductosPorFiltro();
	void ConsultaProductosFiltrados();
	void MuestraProductosFiltrados();
	void ActualizaDatosProducto();
	int ConsultaCompraImportacion(const char *pchrPtrIdCompra,char *);
	void ConsultandoCompraImportacion(const char *pchrPtrIdCompra);
	const char *FormaSignalCambiandoDato(const char *pchrPtrDato);
	void GuardandoCompraImportacion();
	void GuardaCompraImportacion();
	int ValidandoParaAnexar();
	void VeSiSePasaElFocoAProducto();
	int YaTieneDescripcionCompra();
	void CargandoCompra();
	void MuestraDescripcion();
	void HabilitaProveedores();
	void HabilitaProductos();
	void HabilitandoGuardaCompra();
	void HabilitandoRegistraCompra();
	void HabilitandoBodegas();
	void HabilitaSeleccionaBodega();
	void HabilitaRegistroParcialActualizaCompra(QPushButton *);
	void closeEvent(QCloseEvent *);
	void ProductoImportadoInf(zSiscomRegistro *);
	void ConsultaProductoImportadoInf(zSiscomRegistro *);
	void MuestraProductoImportadoInf();
	int TieneClaveProveedor();
	void TeniendoClaveProveedor();
	void HabilitaDesHabilitaCantidadCosto(bool pbModal);
	void HabilitandoProveedoresCompra();
	void GuardarComo();
	void GuardandoComo();

	void MuestraProveedor();
	void ArchivoCompraProveedor();
	void CompletaProductosImportacion();
	void BodegasSiscom();
	void MuestraBodega();

	int YaSeleccionoBodega();
        void AgregandoProductoParaRegistroParcial(zProductoImportado *);
	void AsignaGenerales();
	void ActualizandoCompra();
	void EnviaActualizacionCompra();
private slots:

	void SlotCapturandoNumFactura(const QString &);
	void SlotCapturandoCostoEnvio(const QString &);
	void SlotCapturandoCostoDolar(const QString &);
	void SlotCapturandoCostoAdministrativo(const QString &);
	void SlotCapturandoNumPartidas(const QString &);

	void SlotCapturandoCantidad(const QString &);
	void SlotCapturandoCostoUnitario(const QString &);

	void SlotSeleccionoProducto(zSiscomRegistro *);
	void SlotSeleccionoProveedor(zSiscomRegistro *);
	void SlotFocoACostoUnitario();
	void SlotFocoAAnexar();

	void SlotFocoACotizacionDolar();
	void SlotFocoACostoAdministrativo();
	void SlotFocoANumPartidas();
	void SlotFocoACostoEnvio();

	void SlotFocoAProductos();
	void SlotAnexarProducto();
	void SlotRegistraCompra();
	void SlotEliminar();

	void SlotSeleccionaProducto(int,int,int,const QPoint &);
	void SlotProveedores();
	void SlotActualiza();
	void SlotGuardaCompra();
	void SlotCapturandoDscCompra(const QString &);
	void SlotCargaCompra();
	void SlotCapturoDescripcion();
	void SlotGuardarComo();
	void SlotOtroProveedor();

	void SlotArchivoCompraProveedor();

	void SlotAOtraCelda(int,int);
	void SlotBodegas();
	void SlotRegParProductos();
	void SlotAgregandoParaRegistroParcial(int,int,int,const QPoint &);
	void SlotActualizaCompra();
	void SlotRegistroParcialCompra();
};
extern "C" QComprasImportaciones *InstanciaComprasImportaciones(void *,char **,void *,const char *,int);
#endif
