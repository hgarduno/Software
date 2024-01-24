#ifndef __IMP_RESPONSABLEVEHICULO_H__
#define __IMP_RESPONSABLEVEHICULO_H__
#include <UIC_H_ResponsableVehiculo.h>
class SiscomDatCom;
class CQControlNombres;
class CQSisResponsableVehiculo;
class QResponsableVehiculo:public ResponsableVehiculo
{
 Q_OBJECT
public:
	QResponsableVehiculo(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QResponsableVehiculo();
	void NombreCompleto(char *pchrPtrNombre);
	void Cargo(char *pchrPtrCargo);
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisResponsableVehiculo *CQSC3QtResponsable;
private:
	void ConectaSlots();
	void IniciaVariables();
	CQSisResponsableVehiculo *Responsable();
	int RegistraResponsable();
private slots:
	void SlotPasaFocoCargo();
	void SlotPasaFocoAceptar();
	void SlotAceptar();
};
#endif
