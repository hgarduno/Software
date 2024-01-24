#include <SqlSincronizaExpendios.h>

#include <SiscomDesarrolloMacros.h>
#include <SiscomInsercionesSql.h>

int SqlProductosExpendio(SiscomOperaciones *pSisOpePtrDato)
{
const char *lchrPtrIdExpendio;
char *lchrPtrDirIp,
	    *lchrPtrBaseDatos,
	    *lchrPtrPuertoBaseDatos;
char lchrArrSql[256],lchrArrBuffer[256];
int lintPuertoAD;
lchrPtrIdExpendio=SiscomCampoArgumentoPrim("Expendios","idempresa",pSisOpePtrDato);
SqlConsultaProductosExpendios(lchrPtrIdExpendio,lchrArrSql);
ObtenDatosComunicacionExpendio(pSisOpePtrDato,
		      &lchrPtrDirIp,
		      &lchrPtrBaseDatos,
		      &lchrPtrPuertoBaseDatos,
		      &lintPuertoAD);
LogSiscom("Datos Servidor DirIp(%s:%d) Base Datos %s",
	 lchrPtrDirIp,
	 lintPuertoAD,
	 lchrPtrBaseDatos);
SiscomEnviaConsultaSqlAsignaArgumento(lchrPtrDirIp,
				      lchrPtrBaseDatos,
				      lchrPtrPuertoBaseDatos,
				      lchrArrSql,
				      "ProductosExpendio",
				      lchrArrBuffer,
				      lintPuertoAD,
				      pSisOpePtrDato);
return 0;
}

int SqlLasBodegasDelExpendio(SiscomOperaciones *pSisOpePtrDato)
{
const char *lchrPtrIdExpendio;
char *lchrPtrDirIp,
	    *lchrPtrBaseDatos,
	    *lchrPtrPuertoBaseDatos;
char lchrArrSql[256],lchrArrBuffer[256];
int lintPuertoAD;
lchrPtrIdExpendio=SiscomCampoArgumentoPrim("Expendios","idempresa",pSisOpePtrDato);
SqlConsultaBodegasExpendio(lchrArrSql);
ObtenDatosComunicacionExpendio(pSisOpePtrDato,
		      &lchrPtrDirIp,
		      &lchrPtrBaseDatos,
		      &lchrPtrPuertoBaseDatos,
		      &lintPuertoAD);
LogSiscom("Datos Servidor DirIp(%s:%d) Base Datos %s",
	 lchrPtrDirIp,
	 lintPuertoAD,
	 lchrPtrBaseDatos);
SiscomEnviaConsultaSqlAsignaArgumento(lchrPtrDirIp,
				      lchrPtrBaseDatos,
				      lchrPtrPuertoBaseDatos,
				      lchrArrSql,
				      "BodegasExpendio",
				      lchrArrBuffer,
				      lintPuertoAD,
				      pSisOpePtrDato);
return 0;
}


int SqlProductosMatriz(SiscomOperaciones *pSisOpePtrDato)
{
const char *lchrPtrIdExpendio;
lchrPtrIdExpendio=SiscomCampoAsociadoRespuesta("Matriz","idempresa",pSisOpePtrDato);
SqlConsultandoProductosExpendio(lchrPtrIdExpendio,"ProductosMatriz",pSisOpePtrDato);
return 0;
}
void SqlConsultandoProductosExpendio(const char *pchrPtrIdExpendio,
			  char *pchrPtrAArgumento,
			  SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrSql[256],lchrArrBuffer[256];
SqlConsultaProductosExpendios(pchrPtrIdExpendio,lchrArrSql);
SiscomConsultaSqlAArgumentoOperaciones(lchrArrSql,
					pchrPtrAArgumento,
					lchrArrBuffer,
					pSisOpePtrDato);
			   
}
void SqlConsultaProductosExpendios(const char *pchrPtrIdExpendio,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"select cveproducto,dscproducto			\n\
	from productos as a inner join 			\n\
	     existencias as b using(cveproducto)	\n\
	where idexpendio=%s				\n\
	order by cveproducto",
	pchrPtrIdExpendio);
LogSiscom("%s",pchrPtrSql);
}
void SqlConsultaBodegasExpendio(char *pchrPtrSql)
{
sprintf(pchrPtrSql,"select * from bodegas");
}

void ObtenDatosComunicacionExpendio(SiscomOperaciones *pSisOpePtrDato,
			    char **pchrPtrDirIp,
			    char **pchrPtrBaseDatos,
			    char **pchrPtrPuertoBaseDatos,
			    int *pintPtrPuertoAD)
{

*pchrPtrDirIp=(char *)SiscomCampoArgumentoPrim("Expendios","dirip",pSisOpePtrDato);
*pchrPtrBaseDatos=(char *)SiscomCampoArgumentoPrim("Expendios","basedatos",pSisOpePtrDato);
*pchrPtrPuertoBaseDatos=0;
*pintPtrPuertoAD=SiscomObtenCampoArgumentoInt("Expendios","puerto",pSisOpePtrDato);


}
void InsertIntoProductosSincronizaE(SiscomRegistroProL *pSisRegProLPtrProducto,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into productos values('%s','%s',0,0);",
	SiscomObtenCampoRegistroProLChar("cveproducto",pSisRegProLPtrProducto),
	SiscomObtenCampoRegistroProLChar("dscproducto",pSisRegProLPtrProducto));
}
			
void InsertIntoPreciosSincronizaE(SiscomRegistroProL *pSisRegProLPtrProducto,char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into precios values('%s',1153257207,0,0,0,'DEFAULT');",
	SiscomObtenCampoRegistroProLChar("cveproducto",pSisRegProLPtrProducto));
}

void InsertIntoExistenciasSincronizaE(const char *pchrPtrIdExpendio,
			   SiscomRegistroProL *pSisRegProLPtrProducto,
			   char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into existencias values('%s',0,%s);",
	SiscomObtenCampoRegistroProLChar("cveproducto",pSisRegProLPtrProducto),
	pchrPtrIdExpendio);
}

void InsertIntoMaterialBodegaSincronizaE(const char *pchrPtrIdBodega,
					 SiscomRegistroProL *pSisRegProLPtrProducto,
					 char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"insert into materialbodega values(%s,'%s',0,0);",
	pchrPtrIdBodega,
	SiscomObtenCampoRegistroProLChar("cveproducto",pSisRegProLPtrProducto));
}
						

SiscomRegistroProL *AsignaBaseDatosExpendio(SiscomOperaciones *pSisOpePtrDato)
{
SiscomRegistroProL *lSisRegProLPtrSqlPrim;

if((lSisRegProLPtrSqlPrim=SiscomObtenArgumentoActOperaciones("SqlProductosASincronizar",pSisOpePtrDato)))
{
  SiscomActualizaCampoRegistroActual("BaseDatos",
  			(char *)SiscomCampoArgumentoPrim("Expendios","basedatos",pSisOpePtrDato),
			lSisRegProLPtrSqlPrim);

return lSisRegProLPtrSqlPrim;
}
}
void AgregaInsercionProducto(SiscomRegistroProL *pSisRegProLPtrProducto,
			     SiscomRegistroProL *pSisRegProLPtrSql)
{
char lchrArrBuffer[4196],lchrArrSql[4196];
InsertIntoProductosSincronizaE(pSisRegProLPtrProducto,lchrArrSql);
SiscomAnexaRegistrosAlCampo("SentenciasSql",
			     pSisRegProLPtrSql,
			     lchrArrBuffer,
			     "Sql,"
			     "Estado,",
			     lchrArrSql,
			     "");
}

void AgregaInsercionProductoBodegas(SiscomOperaciones *pSisOpePtrDato,
				    SiscomRegistroProL *pSisRegProLPtrProducto,
			            SiscomRegistroProL *pSisRegProLPtrSql)
{
char lchrArrBuffer[4196],lchrArrSql[4196];
const char *lchrPtrIdBodega;
SiscomRegistroProL *lSisRegProLPtrBodegas;

lSisRegProLPtrBodegas=SiscomObtenArgumentoPrimOperaciones("BodegasExpendio",pSisOpePtrDato);
SiscomRegistroProtocoloLog(lchrArrBuffer,lSisRegProLPtrBodegas);
for(;lSisRegProLPtrBodegas;
     lSisRegProLPtrBodegas=lSisRegProLPtrBodegas->SiscomRegProLPtrSig)
{
lchrPtrIdBodega=SiscomObtenCampoRegistroProLChar("idbodega",lSisRegProLPtrBodegas);
InsertIntoMaterialBodegaSincronizaE(lchrPtrIdBodega,pSisRegProLPtrProducto,lchrArrSql);
SiscomAnexaRegistrosAlCampo("SentenciasSql",
			     pSisRegProLPtrSql,
			     lchrArrBuffer,
			     "Sql,"
			     "Estado,",
			     lchrArrSql,
			     "");
}
}

void AgregaInsercionPrecio(SiscomRegistroProL *pSisRegProLPtrProducto,
			   SiscomRegistroProL *pSisRegProLPtrSql)
{
char lchrArrBuffer[256],lchrArrSql[256];
InsertIntoPreciosSincronizaE(pSisRegProLPtrProducto,lchrArrSql);
SiscomAnexaRegistrosAlCampo("SentenciasSql",
			     pSisRegProLPtrSql,
			     lchrArrBuffer,
			     "Sql,"
			     "Estado,",
			     lchrArrSql,
			     "");
}
void AgregaInsercionExistencia(const char *pchrPtrIdExpendio,
			       SiscomRegistroProL *pSisRegProLPtrProducto,
			       SiscomRegistroProL *pSisRegProLPtrSql)
{
char lchrArrBuffer[256],lchrArrSql[256];
InsertIntoExistenciasSincronizaE(pchrPtrIdExpendio,
				 pSisRegProLPtrProducto,
				 lchrArrSql);
SiscomAnexaRegistrosAlCampo("SentenciasSql",
			     pSisRegProLPtrSql,
			     lchrArrBuffer,
			     "Sql,"
			     "Estado,",
			     lchrArrSql,
			     "");

}
void MostrandoLasSentencias(SiscomRegistroProL *pSisRegProLPtrArgumentoSql)
{
SiscomRegistroProL *lSisRegProLPtrSentencias;
char lchrArrBuffer[8192];
const char *lchrPtrSql;
lSisRegProLPtrSentencias=SiscomObtenRegistrosCampoProL("SentenciasSql",pSisRegProLPtrArgumentoSql);
for(;lSisRegProLPtrSentencias;
     lSisRegProLPtrSentencias=lSisRegProLPtrSentencias->SiscomRegProLPtrSig)
{
 lchrPtrSql=SiscomObtenCampoRegistroProLChar("Sql",lSisRegProLPtrSentencias); 
 if(lchrPtrSql)
   LogSiscom("%s",lchrPtrSql);
}
}
int SqlFormandoLasInsercionesExpendiosSincroniza(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[4196];
const char *lchrPtrIdExpendio;
SiscomRegistroProL *lSisRegProLPtrProdASi,
		   *lSisRegProLPtrSql;
lSisRegProLPtrSql=AsignaBaseDatosExpendio(pSisOpePtrDato);
if((lSisRegProLPtrProdASi=SiscomObtenArgumentoPrimOperaciones("ProductosASincronizar",
								pSisOpePtrDato)))
{
lchrPtrIdExpendio=SiscomCampoArgumentoPrim("Expendios","idempresa",pSisOpePtrDato);
   for(;lSisRegProLPtrProdASi;
        lSisRegProLPtrProdASi=lSisRegProLPtrProdASi->SiscomRegProLPtrSig)
   {
 	AgregaInsercionProducto(lSisRegProLPtrProdASi,lSisRegProLPtrSql);
	AgregaInsercionProductoBodegas(pSisOpePtrDato,lSisRegProLPtrProdASi,lSisRegProLPtrSql);
	AgregaInsercionPrecio(lSisRegProLPtrProdASi,lSisRegProLPtrSql);
	AgregaInsercionExistencia(lchrPtrIdExpendio,
				   lSisRegProLPtrProdASi,
				   lSisRegProLPtrSql);
   }
}
MostrandoLasSentencias(lSisRegProLPtrSql); 

}
int SqlInsertaProductoExpendioSincroniza(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[4196];
const char *lchrPtrDirIp,*lchrPtrBase;
int lintPuerto;
lchrPtrDirIp=SiscomCampoArgumentoAct("Expendios","dirip",pSisOpePtrDato);
lintPuerto=SiscomObtenCampoArgumentoInt("Expendios","puerto",pSisOpePtrDato);
lchrPtrBase=SiscomCampoArgumentoAct("Expendios","basedatos",pSisOpePtrDato);
SqlFormandoLasInsercionesExpendiosSincroniza(pSisOpePtrDato);
LogSiscom("Se enviaran las inserciones a %s:%d En la base %s",
 		lchrPtrDirIp,
		lintPuerto,
		lchrPtrBase);
SiscomEnviaRegistrosBD(lchrPtrDirIp,	
			lintPuerto,
			"SqlProductosASincronizar",
			lchrArrBuffer,
			pSisOpePtrDato);
}

/*
insert into productos values('TL082-MS','Un producto de montaje superficial',0,0);
insert into materialbodega values(0,'TL082-MS',0,0)
insert into materialbodega values(1,'TL082-MS',0,0)
insert into precios values('TL082-MS',1153257207,0,0,0,'DEFAULT');
insert into existencias values('TL082-MS',0,-100);
*/
