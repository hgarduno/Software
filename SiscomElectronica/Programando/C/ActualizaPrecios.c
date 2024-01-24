#include <stdio.h>
#include <string.h>
#include <SiscomFuncionesComunes.h>
#include <SiscomErrores.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomLineaComandos.h>

FILE *gPtrFleArchivoLog;
int gintSocketProtocoloLog;

SiscomError gSiscomErrorSistema;

FILE *AbreArchivo(const char *pchrPtrArchivo)
{
  if(!pchrPtrArchivo)
  return stdin;

}
void CveProductoPrecio(const char *pchrPtrLinea,
		       char *pchrPtrCveProducto,
		       char *pchrPtrPrecio)
{
char **lchrPtrCadenas;
char lchrArrBuffer[256];
if(SiscomAnalizaCadenas(pchrPtrLinea,'|',lchrArrBuffer,&lchrPtrCadenas))
{
    strcpy(pchrPtrCveProducto,*(lchrPtrCadenas+0));
    strcpy(pchrPtrPrecio,*(lchrPtrCadenas+1));

}

}
void Leyendo()
{
FILE *lFlePtrArchivo;
char lchrArrLinea[256],lchrArrCveProducto[256],lchrArrPrecio[28];
if((lFlePtrArchivo=AbreArchivo(0)))
{
    while(SiscomLeeLineaArchivo(lFlePtrArchivo,lchrArrLinea)!=EOF)
    {
      CveProductoPrecio(lchrArrLinea,lchrArrCveProducto,lchrArrPrecio);
      printf("update precios set precio=%s where cveproducto='%s';\n",
      	      lchrArrPrecio,
      	      lchrArrCveProducto);
    }
}

}
int main(int pintArgc,char **pchrPtrArgv)
{

    Leyendo();
}
