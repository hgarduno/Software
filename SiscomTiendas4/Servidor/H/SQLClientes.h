#ifndef __SQLCLIENTES_H__
#define __SQLCLIENTES_H__
#include <SiscomDesarrollo2.h>

void SqlRegistraTipoPersona(SArgsSiscom *pSAgsSiscom);
void SqlGeneraTipoPersona(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros);
void SqlRegistraClienteFisica(SArgsSiscom *pSAgsSiscom);
void SqlGeneraClienteFisica(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros);

void SqlRegistraTipoPersonaPropVehiculo(SArgsSiscom *pSAgsSiscom);
void SqlGeneraTipoPersonaPropVehiculo(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros);

void SqlRegistraTipoPersonaRespVehiculo(SArgsSiscom *pSAgsSiscom);
void SqlGeneraTipoPersonaRespVehiculo(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros);

void SqlRegistraCargoRespVehiculo(SArgsSiscom *pSAgsSiscom);
void SqlGeneraCargoRespVehiculo(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros);

void SqlRegistraDirecciones2(SArgsSiscom *pSAgsSiscom);
void SqlGeneraDirecciones2(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			 LCamposSiscomPro2 **pLCSiscomPro2Prim,
			 LCamposSiscomPro2 **pLCSiscomPro2Act,
			 int *pintPtrNRegistros);
void SQLClientesRegistrados(SArgsSiscom *);
void SqlDireccionesCliente(SArgsSiscom *pSAgsSiscom);
void SqlDireccionesCliente2(SArgsSiscom *pSAgsSiscom);
void SqlNombreCliente(SArgsSiscom *pSAgsSiscom);
#endif
