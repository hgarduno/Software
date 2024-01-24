
#ifndef __IMP_EXPENDIOORIGEN_H__
#define __IMP_EXPENDIOORIGEN_H__
#include <QtExpendioOrigen.h>

class SiscomDatCom;
class QExpendioOrigen:public QtExpendioOrigen
{
 Q_OBJECT
public:
	QExpendioOrigen(SiscomDatCom *pzSisConexion,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QExpendioOrigen();
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
#endif
