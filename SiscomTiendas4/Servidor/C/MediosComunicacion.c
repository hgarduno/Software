#include <MediosComunicacion.h>
#include <SQLMediosComunicacion.h>
#include <stdlib.h>
#include <string.h>
SiscomOperaciones2 *OPConsultaMedios()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SQLMediosComunicacion,lSOpOperaciones);
return lSOpOperaciones;
}
