
#ifndef __IMP_FAMILIAS_H__
#define __IMP_FAMILIAS_H__
#include <UIC_H_Familias.h>
#include <CQSisFamilias.h>
class SiscomDatCom;
class CQSisFamilia;
class QFamilias:public Familias
{
 Q_OBJECT
public:
	QFamilias(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QFamilias();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstFamilia CQSLFamilia;
private:
	void ConectaSlots();
	void IniciaVariables();
	CQSisFamilia *FormaFamilia();
	void RegistraFamilia();
	void ConsultaFamilias();
	void ConsultandoFamilias();
	void MuestraFamilias();
	void HabilitaAnexar();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotPasaFocoDsc();
	void SlotAnexa();
	void SlotCapturandoDsc();
	void SlotCapturandoFamilia(const QString &);
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QFamilias *InstanciaFamilias(void *,char **,void *,const char *,int);
#endif
