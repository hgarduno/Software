#ifndef __IMP_CLIENTEALUMNO_H__
#define __IMP_CLIENTEALUMNO_H__
#include <UIC_H_ClienteAlumno.h>

class zSiscomConexion;
class zSiscomRegistro;
class zClienteSiscom;
class zApartado;
class zCotizacion;
class zOrdenVenta;

class QRegistroApartado;
class QCierraApartado;
class QDescripcionCotizacion;
class QCotizaciones;
class QRegistroPlaca;
class QSeleccionaOrden;


class QClienteAlumno:public ClienteAlumno
{
 Q_OBJECT
public:
	QClienteAlumno(const char *pchrPtrTipoPersona,
		       zOrdenVenta *pzOrdenVenta,
			QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QClienteAlumno();
	zClienteSiscom *Cliente();
	zApartado *Apartado();
	zCotizacion *Cotizacion();
	int Aceptar();
	const char *IdTipoOrden();
	int IdTipoOrdenInt();
	zOrdenVenta *Orden();
	void Orden(zOrdenVenta *pzOrdenVenta);
	int YaSeImprimio();
	int SePagoImpreso();
	QWidget *Parent();
private:
	zClienteSiscom *zCliSiscom;
	zSiscomRegistro *zSisRegEscuela;
	zCotizacion *zCotOrden;
	zOrdenVenta *zOrdVenta;
	zSiscomRegistro *zSisRegCliMayoreo;
	int intAceptar;
	QRegistroApartado *QRApartado;
	QCierraApartado  *QCApartado;
	QDescripcionCotizacion *QDCotizacion;
	QCotizaciones *QCotizacion;
	QSeleccionaOrden *QSelOrden;
	QRegistroPlaca *QRPlaca;
	/*
	zSiscomRegistro *zSisRegApartado;
	*/
	zOrdenVenta *zOrdenVApartado;
	int intMRegApartado;

	int intTipoOrden;
	int intSeImprimio;
	int intSeCapturoDesVenta;
	const char *chrPtrTipoPersona;
	QWidget *QWParent;
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoPublicoEnGeneral();
	void ConsultaPublicoEnGeneral();
	void MuestraPublicoEnGeneral();
	void reject();
	void CapturaDatosApartado();
	void CapturaDescripcionCotizacion();
	void AsignaApartado();
	void CierraApartado();
	void PagarApartado();
	void VendeCotizacion();
	void CancelaOrden();
	void VerificandoVendiendo();	
	void VerificandoEscuela();
	void VerificandoNombre();
	void OrdenActual();
	void ConsultandoEstadosPedido();
	void HabilitaDesHabilitaAceptarCancelar(bool pbEstado);
	void RegistrandoPlaca();
	void MaterialAreaDiseno();
	void DonacionMaterial();
	void ModificaOrden();
	void SeAgregaDescripcionVenta();
	void DatosPractica();
	void IniciaControlesOtrosMovimientos();
	void ConectaSlotsOtrosMovimientos();
	void HabilitaBotonesOtrosMovimientos(bool);
private slots:
	void SlotEscuela(zSiscomRegistro *pzSisRegEscuela);
	void SlotFocoAAceptar();
	void SlotAceptar();
	void SlotCancelar();
	void SlotTipoOrden(int pintTipoOrden);
	void SlotAceptarApartado();
	void SlotPagar(zOrdenVenta *);
	void SlotCotizacion(zCotizacion *pzCotizacion);
	void SlotOtroMovimiento();
	void SlotCancelarApartado();
	void SlotOrdenVenta(zOrdenVenta *pzOrdenVenta);
	void SlotModificaCotizacion(zOrdenVenta *pzOrdenVenta);
	void SlotNuevaOrden();
	void SlotClienteMayoreo(zSiscomRegistro *);
	void SlotCapturandoDesVenta();
	void SlotOrdenFavorita(zOrdenVenta *);
	void SlotCanceloRegistroApartado();
};
#endif
