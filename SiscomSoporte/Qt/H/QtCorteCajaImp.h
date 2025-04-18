#ifndef __QTCORTECAJAIMP_H__
#define __QTCORTECAJAIMP_H__

#include <QtCorteCaja.h>

class zDenominaciones;
class zEncabezadoCaja;

class QtCorteCajaImp:public QtCorteCaja
{
Q_OBJECT
public:
	QtCorteCajaImp(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void ActualizandoGui();
private:
	void ConectaSlots();
	zDenominacion *Denominacion(int,int);
	zGasto *Gasto(int,int);
	void ActualizandoDenominacion(int,int);
	void AgregandoGasto(int,int);
	void ActualizaCantidad(int,int,zDenominacion *);
	void ActualizandoImporteGasto(int,int);
	void ActualizandoPagoTarjeta(int,int);



	void ActualizaImporteGasto(int ,int,zGasto *);

	void ActualizaDineroGui(zDenominaciones *);
	void ActualizaTotalGui(zCaja *);
	void AgregaGasto(int,int);
	void ActualizaDineroEntroCaja();
	void ActualizaImporteTransferencias();
	void ActualizaTotalGastos();
	void ActualizaGui();
	void ActualizandoCambioDiaAnterior();
	void ActualizandoVentasTotales();
	void ActualizandoCalculandoCorte();
	void ActualizandoCorteTotal();

private:
	zDenominacion *zDenoD;
	
private slots:
	void SlotCaptura(int,int);

signals:
	void SignalCapturoCantidadDenominacion();
	void SignalAgregaGasto(int,int);
	void SignalActualizaImporteGasto();
	void SignalPagoTarjeta();
};

#endif
