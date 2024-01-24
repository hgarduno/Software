#ifndef __IMP_VENTASELECTRONICA_H__
#define __IMP_VENTASELECTRONICA_H__

#include <UIC_H_VentasElectronica.h>
#include <ProductosE.h>
class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QToolBox;
class QIconView;
class QIconViewItem;
class QPushButton;
class SiscomDatCom;
class QCotizaDispositivos;
class QOrdenElectronica;
class QCaja;
class ProductoE;
class Persona;
class QIconVOrdenE;
class SISCOMVentanaPrincipal;
class SiscomRegistro3;
class QVentasElectronica : public VentasElectronica
{
    Q_OBJECT

public:
    QVentasElectronica(SiscomDatCom *,
    			char **,
    		       QWidget* parent = 0,
		       const char* name = 0,
		       WFlags fl = 0 );
    ~QVentasElectronica();
    void PonIdExpendio(const char *);
private:
	SiscomDatCom *SisDatCom;
	QCotizaDispositivos *QCtzaDispositivo;
	QCaja *QCajaCentral;
	QWidget *QWParent;
	const char *chrPtrIdExpendio;
	char **chrPtrArgumentos;
	SISCOMVentanaPrincipal *SISCOMVenPrincipal;

	SiscomRegistro3 *SisReg3Escuela;

	int intModificaOrdenPorCajaCentral;
private:
	void ConectaSlots();
	void IniciaVariables();
	void EliminaOrden(QOrdenElectronica *);
	void SeleccionaExpendio();
	void CreaOrden(const char *,ProductosE ,Persona *);
	void CreaOrdenModificaPorCajaCentral(const char *,ProductosE ,Persona *);
	void QuitaOrden(QOrdenElectronica *);
	void EjecutaVenta(QIconVOrdenE *);

	void ObtenIdentificadorOrden(char *);
	void closeEvent(QCloseEvent *);

	/* Miercoles 16 de Enero del 2013
	 * Se integra el manejo de la caja central 
	 */
	int SeDebeCargarLaCajaCentral();
	void CargaCajaCentral();
private slots:
	void S_NuevaOrden();
	void S_VendeOrden(QOrdenElectronica *);
	void S_SelOrden(QIconViewItem *);
	void S_AnexarALaOrden(ProductoE *);
	void S_CotizaPractica();
	void S_JuegosSeparados(int,ProductosE &);
	void S_CancelarVenta(QOrdenElectronica *);
	void S_VenderTodo();
	void S_RegProductoSinOrden();

	void S_ModificaOrdenCajaCentral(const char *,
					ProductosE *,
					Persona *);
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QVentasElectronica *CreaInstanciaVentasElectronica(void *,
							      char **,
							      void *,
							      const char *,
							      int );
#endif 
