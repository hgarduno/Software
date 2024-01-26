#ifndef __QTIMPREPORTEVENTAS_H__
#define __QTIMPREPORTEVENTAS_H__
#include <cstddef>
#include <ReporteVentas.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class QtImpReporteVentas:public ReporteVentas
{
Q_OBJECT
public:
	QtImpReporteVentas(QWidget *pQWParent,
			  const char *pchrPtrName);

public:
	void Conexion(zSiscomConexion *pzSiscomConexion);
	void ConectaSlots();
	void IniciaControles();
	void IniciaVariables();
	void Consulta();
	void Consultando();
	void Muestra();
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistro *zSisRegTipoVenta;
	zSiscomRegistro *zSisRegTienda;
	zSiscomRegistros *zSisRegsRepVentas;
private slots:

	void SlotFocoATiendas();
	void SlotTipoVenta(zSiscomRegistro *);
	void SlotTienda(zSiscomRegistro *);
	void SlotConsulta();

};



#endif
