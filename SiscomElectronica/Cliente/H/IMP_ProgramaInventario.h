
#ifndef __IMP_PROGRAMAINVENTARIO_H__
#define __IMP_PROGRAMAINVENTARIO_H__
#include <UIC_H_ProgramaInventario.h>
class SiscomDatCom;
class QProgramaInventario:public ProgramaInventario
{
 Q_OBJECT
public:
	QProgramaInventario(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QProgramaInventario();
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
extern "C" QProgramaInventario *InstanciaProgramaInventario(void *,char **,void *,const char *,int);
#endif
