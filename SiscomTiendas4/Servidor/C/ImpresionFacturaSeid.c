#include <ImpresionFacturaSeid.h>
#include <ImpresionSeid.h>
#include <ServidorGeneral.h>
#include <stdlib.h>
void ImprimeFacturaSeid(SArgsSiscom *pSAgsSiscom)
{
StcPosicion lPosPosicion={ 10,0,5,235 };
FacturaSeid(pSAgsSiscom,
	    &lPosPosicion,
	    10,
	    40,
	    110,
	    130);
}
void FacturaSeid(SArgsSiscom *pSAgsSiscom,
		 const StcPosicion *pPosPtrPosicion,
		 float pfltTamCantidad,
		 float pfltTamCodigo,
		float pfltTamDescripcion,
		float pfltTamPrecioU)
{
PSDoc *lpsPtrArchivo;
int lintLetra;
int lintPSFirmaDSeid;
int lintLogoSeid;
float lfltPosLugarYFecha;
char lchrArrArchivo[1024];
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
	PS_set_info(lpsPtrArchivo, "Title", "Factura Seid");
	PS_set_info(lpsPtrArchivo, "Keywords", "LineTo, MoveTo, Arc, Rect, Polygon");
/* Importante para localizar los archivos de las letras
 * en este caso 
 * Para esta caso copie el archivo Helvetica.afm
 */
 PS_set_parameter(lpsPtrArchivo,
 		  "SearchPath",
		  RutaImagenImpresionSeid("ImpresionSeid"));
 lintLetra=PS_findfont(lpsPtrArchivo,"Helvetica","",0);
 /*
  * Este es el tamano de la hoja carta, solo que no ocupo toda  
  */
 PS_begin_page(lpsPtrArchivo,MMAPuntos(226),MMAPuntos(279));
 lfltPosLugarYFecha=FacturaTextoSeid(lpsPtrArchivo,
 				      pSAgsSiscom,
				      lintLetra,
				      pfltTamDescripcion,
				      pPosPtrPosicion);
FacturaSeidDetalleEncabezados(lpsPtrArchivo,
			      lintLetra,
			      pPosPtrPosicion,
			      lfltPosLugarYFecha,
			      pfltTamCantidad,
			      pfltTamCodigo,
			      pfltTamDescripcion,
			     pfltTamPrecioU);
  
FacturaSeidDetalleVenta(lpsPtrArchivo,
			 pSAgsSiscom,
			      lintLetra,
			      pPosPtrPosicion,
			      lfltPosLugarYFecha,
			      pfltTamCantidad,
			      pfltTamCodigo,
			      pfltTamDescripcion,
			     pfltTamPrecioU);
FacturaSeidFiscales(lpsPtrArchivo,
		    lintLetra,
		    pPosPtrPosicion);
 ColocaSelloDigital(lpsPtrArchivo,pPosPtrPosicion);

 PS_stroke(lpsPtrArchivo);
 PS_close(lpsPtrArchivo);
 PS_delete(lpsPtrArchivo);
 PS_shutdown();
}
}
void ColocaLogoSeid(PSDoc *ppsPtrDocArchivo,
		    const StcPosicion *pPosPtrPosicion)
{
int lintLogoSeid;
lintLogoSeid=PS_open_image_file(
		ppsPtrDocArchivo,
		"png",
		RutaImagenImpresionSeid("ImpresionSeid/LogoSeidNotaRemision.png"),
		NULL,
		0);
PS_place_image(ppsPtrDocArchivo,
	       lintLogoSeid,
	       SumaXpp(pPosPtrPosicion,0),
	       SumaYpp(pPosPtrPosicion,-12),
	       0.3);
PS_close_image(ppsPtrDocArchivo,lintLogoSeid);
}

void ColocaSelloDigital(PSDoc  *ppsPtrDocArchivo,
			const StcPosicion *pPosPtrPosicion)
{
int lintLogoSeid;
lintLogoSeid=PS_open_image_file(
		ppsPtrDocArchivo,
		"png",
		RutaImagenImpresionSeid("ImpresionSeid/FirmaDigitalSeid.png"),
		NULL,
		0);
PS_place_image(ppsPtrDocArchivo,
	       lintLogoSeid,
	       SumaXpp(pPosPtrPosicion,0),
	       SumaYpp(pPosPtrPosicion,-200),
	       0.3);
PS_close_image(ppsPtrDocArchivo,lintLogoSeid);
}
float FacturaTextoSeid(PSDoc *ppsPtrDocArchivo,
		      SArgsSiscom *pSAgsSiscom,
		      int pintTipoLetra,
		      float pfltTamDescripcion,
		      const StcPosicion *pPosPtrPosicion)
{
char lchrArrLugarYFecha[256];
char lchrArrCliente[256];
char lchrArrNoFactura[128];
float lfltPosLugarYFecha=pPosPtrPosicion->fltHojaYmm+25;
float lfltPosInforme=70;
ColocaLogoSeid(ppsPtrDocArchivo,pPosPtrPosicion);
PS_setfont(ppsPtrDocArchivo,pintTipoLetra,13);
PS_show_xy(ppsPtrDocArchivo,
	  "Sistemas  Electronicos  Ingenieria  y  Diseño",
	  SumaXpp(pPosPtrPosicion,lfltPosInforme),
	  SumaYpp(pPosPtrPosicion,12));
PS_setfont(ppsPtrDocArchivo,pintTipoLetra,11);
PS_show_xy(ppsPtrDocArchivo,
	  "\"Soluciones Tecnologicas de calidad al mejor costo\"",
	  SumaXpp(pPosPtrPosicion,lfltPosInforme),
	  SumaYpp(pPosPtrPosicion,7));

PS_setfont(ppsPtrDocArchivo,pintTipoLetra,10);
PS_show_xy(ppsPtrDocArchivo,
	  "http://www.seid.com.mx  email:seid@att.net.mx",
	  SumaXpp(pPosPtrPosicion,lfltPosInforme+5),
	  SumaYpp(pPosPtrPosicion,2));

PS_show_xy(ppsPtrDocArchivo,
	  "Martinez Garcia Ricardo   RFC:MAGR729493AL7",
	  SumaXpp(pPosPtrPosicion,lfltPosInforme+5),
	  SumaYpp(pPosPtrPosicion,-2));
PS_setfont(ppsPtrDocArchivo,pintTipoLetra,8);
PS_show_xy(ppsPtrDocArchivo,
	  "Republica del Salvador 17, local 16. Col Centro Delg",
	  SumaXpp(pPosPtrPosicion,lfltPosInforme+5),
	  SumaYpp(pPosPtrPosicion,-6));
PS_show_xy(ppsPtrDocArchivo,
	  "Cuahutemoc, Mexico D.F. C.P. 06000 Tel:55 55 10 23 54",
	  SumaXpp(pPosPtrPosicion,lfltPosInforme+5),
	  SumaYpp(pPosPtrPosicion,-9));

sprintf(lchrArrLugarYFecha,
	"Lugar y Fecha: Mexico D.F. a %s",
	SiscomObtenDato(SiscomArgumentoOperacionPrim("Remision",pSAgsSiscom),
			"FechaRemision"));

PS_setfont(ppsPtrDocArchivo,pintTipoLetra,10);
PS_show_xy(ppsPtrDocArchivo,
	  lchrArrLugarYFecha,
	  SumaXpp(pPosPtrPosicion,0),
	  SumaYpp(pPosPtrPosicion,-lfltPosLugarYFecha));
FormaNombreCliente(pSAgsSiscom,lchrArrCliente);
lfltPosLugarYFecha+=4;
PS_show_xy(ppsPtrDocArchivo,
	  lchrArrCliente,
	  SumaXpp(pPosPtrPosicion,0),
	  SumaYpp(pPosPtrPosicion,-lfltPosLugarYFecha));

lfltPosLugarYFecha+=4;
lfltPosLugarYFecha=MuestraDireccionFacturacion(ppsPtrDocArchivo,
			    pPosPtrPosicion,
			    lfltPosLugarYFecha,
			    pSAgsSiscom);

PS_show_xy(ppsPtrDocArchivo,
	  "FACTURA",
	  SumaXpp(pPosPtrPosicion,pfltTamDescripcion),
	  SumaYpp(pPosPtrPosicion,-(lfltPosLugarYFecha-20)));
sprintf(lchrArrNoFactura,
	"Folio:%s",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"NoRemFactura"));
PS_show_xy(ppsPtrDocArchivo,
	  lchrArrNoFactura,
	  SumaXpp(pPosPtrPosicion,pfltTamDescripcion),
	  SumaYpp(pPosPtrPosicion,-(lfltPosLugarYFecha-16)));
return lfltPosLugarYFecha;
}
void FacturaSeidDetalleVenta(PSDoc *ppsPtrDocArchivo,	
			    SArgsSiscom *pSAgsSiscom,
			    int pintLetra,
			    const StcPosicion *pPosPtrPosicion,
			    float pfltPosLugarYFecha,
			    float pfltTamCantidad,
			    float pfltTamCodigo,
			    float pfltTamDescripcion,
			    float pfltTamPrecioU)
{
LCamposSiscomPro2 *lLCSiscomPro2Dat;
float lfltTotal=0.0;
const char *lchrPtrTotal;
const char *lchrPtrDsc;
int lintTamDesplazaYmm=4.0;
int lintDesplazaYmm=lintTamDesplazaYmm;
char lchrArrTotalLetra[128];
char lchrArrRotuloTotalLetra[128];
PS_setfont(ppsPtrDocArchivo,pintLetra,9);

for(lLCSiscomPro2Dat=pSAgsSiscom->LCSiscomPro2Dat;
    lLCSiscomPro2Dat;
    lLCSiscomPro2Dat=lLCSiscomPro2Dat->SCP2PtrSig)
{

 PS_show_xy(ppsPtrDocArchivo,
 	    SiscomObtenDato(lLCSiscomPro2Dat,"Cantidad"),
	    SumaXpp(pPosPtrPosicion,0),
	    SumaYpp(pPosPtrPosicion,-(pfltPosLugarYFecha+4)-lintDesplazaYmm));
 PS_show_xy(ppsPtrDocArchivo,
 	    SiscomObtenDato(lLCSiscomPro2Dat,"Clave"),
	    SumaXpp(pPosPtrPosicion,pfltTamCantidad),
	    SumaYpp(pPosPtrPosicion,-(pfltPosLugarYFecha+4)-lintDesplazaYmm));
 lchrPtrDsc=SiscomObtenDato(lLCSiscomPro2Dat,"Dsc");
 TamanoTextoSeid(ppsPtrDocArchivo,
 	     pintLetra,
	     9,
	     pfltTamCodigo,
	     pfltTamDescripcion,
	     lchrPtrDsc);
 PS_show_xy(ppsPtrDocArchivo,
 	    lchrPtrDsc,
	    SumaXpp(pPosPtrPosicion,pfltTamCodigo),
	    SumaYpp(pPosPtrPosicion,-(pfltPosLugarYFecha+4)-lintDesplazaYmm));
 PS_show_xy(ppsPtrDocArchivo,
 	    SiscomObtenDato(lLCSiscomPro2Dat,"Precio"),
	    SumaXpp(pPosPtrPosicion,pfltTamDescripcion),
	    SumaYpp(pPosPtrPosicion,-(pfltPosLugarYFecha+4)-lintDesplazaYmm));
 PS_show_xy(ppsPtrDocArchivo,
 	    SiscomObtenDato(lLCSiscomPro2Dat,"Total"),
	    SumaXpp(pPosPtrPosicion,pfltTamPrecioU),
	    SumaYpp(pPosPtrPosicion,-(pfltPosLugarYFecha+4)-lintDesplazaYmm));
 lchrPtrTotal=SiscomObtenDato(lLCSiscomPro2Dat,"Total");
 lfltTotal+=atof(lchrPtrTotal);
 lintDesplazaYmm+=lintTamDesplazaYmm;
}
SiscomTransformaImporteALetraFloat(lfltTotal*1.16,lchrArrTotalLetra);
PS_show_xy(ppsPtrDocArchivo,
	   "Total con letra",
	   SumaXpp(pPosPtrPosicion,1),
	   MMAPuntos(pPosPtrPosicion->fltHojaYmm+85));
sprintf(lchrArrRotuloTotalLetra,
	"SON (%s)",
	lchrArrTotalLetra);
PS_show_xy(ppsPtrDocArchivo,
	   lchrArrRotuloTotalLetra,
	   SumaXpp(pPosPtrPosicion,1),
	   MMAPuntos(pPosPtrPosicion->fltHojaYmm+80));
sprintf(lchrArrRotuloTotalLetra,
	"SUBTOTAL: $%.2f",
	lfltTotal);
PS_show_xy(ppsPtrDocArchivo,
	   lchrArrRotuloTotalLetra,
	   SumaXpp(pPosPtrPosicion,130),
	   MMAPuntos(pPosPtrPosicion->fltHojaYmm+85));

sprintf(lchrArrRotuloTotalLetra,
	"IVA 16%%: $%.2f",
	lfltTotal*0.16);
PS_show_xy(ppsPtrDocArchivo,
	   lchrArrRotuloTotalLetra,
	   SumaXpp(pPosPtrPosicion,130),
	   MMAPuntos(pPosPtrPosicion->fltHojaYmm+80));

sprintf(lchrArrRotuloTotalLetra,
	"TOTAL: $%.2f",
	lfltTotal*1.16);
PS_show_xy(ppsPtrDocArchivo,
	   lchrArrRotuloTotalLetra,
	   SumaXpp(pPosPtrPosicion,130),
	   MMAPuntos(pPosPtrPosicion->fltHojaYmm+75));



}
void FacturaSeidFiscales(PSDoc *ppsPtrDocArchivo,
			 int pintLetra,
			 const StcPosicion *pPosPtrPosicion)
{
PS_show_xy(ppsPtrDocArchivo,
	   "NUMERO DE APROBACION SICOFI:21667290",
	   SumaXpp(pPosPtrPosicion,57),
	   MMAPuntos(pPosPtrPosicion->fltHojaYmm+70));
PS_setfont(ppsPtrDocArchivo,pintLetra,7);
PS_show_xy(ppsPtrDocArchivo,
	   "La reproduccion apocrifa de este comprobante constituye un delito en los terminos",
	   SumaXpp(pPosPtrPosicion,57),
	   MMAPuntos(pPosPtrPosicion->fltHojaYmm+65));

PS_show_xy(ppsPtrDocArchivo,
	   "de las disposiciones fiscales",
	   SumaXpp(pPosPtrPosicion,57),
	   MMAPuntos(pPosPtrPosicion->fltHojaYmm+62));
PS_show_xy(ppsPtrDocArchivo,
	   "Este comprobante tendra una vigencia de dos años contados a partir de la fecha",
	   SumaXpp(pPosPtrPosicion,57),
	   MMAPuntos(pPosPtrPosicion->fltHojaYmm+59));

PS_show_xy(ppsPtrDocArchivo,
	   "de aprobacion de la asignacion de folios, la cual es:23/02/2013",
	   SumaXpp(pPosPtrPosicion,57),
	   MMAPuntos(pPosPtrPosicion->fltHojaYmm+56));
PS_show_xy(ppsPtrDocArchivo,
	   "Pago en una sola exhibicion",
	   SumaXpp(pPosPtrPosicion,57),
	   MMAPuntos(pPosPtrPosicion->fltHojaYmm+53));
PS_show_xy(ppsPtrDocArchivo,
	   "Efectos Fiscales al pago",
	   SumaXpp(pPosPtrPosicion,57),
	   MMAPuntos(pPosPtrPosicion->fltHojaYmm+50));
}
void FacturaSeidDetalleEncabezados(PSDoc *ppsPtrDocArchivo,	
				   int pintLetra,
				   const StcPosicion *pPosPtrPosicion,
				   float pfltPosLugarYFecha,
				   float pfltTamCantidad,
				   float pfltTamCodigo,
				   float pfltTamDescripcion,
				   float pfltTamPrecioU)
{

 PS_setfont(ppsPtrDocArchivo,pintLetra,10);

 PS_show_xy(ppsPtrDocArchivo,
 	    "Cant.",
	    SumaXpp(pPosPtrPosicion,0),
	    SumaYpp(pPosPtrPosicion,-(pfltPosLugarYFecha+4)));
 
 PS_show_xy(ppsPtrDocArchivo,
 	    "Codigo",
	    SumaXpp(pPosPtrPosicion,pfltTamCantidad),
	    SumaYpp(pPosPtrPosicion,-(pfltPosLugarYFecha+4)));
 PS_show_xy(ppsPtrDocArchivo,
 	    "Descripcion",
	    SumaXpp(pPosPtrPosicion,pfltTamCodigo),
	    SumaYpp(pPosPtrPosicion,-(pfltPosLugarYFecha+4)));
 PS_show_xy(ppsPtrDocArchivo,
 	    "P. Unitario",
	    SumaXpp(pPosPtrPosicion,pfltTamDescripcion),
	    SumaYpp(pPosPtrPosicion,-(pfltPosLugarYFecha+4)));
 PS_show_xy(ppsPtrDocArchivo,
 	    "Importe",
	    SumaXpp(pPosPtrPosicion,pfltTamPrecioU),
	    SumaYpp(pPosPtrPosicion,-(pfltPosLugarYFecha+4)));


}
float MuestraDireccionFacturacion(PSDoc *ppsPtrDocArchivo,
		      const StcPosicion *pPosPtrPosicion,
		      float pfltPosLugarYFecha,
		      SArgsSiscom *pSAgsSiscom)
{
const char *lchrPtrDireccion;
LCamposSiscomPro2 *lLCSiscomPro2Dat;
char lchrArrLinea[256];
char lchrArrMuestra[256];
int lintContador=0;
float lfltYpp=pfltPosLugarYFecha;
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
	   SumaXpp(pPosPtrPosicion,0),
	   SumaYpp(pPosPtrPosicion,-lfltYpp));
}
else
PS_show_xy(ppsPtrDocArchivo,
	   lchrArrLinea,
	   SumaXpp(pPosPtrPosicion,0),
	   SumaYpp(pPosPtrPosicion,-lfltYpp));
lintContador++;
lfltYpp+=4;
}
}
else
SiscomLog("La Persona no tiene direcciones registradas");
return lfltYpp;
}
float SumaXpp(const StcPosicion *pPosPtrDato,float pfltXmmDes)
{
   return MMAPuntos(pPosPtrDato->fltHojaXmm+
   		    pPosPtrDato->fltBaseXmm+
		    pfltXmmDes);
}


float SumaYpp(const StcPosicion *pPosPtrDato,float pfltYmmDes)
{
   return MMAPuntos(pPosPtrDato->fltHojaYmm+
   		    pPosPtrDato->fltBaseYmm+
		    pfltYmmDes);
}

float RestaXpp(const StcPosicion *pPosPtrDato,float pfltXmmDes)
{
   return MMAPuntos(pPosPtrDato->fltHojaXmm+
   		    pPosPtrDato->fltBaseXmm-
		    pfltXmmDes);
}


float RestaYpp(const StcPosicion *pPosPtrDato,float pfltYmmDes)
{
   return MMAPuntos(pPosPtrDato->fltHojaYmm+
   		    pPosPtrDato->fltBaseYmm-
		    pfltYmmDes);
}
