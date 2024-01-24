#ifndef __IMP_EDOREGGIMNASIO_H__
#define __IMP_EDOREGGIMNASIO_H__
#include <UIC_H_EdoRegGimnasio.h>
class SiscomDatCom;
class CQSisLstGimnasio;
class QEdoRegGimnasio:public EdoRegGimnasio
{
 Q_OBJECT
public:
	QEdoRegGimnasio(const char *,
			CQSisLstGimnasio *,
			QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=true,
	    WFlags pWFlags=0);
	~QEdoRegGimnasio();
	int ObtenSiLoRegistro();
private:
	CQSisLstGimnasio *CQSLstGimnasio;
	int intSiLoRegistro;
	const char *chrPtrGimnasio;
private:
	void ConectaSlots();
	void IniciaVariables();
	void MuestraGimnasios();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotCancelaRegistro();
	void SlotRegistra();
};
#endif
