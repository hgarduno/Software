#include <PdfFactura.h>

#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include <string.h>


#include <SiscomDesarrolloMacros.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperaciones.h>
#include <Facturando4.h>
jmp_buf env;
void error_handler (HPDF_STATUS   error_no,
               HPDF_STATUS   detail_no,
               void         *user_data)
{
    printf ("ERROR: error_no=%04X, detail_no=%u\n", (HPDF_UINT)error_no,
                (HPDF_UINT)detail_no);
    longjmp(env, 1);
}


#ifdef __DESARROLLANDO_LA_FACTURA__

#define MensajesLog(pchrPtrCadena) printf("(%d) %s\n",__LINE__,pchrPtrCadena);

int main(int pintArgc,char **pchrArgv)
{

HPDF_Doc lHpdfDocPtrArchivo;
HPDF_Page lHpdfPagePtrPagina;
HPDF_REAL lHpdfRealAlto;
HPDF_REAL lHpdfRealAncho;

printf("Hola Mundo\n");

lHpdfDocPtrArchivo=HPDF_New(error_handler,0);
if(!lHpdfDocPtrArchivo)
{
 printf("NO se pudo crear el documento PDf\n");
 return 1;
}

if (setjmp(env)) {
        HPDF_Free (lHpdfDocPtrArchivo);
        return 1;
    }

lHpdfPagePtrPagina=HPDF_AddPage(lHpdfDocPtrArchivo);
lHpdfRealAlto=HPDF_Page_GetHeight(lHpdfPagePtrPagina);
lHpdfRealAncho=HPDF_Page_GetWidth(lHpdfPagePtrPagina);
HPDF_Page_SetLineWidth(lHpdfPagePtrPagina,1);
HPDF_Page_Rectangle(lHpdfPagePtrPagina,50,50,lHpdfRealAncho-100,lHpdfRealAlto-90);
HPDF_Page_Stroke(lHpdfPagePtrPagina);
SiscomPdfTexto(55,
	       lHpdfRealAlto-80,
	       "Helvetica",
	       10,
	       lHpdfDocPtrArchivo,
	       lHpdfPagePtrPagina,
	       "Soluciones en Sistemas de Computo y Electronica SA de CV");

SiscomPdfTexto(55,
	       lHpdfRealAlto-90,
	       "Helvetica",
	       8,
	       lHpdfDocPtrArchivo,
	       lHpdfPagePtrPagina,
	       "RFC SSC160604EF3");

SiscomPdfTexto(55,
	       lHpdfRealAlto-100,
	       "Helvetica",
	       8,
	       lHpdfDocPtrArchivo,
	       lHpdfPagePtrPagina,
	       "Eva Samano de Lopez Mateos #28");

SiscomPdfTexto(55,
	       lHpdfRealAlto-110,
	       "Helvetica",
	       8,
	       lHpdfDocPtrArchivo,
	       lHpdfPagePtrPagina,
	       "Colonia: Bo Tlacateco");

SiscomPdfTexto(55+HPDF_Page_TextWidth(lHpdfPagePtrPagina,"Colonia:Bo Tlacateco")+5,
	       lHpdfRealAlto-110,
	       "Helvetica",
	       8,
	       lHpdfDocPtrArchivo,
	       lHpdfPagePtrPagina,
	       "Alcaldia/Municipio Tepotzotlan");


HPDF_SaveToFile(lHpdfDocPtrArchivo,"Pruebas.pdf");

HPDF_Free(lHpdfDocPtrArchivo);


}




#endif

void SiscomHaruPdfTexto(int pintX,
		    int pintY,
		    const char *pchrPtrLetra,
		    int pintTamano,
		    HPDF_Doc pHpdfDocPtrArchivo,
		    HPDF_Page pHpdfPagePtrPagina,
		    const char *pchrPtrTexto)
{
HPDF_Font lHpdfFontPtrLetra;
lHpdfFontPtrLetra=HPDF_GetFont(pHpdfDocPtrArchivo,pchrPtrLetra,0);
HPDF_Page_SetFontAndSize(pHpdfPagePtrPagina,lHpdfFontPtrLetra,pintTamano);
HPDF_Page_BeginText(pHpdfPagePtrPagina);
HPDF_Page_TextOut(pHpdfPagePtrPagina,pintX,pintY,pchrPtrTexto);
HPDF_Page_EndText(pHpdfPagePtrPagina);
}

void SiscomHaruEscribe(SiscomHaruTexto *pSisHaruPtrTexto,
		     const char *pchrPtrTexto)
{
HPDF_Font lHpdfFontPtrLetra;
lHpdfFontPtrLetra=HPDF_GetFont(pSisHaruPtrTexto->HpdfDocPtrArchivo,
			       pSisHaruPtrTexto->chrPtrTipoLetra,
			       0);

HPDF_Page_SetFontAndSize(pSisHaruPtrTexto->HpdfPagePtrPagina,
			 lHpdfFontPtrLetra,
			 pSisHaruPtrTexto->intTamano);
HPDF_Page_BeginText(pSisHaruPtrTexto->HpdfPagePtrPagina);
HPDF_Page_TextOut(pSisHaruPtrTexto->HpdfPagePtrPagina,
		  pSisHaruPtrTexto->intX,
		  pSisHaruPtrTexto->intY,
		  pchrPtrTexto);
HPDF_Page_EndText(pSisHaruPtrTexto->HpdfPagePtrPagina);
}
void SiscomHaruEscribe2(SiscomHaruTexto *pSisHaruPtrTexto)
{
  SiscomHaruEscribe(pSisHaruPtrTexto,pSisHaruPtrTexto->chrPtrTexto);
}

void SiscomHaruColocaEncabezadosTabla(SiscomHaruColumna *pSisHaruColumnas)
{
int lintPosicionX=pSisHaruColumnas->intX;
   while(pSisHaruColumnas->chrPtrTexto)
   {
     pSisHaruColumnas->intX=lintPosicionX;
     SiscomHaruPdfTexto(lintPosicionX,
     			pSisHaruColumnas->intY,
			pSisHaruColumnas->chrPtrTipoLetra,
			pSisHaruColumnas->intTamano,
			pSisHaruColumnas->HpdfDocPtrArchivo,
			pSisHaruColumnas->HpdfPagePtrPagina,
			pSisHaruColumnas->chrPtrTexto);

    lintPosicionX+=HPDF_Page_TextWidth(pSisHaruColumnas->HpdfPagePtrPagina,pSisHaruColumnas->chrPtrTexto)+
    		   pSisHaruColumnas->intTamColumna;
    pSisHaruColumnas++;
   }

}
int SiscomHaruLineaDatosTabla(SiscomHaruColumna *pSisHaruColumnas,
			     const char *pchrPtrCampos[],
			     SiscomRegistroProL *pSisRegProLPtrDatos,
			     int *pintPtrUltimoY)
{
int lintPosicionX=pSisHaruColumnas->intX,
    lintPosicionY=pSisHaruColumnas->intY-10;


    while(*pchrPtrCampos)
    {
	pSisHaruColumnas->intX=lintPosicionX;
	pSisHaruColumnas->intY=lintPosicionY;
	SiscomHaruPdfTexto(lintPosicionX,
			   pSisHaruColumnas->intY,
			   pSisHaruColumnas->chrPtrTipoLetra,
			   pSisHaruColumnas->intTamano,
			   pSisHaruColumnas->HpdfDocPtrArchivo,
			   pSisHaruColumnas->HpdfPagePtrPagina,
			   SiscomObtenCampoRegistroProLChar(*pchrPtrCampos,pSisRegProLPtrDatos));
    lintPosicionX+=HPDF_Page_TextWidth(pSisHaruColumnas->HpdfPagePtrPagina,pSisHaruColumnas->chrPtrTexto)+
    		   pSisHaruColumnas->intTamColumna;
		   *pintPtrUltimoY=pSisHaruColumnas->intY;

	 pchrPtrCampos++;
	 pSisHaruColumnas++;
    }
return lintPosicionY;
}
/*
HPDF_AddPage(pSisHaruColumnas->HpdfPagePtrPagina);

*/

			     
SiscomRegistroProL *SiscomHaruTabla(SiscomHaruColumna *pSisHaruColumnas,
		     const char *pchrPtrCampos[],
		     SiscomRegistroProL *pSisRegProLPtrDatos,
		     int *pintPtrUltimoY)
{
int lintY;
  SiscomHaruColocaEncabezadosTabla(pSisHaruColumnas);
  while(pSisRegProLPtrDatos)
  {
     SiscomHaruLineaDatosTabla(pSisHaruColumnas,
     				pchrPtrCampos,
				pSisRegProLPtrDatos,
				pintPtrUltimoY);
    if(pSisHaruColumnas->intY<=91)
     return pSisRegProLPtrDatos;

     pSisRegProLPtrDatos=pSisRegProLPtrDatos->SiscomRegProLPtrSig;
  }
return 0;
}

int IniciandoArchivoPdf(SiscomHaruTexto *pSisHaruPtrTexto)
{
pSisHaruPtrTexto->HpdfDocPtrArchivo=HPDF_New(error_handler,0);
if(!pSisHaruPtrTexto->HpdfDocPtrArchivo)
{
LogSiscom("No se pudo iniciar el documento Pdf");
}
else
{
LogSiscom("Se inicio Haru PDF");
}

HPDF_SetCompressionMode (pSisHaruPtrTexto->HpdfDocPtrArchivo, HPDF_COMP_ALL);
pSisHaruPtrTexto->HpdfPagePtrPagina=HPDF_AddPage(pSisHaruPtrTexto->HpdfDocPtrArchivo);
}
const char *RutaImagenes()
{
const char *lchrPtrRuta;
if((lchrPtrRuta=getenv("DirectorioImagenes")))
   return lchrPtrRuta;
else
 return getenv("HOME");
}

void FormaPaginaPdf(HPDF_REAL pHpdfRealAlto,
		    HPDF_REAL pHpdfRealAncho,
		    SiscomHaruTexto *pSisHaruPtrTexto,
		    const char *pchrPtrPagina)
{
HPDF_Image lHpdfImagen;
HPDF_Destination lHpdfDestination;
char lchrArrLogo[1024];
HPDF_Page_Rectangle(pSisHaruPtrTexto->HpdfPagePtrPagina,
		    50,
		    50,
		    pHpdfRealAncho-100,
		    pHpdfRealAlto-90);

lHpdfDestination=HPDF_Page_CreateDestination(pSisHaruPtrTexto->HpdfPagePtrPagina);
HPDF_Destination_SetXYZ(lHpdfDestination,
			0,
			HPDF_Page_GetHeight(pSisHaruPtrTexto->HpdfPagePtrPagina),
			1);
HPDF_SetOpenAction(pSisHaruPtrTexto->HpdfDocPtrArchivo,lHpdfDestination);
sprintf(lchrArrLogo,"%s/Imagenes/Logo_normal.png",RutaImagenes());
if((lHpdfImagen=HPDF_LoadPngImageFromFile(pSisHaruPtrTexto->HpdfDocPtrArchivo,lchrArrLogo)))
{

HPDF_Page_Stroke(pSisHaruPtrTexto->HpdfPagePtrPagina);
HPDF_Page_DrawImage(pSisHaruPtrTexto->HpdfPagePtrPagina,
		    lHpdfImagen, 
		    50,
		    pHpdfRealAlto-155, 
		    100,
		    120);
}
else
LogSiscom("No se encontraron los iconos");
}
void DireccionEmisorPdf(HPDF_REAL pHpdfRealAlto,
			HPDF_REAL pHpdfRealAncho,
			SiscomHaruTexto *pSisHaruTexto,
			SiscomOperaciones *pSisOpePtrDato)
{
  pSisHaruTexto->intY-=10;
  pSisHaruTexto->intTamano=6;
  SiscomHaruEscribe(pSisHaruTexto,"Calle: Eva Samano de Lopez Mateso #29");
  pSisHaruTexto->intY-=7;
  SiscomHaruEscribe(pSisHaruTexto,"Colonia: Bo Tlacateco, Tepotzotlan, Mexico");
  pSisHaruTexto->intY-=7;
  SiscomHaruEscribe(pSisHaruTexto,"C.P. 54600");
  pSisHaruTexto->intY-=7;
  SiscomHaruEscribe(pSisHaruTexto,"Regimen General");
}

void DatosReceptorPdf(HPDF_REAL pHpdfRealAlto,
		      HPDF_REAL pHpdfRealAncho,
		      SiscomHaruTexto *pSisHaruTexto,
		      SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSiscomRegProLPtrDato;
char lchrArrReceptor[512],
	lchrArrCP[12],
	lchrArrLinea[256];
pSisHaruTexto->intX=220;
pSisHaruTexto->intY=pHpdfRealAlto-110;
pSisHaruTexto->intTamano=9;
SiscomHaruEscribe(pSisHaruTexto,"Receptor");
pSisHaruTexto->intTamano=7;
lSiscomRegProLPtrDato=SiscomRegistroAsociadoEntradaOperacion("Envio",
							     "Cliente",
							     pSisOpePtrDato);
sprintf(lchrArrCP,"%05d",atoi(SiscomAsociadoPrimerCampo("Direccion","CP",lSiscomRegProLPtrDato)));

pSisHaruTexto->intY-=7;
SiscomHaruEscribe(pSisHaruTexto,SiscomAsociadoPrimerCampo("Empresa","RazonSocial",lSiscomRegProLPtrDato));
pSisHaruTexto->intY-=7;
SiscomHaruEscribe(pSisHaruTexto,
		 SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","Cliente","RFC",pSisOpePtrDato));
pSisHaruTexto->intY-=7;
SiscomHaruEscribe(pSisHaruTexto,SiscomAsociadoPrimerCampo("Direccion","Calle",lSiscomRegProLPtrDato));
pSisHaruTexto->intX+=HPDF_Page_TextWidth(pSisHaruTexto->HpdfPagePtrPagina,
			SiscomAsociadoPrimerCampo("Direccion","Calle",lSiscomRegProLPtrDato))+5;
SiscomHaruEscribe(pSisHaruTexto,SiscomAsociadoPrimerCampo("Direccion","Numero",lSiscomRegProLPtrDato));
pSisHaruTexto->intX=220;
pSisHaruTexto->intY-=7;
sprintf(lchrArrLinea,
	"%s, %s, %s",
	SiscomAsociadoPrimerCampo("Direccion","Colonia",lSiscomRegProLPtrDato),
	SiscomAsociadoPrimerCampo("Direccion","Delegacion",lSiscomRegProLPtrDato),
	SiscomAsociadoPrimerCampo("Direccion","Estado",lSiscomRegProLPtrDato));
SiscomHaruEscribe(pSisHaruTexto,lchrArrLinea);
pSisHaruTexto->intY-=7;
sprintf(lchrArrLinea, "%s C.P. %s", "Mexico",lchrArrCP);
SiscomHaruEscribe(pSisHaruTexto,lchrArrLinea);
}
void DatosComprobantePdf(HPDF_REAL pHpdfRealAlto,
			 HPDF_REAL pHpdfRealAncho,
			 SiscomHaruTexto *pSisHaruTexto,
			 SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrLinea[256];
int lintMitad=pHpdfRealAncho/2;
pSisHaruTexto->intX=lintMitad-25;
pSisHaruTexto->intY=pHpdfRealAlto-75;
pSisHaruTexto->intTamano=6;
SiscomHaruEscribe(pSisHaruTexto,"Tipo de Comprobante I  PO 145685");
pSisHaruTexto->intY-=7;
sprintf(lchrArrLinea,
	"Fecha de emision %s",
	SiscomCampoAsociadoEntradaOperacion("Envio","Fecha",pSisOpePtrDato));
SiscomHaruEscribe(pSisHaruTexto,lchrArrLinea);
pSisHaruTexto->intY-=14;
sprintf(lchrArrLinea,"Certificado: %s",SiscomCampoAsociadoEntradaOperacion("Envio","Certificado",pSisOpePtrDato));
SiscomHaruEscribe(pSisHaruTexto,lchrArrLinea);
pSisHaruTexto->intY-=7;
sprintf(lchrArrLinea,"Folio Fiscal: %s",SiscomCampoAsociadoEntradaOperacion("Envio","FolioFiscal",pSisOpePtrDato));
SiscomHaruEscribe(pSisHaruTexto,lchrArrLinea);
sprintf(lchrArrLinea,
	"Forma de Pago: %s %s",
	   SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","FormaPago","codigo",pSisOpePtrDato),
	   SiscomCampoAsociadoAsociadoEntradaOperacion("Envio","FormaPago","formapago",pSisOpePtrDato));
pSisHaruTexto->intY=pHpdfRealAlto-75;
pSisHaruTexto->intX=lintMitad+85;
SiscomHaruEscribe(pSisHaruTexto,lchrArrLinea);
pSisHaruTexto->intY-=7;
sprintf(lchrArrLinea,
	"Metodo de Pago: %s",
	    SiscomCampoAsociadoAsociadoEntradaOperacion("Envio", "MetodoPago","metodopago",pSisOpePtrDato));
SiscomHaruEscribe(pSisHaruTexto,lchrArrLinea);
pSisHaruTexto->intY-=7;
SiscomHaruEscribe(pSisHaruTexto,"Efectos Fiscales al pago");
pSisHaruTexto->intY-=7;
sprintf(lchrArrLinea,
	"Uso del CFDI %s %s",
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
						    "UsoFactura",
						    "codigo",
						    pSisOpePtrDato),
	SiscomCampoAsociadoAsociadoEntradaOperacion("Envio",
						    "UsoFactura",
						    "uso",
						    pSisOpePtrDato));
SiscomHaruEscribe(pSisHaruTexto,lchrArrLinea);
}

void AsignaPaginaPdfColumnas(SiscomHaruTexto *pSisHaruTexto,
			     SiscomHaruColumna *pSisHaruPtrTexto)
{
  while(pSisHaruPtrTexto->chrPtrTexto)
  {
      pSisHaruPtrTexto->HpdfPagePtrPagina=pSisHaruTexto->HpdfPagePtrPagina;
      pSisHaruPtrTexto->HpdfDocPtrArchivo=pSisHaruTexto->HpdfDocPtrArchivo;
    pSisHaruPtrTexto++;
  }

}
SiscomRegistroProL *FormaTablaProductosPdf(HPDF_REAL pHpdfRealAlto,
			    HPDF_REAL pHpdfRealAncho,
			    SiscomHaruTexto *pSisHaruTexto,
			    SiscomRegistroProL *pSisRegProLPtrProductos,
			    int *pintPtrUltimoY,
			    int *pintPtrXPrecio,
			    int *pintPtrXImporte)
{
SiscomRegistroProL *lSisRegProLPtrUltimoProducto;
char lchrArrBuffer[256];
SiscomHaruColumna *lSisHaruPtrPaso;
int lintPosicionY=170;
 SiscomHaruColumna lSisHaruArrTexto[]={ 
 	
	{55,pHpdfRealAlto-lintPosicionY,7,"Helvetica","Cantidad",10,0,0},
	{55,pHpdfRealAlto-lintPosicionY,7,"Helvetica","Unidad",10,0,0},
	{55,pHpdfRealAlto-lintPosicionY,7,"Helvetica","Codigo SAT",10,0,0},
	{55,pHpdfRealAlto-lintPosicionY,7,"Helvetica","Codigo",100,0,0},
	{55,pHpdfRealAlto-lintPosicionY,7,"Helvetica","Descripcion",100,0,0},
	{55,pHpdfRealAlto-lintPosicionY,7,"Helvetica","Precio",20,0,0},
	{55,pHpdfRealAlto-lintPosicionY,7,"Helvetica","Importe",10,0,0},
	{0,0,0,0,0,0,0,0}
	};
const char *lchrPtrCampos[]={"cantidad","unidad","sat","cveproducto","cveproducto","precio","importe",0};
lSisHaruPtrPaso=lSisHaruArrTexto; 
AsignaPaginaPdfColumnas(pSisHaruTexto,lSisHaruPtrPaso);
if((lSisRegProLPtrUltimoProducto=SiscomHaruTabla(lSisHaruPtrPaso,
		lchrPtrCampos,
		pSisRegProLPtrProductos,
		pintPtrUltimoY)))
   return lSisRegProLPtrUltimoProducto;

*pintPtrUltimoY-=13;
*pintPtrXPrecio=(lSisHaruPtrPaso+5)->intX;
*pintPtrXImporte=(lSisHaruPtrPaso+6)->intX;
return 0;
}
void ImporteIvaTotalesPdf(SiscomHaruTexto *pSisHaruTexto,
			  int pintXImporte,
		          SiscomOperaciones *pSisOpePtrDato)
{
 pSisHaruTexto->intTamano=7;
 SiscomHaruPdfTexto(pSisHaruTexto->intX,
 		   pSisHaruTexto->intY,
		pSisHaruTexto->chrPtrTipoLetra,
		pSisHaruTexto->intTamano,
		pSisHaruTexto->HpdfDocPtrArchivo,
		pSisHaruTexto->HpdfPagePtrPagina,
		"Importe");

 SiscomHaruPdfTexto(pintXImporte,
 		   pSisHaruTexto->intY,
		pSisHaruTexto->chrPtrTipoLetra,
		pSisHaruTexto->intTamano,
		pSisHaruTexto->HpdfDocPtrArchivo,
		pSisHaruTexto->HpdfPagePtrPagina,
		SiscomCampoAsociadoEntradaOperacion("Envio","Importe",pSisOpePtrDato));

 SiscomHaruPdfTexto(pSisHaruTexto->intX,
 		   pSisHaruTexto->intY-10,
		pSisHaruTexto->chrPtrTipoLetra,
		pSisHaruTexto->intTamano,
		pSisHaruTexto->HpdfDocPtrArchivo,
		pSisHaruTexto->HpdfPagePtrPagina,
		"I.V.A.");


/*

 SiscomHaruPdfTexto(pSisHaruTexto->intX-30,
 		   pSisHaruTexto->intY-10,
		pSisHaruTexto->chrPtrTipoLetra,
		pSisHaruTexto->intTamano,
		pSisHaruTexto->HpdfDocPtrArchivo,
		pSisHaruTexto->HpdfPagePtrPagina,
		"Impuesto Trasladado");

*/

 SiscomHaruPdfTexto(pintXImporte,
 		   pSisHaruTexto->intY-10,
		pSisHaruTexto->chrPtrTipoLetra,
		pSisHaruTexto->intTamano,
		pSisHaruTexto->HpdfDocPtrArchivo,
		pSisHaruTexto->HpdfPagePtrPagina,
	 	SiscomCampoAsociadoEntradaOperacion("Envio","Iva",pSisOpePtrDato));

/*
 SiscomHaruPdfTexto(pSisHaruTexto->intX,
 		   pSisHaruTexto->intY-20,
		pSisHaruTexto->chrPtrTipoLetra,
		pSisHaruTexto->intTamano,
		pSisHaruTexto->HpdfDocPtrArchivo,
		pSisHaruTexto->HpdfPagePtrPagina,
		"Impuesto Retenido");


 SiscomHaruPdfTexto(pintXImporte,
 		   pSisHaruTexto->intY-20,
		pSisHaruTexto->chrPtrTipoLetra,
		pSisHaruTexto->intTamano,
		pSisHaruTexto->HpdfDocPtrArchivo,
		pSisHaruTexto->HpdfPagePtrPagina,
	 	SiscomCampoAsociadoEntradaOperacion("Envio","Iva",pSisOpePtrDato));

*/


 SiscomHaruPdfTexto(pSisHaruTexto->intX,
 		   pSisHaruTexto->intY-20,
		pSisHaruTexto->chrPtrTipoLetra,
		pSisHaruTexto->intTamano,
		pSisHaruTexto->HpdfDocPtrArchivo,
		pSisHaruTexto->HpdfPagePtrPagina,
		"Total");

 SiscomHaruPdfTexto(pintXImporte,
 		   pSisHaruTexto->intY-20,
		pSisHaruTexto->chrPtrTipoLetra,
		pSisHaruTexto->intTamano,
		pSisHaruTexto->HpdfDocPtrArchivo,
		pSisHaruTexto->HpdfPagePtrPagina,
	 	SiscomCampoAsociadoEntradaOperacion("Envio","Total",pSisOpePtrDato));

}
int MuestraSelloPdf(SiscomHaruTexto *pSisHaruTexto,
		    const char *pchrPtrSello,
		    SiscomOperaciones *pSisOpePtrDato)
{
int lintCopiando,lintContando=0;
int lintNCaracteres;
const char *lchrPtrSello;
char lchrArrPaso[1024],*lchrPtrPaso;
lchrPtrSello=SiscomCampoAsociadoEntradaOperacion("Envio",pchrPtrSello,pSisOpePtrDato);
lintNCaracteres=strlen(lchrPtrSello);
lintCopiando=lintNCaracteres/4;
lchrPtrPaso=lchrArrPaso;
pSisHaruTexto->intX=60;
/*pSisHaruTexto->intY-=80; */
pSisHaruTexto->intTamano=10;
SiscomHaruEscribe(pSisHaruTexto,pchrPtrSello);
pSisHaruTexto->intY-=10;
pSisHaruTexto->intTamano=5;
while(lintContando<lintNCaracteres)
{
  strncpy(lchrPtrPaso,lchrPtrSello+lintContando,lintCopiando);
  *(lchrPtrPaso+lintCopiando)=0;
  LogSiscom("%s",lchrPtrPaso);
  SiscomHaruEscribe(pSisHaruTexto,lchrPtrPaso);
  lintContando+=lintCopiando;
  pSisHaruTexto->intY-=7;
}


}
int DatosTimbradoPdf(HPDF_REAL pHpdfRealAlto,
		     HPDF_REAL pHpdfRealAncho,
		     SiscomHaruTexto *pSisHaruTexto,
		     SiscomOperaciones *pSisOpePtrDato)
{
HPDF_Image lHpdfImagen;
HPDF_Destination lHpdfDestination;
LogSiscom("%s",SiscomCampoAsociadoEntradaOperacion("Envio", "SelloCFDI", pSisOpePtrDato));
LogSiscom("%s",SiscomCampoAsociadoEntradaOperacion("Envio", "SelloSAT", pSisOpePtrDato));
LogSiscom("%s",SiscomCampoAsociadoEntradaOperacion("Envio", "FolioFiscal", pSisOpePtrDato));
LogSiscom("%s",SiscomCampoAsociadoEntradaOperacion("Envio", "Certificado", pSisOpePtrDato));

pSisHaruTexto->intY=180;
pSisHaruTexto->intX=60;
pSisHaruTexto->intTamano=10;
SiscomHaruEscribe(pSisHaruTexto,"Importe Con Letra");
pSisHaruTexto->intY-=10;
pSisHaruTexto->intTamano=7;
SiscomHaruEscribe(pSisHaruTexto,SiscomCampoAsociadoEntradaOperacion("Envio","TotalLetra",pSisOpePtrDato));
pSisHaruTexto->intY=300;
HPDF_Page_Rectangle(pSisHaruTexto->HpdfPagePtrPagina,
		    50,
		    50,
		    pHpdfRealAncho-100,
		    pHpdfRealAlto-90);
lHpdfDestination=HPDF_Page_CreateDestination(pSisHaruTexto->HpdfPagePtrPagina);
HPDF_Destination_SetXYZ(lHpdfDestination,
			0,
			HPDF_Page_GetHeight(pSisHaruTexto->HpdfPagePtrPagina),
			1);
HPDF_SetOpenAction(pSisHaruTexto->HpdfDocPtrArchivo,lHpdfDestination);

lHpdfImagen=HPDF_LoadJpegImageFromFile(pSisHaruTexto->HpdfDocPtrArchivo, 
				      "/home/hgarduno/ArchivosFacturacionSiscom/QR.SiscomFacturacion.jpg");

HPDF_Page_Stroke(pSisHaruTexto->HpdfPagePtrPagina);
HPDF_Page_DrawImage(pSisHaruTexto->HpdfPagePtrPagina,
		   lHpdfImagen,
		   348,
		   60,
		   80,
		   80);

pSisHaruTexto->intY-=150;
MuestraSelloPdf(pSisHaruTexto,"SelloCFDI",pSisOpePtrDato);
pSisHaruTexto->intY-=7;
MuestraSelloPdf(pSisHaruTexto,"SelloSAT",pSisOpePtrDato);

}
int FormandoPaginasFacturaPdf(HPDF_REAL pHpdfRealAlto,
			      HPDF_REAL pHpdfRealAncho,
			      SiscomHaruTexto *pSisHaruTexto,
			      SiscomRegistroProL *pSisRegProLPtrUltimoProducto,
			      SiscomOperaciones *pSisOpePtrDato)
{
static int lintNVeces=0;
char lchrArrCadena[256],
	lchrArrBuffer[1024];
int lintXImporte;
SiscomRegistroProL *lSisRegProLPtrProductos,
		   *lSisRegProLPtrUltimoProducto;

if(!pSisRegProLPtrUltimoProducto)
lSisRegProLPtrProductos=SiscomRegistroAsociadoEntradaOperacion("Envio","Productos",pSisOpePtrDato);
else
lSisRegProLPtrProductos=pSisRegProLPtrUltimoProducto;
FormaPaginaPdf(pHpdfRealAlto, pHpdfRealAncho, pSisHaruTexto, "Pagina 1");

 pSisHaruTexto->intX=150;
 pSisHaruTexto->intY=pHpdfRealAlto-45;
 pSisHaruTexto->chrPtrTipoLetra="Helvetica";
 pSisHaruTexto->intTamano=10;
 pSisHaruTexto->intY-=10;

 SiscomHaruEscribe(pSisHaruTexto,
	 	  SiscomCampoAsociadoRespuestaOperacion("AmbienteTimbrado","razonsocial",pSisOpePtrDato));
 pSisHaruTexto->intY-=10;
 sprintf(lchrArrCadena,
 	 "RFC: %s",
	 SiscomCampoAsociadoRespuestaOperacion("AmbienteTimbrado","rfcemisor",pSisOpePtrDato));
 SiscomHaruEscribe(pSisHaruTexto,lchrArrCadena);
DireccionEmisorPdf(pHpdfRealAlto,
		pHpdfRealAncho,
		pSisHaruTexto,
		pSisOpePtrDato);
DatosReceptorPdf(pHpdfRealAlto,
		 pHpdfRealAncho,
		 pSisHaruTexto,
		 pSisOpePtrDato);
DatosComprobantePdf(pHpdfRealAlto,
		    pHpdfRealAncho,
		    pSisHaruTexto,
		    pSisOpePtrDato);


if((lSisRegProLPtrUltimoProducto=FormaTablaProductosPdf(pHpdfRealAlto,
		    pHpdfRealAncho,
		    pSisHaruTexto,
		    lSisRegProLPtrProductos,
		    &pSisHaruTexto->intY,
		    &pSisHaruTexto->intX,
		    &lintXImporte)))
 {
     pSisHaruTexto->HpdfPagePtrPagina=HPDF_AddPage(pSisHaruTexto->HpdfDocPtrArchivo);
     FormandoPaginasFacturaPdf(pHpdfRealAlto,
     			       pHpdfRealAncho,
			       pSisHaruTexto,
			       lSisRegProLPtrUltimoProducto,
			       pSisOpePtrDato);
 
 }
 if(!lintNVeces)
 {
ImporteIvaTotalesPdf(pSisHaruTexto,lintXImporte,pSisOpePtrDato);
DatosTimbradoPdf(pHpdfRealAlto,pHpdfRealAncho,pSisHaruTexto,pSisOpePtrDato);
lintNVeces++;
}
} 

int PdfFacturaSiscomElectronica(SiscomOperaciones *pSisOpePtrDato)
{
HPDF_REAL lHpdfRealAlto;
HPDF_REAL lHpdfRealAncho;
char lchrArrArchivoPdf[1024];
SiscomHaruTexto lSisHaruTexto,
  		*lSisHaruTextoD=&lSisHaruTexto;
NombreArchivoFacturacion_4_0(pSisOpePtrDato,".pdf",lchrArrArchivoPdf);
LogSiscom("%s",lchrArrArchivoPdf);
IniciandoArchivoPdf(lSisHaruTextoD);
lHpdfRealAlto=HPDF_Page_GetHeight(lSisHaruTextoD->HpdfPagePtrPagina);
lHpdfRealAncho=HPDF_Page_GetWidth(lSisHaruTextoD->HpdfPagePtrPagina);
/*
HPDF_Page_SetLineWidth(lSisHaruTextoD->HpdfPagePtrPagina,1);
*/
FormandoPaginasFacturaPdf(lHpdfRealAlto,
			  lHpdfRealAncho,
			  lSisHaruTextoD,
			  0,
			  pSisOpePtrDato);

HPDF_SaveToFile(lSisHaruTextoD->HpdfDocPtrArchivo,lchrArrArchivoPdf);
HPDF_Free(lSisHaruTextoD->HpdfDocPtrArchivo);
}
