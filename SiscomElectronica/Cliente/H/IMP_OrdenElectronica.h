#ifndef __IMP_ORDENELECTRONICA_H__
#define __IMP_ORDENELECTRONICA_H__

#include <UIC_H_OrdenElectronica.h>

#include <CQSisPuntosElectronica.h>
#include <Seguridad3Protocolo2.h>
#include <qiconview.h>
#include <ProductosE.h>
#include <qmemarray.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QPushButton;
class QLCDNumber;
class SiscomDatCom;
class Persona;
class ProductoE;
class QIconVOrdenE;
class SiscomRegistro3;
class MenuOrdenElectronica;
/*!
 * Integra la funcionalidad que permite controlar <br>
 * el detalle de la orden
 */
class QOrdenElectronica : public OrdenElectronica,
			  public Seguridad3Protocolo2
{
    Q_OBJECT

public:
   /*!
    * Constructor de la clase
    */
    QOrdenElectronica(SiscomDatCom *,
    		      char **pchrPtrArgumentos,
    		      Persona *,
		      const char *,
		      const char *,
		      const char *,
    			QWidget* parent = 0,
			const char* name = 0, 
			WFlags fl = 0 );
    /*!
     * Destructor de la clase
     */
    ~QOrdenElectronica();
    /*!
     * Regresa los datos del cliente
     */
    Persona *ObtenPersona();
    void ActivaOrden();
    void AnexaProductoALaOrden(ProductoE *);
    void AnexaProductosALaOrden(ProductosE );
    const char *ObtenImporteTotal();
    void PonQIconAsociado(QIconVOrdenE *);
    void Escuela(SiscomRegistro3 *pSisReg3Escuela);
    void ModificaOrdenPorCajaCentral(int pintModifcaOrdenPorCajaCentral);
    
private:
	SiscomDatCom *SisDatCom;
	Persona *PPersona;
	ProductosE PProductos;
	QIconVOrdenE *QIVOrdenE;
	QPixmap QPMarcas[20];
	int intTurnoIcono;
	int intNumJuegos;
	MenuOrdenElectronica *MOElectronica;
	const char *chrPtrIdEmpleado;
	int intYaSeNotificoClienteFrecuente;
	const char *chrPtrClienteFrecuente;
	const char *chrPtrPorDescuento;
	char chrArrIdOrden[20];
	const char *chrPtrIdExpendio;
	char chrArrRecibi[20];
	const char *chrPtrCambio;

	char **chrPtrArgumentos;
	SiscomRegistro3 *SisReg3Escuela;
	const char *chrPtrIdCaja;

	/*
	 * Viernes 29 Julio 2011
	 *
	 * Se agrego el manejo de los puntos promociones electronica
	 *
	 */

	CQSisPuntosPromocionCliente CQSPPCliente;
	/* Viernes 18 De Enero del 2013
	 * Cuando la orden se modifica de la caja central
	 */
	 
	 int intModificaOrdenPorCajaCentral;
private:
	void ColocaEncabezado();
	void ConectaSlots();
	void CotizaOrden();
	void RedimensionaColumnas();
	void IniciaVariables();
	void CambiaCantidad(int );
	QMemArray<int> CuantosProductosSeleccionados();
	ProductosE ProductosSeleccionados();
	void CambiaNumeroJuegos(QMemArray<int>,int );
	int EliminaProductos(ProductosE );
	int AvisoNoSePuedeVender(ProductoE *);
	void closeEvent(QCloseEvent *);
	void Imprime(const char *);
	void MuestraProductos();
	void VentaCaja();
	void AgregaInformacionCaja();

	const char *ImporteTotal();
	const char *IdCaja();

	int ValidaCierreOrden();

	void PuntosPromocionesCliente();

	void AsignaPorcentajeDescuentoOrden(int);

	void SeModificoLaOrdenEnLaCaja();
public slots:
	void S_ImprimeTicket();
	void S_ImprimeCotizacion();
	void S_RealizaVenta();
	void S_OperacionCotizacion(int,int,int,const QPoint &);
	void S_CargaMenu(int,int,const QPoint &);
	void S_CambioNumJuegos(int);
	void S_JuegosSeparados(int);
	void S_EliminaProductos();
	void S_RCotizacion();
	void S_VendeCotizacion();
	void S_OrdenVendida();
	void S_PorcentajeDescuento();
	void S_PorcentajeDescuentoOrden(int);
	void S_OrdenCaja();
signals:
	void SignalVendeOrden(QOrdenElectronica *);
	void SignalJuegosSeparados(int,ProductosE &);
	void SignalCancelarVenta(QOrdenElectronica *);
};
class QIconVOrdenE:public QIconViewItem
{
public:
	QIconVOrdenE(QOrdenElectronica *,QIconView *);
	QOrdenElectronica *ObtenOrdenElectronica();
	void ActualizaImporte();
private:
	QOrdenElectronica *QOElectronica;	

};
#endif 
