#ifndef __QTCOMPRACONTENEDOR_H__
#define __QTCOMPRACONTENEDOR_H__

#include <UIC_H_CompraContenedor.h>
#include <zComprasImportacion.h>
class zSiscomConexion;
class zComprasImportacion;
class zCompraContenedor;

class QtCompraContenedor:public CompraContenedor
{
Q_OBJECT
public:
	QtCompraContenedor(zSiscomConexion *,
			   char **pchrPtrArgumentos,
			   QWidget *pQWParent,
			   const char *pchrPtrName,
			   WFlags pWFlags);
	void Inicia();
	void ConectaSlots();
	zCompraContenedor *Contenedor();
private:
	zSiscomConexion *zSisConexion;
 	zCompraContenedor *zComContenedor;	
	char **chrPtrArgumentos;
	QWidget *QWParent;
private:
	void IniciaVariables();
	void Capturando();
	void Captura();
	void Muestra();
private slots:
	void SlotAgregaFactura();
	void SlotCapturaFactura(int,int,int, const QPoint &);
	void SlotFocoCostoAdministrativo();
	void SlotFocoCostoDolar();
	void SlotFocoAAnexarFactura();
};

#endif
