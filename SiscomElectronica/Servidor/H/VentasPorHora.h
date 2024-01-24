#ifndef __VENTASPORHORA_H__
#define __VENTASPORHORA_H__
#include <SiscomDesarrollo2.h>
#include <ServidorGeneral.h>

typedef struct Hora
{
	float fltImporte;
	int intOrdenes;
	char chrCadenaHora[10];
}StcHora;

typedef struct DatoSemana
{
	int intDia;
	char chrArrDia[25];
	char chrArrFecha[25];
	StcHora StcHrs[25];
	LCamposSiscomPro2 *LCSiscomPro2Prim;
	LCamposSiscomPro2 *LCSiscomPro2Actual;
}StcDatoSemana;

typedef struct DatosSemana
{
	StcDatoSemana StcDatSemana[8];
	char chrArrFechaIniSemana[20];
	char chrArrFechaFinSemana[20];
	int intConInformacion;
}StcDatosSemana;

void ConsultaVentasPorHora(int,int);
int EsConsultaVentasPorHora(char **);
void FormaConsultaVentasPorHora(char **,SiscomOperacionesServidor *);
void RegistraVentasPorHora(int,int);
#endif
