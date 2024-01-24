
#ifndef __IMP_PROVEEDORESCOMPRAIMPORTACION_H__
#define __IMP_PROVEEDORESCOMPRAIMPORTACION_H__
#include <UIC_H_ProveedoresCompraImportacion.h>

class zCompraImportacion;
class zEmpresa;
class QProveedoresCompraImportacion:public ProveedoresCompraImportacion
{
 Q_OBJECT
public:
	QProveedoresCompraImportacion(
	   zCompraImportacion *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QProveedoresCompraImportacion();
	zEmpresa *Proveedor();
private:
	zCompraImportacion *zCompImp;
	zEmpresa *zEmpresaReg;
private:
	void ConectaSlots();
	void IniciaVariables();
	zCompraImportacion *Compra();
	void MuestraProveedores();
private slots:
	void SlotProveedor(int,int,int,const QPoint &);
};
#endif
