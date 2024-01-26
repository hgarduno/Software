#include <InsercionesArchivoSql.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomFuncionesComunes.h>
#include <Principal.h>
#include <EjecutaSql.h>
void ProcesaArchivos(const char *pchrPtrDirServiSNTE,
		    const char *pchrPtrDirScriptsSql,
		    const char *pchrPtrVariable,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char **lchrPtrScriptsSql;
SiscomObtenVariableArregloACharChar(&gSiscomDatIni, pchrPtrVariable, &lchrPtrScriptsSql);
CargaArchivosSql(pchrPtrDirServiSNTE,
		 pchrPtrDirScriptsSql,
		 lchrPtrScriptsSql,
		 pSiscomRegProLPtrSqlPrim,
		 pSiscomRegProLPtrSqlAct);


}

void CargaArchivosSql(const char *pchrPtrDirServiSNTE,
		      const char *pchrPtrDirTablasSql,
		      char **pchrPtrArchivos,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
char lchrArrArchivo[1024];
while(*pchrPtrArchivos)
{
sprintf(lchrArrArchivo,
	"%s/%s/%s",
	pchrPtrDirServiSNTE,
	pchrPtrDirTablasSql,
	*pchrPtrArchivos);
CargaArchivoSql(lchrArrArchivo,
		 pSiscomRegProLPtrSqlPrim,
		 pSiscomRegProLPtrSqlAct);
pchrPtrArchivos++;
}

}
void CargaArchivoSql(const char *pchrPtrArchivo,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlPrim,
		   SiscomRegistroProL **pSiscomRegProLPtrSqlAct)
{
FILE *lFlePtrArchivo;
char lchrArrSentenciaSql[32000],
	lchrArrBuffer[32000];
if((lFlePtrArchivo=fopen(pchrPtrArchivo,"r")))
{
 /*
  * Domingo 19 de Junio del 2016 
  * Se cambio todo el proceso a construir las sentencias 
  * Sql y ponerlas en pSiscomRegProLPtrSql.. para poder 
  * ejecutarlas desde el programa y no desde el manejador
  * y asi aplicar algunas reglas de negocio que son necesarias
  * como en la insercion de los creditos que nos pasaron en 
  * el archivo
  while(SiscomLeeLineaArchivo(lFlePtrArchivo,lchrArrLinea)!=EOF)
  {
  */
  	/* Queretaro 16 Septiembre del 2015
	 * Esta funcion se debera modificar para que se pueda leer 
	 * la sentencia sql hasta el ";"  ya que esta funcion 
	 * toma una sentencia Sql no una linea
	 *
    	EjecutaSentenciaSql(lchrArrLinea);	
	*/
	/*
	printf("%s\n",lchrArrLinea);

  }
  */
     while(LeeSentenciaSql(lFlePtrArchivo,lchrArrSentenciaSql))
     {
        if(lchrArrSentenciaSql[0])
     	SiscomAnexaRegistroPro(pSiscomRegProLPtrSqlPrim,
			       pSiscomRegProLPtrSqlAct,
			       lchrArrBuffer,
			       "SentenciaSql,EstadoRegistro,",
			       lchrArrSentenciaSql,
			       0);
     }
fclose(lFlePtrArchivo);
}
}
int LeeSentenciaSql(FILE *pFlePtrArchivo,
		     char *pchrPtrSql)
{
int lintCaracter;
   	while((lintCaracter=getc(pFlePtrArchivo))!=';' &&
	      lintCaracter!=EOF)
	{
	   *pchrPtrSql=lintCaracter;
	   pchrPtrSql++;
	}
	if(lintCaracter==';')
	 lintCaracter=getc(pFlePtrArchivo);
	*pchrPtrSql=0;
   return lintCaracter==EOF ? 0 : 1;
}
