#ifndef __QTIMPREPORTECOMPRAS_H__
#define __QTIMPREPORTECOMPRAS_H__
#include <ReporteCompras.h>

class zSiscomConexion;
class zSiscomRegistro;
class zSiscomRegistros;
class zCosto;
class QtImpReporteCompras:public ReporteCompras
{
Q_OBJECT
public:
	QtImpReporteCompras(QWidget *pQWParent=0,
				const char *pchrPtrName=0);
private:
	void IniciaVariables();
	void ConectaSlots();
	void Conexion(zSiscomConexion *pzSisConexion);
	void Consultando();
	void Consulta();
	void Muestra();
	void ConsultandoDetalleCompra(zSiscomRegistro *pzSisRegCompra);
	zSiscomRegistros *ConsultaDetalleCompra(zSiscomRegistro *pzSisRegCompra);
	void MostrandoDetalleCompra();
	void CalculandoCosto(zCosto *);
	zCosto *Costo(const QString &,const QString &);
	void RegistrandoPrecioCompra(zSiscomRegistro *,zCosto *);
private:
	zSiscomConexion *zSisConexion;
	zSiscomRegistros *zSisRegsCompras;
	zSiscomRegistros *zSisRegsProductos;
	zSiscomRegistro *zSisRegCompra;
	int intNumeroCompra;
private slots:
	void SlotRangoFecha();
	void SlotSeleccionaCompra(int pintCompra,
				  int pintColumna,
				  int pintBoton,
				  const QPoint &pQPPosicion);
	void SlotSeleccionaProducto(int,int,int,const QPoint &);
	void SlotSeleccionaProducto(int,int);
};

#endif
