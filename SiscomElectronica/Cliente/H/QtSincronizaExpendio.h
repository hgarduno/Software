#ifndef __QTSINCRONIZAEXPENDIO_H__
#define __QTSINCRONIZAEXPENDIO_H__

#include <UIC_H_SincronizaExpendio.h>

class SiscomDatCom;
class zEmpresa;
class zSiscomConexion;
class zListaExpendios;

class SiscomRegistro3;
class QtSincronizaExpendio:public SincronizaExpendio
{

Q_OBJECT
public:
	QtSincronizaExpendio(SiscomDatCom *,
				char **,
				QWidget *,
				const char *pchrPtrName=0,
				WFlags pWFlags=0);
	void IniciaVariables();
	void ConectaSlots();
	zEmpresa *Expendio();
	zEmpresa *ExpendioO();
	void Expendio(zEmpresa *);
	zListaExpendios *Expendios();
private:
	SiscomDatCom *SisDatCom;
        char **chrPtrArgumentos;
	zEmpresa *zEExpendio;
	zEmpresa *zEExpendioO;
	zSiscomConexion *zSisConexion;
	zListaExpendios *zLstExpendios;
private:
	void IniciaExpendios();
	void IniciandoLasVariables();
	void ExpendioOrigen();
	void ExpendioO(zEmpresa *);


	virtual void SincronizaProductos(zListaExpendios *);
	virtual void SincronizaPrecios();


private slots:
	void SlotSincronizaProductos();
	void SlotExpendio(SiscomRegistro3 *);
	void SlotSincronizaPrecios();
};

#endif
				
