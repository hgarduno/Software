#include <zTextoWhatsApp.h>
#include <zOrdenVenta.h>
#include <zProductoCotizar.h>
#include <zSiscomRegistros.h>
#include <zSiscomDesarrollo4.h>
#include <zCotizacion.h>
#include <string.h>
#include <stdlib.h>
zTextoWhatsApp::zTextoWhatsApp(zOrdenVenta *pzOrdVenta):
				zOrdVenta(pzOrdVenta)
{
  
}
zTextoWhatsApp::~zTextoWhatsApp()
{
  LogSiscom("");
}
void zTextoWhatsApp::Lista(char **pchrPtrCadena)
{

char lchrArrLinea[256];
zProductoCotizar *lzProdCotizar;
int lintContador=1;
for(lzProdCotizar=(zProductoCotizar *)zOrdVenta->Productos()->Primer();
    lzProdCotizar;
    lzProdCotizar=(zProductoCotizar *)zOrdVenta->Productos()->Siguiente())
{
     if(CadenaLlena(lintContador,*pchrPtrCadena,lchrArrLinea))
     {
      ReAsignaBuffer(lintContador,pchrPtrCadena);
      lintContador++;
     }
     else
     {
     AgregaLineaProducto(lzProdCotizar,lchrArrLinea);
     strcat(*pchrPtrCadena,lchrArrLinea);
     }
}
}
int zTextoWhatsApp::CadenaLlena(int pintContador,
				const char *pchrPtrCadena,
				const char *pchrPtrLinea)
{
int lintTamanoActual;
	lintTamanoActual=strlen(pchrPtrCadena)+strlen(pchrPtrLinea);
      return lintTamanoActual > pintContador*1024;
}
const char *zTextoWhatsApp::CadenaDescripcionCotizacion()
{
char **lchrPtrLineas,*lchrPtrPaso,**lchrPtrPasito;
char lchrArrRegreso[1024],lchrArrLinea[128];

lchrPtrPaso=lchrArrRegreso;


  zSiscomDesarrollo4::CadenasPorSeparador(zOrdVenta->Cotizacion()->Descripcion(),
  					  '\n',
					  &lchrPtrLineas);

*lchrPtrPaso=0;
lchrPtrPasito=lchrPtrLineas;

  while(*lchrPtrLineas)
  {
     //CadenaConNegritas(*lchrPtrLineas,lchrArrLinea);
     //strcat(lchrPtrPaso,lchrArrLinea);
     strcat(lchrPtrPaso,*lchrPtrLineas);
     strcat(lchrPtrPaso,"\n");
   lchrPtrLineas++;
  }
zSiscomDesarrollo4::LiberaCadenas(lchrPtrPasito);
return strdup(lchrPtrPaso);
}
const char *zTextoWhatsApp::DescripcionCotizacion()
{
 if(zOrdVenta 			&& 
    zOrdVenta->Cotizacion() 	&&
    zOrdVenta->Cotizacion()->Descripcion())
  return zOrdVenta->Cotizacion()->Descripcion();
 else
 return "";
}
void zTextoWhatsApp::Cliente(char *pchrPtrCadena)
{
sprintf(pchrPtrCadena,
	"*Siscom Electronica*		\n"
	"Fecha: *%s*			\n"
	"# Cotizacion *%s*   		\n"
	"%s				\n"
	"\n\n",
	zOrdVenta->Fecha(),
	zOrdVenta->IdVenta(),
	CadenaDescripcionCotizacion());
}
void zTextoWhatsApp::Total(char *pchrPtrCadena)
{
sprintf(pchrPtrCadena,"*Total $%s*",zOrdVenta->ImporteOrden());
}
void zTextoWhatsApp::CotizacionWhats(char **pchrPtrCadena)
{
char lchrArrTotal[128];
IniciaBuffer(pchrPtrCadena);
Cliente(*pchrPtrCadena);  
Lista(pchrPtrCadena);
strcat(*pchrPtrCadena,"\n");
Total(lchrArrTotal);
strcat(*pchrPtrCadena,lchrArrTotal);
}
void zTextoWhatsApp::CadenaConNegritas(const char *pchrPtrCadena,
				       char *pchrPtrSalida)
{
  sprintf(pchrPtrSalida,"*%s*",pchrPtrCadena);
}
void zTextoWhatsApp::AgregaLineaProducto(zProductoCotizar *pzProdCot,
					 char *pchrPtrLinea)
{
char lchrArrCveProducto[256];
CadenaConNegritas(pzProdCot->Clave(),lchrArrCveProducto);
sprintf(pchrPtrLinea,
	"%-10s%-50s%-12s%-12s\n",
	pzProdCot->Cantidad(),
	lchrArrCveProducto,
	pzProdCot->Precio(),
	pzProdCot->Importe());
}
void zTextoWhatsApp::IniciaBuffer(char **pchrPtrBuffer)
{
  if(*pchrPtrBuffer==0) 
    *pchrPtrBuffer=(char *)malloc(1024);
}
void zTextoWhatsApp::ReAsignaBuffer(int pintContador,char **pchrPtrBuffer)
{
int lintTamBuffer;
     lintTamBuffer=strlen(*pchrPtrBuffer);
       lintTamBuffer+=1024;
       *pchrPtrBuffer=(char *)realloc(*pchrPtrBuffer,lintTamBuffer);
}

void zTextoWhatsApp::PrecioProducto(zOrdenVenta *pzOrdenV,
				    char *pchrPtrTexto)
{
char lchrArrSePuedeVender[256];
if(pzOrdenV->Producto(0)->SePuedeVender())
sprintf(lchrArrSePuedeVender,
	"Si tenemos *Existencia del producto*"
	"				     \n"
	":) :) :) :) :)");
else
sprintf(lchrArrSePuedeVender,
	"No tenemos *Existencia del producto*\n"
	"					\n"
	":( :( :( :(");


 sprintf(pchrPtrTexto,
 	 "*Siscom Electronica*\n"
	 "			\n"
	 "			\n"
	 "El Precio del *%s* es de *$%s*\n"
	 "				\n"
	 "%s				\n",
	 pzOrdenV->Clave(0),
	 pzOrdenV->Precio(0),
	 lchrArrSePuedeVender);
}
