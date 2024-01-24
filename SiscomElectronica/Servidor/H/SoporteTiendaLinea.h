#ifndef __SOPORTETIENDALINEA_H__
#define __SOPORTETIENDALINEA_H__
#include <SiscomDesarrollo4/H/SiscomOperaciones.h>

void LogOrdenTiendaLinea(const char *pchrPtrFile,
			 const char *pchrPtrFuncion,
			 int pintLinea,
			 SiscomRegistroProL *pSisRegProLPtrDatoTL);


#define LOGOrdenTiendaLinea(pSisRegProLPtrDatoTL) \
	LogOrdenTiendaLinea(__FILE__,__FUNCTION__,__LINE__,pSisRegProLPtrDatoTL)
#endif
