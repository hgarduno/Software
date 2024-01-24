#ifndef __SQLINICIAEXPENDIOS_H__
#define __SQLINICIAEXPENDIOS_H__
#include <SiscomDesarrollo2.h>


void SqlObtenMatriz(SArgsSiscom *pSAgsSiscom);
void SqlObtenFirmasMatriz(SArgsSiscom *pSAgsSiscom);
void SqlObtenTiposPersonaMatriz(SArgsSiscom *pSAgsSiscom);
void SqlObtenTipoPrecio(SArgsSiscom *pSAgsSiscom);
void SqlObtenPrecios(SArgsSiscom *pSAgsSiscom);
void SqlObtenControlesCaja(SArgsSiscom *pSAgsSiscom);
void SqlObtenEdoControlesCaja(SArgsSiscom *pSAgsSiscom);


void SqlInsertaExpendioEmpresa(SArgsSiscom *pSAgsSiscom);
void SqlInsertaExpendioExpendio(SArgsSiscom *pSAgsSiscom);
void SqlInsertaExpendioMatriz(SArgsSiscom *pSAgsSiscom);
void SqlInsertaExpendioMatrizEmpresa(SArgsSiscom *pSAgsSiscom);
void SqlInsertaExpendioMatrizExpendio(SArgsSiscom *pSAgsSiscom);
void SqlInsertaExpendioFirmas(SArgsSiscom *pSAgsSiscom);
void SqlInsertaExpendioPersonas(SArgsSiscom *pSAgsSiscom);
void SqlInsertaExpendioTiposPersona(SArgsSiscom *pSAgsSiscom);
void SqlInsertaExpendioPublicoEnGeneral(SArgsSiscom *pSAgsSiscom);
void SqlInsertaExpendioTipoPrecio(SArgsSiscom *pSAgsSiscom);
void SqlInsertaExpendioPrecios(SArgsSiscom *pSAgsSiscom);
void SqlInsertaExpendioControlesCaja(SArgsSiscom *pSAgsSiscom);
void SqlInsertaExpendioEdoControlesCaja(SArgsSiscom *pSAgsSiscom);

void SqlFamiliasMatriz(SArgsSiscom *pSAgsSiscom);
void SqlProductosMatriz(SArgsSiscom *pSAgsSiscom);
void SqlUnidadesMatriz(SArgsSiscom *pSAgsSiscom);

void ObtenDatosComunicacionMatriz(SArgsSiscom *pSAgsSiscom,
				  char *pchrPtrDirIp,
				  int *pintPtrPuerto);

void ObtenIdEmpresaMatriz(SArgsSiscom *pSAgsSiscom,
			  char *pchrPtrIdEmpresa);
void EjecutandoConsultaMatriz(const char *pchrPtrSql,
			      const char *pchrPtrArgumento,
			      SArgsSiscom *pSAgsSiscom);

void SqlFormaInsertaProductos(SArgsSiscom *pSAgsSiscom);
void SqlFormaInsertaFamilias(SArgsSiscom *pSAgsSiscom);
void SqlFormaInsertaUnidades(SArgsSiscom *pSAgsSiscom);
void SqlFormaInsertaExistencias(SArgsSiscom *pSAgsSiscom);


void SqlInsertandoProductos(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);

void SqlInsertandoUnidades(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
void SqlInsertandoFamilias(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);


void SqlGeneraInsertaExpendioEmpresa(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);


void SqlGeneraInsertaExpendioExpendio(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);

void SqlGeneraInsertaExpendioMatriz(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
	
void SqlGeneraInsertaExpendioFirmas(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);


void SqlGeneraInsertaExpendioPersonas(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);


void SqlGeneraInsertaExpendioTiposPersona(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);

void SqlGeneraInsertaExpendioPublicoEnGeneral(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);

void SqlGeneraInsertaExpendioTipoPrecio(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);

void SqlGeneraInsertaExpendioPrecios(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);



void SqlGeneraInsertaExpendioControlesCaja(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
void SqlGeneraInsertaExpendioEdoControlesCaja(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    LCamposSiscomPro2 **pLCSiscomPro2DatPrim,
			    LCamposSiscomPro2 **pLCSiscomPro2DatAct,
			    int *pintPtrNRegistros);
#endif
