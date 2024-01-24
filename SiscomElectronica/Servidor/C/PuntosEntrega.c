#include <PuntosEntrega.h>
#include <SqlPuntosEntrega.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>



#include <string.h>
#include <stdlib.h>

void PuntosEntrega(int pintSocket,
			  SiscomRegistroProL *pSisRegProLPtrPrim,
			  SiscomRegistroProL *pSisRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSisRegProLPtrPrim,
			   (SiscomRegistroProL *)pSisRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(SqlPuntosEntrega,&lSiscomProDat);
SiscomAgregaOperacion(ConsultandoPuntosEntrega,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}



void RegistraPuntoEntrega(int pintSocket,
			  SiscomRegistroProL *pSisRegProLPtrPrim,
			  SiscomRegistroProL *pSisRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSisRegProLPtrPrim,
			   (SiscomRegistroProL *)pSisRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoPuntoEntrega,&lSiscomProDat);
SiscomAgregaOperacion(IdPuntoEntrega,&lSiscomProDat);
SiscomAgregaOperacion(AsignaIdPuntoEntregaADireccion,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistrandoPuntoEntrega,&lSiscomProDat);
SiscomAgregaOperacion(RegistrandoPuntoEntrega,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);

}

int ConsultandoPuntosEntrega(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[512];
LogSiscom("Ahora voy a consulta los puntos de entrega");
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);  
SiscomAsociadoRespuestaLog("SqlPuntosEntrega",lchrArrBuffer,pSisOpePtrDato);
SiscomEnviaAsociadoRespuestaCliente("SqlPuntosEntrega",
				    lchrArrBuffer,
				    pSisOpePtrDato);
return 0;
}

int RegistrandoPuntoEntrega(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[512];
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);  
SiscomAsociadosArgumentoLog("SqlPuntoEntrega",
			    "SentenciasSql",
			    lchrArrBuffer,
			    pSisOpePtrDato);
SiscomAsociadoAsociadoLog("Envio","Direccion",lchrArrBuffer,pSisOpePtrDato);
return 0;
}

int ArgumentoPuntoEntrega(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlPuntoEntrega",
				  pSisOpePtrDato->chrArrBaseDatos,
				  pSisOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSisOpePtrDato);
return 0;
}

int IdPuntoEntrega(SiscomOperaciones *pSisOpePtrDato)
{
SiscomIdARegistrosAsociadosEntrada("Envio","IdPuntoEntrega",pSisOpePtrDato);
return 0;
}

int AsignaIdPuntoEntregaADireccion(SiscomOperaciones *pSisOpePtrDato)
{
const char *lchrPtrIdPuntoEntrega;

if((lchrPtrIdPuntoEntrega=SiscomCampoAsociadoEntradaOperacion(
				"Envio",
				"IdPuntoEntrega",
				pSisOpePtrDato)))
{
SiscomActualizaCampoAsociadoAsociadoEntrada("Envio",
					    "Direccion",
					    "IdDireccion",
					    lchrPtrIdPuntoEntrega,
					    pSisOpePtrDato);
}

return 0;
}
