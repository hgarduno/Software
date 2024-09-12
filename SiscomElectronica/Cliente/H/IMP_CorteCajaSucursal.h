
#ifndef __IMP_CORTECAJASUCURSAL_H__
#define __IMP_CORTECAJASUCURSAL_H__
#include <UIC_H_CorteCajaSucursal.h>
#include <zCorteCaja.h>
class SiscomDatCom;
class zSiscomConexion;
class zCambioCaja;
class QCorteCajaSucursal:public CorteCajaSucursal
{
 Q_OBJECT
public:
	QCorteCajaSucursal(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QCorteCajaSucursal();
	
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	zSiscomConexion *zSisConexion;
	zCorteCaja zCCaja;
private:
	void ConectaSlots();
	void IniciaVariables();
	void CalculandoCorteCaja();
	void AgregaGasto(int,int);
	void RegistrandoCambio();
	void RegistraCambio();
	void SeleccionaCambioCaja();
	void ConsultaCambioCaja(zCambioCaja *);
	void ConsultandoCambioCaja(zCambioCaja *);
	void ActualizaCambioCaja(zCambioCaja *);
	void HabilitaDesHabilitaControles(bool pbEstado);
	void HabilitaDesHabilitaRegistroCambio(bool );
	void RegistrosDia();
	void RegistrandoCorteDia();
	zCorteCaja &CorteCaja();
	void ImportesDia();
	void IniciandoFechas();
private slots:
	void SlotCapturoCantidad();
	void SlotActualizaCorteCaja();
	void SlotSeleccionaCambio();
	void SlotRegistraCorte();
	void SlotActualiza();
	void SlotFocoAActualiza();
	void SlotFocoAFFin();
};
extern "C" QCorteCajaSucursal *InstanciaCorteCajaSucursal(void *,char **,void *,const char *,int);
#endif
