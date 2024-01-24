
#ifndef __IMP_CAPTURADIRECCION_H__
#define __IMP_CAPTURADIRECCION_H__
#include <UIC_H_CapturaDireccion.h>
class SiscomDatCom;
class CQSisEntrenador;
class QCapturaDireccion:public CapturaDireccion
{
 Q_OBJECT
public:
	QCapturaDireccion(SiscomDatCom *,
	    CQSisEntrenador *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaDireccion();
private:
	SiscomDatCom *SisDatCom;
	CQSisEntrenador *CQSEPersona;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
#endif
