
#ifndef __IMP_CAPTURADENOMINACION_H__
#define __IMP_CAPTURADENOMINACION_H__
#include <UIC_H_CapturaDenominacion.h>
class SiscomDatCom;
class QCapturaDenominacion:public CapturaDenominacion
{
 Q_OBJECT
public:
	QCapturaDenominacion(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=0,
	    WFlags pWFlags=0);
	~QCapturaDenominacion();
	int Opcion();
	void DatosDenominacion(char *,char *);
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	char chrArrDenominacion[12];
	char chrArrCantidad[12];
	int intOpcion;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotAceptar();
	void SlotCancelar();
	void SlotPasaFocoCantidad();
	void SlotPasaFocoAceptar();
};
#endif
