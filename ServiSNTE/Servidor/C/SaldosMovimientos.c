#include <SaldosMovimientos.h>
#include <SqlSaldosMovimientos.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>
void SaldosMovimientosMes(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);
SiscomAgregaOperacion(SqlFormaConsultasSaldosMovimientos,&lSiscomProDat);
SiscomAgregaOperacion(SqlSaldosMovimientosMes,&lSiscomProDat);
SiscomAgregaOperacion(EnviaSaldosMovimientosMes,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void ConceptosSaldosMovimientos(int pintSocket,
	   void *pvidPtrAncla,
	   const SiscomRegistroProL *pSiscomRegProLPtrPrim,
	   const SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   pvidPtrAncla,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(ComunicacionAccesoDatos,&lSiscomProDat);
SiscomAgregaOperacion(SqlConceptosSaldosMovimientos,&lSiscomProDat);
SiscomAgregaOperacion(EnviaConceptosSaldosMovimientos,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void AgregandoSaldosMovimientoProductoMes(const char *pchrPtrMes,
					  SiscomRegistroProL *pSiscomRegProLPtrMes,
					  SiscomRegistroProL **pSiscomRegProLPtrRegresoPrim,
					  SiscomRegistroProL **pSiscomRegProLPtrRegresoAct)
{
char lchrArrBuffer[128];
  LogSiscom("Si hay movimiento en el mes %s",pchrPtrMes);
  SiscomRegistroProtocoloLog(lchrArrBuffer,pSiscomRegProLPtrMes);
  SiscomAnexaRegistroPro(pSiscomRegProLPtrRegresoPrim,
  			pSiscomRegProLPtrRegresoAct,
			lchrArrBuffer,
			"Mes,Salidas,Entradas,Existencia",
			pchrPtrMes,
			SiscomObtenCampoRegistroProLChar("salidas",pSiscomRegProLPtrMes),
			0,
			0);
}
					 
void AgregandoSaldosMovimientoProductoMesVacio(
					  const char *pchrPtrMes,
					  SiscomRegistroProL **pSiscomRegProLPtrRegresoPrim,
					  SiscomRegistroProL **pSiscomRegProLPtrRegresoAct)
{
char lchrArrBuffer[128];
LogSiscom("Agregando %s Vacio",pchrPtrMes);
  SiscomAnexaRegistroPro(pSiscomRegProLPtrRegresoPrim,
  			pSiscomRegProLPtrRegresoAct,
			lchrArrBuffer,
			"Mes,Salidas,Entradas,Existencia,",
			pchrPtrMes,
			"0",
			0,
			0);

}
void FormaRespuestaSaldosMovimientosProductoMes(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrMeses,
		   *lSiscomRegProLPtrDatos,
		   *lSiscomRegProLPtrRegresoPrim=0,
		   *lSiscomRegProLPtrRegresoAct=0;
const char *lchrPtrMes;
char lchrArrBuffer[128];
for(lSiscomRegProLPtrMeses=SiscomObtenArgumentoPrimOperaciones("ConsultasSaldosMovimientos",
						pSiscomOpePtrDato);
    lSiscomRegProLPtrMeses;
    lSiscomRegProLPtrMeses=lSiscomRegProLPtrMeses->SiscomRegProLPtrSig)
{
  lchrPtrMes=SiscomObtenCampoRegistroProLChar("Mes",lSiscomRegProLPtrMeses);
 LogSiscom("%s",lchrPtrMes);
 if((lSiscomRegProLPtrDatos=SiscomRegistrosAsociadoRespuestaOperacion(lchrPtrMes,pSiscomOpePtrDato)))
   AgregandoSaldosMovimientoProductoMes(lchrPtrMes,
   					lSiscomRegProLPtrDatos,
				       &lSiscomRegProLPtrRegresoPrim,
				       &lSiscomRegProLPtrRegresoAct);
   else
   AgregandoSaldosMovimientoProductoMesVacio(lchrPtrMes,
   						&lSiscomRegProLPtrRegresoPrim,
					     &lSiscomRegProLPtrRegresoAct);

}
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrRegresoPrim);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,lchrArrBuffer,lSiscomRegProLPtrRegresoPrim);
}

int EnviaSaldosMovimientosMes(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
FormaRespuestaSaldosMovimientosProductoMes(pSiscomOpePtrDato);
}
int EnviaConceptosSaldosMovimientos(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("");
}
