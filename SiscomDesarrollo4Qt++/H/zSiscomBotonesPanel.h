#ifndef __ZSISCOMBOTONESPANEL_H__
#define __ZSISCOMBOTONESPANEL_H__
#include <zSiscomRegistros.h>

class zSiscomBotonPanel;
class zSiscomBotonesPanel:public zSiscomRegistros
{
public:
	zSiscomBotonesPanel();
	zSiscomBotonesPanel &operator<<(zSiscomBotonPanel *);


};

#endif
