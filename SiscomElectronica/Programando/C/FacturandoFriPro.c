#include <FacturandoFriPro.h>
#include <string.h>
#include <error.h>

#include <SiscomDesarrolloMacros.h>


void FacturandoFriPro(StcSiscomOpciones *pStcPtrSisOpciones,
		      SiscomRegistroProL *pSisRegProLConfig)
{
float lfltIva,
	lfltImporte,
	lfltTotal;
char lchrArrFechaHora[128],
	*lchrPtrImporteLetra;
SiscomObtenFechaHoraActualAAAADDMM(lchrArrFechaHora);
  ImportesFactura(pStcPtrSisOpciones,&lfltIva,&lfltImporte,&lfltTotal);
  SiscomALetra(lfltTotal,&lchrPtrImporteLetra);
  FormaArchivoSiscomFacturaGeneral(pStcPtrSisOpciones,
  				  pSisRegProLConfig,
  			    lchrArrFechaHora,
			    lchrPtrImporteLetra,
			    lfltIva,
			    lfltImporte,
			    lfltTotal);
  SiscomCambiaCaracter(':','_',lchrArrFechaHora);
  SiscomCambiaCaracter('-','_',lchrArrFechaHora);
  SiscomCambiaCaracter('T','_',lchrArrFechaHora);
  EjecutandoFacturacion(pStcPtrSisOpciones,pSisRegProLConfig,lchrArrFechaHora); 
}
void ImportesFactura(StcSiscomOpciones *pStcPtrSisOpciones,
		     float *pfltPtrIva,
		     float *pfltPtrImporte,
		     float *pfltPtrTotal)
{
float lfltImporte;

*pfltPtrTotal=SiscomOpcionAFloat("Importe",pStcPtrSisOpciones);
*pfltPtrImporte=*pfltPtrTotal/1.16;
*pfltPtrIva=*pfltPtrImporte*.16;
}

void FormaArchivoSiscomFactura(StcSiscomOpciones *pStcPtrSisOpciones,
				const char *pchrPtrFechaHora,
				const char *pchrPtrImporteLetra,
			       float pfltIva,
			       float pfltImporte,
			       float pfltTotal)
{
FILE *lFlePtrArchivo;

char lchrArrArcFactura[2048];

sprintf(lchrArrArcFactura,
"%s|%s|01|28 (Tarjeta Debito)|%.2f|%.2f|PUE|%s||\n"
"%s|Soluciones En Sistemas de Cómputo y Electrónica S.A. de C.V.||\n"
"Eva Samano de López Mateos|28|1|Bo Tlacateco|Tepotzotlan|México|México|54600||\n"
"Régimen General|601|\n"
"FRI150701RDA|FRIPRO SA De CV|P01|\n"
"Lago Alberto|320 A03|0|Anahuac 1 Seccion|Miguel Hidalgo|CDMX|Mexico|11320||\n"
"%.2f||\n"
"1.00|32101600|H87|%s|%.2f|DESSIS|Pieza|%.2f|%.2f|",
SiscomOpcionAChar("Folio",pStcPtrSisOpciones),
pchrPtrFechaHora,
pfltImporte,
pfltTotal,
pchrPtrImporteLetra,
RfcAmbiente(pStcPtrSisOpciones),
pfltIva,
SiscomOpcionAChar("Concepto",pStcPtrSisOpciones),
pfltImporte,
pfltImporte,
pfltIva);

if((lFlePtrArchivo=fopen("FriPro.SiscomFacturacion","w")))
{
  fprintf(lFlePtrArchivo,"%s",lchrArrArcFactura);
  fclose(lFlePtrArchivo);
}

}
/* Jueves 20 Septiembre 2018 
 *
 *  Se debe agregar los datos de Direccion y RFC para facturar 
 *  a otras empresas 
 */

void FormaArchivoSiscomFacturaGeneral(StcSiscomOpciones *pStcPtrSisOpciones,
				SiscomRegistroProL *pSisRegProLConfig,
				const char *pchrPtrFechaHora,
				const char *pchrPtrImporteLetra,
			       float pfltIva,
			       float pfltImporte,
			       float pfltTotal)
{
FILE *lFlePtrArchivo;
char lchrArrBuffer[128];
char lchrArrArcFactura[2048];
char lchrArrArchivo[256];

sprintf(lchrArrArcFactura,
"%s|%s|%s|%s|%.2f|%.2f|PUE|%s||\n"
"%s|Soluciones En Sistemas de Cómputo y Electrónica S.A. de C.V.||\n"
"Eva Samano de López Mateos|28|1|Bo Tlacateco|Tepotzotlan|México|México|54600||\n"
"Régimen General|601|\n"
"%s|%s|P01|\n"
"%s|%s|%s|%s|%s|%s|%s|%s||\n"
"%.2f||\n"
"1.00|32101600|H87|%s|%.2f|DESSIS|Pieza|%.2f|%.2f|",
SiscomOpcionAChar("Folio",pStcPtrSisOpciones),
pchrPtrFechaHora,
SiscomOpcionAChar("CodigoFormaPago",pStcPtrSisOpciones),
SiscomOpcionAChar("FormaPago",pStcPtrSisOpciones),
pfltImporte,
pfltTotal,
pchrPtrImporteLetra,
RfcAmbiente(pStcPtrSisOpciones),
SiscomObtenCampoRegistroProLChar("Rfc",pSisRegProLConfig),
SiscomObtenCampoRegistroProLChar("RazonSocial",pSisRegProLConfig),
SiscomObtenCampoRegistroProLChar("Calle",pSisRegProLConfig),
SiscomObtenCampoRegistroProLChar("Numero",pSisRegProLConfig),
SiscomObtenCampoRegistroProLChar("NumeroInt",pSisRegProLConfig),
SiscomObtenCampoRegistroProLChar("Colonia",pSisRegProLConfig),
SiscomObtenCampoRegistroProLChar("Delegacion",pSisRegProLConfig),
SiscomObtenCampoRegistroProLChar("Estado",pSisRegProLConfig),
SiscomObtenCampoRegistroProLChar("Pais",pSisRegProLConfig),
SiscomObtenCampoRegistroProLChar("Cp",pSisRegProLConfig),
pfltIva,
SiscomOpcionAChar("Concepto",pStcPtrSisOpciones),
pfltImporte,
pfltImporte,
pfltIva);
sprintf(lchrArrArchivo,"%s.SiscomFacturacion",SiscomObtenCampoRegistroProLChar("Prefijo",pSisRegProLConfig));
if((lFlePtrArchivo=fopen(lchrArrArchivo,"w")))
{
  fprintf(lFlePtrArchivo,"%s",lchrArrArcFactura);
  fclose(lFlePtrArchivo);
}
}
const char *RfcAmbiente(StcSiscomOpciones *pStcPtrSisOpciones)
{
const char *lchrPtrAmbiente=SiscomOpcionAChar("Ambiente",pStcPtrSisOpciones);
   if(lchrPtrAmbiente)
   {
    if(!strcmp("Produccion",lchrPtrAmbiente))
    return RfcSiscomProduccion();
    else
    if(!strcmp("Pruebas",lchrPtrAmbiente))
    return RfcSiscomPruebas();
  }
  else
    return RfcSiscomPruebas();
}
const char *RfcSiscomProduccion()
{
 return "SSC160604EF3";
}
const char *RfcSiscomPruebas()
{
 return "AAA010101AAA";
}

void EjecutandoFacturacion(StcSiscomOpciones *pStcPtrSisOpciones,
			   SiscomRegistroProL *pSisRegProLConfig,
			   const char *pchrPtrPrefijoArchivo)
{
FILE *lFlePtrEjecucion=0;
const char *lchrPtrComando;
char lchrArrLinea[1024];
if((lchrPtrComando=ComandoFacturacion(pStcPtrSisOpciones,
				      pSisRegProLConfig,
				      pchrPtrPrefijoArchivo)))
{
 printf("%s\n",lchrPtrComando);
  if((lFlePtrEjecucion=popen(lchrPtrComando,"r")))
  {
	MensajesEjecucion(lFlePtrEjecucion);	
        pclose(lFlePtrEjecucion);
  }
  else
  {
    LogSiscom("NOOOOO ");
  }
}
}
void MensajesEjecucion(FILE *pFlePtrEjecucion)
{
char lchrArrLinea[2048];
   while(SiscomLeeLineaArchivo(pFlePtrEjecucion,lchrArrLinea)!=-1)
    printf("%s\n",lchrArrLinea);
}
const char *ComandoFacturacion(StcSiscomOpciones *pStcPtrSisOpciones,
			       SiscomRegistroProL *pSisRegProLPtrConf,
			       const char *pchrPtrPrefijoArchivo)
{
char lchrArrComando[4192];
char lchrArrArchivoFacturacion[1024];
sprintf(lchrArrArchivoFacturacion,"%s.SiscomFacturacion",SiscomObtenCampoRegistroProLChar("Prefijo",pSisRegProLPtrConf));
sprintf(lchrArrComando,
	"%s %s/SiscomFacturacion.php %s %s %s %s %s \"%s\" \"%s\" %s_%s %s",
	SiscomOpcionAChar("Php",pStcPtrSisOpciones),
	SiscomOpcionAChar("DirFacturacion",pStcPtrSisOpciones),
	SiscomOpcionAChar("DirFacturacion",pStcPtrSisOpciones),
	lchrArrArchivoFacturacion,
	"hgarduno@gmail.com",
	"hgarduno@siscomelectronica.com",
	"Heli1972Esquivel",
	UsuarioTimbrado(pStcPtrSisOpciones),
	ServidorTimbrado(pStcPtrSisOpciones),
	SiscomObtenCampoRegistroProLChar("Prefijo",pSisRegProLPtrConf),
	pchrPtrPrefijoArchivo,
	"Envio");
LogSiscom("%s",lchrArrComando);
return strdup(lchrArrComando);
}
const char *UsuarioTimbrado(StcSiscomOpciones *pStcPtrSisOpciones)
{
const char *lchrPtrAmbiente=SiscomOpcionAChar("Ambiente",pStcPtrSisOpciones);
  if(lchrPtrAmbiente)
  {
   if(!strcmp("Produccion",lchrPtrAmbiente))
   return UsuarioTimbradoProduccion();
   else
   if(!strcmp("Pruebas",lchrPtrAmbiente))
   return UsuarioTimbradoPruebas();
   }
   else
   return UsuarioTimbradoPruebas();

}
const char *ServidorTimbrado(StcSiscomOpciones *pStcPtrSisOpciones)
{
const char *lchrPtrAmbiente=SiscomOpcionAChar("Ambiente",pStcPtrSisOpciones);
   if(lchrPtrAmbiente)
   {
   if(!strcmp("Produccion",lchrPtrAmbiente))
   return ServidorTimbradoProduccion();
   else
   if(!strcmp("Pruebas",lchrPtrAmbiente))
   return ServidorTimbradoPruebas();
   }
   else
   return ServidorTimbradoPruebas();

}

const char *UsuarioTimbradoProduccion()
{
  return "92Uo9Zn1plulh1T2mu5RRQ==|92Uo9Zn1plulh1T2mu5RRQ==";
}
const char *ServidorTimbradoProduccion()
{
 return "https://timbracfdi33.mx:1443/Timbrado.asmx?wsdl";
}

const char *UsuarioTimbradoPruebas()
{
 return "mvpNUXmQfK8=|";
}
const char *ServidorTimbradoPruebas()
{
 return "https://cfdi33-pruebas.buzoncfdi.mx:1443/Timbrado.asmx?wsdl";
}
