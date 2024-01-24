#include <Empleados.h>
#include <ComunElectronica2.h>
#include <stdlib.h>
#include <SqlEmpleados.h>

SiscomOperaciones2 *OPEmpleados()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*120);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlEmpleados,lSOpOperaciones);
return lSOpOperaciones;
}

SiscomOperaciones2 *OpCambiaSueldo()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*120);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosSueldos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaSueldo,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlActualizaSueldo,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EnviaSueldos,lSOpOperaciones);
return lSOpOperaciones;
}

void EnviaSueldos(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("");
SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlSueldos");
}
void ArgumentosSueldos(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("");
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlSueldos",pSAgsSiscom);
}

