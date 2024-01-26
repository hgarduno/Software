#ifndef __QTIMPREPLISTAPRECIOSCOMPRADOR_H__
#define __QTIMPREPLISTAPRECIOSCOMPRADOR_H__
#include <RepListaPreciosComprador.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zListaPrecios;
class QtImpRepListaPreciosComprador:public RepListaPreciosComprador
{
Q_OBJECT
public:
	QtImpRepListaPreciosComprador(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
        int MuestraProductosProveedor(int);

private:
	zSiscomConexion *zSisConexion;
        zSiscomRegistro *zSisRegProveedor;
	zListaPrecios *zLstPrecios;
	char *chrPtrMensaje;
private:
	void Consulta();
	void Muestra();

private slots:
	void SlotProveedor(zSiscomRegistro *pzSisRegProveedor);
	void SlotConsulta();
	void SlotImprimir();
};

#endif
