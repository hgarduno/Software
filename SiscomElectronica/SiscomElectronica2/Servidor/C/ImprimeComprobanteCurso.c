#include <ImprimeComprobanteCurso.h>
#include <ServidorGeneral.h>
#include <cups/cups.h>
SiscomOperaciones2 *OpImprimeComprobanteCurso()
{
SiscomOperaciones2 *lSOpOperaciones;
SiscomMemoriaOperaciones2(120,&lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(SiscomLeeEntradaOperaciones2,lSOpOperaciones);
SiscomAnexaOperacionAlArreglo2(ImprimeComprobanteCurso,lSOpOperaciones);
return lSOpOperaciones;
}

void ImprimeComprobanteCurso(SArgsSiscom *pSAgsSiscom)
{
char lchrArrTextoTicket[512];
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
TextoTicketPagoCurso(pSAgsSiscom,lchrArrTextoTicket);
ImprimiendoTicketPagoCurso(lchrArrTextoTicket);
SiscomLog("%s",lchrArrTextoTicket);
}


void ArchivoTemporalTicketPagoCurso(
		     const char *pchrPtrTexto,
		     char *pchrPtrArchivo)
{
FILE *lptrFleTemporal;
sprintf(pchrPtrArchivo,
	"%s/ImpresionTickets/TicketPagoCurso.SiscomElectronica.%d",
	gSSiscomConfiguracionSvr.chrPtrDirTrabajo,
	getpid());
if((lptrFleTemporal=fopen(pchrPtrArchivo,"w")))
{
fprintf(lptrFleTemporal,"%s",pchrPtrTexto);
fclose(lptrFleTemporal);
}
else
SiscomLog("No se pudo crear el archivo:%s",pchrPtrArchivo);

}
void ImprimiendoTicketPagoCurso(const char *pchrPtrTexto)
{
char lchrArrArchivo[256];
char lchrCaracter;
int lintNumDests;;
cups_dest_t *lcupsPtrDestinos,*lcupsPtrDefault;
lintNumDests=cupsGetDests(&lcupsPtrDestinos);
if((lcupsPtrDefault=cupsGetDest(0,0,lintNumDests,lcupsPtrDestinos))) 
{
ArchivoTemporalTicketPagoCurso(pchrPtrTexto,lchrArrArchivo);
cupsPrintFile(lcupsPtrDefault->name,
	      lchrArrArchivo,
		lchrArrArchivo,
		lcupsPtrDefault->num_options,
		lcupsPtrDefault->options);
}
else
SiscomLog("No se ha configurado la impresora por default");
}
/*
const char *SiscomObtenDatoBaseDatos(LCamposSiscomPro2 *pLCSiscomPro2Dat,
					    const char *pchrPtrNmbCampo,
					    const char *pchrPtrCampoBaseDatos)
{
const char *lchrPtrRegreso;
lchrPtrRegreso=SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrNmbCampo);
if(!strcmp(lchrPtrRegreso,"Campo No Encontrado"))
return SiscomObtenDato(pLCSiscomPro2Dat,pchrPtrCampoBaseDatos);
else
return lchrPtrRegreso;

}
*/
void TextoTicketPagoCurso(SArgsSiscom *pSAgsSiscom,char *pchrPtrTexto)
{
char lchrArrFecha[11];
int lintHora,
	lintMinuto,
	lintSegundo;

SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
SiscomObtenHoraActual(&lintHora,&lintMinuto,&lintSegundo);
sprintf(pchrPtrTexto,
	"\n"
	"SISCOM Electronica\n"
	"A.v. I.P.N. #2085\n"
	"Colonia San Pedro Zacatenco\n"
	"Delegacion Gustavo A. Madero\n"
	"Mexico D.F.\n"
	"Telefono:57540823\n"
	"Fecha %s Hora %02d:%02d:%02d\n"
	"Alumno:%s %s %s\n"
	"Correo:%s\n"
	"Telefono:%s\n"
	"Curso:%s\n"
	"Costo:%s\n"
	"Fecha Inicio:%s Hora Inicio:%s\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n",
	lchrArrFecha,
	lintHora,
	lintMinuto,
	lintSegundo,
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Nombre"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"APaterno"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"AMaterno"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Correo"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Telefono"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Curso"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Costo"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"fecha"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"HoraInicio"));
}
