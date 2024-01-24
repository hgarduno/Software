#include <Existencias.h>
#include <SQLExistencias.h>
#include <string.h>
#include <stdlib.h>
SiscomOperaciones2 *OPExistenciaProductos()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(SQLExistenciaProductos,lSOpOperaciones);
return lSOpOperaciones;
}
