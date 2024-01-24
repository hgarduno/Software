#ifndef __IMP_VENTASPEDIDOS_H__
#define __IMP_VENTASPEDIDOS_H__

#include <UIC_H_VentasPedidos.h>
#include <Cotizaciones.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QLabel;
class QLineEdit;
class QComboBox;
class QLCDNumber;
class QPushButton;
class CSISCOMDatComunicaciones;
class CQSeleccionaProducto;
class CQ_Persona;
class ProductoCotizacion;
class CQSeleccionaTipoPrecio;
class Empresa;

class QVentasPedidos : public VentasPedidos
{
    Q_OBJECT

public:
    QVentasPedidos(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QVentasPedidos();
	const CQProductosCotizacion &ObtenProductos();
	CQ_Persona *ObtenCliente();
	CQ_Persona *ObtenUsuario();
	void EliminaProductosCotizacion();
	void AsignaProductos(CQProductosCotizacion,CQ_Persona *);
	void PonExpendio(Empresa *);
	Empresa *ObtenExpendio();
	void PonModificarDatos(int);
	void PonModificarPrecio(int);
private:
    	CSISCOMDatComunicaciones *CSisDatCom;
	CQSeleccionaProducto *CQSProducto;
	QLineEdit *QLECProductos;
	QLineEdit *QLECNmbTipoPrecio;
	QWidget *QWParent;
	CQ_Persona *CQPersona;
	CQ_Persona *CQPVendedor;
	CQProductosCotizacion CQPCotizacion;
	ProductoCotizacion *P_PCotizacion;
	CQSeleccionaTipoPrecio *CQSTPrecio;
	TipoPrecio *TTPrecio;
	Empresa *E_Expendio;
	int intModificarDatos;
	int intModificarPrecio;
private:
	void IniciaVariables();
	void CotizaProductos();
	void MuestraDatosCliente();
	void CambiaCantidad(int);
	void CambiaPrecio(int);
	void ConectaSlots();
	void QuitaPreciosCotizacion();
private slots:
	void S_SeleccionaCliente();
	void S_CotizaProducto();
	void S_PasaFocoAnexar();
	void S_PasaFocoCantidad();
	void S_AnexarProductoYCotiza();
	void S_TipoPrecio(TipoPrecio *);
	void S_PublicoEnGeneral();
	void S_EliminarProducto();
	void S_SeleccionoProducto(int,int,int,const QPoint &);
	void S_PasaFocoContactoCliente();
	void S_PasaFocoFechaEntrega();
	void S_PasaFocoTipoPrecio();
	void S_PasaFocoProducto();

};

extern "C" QVentasPedidos *InstanciaVentasPedidos(void *,void *,const char *,int );
#endif 
