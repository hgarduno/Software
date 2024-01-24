#include <Ordenes.h>
#include <SqlOrdenes.h>
#include <ComunElectronica2.h>

SiscomOperaciones2 *OpAnexarOrdenContabilidad()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ArgumentosOrdenes,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlAnexarOrdenContabilidad,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(AnexarOrdenContabilidad,lSOpOperaciones2);
return lSOpOperaciones2;
}

void ArgumentosOrdenes(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"SqlOrdenes",pSAgsSiscom);
}
SiscomOperaciones2 *OpOrdenesVendidasSiscom()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlOrdenesVendidas,lSOpOperaciones2);
return lSOpOperaciones2;
}

SiscomOperaciones2 *OpDetalleOrden()
{
SiscomOperaciones2 *lSOpOperaciones2;
SiscomMemoriaOperaciones2(150,&lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones2);
SiscomAnexaOperacionAlArreglo2(SqlDetalleOrden,lSOpOperaciones2);
return lSOpOperaciones2;
}

void AnexarOrdenContabilidad(SArgsSiscom *pSAgsSiscom)
{
SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlOrdenes");

}

