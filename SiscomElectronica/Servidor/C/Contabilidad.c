#include <Contabilidad.h>


#include <SqlSiscomElectronica.h>
#include <SqlContabilidad.h>

#include <ExistenciaExpendios.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomMacrosInsercionesSql.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>

#include <SiscomInsercionesSql.h>
#include <SiscomDesarrollo4/H/SiscomFuncionesComunes.h>
#include <ComunSiscomElectronica4.h>
#include <string.h>
#include <stdlib.h>

void FacturaPublicaEnGeneralPE(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(FacturandoPublicoEnGeneralPe,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);



}


void OrdenesTransferenciaTarjeta(int pintSocket,
			     SiscomRegistroProL *pSiscomRegProLPtrPrim,
			     SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(CreaArgumentosExistenciaExpendios,&lSiscomProDat);
/*
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
*/
SiscomAgregaOperacion(AgregaCamposExpendioComoPago,&lSiscomProDat);
SiscomAgregaOperacion(AgregaArgumentoSqlContabilidad,&lSiscomProDat);
SiscomAgregaOperacion(SqlComunicacionMatrizAArgumento,&lSiscomProDat); 
SiscomAgregaOperacion(AccesoDatosSiscomMatriz,&lSiscomProDat);
SiscomAgregaOperacion(SqlComunicacionExpendios,&lSiscomProDat);
SiscomAgregaOperacion(SqlOrdenesTarjetaTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(ConsultaOrdenesTarjetaTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(SqlInsertaOrdenesCantabilidad,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

SiscomCampoProL *ExpendioConsultado(SiscomCampoProL *pSisCamProLPtrExpendio,
				    const char **pchrPtrExpendio)
{
  if(pSisCamProLPtrExpendio)
  {
  *pchrPtrExpendio=pSisCamProLPtrExpendio->chrPtrNmbCampo;
   return pSisCamProLPtrExpendio->SiscomCamProLPtrSig;
  }
  else
  return 0;
}
SiscomCampoProL *ObtenExpendiosConsultados(SiscomOperaciones *pSisOpePtrDatos)
{
return pSisOpePtrDatos->SiscomRegProLPtrPrimRes->SiscomCamProLPtrDato;
}
SiscomRegistroProL *OrdenesTarjetaTransferencia(SiscomRegistroProL *pSisRegProLPtrDatos)
{
 SiscomRegistroProL *lSisRegProLPtrOrdenes;

 if((lSisRegProLPtrOrdenes=SiscomObtenRegistrosCampoProL("Ordenes",pSisRegProLPtrDatos)))
 return lSisRegProLPtrOrdenes;
 else
 return 0;
 							
}
void PonElExpendioConsultado(SiscomCampoProL *pSisCamProLPtrDato,
			     SiscomOperaciones *pSisOpePtrDatos)
{
SiscomActualizaCampoAsociadoEntrada("Envio",
				    "IdExpendio",
				    (char *)pSisCamProLPtrDato->chrPtrNmbCampo,
				    pSisOpePtrDatos);

}
void ArgumentoSentenciasContabilidad(SiscomOperaciones *pSiscomOpePtrDato,
				     SiscomRegistroProL **pSisRegProLPtrSqlAct)
{
*pSisRegProLPtrSqlAct=SiscomObtenArgumentoActOperaciones("SqlContabilidad",
							 pSiscomOpePtrDato);

}
int ConsultaOrdenesTarjetaTransferencia(SiscomOperaciones *pSiscomOpePtrDat)
{
SiscomRegistroProL *lSisRegProLPtrDatos,
	           *lSisRegProLPtrOrdenes,
		   *lSisRegProLPtrSqlContabilidad;
SiscomCampoProL *lSisCamProLPtrExpendios;
const char *lchrPtrExpendio;
char lchrArrBuffer[128];
lSisCamProLPtrExpendios=ObtenExpendiosConsultados(pSiscomOpePtrDat);
 ArgumentoSentenciasContabilidad(pSiscomOpePtrDat,&lSisRegProLPtrSqlContabilidad);
 InsertandoFacturacionPeriodica(pSiscomOpePtrDat,lSisRegProLPtrSqlContabilidad);
for(;
     lSisCamProLPtrExpendios;
     lSisCamProLPtrExpendios=lSisCamProLPtrExpendios->SiscomCamProLPtrSig)
{
 LogSiscom("Procesando Expendio %s",lSisCamProLPtrExpendios->chrPtrNmbCampo);
 PonElExpendioConsultado(lSisCamProLPtrExpendios,pSiscomOpePtrDat);
 lSisRegProLPtrOrdenes=SiscomObtenRegistrosCampoProL("Ordenes",
 			(SiscomRegistroProL *)lSisCamProLPtrExpendios->vidPtrSubPrim);
 SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrOrdenes);   
 if(lSisRegProLPtrOrdenes)
 SqlOrdenesContabilidadExpendio(lSisRegProLPtrOrdenes,
 			       lSisRegProLPtrSqlContabilidad,
			       pSiscomOpePtrDat);
}

SiscomArgumentoInsercionSqlLog("SqlContabilidad",lchrArrBuffer,pSiscomOpePtrDat); 
/*
while((lSisCamProLPtrExpendios=ExpendioConsultado(lSisCamProLPtrExpendios,&lchrPtrExpendio)))
{
LogSiscom("%s",lchrPtrExpendio);
lSisRegProLPtrOrdenes=OrdenesTarjetaTransferencia((SiscomRegistroProL *)lSisCamProLPtrExpendios->vidPtrSubPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrOrdenes);

}
*/
return 0;
}

int AgregaCamposExpendioComoPago(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrIdFacturacion[28];
SiscomObtenNumeroUnicoChar(lchrArrIdFacturacion);
SiscomAgregaCampoAsociadoEntrada("IdExpendio",0,"Envio",pSisOpePtrDatos);
SiscomAgregaCampoAsociadoEntrada("IdFacturacion",lchrArrIdFacturacion,"Envio",pSisOpePtrDatos);
return 0;
}
int AgregaArgumentoSqlContabilidad(SiscomOperaciones *pSisOpePtrDatos)
{
char lchrArrBuffer[256];
SiscomAgregaArgumentoInsercionSql2("SqlContabilidad",lchrArrBuffer,pSisOpePtrDatos);
return 0;
}

int FacturandoPublicoEnGeneralPe(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);
SiscomAsociadoAsociadoLog("Envio","Productos",lchrArrBuffer,pSisOpePtrDato);

}
