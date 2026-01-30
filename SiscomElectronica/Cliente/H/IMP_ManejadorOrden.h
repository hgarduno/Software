#ifndef __IMP_MANEJADORORDEN_H__
#define __IMP_MANEJADORORDEN_H__
#include <UIC_H_ManejadorOrden.h>
#include <QtManejadorOrden.h>
#include <zExistenciaExpendios.h>

#include <zOrdenVenta.h>
#include <zOrdenes.h>
#include <zExpendios.h>

class SiscomDatCom;
class zSiscomConexion;
class zSiscomRegistro;

class zClienteSiscom;
class zProductoNoAlcanza;
class zUbicacion;

class SiscomRegistro3;

class QMenuManejadorOrden;
class QConExpendiosVenta;
class zExpendio;
class zConexionExpendio;

class zProducto;

class QManejadorOrden:public ManejadorOrden ,public QtManejadorOrden 
{
 Q_OBJECT
public:
	QManejadorOrden(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QManejadorOrden();
	zOrdenVenta *Orden();
	void Orden(zOrdenVenta *pzOrdenVenta);
	void ProductosALaOrden(zSiscomRegistros *);
	zSiscomConexion *Conexion();
	const char *Argumentos(int pintNOrgumento);
	zExpendio *ExpendioActual();
	zOrdenVenta *ProductoCotizado();
	zOrdenVenta *LaUltimaOrden();

	int ComoPago();
	
	void IniciaOrden();
	void ObtenIdOrden();
	void EliminaOrden();
	void ReIniciaInterfaz();
	void ReCotizandoOrden();
	int SePuedeHabilitarRegistro();
	void AgregandoOrden();
	void EliminaOrdenLista();
	void IniciandoOrden();
	int OrdenesDisponibles();
	void MuestraOrdenActual();
	virtual void NuevaOrden();	
	virtual void TextoEncabezado(const char *pchrPtrTexto);
	virtual void TextoEncabezado();
	virtual void TextoBotonRegistro(const char *pchrPtrTexto);
	virtual void TextoBotonNuevaOrden(const char *pchrPtrTexto);
	virtual void Registrar();
	virtual void Imprimir();
	virtual void ImprimirPdf();
	virtual void PagoConTarjeta();
	virtual void OrdenRapidaEscuelaPrincipal();
	virtual void OrdenRapidaOtro();
	virtual void CopiandoPortapapelesTelemarketing();
	virtual void CopiandoPrecioProductoPortapapeles();
	virtual void RegistroRapidoCotizacion();
	virtual void RegistroRapidoCotizacionEnvio();
	/* Tepotzotlan Mexico a 12 Enero 2019
	 * La patanalla mas usada para el punto de 
	 * venta en este momento y que mas se requiere
	 * es la de el estado de circuitos impresos
	 */
	virtual void PantallaMasUsada();
	virtual void Redimensiona();
	virtual void ModificaCotizacion();
	void resizeEvent(QResizeEvent *);
	int ProductosSeleccionados(int *pintPtrProductos);
	void MenuConUnaSeleccion(int ,const QPoint &pQPPosicion);
	void IdConsecutivo(int pintIdConsecutivo);
	void IncrementaConsecutivo(int pintIdConsecutivo);
	void SeEnviaSenalActualizaMenu(int pintSenalActualizaMenu);
	int NoAlcanza();

	void CambiandoCantidades(int );
	int HayCantidadesSeleccionadas(int *pintPtrSeleccionadas);
	void AsignaCantidades(int,int *,const char *);
	void AsignaPrecios(int,int *,const char *);
	void MuestraUbicacion();
	int CambiandoExpendio();
	const char *Expendio();
	const char *IdExpendio();
	void CambiaPrecio(int);
	void CambiandoPrecios(int);

	void ConectandoAlExpendio(int);
	void UltimaOrden();
	void ClientePublicoEnGeneral();
	void CopiandoOrdenDesdePortaPapeles();
	int SoloDescripcion();
	void SoloDescripcion(int);
	void CambiandoAlExpendio(int);
	int HabilitaImpresionRegistro();

	void AsignandoOrdenSeleccionada();

	void Parent(QWidget *);


	QWidget *Parent();

	void ConsultaExistenciaExpendios();

private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zSiscomConexion *zSisOExpendio;
	zSiscomRegistro *zSisRegProducto;


	zOrdenVenta *zOrdVenta;
	zOrdenVenta *zOrdCotProducto;
	zOrdenVenta *zOrdVUltima;
	zOrdenes zOrdsVenta;
	zProductoCotizar *zProdCotizar;
	zSiscomRegistro *zSisRegEdoCotizacion;
	int intIdConsecutivo;
	char *chrPtrIdOrden;
	int intNoAlcanza;
	zUbicacion *zUbProducto;

	QColor QCFondoBotones;
	QConExpendiosVenta *QConExpsV;
	int intSeAbrioOExpendios;
	zConexionExpendio *zConExpendio;

	int intSoloDescripcion;

	zProducto *zProdPPFaltante;

	QWidget *QWParent;

	 zExistenciaExpendios zExExpendios;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraPuntoVenta();
	void CargaArchivoHtmlPuntoVenta();
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void CotizandoProducto(zSiscomRegistro *pzSisRegProducto);
	void MuestraCotizacionProducto(zOrdenVenta *pzOrdVenta);
	void CotizandoOrden();
	void CotizaOrden();
	void MuestraDatosCliente();
	int MuestraProducto(int pintNProducto,zProductoCotizar *);
	int MuestraDefinicionProducto(zOrdenVenta *pzOrdVenta,zProductoCotizar *,int *);
	int NoEsProducto(zProductoCotizar *pzProdCotizar);
	void MuestraProductos(zOrdenVenta *);
	void MuestraProductos2(zOrdenVenta *);
	void MuestraNoProductos(zOrdenVenta *);
	void MuestraOrdenCotizada(zOrdenVenta *pzOrdenVenta);
	void MuestraNombreKit(int pintFila,zProductoCotizar *pzProdCotizar);
	void MuestraProductoKit(int pintFila,zSiscomRegistro *pzSisProducto);
	void CambiaCantidad(int pintProducto);
	void CambiaNoJuegos(const char *pchrPtrNoJuegos);
	void CapturaCantidad(const char *,char *pchrPtrCantidad);
	int ReCotizaOrden();
	int ReCotizandoPorEliminacion(zProductoCotizar *pzProdCotizar);
	void SePuedeAnexarProducto(zProductoCotizar *);
	void AvisoNoAlcanza(zProductoCotizar *pzProdCotizar);
	void DescuentoOrden(const char *pchrPtrDescuentoOrden);
	void DescuentoProducto(const char *pchrPtrDescuentoProducto);
	void SeleccionandoOrden();
	int EsCantidadValida();
	int SeHabilitaPagoConTarjeta();
	void ConsultandoExistenciaExpendios();
	int SeMuestraDefinicionProducto(zProductoCotizar *pzProdCotizar);
	void TeclasEspeciales(QKeyEvent *pQKEvent);
	void TeclasNormales(QKeyEvent *pQKEvent);
	void EliminaProductos();
	void AsignaIdOrden(int);

	void SeImprimeSinTiquet();
	void CopiandoPortaPapeles();
	void ComunicacionExpendio();
	void ComunicacionExpendio(zExpendio *);
	void IniciaConexionExpendio();
	void CambiaColorBotonVenderImprimir(const QColor &);
	void CambiandoColorBotonVenderImprimir();
	void CambiandoDeExpendio(int);
	void CargaUltimaOrden();
	zExpendio *IniciaExpendioActual();

	zConexionExpendio *ContinuandoConOtroExpendio();	

	void RegistrandoFaltante();
	/* Ciudad de Mexico 14 de Agosto 2024 
	 * Se integra la validacion para ver si se carga la ventana 
	 * de pago con tarjeta, transferencia etc , para que en el 
	 * caso de Donacion, material a la area de diseno y cotizacion 
	 * no se paga , por lo tanto no se debe cargar la ventana de
	 * como pago
	 */
	int  SeCargaComoPago();

protected:
	void keyPressEvent(QKeyEvent *pQKEvent);
	
public slots:	
	virtual void SlotAnexarOrden();
	virtual void SlotCantidad(int,int,int,const QPoint &);
private slots:
	void SlotSeleccionoProducto(zSiscomRegistro *pzSisRegProducto);
	void SlotFocoAProducto();
	void SlotNuevaOrden();
	void SlotRegistrar();
	void SlotImprimir();
	void SlotActivaMenu(int pintFila,int pintColumna,const QPoint &pQPosicion);
	void SlotEliminaProducto(zProductoCotizar *pzProdCotizar);
	void SlotNumeroJuegos(const char *pchrPtrNumeroJuegos);
	void SlotJuegosSeparados(int pintJuegosSeparados);
	void SlotDescuentoOrden(const char *pchrPtrDecuentoOrden);
	void SlotDescuentoProducto(const char *pchrPtrDesProducto);
	void SlotPrecioProducto();
	void SlotCapturandoCantidad(const QString &);
	void SlotPagoConTarjeta();
	void SlotExistenciaExpendios();

	void SlotCargaCotizacion();

	void SlotImprimirPdf();
	void SlotFaltante();
	void SlotProductoNoValido(zProducto *);

signals:
	void SignalNoSePuedeVender(zProductoCotizar *pzProdCotizar);
	void SignalActualizaMenu(const QString &);
};
#endif
