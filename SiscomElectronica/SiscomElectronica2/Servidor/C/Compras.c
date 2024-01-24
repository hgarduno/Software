#include <Compras.h>
#include <ComunElectronica2.h>
#include <SqlCompras.h>
SiscomOperaciones2 *OpCompras()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(10,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ObtenSemestreAnterior,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlHistoricoCompras,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlComprasSemestreAnterior,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlVentasTotalesSemestreAnterior,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EnviaResultadoCompras,lSOpOperaciones);
/*
SiscomAnexaOperacionAlArreglo21(ComunicacionExpendioConsulta,lSOpOperaciones,&lintNumOpS);
SiscomAnexaOperacionAlArreglo21(ObtenSemestreAnterior,lSOpOperaciones,&lintNumOpS);
SiscomAnexaOperacionAlArreglo21(SqlHistoricoCompras,lSOpOperaciones,&lintNumOpS);
SiscomAnexaOperacionAlArreglo21(SqlComprasSemestreAnterior,lSOpOperaciones,&lintNumOpS);
SiscomAnexaOperacionAlArreglo21(SqlVentasTotalesSemestreAnterior,lSOpOperaciones,&lintNumOpS);
SiscomAnexaOperacionAlArreglo21(EnviaResultadoCompras,lSOpOperaciones,&lintNumOpS);
SiscomAnexaOperacionAlArreglo21(0,lSOpOperaciones,&lintNumOpS);
SiscomLog("Las operaciones %d",lintNumOpS);
*/
return lSOpOperaciones;
}
SiscomOperaciones2 *OpComprasExistenciaMinima()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioConsulta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlHistoricoComprasExistenciaMinima,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(FiltraPorProducto,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(EnviaResultadoCompras,lSOpOperaciones);
return lSOpOperaciones;
}
void EnviaResultadoCompras(SArgsSiscom *pSAgsSiscom)
{

SiscomEnviaRegreso(pSAgsSiscom);
}
void ObtenSemestreAnterior(SArgsSiscom *pSAgsSiscom)
{
int lintDia,
    lintMes,
    lintAno;
int lintAnoA;
char lchrArrFechaIni[25],
     lchrArrFechaFin[25];
SiscomObtenFechaHoyINT(&lintDia,&lintMes,&lintAno);
if(lintMes>=1 && 
   lintMes<=6)
{
lintAnoA=lintAno-1;
sprintf(lchrArrFechaIni,
	"%04d-%02d-%02d",
	lintAnoA,
	6,
	30);
sprintf(lchrArrFechaFin,
	"%04d-%02d-%02d",
	lintAnoA,
	12,
	31);
}
if(lintMes>6 &&
   lintMes<=12 )
{
sprintf(lchrArrFechaIni,
	"%04d-%02d-%02d",
	lintAno,
	1,
	1);
sprintf(lchrArrFechaFin,
	"%04d-%02d-%02d",
	lintAno,
	6,
	30);
}
SiscomAnexaArgumentoConsulta(lchrArrFechaIni,
			     pSAgsSiscom);
SiscomAnexaArgumentoConsulta(lchrArrFechaFin,
			     pSAgsSiscom);

}

void FiltraPorProducto(SArgsSiscom *pSAgsSiscom)
{
int lintRFiltrados;
LCamposSiscomPro2 *lLCSiscomPro2ParaFiltrar=pSAgsSiscom->LCSiscomPro2Regreso;
LCamposSiscomPro2 *lLCSiscomPro2Ord=0;
SiscomAgrupaRegistrosPorCampo(lLCSiscomPro2ParaFiltrar,
			      pSAgsSiscom->intNumRegRegreso,
			      "cveproducto",
			      1,
			      &pSAgsSiscom->intNumRegRegreso,
			      &pSAgsSiscom->LCSiscomPro2Regreso);
SiscomOrdenaPorCampo("proveedor",
		     pSAgsSiscom->LCSiscomPro2Regreso,
		     pSAgsSiscom->intNumRegRegreso,
		     &lLCSiscomPro2Ord);
pSAgsSiscom->LCSiscomPro2Regreso=lLCSiscomPro2Ord;

}
