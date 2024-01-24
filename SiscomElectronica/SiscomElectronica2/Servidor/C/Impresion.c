#include <Impresion.h>
#include <SqlImpresion.h>
#include <ComunElectronica2.h>
#include <ServidorGeneral.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <cups/cups.h>
SiscomOperaciones2 *OpImprimeTicketVenta()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ComunicacionExpendioRegistra,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ArgumentosTicketVenta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlTicketYaRegistrado,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaTicketImpreso,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaTicketImpresoTotal,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SqlInsertaTicketImpresoHistorial,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ImprimeTicketVenta,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(RegistraTicketVenta,lSOpOperaciones);
return lSOpOperaciones;
}
int TamanoBufferImpresion(const SArgsSiscom *pSAgsSiscom)
{
/*
 * Cade cantidad representa el numero 
 * de bytes que se asignaran a cada campo
 *
 */
int lintTamRegistro=5	+ /* Cantidad */
  		    5	+ /*Importe   */
		    5	+ /*Num Juegos*/
		    50	+ /*CveProducto*/
		    5	+ /*Precio*/
		    4	+ /*Cliente Frecuente*/
		    5	+ /*No Orden*/
		    20	 /*Nombre Cliente*/ 
		    ;
return 256+
	(lintTamRegistro*pSAgsSiscom->intNRegistrosDat)+
	256; /* Domingo 31 De Julio 
	      * Se agrego espacio para la leyenda de puntos 
	      * Siscom Electronica
	      */
}
void ArchivoTemporal(const char *pchrPtrNoOrden,
		     const char *pchrPtrTexto,
		     char *pchrPtrArchivo)
{
FILE *lptrFleTemporal;
sprintf(pchrPtrArchivo,
	"%s/ImpresionTickets/Impresion.SiscomElectronica.%s",
	gSSiscomConfiguracionSvr.chrPtrDirTrabajo,
	pchrPtrNoOrden);
if((lptrFleTemporal=fopen(pchrPtrArchivo,"w")))
{
fprintf(lptrFleTemporal,"%s",pchrPtrTexto);
fclose(lptrFleTemporal);
}
else
SiscomLog("No se pudo crear el archivo:%s",pchrPtrArchivo);

}
void EjecutaComandoImpresion(const char *pchrPtrNoOrden,
			     const char *pchrPtrTexto,
			     int pintTamBuffer)
{
char lchrArrArchivo[256];
char lchrCaracter;
int lintNumDests;;
cups_dest_t *lcupsPtrDestinos,*lcupsPtrDefault;
lintNumDests=cupsGetDests(&lcupsPtrDestinos);
if((lcupsPtrDefault=cupsGetDest(0,0,lintNumDests,lcupsPtrDestinos))) 
{
ArchivoTemporal(pchrPtrNoOrden,pchrPtrTexto,lchrArrArchivo);
cupsPrintFile(lcupsPtrDefault->name,
	      lchrArrArchivo,
		lchrArrArchivo,
		lcupsPtrDefault->num_options,
		lcupsPtrDefault->options);
}
else
SiscomLog("No se ha configurado la impresora por default");
}


void ImprimeTicketVenta(SArgsSiscom *pSAgsSiscom)
{
char *lchrPtrImpresion;
int lintTamBuffer;
SiscomLog("Se Imprimiran:%d",pSAgsSiscom->intNRegistrosDat);
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
lchrPtrImpresion=TextoImpresion(pSAgsSiscom,&lintTamBuffer);
SiscomLog("%s",lchrPtrImpresion);
EjecutaComandoImpresion(
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"NoOrden"),
	lchrPtrImpresion,
	lintTamBuffer);
	
}
void RegistraTicketVenta(SArgsSiscom *pSAgsSiscom)
{
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
SiscomImprimeArgumento("SqlTicketImpreso",pSAgsSiscom);
SiscomEnviaServidorArgumento(pSAgsSiscom,"SqlTicketImpreso");
}
void FormaRegistroImpresion(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			    char *pchrPtrRegistro)
{
float lfltCantidad=atof(SiscomObtenDato(pLCSiscomPro2Dat,"Cantidad"))*
		 atof(SiscomObtenDato(pLCSiscomPro2Dat,"NumJuegos"));
char lchrArrCantidad[10];
sprintf(lchrArrCantidad,"%d",(int )lfltCantidad);
sprintf(pchrPtrRegistro,
	"%-11s%-13s%-9s%-7s\n",
	lchrArrCantidad,
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Precio"),
	SiscomObtenDato(pLCSiscomPro2Dat,"Importe"));
}
void TextoClienteFrecuente(SArgsSiscom *pSAgsSiscom,
			   char *pchrPtrTexto)
{
if(!strcmp(SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"ClienteFrecuente"),"Si"))
{
sprintf(pchrPtrTexto,
	"\n%s!!!, tienes el %s%% de descuento\n"
	"Por ser cliente frecuente, GRACIAS\n",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"NmbCliente"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2DatUltimo,"PorDescuento"));

}
else
strcpy(pchrPtrTexto,"\n");	



}
void Encabezado(SArgsSiscom *pSAgsSiscom,
		char *pchrPtrTexto)
{
char lchrArrFecha[11];
char lchrArrTextoClienteF[256];
int lintHora,
	lintMinuto,
	lintSegundo;

SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
SiscomObtenHoraActual(&lintHora,&lintMinuto,&lintSegundo);
TextoClienteFrecuente(pSAgsSiscom,lchrArrTextoClienteF);
sprintf(pchrPtrTexto,
	"\n"
	"SISCOM Electronica\n"
	"A.v. I.P.N. #2085\n"
	"Colonia San Pedro Zacatenco\n"
	"Delegacion Gustavo A. Madero\n"
	"Mexico D.F.\n"
	"Telefono:57540823\n"
	"Fecha %s Hora %02d:%02d:%02d\n"
	"No De Orden %s"
	"%s"
	"%-11s"
	"%-13s"
	"%-9s"
	"%-7s\n",
	lchrArrFecha,
	lintHora,
	lintMinuto,
	lintSegundo,
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"NoOrden"),
	lchrArrTextoClienteF,
	"Cantidad",
	"Producto",
	"Precio",
	"Importe");
}
void RegistrosImpresion(SArgsSiscom *pSAgsSiscom,	
			char *pchrPtrTexto)
{
char lchrArrRegistro[256];
LCamposSiscomPro2 *lLCSiscomPro2Dat;
lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
while(lLCSiscomPro2Dat!=pSAgsSiscom->LCSiscomPro2DatUltimo)
{
  FormaRegistroImpresion(lLCSiscomPro2Dat,lchrArrRegistro);
  strcat(pchrPtrTexto,lchrArrRegistro);
  lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig;
}
}
void TotalOrden(SArgsSiscom *pSAgsSiscom,
		char *pchrPtrTexto)
{
char lchrArrTotal[256];
sprintf(lchrArrTotal,
	"Importe Total               ---> %s",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2DatUltimo,"Importe"));
strcat(pchrPtrTexto,lchrArrTotal);
}
void TextoNoCambios(char *pchrPtrTexto)
{
char lchrArrNoCambios[256];
sprintf(lchrArrNoCambios,
	"\nNo se hacen cambios ni devoluciones"
	"\nEn dispositivos electronicos"
	"\nno hay GARANTIA"
	"\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
strcat(pchrPtrTexto,lchrArrNoCambios);
}
/* Domingo 31 De Julio  2011
 * Se agrego el manejo de los puntos y promociones en 
 * los tickets 
 */
void TextoPuntosPromociones(SArgsSiscom *pSAgsSiscom,
			    char *pchrPtrTexto)
{
char lchrArrPuntosPromociones[256];
const char *lchrPtrPuntosCliente;
const char *lchrPtrNmbCliente;
lchrPtrPuntosCliente=SiscomCampoDatosEntrada("PuntosCliente",pSAgsSiscom);
lchrPtrNmbCliente=SiscomCampoDatosEntrada("NmbCliente",pSAgsSiscom);
if(lchrPtrNmbCliente &&
   strcmp(lchrPtrNmbCliente,"Publico En General") &&
   lchrPtrPuntosCliente  &&
   *lchrPtrPuntosCliente &&
   atoi(lchrPtrPuntosCliente)>0)
{
sprintf(lchrArrPuntosPromociones,
	"\n\n%s !!!!"
	"\nHas acumulado  %s Puntos Siscom"
	"\nque puedes canjear por %s promociones"
	"\n\n",
	lchrPtrNmbCliente,
	SiscomCampoDatosEntrada("PuntosCliente",pSAgsSiscom),
	SiscomCampoDatosEntrada("Promociones",pSAgsSiscom));
strcat(pchrPtrTexto,lchrArrPuntosPromociones);
}
}
char *TextoImpresion(SArgsSiscom *pSAgsSiscom,
		     int *pintPtrTamBuffer)
{
*pintPtrTamBuffer=TamanoBufferImpresion(pSAgsSiscom);
char *lchrPtrImpresion;
lchrPtrImpresion=(char *)malloc(*pintPtrTamBuffer);
Encabezado(pSAgsSiscom,lchrPtrImpresion);
RegistrosImpresion(pSAgsSiscom,lchrPtrImpresion);
TotalOrden(pSAgsSiscom,lchrPtrImpresion);
TextoPuntosPromociones(pSAgsSiscom,lchrPtrImpresion);
TextoNoCambios(lchrPtrImpresion);
return lchrPtrImpresion;
}

void ArgumentosTicketVenta(SArgsSiscom *pSAgsSiscom)
{
  SiscomAsignaMemoriaArgumentosOperaciones(1,pSAgsSiscom);
  SiscomIniciaMemoriaArgumentoOperacion(0,"SqlTicketImpreso",pSAgsSiscom);
}
