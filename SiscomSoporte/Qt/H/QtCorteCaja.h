#ifndef __QTCORTECAJA_H__
#define __QTCORTECAJA_H__
#include <qtable.h>

class QtImpCaja;

class zCaja;
class zEncabezadoCaja;
class zDenominacion;
class zGasto;
class zCeldaPagoTarjeta;
class zCeldaImporteGastos;

class zCajas;
class zZonaGasto;
class QtCorteCaja:public QTable
{
Q_OBJECT 
public:
	QtCorteCaja(QWidget *pQWParent=0,const char *pchrPtrName=0);
	void AgregaCaja(const char *pchrPtrCaja,int ,int);
	zCajas *Cajas();
	void FormaDenominacionesCaja(zCaja *);
	void IniciaControl(int pintFila,int pintColumna);
	zZonaGasto *ZonaGasto();
	void AgregaGasto(int,int);
	zCeldaPagoTarjeta *CeldaPagoTarjeta();
	zCeldaImporteGastos *CeldaImporteGastos();
private:
	void CeldaGris(int,int,const QString &);
	void CeldaColor(int,int,const char *,const QString &);
	void LlenaCeldasDinero(int pintFila,int pintColumna,zCaja *);
	zCaja *FormaCajaDinero(int,int,const char *);
	void FormaEncabezadosCaja(zCaja *);
	void FormandoCajaCorte(int ,int);
	void FormaRegistroDenominacion(zDenominacion *);
	void FormaRegistroEncabezadoCaja(zEncabezadoCaja *);
	void FormaRegistroGasto(const char *,zGasto *);
	void EncabezadosDinero(int,int,zCaja *);
	void EncabezadosGastos(int,int);
	void EncabezadoPagoTarjeta(int,int);
	void EncabezadoImporteGastos(int,int);
	void EncabezadoVentasEfectivo(int,int);
	void FormandoEncabezadosCorte();
	zGasto *Gasto(int,int);
	void PagoTarjeta(int,int);
	void ImporteGastos(int,int);

	void MuestraGastos(zCaja *);
private:
	zZonaGasto *zZoGasto;
	zCajas *zCajasExp;
	zCeldaPagoTarjeta *zCelPaTarjeta;
	zCeldaImporteGastos *zCelImGastos;
	int intFila;
	int intColumna;

};

#endif
