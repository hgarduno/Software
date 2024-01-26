#ifndef __ZFOLIO_H__
#define __ZFOLIO_H__
#include <zSiscomRegistro.h>

class zFolio:public zSiscomRegistro
{
public:
	zFolio();
	zFolio(zSiscomRegistro *pzSisRegTienda,
	       zSiscomRegistro *pzSisRegTipoFolio,
	       const char *pchrPtrFolioInicio,
	       const char *pchrPtrFolioFin);
private:
	zSiscomRegistro *zSisRegTienda;
};


#endif
