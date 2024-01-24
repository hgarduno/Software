#ifndef __SQLCLIENTES_H__
#define __SQLCLIENTES_H__
#include <SiscomDesarrollo2.h>

void SqlClientes(SArgsSiscom *pSAgsSiscom);
void SqlDatosGeneralesCliente(SArgsSiscom *pSAgsSiscom);

void SqlInsertaDireccionCliente(SArgsSiscom *);
void SqlInsertaDireccionClienteMoral(SArgsSiscom *);
void SqlGeneraInsertaDireccionCliente(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);

void SqlGeneraInsertaDireccionClienteMoral(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);
void SqlActualizaRFC(SArgsSiscom *);
void SqlGeneraActualizaRFC(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);

void SqlInsertaTelefono(SArgsSiscom *);
void SqlGeneraInsertaTelefono(LCamposSiscomPro2 *pLCSiscomPro2,
                                 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros);




#endif
