#ifndef __MANEJOCAPACITORES_H__
#define __MANEJOCAPACITORES_H__
#include <SiscomDesarrollo2.h>
typedef struct OpManejoCapacitores
{
	const char *chrPtrOperacion;
	SiscomOperaciones2 gSiscomOperacion;
}OpManejoCapacitores;
typedef const char *(*CondicionManejoCapacitor)(SArgsSiscom *);
void ManejoCapacitores(char **pchrPtrEntrada,
		       char *pchrPtrSql);
int OperacionBusquedaCapacitor(const char *pchrPtrConsulta,
				SArgsSiscom *pSAgsSiscom,
				OpManejoCapacitores *pOpManejoCapacitores,
				SiscomOperaciones2 *pSisOperRegreso);

void ManejoCapacitoresCODIGO(SArgsSiscom *pSisArgsSiscom);
void ManejoCapacitoresVALOR(SArgsSiscom *pSisArgsSiscom);

void ArgumentosManejoCapacitores(SArgsSiscom *pSAgsSiscom);
void CopiaDatosConsultaAArgumentos(char **pchrPtrDatos,
				   SArgsSiscom *pSAgsSiscom);
void CopiaCadenaProductosCapacitor(const char *pchrPtrSql,
				   SArgsSiscom *pSAgsSiscom);

void CopiaExpendioAArgumento(const char *pchrPtrExpendio,
			     SArgsSiscom *pSAgsSiscom);
const char *CondicionUnidadesNanos(SArgsSiscom *pSAgsSiscom);
const char *CondicionUnidadesPicos(SArgsSiscom *pSAgsSiscom);
const char *CondicionUnidadesMicros(SArgsSiscom *pSAgsSiscom);

void FormaCadenaCapacitoresPicos(SArgsSiscom *pSAgsSiscom,char *pchrPtrSql);
void FormaCadenaCapacitoresNanos(SArgsSiscom *pSAgsSiscom,char *pchrPtrSql);
void FormaCadenaCapacitoresMicros(SArgsSiscom *pSAgsSiscom,char *pchrPtrSql);
CondicionManejoCapacitor ObtenCondicionManejoCapacitor(const char *pchrPtrUnidad);
int ObtenIndiceArregloAjustado(const char *pchrPtrUnidad);

void GenerandoCadenaSqlSinCodigoCapacitores(SArgsSiscom *pSAgsSiscom,
					    char *pchrPtrSql);
void FiltraResultados(SArgsSiscom *pSAgsSiscom);
int ConsultandoCodigoCapacitor(SArgsSiscom *pSAgsSiscom);
#endif
