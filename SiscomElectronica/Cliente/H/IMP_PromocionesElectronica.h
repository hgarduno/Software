#ifndef __IMP_PROMOCIONESELECTRONICA_H__
#define __IMP_PROMOCIONESELECTRONICA_H__
#include <UIC_H_PromocionesElectronica.h>
class SiscomDatCom;
class CQSisPromocion;
class SiscomRegistro3Lst;
class QPromocionesElectronica:public PromocionesElectronica
{
 Q_OBJECT
public:
	QPromocionesElectronica(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QPromocionesElectronica();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void RegistraPromocion();
	CQSisPromocion *Promocion();
	void MuestraEdoRegistro(SiscomRegistro3Lst *);
private slots:
	void SlotPasaFocoPuntosSiscom();
	void SlotPasaFocoFechaIni();
	void SlotPasaFocoFechaFin();
	void SlotPasaFocoDescripcion();

	void SlotRegistra();
	void SlotActualiza();
};
extern "C" QPromocionesElectronica *InstanciaPromocionesElectronica(void *,char **,void *,const char *,int);
#endif
