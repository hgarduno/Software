#ifndef __QTCONTANDOCORTES_H__
#define __QTCONTANDOCORTES_H__

#include <UIC_H_ContandoCortes.h>

class QtContandoCortes:public ContandoCortes
{
Q_OBJECT
public:
	QtContandoCortes(QWidget *pQWParent=0,const char *pchrPtrName=0,WFlags pWFlags=false);


};

#endif
