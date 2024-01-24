#ifndef __IMP_CLAVESPROVEEDORES_H__
#define __IMP_CLAVESPROVEEDORES_H__
#include <UIC_H_ClavesProveedores.h>
#include <SiscomRegistros4.h>
class SiscomDatCom;
class QLineEdit;
class QManProductos;
class ProductoE;
class QClavesProveedores:public ClavesProveedores
{
 Q_OBJECT
public:
	QClavesProveedores(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QClavesProveedores();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	QManProductos *QMProductos;
	ProductoE *ProdSeleccionado;
	QLineEdit *QLECProductos;
	SiscomRegistro4 SisReg4Claves;
	char chrArrCveProducto[50];
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultandoClaves();
	void ConsultaClaves();
	void MuestraClaves();
	void SeleccionaProveedor(int);
	void CapturaClave(int);
	void ActualizaClave(int);
private slots:
	void S_Producto(ProductoE *);
	void S_Proveedor(int,int,int,const QPoint &);
};
extern "C" QClavesProveedores *InstanciaClavesProveedores(void *,char **,void *,const char *,int);
#endif
