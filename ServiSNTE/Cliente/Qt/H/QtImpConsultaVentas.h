#ifndef __QTIMPCONSULTAVENTAS_H__
#define __QTIMPCONSULTAVENTAS_H__

#include <ConsultaVentas.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zVentas;

class QtImpConsultaVentas:public ConsultaVentas
{
Q_OBJECT

public:
	QtImpConsultaVentas(QWidget *pQWParent,
			    const char *pchrPtrName);
private:
	zSiscomConexion *zSisConexion;
	zVentas *zVentasCliente;
private:
	void Conexion(zSiscomConexion *pzSisConexion);
	void IniciaVariables();
	void ConectaSlots();
	void ConsultandoVentas();
	void Consulta();
	void MuestraVentas();
	void MuestraCliente();
private slots:
	void SlotFocoAConsultaVentas();
	void SlotConsultaVentas();
};

#endif
