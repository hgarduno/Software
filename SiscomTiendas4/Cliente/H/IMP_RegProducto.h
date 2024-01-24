
#ifndef __IMP_REGPRODUCTO_H__
#define __IMP_REGPRODUCTO_H__
#include <UIC_H_RegProducto.h>
class SiscomDatCom;
class CQSisFamilia;
class CQSisProducto;
class QRegProducto:public RegProducto
{
 Q_OBJECT
public:
	QRegProducto(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QRegProducto();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisFamilia *CQSFamilia;
private:
	void ConectaSlots();
	void IniciaVariables();
	CQSisProducto *GeneraProducto();
	void RegistraProducto();
	void closeEvent(QCloseEvent *);
private slots:
	void SlotFamilia(CQSisFamilia *);
	void SlotPasaFocoDescripcion();
	void SlotRegistrar();
	void SlotCambiandoFamilia();
	void SlotCapturandoDsc();
	void SlotCambiandoClave(const QString &);
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QRegProducto *InstanciaRegProducto(void *,char **,void *,const char *,int);
#endif
