#include <ReportesSiscom.h>
#include <ExistenciaExpendios.h>
#include <SqlReportesSiscom.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomMacrosOperaciones.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <stdio.h>

void ReporteVentas4(int pintSocket,
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
SiscomAgregaOperacion(SqlExpendiosSiscom,&lSiscomProDat);
SiscomAgregaOperacion(SqlReporteVentas4,&lSiscomProDat);
SiscomAgregaOperacion(EnviaReportes,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}
void VentasSiscom(int pintSocket,
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
SiscomAgregaOperacion(SqlVentasSiscom,&lSiscomProDat);
SiscomAgregaOperacion(EnviaVentasSiscom,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}

void CierraDia(int pintSocket,
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
SiscomAgregaOperacion(SqlExpendiosSiscom,&lSiscomProDat);
SiscomAgregaOperacion(SqlCierraDia,&lSiscomProDat);
SiscomAgregaOperacion(AsignaReporteCierre,&lSiscomProDat);
SiscomAgregaOperacion(EnviaCierreDia,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}


int EnviaReportes(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrRegreso;

lSisRegProLPtrRegreso=SiscomRegistrosAsociadoRespuestaOperacion("VentasTotales",pSiscomOpePtrDato);

if((lSisRegProLPtrRegreso=SiscomRegistrosAsociadoRespuestaOperacion("VentasTotales",pSiscomOpePtrDato)) &&
   SiscomObtenCampoRegistroProLChar("ventastotales",lSisRegProLPtrRegreso))
{
SiscomAsociadoRespuestaLog("VentasTotales",lchrArrBuffer,pSiscomOpePtrDato);
/*
SiscomAsociadoRespuestaLog("VentasApartados",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("VentasPedidos",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("ImporteVentasPorEscuela",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("ImportePedidosPorEscuela",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("MaterialEscuela",lchrArrBuffer,pSiscomOpePtrDato);
*/
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
}
else
{
LogSiscom("Reporte sin datos");
pSiscomOpePtrDato->SiscomRegProLPtrPrimRes=0;
SiscomFormaEnviaRegistroRespuesta(pSiscomOpePtrDato,
				 lchrArrBuffer,
				 "Estado,Descripcion,",
				 "1",
				 "Reporte Sin Datos");
}
}
int EnviaVentasSiscom(SiscomOperaciones *pSiscomOpePtrDato)
{
LogSiscom("-----");
}
int EnviaCierreDia(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAsociadoRespuestaLog("VentasEfectivo",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("VentasPedidos",lchrArrBuffer,pSiscomOpePtrDato);
SiscomAsociadoRespuestaLog("TotalCaja",lchrArrBuffer,pSiscomOpePtrDato);
SiscomEnviaRegistrosRespuesta(pSiscomOpePtrDato,lchrArrBuffer);
}
int AsignaReporteCierre(SiscomOperaciones *pSiscomOpePtrDato)
{
}


