#ifndef __ZCLIENTESSISCOM_H__
#define __ZCLIENTESSISCOM_H__


#include <zSiscomRegistros.h>


class zClienteSiscom;
class zClientesSiscom:public zSiscomRegistros
{
public:
	zClientesSiscom(zSiscomRegistros *pzSisRegsSiscom);
	zClienteSiscom *Cliente(int);
private:
	void Clientes(zSiscomRegistros *pzSisRegsSiscom);
	zClienteSiscom *Cliente(zSiscomRegistro *);
};


#endif
