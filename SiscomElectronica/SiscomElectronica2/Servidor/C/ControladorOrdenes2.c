#include <ControladorOrdenes2.h>
#include <ComunElectronica2.h>
#include <SqlControladorOrdenes.h>
SiscomOperaciones2 *OpProductosOrden()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);

SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlProductosOrden,lSOpOperaciones2);
return lSOpOperaciones2;
}
