
#ifndef __IMP_ANEXADIRECCION_H__
#define __IMP_ANEXADIRECCION_H__
#include <UIC_H_AnexaDireccion.h>
class SiscomDatCom;
class SiscomRegistro3;
class QAnexaDireccion:public AnexaDireccion
{
 Q_OBJECT
public:
	QAnexaDireccion(
	    const char *pchrPtrIdPersona,
	    SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QAnexaDireccion();
	int Opcion();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	const char *chrPtrIdPersona;
	SiscomRegistro3 *SisReg3Direccion;
	int intOpcion;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotDireccion(SiscomRegistro3 *);
	void SlotAnexa();
};
#endif
