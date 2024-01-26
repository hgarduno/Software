#include <FijaFechaCompra.h>
#include <SqlFechaCompra.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>

void FechaCompraProveedor(int pintSocket,
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
SiscomAgregaOperacion(ObtenFechaHoy,&lSiscomProDat);
SiscomAgregaOperacion(SqlFechaCompraProveedor,&lSiscomProDat);
SiscomAgregaOperacion(EnviaFechaCompraProveedor,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void FijaFechaCompra(int pintSocket,
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
SiscomAgregaOperacion(ObtenFechaHoy,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraFechaCompra,&lSiscomProDat);
SiscomAgregaOperacion(EnviaIdFechaCompraRegistrado,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int ObtenFechaHoy(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrFechaHoy[12];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFechaHoy);
SiscomAgregaCampoAsociadoEntrada("FechaHoy",lchrArrFechaHoy,"Envio",pSiscomOpePtrDato);
}

int EnviaIdFechaCompraRegistrado(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("");
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
const char *lchrPtrIdFechaCompra;
lchrPtrIdFechaCompra=SiscomCampoAsociadoEntradaOperacion("Envio",
						     "IdFechaCompra",
						     pSiscomOpePtrDato);
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdFechaCompra,Mensajes,",
		       lchrPtrIdFechaCompra,
		       "Registro Exitoso");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrPrim);
SiscomAsociadosArgumentoLog("SqlInsertaFechaCompra",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSiscomOpePtrDato);
}

int EnviaFechaCompraProveedor(SiscomOperaciones *pSiscomOpePtrDat)
{
char lchrArrBuffer[1024];

if(SiscomObtenRegistrosCampoRespuesta("FechaCompraProveedor",pSiscomOpePtrDat))
SiscomEnviaRegistrosSocket(pSiscomOpePtrDat->intSocket,
                           lchrArrBuffer,
			   SiscomRegistrosCampoO("FechaCompraProveedor",pSiscomOpePtrDat));

else
RespondeConsultaSinRegistros(pSiscomOpePtrDat);
}
