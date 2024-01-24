#ifndef __QTFACTURACONTENEDOR_H__
#define __QTFACTURACONTENEDOR_H__

#include <UIC_H_FacturaContenedor.h>

class zCompraImportacion;
class zSiscomConexion;
class zSiscomRegistro;
class QtFacturaContenedor:public FacturaContenedor
{

Q_OBJECT
public:
	QtFacturaContenedor(zSiscomConexion *,
			   QWidget *pchrPtrParent=0,
			   const char *pchrPtrName=0,
			   bool pbModal=false,
			   WFlags pWFlags=false );

	zCompraImportacion *Factura();
private:
	zSiscomConexion *zSisConexion;
	zCompraImportacion *zComImportacion;
private:
	void Inicia();
	void ConectaSlots();
	void IniciaControles();
	void IniciaVariables();
private slots:
	void SlotProveedor(zSiscomRegistro *);
	void SlotFocoAceptar();
	void SlotAceptar();
	void SlotFocoNumPartidas();
	void SlotFocoDscCompra();
};

#endif
