#ifndef __ZCONEXIONEXPENDIO_H__
#define __ZCONEXIONEXPENDIO_H__
#include <zConexionExpendio.h>
#include <zSiscomConexion.h>
#include <zExpendio.h>

class zConexionExpendio:public zSiscomConexion,
			public zExpendio
{
public:
	zConexionExpendio(zExpendio *);
			   

};





#endif

