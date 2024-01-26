#include <Clientes.h>
#include <SqlClientes.h>
#include <ComunSiscomServiSNTE.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <string.h>
void ConsultaClienteCompras(int pintSocket,
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
SiscomAgregaOperacion(SqlComprasCliente,&lSiscomProDat);
SiscomAgregaOperacion(EnviaComprasCliente,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

int HayDatosCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrCliente;
lSiscomRegProLPtrCliente=SiscomObtenRegistrosCampoRespuesta("Cliente",pSiscomOpePtrDato);
return lSiscomRegProLPtrCliente ? 1 : 0;
}
void ClienteNoRegistrado(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrPrim=0,
		   *lSiscomRegProLPtrAct=0;
char lchrArrBuffer[128];
SiscomAnexaRegistroPro(&lSiscomRegProLPtrPrim,
		       &lSiscomRegProLPtrAct,
		       lchrArrBuffer,
		       "IdMensaje,Mensajes,",
		       "0",
		       "Persona No Registrada");
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   lSiscomRegProLPtrPrim);
}
int EnviaComprasCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
  if(HayDatosCliente(pSiscomOpePtrDato))
  {
	VerificaSiSePuedeVenderACredito(pSiscomOpePtrDato);
  }
  else
  {
  	LogSiscom("Se Envia Cliente No Registrado");
	ClienteNoRegistrado(pSiscomOpePtrDato);

  }
}
int CuentaComprasACredito(SiscomOperaciones *pSiscomOpePtrDato)
{
int lintComprasACredito=0;
SiscomRegistroProL *lSisRegProLPtrCompras;
lSisRegProLPtrCompras=SiscomRegistrosAsociadoRespuestaOperacion("Compras",pSiscomOpePtrDato);
for( ;
     lSisRegProLPtrCompras;
     lSisRegProLPtrCompras=SiscomSiguienteNodoRegistroProL(lSisRegProLPtrCompras))
{
  if(SiscomObtenCampoRegistroProLInt("idtipoventa",lSisRegProLPtrCompras)==
     ComprasPorFinanciera(pSiscomOpePtrDato))
   lintComprasACredito++;

}
return lintComprasACredito;
}
int ComprasPorFinanciera(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrCreditosPorFinanciera;
int lintIdFinanciera=SiscomCampoAsociadoRespuestaOperacionInt("Compras",
							      "idfinanciadora",
							      pSiscomOpePtrDato);
lSiscomRegProLPtrCreditosPorFinanciera=SiscomRegistrosAsociadoRespuestaOperacion("CreditosPorFinanciera",
										 pSiscomOpePtrDato);
for(;
    lSiscomRegProLPtrCreditosPorFinanciera;
    lSiscomRegProLPtrCreditosPorFinanciera=lSiscomRegProLPtrCreditosPorFinanciera->SiscomRegProLPtrSig)
{
   if(lintIdFinanciera==SiscomObtenCampoRegistroProLInt("idfinanciadora",lSiscomRegProLPtrCreditosPorFinanciera))
   return SiscomObtenCampoRegistroProLInt("numero",lSiscomRegProLPtrCreditosPorFinanciera);

}
return 0;
}
void AgregaComprasCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrCompras;
lSisRegProLPtrCompras=SiscomRegistrosAsociadoRespuestaOperacion("Compras",pSiscomOpePtrDato);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrCompras);
SiscomAgregaCampoAsociadoRespuesta("Compras",0,"Cliente",pSiscomOpePtrDato); 
SiscomRegistrosAlCampoAsociadoRespuesta("Cliente",
				"Compras",
				lSisRegProLPtrCompras,
				lSisRegProLPtrCompras,
				pSiscomOpePtrDato);

}
void SePuedeVenderACredito(SiscomOperaciones *pSiscomOpePtrDato)
{
int lintNCompras;
if(SiscomCampoAsociadoEntradaOperacionInt("Envio",
					  "IdTipoVenta",
					  pSiscomOpePtrDato)==2 &&
   (lintNCompras=CuentaComprasACredito(pSiscomOpePtrDato))>=2)
SiscomAgregaCampoAsociadoRespuesta("SePuedeVender","0","Cliente",pSiscomOpePtrDato); 
else
SiscomAgregaCampoAsociadoRespuesta("SePuedeVender","1","Cliente",pSiscomOpePtrDato); 

LogSiscom("Se tienen %d Compras",lintNCompras);
}
void VerificaSiSePuedeVenderACredito(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrDatos;
SePuedeVenderACredito(pSiscomOpePtrDato);
SiscomEnviaRegistrosSocket(pSiscomOpePtrDato->intSocket,
			   lchrArrBuffer,
			   pSiscomOpePtrDato->SiscomRegProLPtrActRes);
}
