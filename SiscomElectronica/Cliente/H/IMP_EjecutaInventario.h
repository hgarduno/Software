
#ifndef __IMP_EJECUTAINVENTARIO_H__
#define __IMP_EJECUTAINVENTARIO_H__
#include <UIC_H_EjecutaInventario.h>
class SiscomDatCom;
class QEjecutaInventario:public EjecutaInventario
{
 Q_OBJECT
public:
	QEjecutaInventario(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QEjecutaInventario();
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
extern "C" QEjecutaInventario *InstanciaEjecutaInventario(void *,char **,void *,const char *,int);
#endif
