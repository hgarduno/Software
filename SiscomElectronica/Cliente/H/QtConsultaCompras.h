#ifndef __QTCONSULTACOMPRAS_H__
#define __QTCONSULTACOMPRAS_H__
#include <UIC_H_ConsultaCompras.h>


class zCompras;

class zCompra;

class QtConsultaCompras:public ConsultaCompras
{
Q_OBJECT

public:
	QtConsultaCompras(QWidget *pQWParent=0,
			  const char *pchrPtrName=0,
			  WFlags pWFlags=false);
	zCompras *Compras();
private:
	void IniciaFechas();
	void IniciaVariables();
	void ConectaSlots();
	void MuestraConsulta();

	void Consultando();
	void Muestra();
	void MuestraDetalleCompra(zCompra *);
	zCompra *Compra(int);


	virtual void Consulta();

private:
	zCompras *zComsSiscom;
private slots:
	void SlotFocoAFechaFin();
	void SlotConsulta();
	void SlotFocoAConsulta();
	void SlotDetalleCompra(int,int,int,const QPoint &);
};

#endif

