#ifndef __SQLTIPOPRECIO_H__
#define __SQLTIPOPRECIO_H__
#include <SiscomDesarrollo2.h>

void SQLTipoPrecio(SArgsSiscom *pSAgsSiscom);
void SQLGeneraRegistroTipoPrecio(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);
void SQLTipoPrecioRegistrados(SArgsSiscom *);

void SQLAnexaTipoPrecioServicios(SArgsSiscom *);
void SQLAnexaTipoPrecioServiciosMedico(SArgsSiscom *);

#endif
