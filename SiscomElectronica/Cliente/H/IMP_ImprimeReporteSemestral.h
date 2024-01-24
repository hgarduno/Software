#ifndef __IMP_IMPRIMEREPORTESEMESTRAL_H__
#define __IMP_IMPRIMEREPORTESEMESTRAL_H__
#include <UIC_H_ImprimeReporteSemestral.h>
class QPushButton;
class QtSisImprime;
class QtSisImprimeTabla;
class SiscomRegistro3Lst;
class QImprimeReporteSemestral:public ImprimeReporteSemestral
{
 Q_OBJECT
public:
	QImprimeReporteSemestral(SiscomRegistro3Lst *pSisReg3LstDatos,
				 QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QImprimeReporteSemestral();
private:
	QGridLayout *QHBRegilla;
	QWidget *QWParent;
	QPushButton *QPBImprime;
	QtSisImprime *QtSisIProtocolo;	
	QtSisImprimeTabla *QtSisImpRepSemestral;
	SiscomRegistro3Lst *SisReg3LstDatos;
	char **chrPtrCampos;
	char **chrPtrTitulosColumnas;
	int intCaracteresColumna[100];
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
	void SlotImprime();
};
#endif
