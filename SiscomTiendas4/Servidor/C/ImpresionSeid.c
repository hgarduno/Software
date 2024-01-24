#include <ImpresionSeid.h>
#include <ImpresionFacturaSeid.h>
#include <ServidorGeneral.h>
#include <stdlib.h>
#include <string.h>

void ImprimeSeid(SArgsSiscom *pSAgsSiscom)
{
const char *lchrPtrTipoOrden;
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
lchrPtrTipoOrden=SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"TipoOrden");
if(!strcmp(lchrPtrTipoOrden,"Remision") ||
   !strcmp(lchrPtrTipoOrden,"Cotizacion"))
NotaRemisionSeid(pSAgsSiscom,50,0,10,32,77,91);
if(!strcmp(lchrPtrTipoOrden,"Factura"))
{
SiscomLog("Se Solicito Una Factura");
ImprimeFacturaSeid(pSAgsSiscom);
}
}
void AsignaArchivoParaCups(SArgsSiscom *pSAgsSiscom,
			   const char *pchrPtrArchivo)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
if((lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("ArchivoImpresion",pSAgsSiscom)))
{
 SiscomAsignaDatoCampo2("ArchivoParaCups",
 			pchrPtrArchivo,
			lLCSiscomPro2Dat);
}
else
{
SiscomLog("NO se encontro el argumento para el nombre");
}

}
void NotaRemisionSeid(SArgsSiscom *pSAgsSiscom,
			float pfltXmm,
		      float pfltYmm,
				  float pfltTamCantidad,
				  float pfltTamCodigo,
				  float pfltTamDescripcion,
				  float pfltTamPrecioU)
{
PSDoc *lpsPtrArchivo;
int lintLetra;
int lintPSFirmaDSeid;
int lintLogoSeid;
char lchrArrArchivo[256];
PS_boot();
lpsPtrArchivo=PS_new();
ObtenNombreArchivoImpresion(pSAgsSiscom,lchrArrArchivo);
AsignaArchivoParaCups(pSAgsSiscom,lchrArrArchivo);
if(!PS_open_file(lpsPtrArchivo,
		RutaImagenImpresionSeid(lchrArrArchivo)))
{
	PS_set_parameter(lpsPtrArchivo, "warning", "true");
	PS_set_info(lpsPtrArchivo, "Creator", __FILE__);
	PS_set_info(lpsPtrArchivo, "Author", "Ing. Heli Garduno Esquivel");
	PS_set_info(lpsPtrArchivo, "Title", "Remision Seid");
	PS_set_info(lpsPtrArchivo, "Keywords", "LineTo, MoveTo, Arc, Rect, Polygon");
/* Importante para localizar los archivos de las letras
 * en este caso 
 * Para esta caso copie el archivo Helvetica.afm
 */
 PS_set_parameter(lpsPtrArchivo,
 		  "SearchPath",
		  RutaImagenImpresionSeid("ImpresionSeid"));
 lintLetra=PS_findfont(lpsPtrArchivo,"Helvetica","",0);
 PS_begin_page(lpsPtrArchivo,MMAPuntos(226),MMAPuntos(279));
 NotaRemisionSeidTexto(lpsPtrArchivo,
 			pSAgsSiscom,
 			lintLetra,
		       pfltXmm,
		       pfltYmm);
 NotaRemisionSeidDetalleVenta(lpsPtrArchivo,
 				pSAgsSiscom,
				lintLetra,
 			      pfltXmm,
			      pfltYmm,
			      pfltTamCantidad,
			      pfltTamCodigo,
			      pfltTamDescripcion,
			      pfltTamPrecioU);
 DibujandoLineasRemisionSeid(lpsPtrArchivo,
 				pfltXmm,
 			     pfltYmm,
			      pfltTamCantidad,
			      pfltTamCodigo,
			      pfltTamDescripcion,
			      pfltTamPrecioU);
 PS_stroke(lpsPtrArchivo);
 PS_close(lpsPtrArchivo); 
}
else
SiscomLog("Error al abrir el archivo");
PS_delete(lpsPtrArchivo);
PS_shutdown();
}

void FormaNombreCliente(SArgsSiscom *pSAgsSiscom,
			char *pchrPtrCliente)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("Nombre",pSAgsSiscom);

sprintf(pchrPtrCliente,
	"Cliente: %s %s %s",
	SiscomObtenDato(lLCSiscomPro2Dat,"nombre"),
	SiscomObtenDato(lLCSiscomPro2Dat,"apaterno"),
	SiscomObtenDato(lLCSiscomPro2Dat,"amaterno"));
}
void NotaRemisionSeidTexto(PSDoc *ppsPtrDocArchivo,
			   SArgsSiscom *pSAgsSiscom,
			   int pintLetra,
			   float pfltXmm,
			   float pfltYmm)
{
char lchrArrLugarYFecha[128];
char lchrArrCliente[256];
char lchrArrNoRemision[128];
int lintPSFirmaDSeid;
int lintLogoSeid;
if(pintLetra!=0)
{
lintLogoSeid=PS_open_image_file(
		   ppsPtrDocArchivo,
		   "png",
	   RutaImagenImpresionSeid("ImpresionSeid/LogoSeidPequeno.png"),
			NULL,
			0);

PS_place_image(ppsPtrDocArchivo,
	lintLogoSeid,
	MMAPuntos(pfltXmm+5),
	MMAPuntos(pfltYmm+235),0.3);
PS_close_image(ppsPtrDocArchivo,lintLogoSeid);

PS_setfont(ppsPtrDocArchivo,pintLetra,10);
PS_show_xy(ppsPtrDocArchivo,
   "Sistemas Electronicos Ingenieria y Diseño",
   MMAPuntos(pfltXmm+35),
   MMAPuntos(pfltYmm+247));
PS_setfont(ppsPtrDocArchivo,pintLetra,8);
PS_show_xy(ppsPtrDocArchivo,
   "\"Soluciones tecnologicas de calidad al mejor costo\"",
   MMAPuntos(pfltXmm+37),
   MMAPuntos(pfltYmm+243));
PS_setfont(ppsPtrDocArchivo,pintLetra,8);
PS_show_xy(ppsPtrDocArchivo,
   "http://www.seid.com.mx",
   MMAPuntos(pfltXmm+37),
   MMAPuntos(pfltYmm+240));
PS_show_xy(ppsPtrDocArchivo,
   "email: seid@att.net.mx",
   MMAPuntos(pfltXmm+70),
   MMAPuntos(pfltYmm+240));

PS_setfont(ppsPtrDocArchivo,pintLetra,9);
PS_show_xy(ppsPtrDocArchivo,
   "Martinez Garcia Ricardo",
   MMAPuntos(pfltXmm+33),
   MMAPuntos(pfltYmm+236));

PS_show_xy(ppsPtrDocArchivo,
   "RFC:MAGR729493AL7",
   MMAPuntos(pfltXmm+67),
   MMAPuntos(pfltYmm+236));
PS_show_xy(ppsPtrDocArchivo,
   "Republica del Salvador 17, local 16. Col Centro Deleg",
   MMAPuntos(pfltXmm+33),
   MMAPuntos(pfltYmm+230));
   
PS_show_xy(ppsPtrDocArchivo,
   "Cuahutemoc, Mexico D.F. C.P. 06000. Tel:(55) 55 10 23 54",
   MMAPuntos(pfltXmm+33),
   MMAPuntos(pfltYmm+227));

PS_show_xy(ppsPtrDocArchivo,
   "Nota de remision",
   MMAPuntos(pfltXmm+5),
   MMAPuntos(pfltYmm+222));
sprintf(lchrArrNoRemision,
	"Remision No: %s",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"NoRemFactura"));
PS_show_xy(ppsPtrDocArchivo,
   lchrArrNoRemision,
   MMAPuntos(pfltXmm+75),
   MMAPuntos(pfltYmm+222));
sprintf(lchrArrLugarYFecha,
"Lugar y Fecha: Mexico D.F. a %s",
SiscomObtenDato(SiscomArgumentoOperacionPrim("Remision",pSAgsSiscom),
		"FechaRemision"));
PS_show_xy(ppsPtrDocArchivo,
   lchrArrLugarYFecha,
   MMAPuntos(pfltXmm+5),
   MMAPuntos(pfltYmm+218));
FormaNombreCliente(pSAgsSiscom,lchrArrCliente);
PS_show_xy(ppsPtrDocArchivo,
   lchrArrCliente,
   MMAPuntos(pfltXmm+5),
   MMAPuntos(pfltYmm+214));
MuestraDireccion(ppsPtrDocArchivo,
	 pSAgsSiscom,
	 MMAPuntos(pfltXmm+5),
	 MMAPuntos(pfltYmm+211));
/*
PS_show_xy(ppsPtrDocArchivo,
   "Domicilio:Esta es una prueba \n para la que estare\nhaciendo \nla direccion",
   MMAPuntos(pfltXmm+5),
   MMAPuntos(pfltYmm+211));
*/
}
else
SiscomLog("No se encontro el tipo de letra:%d",pintLetra);


}
void MuestraDireccion(PSDoc *ppsPtrDocArchivo,
	      SArgsSiscom *pSAgsSiscom,
	      float pfltXpp,
	      float pfltYpp)
{
const char *lchrPtrDireccion;
LCamposSiscomPro2 *lLCSiscomPro2Dat;
char lchrArrLinea[256];
char lchrArrMuestra[256];
int lintContador=0;
lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("Direccion",pSAgsSiscom);
if(lLCSiscomPro2Dat)
{
lchrPtrDireccion=SiscomObtenDato(lLCSiscomPro2Dat, "direccion");

while((lchrPtrDireccion=SiguienteLineaDireccion(lchrPtrDireccion,lchrArrLinea)))
{
if(!lintContador)
{
sprintf(lchrArrMuestra,"Domicilio: %s",lchrArrLinea);
PS_show_xy(ppsPtrDocArchivo,
   lchrArrMuestra,
   pfltXpp,
   pfltYpp);
}
else
PS_show_xy(ppsPtrDocArchivo,
   lchrArrLinea,
   pfltXpp,
   pfltYpp);
lintContador++;
pfltYpp-=10;
}
}
else
SiscomLog("La Persona no tiene direcciones registradas");
}
void EliminaUltimoCaracter(char *pchrPtrTexto)
{
pchrPtrTexto[strlen(pchrPtrTexto)-1]=0;
}
int TamanoTextoSeid(PSDoc *ppsPtrArchivo,
	   int pintLetra,
	  float pfltTamano,
	  float pfltTamCodigo,
	  float pfltTamDescripcion,
	  const char *pchrPtrTexto)
{
float lfltTamPuntos;
float lfltTamMMDsc;
float lfltTamPuntosDisponible;
char *lchrPtrTextoVisible;
int lintContador=0;
int lintEstado;
lchrPtrTextoVisible=(char *)pchrPtrTexto;
do
{
lfltTamPuntos=PS_stringwidth(ppsPtrArchivo,
	lchrPtrTextoVisible,
	pintLetra,
	pfltTamano);
lfltTamMMDsc=pfltTamDescripcion-pfltTamCodigo-1.8;
lfltTamPuntosDisponible=MMAPuntos(lfltTamMMDsc);
lintEstado=lfltTamPuntosDisponible<lfltTamPuntos;
if(lintEstado)
EliminaUltimoCaracter(lchrPtrTextoVisible);
}while(lintEstado);
}
void NotaRemisionSeidDetalleVenta(PSDoc *ppsPtrDocArchivo,
			  SArgsSiscom *pSAgsSiscom,
			  int pintLetra,
			  float pfltXmm,
			  float pfltYmm,
			  float pfltTamCantidad,
			  float pfltTamCodigo,
			  float pfltTamDescripcion,
			  float pfltTamPrecioU)
{
/* En este punto no he averiguado porque se necesita poner primero el 
* texto y despues las lineas, porque si voy poniendo el texto no 
* se muestra el texto.
*/
LCamposSiscomPro2 *lLCamposSiscomPro2Cont;
float lintDesplazaYmm=0;
const char *lchrPtrDsc;
const char *lchrPtrTotal;
char lchrArrTotalLetra[128];
char lchrArrRotuloTotalLetra[128];
float lfltTotal=0.0;
float lfltPosicionYmm=195;
PS_setfont(ppsPtrDocArchivo,pintLetra,8);
NotaRemisionSeidDetalleVentaEncabezados(ppsPtrDocArchivo,
			       pintLetra,
			       pfltXmm,
			       pfltYmm,
			       pfltTamCantidad,
			       pfltTamCodigo,
			       pfltTamDescripcion,
			       pfltTamPrecioU);

for(lLCamposSiscomPro2Cont=pSAgsSiscom->LCSiscomPro2Dat;
lLCamposSiscomPro2Cont;
lLCamposSiscomPro2Cont=lLCamposSiscomPro2Cont->SCP2PtrSig)
{
PS_show_xy(ppsPtrDocArchivo,
   SiscomObtenDato(lLCamposSiscomPro2Cont,"Cantidad"),
   MMAPuntos(pfltXmm+6),
   MMAPuntos(pfltYmm+lfltPosicionYmm-lintDesplazaYmm));
PS_show_xy(ppsPtrDocArchivo,
   SiscomObtenDato(lLCamposSiscomPro2Cont,"Clave"),
   MMAPuntos(pfltXmm+6+pfltTamCantidad),
   MMAPuntos(pfltYmm+lfltPosicionYmm-lintDesplazaYmm));

lchrPtrDsc=SiscomObtenDato(lLCamposSiscomPro2Cont,"Dsc");
TamanoTextoSeid(ppsPtrDocArchivo,
   pintLetra,
   8,
   pfltTamCodigo,
   pfltTamDescripcion,
   lchrPtrDsc);
PS_show_xy(ppsPtrDocArchivo,
   lchrPtrDsc,
   MMAPuntos(pfltXmm+6+pfltTamCodigo),
   MMAPuntos(pfltYmm+lfltPosicionYmm-lintDesplazaYmm));
PS_show_xy(ppsPtrDocArchivo,
   SiscomObtenDato(lLCamposSiscomPro2Cont,"Precio"),
   MMAPuntos(pfltXmm+6+pfltTamDescripcion),
   MMAPuntos(pfltYmm+lfltPosicionYmm-lintDesplazaYmm));
PS_show_xy(ppsPtrDocArchivo,
   SiscomObtenDato(lLCamposSiscomPro2Cont,"Total"),
   MMAPuntos(pfltXmm+6+pfltTamPrecioU),
   MMAPuntos(pfltYmm+lfltPosicionYmm-lintDesplazaYmm));
lchrPtrTotal=SiscomObtenDato(lLCamposSiscomPro2Cont,"Total");
lfltTotal+=atof(lchrPtrTotal);
lintDesplazaYmm+=3.2;
}
PS_setfont(ppsPtrDocArchivo,pintLetra,10);
PS_show_xy(ppsPtrDocArchivo,
   "Total con letra",
   MMAPuntos(pfltXmm+6),
   MMAPuntos(pfltYmm+85));
SiscomTransformaImporteALetraFloat(lfltTotal,lchrArrTotalLetra);
sprintf(lchrArrRotuloTotalLetra,
"SON (%s)",
lchrArrTotalLetra);
PS_setfont(ppsPtrDocArchivo,pintLetra,8);
PS_show_xy(ppsPtrDocArchivo,
   lchrArrRotuloTotalLetra,
   MMAPuntos(pfltXmm+6),
   MMAPuntos(pfltYmm+80));
sprintf(lchrArrRotuloTotalLetra,
"Total:$%.2f",
lfltTotal);
PS_show_xy(ppsPtrDocArchivo,
   lchrArrRotuloTotalLetra,
   MMAPuntos(pfltXmm+6+pfltTamDescripcion),
   MMAPuntos(pfltYmm+85));
}
	

void DibujandoLineasRemisionSeid(PSDoc *ppsPtrDocArchivo,
		float pfltXmm,
		float pfltYmm,
			  float pfltTamCantidad,
				  float pfltTamCodigo,
				  float pfltTamDescripcion,
				  float pfltTamPrecioU)

{
float  lfltPosicionYmm=203;

DibujaLinea(ppsPtrDocArchivo,
	    MMAPuntos(pfltXmm+5),
	    MMAPuntos(pfltYmm+lfltPosicionYmm),
	    MMAPuntos(pfltXmm+110),
	    MMAPuntos(pfltYmm+lfltPosicionYmm));
DibujaLinea(ppsPtrDocArchivo,
	    MMAPuntos(pfltXmm+5),
	    MMAPuntos(pfltYmm+lfltPosicionYmm),
	    MMAPuntos(pfltXmm+5),
	    MMAPuntos(pfltYmm+90));
DibujaLinea(ppsPtrDocArchivo,
	    MMAPuntos(pfltXmm+110),
	    MMAPuntos(pfltYmm+lfltPosicionYmm),
	    MMAPuntos(pfltXmm+110),
	    MMAPuntos(pfltYmm+90));
DibujaLinea(ppsPtrDocArchivo,
	    MMAPuntos(pfltXmm+5),
	    MMAPuntos(pfltYmm+90),
	    MMAPuntos(pfltXmm+110),
	    MMAPuntos(pfltYmm+90));


DibujaLinea(ppsPtrDocArchivo,
	    MMAPuntos(pfltXmm+5+pfltTamCantidad),
	    MMAPuntos(pfltYmm+lfltPosicionYmm),
	    MMAPuntos(pfltXmm+5+pfltTamCantidad),
	    MMAPuntos(pfltYmm+90));

DibujaLinea(ppsPtrDocArchivo,
	    MMAPuntos(pfltXmm+5+pfltTamCodigo),
	    MMAPuntos(pfltYmm+lfltPosicionYmm),
	    MMAPuntos(pfltXmm+5+pfltTamCodigo),
	    MMAPuntos(pfltYmm+90));
DibujaLinea(ppsPtrDocArchivo,
	    MMAPuntos(pfltXmm+5+pfltTamDescripcion),
	    MMAPuntos(pfltYmm+lfltPosicionYmm),
	    MMAPuntos(pfltXmm+5+pfltTamDescripcion),
	    MMAPuntos(pfltYmm+90));

DibujaLinea(ppsPtrDocArchivo,
	    MMAPuntos(pfltXmm+5+pfltTamPrecioU),
	    MMAPuntos(pfltYmm+lfltPosicionYmm),
	    MMAPuntos(pfltXmm+5+pfltTamPrecioU),
	    MMAPuntos(pfltYmm+90));

DibujaLinea(ppsPtrDocArchivo,
	    MMAPuntos(pfltXmm+5),
	    MMAPuntos(pfltYmm+lfltPosicionYmm-5),
	    MMAPuntos(pfltXmm+110),
	    MMAPuntos(pfltYmm+lfltPosicionYmm-5));


}
float MMAPuntos(float pfltMM)
{
return pfltMM/0.33;
}

char *RutaImagenImpresionSeid(char *pchrPtrImagen)
{
char *lchrPtrRegreso=(char *)malloc(strlen(pchrPtrImagen)+
				    strlen(gSSiscomConfiguracionSvr.chrPtrDirTrabajo)+2);
sprintf(lchrPtrRegreso,
	"%s/%s",
	gSSiscomConfiguracionSvr.chrPtrDirTrabajo,
	pchrPtrImagen);
return lchrPtrRegreso;

}
void DibujaLinea(PSDoc *ppsPtrDocArchivo,
		 float pfltXmm,
		 float pfltYmm,
		 float pfltX1mm,
		 float pfltY1mm)
{
PS_moveto(ppsPtrDocArchivo,
	  pfltXmm,
	  pfltYmm);
PS_lineto(ppsPtrDocArchivo,
	  pfltX1mm,
	  pfltY1mm);

}

void NotaRemisionSeidDetalleVentaEncabezados(PSDoc *ppsPtrDocArchivo,
				  int pintLetra,
				  float pfltXmm,
				  float pfltYmm,
				  float pfltTamCantidad,
				  float pfltTamCodigo,
				  float pfltTamDescripcion,
				  float pfltTamPrecioU)
{
/* En este punto no he averiguado porque se necesita poner primero el 
 * texto y despues las lineas, porque si voy poniendo el texto no 
 * se muestra el texto.
 */
float lfltPosicionYmm=200;
PS_setfont(ppsPtrDocArchivo,pintLetra,8);
PS_show_xy(ppsPtrDocArchivo,
	   "Cant.",
	   MMAPuntos(pfltXmm+6),
	   MMAPuntos(pfltYmm+lfltPosicionYmm));

PS_show_xy(ppsPtrDocArchivo,
	   "Codigo",
	    MMAPuntos(pfltXmm+6+pfltTamCantidad),
	   MMAPuntos(pfltYmm+lfltPosicionYmm));
	   
PS_show_xy(ppsPtrDocArchivo,
	   "Descripcion",
	    MMAPuntos(pfltXmm+6+pfltTamCodigo),
	   MMAPuntos(pfltYmm+lfltPosicionYmm));

PS_show_xy(ppsPtrDocArchivo,
	   "Precio",
	    MMAPuntos(pfltXmm+6+pfltTamDescripcion),
	   MMAPuntos(pfltYmm+lfltPosicionYmm));
PS_show_xy(ppsPtrDocArchivo,
	   "Importe",
	    MMAPuntos(pfltXmm+6+pfltTamPrecioU),
	   MMAPuntos(pfltYmm+lfltPosicionYmm));
}

const char *EliminaSaltoRetono(const char *pchrPtrLinea)
{
	while(*pchrPtrLinea=='\n' ||
	      *pchrPtrLinea=='\r')
	  pchrPtrLinea++;
return pchrPtrLinea;
}
const char *SiguienteLineaDireccion(const char *pchrPtrDireccion,
				    char *pchrPtrLinea)
{
const char *lchrPtrRegreso;
int lintTamano;

	if((lchrPtrRegreso=strchr(pchrPtrDireccion,'\n')))
	{
	lintTamano=lchrPtrRegreso-pchrPtrDireccion;
       strncpy(pchrPtrLinea,pchrPtrDireccion,lchrPtrRegreso-pchrPtrDireccion);
       pchrPtrLinea[lintTamano]=0;
       lchrPtrRegreso=EliminaSaltoRetono(lchrPtrRegreso);
	return lchrPtrRegreso;
	}
	else
	strcpy(pchrPtrLinea,pchrPtrDireccion);
   return 0;
}

void ObtenNombreArchivoImpresion(SArgsSiscom *pSAgsSiscom,	
				 char *pchrPtrArchivo)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
if((lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim("ArchivoImpresion",pSAgsSiscom)))
{
sprintf(pchrPtrArchivo,
	"ImpresionSeid/%s",
	SiscomObtenDato(lLCSiscomPro2Dat,"Archivo"));
SiscomLog("%s",pchrPtrArchivo);
}
else
{
SiscomLog("NO se encontro el argumento para el nombre");
}
}
