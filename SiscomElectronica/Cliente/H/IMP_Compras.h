#ifndef __IMP_COMPRAS_H__
#define __IMP_COMPRAS_H__

#include <UIC_H_Compras.h>
#include <ProductosE.h>
#include <EmpresasN.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QTable;
class QPushButton;
class QLabel;
class QLineEdit;
class QComboBox;
class CQControlFechaDesarrollo2;
class SiscomDatCom;
class QManProductos;
class ManTipoPrecio;
class TipoPrecio;
class QCheckTableItem;
class QManProductos;
class SiscomRegistro3;
class zSiscomConexion;
/*!
 * Para esta clase se debera de considerar el hecho <br>
 * de contar con un manejo adecuado de los precios de <br>
 * compra, ya que se debera avisar al empleado que captura<br>
 * la informacion, en el caso de que el precio de compra se <br>
 * modifique en la compra que se esta registrando, para esto <br>
 * a su ves se debera considerar el precio con IVA o sin iva que <br>
 * se captura en el registro de compras.
 *
 * Ademas se debe poner la consulta de compras por fecha, esto para <br>
 * validar la captura de las facturas por dia ya que se ha dado el caso<br>
 * de que alguna factura no se registra
 *
 */
class QCompras : public Compras
{
    Q_OBJECT

public:
    QCompras(SiscomDatCom *,
    	     char **,
	     QWidget* parent = 0,
	     const char* name = 0,
	     WFlags fl = 0 );
    ~QCompras();
private:
	void (QCompras::*ModificaDatos[10])(int);
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	ProductosE PCompras;
	EmpresasN EProveedores;
	QLineEdit *QLECProductos;
	QLineEdit *QLECProveedores;
	QLineEdit *QLECFormaPago;
	QLineEdit *QLECTipoPrecio;
	QManProductos *QMProductos;
	ProductoE *PProducto;
	ManTipoPrecio *MTipoPrecio;
	TipoPrecio *TTipoPrecio;
	int intProductoValido;
	const char *chrPtrUPCompra;
	SiscomRegistro3 *SisReg3Bodega;
	SiscomRegistro3 *SisReg3OrigenCompra;

	zSiscomConexion *zSisConexion;
protected:
	void keyPressEvent(QKeyEvent *);
private:

	void ModificaCantidad(int);
	void ModificaPrecioCompra(int);
	void ModificaCantidadATransferir(int);
	void IniciaVariables();
	void LlenaComboProductos();
	void LlenaComboProveedores();
	void ConectaSlots();
	void CambiaConMasIva(int);
	void CambiaEstadoControlIva(QCheckTableItem *,const char *);
	const char *ProductoConIva();
	void AnexaControlIvaTabla(int,const char *);

	void closeEvent(QCloseEvent *);

	void IniciaBodegas();

	int ValidaCantidadATransferir(const char **);

private slots:
	void S_PasaFocoProductos();
	void S_PasaFocoProveedor();
	void S_SeleccionoBodega(SiscomRegistro3 *pSisReg3Bodega);
	void S_PasaFocoCantidad();
	void S_PasaFocoPrecioCompra();
	void S_PasaFocoFormaPago();

	void S_SeleccionoFormaPago();
	void S_PasaFocoFechaPago();
	void S_PasaFocoAnexar();
	void S_PasaFocoPrecioVenta();
	void S_PasaFocoTipoPrecio();
	void S_PasaFocoNumFactura();
	void S_PasaFocoMasIVA();

	void S_Anexar();
	void S_Registrar();
	void S_SelProducto(ProductoE *);
	void S_NoEstaLaClave(const char *);
	void S_SelTipoPrecio(TipoPrecio *);
	void S_MasIva();
	void S_ModificarDatos(int,int,int,const QPoint &);

	void S_EliminaProductos();

	void S_PasaFocoBodegas();
	void SlotOrigenCompra(SiscomRegistro3 *pSisReg3OrigenCompra);
	void SlotFocoACantidadTransfiereZacatenco();
signals:
	void SignalTerminar(QWidget *);
};

extern "C"  QCompras *InstanciaCompras(void *,char **,void *,const char *,int);

#endif 
