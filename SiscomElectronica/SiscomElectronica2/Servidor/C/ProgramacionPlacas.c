#include <ProgramacionPlacas.h>
#include <ComunElectronica2.h>
#include <SqlProgramacionPlacas.h>
#include <stdlib.h>
SiscomOperaciones2 *OpProgramacionPlacas()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlProgramacionPlacas,lSOpOperaciones2);
return lSOpOperaciones2;
}

SiscomOperaciones2 *OpEntregarPlaca()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*300);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosEntregaPlaca,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlEntregaPlaca,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EntregaPlaca,lSOpOperaciones);
return lSOpOperaciones;
}

void ArgumentosEntregaPlaca(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlEntregarPlaca",pSAgsSiscom);
}

void EntregaPlaca(SArgsSiscom *pSAgsSiscom)
{
  SiscomLog("Entregando la placa");
  SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlEntregarPlaca");
}
