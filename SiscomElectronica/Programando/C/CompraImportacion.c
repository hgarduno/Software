#include <CompraImportacion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <unistd.h>
#include <string.h>


#include <FacturandoFriPro.h>


#include <stdlib.h>
FILE *gPtrFleArchivoLog;
int gintSocketProtocoloLog;
SiscomError gSiscomErrorSistema;


int main(int pintArgc,
	 char **pchrPtrArgv)
{
SiscomRegistroProL *lSisRegProLPtrComImportacion=0,
		   *lSisRegProLPtrDetComImportacion=0;

 gPtrFleArchivoLog=stdout;
 LeyendoEntrada(ObtenArchivo(*(pchrPtrArgv+1)),&lSisRegProLPtrComImportacion,&lSisRegProLPtrDetComImportacion);
 GeneraSentenciasSql(*(pchrPtrArgv+1),lSisRegProLPtrComImportacion,lSisRegProLPtrDetComImportacion);

}

FILE *ObtenArchivo(const char *pchrPtrArchivo)
{
/*
FILE *lFlePtrArchivo;
   if((lFlePtrArchivo=fopen(pchrPtrArchivo,"r")))
   return lFlePtrArchivo;
   else
*/
    return stdin;

}

int LeyendoEntrada(FILE *pFlePtrArchivo,
		   SiscomRegistroProL **pSisRegProLPtrComImportacion,
		   SiscomRegistroProL **pSisRegProLPtrDetComImportacion)
{
char lchrArrLinea[1024];
const char *lchrPtrLinea;
SiscomRegistroProL *lSisRegProLPtrActDatImp=0,
		   *lSisRegProLPtrActDetCompra=0;
while(SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea)!=(char )EOF)
{
  if(lchrPtrLinea=EstaClaveProducto(lchrArrLinea))
  RegistroDetalleCompraImportacion(pFlePtrArchivo,
  			           lchrPtrLinea,
  				   pSisRegProLPtrDetComImportacion,
				   &lSisRegProLPtrActDetCompra);
  else
   if(strstr(lchrArrLinea,"IdExpendio"))
       ObtenDatosImportacion(lchrArrLinea,
       			     pFlePtrArchivo,
			     pSisRegProLPtrComImportacion,
			     &lSisRegProLPtrActDatImp);
}
}
const char *EstaClaveProducto(const char *pchrPtrLinea)
{
const char *lchrPtrRegreso;
pchrPtrLinea++;
if((lchrPtrRegreso=strstr(pchrPtrLinea,"CveProducto")))
{
     while(lchrPtrRegreso!=pchrPtrLinea)  
	  pchrPtrLinea++;
return pchrPtrLinea;
}
else 
return 0;
}
const char *ObtenLineaValida(const char *pchrPtrLinea)
{
const char *lchrPtrRegreso=strchr(pchrPtrLinea,')');
if(lchrPtrRegreso)
{
     while(lchrPtrRegreso!=pchrPtrLinea)
      pchrPtrLinea++;
      pchrPtrLinea+=2;
}
return pchrPtrLinea;
}
void RegistroDetalleCompraImportacion(FILE *pFlePtrArchivo,
				      const char *pchrPtrLinea,
				      SiscomRegistroProL **pSisRegProLPtrPrimDetCompra,
				      SiscomRegistroProL **pSisRegProLPtrActDetCompra)
{
char lchrArrBuffer[512],
     lchrArrLinea[512];
char **lchrPtrProducto,**lchrPtrDatos;
SiscomAnalizaCadenas(pchrPtrLinea,'|',lchrArrBuffer,&lchrPtrProducto);
while(SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea)!=EOF)
{
SiscomAnalizaCadenas(ObtenLineaValida(lchrArrLinea),'|',lchrArrBuffer,&lchrPtrDatos);
SiscomNodoRegistroPro(FormaRegistroDetalleCompra(lchrPtrProducto,lchrPtrDatos),
		      pSisRegProLPtrPrimDetCompra,
		      pSisRegProLPtrActDetCompra);
}
}
void ObtenDatosImportacion(const char *pchrPtrNmbCampos,
			   FILE *pFlePtrArchivo,
			   SiscomRegistroProL **pSisRegProLPtrPrim,
			   SiscomRegistroProL **pSisRegProLPtrAct)
{
char lchrArrBuffer[512],
	lchrArrLinea[512];
char **lchrPtrNmbCampos,
	**lchrPtrDatos;
SiscomLeeLineaArchivo(pFlePtrArchivo,lchrArrLinea);
SiscomAnalizaCadenas(pchrPtrNmbCampos,'|',lchrArrBuffer,&lchrPtrNmbCampos);
SiscomAnalizaCadenas(lchrArrLinea,'|',lchrArrBuffer,&lchrPtrDatos);
SiscomNodoRegistroPro(FormaRegistro(lchrPtrNmbCampos,lchrPtrDatos),
		      pSisRegProLPtrPrim,
		      pSisRegProLPtrAct);
}
SiscomCampoProL *FormaRegistro(char **pchrPtrNmbCampos, char **pchrPtrDatos)
{
SiscomCampoProL *lSisCamProLPtrPrim=0,
		*lSisCamProLPtrAct=0;

      while(*pchrPtrNmbCampos)
      {
	   
	  SiscomAgregaCampo(*pchrPtrNmbCampos,*pchrPtrDatos,&lSisCamProLPtrPrim,&lSisCamProLPtrAct);
 	  pchrPtrNmbCampos++;
	  pchrPtrDatos++;
      }
return lSisCamProLPtrPrim;
}

SiscomCampoProL *FormaRegistroDetalleCompra(char **pchrPtrProducto,char **pchrPtrDatos)
{

SiscomCampoProL *lSisCamProLPtrPrim=0,
		*lSisCamProLPtrAct=0;

	while(*pchrPtrProducto)
	{
	   SiscomAgregaCampo(*pchrPtrProducto,*pchrPtrDatos,&lSisCamProLPtrPrim,&lSisCamProLPtrAct);
	   pchrPtrProducto++;
	   pchrPtrDatos++;
	}
return lSisCamProLPtrPrim;
}
void SqlCompraImportacion(const char *pchrPtrIdProveedor,
		 	  const char *pchrPtrIdCompraImp,
			  SiscomRegistroProL *pSisRegProLPtrComImportacion,
		   	  char *pchrPtrSql)
{
char lchrArrFecha[28];
SiscomObtenFechaHoyCharAAAADDMM(lchrArrFecha);
sprintf(pchrPtrSql,
	"insert into CompraImportacion values(%s,%s,'%s','%s',%s,%s,%s,%s,%s,%s,%s);",
	 pchrPtrIdCompraImp,
	 pchrPtrIdProveedor,
	 lchrArrFecha,
	 SiscomObtenCampoRegistroProLChar("NumFactura",pSisRegProLPtrComImportacion),
	 SiscomObtenCampoRegistroProLChar("ImporteFactura",pSisRegProLPtrComImportacion),
	 SiscomObtenCampoRegistroProLChar("CostoEnvio",pSisRegProLPtrComImportacion),
	 SiscomObtenCampoRegistroProLChar("CostoDolar",pSisRegProLPtrComImportacion),
	 SiscomObtenCampoRegistroProLChar("CostoAdministrativo",pSisRegProLPtrComImportacion),
	 SiscomObtenCampoRegistroProLChar("PonderacionCostoAdministrativo",pSisRegProLPtrComImportacion),
	 SiscomObtenCampoRegistroProLChar("NumPartidas",pSisRegProLPtrComImportacion),
	 SiscomObtenCampoRegistroProLChar("PesoCompra",pSisRegProLPtrComImportacion));

}
void SqlDetalleCompraImportacion(const char *pchrPtrIdCompraImp,
				 int pintConsecutivo,
			         SiscomRegistroProL *pSisRegProLPtrDetComImportacion,
				 char *pchrPtrSqlDetComImportacion)
{
sprintf(pchrPtrSqlDetComImportacion,
	"insert into DetalleCompraImportacion values(%s,%d,'%s',%s,%s);",
	pchrPtrIdCompraImp,
	pintConsecutivo,
	SiscomObtenCampoRegistroProLChar("CveProducto",pSisRegProLPtrDetComImportacion),
	SiscomObtenCampoRegistroProLChar("Cantidad",pSisRegProLPtrDetComImportacion),
	SiscomObtenCampoRegistroProLChar("CostoUnitarioDolares",pSisRegProLPtrDetComImportacion));

}
void FormandoSqlDetalleCompraImportacion(const char *pchrPtrIdCompraImp,
			   SiscomRegistroProL *pSisRegProLPtrDetComImportacion)
{
char lchrArrSql[256];
int lintConsecutivo;
for(lintConsecutivo=0;
     pSisRegProLPtrDetComImportacion;
     pSisRegProLPtrDetComImportacion=pSisRegProLPtrDetComImportacion->SiscomRegProLPtrSig,
     lintConsecutivo++)
{
SqlDetalleCompraImportacion(pchrPtrIdCompraImp,
			    lintConsecutivo,
			    pSisRegProLPtrDetComImportacion,
			    lchrArrSql);
printf("%s\n",lchrArrSql);
}

}
void GenerandoSqlCompraImportacion(const char *pchrPtrIdProveedor,
				 const char *pchrPtrIdCompra,
				SiscomRegistroProL *pSisRegProLPtrComImportacion)
{
char lchrArrSqlCompraImportacion[256];
SqlCompraImportacion(pchrPtrIdProveedor,
		     pchrPtrIdCompra,
		     pSisRegProLPtrComImportacion,
		     lchrArrSqlCompraImportacion);
printf("%s\n",lchrArrSqlCompraImportacion);

}
void GeneraSentenciasSql(const char *pchrPtrIdProveedor,
			  SiscomRegistroProL *pSisRegProLPtrComImportacion,
		         SiscomRegistroProL *pSisRegProLPtrDetComImportacion)
{
char lchrArrBuffer[512];
char lchrArrIdCompra[28];
SiscomObtenNumeroUnicoChar(lchrArrIdCompra);
/*
SiscomRegistroProtocoloLog(lchrArrBuffer,pSisRegProLPtrComImportacion);
SiscomRegistroProtocoloLog(lchrArrBuffer,pSisRegProLPtrDetComImportacion);
*/
GenerandoSqlCompraImportacion(pchrPtrIdProveedor,lchrArrIdCompra,pSisRegProLPtrComImportacion);
FormandoSqlDetalleCompraImportacion(lchrArrIdCompra,pSisRegProLPtrDetComImportacion);
}
