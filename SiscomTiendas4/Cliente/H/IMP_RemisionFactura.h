
#ifndef __IMP_REMISIONFACTURA_H__
#define __IMP_REMISIONFACTURA_H__
#include <UIC_H_RemisionFactura.h>
class SiscomDatCom;
class QRemisionFactura:public RemisionFactura
{
 Q_OBJECT
public:
	QRemisionFactura(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QRemisionFactura();
	int Opcion();
	void NoRemFactura(char *pchrPtrNoRemFactura);
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	int intOpcion;
	char chrArrNoRemFactura[28];
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotPasaFocoAceptar();
	void SlotAceptar();
	void SlotCancelar();
};
#endif
