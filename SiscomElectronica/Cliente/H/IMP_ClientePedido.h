
#ifndef __IMP_CLIENTEPEDIDO_H__
#define __IMP_CLIENTEPEDIDO_H__
#include <QtClientePedido.h>
#include <zDirecciones.h>

class QCotizaciones;
class zSiscomConexion;
class zSiscomRegistro;

class zClienteSiscom;
class zDireccion;

/* Viernes 16 de Diciembre del 2016 
 * Se debe considerar que un cliente podra tener varias direcciones 
 * de entrega
 *
 */
class zTelefono;
class zSiscomRegistros;

class zOrdenVenta;
class zCobertura;
class zClientesSiscom;


class QClientePedido:public QtClientePedido
{
 Q_OBJECT
public:
	QClientePedido(zOrdenVenta *,
			char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QClientePedido();
	const char *IdTipoOrden();
	int EntregaEn();
	zOrdenVenta *Orden();
	int SeVendeUnaOrden();

	void EntregaEn(int);
	int Aceptar();
private:
	char **chrPtrArgumentos;
	/* Ecatepec a 21/dic/2023 
	 *  Se agrego la clase zClientesSiscom ...
	zSiscomRegistros *zSisRegsClientes;
	*/
	zClientesSiscom *zClisSiscom;
	/* CDMX Sabado 25 Julio 2020
	 * Con la integracion de la funcionalidad para seleccionar una orden 
	 * para agregar al pedido, se definen varios valores para intAceptar
	 *
	 *  intAceptar = 1 Un pedido normal desde cero
	 *  intAceptar = 2 Se selecciono una orden, pedido, o Cotizacion 
	 */

	zDireccion *zDirEscuela;

	int intEntregaEn; /*   1 Entrega en tienda
			   *   2 Entrega en un punto de entrega Siscom
			   *   3 Enviar a direccion cliente
			   */

	QCotizaciones *QCotsSelecciona;
	/* CDMX a 25 de Julio 2020 
	 * Se integra la posibilidad de seleccionar una orden, cotizacion o 
	 * pedido para que se seleccione y se agregue al pedido 
	 */
	 
	 zOrdenVenta *zOrdVenta;
	 zCobertura *zCobPaqueteria;
	 zDireccion *zDirEnvio;

private:
	void ConectaSlots();
	void IniciaVariables();
	int ValidandoTelefono();
	int RegistrandoPersonales();
	int RegistrandoCelular();
	int RegistrandoDireccion();

	zClienteSiscom *ClienteSiscom();
	zDireccion *FormaDireccion();
	

	int RegistraCliente();
	int RegistraCelular();
	int RegistraDireccion();

	int MuestraClientesSimilares();
	void MuestraCliente();
	void FocoADondeFalta();
	void ObtenDireccionEscuela();
	void AsignandoDireccion();
	void MuestraGenerales();
	void MuestraEscuela();


	int HayClientesSimilares();

	int BuscandoAElCliente();
	zClienteSiscom *UnClienteEncontrado();


	int CoberturaJTExpress(const char *pchrPtrCP);

	void SiHayCoberturaPaqueteria();
	void Direccion(int);
	void PuntoEntregaDomicilioCliente();
	zDireccion *DireccionEnvio();
	

private slots:
	void SlotRegistraPersonales();
	void SlotRegistraCelular();
	void SlotAceptar();
	void SlotCoberturaJTExpress();
	void SlotRegistraDireccion();
	void SlotDireccionEnvio(int,int,int,const QPoint &);
};
#endif
