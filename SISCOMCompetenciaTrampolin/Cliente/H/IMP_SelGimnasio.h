
#ifndef __IMP_SELGIMNASIO_H__
#define __IMP_SELGIMNASIO_H__
#include <UIC_H_SelGimnasio.h>
class SiscomDatCom;
class CQSisGimnasio;
class QSelGimnasio:public SelGimnasio
{
 Q_OBJECT
public:
	QSelGimnasio(SiscomDatCom *,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=true,
	    WFlags pWFlags=0);
	~QSelGimnasio();
	CQSisGimnasio *ObtenGimnasio();
private:
	SiscomDatCom *SisDatCom;
	CQSisGimnasio *CQSGimnasio;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotAceptar();
	void SlotCancelar();
	void SlotGimnasio(CQSisGimnasio *);
};
#endif
