#ifndef __QTEXISTENCIAS_H__
#define __QTEXISTENCIAS_H__
#include <UIC_H_Existencias.h>


class zPedidoExistenciaM;

class QtExistencias:public Existencias
{
Q_OBJECT
public:
	QtExistencias(QWidget *,const char *,WFlags );
	~QtExistencias();
	zPedidoExistenciaM *PedidoExistenciaM();
private:
	  zPedidoExistenciaM *zPedidoEm;
private:
	void MuestraProductosMinimos();
public:
	virtual void PedidoExistenciaMinima();
	virtual void RegistraPedidoExistenciaMinima();
	void ConectaSlots();
	void IniciaVariables();
	void IniciaPedidoExistenciaMinima();
private slots:
	void SlotPedidoEM();
	void SlotCapturoPorcentaje();
	void SlotRegistraPedidoEm();
};

#endif
