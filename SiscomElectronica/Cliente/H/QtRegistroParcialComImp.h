#ifndef __QTREGISTROPARCIALCOMIMP_H__
#define __QTREGISTROPARCIALCOMIMP_H__
#include <UIC_H_RegistroParcialComImp.h>
#include <zProductosImportados.h>
class zCompraImportacion;
class zProductoImportado;

class QtRegistroParcialComImp:public RegistroParcialComImp
{
Q_OBJECT
public:
	QtRegistroParcialComImp(QWidget *,const char *, WFlags );
	void CompraImportacion(zCompraImportacion *);
	zCompraImportacion *CompraImportacion();
	void AgregaProducto(zProductoImportado *);
	void AgregandoProducto(zProductoImportado *);
	void MuestraProductos();
	const zProductosImportados &Productos();
	void ConectaSlots();

private:
	zCompraImportacion *zComImportacion;
	zProductosImportados zProdsImportados;
public slots:
	virtual void SlotRegistroProductos();
};

#endif
