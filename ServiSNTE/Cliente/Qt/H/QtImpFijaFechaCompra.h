#ifndef __QTIMPFIJAFECHACOMPRA_H__
#define __QTIMPFIJAFECHACOMPRA_H__
#include <cstddef>
#include <FijaFechaCompra.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;

class QtImpFijaFechaCompra:public FijaFechaCompra
{
Q_OBJECT
public:
	QtImpFijaFechaCompra(QWidget *pQWParent,
			    const char *pchrPtrName);
	
private:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaControles();
    	void IniciaVariables();
	void FijandoFechaCompra();
private:
	zSiscomRegistros *zSisRegsDirecciones;
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisProveedor;
private slots:
	void SlotProveedor(zSiscomRegistro *);
	void SlotRegistraFecha();
	void SlotFocoARegistraFecha();
};

#endif
