
#ifndef __IMP_VENTAS_H__
#define __IMP_VENTAS_H__
#include <UIC_H_Ventas.h>
#include <CQSisProdCotiza.h>
#include <CQSisPrecios.h>
/*
 *
 * El empleado se tomara de la fase de firma
 * para lo cual en la matriz de caracteres de argumentos
 * se copiara en este momento para pruebas 
 * se crea en la linea
 *
 */
class SiscomDatCom;
class CQSisCliente;
class CQSisProducto;
class CQSisProdCotiza;
class CQSisPrecio;
class CQSisEmpresa;
class CQSisEmpleado;
class CQSisOrden;
class CQSisPreciosTabla;
class SisPersona;

class QVentas:public Ventas
{
 Q_OBJECT
public:
	QVentas(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	QVentas(SiscomDatCom *,
	    char **,
	    CQSisOrden *,
	    CQSisLstProdCotiza *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);

	~QVentas();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisCliente *CQSCliente;
	CQSisProducto *CQSProducto;
	CQSisPrecio *CQSPrecio;
	CQSisFormaPago *CQSFPago;
	CQSisContacto *CQSContacto;
	CQSisProdCotiza *CQSPCotiza;
	CQSisLstProdCotiza CQSLPCotiza;
	CQSisLstPrecio CQSLPrecios;
	void (QVentas::*CambiaDatos[10])(CQSisProdCotiza *,int,int);
	CQSisOrden *CQSOrden;
	CQSisPreciosTabla *CQSPTabla;
	QString QSTipoPrecio;
	CQSisEmpresa *CQSEExpendio;
	CQSisEmpleado *CQSEUsuario;
private:
	void CambiaCantidad(CQSisProdCotiza *,int,int);
	void CambiaTipoPrecio(CQSisProdCotiza *,int,int);
	void OpcionInvalida(CQSisProdCotiza *,int,int);
	void ConectaSlots();
	void IniciaVariables();
	void MuestraCliente();
	void MuestraDescripcion();
	void MuestraArgumentos();
	void Cotiza();
	void CotizaOrden();
	void CotizandoOrden();
	CQSisProdCotiza *ProductoCotiza();
	void MuestraCotizacion();
	void MuestraCotizacionOrden();
	void MuestraContactos();
	void ActivaAnexarOrden();
	void Registra();
	void GeneraIdVenta();
	void IniciaOtraVenta();
	void Eliminar();
	void ActivaImprimirEliminar();
	void AsignaPerfilVenta();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotFisica(CQSisCliente *);
	void SlotMoral(CQSisCliente *);
	void SlotProducto(CQSisProducto *);
	void SlotPrecio(CQSisPrecio *);
	void SlotFormaPago(CQSisFormaPago *);
	void SlotCotiza();
	void SlotAnexar();
	void SlotContacto(CQSisContacto *);
	void SlotRegistra();
	void SlotImprime();
	void SlotEliminar();
	void SlotCambiaDato(int,int,int,const QPoint &);
	void SlotCalculaCantidad();
	void SlotCambiaPrecio(CQSisPrecio *,int,int);
	void SlotSeleccionandoProducto(CQSisProducto *);
signals:
	void SignalRealizoOperacion(QVentas *);
	void SignalTerminar(QWidget *);
};
extern "C" QVentas *InstanciaVentas(void *,char **,void *,const char *,int);
#endif
