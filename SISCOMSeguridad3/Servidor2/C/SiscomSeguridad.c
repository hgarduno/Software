#include <SiscomSeguridad.h>
#include <SqlSeguridad.h>

#include <stdlib.h>
SiscomOperaciones2 *SiscomOpInfoVariable()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
if(ComunicacionSeguridad)
{
SiscomAnexaOperacionAlArreglo2(ComunicacionSeguridad,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomSqlInfoVariable,lSOpOperaciones2);
}
else
{
 SiscomLog("No se ha iniciado la variable ComunicacionSeguridad");
 exit(0);
}
return lSOpOperaciones2;
}
