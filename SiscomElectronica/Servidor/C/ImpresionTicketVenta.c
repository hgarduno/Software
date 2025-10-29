#include <ImpresionTicketVenta.h>
#include <Cotizando4.h>
#include <TicketPedido.h>
#include <SqlImpresionTicketVenta.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>

#include <string.h>
#include <stdlib.h>
#include <cups/cups.h>
int gintTamanoBufferImpresion;
extern char gchrArrDirIpCliente[28]; 
void ImprimeTicketVenta4(int pintSocket,
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
SiscomAgregaOperacion(AgregaCampoFechaHora,&lSiscomProDat);
SiscomAgregaOperacion(AgregaCampoIdImpresion,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoImpresionTicket,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoImpresoras,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoDireccionExpendio,&lSiscomProDat);
SiscomAgregaOperacion(ArgumentoTelefonosExpendio,&lSiscomProDat);
SiscomAgregaOperacion(SqlImpresionTicket,&lSiscomProDat);
SiscomAgregaOperacion(SqlImpresionesTicket,&lSiscomProDat);
SiscomAgregaOperacion(SqlImpresionesTicketTotal,&lSiscomProDat);
SiscomAgregaOperacion(SqlImpresionTicketHistorial,&lSiscomProDat);
SiscomAgregaOperacion(SqlEnviaRegistroImpresionTicket,&lSiscomProDat); 
SiscomAgregaOperacion(SqlPuntosVentaImpresoras,&lSiscomProDat); 
SiscomAgregaOperacion(SqlDireccionExpendio,&lSiscomProDat); 
SiscomAgregaOperacion(SqlTelefonosExpendio,&lSiscomProDat); 
SiscomAgregaOperacion(ImprimiendoTicketVenta,&lSiscomProDat);
SiscomAgregaOperacion(0,&lSiscomProDat);
SiscomEjecutaProcesos(&lSiscomOpDat,0,lSiscomProDat);
}
int EsApartado(SiscomOperaciones *pSiscomOpePtrDato)
{
  return !SiscomComparaCampoAsociadoEntradaCadena("Envio","IdTipoOrden","2",pSiscomOpePtrDato);
}
int EsCotizacion(SiscomOperaciones *pSiscomOpePtrDato)
{
  return !SiscomComparaCampoAsociadoEntradaCadena("Envio","IdTipoOrden","1",pSiscomOpePtrDato);
}
int EsPedido(SiscomOperaciones *pSiscomOpePtrDato)
{
  return !SiscomComparaCampoAsociadoEntradaCadena("Envio","IdTipoOrden","4",pSiscomOpePtrDato);
}
int EsCancelacion(SiscomOperaciones *pSiscomOpePtrDato)
{
  return !SiscomComparaCampoAsociadoEntradaCadena("Envio","IdTipoOrden","5",pSiscomOpePtrDato);
}
int EsRegistroImpreso(SiscomOperaciones *pSiscomOpePtrDato)
{
  return !SiscomComparaCampoAsociadoEntradaCadena("Envio","IdTipoOrden","6",pSiscomOpePtrDato);
}

int SeImprimeTicketVenta(SiscomOperaciones *pSiscomOpePtrDato)
{

  return !SiscomComparaCampoAsociadoEntradaCadena("Envio","SeImprimeTicket","1",pSiscomOpePtrDato);
}
int EsMaterialAAreaDiseno(SiscomOperaciones *pSiscomOpePtrDato)
{
  return !SiscomComparaCampoAsociadoEntradaCadena("Envio","IdTipoOrden","8",pSiscomOpePtrDato);
}

int EsDonacionMaterial(SiscomOperaciones *pSiscomOpePtrDato)
{
return !SiscomComparaCampoAsociadoEntradaCadena("Envio","IdTipoOrden","9",pSiscomOpePtrDato);
}


void FormaTicketImpresionApartado(SiscomOperaciones *pSiscomOpePtrDato,
				  char **pchrPtrTicket)
{

}
int ImprimiendoTicketVenta(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrArchivo[4192];
char *lchrPtrTicket;
LOGOrden(pSiscomOpePtrDato);
FormaTicketImpresion(pSiscomOpePtrDato,&lchrPtrTicket);
EscribiendoArchivoImpresion(pSiscomOpePtrDato,lchrPtrTicket,lchrArrArchivo);
LogSiscom("\n\n  %s \n\n\n\n",lchrPtrTicket);
if(SeImprimeTicketVenta(pSiscomOpePtrDato)) 
{
EjecutaComandoImpresion4ConMensaje(pSiscomOpePtrDato,
				    lchrArrArchivo,
			           "Se imprimio el comprobante de %s");
}
return 0;
}

void NombreArchivoImpresion(SiscomOperaciones *pSiscomOpePtrDato,
			    char *pchrPtrArchivo)
{
sprintf(pchrPtrArchivo,
	"%s/ImpresionTickets/SiscomElectronica.%s",
	gSSiscomConfiguracionSvr.chrPtrDirTrabajo,
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato));
}
FILE *ArchivoImpresionTicket(SiscomOperaciones *pSiscomOpePtrDato,
			     const char *pchrPtrArchivo)
{
FILE *lFlePtrArchivo;
if((lFlePtrArchivo=fopen(pchrPtrArchivo,"w")))
return lFlePtrArchivo;
else
return 0;
}
void TicketAArchivo(SiscomOperaciones *pSiscomOpePtrDato,
		    const char *pchrPtrTicket,
		    const char *pchrPtrArchivo)
{
FILE *lFlePtrArchivo;

if((lFlePtrArchivo=ArchivoImpresionTicket(pSiscomOpePtrDato,pchrPtrArchivo)))
{
 fprintf(lFlePtrArchivo,"%s",pchrPtrTicket);
 fclose(lFlePtrArchivo);
}
else
LogSiscom("\n\n\n\n NO Se pudo abrir el archivo %s",pchrPtrArchivo);

}

void EjecutaComandoImpresion4ConMensaje(SiscomOperaciones *pSiscomOpePtrDato,
					const char *pchrPtrArchivo,
				        const char *pchrPtrMensaje)
{
 EjecutaComandoImpresion4(pSiscomOpePtrDato,pchrPtrArchivo);

}
void EjecutaComandoImpresion4(SiscomOperaciones *pSiscomOpePtrDato,
				const char *pchrPtrArchivo)
{
const char *lchrPtrImpresora;
int lintNumDests;;
cups_dest_t *lcupsPtrDestinos,*lcupsPtrDefault;
lintNumDests=cupsGetDests(&lcupsPtrDestinos);
lchrPtrImpresora=ObtenImpresoraParaTicket(pSiscomOpePtrDato);
if((lcupsPtrDefault=cupsGetDest(lchrPtrImpresora,0,lintNumDests,lcupsPtrDestinos))) 
{
cupsPrintFile(lcupsPtrDefault->name,
	      pchrPtrArchivo,
		pchrPtrArchivo,
		lcupsPtrDefault->num_options,
		lcupsPtrDefault->options);
}
else
LogSiscom("NO Se pudo Abrir el Archivo (%s)",pchrPtrArchivo);
}
void EscribiendoArchivoImpresion(SiscomOperaciones *pSiscomOpePtrDato,
				 const char *pchrPtrTicket,
				 char *pchrPtrArchivo)
{
FILE *lFlePtrArchivo;
  NombreArchivoImpresion(pSiscomOpePtrDato,pchrPtrArchivo);
  if((lFlePtrArchivo=ArchivoImpresionTicket(pSiscomOpePtrDato,pchrPtrArchivo)))
  {
    fprintf(lFlePtrArchivo,"%s",pchrPtrTicket);
    fclose(lFlePtrArchivo);
  }

}
void TotalTicketImpresion(SiscomOperaciones *pSiscomOpePtrDato,
			  char *pchrPtrTexto)
{
char lchrArrImporte[128];
sprintf(lchrArrImporte,
	"Importe Total               ---> %s",
	SiscomCampoAsociadoEntradaOperacion("Envio","Importe",pSiscomOpePtrDato));
strcat(pchrPtrTexto,lchrArrImporte);
}
void TextoSiguenosEnFacebook(char *pchrPtrTexto)
{
char lchrArrTexto[128];
sprintf(lchrArrTexto,
	"\n\nSiguenos en fb/siscomelectronica1\n");
strcat(pchrPtrTexto,lchrArrTexto);
}
void AgregaTextoDescripcionVenta(SiscomOperaciones *pSisOpePtrDato,
				  const char *pchrPtrDescripcion,
				 char *pchrPtrTexto)
{
char **lchrPtrRenglones;
char lchrArrBuffer[512];
char lchrArrNoCambios[256];
if(SiscomAnalizaCadenas(pchrPtrDescripcion,'\n',lchrArrBuffer,&lchrPtrRenglones))
{
   SiscomImprimeCadenas(lchrPtrRenglones);
   sprintf(lchrArrNoCambios,
	"\nNo se hacen cambios ni devoluciones"
	"\nEn dispositivos electronicos"
	"\nno hay GARANTIA\n\n");
   strcat(pchrPtrTexto,lchrArrNoCambios);
   strcat(pchrPtrTexto,"*******************\n");
   while(*lchrPtrRenglones)
   {
    sprintf(lchrArrBuffer,"%s\n",*lchrPtrRenglones); 
    strcat(pchrPtrTexto,lchrArrBuffer);
    LogSiscom("%s",lchrArrBuffer);
    lchrPtrRenglones++;
   }
   TextoRifa(pSisOpePtrDato,pchrPtrTexto);        
   strcat(pchrPtrTexto,"******************\n");
   sprintf(lchrArrBuffer,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
   strcat(pchrPtrTexto,lchrArrBuffer);
}
else
{
 LogSiscom("Solo es una linea");
}

}
int AgregandoTextoDescripcion(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrTexto)
{
const char *lchrPtrDescripcion;
if(EsCotizacion(pSiscomOpePtrDato))
{
   lchrPtrDescripcion=SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
   								  "Cotizacion",
								  "Descripcion",
								  pSiscomOpePtrDato);

}
else
lchrPtrDescripcion=SiscomCampoAsociadoEntradaOperacion("Envio","Descripcion",pSiscomOpePtrDato);
if(lchrPtrDescripcion)
AgregaTextoDescripcionVenta(pSiscomOpePtrDato,lchrPtrDescripcion,pchrPtrTexto);


return lchrPtrDescripcion ? 1 : 0;
}
void TextoNoSeHacenCambios(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrTexto)
{
char lchrArrNoCambios[256];
if(AgregandoTextoDescripcion(pSiscomOpePtrDato,pchrPtrTexto))
{

}
else
{
sprintf(lchrArrNoCambios,
	"\nNo se hacen cambios ni devoluciones"
	"\nEn dispositivos electronicos"
	"\nno hay GARANTIA"
	"\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
strcat(pchrPtrTexto,lchrArrNoCambios);
}
}
void TextoCotizacion(SiscomOperaciones *pSiscomOpePtrDato,
		     char *pchrPtrTexto)
{
char lchrArrBuffer[256];

}

void TextoRifa(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrTexto)
{
char lchrArrTexto[256];
 LogSiscom("Poniendo la fecha aqui");
 sprintf(lchrArrTexto,
 	 "\n%s\n",
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaHora",pSiscomOpePtrDato));
strcat(pchrPtrTexto,lchrArrTexto);
}
void FormaTicketImpresion(SiscomOperaciones *pSiscomOpePtrDato,
			  char **pchrPtrTextoImpresion)
{
FormaTextoTicket(pSiscomOpePtrDato,pchrPtrTextoImpresion);
FormaProductosTicket(pSiscomOpePtrDato,*pchrPtrTextoImpresion);
TotalTicketImpresion(pSiscomOpePtrDato,*pchrPtrTextoImpresion);
TextoSiguenosEnFacebook(*pchrPtrTextoImpresion);
TextoWhatsApp(pSiscomOpePtrDato,*pchrPtrTextoImpresion);
TextoNoSeHacenCambios(pSiscomOpePtrDato,*pchrPtrTextoImpresion);
}

int AgregaCampoFechaHora(SiscomOperaciones *pSiscomOpePtrDato)
{
SiscomAgregaCampoAsociadoEntrada("FechaHora",
				 (const char *)0,
				 "Envio",
				 pSiscomOpePtrDato);
SiscomAsignaFechaHoraAsociadoEntrada("Envio","FechaHora",pSiscomOpePtrDato);
return 0;
}

int AgregaCampoIdImpresion(SiscomOperaciones *pSiscomOpePtrDato)
{
const char *lchrPtrIdVenta;
SiscomAgregaCampoAsociadoEntrada("IdImpresion",
				 (const char *)0,
				 "Envio",
				 pSiscomOpePtrDato);

SiscomIdARegistrosAsociadosEntrada("Envio","IdImpresion",pSiscomOpePtrDato);
/*SiscomActualizaCampoAsociadoEntrada("Envio","IdImpresion",(char *)lchrPtrIdVenta,pSiscomOpePtrDato); */
return 0;
}
float ObtenRestaPago(SiscomOperaciones *pSiscomOpePtrDato)
{
float lfltRestaPago;
lfltRestaPago=SiscomCampoAsociadoEntradaOperacionFloat("Envio","Importe",pSiscomOpePtrDato)-
	  	SiscomCampoAsociadoAsociadoEntradaOperacionFloat("Envio",
						         "Apartado",
							 "ACuenta",
							 pSiscomOpePtrDato);

return lfltRestaPago;
}
const char *ObtenCelularCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
const char *lchrPtrTelefono;
SiscomRegistroProL *lSiscomRegProLPtrTelefono;
lSiscomRegProLPtrTelefono=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
								 "Cliente",
								 "Celular",
								 pSiscomOpePtrDato);
if(lSiscomRegProLPtrTelefono && 
  (lchrPtrTelefono=SiscomObtenCampoRegistroProLChar("Telefono",lSiscomRegProLPtrTelefono)))
 return lchrPtrTelefono;
else
return "Sin Telefono";

}
const char *ObtenObservacionesApartado(SiscomOperaciones *pSiscomOpePtrDato)
{

return SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Apartado","Observaciones",pSiscomOpePtrDato);
}

const char *ObtenCorreoCliente(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSiscomRegProLPtrTelefono;
if(lSiscomRegProLPtrTelefono=SiscomRegistrosCampoAsociadoAsociadoEntradaOperacion("Envio",
								 "Cliente",
								 "Correo",
								 pSiscomOpePtrDato))
return SiscomObtenCampoRegistroProLChar("Correo",lSiscomRegProLPtrTelefono);
else
return (const char *)"";
}
void AgregaTextoApartado(SiscomOperaciones *pSiscomOpePtrDato,
			 char *pchrPtrTextoApartado)
{
char lchrArrBuffer[1024];
const char *lchrPtrCorreo,
	   *lchrPtrObservaciones;
lchrPtrCorreo=(lchrPtrCorreo=ObtenCorreoCliente(pSiscomOpePtrDato)) ?  lchrPtrCorreo : "";
lchrPtrObservaciones=(lchrPtrObservaciones=ObtenObservacionesApartado(pSiscomOpePtrDato)) ? lchrPtrObservaciones : "";
sprintf(pchrPtrTextoApartado,
	"Recibo de Apartado No %s\n"
	"Nombre %s %s\n"
	"Fecha de Entrega: %s\n"
	"Quedando a cuenta %s\n"
	"Restando %.2f\n"
	"Observaciones\n%s\n\n"
	"Celular %s\n"
	"Correo  %s\n",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","Nombre",pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","APaterno",pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Apartado","FechaHoraE",pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Apartado","ACuenta",pSiscomOpePtrDato),
	ObtenRestaPago(pSiscomOpePtrDato),
	lchrPtrObservaciones,
	ObtenCelularCliente(pSiscomOpePtrDato),
	lchrPtrCorreo);
}
void AgregaTextoCotizacion(SiscomOperaciones *pSiscomOpePtrDato,
			char *pchrPtrTexto)
{
 sprintf(pchrPtrTexto,
 	"Cotizacion:%s",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato));
}
void AgregaTextoMaterialAAreaDiseno(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrTexto)
{
 sprintf(pchrPtrTexto,
 	"Material Area Diseno:%s\n\n\n"
	"%s",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","MaterialAAreaDiseno","Explicacion",pSiscomOpePtrDato));
}

void AgregaTextoDonacionMaterial(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrTexto)
{
 sprintf(pchrPtrTexto,
 	"Donacion de Material:%s\n\n\n"
	"%s",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","DonacionMaterial","Explicacion",pSiscomOpePtrDato));
}

const char *NumeroInterior(SiscomRegistroProL *pSiscomRegProLPtrDireccion)
{
const char *lchrPtrNumero;
char lchrArrRegreso[128];
lchrPtrNumero=SiscomObtenCampoRegistroProLChar("NumeroInt",pSiscomRegProLPtrDireccion);
if(lchrPtrNumero)
{
sprintf(lchrArrRegreso,"Num. Interior %s",lchrPtrNumero);
return strdup(lchrArrRegreso);
}
else
return "";


}
void AgregaTextoPedido(SiscomOperaciones *pSiscomOpePtrDato,
			char *pchrPtrTextoPedido)
{
char lchrArrDireccion[512];
const char *lchrPtrObservaciones;
FormaTextoDireccionEntrega(pSiscomOpePtrDato,lchrArrDireccion);
lchrPtrObservaciones=SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
								 "Pedido",
								 "Observaciones",
								 pSiscomOpePtrDato);

sprintf(pchrPtrTextoPedido,
	"Pedido Telefonico %s\n"
	"Nombre %s %s\n"
	"Fecha de Entrega %s\n"
	"Celular %s\n"
	"Correo  %s\n"
	"Se Paga Con %s\n"
	"%s\n"
	"Observaciones %s\n",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","Nombre",pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","APaterno",pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Pedido","FechaHoraE",pSiscomOpePtrDato),
	ObtenCelularCliente(pSiscomOpePtrDato),
	ObtenCorreoCliente(pSiscomOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Pedido","SePagaCon",pSiscomOpePtrDato),
	lchrArrDireccion,
	lchrPtrObservaciones ? lchrPtrObservaciones : "");

}
void AgregaTextoRegistroImpreso(SiscomOperaciones *pSiscomOpePtrDato,
			char *pchrPtrTextoPedido)
{
SiscomRegistroProL *lSiscomRegProLPtrCliente;
if((lSiscomRegProLPtrCliente=SiscomRegistroAsociadoEntradaOperacion("Envio",
								   "Cliente",
								   pSiscomOpePtrDato)))
sprintf(pchrPtrTextoPedido,
	"Programacion Circuito Impreso %s\n"
	"Nombre %s %s\n"
	"Pagado ***** %s ***** \n"
	"Fecha de Entrega *** %s ***\n"
	"Celular **** %s  ***\n"
	"Observaciones \n%s\n\n"
	"Archivo %s\n",
SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","Nombre",pSiscomOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","APaterno",pSiscomOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","CircuitoImpreso","Pagado",pSiscomOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","CircuitoImpreso","FechaHoraEntrega",pSiscomOpePtrDato),
ObtenCelularCliente(pSiscomOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","CircuitoImpreso","Memoria",pSiscomOpePtrDato),
SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","CircuitoImpreso","Archivo",pSiscomOpePtrDato));
LogSiscom("El Texto (%s)",pchrPtrTextoPedido);
}

void GeneraTextoNoOrden(SiscomOperaciones *pSiscomOpePtrDato,
			 char *pchrPtrTexto)
{
sprintf(pchrPtrTexto,
	"No Orden:%s",
	SiscomCampoAsociadoEntradaOperacion("Envio","IdVenta",pSiscomOpePtrDato));
}
void FormaTextoEncabezadoTicket(SiscomOperaciones *pSiscomOpePtrDato,
				char *pchrPtrTexto)
{

char lchrArrTextoOrden[1024];
if(EsApartado(pSiscomOpePtrDato))
AgregaTextoApartado(pSiscomOpePtrDato,lchrArrTextoOrden);
else
if(EsCotizacion(pSiscomOpePtrDato))
AgregaTextoCotizacion(pSiscomOpePtrDato,lchrArrTextoOrden);
else
if(EsPedido(pSiscomOpePtrDato))
AgregaTextoPedido(pSiscomOpePtrDato,lchrArrTextoOrden);
else
if(EsRegistroImpreso(pSiscomOpePtrDato))
AgregaTextoRegistroImpreso(pSiscomOpePtrDato,lchrArrTextoOrden);
else
if(EsMaterialAAreaDiseno(pSiscomOpePtrDato))
AgregaTextoMaterialAAreaDiseno(pSiscomOpePtrDato,lchrArrTextoOrden);
else
if(EsDonacionMaterial(pSiscomOpePtrDato))
AgregaTextoDonacionMaterial(pSiscomOpePtrDato,lchrArrTextoOrden);
else
GeneraTextoNoOrden(pSiscomOpePtrDato,lchrArrTextoOrden);
sprintf(pchrPtrTexto,
	"\n"
	"SISCOM Electronica\n"
	"%s #%s\n"
	"Colonia %s\n"
	"Delegacion %s \n"
	"%s \n"
	"Telefono:%s\n"
	"Fecha %s \n"
	"%s\n"
	"%s\n"
	"%-11s"
	"%-13s"
	"%-9s"
	"%-7s\n",
	SiscomCampoArgumentoPrim("SqlDirExpendio","calle",pSiscomOpePtrDato),
	SiscomCampoArgumentoPrim("SqlDirExpendio","numero",pSiscomOpePtrDato),
	SiscomCampoArgumentoPrim("SqlDirExpendio","colonia",pSiscomOpePtrDato),
	SiscomCampoArgumentoPrim("SqlDirExpendio","municipio",pSiscomOpePtrDato),
	SiscomCampoArgumentoPrim("SqlDirExpendio","estado",pSiscomOpePtrDato),
	TelefonoExpendio(pSiscomOpePtrDato),
	SiscomCampoAsociadoEntradaOperacion("Envio","FechaHora",pSiscomOpePtrDato),
	lchrArrTextoOrden,
	"",
	"Cantidad",
	"Producto",
	"Precio",
	"Importe");
}
char *AsignaMemoriaTicket(SiscomOperaciones *pSiscomOpePtrDato)
{
char *lchrPtrRegreso;
int lintTamanoBuffer,lintTamanoTextoApartado;
lintTamanoBuffer=TamanoBufferImpresion4(pSiscomOpePtrDato);
lintTamanoTextoApartado=(EsApartado(pSiscomOpePtrDato)  || 
		        EsPedido(pSiscomOpePtrDato)     ||
			EsRegistroImpreso(pSiscomOpePtrDato))   ? 256 :0 ;
gintTamanoBufferImpresion=lintTamanoBuffer + lintTamanoTextoApartado+128;
lchrPtrRegreso=(char *)malloc(gintTamanoBufferImpresion);
return lchrPtrRegreso;
}
void FormaTextoTicket(SiscomOperaciones *pSiscomOpePtrDato,
		     char **pchrPtrTexto)
{
*pchrPtrTexto=AsignaMemoriaTicket(pSiscomOpePtrDato);
FormaTextoEncabezadoTicket(pSiscomOpePtrDato,*pchrPtrTexto);
}
int TamanoBufferImpresion4(SiscomOperaciones *pSiscomOpePtrDato)
{
int lintTamRegistro=5	+ /* Cantidad */
  		    5	+ /*Importe   */
		    5	+ /*Num Juegos*/
		    50	+ /*CveProducto*/
		    5	+ /*Precio*/
		    4	+ /*Cliente Frecuente*/
		    5	+ /*No Orden*/
		    20	 /*Nombre Cliente*/ 
		    ;
int lintNoProductos;
lintNoProductos=SiscomNoRegistrosAsociado("Envio","Productos",pSiscomOpePtrDato);
return 256+
	(lintTamRegistro*lintNoProductos)+
	512;
}
void FormaRegistroImpresion(SiscomRegistroProL *pSiscomRegProLPtrDato,
			    float pfltJuegos,
			    char *pchrPtrRegistro)
{
float lfltCantidad;
char lchrArrCantidad[28];
lfltCantidad=SiscomObtenCampoRegistroProLFloat("Cantidad",pSiscomRegProLPtrDato)*
	     pfltJuegos;
sprintf(lchrArrCantidad,"%.2f",lfltCantidad);
sprintf(pchrPtrRegistro,
	"%-11s%-13s%-9s%-7s\n",
	lchrArrCantidad,
	SiscomObtenCampoRegistroProLChar("Clave",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Precio",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("Importe",pSiscomRegProLPtrDato));
}
void FormaRegistroImpresionDefinicionProducto(SiscomRegistroProL *pSiscomRegProLPtrDato,
			    char *pchrPtrRegistro)
{
sprintf(pchrPtrRegistro,
	"%-11s%-13s%-9s%-7s\n",
	SiscomObtenCampoRegistroProLChar("cantidad",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("cveproducto",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("precio",pSiscomRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("importe",pSiscomRegProLPtrDato));
}
void ReAsignaMemoriaTicketImpresion(char *pchrPtrRegistro,
				    char *pchrPtrTexto)
{
int lintTamano;
lintTamano=gintTamanoBufferImpresion +
	   strlen(pchrPtrTexto);
pchrPtrTexto=(char *)realloc(pchrPtrTexto,lintTamano);
}
						
void AgregaImpresionDefinicionProducto(SiscomRegistroProL *pSiscomRegProLPtrProducto,
				       char *pchrPtrTexto)
{
SiscomRegistroProL *lSiscomRegProLPtrDefProducto;
char lchrArrBuffer[1024],
	lchrArrRegistro[256];
lSiscomRegProLPtrDefProducto=SiscomObtenRegistrosCampoProL("Productos",pSiscomRegProLPtrProducto);

SiscomRegistroProtocoloLog(lchrArrBuffer,lSiscomRegProLPtrDefProducto);
for(;
    lSiscomRegProLPtrDefProducto;
    lSiscomRegProLPtrDefProducto=lSiscomRegProLPtrDefProducto->SiscomRegProLPtrSig)
{
   FormaRegistroImpresionDefinicionProducto(lSiscomRegProLPtrDefProducto,lchrArrRegistro);
   ReAsignaMemoriaTicketImpresion(lchrArrRegistro,pchrPtrTexto);
   strcat(pchrPtrTexto,lchrArrRegistro);
}

}
void FormaProductosTicket(SiscomOperaciones *pSiscomOpePtrDato,
			  char *pchrPtrTexto)
{
SiscomRegistroProL *lSiscomRegProLPtrProductos;
char lchrArrRegistro[256];
float lfltJuegos;
if((lSiscomRegProLPtrProductos=SiscomRegistrosAsociadosCampoEntrada("Envio",
								    "Productos",
								    pSiscomOpePtrDato)))
{
lfltJuegos=SiscomCampoAsociadoEntradaOperacionFloat("Envio","Juegos",pSiscomOpePtrDato);
for(;
     lSiscomRegProLPtrProductos;
     lSiscomRegProLPtrProductos=lSiscomRegProLPtrProductos->SiscomRegProLPtrSig)
{
FormaRegistroImpresion(lSiscomRegProLPtrProductos,lfltJuegos,lchrArrRegistro);
strcat(pchrPtrTexto,lchrArrRegistro);
if(!NoEsProducto(lSiscomRegProLPtrProductos) && 
  (!EsCircuitoImpreso(lSiscomRegProLPtrProductos) &&
   !EsProductoSiscom(lSiscomRegProLPtrProductos)))
AgregaImpresionDefinicionProducto(lSiscomRegProLPtrProductos,pchrPtrTexto);
}
}
}

int ArgumentoImpresionTicket(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlImpresionTicket",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}

int ArgumentoImpresoras(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlImpresoras",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}

int ArgumentoDireccionExpendio(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlDirExpendio",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}

int ArgumentoTelefonosExpendio(SiscomOperaciones *pSiscomOpePtrDato)
{
char lchrArrBuffer[128];
SiscomAgregaArgumentoInsercionSql("SqlTelefonos",
				  pSiscomOpePtrDato->chrArrBaseDatos,
				  pSiscomOpePtrDato->chrArrPuertoBaseDatos,
				  lchrArrBuffer,
				  pSiscomOpePtrDato);
return 0;
}
const char *ObtenImpresoraParaTicket(SiscomOperaciones *pSiscomOpePtrDatos)
{
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrImpresoras;

if((lSisRegProLPtrImpresoras=SiscomObtenArgumentoPrimOperaciones("SqlImpresoras",pSiscomOpePtrDatos)))
{
  for( ;lSisRegProLPtrImpresoras;
  	lSisRegProLPtrImpresoras=lSisRegProLPtrImpresoras->SiscomRegProLPtrSig)
  {
      if(!SiscomComparaCadenaCampoRegistroProL(gchrArrDirIpCliente,
      					       "direccionip",
					       lSisRegProLPtrImpresoras))
      {
	LogSiscom("Se Envia a la impresora");
	return SiscomObtenCampoRegistroProLChar("impresora",lSisRegProLPtrImpresoras);
      }
  }
}
return 0;
}
const char *ObtenTelefonoPorDepartamento(SiscomOperaciones *pSiscomOpePtrDato,
					 const char *pchrPtrDepartamento)
{
SiscomRegistroProL *lSisRegProLPtrTelefonos;
lSisRegProLPtrTelefonos=SiscomObtenArgumentoPrimOperaciones("SqlTelefonos",pSiscomOpePtrDato);
for(;lSisRegProLPtrTelefonos;lSisRegProLPtrTelefonos=lSisRegProLPtrTelefonos->SiscomRegProLPtrSig)
{
 if(!SiscomComparaCadenaCampoRegistroProL(pchrPtrDepartamento,
 					  "departamenteo",
					  lSisRegProLPtrTelefonos))
 return SiscomObtenCampoRegistroProLChar("telefono",lSisRegProLPtrTelefonos);
}
return 0;


}
const char *TelefonoExpendio(SiscomOperaciones *pSiscomOpePtrDato)
{
/*
char lchrArrBuffer[128];
SiscomRegistroProL *lSisRegProLPtrTelefonos;
lSisRegProLPtrTelefonos=SiscomObtenArgumentoPrimOperaciones("SqlTelefonos",pSiscomOpePtrDato);
for(;lSisRegProLPtrTelefonos;lSisRegProLPtrTelefonos=lSisRegProLPtrTelefonos->SiscomRegProLPtrSig)
{
 if(!SiscomComparaCadenaCampoRegistroProL("Expendio","departamenteo",lSisRegProLPtrTelefonos))
 return SiscomObtenCampoRegistroProLChar("telefono",lSisRegProLPtrTelefonos);
}
return "5557540823";
*/
const char *lchrPtrTelefono;
if((lchrPtrTelefono=ObtenTelefonoPorDepartamento(pSiscomOpePtrDato,"Expendio")))
return lchrPtrTelefono;
else
return "5557540823";
}
const char *ObtenTelefonoWhats(SiscomOperaciones *pSiscomOpePtrDato)
{
    return ObtenTelefonoPorDepartamento(pSiscomOpePtrDato,"Whats");
}
void TextoWhatsApp(SiscomOperaciones *pSiscomOpePtrDato,char *pchrPtrTextoImpresion)
{
const char *lchrPtrWhats;
char lchrArrTextoWhats[256];
 if((lchrPtrWhats=ObtenTelefonoWhats(pSiscomOpePtrDato)))
 {
     sprintf(lchrArrTextoWhats,
     	 "\n**************************"
	 "\nCotiza en Linea Whats App"
	 "\n%s"
	 "\n**************************",
	 lchrPtrWhats);
	 strcat(pchrPtrTextoImpresion,lchrArrTextoWhats);
 }

}
