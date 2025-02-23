#include <Escuelas.h>
#include <ComunElectronica2.h>
#include <SQLEscuelas.h>
#include <stdlib.h>
#include <string.h>

SiscomOperaciones2 *OPEscuelas()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*3);
memset(lSOpOperaciones,0,sizeof(SiscomOperaciones2)*3);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLEscuelas,lSOpOperaciones);
return lSOpOperaciones;
}
