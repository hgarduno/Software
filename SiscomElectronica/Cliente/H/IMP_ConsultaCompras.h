
#ifndef __IMP_CONSULTACOMPRAS_H__
#define __IMP_CONSULTACOMPRAS_H__
#include <QtConsultaCompras.h>
class SiscomDatCom;
class QConsultaCompras:public QtConsultaCompras
{
 Q_OBJECT
public:
	QConsultaCompras(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QConsultaCompras();
	
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void Consulta();
private slots:
};
extern "C" QConsultaCompras *InstanciaConsultaCompras(void *,char **,void *,const char *,int);
#endif
