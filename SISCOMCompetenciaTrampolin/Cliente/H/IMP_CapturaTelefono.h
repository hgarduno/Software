
#ifndef __IMP_CAPTURATELEFONO_H__
#define __IMP_CAPTURATELEFONO_H__
#include <UIC_H_CapturaTelefono.h>
class SiscomDatCom;
class CQSisEntrenador;
class QCapturaTelefono:public CapturaTelefono
{
 Q_OBJECT
public:
	QCapturaTelefono(SiscomDatCom *,
	    CQSisEntrenador *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QCapturaTelefono();
	int SeAnexo();
private:
	SiscomDatCom *SisDatCom;
	CQSisEntrenador *CQSEPersona;
	int intSeAnexo;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotPasaFocoDescripcion();
	void SlotPasaFocoAnexar();
	void SlotCancelar();
	void SlotAnexar();
};
#endif
