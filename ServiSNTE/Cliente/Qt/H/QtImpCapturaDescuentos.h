#ifndef __QTIMPREPCAPTURADESCUENTOS_H__
#define __QTIMPREPCAPTURADESCUENTOS_H__
#include <CapturaDescuentos.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zDescuento;
class QtImpCapturaDescuentos:public CapturaDescuentos
{
Q_OBJECT
public:
	QtImpCapturaDescuentos(QWidget *pQWParent=0,
				const char *pchrPtrName=0,
				bool pbModal=false,
				WFlags pWFlags=false);
	zDescuento *Descuento();
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;
private:
private slots:
	void SlotFocoADescuento2();
	void SlotFocoADescuento3();
	void SlotFocoADescuento4();
	void SlotFocoAAceptar();
	void SlotAceptar();
	
};

#endif
