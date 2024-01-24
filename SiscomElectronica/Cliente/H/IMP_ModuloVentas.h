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
	

private slots:
	void SlotNoSePuedeVender(zProductoCotizar *);
signals:
	void SignalActualizaMenu(const QString &);
};

extern "C" QModuloVentas *InstanciaModuloVentas(void *,char **,void *,const char *,int);

#endif
