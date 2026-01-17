#ifndef __QTCONTABILIDADSISCOM_H__
#define __QTCONTABILIDADSISCOM_H__
#include <UIC_H_ContabilidadSiscom.h>


class QtContabilidadSiscom:public ContabilidadSiscom
{
Q_OBJECT
public:
	QtContabilidadSiscom(QWidget *,const char *,WFlags );
	~QtContabilidadSiscom();
};


#endif
