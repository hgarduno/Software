
#ifndef __IMP__H__
#define __IMP__H__
#include <UIC_H_.h>
class SiscomDatCom;
class Q:public 
{
 Q_OBJECT
public:
	Q(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~Q();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
extern "C" Q *Instancia(void *,char **,void *,const char *,int);
#endif
