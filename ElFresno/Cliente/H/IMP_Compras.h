#ifndef __IMP_COMPRAS_H__
#define __IMP_COMPRAS_H__

#include <UIC_H_Compras.h>
#include <Cotizaciones.h>
#include <Compras.h>

class QVBoxLayout;
class QHBoxLayout;
class QGridLayout;
class QSpacerItem;
class QLabel;
class QComboBox;
class QLineEdit;
class QPushButton;
class QTable;
class CSISCOMDatComunicaciones;
class Empresa;
class CQSeleccionaProducto;
class CQSeleccionaProveedor;
class Compra;

class QCompras : public Compras
{
    Q_OBJECT

public:
    QCompras(CSISCOMDatComunicaciones *, QWidget* parent = 0, const char* name = 0, WFlags fl = 0 );
    ~QCompras();
	void PonExpendio(Empresa *);
private:
    	CSISCOMDatComunicaciones *CSisDatCom;
	Empresa *E_Expendio;
	Empresa *E_Proveedor;
	CQSeleccionaProducto *CQSProducto;
	CQSeleccionaProveedor *CQSProveedor;
	QLineEdit *QLECProductos;
	QLineEdit *QLECRazonSocial;
	QLineEdit *QLECFormaPago;
	Producto *PProducto;
	Compra *C_Compra;
	CQCompras CQCompra;

	FILE *FleRegCompras;
	
private:
	void MuestraNombreExpendio();
	void ConectaSlots();
	void IniciaVariables();
	void AbreArchivoCompras();
	void RegistraCompraEnArchivo();
private slots:
	void S_SeleccionoFormaPago(int);
	void S_SeleccionoProveedor(Empresa *);
	void S_SeleccionoProducto(Producto *);
	void S_PasaFocoProducto();
	void S_PasaFocoFormaPago();
	void S_PasaFocoNumFactura();
	void S_PasaFocoFechaPago();
	void S_PasaFocoPrecioCompra();
	void S_Anexar();
	void S_RegistrarCompra();
	void S_EliminaCompra();
	void S_SeleccionoCompra(int,int,int,const QPoint &);
};
extern "C" QCompras *InstanciaCompras(void *,void *,const char *,int);
#endif 
