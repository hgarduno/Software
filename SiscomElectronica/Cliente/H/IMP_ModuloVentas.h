#ifndef __MODULOVENTAS_H__
#define __MODULOVENTAS_H__
#include <IMP_ManejadorOrden.h>
class zProductoCotizar;
class zClienteSiscom;

class QModuloVentas:public QManejadorOrden
{
Q_OBJECT
public:
	QModuloVentas(SiscomDatCom *pzSisDatCom,
		      char **pchrPtrArgumentos,
		      QWidget *pQWParent,
		      const char *pchrPtrName,
		      WFlags pWFlags);

private:
	zProductoCotizar *zProdCotNoAlcanza;
	zSiscomRegistros *zSisRegsProdEnApartados;
	int intVendiendo;
	/*  Tepotzotlan Mexico 
	 *  1 de mayo del 2024 
	 *
	 *  Con la integracion de la forma de pago, resulta 
	 *  que al cerrar o hacer registro de donacion, area de diseno
	 *  tambien se pone la ventanita para captuar la forma de pago
	 *  lo que esta mal :(
	 *
	 */

	int intPorqueSeRegistra;
private:
	void ConectaSlots();
	void Vendiendo();
	void TextoEncabezado();
	void TextoBotonRegistro(const char *pchrPtrTexto);
	void TextoBotonNuevaOrden(const char *pchrPtrTexto);
	void IniciaVariables();
	void NuevaOrden();
	void Registrar();
	void Imprimir();
	void ImprimirPdf();
	void RegistraOrden();
	void MuestraProductoEnApartados(zProductoCotizar *);
	void closeEvent(QCloseEvent *);
	const char *TextoTipoOrdenBoton();
	void OrdenRapidaEscuelaPrincipal();
	void OrdenRapidaOtro();
	void PantallaMasUsada();
	zClienteSiscom *OrdenOtro();
	void VendiendoAlCliente(zClienteSiscom *);
	void CopiandoPortapapelesTelemarketing();
	void CopiandoPrecioProductoPortapapeles();
	void AgregaLineaProducto(zProductoCotizar *,char *pchrPtrLinea);
	void CadenaConNegritas(const char *,char *);
	void RegistroRapidoCotizacion();
	void RegistroRapidoCotizacionEnvio();
	void CapturandoDescripcion(const char *);
	void RegistrandoRapidoCotizacion(const char *);
	void EliminaBotonesQueNoUso();

	int PorqueSeRegistra();

private slots:
	void SlotNoSePuedeVender(zProductoCotizar *);
signals:
	void SignalActualizaMenu(const QString &);
};

extern "C" QModuloVentas *InstanciaModuloVentas(void *,char **,void *,const char *,int);

#endif
