
#ifndef __IMP_BALANCEFINANCIERO_H__
#define __IMP_BALANCEFINANCIERO_H__
#include <UIC_H_BalanceFinanciero.h>
class SiscomDatCom;
class zSiscomConexion;
class zSiscomRegistro;
class QBalanceFinanciero:public BalanceFinanciero
{
 Q_OBJECT
public:
	QBalanceFinanciero(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QBalanceFinanciero();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	char chrArrBalanceFinanciero[2048];
private:
	void ConectaSlots();
	void IniciaVariables();
	void CargaArchivoHtml();
private slots:
	void SlotCargaArchivoHtml();
};
extern "C" QBalanceFinanciero *InstanciaBalanceFinanciero(void *,char **,void *,const char *,int);
#endif
