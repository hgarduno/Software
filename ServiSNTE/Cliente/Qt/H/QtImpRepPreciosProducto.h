#ifndef __QTIMPREPPRECIOSPRODUCTO_H__
#define __QTIMPREPPRECIOSPORDUCTO_H__
#include <RepPreciosProducto.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zListaPrecios;
class QtImpRepPreciosProducto:public RepPreciosProducto
{
Q_OBJECT
public:
	QtImpRepPreciosProducto(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	 void Conexion(zSiscomConexion *pzSisConexion);
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegTienda;
	zSiscomRegistro *zSisRegProveedor;
	zSiscomRegistro *zSisRegDepartamento;
	zListaPrecios *zLstPrecios;
	char *chrPtrMensaje;
private:
	void Consultando();
	void Consulta();
	void Muestra();
	int MuestraProductosProveedor(int);
	 int SeAgregaALaLista(zListaPrecios *pzLstPrecios);
private slots:
	void SlotTienda(zSiscomRegistro *pzSisRegTienda);	
	void SlotDepartamento(zSiscomRegistro *pzSisRegDepartamento);
	void SlotProveedor(zSiscomRegistro *pzSisRegProveedor);	
	void SlotConsulta();
	void SlotImprime();
};

#endif
