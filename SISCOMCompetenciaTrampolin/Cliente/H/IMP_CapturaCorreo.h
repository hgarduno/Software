
#ifndef __IMP_CAPTURACORREO_H__
#define __IMP_CAPTURACORREO_H__
#include <UIC_H_CapturaCorreo.h>
class SiscomDatCom;
class CQSisEntrenador;
class QCapturaCorreo:public CapturaCorreo
{
 Q_OBJECT
public:
	QCapturaCorreo(SiscomDatCom *,
	    CQSisEntrenador *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaCorreo();
private:
	SiscomDatCom *SisDatCom;
	CQSisEntrenador *CQSEPersona;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
#endif
