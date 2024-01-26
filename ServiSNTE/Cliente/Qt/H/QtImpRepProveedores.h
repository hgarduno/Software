#ifndef __QTIMPREPPROVEEDORES_H__
#define __QTIMPREPPROVEEDORES_H__
#include <RepProveedores.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zProveedores;
class QtImpRepProveedores:public RepProveedores
{
Q_OBJECT
public:
	QtImpRepProveedores(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
	void Consultando();
	void Consulta();
	void Muestra();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegProveedor;
private:
	zProveedores *zPrvDatos;
private slots:
	void SlotConsultar();
	void SlotImprimir();
	
};

#endif
