#include <EjecutaSql.h>
#include <string.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomFuncionesComunes.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomOperacionesDirectorios.h>
#include <Principal.h>
#include <stdlib.h>
int ArchivosDirectorio(const char *pchrPtrDirectorio,
			SiscomRegistroProL **pSiscomRegProLPtrPrim,
			SiscomRegistroProL **pSiscomRegProLPtrAct)
{
char lchrArrArchivo[256];
SiscomArchivosDirectorio *lSiscomArchsDirectorioPrim=0,
			 *lSiscomArchsDirectorioAct=0,
			 *lSiscomArchsDirectorioDat;
SiscomBuscaArchivos(pchrPtrDirectorio,
                   0,
		   ".csv",
		   &lSiscomArchsDirectorioPrim,
		   &lSiscomArchsDirectorioAct);
lSiscomArchsDirectorioDat=lSiscomArchsDirectorioPrim;
for(;
	lSiscomArchsDirectorioDat;
     lSiscomArchsDirectorioDat=lSiscomArchsDirectorioDat->NMSArchivoSig)
{
   LogSiscom("%s/%s",
   		pchrPtrDirectorio,
   		lSiscomArchsDirectorioDat->SNArchivo.chrArrArchivo);
  sprintf(lchrArrArchivo,
  		"%s/%s",
		pchrPtrDirectorio,
		lSiscomArchsDirectorioDat->SNArchivo.chrArrArchivo);
   DatosDesdeArchivo(lchrArrArchivo,
   			pSiscomRegProLPtrPrim,
			pSiscomRegProLPtrAct);
}
}
int DatosDesdeArchivo(const char *pchrPtrArchivo,
		      SiscomRegistroProL **pSiscomRegProLPtrPrim,
		      SiscomRegistroProL **pSiscomRegProLPtrAct)
{
FILE *lFlePtrArchivo;
char lchrArrLinea[4192];
char **lchrPtrCampos,**lchrPtrDatos;
int lintContador=0;
if((lFlePtrArchivo=fopen(pchrPtrArchivo,"r")))
{
   while(SiscomLeeLineaArchivo(lFlePtrArchivo,lchrArrLinea)!=EOF)
   {
       if(!lintContador)
       ObtenCampos(lchrArrLinea,&lchrPtrCampos);
       else
       {
       ObtenCampos(lchrArrLinea,&lchrPtrDatos); 
       AgregaRegistroRegreso(lchrPtrCampos,
       			     lchrPtrDatos,
			     pSiscomRegProLPtrPrim,
			     pSiscomRegProLPtrAct);
	}
       
	lintContador++;
   }
}
}

int EjecutaSql(const char *pchrPtrArchivo,
	       const char *pchrPtrSql,
	       SiscomRegistroProL **pSiscomRegProLPtrPrim,
	       SiscomRegistroProL **pSiscomRegProLPtrAct)
{
FILE *lFlePtrArchivo;
const char *lchrPtrComando;
char lchrArrLinea[2048];
char **lchrPtrCampos,
     **lchrPtrDatos;
int lintContador=0;
if((lchrPtrComando=FormaComando(pchrPtrArchivo,pchrPtrSql)))
{
  if(lFlePtrArchivo=popen(lchrPtrComando,"r"))
  {
  	
	 while(SiscomLeeLineaArchivo(lFlePtrArchivo,lchrArrLinea)!=EOF)
	 {
	   if(lintContador==1)
	   ObtenCampos(lchrArrLinea,&lchrPtrCampos);
	   if(lintContador>1)
	   {
	     ObtenCampos(lchrArrLinea,&lchrPtrDatos);
	     AgregaRegistroRegreso(lchrPtrCampos,
	     			   lchrPtrDatos,
				   pSiscomRegProLPtrPrim,
				   pSiscomRegProLPtrAct);
	   }
	   lintContador++;
	 }


  }

}


}
void ObtenCampos(const char *pchrPtrLinea,
		 char ***pchrPtrCampos)
{
char lchrArrBuffer[2048];
if(SiscomAnalizaCadenas(pchrPtrLinea,
			'\t',
			lchrArrBuffer,
			pchrPtrCampos))
{

}
else
{
   LogSiscom("Archivo Sin tabuladores");
   exit(0);
}
			

}
const char *FormaComando(const char *pchrPtrArchivo,
			 const char *pchrPtrSql)
{
char lchrArrComando[1024];

sprintf(lchrArrComando,
	"echo \"%s\" |mdb-sql -pF %s",
	pchrPtrSql,
	pchrPtrArchivo);

return strdup(lchrArrComando);


}

void AgregaRegistroRegreso(char **pchrPtrCampos,
			   char **pchrPtrDatos,
			   SiscomRegistroProL **pSiscomRegProLPtrPrim,
			   SiscomRegistroProL **pSiscomRegProLPtrActual)
{
SiscomCampoProL *lSiscomCamProLPtrPrim=0,
	 	*lSiscomCamProLPtrAct=0;
   while(*pchrPtrCampos)
   {
   	SiscomAgregaCampo(*pchrPtrCampos,
			  *pchrPtrDatos,
			  &lSiscomCamProLPtrPrim,
			  &lSiscomCamProLPtrAct);
	pchrPtrCampos++;
	pchrPtrDatos++;
   }
   SiscomNodoRegistroPro(lSiscomCamProLPtrPrim,
   			 pSiscomRegProLPtrPrim,
			 pSiscomRegProLPtrActual);
}
void EjecutandoSql(const char *pchrPtrArchivo,
		   const char *pchrPtrFuncion,
		   int pintNoLinea,
		   const char *pchrPtrSql)
{
const char *lchrPtrRegresoSql;
PGresult *lPGRRegreso;
  if(!gzPostgresSql.PGConPtrConexion)
   printf("%s\n",pchrPtrSql);
   else
   {
	if((lchrPtrRegresoSql=PostgresEjecutaComando(gzPostgresSql.PGConPtrConexion,
						 pchrPtrSql,
						 1,
						 &lPGRRegreso)))
	 printf("%s %s %d %s\n",
	 	pchrPtrArchivo,
		pchrPtrFuncion,
		pintNoLinea,
		pchrPtrSql);
   }
}
