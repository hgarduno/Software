#include <TransferenciasExpendioAExpendio.h>
#include <ImpresionTicketVenta.h>
#include <ExistenciaExpendios.h>
#include <SqlTransferenciasExpendioAExpendio.h>
#include <SqlSiscomElectronica.h>


#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomMacrosInsercionesSql.h>
#include <SiscomReplicacion.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>
#include <string.h> 

void ExistenciaExpendioOrigenDestino(int pintSocket,
				     SiscomRegistroProL *pSiscomRegProLPtrPrim,
				     SiscomRegistroProL *pSiscomRegProLPtrAct)
{
SiscomProcesos *lSiscomProDat=0;
SiscomOperacionErrores lSisOpDatError={0,
				       ExpendioOrigenSinConexion,
				       ExpendioDestinoSinConexion,
				       0};
SiscomOperaciones lSiscomOpDat;
memset(&lSiscomOpDat,0,sizeof(SiscomOperaciones));
SiscomIniciaDatosOperacion(pintSocket,
			   0,
			   (SiscomRegistroProL *)pSiscomRegProLPtrPrim,
			   (SiscomRegistroProL *)pSiscomRegProLPtrAct,
			   &lSiscomOpDat);
SiscomAgregaOperacion(AccesoDatosSiscomElectronica4,&lSiscomProDat);
SiscomAgregaOperacion(CreaArgumentosExistenciaExpendios,&lSiscomProDat);
SiscomAgregaOperacion(SqlComunicacionExpendios,&lSiscomProDat);
SiscomAgregaOperacion(ObteniendoExistenciaExpendioOrigenDestino,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,lSisOpDatError,lSiscomProDat);
}
void TransferenciaOtrosExpendios(int pintSocket,
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
SiscomAgregaOperacion(AsignaFechaHoyProductosOtrosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(SqlTransferenciasOtrosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(ProductosTransferenciaOtrosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void TransfiereExpendioAExpendio(int pintSocket,
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
SiscomAgregaOperacion(SqlComunicacionExpendios,&lSiscomProDat);
SiscomAgregaOperacion(CreaArgumentoExpendioOrigen,&lSiscomProDat);
SiscomAgregaOperacion(CreaArgumentoExpendioDestino,&lSiscomProDat);
SiscomAgregaOperacion(AgregaCampoFechaHora,&lSiscomProDat);
SiscomAgregaOperacion(AgregaIdTransferencia,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraTransferenciaExpendioOrigen,&lSiscomProDat);
SiscomAgregaOperacion(SqlRegistraTransferenciaExpendioDestino,&lSiscomProDat);
SiscomAgregaOperacion(TransfiriendoExpendioAExpendio,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}

void ValidandoTransferenciaExpendioOrigen(int pintSocket,
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
SiscomAgregaOperacion(ValidaTransferenciaExpendioOrigen,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);


}

void AgregaExpendioOrigenDestino(const char *pchrPtrIdExpendio,
				 SiscomRegistroProL *pSisRegProLPtrExpendio,
				 SiscomRegistroProL **pSisRegProLPtrPrimReg,
				 SiscomRegistroProL **pSisRegProLPtrActReg)
{
 if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrIdExpendio,
 					  "idempresa",
					  pSisRegProLPtrExpendio))
 SiscomNodoRegistroPro(pSisRegProLPtrExpendio->SiscomCamProLPtrDato,
 		       pSisRegProLPtrPrimReg,
		       pSisRegProLPtrActReg);

}
void ObtenExpendiosOrigenDestino(SiscomOperaciones *pSiscomOpePtrDato,
		                 SiscomRegistroProL **pSisRegProLPtrDatos)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrDatos,
		   *lSisRegProLPtrDatosAct=0,
		   *lSisRegProLPtrDatosPrim=0,
		   *lSisRegProLPtrRegAct;
const char *lchrPtrIdExpendioDestino,
	   *lchrPtrIdExpendioOrigen;
lSisRegProLPtrDatos=SiscomObtenArgumentoPrimAsociadoOperaciones("Expendios",
							"Servidores",
							pSiscomOpePtrDato);

lchrPtrIdExpendioDestino=SiscomCampoAsociadoEntradaOperacion("Envio",
							     "IdExpendioD",
							     pSiscomOpePtrDato);
lchrPtrIdExpendioOrigen=SiscomCampoAsociadoEntradaOperacion("Envio",
							    "IdExpendioO",
							    pSiscomOpePtrDato);
*pSisRegProLPtrDatos=0;

SiscomAnexaRegistroPro(pSisRegProLPtrDatos,
		       &lSisRegProLPtrRegAct,
		       lchrArrBuffer,
		       "Servidores,",
		       (const char *)0);
for(;
    lSisRegProLPtrDatos;
    lSisRegProLPtrDatos=lSisRegProLPtrDatos->SiscomRegProLPtrSig)
{
  AgregaExpendioOrigenDestino(lchrPtrIdExpendioOrigen,
  			       lSisRegProLPtrDatos,
			       &lSisRegProLPtrDatosPrim,
			       &lSisRegProLPtrDatosAct);
  AgregaExpendioOrigenDestino(lchrPtrIdExpendioDestino,
  			       lSisRegProLPtrDatos,
			       &lSisRegProLPtrDatosPrim,
			       &lSisRegProLPtrDatosAct);
}
SiscomRegistrosAlCampo("Servidores",
		       lSisRegProLPtrDatosPrim,
		       lSisRegProLPtrDatosAct,
		       *pSisRegProLPtrDatos);
}
const char *SePuedeTransferirOrigenDestino(SiscomRegistroProL *pSisRegProLPtrExpO)
{
float lfltExistenciaO;
   if((lfltExistenciaO=SiscomObtenCampoRegistroProLFloat("existencia",pSisRegProLPtrExpO))>0.0)
   {
      LogSiscom("Si se puede Transferir ");
      return "1"; 
   }
   else
   return "0";

}
void FormaRegistroRespuestaExistenciaOrigenDestino(SiscomRegistroProL *pSisRegProLPtrExpO,
						   SiscomRegistroProL *pSisRegProLPtrExpD,
						   SiscomRegistroProL **pSisRegProLPtrRegreso)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrRegAct=0;
*pSisRegProLPtrRegreso=0;
SiscomAnexaRegistroPro(pSisRegProLPtrRegreso,
		       &lSisRegProLPtrRegAct,
		       lchrArrBuffer,
		       "ExistenciaOrigen,ExistenciaDestino,SePuedeTransferir,Cantidad,",
		       SiscomObtenCampoRegistroProLChar("existencia",pSisRegProLPtrExpO),
		       SiscomObtenCampoRegistroProLChar("existencia",pSisRegProLPtrExpD),
		       SePuedeTransferirOrigenDestino(pSisRegProLPtrExpO),
		       "0");
}

/* Tepotzotlan Martes 14 Septiembre 2021  
 * Seguimos con lo del Covid , ya casi 2 anios 
 * Cuando alguna de las maquinas no tiene conexion, el sistema truena
 * hay que agregar la validacion correspondiente
 */
int ObtenExistenciaExpendioOrigenDestino(SiscomOperaciones *pSiscomOpePtrDato,
					  SiscomRegistroProL **pSisRegProLPtrExiRegreso)
{
char lchrArrBuffer[256];
SiscomRegistroProL *lSisRegProLPtrExistenciaO,
		   *lSisRegProLPtrExistenciaD ;
const char *lchrPtrIdExpendioDestino,
	   *lchrPtrIdExpendioOrigen;

lchrPtrIdExpendioDestino=SiscomCampoAsociadoEntradaOperacion("Envio",
							     "IdExpendioD",
							     pSiscomOpePtrDato);
lchrPtrIdExpendioOrigen=SiscomCampoAsociadoEntradaOperacion("Envio",
							    "IdExpendioO",
							    pSiscomOpePtrDato);
LogSiscom("%s %s",lchrPtrIdExpendioDestino,lchrPtrIdExpendioOrigen);
lSisRegProLPtrExistenciaO=SiscomRegistrosMaquinaConsulta(lchrPtrIdExpendioOrigen,
							 "Existencia",
							 pSiscomOpePtrDato);
lSisRegProLPtrExistenciaD=SiscomRegistrosMaquinaConsulta(lchrPtrIdExpendioDestino,
							 "Existencia",
							 pSiscomOpePtrDato);
if(lSisRegProLPtrExistenciaO && 
   lSisRegProLPtrExistenciaD)
{
FormaRegistroRespuestaExistenciaOrigenDestino(lSisRegProLPtrExistenciaO,
					      lSisRegProLPtrExistenciaD,
					      pSisRegProLPtrExiRegreso);
return 0;
}
else
if(!lSisRegProLPtrExistenciaO)
return 1;
else
if(!lSisRegProLPtrExistenciaD)
return 2;
}
int ObteniendoExistenciaExpendioOrigenDestino(SiscomOperaciones *pSisOpePtrDato)
{
int lintRegreso;
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrExistenciaOrigen,
		   *lSisRegProLPtrExistenciaDestino;
SiscomRegistroProL *lSisRegProLPtrExpendios,
		   *lSisRegProLPtrExistenciaReg;
SiscomRegistroProtocoloLog(lchrArrBuffer,pSisOpePtrDato->SiscomRegProLPtrPrimRes);
ObtenExpendiosOrigenDestino(pSisOpePtrDato,&lSisRegProLPtrExpendios);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrExpendios);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"Servidores",lSisRegProLPtrExpendios);
SqlExistenciaExpendioOrigenDestino(lSisRegProLPtrExpendios,pSisOpePtrDato);
if(!(lintRegreso=ObtenExistenciaExpendioOrigenDestino(pSisOpePtrDato,
						     &lSisRegProLPtrExistenciaReg)))
SiscomEnviaRegistrosSocket(pSisOpePtrDato->intSocket,lchrArrBuffer,lSisRegProLPtrExistenciaReg);

return lintRegreso; 
}
void FormaRegistroEnvioSePuedeTransferir(SiscomRegistroProL **pSisRegProLPtrRegPrim,
					 SiscomRegistroProL **pSisRegProLPtrRegAct,
					 const char *pchrPtrEstado)
{
char lchrArrBuffer[128];
SiscomAnexaRegistroPro(pSisRegProLPtrRegPrim,
		       pSisRegProLPtrRegAct,
		       lchrArrBuffer,
		       "SePuedeTransferir,",
		       pchrPtrEstado);
}
int ValidaTransferenciaExpendioOrigen(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
float lfltExistenciaOrigen,
	lfltCantidad;
SiscomRegistroProL *lSisRegProLPtrRegPrim=0,
		   *lSisRegProLPtrRegAct=0;
const char *lchrPtrEstado;
lfltExistenciaOrigen=SiscomCampoAsociadoEntradaOperacionFloat("Envio","ExistenciaOrigen",pSisOpePtrDato);
lfltCantidad=SiscomCampoAsociadoEntradaOperacionFloat("Envio","Cantidad",pSisOpePtrDato);
LogSiscom("Existencia Expendio Origen %f Cantidad %f",
	   lfltExistenciaOrigen,
	   lfltCantidad);
if(lfltExistenciaOrigen>0.0 &&
   lfltCantidad<=lfltExistenciaOrigen)
  lchrPtrEstado="1";
  else
  lchrPtrEstado="0";
   FormaRegistroEnvioSePuedeTransferir(&lSisRegProLPtrRegPrim,
   				       &lSisRegProLPtrRegAct,
				       lchrPtrEstado);
 SiscomEnviaRegistrosSocket(pSisOpePtrDato->intSocket,lchrArrBuffer,lSisRegProLPtrRegPrim); 
}
void ObtenIdsExpendios(SiscomOperaciones *pSisOpPtrDato,
		       const char **pchrPtrIdExpendioO,
		       const char **pchrPtrIdExpendioD)
{
*pchrPtrIdExpendioO=SiscomCampoAsociadoEntradaOperacion("Envio","ExpendioO",pSisOpPtrDato);
*pchrPtrIdExpendioD=SiscomCampoAsociadoEntradaOperacion("Envio","ExpendioD",pSisOpPtrDato);
}
int TransfiriendoExpendioAExpendio(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
const char *lchrPtrIdExpendioO,
	   *lchrPtrIdExpendioD;
SiscomRegistroProL *lSisRegProLPtrExpendios;
SiscomAsociadoEntradaLog("Envio",lchrArrBuffer,pSisOpePtrDato);
if((lSisRegProLPtrExpendios=SiscomObtenArgumentoPrimOperaciones("Expendios",
					pSisOpePtrDato)))
{
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrExpendios);
SiscomRegistrosAsociadosLog(lchrArrBuffer,"Servidores",lSisRegProLPtrExpendios);
ObtenIdsExpendios(pSisOpePtrDato,&lchrPtrIdExpendioO,&lchrPtrIdExpendioD);
LogSiscom("Los Ids Origen (%s) Destino (%s)",lchrPtrIdExpendioO,lchrPtrIdExpendioD);
LogSiscom("Enviando Actualizacion Expendio Origen(%s)",lchrPtrIdExpendioO);
SiscomArgumentoInsercionSqlLog("SqlExpendioOrigen",lchrArrBuffer,pSisOpePtrDato);
SiscomReplicaMaquinaPorCampo("idempresa",
			     lchrPtrIdExpendioO,
			     "SqlExpendioOrigen",
			     lchrArrBuffer,
			     lSisRegProLPtrExpendios,
			     0,
			     pSisOpePtrDato);
LogSiscom("Enviando Actualizacion Expendio Destino(%s)",lchrPtrIdExpendioD);
SiscomArgumentoInsercionSqlLog("SqlExpendioDestino",lchrArrBuffer,pSisOpePtrDato);
SiscomReplicaMaquinaPorCampo("idempresa",
			     lchrPtrIdExpendioD,
			     "SqlExpendioDestino",
			     lchrArrBuffer,
			     lSisRegProLPtrExpendios,
			     0,
			     pSisOpePtrDato);
}
}

int CreaArgumentoExpendioDestino(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
const char *lchrPtrBaseDestino,
	   *lchrPtrIdExpendioDestino;

lchrPtrIdExpendioDestino=SiscomCampoAsociadoEntradaOperacion("Envio",
							     "ExpendioD",
							     pSiscomOpePtrDato);
lchrPtrBaseDestino=SiscomCampoServidorPorId("basedatos",
					   "idempresa",
					   lchrPtrIdExpendioDestino,
					   "Expendios",
					   "Servidores",
					   pSiscomOpePtrDato);
SiscomAgregaArgumentoInsercionSql("SqlExpendioDestino",
				  lchrPtrBaseDestino,
				  0,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
}
int CreaArgumentoExpendioOrigen(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
const char *lchrPtrBaseOrigen,
	   *lchrPtrPuertoDB=0,
	   *lchrPtrIdExpendioOrigen;
lchrPtrIdExpendioOrigen=SiscomCampoAsociadoEntradaOperacion("Envio",
							    "ExpendioO",
							    pSiscomOpePtrDato);
lchrPtrBaseOrigen=SiscomCampoServidorPorId("basedatos",
					   "idempresa",
					   lchrPtrIdExpendioOrigen,
					   "Expendios",
					   "Servidores",
					   pSiscomOpePtrDato);
SiscomAgregaArgumentoInsercionSql("SqlExpendioOrigen",
				  lchrPtrBaseOrigen,
				  lchrPtrPuertoDB,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
}

int AgregaIdTransferencia(SiscomOperaciones *pSisOpePtrDato)
{
int lintContador;
SiscomAgregaCampoAsociadoEntrada("IdTransferencia",0,"Envio",pSisOpePtrDato);
SiscomIdARegistrosAsociadosEntrada("Envio","IdTransferencia",pSisOpePtrDato);
}

int AsignaFechaHoyProductosOtrosExpendios(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAsignaFechaAsociadoEntrada("Envio","Fecha",pSiscomOpePtrDato);
}

int ProductosTransferenciaOtrosExpendios(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAsociadoRespuestaLog("Productos",lchrArrBuffer,pSisOpePtrDato);
SiscomEnviaAsociadoRespuestaCliente("Productos",
				    lchrArrBuffer,
				    pSisOpePtrDato);
}

int ConexionExpendioTransferencia(SiscomRegistroProL *pSisRegProLPtrMemoria,
				  const char *pchrPtrCampo,
				  SiscomOperaciones *pSisOpePtrDato)
{
LogSiscom("Conectando a %s:%s",
	  SiscomObtenCampoRegistroProLChar("dirip",pSisRegProLPtrMemoria),
	  SiscomObtenCampoRegistroProLChar("puerto",pSisRegProLPtrMemoria));


}
int ErrorConexionExpendioTransferencia(
			  SiscomRegistroProL *pSiscomRegProLPtrMemoria,
			  const char *pchrPtrCampo,
			  SiscomOperaciones *pSiscomOpePtrDatos)
{

LogSiscom("Error Al Conectarse  %s:%s",
	  SiscomObtenCampoRegistroProLChar("dirip",pSiscomRegProLPtrMemoria),
	  SiscomObtenCampoRegistroProLChar("puerto",pSiscomRegProLPtrMemoria));
	  
}

int MensajeConexionExpendioTransferencia(SiscomRegistroProL *pSisRegProLPtrMemoria,
				         const char *pchrPtrCampo,
					 SiscomOperaciones *pSisOpePtrDato)
{
LogSiscom("Si se conecto a %s:%s",
	  SiscomObtenCampoRegistroProLChar("dirip",pSisRegProLPtrMemoria),
	  SiscomObtenCampoRegistroProLChar("puerto",pSisRegProLPtrMemoria));
return 0;
}



int ExpendioOrigenSinConexion(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
pSisOpePtrDato->SiscomRegProLPtrPrimRes=0;
SiscomFormaEnviaRegistroRespuesta(pSisOpePtrDato,
				  lchrArrBuffer,
				  "EdoConexion,Error,",
				  "1",
				  "Error , expendio origen sin conexion");

return 0;
}
int ExpendioDestinoSinConexion(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[128];
pSisOpePtrDato->SiscomRegProLPtrPrimRes=0;
SiscomFormaEnviaRegistroRespuesta(pSisOpePtrDato,
				  lchrArrBuffer,
				  "EdoConexion,Error,",
				  "1",
				  "Error , expendio destino sin conexion");
return 0;
}
