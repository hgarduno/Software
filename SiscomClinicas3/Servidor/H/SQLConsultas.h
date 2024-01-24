#ifndef __SQLCONSULTAS_H__
#define __SQLCONSULTAS_H__
#include <SiscomDesarrollo2.h>

void SQLActualizaReceta(SArgsSiscom *pSAgsSiscom);

void SQLGeneraActualizaReceta(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);

void SQLRegistraConsulta(SArgsSiscom *pSAgsSiscom);

void SQLGeneraRegistroConsultas(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);

void SQLCambiaEdoConsulta(SArgsSiscom *pSAgsSiscom);

void SQLGeneraCambioEdoConsulta(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);



void SQLServiciosProductosConsulta(SArgsSiscom *pSAgsSiscom);

void SQLGeneraServiciosProductosConsulta(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);



void SQLRegistraReceta(SArgsSiscom *pSAgsSiscom);

void SQLGeneraRegistraReceta(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);

void SQLEdoConsultaTermina(SArgsSiscom *pSAgsSiscom);

void SQLGeneraEdoConsultaTermina(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *);
void SQLTerminaConsulta(SArgsSiscom *pSAgsSiscom);

void SQLGeneraTerminaConsulta(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros);

void SQLConsultasPendientesMedico(SArgsSiscom *pSAgsSiscom);
void SQLConsultasRegistradasHoyEnEspera(SArgsSiscom *pSAgsSiscom);
void SQLConsultasMedicoHoy(SArgsSiscom *pSAgsSiscom);
void SQLConsultasActualMedico(SArgsSiscom *pSAgsSiscom);
void SQLRecetaConsulta(SArgsSiscom *pSAgsSiscom);


#endif
