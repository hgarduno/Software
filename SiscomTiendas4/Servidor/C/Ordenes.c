#include <Ordenes.h>
#include <SQLOrdenes.h>
#include <ComunSiscomTiendas4.h>

#include <stdlib.h>
#include <string.h>

SiscomOperaciones2 *OPOrdenVendida()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLOrdenVendida,lSOpOperaciones);
return lSOpOperaciones;
}
SiscomOperaciones2 *OPOrdenesVendidas()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*100);
SiscomAnexaOperacionAlArreglo2(ComunicacionAccesoDatos,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SQLOrdenesVendidas,lSOpOperaciones);
return lSOpOperaciones;
}
