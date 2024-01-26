#include <SqlSaldosMovimientos.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <stdio.h>
#include <string.h>

int SqlSaldosMovimientosMes(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[512];
SiscomRegistroProL *lSiscomRegProLPtrSqls;
lSiscomRegProLPtrSqls=SiscomObtenArgumentoPrimOperaciones("ConsultasSaldosMovimientos",
					pSiscomOpePtrDato);
SiscomConsultasSqlServidorPorIdMaquina2A(
	SiscomCampoAsociadoEntradaOperacion("Envio","IdTienda",pSiscomOpePtrDato),
	gSiscomRegProLPtrMemoria,
	"Mes",
	"SqlEntradas",
	lchrArrBuffer,
	lSiscomRegProLPtrSqls,
	pSiscomOpePtrDato);
}

int SqlConceptosSaldosMovimientos(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("");

}


char *SqlFormaConsultaPorMes(int pintMes,
			     SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrSql[512];

sprintf(lchrArrSql,
"									\n\
select 	sum(cantidad) salidas						\n\
from meses as a left outer join						\n\
	ventas as b on a.idmes=date_part('mon',fecha) left outer join	\n\
	detalleventas as d using(idventa)				\n\
where date_part('mon',fecha)=%d and 					\n\
	idproducto=%s",
pintMes,
SiscomCampoAsociadoEntradaOperacion("Envio","IdProducto",pSiscomOpePtrDato));
return strdup(lchrArrSql);	
}
int SqlFormaConsultasSaldosMovimientos(SiscomOperaciones *pSiscomOpePtrDato)
{
char *lchrPtrNombresConsultas[]={"Enero",
				 "Febrero",
				 "Marzo",
				 "Abril",
				 "Mayo",
				 "Junio",
				 "Julio",
				 "Agosto",
				 "Septiembre",
				 "Octubre",
				 "Noviembre",
				 "Diciembre",
				 0
				 };
char lchrArrBuffer[512];
int lintContador;
SiscomRegistroProL *lSiscomRegProLPtrPrimSql=0,
		   *lSiscomRegProLPtrActSql=0;
for(lintContador=0;
    lintContador<12;
    lintContador++)
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrimSql,
		       &lSiscomRegProLPtrActSql,
		       lchrArrBuffer,
		       "Mes,SqlEntradas,SqlSalidas,SqlExistencias,",
		       lchrPtrNombresConsultas[lintContador],
		       SqlFormaConsultaPorMes(lintContador+1,pSiscomOpePtrDato), 
		       0,
		       0);
SiscomAgregaArgumentoOperacion("ConsultasSaldosMovimientos",
				lSiscomRegProLPtrPrimSql,
				lSiscomRegProLPtrActSql,
				pSiscomOpePtrDato);
return 0;
}
SiscomCampoProL *SiscomFormaCamposParaNombresSqlPro(
			SiscomRegistroProL *pSiscomRegProLPtrDat,
			const char *pchrPtrCampo)
{
SiscomCampoProL *lSiscomCamProLPrim=0,
		*lSiscomCamProLAct=0;
   for(; 
	pSiscomRegProLPtrDat;
	pSiscomRegProLPtrDat=pSiscomRegProLPtrDat->SiscomRegProLPtrSig)
	SiscomNodoCampoPro(
		SiscomObtenCampoRegistroProLChar(pchrPtrCampo,pSiscomRegProLPtrDat),
		0,
		&lSiscomCamProLPrim,
		&lSiscomCamProLAct);
return lSiscomCamProLPrim;
}
/* Domingo 14 de Agosto 2016
 * Se requiere revisar la forma crear registros asociados 
 * adicionales para almacenar cada consulta, ahorita con 
 * esta implementacion solo, se puede trabajar con un 
 * campo del registro, pero para este caso van 3 consultas 
 * por lo que hay que ver como se debe solucionar esto
 *
 */
void SiscomConsultasSqlServidorPorIdMaquina2A(const char *pchrPtrIdServidor,
				     SiscomRegistroProL *pSiscomRegProLPtrMemoria,
				     const char *pchrPtrCampoParaNombres,
				     const char *pchrPtrCamposSqls,
				     char *pchrPtrBuffer,
				     SiscomRegistroProL *pSiscomRegProLPtrSqls,
				     SiscomOperaciones *pSiscomOpePtrDatos)

{
SiscomCampoProL *lSiscomCamProLPtrDato=0,
		*lSiscomCamProLPtrDatoAct=0,
	 	*lSiscomCamProLPtrPaso,
		*lSiscomCamProLPtrCampo;
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;

char *lchrPtrSql;
char *lchrPtrEdoConexion;
char lchrArrBuffer[256];
const char *lchrPtrDirIp;
int lintPuerto;
SiscomServidorPorIdMaquina(pchrPtrIdServidor,
			   pSiscomRegProLPtrMemoria,
			   &lintPuerto,
			   &lchrPtrDirIp);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       pchrPtrBuffer,
		       "BaseDatos,"
		       "PuertoBaseDatos,"
		       "Operacion,"
		       "EstadoOperacion,",
		       pSiscomOpePtrDatos->chrArrBaseDatos,
		       pSiscomOpePtrDatos->chrArrPuertoBaseDatos,
		       "EjecutaConsulta",
		       (char *)0);
lSiscomCamProLPtrPaso=lSiscomCamProLPtrDato=SiscomFormaCamposParaNombresSqlPro(
				pSiscomRegProLPtrSqls,
				pchrPtrCampoParaNombres);
SiscomNodoRegistroPro(lSiscomCamProLPtrPaso,
		      &lSiscomRegProLPtrPrim,
		      &lSiscomRegProLPtrAct);
 while(pSiscomRegProLPtrSqls)
 {
  SiscomAnexaRegistrosAlCampo(lSiscomCamProLPtrDato->chrPtrNmbCampo,
  			      lSiscomRegProLPtrAct,
			      pchrPtrBuffer,
			      "Sql,",
			      SiscomObtenCampoRegistroProLChar(pchrPtrCamposSqls,pSiscomRegProLPtrSqls));
  lSiscomCamProLPtrDato=lSiscomCamProLPtrDato->SiscomCamProLPtrSig;
  pSiscomRegProLPtrSqls=pSiscomRegProLPtrSqls->SiscomRegProLPtrSig;
}
if((pSiscomOpePtrDatos->intSocketAD=SiscomConectateCliente(
				lchrPtrDirIp,
				lintPuerto,
				&lchrPtrEdoConexion))>0)
{
SiscomEnviaRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			   pchrPtrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomLeeRegistrosSocket(pSiscomOpePtrDatos->intSocketAD,
			 pchrPtrBuffer,
			 &pSiscomOpePtrDatos->SiscomRegProLPtrPrimRes,
			 &pSiscomOpePtrDatos->SiscomRegProLPtrActRes);
close(pSiscomOpePtrDatos->intSocketAD);
}

}
