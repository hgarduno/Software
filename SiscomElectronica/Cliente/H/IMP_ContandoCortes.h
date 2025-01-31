
#ifndef __IMP_CONTANDOCORTES_H__
#define __IMP_CONTANDOCORTES_H__
#include <QtContandoCortes.h>
class SiscomDatCom;
class QContandoCortes:public QtContandoCortes
{
 Q_OBJECT
public:
	QContandoCortes(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QContandoCortes();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
extern "C" QContandoCortes *InstanciaContandoCortes(void *,char **,void *,const char *,int);
#endif
