#include <Proveedores2.h>
#include <ComunElectronica2.h>
#include <SqlProveedores.h>
SiscomOperaciones2 *OpProveedores()
{
SiscomOperaciones2 *lSOpOperaciones;
lSOpOperaciones=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2 )*120);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlProveedoresRegistrados,lSOpOperaciones);
return lSOpOperaciones;
}
