#include <PosicionesImpresion.h>
#include <SqlPosicionesImpresion.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void PosicionesPuntoVenta(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesPuntoVenta,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void PosicionesReciboApartado(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesReciboApartado,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosicionesReciboApartado,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void PosicionesTransferencia(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void PosicionesListaPrecios(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesListaPrecios,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void PosicionesListaPreciosComprador(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesListaPreciosComprador,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void PosicionesStockTienda(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesStockTienda,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void PosicionesCuentasPagar(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesCuentasPagar,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void PosicionesRelacionChequesPagar(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesRelacionChequesPagar,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void PosicionesSoporteCompras(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesSoporteCompras,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void PosicionesSoporteVentas(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesSoporteVentas,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void PosicionesStockProveedorCosto(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesStockProveedorCosto,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void PosicionesExistenciaTiendaProveedor(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesExistenciaTiendaProveedor,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void PosicionesSoporteTransferencias(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesSoporteTransferencias,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void PosicionesExistenciaProveedor(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesExistenciaProveedor,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void PosicionesDatosCompra(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesDatosCompra,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
void PosicionesProveedores(int pintSocket,
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
SiscomAgregaOperacion(SqlPosicionesProveedores,&lSiscomProDat);
SiscomAgregaOperacion(ArmaRespuestaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(EnviaPosiciones,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int EnviaPosiciones(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("PosicionesPuntoVenta",pSiscomOpePtrDato))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("PosicionesPuntoVenta",pSiscomOpePtrDato));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDato);
}
int EnviaPosicionesReciboApartado(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[1024];
if(SiscomObtenRegistrosCampoRespuesta("PosicionesReciboApartado",pSiscomOpePtrDato))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("PosicionesReciboApartado",pSiscomOpePtrDato));
else
RespondeConsultaSinRegistros(pSiscomOpePtrDato);
}
void AgregaPosicionesCampoRegistro(SiscomRegistroProL *pSiscomRegProLPtrRegistros,
				   SiscomRegistroProL *pSiscomRegProLPtrCamposRegistro)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrCamposRegistro;
SiscomRegistroProL *lSiscomRegProLPtrRegPosicionesPrim=0,
		   *lSiscomRegProLPtrRegPosicionesAct=0;
LogSiscom("%s",SiscomObtenCampoRegistroProLChar("idcampo",pSiscomRegProLPtrRegistros));
			
for(lSiscomRegProLPtrCamposRegistro=pSiscomRegProLPtrCamposRegistro;
    lSiscomRegProLPtrCamposRegistro;
    lSiscomRegProLPtrCamposRegistro=lSiscomRegProLPtrCamposRegistro->SiscomRegProLPtrSig)
{
  if(!SiscomComparaCampoRegistrosProL2("idcampo",
  				      "idregistro",
				      pSiscomRegProLPtrRegistros,
				      lSiscomRegProLPtrCamposRegistro))
   {
	LogSiscom("\t%s %s",
		   SiscomObtenCampoRegistroProLChar("idregistro",lSiscomRegProLPtrCamposRegistro),
		   SiscomObtenCampoRegistroProLChar("idcampo",lSiscomRegProLPtrCamposRegistro));
	/*
	SiscomAnexaRegistroPro2(&lSiscomRegProLPtrRegPosicionesPrim,
			&lSiscomRegProLPtrRegPosicionesAct,
			lSiscomRegProLPtrCamposRegistro);
			*/
   }
}
SiscomRegistrosAlCampo("registrocampo",
			lSiscomRegProLPtrRegPosicionesPrim,
			lSiscomRegProLPtrRegPosicionesAct,
			pSiscomRegProLPtrRegistros);
}
int ArmaRespuestaPosiciones(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrCampos,
		   *lSisRegProLPtrCamposRegistro;
lSisRegProLPtrCampos=SiscomRegistrosCampoO("PosicionesPuntoVenta",pSiscomOpePtrDato);
lSisRegProLPtrCamposRegistro=SiscomRegistrosCampoO("CampoRegistroPosiciones",pSiscomOpePtrDato);
/*
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrCampos);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrCamposRegistro); 
*/
for(;
	lSisRegProLPtrCampos;
	lSisRegProLPtrCampos=lSisRegProLPtrCampos->SiscomRegProLPtrSig)
{
   for(lSisRegProLPtrCamposRegistro=SiscomRegistrosCampoO("CampoRegistroPosiciones",pSiscomOpePtrDato); 
   	lSisRegProLPtrCamposRegistro;
	lSisRegProLPtrCamposRegistro=lSisRegProLPtrCamposRegistro->SiscomRegProLPtrSig)
   {
      if(SiscomObtenCampoRegistroProLInt("idtipocampo",lSisRegProLPtrCampos)==1)
      {
        LogSiscom("%s",
		  SiscomObtenCampoRegistroProLChar("idcampo",lSisRegProLPtrCampos));
	AgregaPosicionesCampoRegistro(lSisRegProLPtrCampos,
				      lSisRegProLPtrCamposRegistro);
	break;
      } 
   }

}
}
