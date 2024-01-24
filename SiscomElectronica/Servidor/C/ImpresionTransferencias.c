#include <ImpresionTransferencias.h>
#include <ImpresionTicketVenta.h>
#include <SqlTransferenciasExpendioAExpendio.h>

#include <TransferenciasExpendioAExpendio.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void ImprimePedidoOtrosExpendios(int pintSocket,
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
SiscomAgregaOperacion(ImprimiendoOtrosExpendios,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int ImprimiendoOtrosExpendios(SiscomOperaciones *pSiscomOpePtrDato)
{
char *lchrPtrTextoImpresion;
char lchrArrBuffer[128],
	lchrArrArchivo[1024];
ArchivoTransferenciaExpendioAExpendio(pSiscomOpePtrDato,lchrArrArchivo);
FormaTextoImprimiendoOtrosExpendios(pSiscomOpePtrDato,&lchrPtrTextoImpresion);
EscribiendoArchivoTicketTransferencia(lchrArrArchivo,lchrPtrTextoImpresion);
EjecutaComandoImpresion4(pSiscomOpePtrDato,lchrArrArchivo);
}
void EscribiendoArchivoTicketTransferencia(const char *pchrPtrArchivo,
					   char *pchrPtrTextoImpresion)
{
FILE *lFlePtrArchivo;
if((lFlePtrArchivo=ArchivoImpresionTicket(0,pchrPtrArchivo)))
{
 LogSiscom("El ticket de la transferencia  \n\n\n\n\n\n\n %s \n\n\n\n%s ",
 	  pchrPtrArchivo,
 	   pchrPtrTextoImpresion);
  fprintf(lFlePtrArchivo,"%s",pchrPtrTextoImpresion);
  fclose(lFlePtrArchivo);
}
else
LogSiscom("Error al abrir el archivo\n\n\n\n\n\n %s \n\n\n\n %s",
	  pchrPtrArchivo,
	  pchrPtrTextoImpresion);
}
void FormaTextoImprimiendoOtrosExpendios(SiscomOperaciones *pSiscomOpePtrDato,
				         char **pchrPtrTexto)
{
char *lchrPtrTextoProducto;
int lintTamano;
  TextoEncabezadoImprimiendoOtrosExpendios(pSiscomOpePtrDato,pchrPtrTexto);
  TextoProductosImprimiendoOtrosExpendios(pSiscomOpePtrDato,&lchrPtrTextoProducto);
  lintTamano=strlen(*pchrPtrTexto)+strlen(lchrPtrTextoProducto)	+
  	     2							+
	     18 /* Los saltos de linea para sacar el ticket */;
  *pchrPtrTexto=(char *)realloc(*pchrPtrTexto,lintTamano);
  strcat(*pchrPtrTexto,"\n");
  strcat(*pchrPtrTexto,lchrPtrTextoProducto);
  strcat(*pchrPtrTexto,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
int AsignandoYCopiando(int pintContador,
			const char *pchrPtrCadena,
			char **pchrPtrTexto)
{
int lintNuevoTamano;
   if(!pintContador)
   {
    *pchrPtrTexto=(char *)malloc(strlen(pchrPtrCadena));
    strcpy(*pchrPtrTexto,pchrPtrCadena);
   }
   else
   {
     lintNuevoTamano=strlen(*pchrPtrTexto);
     lintNuevoTamano+=strlen(pchrPtrCadena);
     *pchrPtrTexto=(char *)realloc(*pchrPtrTexto,lintNuevoTamano+1);
      strcat(*pchrPtrTexto,"\n");
     strcat(*pchrPtrTexto,pchrPtrCadena);
   }

return ++pintContador;
}
void TextoProductosImprimiendoOtrosExpendios(SiscomOperaciones *pSiscomOpePtrDato,
					     char **pchrPtrTexto)
{
int lintContador=0;
char lchrArrPaso[128];
SiscomRegistroProL *lSisRegProLPtrProducto;

lSisRegProLPtrProducto=SiscomRegistrosAsociadoRespuestaOperacion("Productos",pSiscomOpePtrDato);

for(;
    lSisRegProLPtrProducto;
    lSisRegProLPtrProducto=lSisRegProLPtrProducto->SiscomRegProLPtrSig)
{
 
 sprintf(lchrArrPaso,
 	 "%s\t%s",
	 SiscomObtenCampoRegistroProLChar("cantidad",lSisRegProLPtrProducto),
	 SiscomObtenCampoRegistroProLChar("cveproducto",lSisRegProLPtrProducto));
  lintContador=AsignandoYCopiando(lintContador,lchrArrPaso,pchrPtrTexto);
}

}
void TextoEncabezadoImprimiendoOtrosExpendios(SiscomOperaciones *pSiscomOpePtrDato,
					      char **pchrPtrTexto)
{
*pchrPtrTexto=(char *)malloc(1024);
sprintf(*pchrPtrTexto,
	"\n"
	"SISCOM Electronica\n"
	"A.v. I.P.N. #2085\n"
	"Colonia San Pedro Zacatenco\n"
	"Delegacion Gustavo A. Madero\n"
	"Mexico D.F.\n"
	"Telefono:57540823\n"
	"Fecha %s \n"
	"Expendio Origen %s\n"
	"Expendio Destino %s\n\n"
	"%-11s"
	"%-13s",
	SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSiscomOpePtrDato),
	SiscomCampoAsociadoRespuesta("Productos","origen",pSiscomOpePtrDato),
	SiscomCampoAsociadoRespuesta("Productos","destino",pSiscomOpePtrDato),
	"Cantidad",
	"Producto");
}
void ArchivoTransferenciaExpendioAExpendio(SiscomOperaciones *pSiscomOpePtrDato,
					  char *pchrPtrArchivo)
{
sprintf(pchrPtrArchivo,
	"%s/ImpresionTickets/SiscomElectronica.Pedido.Expendio.%s",
	gSSiscomConfiguracionSvr.chrPtrDirTrabajo,
	SiscomCampoAsociadoRespuesta("Productos","idtransferencia",pSiscomOpePtrDato));
}
