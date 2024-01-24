
#ifndef __IMP_EXPENDIOSSE_H__
#define __IMP_EXPENDIOSSE_H__
#include <UIC_H_ExpendiosSE.h>

class QExpendiosSE:public ExpendiosSE
{
 Q_OBJECT
public:
	QExpendiosSE(QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    bool pbModal=false,
	    WFlags pWFlags=0);
	~QExpendiosSE();
private:
private:
	void ConectaSlots();
	void IniciaVariables();
private slots:
};
#endif
