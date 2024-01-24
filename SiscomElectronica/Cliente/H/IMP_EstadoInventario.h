
#ifndef __IMP_ESTADOINVENTARIO_H__
#define __IMP_ESTADOINVENTARIO_H__
#include <UIC_H_EstadoInventario.h>
class SiscomDatCom;
class QEstadoInventario:public EstadoInventario
{
 Q_OBJECT
public:
	QEstadoInventario(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QEstadoInventario();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
	void closeEvent(QCloseEvent *);
private slots:
signals:
	void SignalTerminar(QWidget *);
};
extern "C" QEstadoInventario *InstanciaEstadoInventario(void *,char **,void *,const char *,int);
#endif
