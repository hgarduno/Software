#include <MotivoInventario.h>
#include <ComunElectronica2.h>
#include <SqlMotivoInventario.h>
SiscomOperaciones2 *OPMotivoInventario()
{

SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlMotivoInventario,lSOpOperaciones2);
return lSOpOperaciones2;
}
