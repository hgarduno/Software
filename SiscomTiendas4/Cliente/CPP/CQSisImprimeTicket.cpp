#include <CQSisImprimeTicket.h>
#include <CQSisOrdenes.h>
#include <CQSisClientes.h>
#include <CQSisProdCotiza.h>
#include <CQSisProductos.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

CQSisImprimeTicket::CQSisImprimeTicket(
			CQSisLstProdCotiza *pCQSLPCotiza,
			CQSisCliente *pCQSCliente,
			CQSisOrden *pCQSOrden):
			CQSLPCotiza(pCQSLPCotiza),
			CQSCliente(pCQSCliente),
			CQSOrden(pCQSOrden),
			intSeImprime(0)
{
AbreArchivo();
if(intSeImprime)
{
LeeArchivoTicket();
ObtenDatosNegocio();
ImprimeDatosNegocio();
ImprimeFechaHora();
ImprimeNoOrden();
ImprimeDetalleOrden();
ImprimeTotalOrden();
fclose(FleArchivo);
ImprimeTicket();
}

}
CQSisImprimeTicket::~CQSisImprimeTicket()
{
}
void CQSisImprimeTicket::AbreArchivo()
{
sprintf(chrArrArchivo,"%s/.SiscomImpresionTiendas4",getenv("HOME"));
if(!(FleArchivo=fopen(chrArrArchivo,"w")))
{
printf("No se pudo crear el archivo:%s Para imprimir",chrArrArchivo);
intSeImprime=0;
}
else
intSeImprime=1;
}
void CQSisImprimeTicket::ImprimeTicket()
{

   if(!fork())
    execl("/usr/bin/lpr","lpr",chrArrArchivo,0);
    ::wait(0);
}
void CQSisImprimeTicket::ImprimeDatosNegocio()
{
   fprintf(FleArchivo,"Chiles y Semillas Zuniga\n");
   fprintf(FleArchivo,"Los unicos que hacemos pedazos al chile\n");
   fprintf(FleArchivo,"Insurgentes #58\n");
   fprintf(FleArchivo,"Visitacion Estado De Mexico\n");
   fprintf(FleArchivo,"Telefono:58782631\n");
   fprintf(FleArchivo,"molinozuniga@prodigy.com.mx\n\n");
   	
}
void CQSisImprimeTicket::ImprimeFechaHora()
{
char lchrArrFecha[15],
     lchrArrHora[15];
     SiscomObtenHoraActualChar(lchrArrHora);
     SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
     fprintf(FleArchivo,
             "Fecha:%s Hora:%s\n",
	     lchrArrFecha,
	     lchrArrHora);
}
void CQSisImprimeTicket::ImprimeNoOrden()
{
fprintf(FleArchivo,
	"No Orden:%s\n",
	(*CQSLPCotiza->at(0))["IdCotizacion"]);
	
}
void CQSisImprimeTicket::ImprimeDetalleOrden()
{
CQSisProdCotiza *lCQSPCotiza;
char lchrArrDescripcion[56];
fprintf(FleArchivo,
        "Cantidad     Producto    Precio   Importe\n");

for(lCQSPCotiza=CQSLPCotiza->first();
    lCQSPCotiza;
    lCQSPCotiza=CQSLPCotiza->next())
 {
 /*
 strncpy(lchrArrDescripcion,
	 (*lCQSPCotiza->Producto())["Dsc"],
	 12);
lchrArrDescripcion[12]=0;

*/
 fprintf(FleArchivo,
 	 "%s  %s %s   %s\n",
	 (*lCQSPCotiza)["Cantidad"],
	 (*lCQSPCotiza->Producto())["Dsc"],
	 (*lCQSPCotiza)["Precio"],
	 (*lCQSPCotiza)["Total"]);
 }   
}
void CQSisImprimeTicket::ImprimeTotalOrden()
{
fprintf(FleArchivo,
	"\n\n\n         Total Orden:%s\n\n\n\n\n\n\n\n",
	CQSLPCotiza->TotalOrden());
}
void CQSisImprimeTicket::LeeArchivoTicket()
{
FILE *lFleArchivo;
const char *lchrPtrArchivo=getenv("ArchivoTicket");
int lintContador;
 if(lchrPtrArchivo)
 {
    if((lFleArchivo=fopen(lchrPtrArchivo,"r")))
    {
	for(lintContador=0;
	    !feof(lFleArchivo);
	    lintContador++)
	 chrArrInfATicket[lintContador]=getc(lFleArchivo);
	 chrArrInfATicket[lintContador-1]=0;
	 fclose(lFleArchivo);
    }
 }
}
void CQSisImprimeTicket::ObtenDatosNegocio()
{
/*
int lintPosicion,
    lintTamano,
    lintTamano2;
    if(SiscomBuscaSubCadena(chrArrInfATicket,
    			    "[DatosNegocio]",
			    &lintPosicion,
			    &lintTamano))
    {
	if(SiscomBuscaSubCadena(&chrArrInfATicket[lintTamano],
				"[DatosNegocio]",
				&lintPosicion,
				&lintTamano2))
	{
	   strcpy(chrArrDatosNegocio,
	   	  &chrArrInfATicket[lintTamano]);
	   chrArrDatosNegocio[lintPosicion-1]=0;
	}

    }
*/
	 
}
