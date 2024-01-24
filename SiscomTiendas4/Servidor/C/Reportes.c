#include <Reportes.h>
#include <SQLReportes.h>
#include <ComunSiscomTiendas4.h>

#include <stdlib.h>
#include <string.h>
SiscomOperaciones2 *OPReporteVentas()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLReporteVentas,lSOpOperaciones);
return lSOpOperaciones;
}


SiscomOperaciones2 *OPDetalleVentas()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLDetalleVentas,lSOpOperaciones);
return lSOpOperaciones;
}
