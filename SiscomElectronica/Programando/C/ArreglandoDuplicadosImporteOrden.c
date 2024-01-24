#include <ArreglandoDuplicadosImporteOrden.h>
#include <SiscomFuncionesComunes.h>
#include <SiscomErrores.h>
#include <string.h>
#include <stdlib.h>


FILE *gPtrFleArchivoLog;
int gintSocketProtocoloLog;
SiscomError gSiscomErrorSistema;
/* Tepotzotlan Mexico a Jueves 27 de Julio del 2017
 * el programa tomara de la entrada estandar el 
 * resultado de ejecuta un query de la siguiente 
 * manera
 *  echo 'select ctid,idventa from importeorden ' |psql -t SiscomElectronica
 *  , con esta informacion tomara el idventa, buscando los registros duplicados
 *  generara un delete con el ctid, para eliminar los duplicados
 */

int main(int pintArgc,
	 char **pchrPtrArgv)
{
int lintNRegistros,lintContador;
FILE *lFlePtrArchivo;
zCTIDIdVenta *lzCTIDIdVentaReg;
lFlePtrArchivo=AbreArchivo(NombreArchivo(pintArgc,pchrPtrArgv));
gPtrFleArchivoLog=stdout;
lintNRegistros=CargaInformacion(lFlePtrArchivo,&lzCTIDIdVentaReg);
ObtenIdsVentaDuplicados(*(pchrPtrArgv+2),lintNRegistros,lzCTIDIdVentaReg);
}

FILE *AbreArchivo(const char *pchrPtrArchivo)
{
FILE *lFlePtrArchivo;

if(!pchrPtrArchivo)
 return stdin;
else
{
 if((lFlePtrArchivo=fopen(pchrPtrArchivo,"r")))
 return lFlePtrArchivo;
}


}
const char *NombreArchivo(int pintArgc,char **pchrPtrArgv)
{
   if(pintArgc==1)
   return 0;
   else
	return *(pchrPtrArgv+1);
}
void SiscomEliminaEspaciosInicioAqui(char *pchrPtrCadena)
{
char *lchrPtrPaso=pchrPtrCadena;
   while(*pchrPtrCadena && 
         *pchrPtrCadena==' ')
    pchrPtrCadena++;

 strcpy(lchrPtrPaso,pchrPtrCadena);

}
void ObtenCTIDIdVenta(const char *pchrPtrLinea,char *pchrPtrCTID,char *pchrPtrIdVenta)
{
char lchrArrBuffer[TAMANOBUFFER];
const char *lchrPtrPaso;
char **lchrPtrCampos;
	if(SiscomAnalizaCadenas(pchrPtrLinea,'|',lchrArrBuffer,&lchrPtrCampos))
	{
	   strcpy(pchrPtrCTID,*(lchrPtrCampos+0));
	   strcpy(pchrPtrIdVenta,*(lchrPtrCampos+1));
	   SiscomEliminaEspaciosFinal(pchrPtrCTID);
	   SiscomEliminaEspaciosInicioAqui(pchrPtrCTID);
	   SiscomEliminaEspaciosInicioAqui(pchrPtrIdVenta);
	   SiscomLiberaCadenas(lchrPtrCampos);
	}
}
int CargaInformacion(FILE *pFlePtrArchivo,zCTIDIdVenta **pzCTIDIdVentaReg)
{
char lchrArrLinea[TAMANOBUFFER],
	lchrArrCTID[28],
	lchrArrIdVenta[TAMANOBUFFER];
int lintContador=0;
*pzCTIDIdVentaReg=(zCTIDIdVenta *)malloc(sizeof(zCTIDIdVenta));

while(SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea)!=EOF)
{
  *pzCTIDIdVentaReg=(zCTIDIdVenta *)realloc(*pzCTIDIdVentaReg,sizeof(zCTIDIdVenta)*(lintContador+1));
  ObtenCTIDIdVenta(lchrArrLinea, 
  		   ((*pzCTIDIdVentaReg)+lintContador)->chrArrCTID, 
		   ((*pzCTIDIdVentaReg)+lintContador)->chrArrIdVenta);
  lintContador++;
}
return lintContador;
}

void ObtenIdsVentaDuplicados(const char *pchrPtrSqlDelete,int pintNRegistros,zCTIDIdVenta *pzCTIDIdVenta)
{
int lintContador,
    lintContadorI;
    for(lintContadorI=0;lintContadorI<pintNRegistros;lintContadorI++)
   for(lintContador=lintContadorI+1;lintContador<pintNRegistros;lintContador++)
{
	if(!strcmp((pzCTIDIdVenta+lintContadorI)->chrArrIdVenta,
		   (pzCTIDIdVenta+lintContador)->chrArrIdVenta))
	{
	/*
 	printf("Duplicado %s %s\n",
	(pzCTIDIdVenta+lintContador)->chrArrCTID,
	(pzCTIDIdVenta+lintContador)->chrArrIdVenta);
	*/
	
	printf("%s where ctid='%s';\n",pchrPtrSqlDelete, (pzCTIDIdVenta+lintContador)->chrArrCTID);
	}
}
}
