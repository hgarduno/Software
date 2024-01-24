#include <ComunElectronica.h>
#include <ServidorGeneral.h>
#include <RNProductos.h>
#include <string.h>
#include <stdlib.h>
void ElectronicaComunicacionExpendio(LCamposSiscomPro2 *pLCSiscomPro2,
				     int *pintPtrPtoCom,
				     char *pchrPtrDirIpSvr)
{
LCamposSiscomPro2 *lLCSiscomPro2=*gLCSiscomPro2Memoria; 
const char *lchrPtrIdExpendio=SiscomObtenDato(pLCSiscomPro2,"IdExpendio");
	for( ;
		lLCSiscomPro2;
		lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
	{
	    if(!strcmp(lchrPtrIdExpendio,SiscomObtenDato(lLCSiscomPro2,"idempresa")))
	    {
		*pintPtrPtoCom=atoi(SiscomObtenDato(lLCSiscomPro2,"ptocomad"));
		strcpy(pchrPtrDirIpSvr,SiscomObtenDato(lLCSiscomPro2,"diripsvrad"));		   
	    }
	    	

	}
}

void ElectronicaComunicacionExpendio2(const char *pchrPtrIdExpendio,
				     int *pintPtrPtoCom,
				     char *pchrPtrDirIpSvr,
				     char *pchrPtrBaseDatos)
{
LCamposSiscomPro2 *lLCSiscomPro2=*gLCSiscomPro2Memoria; 

	for( ;
		lLCSiscomPro2;
		lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig)
	{
	    if(!strcmp(pchrPtrIdExpendio,SiscomObtenDato(lLCSiscomPro2,"idempresa")))
	    {
		*pintPtrPtoCom=atoi(SiscomObtenDato(lLCSiscomPro2,"ptocomad"));
		strcpy(pchrPtrDirIpSvr,SiscomObtenDato(lLCSiscomPro2,"diripsvrad"));
		if(pchrPtrBaseDatos)
		strcpy(pchrPtrBaseDatos,SiscomObtenDato(lLCSiscomPro2,"basedatos"));
		return ;
	    }
	    	

	}
	SiscomLog("No se encontro el expendio:%s",pchrPtrIdExpendio);
}



void ConexionNoDisponibleAlExpendio(int pintNRegistros,
				    int pintPuertoAccesoDatos,
				    const char *pchrPtrDirIpAccesoDatos,
				    LCamposSiscomPro2 *pLCSiscomPro2Sqls)
{
SiscomLog("Conexion al expendio (%d,%s) No disponible",
	  pintPuertoAccesoDatos,
	  pchrPtrDirIpAccesoDatos);
}



int InsertandoAlExpendio(int pintNRegistros,
			  LCamposSiscomPro2 *pLCSiscomPro2Expendio,
			  LCamposSiscomPro2 *pLCSiscomPro2SqlAlExpendio,
			  LCamposSiscomPro2 **pLCSiscomPro2EdoExpendioPrim,
			  LCamposSiscomPro2 **pLCSiscomPro2EdoExpendioAct)
{
int lintPuertoAccesoDatos=SiscomObtenDatoInt(pLCSiscomPro2Expendio,"ptocomad");
const char *lchrPtrDirIpAccesoDatos=SiscomObtenDato(pLCSiscomPro2Expendio,"diripsvrad");
char *lchrPtrEdoConexion=0;
int lintSocketAd;
SiscomInformacionServidorNoBloqueante(lintPuertoAccesoDatos,
			  lchrPtrDirIpAccesoDatos,
			  "Inserciones",
			  pintNRegistros,
			  pLCSiscomPro2SqlAlExpendio,
			  5,
			  &lchrPtrEdoConexion,
			  &lintSocketAd);
SiscomLog("Se ha enviado al servidor de Base de datos");
if(lchrPtrEdoConexion)
{
  SiscomCreaListaCamposPro2(pLCSiscomPro2Expendio->SCSiscomPro2,
  			    pLCSiscomPro2EdoExpendioPrim,
			    pLCSiscomPro2EdoExpendioAct);
  ConexionNoDisponibleAlExpendio(pintNRegistros,
  				 lintPuertoAccesoDatos,
				 lchrPtrDirIpAccesoDatos,
				 pLCSiscomPro2SqlAlExpendio);
}
return lchrPtrEdoConexion? 0 : 1;
}

void InsertandoALosExpendios(int pintNRegistros,
			    LCamposSiscomPro2 *pLCSiscomPro2SqlAlExpendio,
			    LCamposSiscomPro2 **pLCSiscomPro2EdoExpendioPrim)
{
LCamposSiscomPro2 *lLCSiscomPro2=*gLCSiscomPro2Memoria;
LCamposSiscomPro2 *lLCSiscomPro2EdoExpendioAct=0;
SiscomContenidoProtocolo(pLCSiscomPro2SqlAlExpendio);
SiscomContenidoProtocolo(lLCSiscomPro2);
while(lLCSiscomPro2)
{
if(!SiscomObtenDato(lLCSiscomPro2,"matriz")[0])
{
SiscomLog("Enviando Productos al Expendio %s %d (%s)",
	SiscomObtenDato(lLCSiscomPro2,"diripsvrad"),
	SiscomObtenDatoInt(lLCSiscomPro2,"ptocomad"),
	SiscomObtenDato(lLCSiscomPro2,"matriz"));
InsertandoAlExpendio(pintNRegistros,
		     lLCSiscomPro2,
		     pLCSiscomPro2SqlAlExpendio,
		     pLCSiscomPro2EdoExpendioPrim,
		     &lLCSiscomPro2EdoExpendioAct);
}
lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig;
}
}
/* Tepotzotlan Mexico Domingo 15 de Noviembre del 2015
 * Toma las sentencias SQL del Argumento pchrPtrArgumento
 * y las envia a todos los expendios, incluyendo la matriz
 * 
 */
void SiscomElectronicaInsertaSistema(SArgsSiscom *pSAgsSiscom,
				     const char *pchrPtrArgumento)
{
LCamposSiscomPro2 *lLCSiscomPro2=*gLCSiscomPro2Memoria;
LCamposSiscomPro2 *lLCSiscomPro2EdoExpendioPrim=0,
		   *lLCSiscomPro2EdoExpendioAct=0,
		   *lLCSiscomPro2SqlAlExpendioPrim,
		   *lLCSiscomPro2SqlAlExpendioAct;
int lintNRegistros;
SiscomObtenInformacionArgumento(pchrPtrArgumento,
				pSAgsSiscom,
				&lLCSiscomPro2SqlAlExpendioPrim,
				&lLCSiscomPro2SqlAlExpendioAct,
				&lintNRegistros);
SiscomContenidoProtocolo(lLCSiscomPro2SqlAlExpendioPrim);
while(lLCSiscomPro2)
{
SiscomLog("Enviando Productos al Expendio %s:%d" ,
	SiscomObtenDato(lLCSiscomPro2,"diripsvrad"),
	SiscomObtenDatoInt(lLCSiscomPro2,"ptocomad"));
InsertandoAlExpendio(lintNRegistros,
		     lLCSiscomPro2,
		     lLCSiscomPro2SqlAlExpendioPrim,
		     &lLCSiscomPro2EdoExpendioPrim,
		     &lLCSiscomPro2EdoExpendioAct);
lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig;
}
}


/* CDMX a Martes 9 de agosto del 2022 
 * Al hacer el registro de un producto, al formar la sentencia sql de existencia
 * el id del expendio se va con el de la matriz, con lo que no se puede ver el 
 * producto en el expendio, porque se queda con el id de la matriz
 *
 * Por tal motivo saque del de la funcion el codigo para hacer una subfuncion 
 * que me permita resolver el problema
 *
 */
void GenerandoSqlsRegistroProductos(LCamposSiscomPro2 *pLCSiscomPro2,
			     LCamposSiscomPro2 *pLCSiscomPro2Expendio,
			     LCamposSiscomPro2 *pLCSiscomPro2IniTipoPrecio,
			     int pintIdPublicoEnGeneral,
			     int *pintPtrNRegistros,
			     LCamposSiscomPro2 **pLCSiscomSqlPrim,
			     LCamposSiscomPro2 **pLCSiscomSqlAct)
{
int lintContador=0;
char lchrArrActualiza[2048],
	lchrArrCadInsertaExistencia[256],
	lchrArrCadInsertaPrecios[256];
 LCamposSiscomPro2 *lLCSiscomPro2IniTipoPrecio=0,
 		   *lLCSiscomPro2TipoPrecio=0,
		   *lLCSiscomPro2Expendios=0;
  for(lintContador=0;
  	pLCSiscomPro2;
	pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	sprintf(lchrArrActualiza,
		"insert into productos values('%s','%s',%s,%s);",
		SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
		SiscomObtenDato(pLCSiscomPro2,"DscProducto"),
		SiscomObtenDato(pLCSiscomPro2,"IdUnidad"),
		SiscomObtenDato(pLCSiscomPro2,"IdFamilia"));
	 SiscomLog("%s",lchrArrActualiza); 
	SiscomContenidoProtocolo(pLCSiscomPro2);	
	SiscomLog("Probando");
	 SiscomAnexaRegistroPro2(pLCSiscomSqlPrim,
	 			 pLCSiscomSqlAct,
				 pintPtrNRegistros,
				 "ComandoSQL,EdoRegistro",
				 lchrArrActualiza,
				 "");
  	SiscomLog("%s",lchrArrActualiza);
	RegistraProductoBodegas(SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
				pLCSiscomSqlPrim,
				pLCSiscomSqlAct,
				pintPtrNRegistros);
    for(lLCSiscomPro2TipoPrecio=pLCSiscomPro2IniTipoPrecio;
    	lLCSiscomPro2TipoPrecio;
	lLCSiscomPro2TipoPrecio=lLCSiscomPro2TipoPrecio->SCP2PtrSig)
    {
    	sprintf(lchrArrCadInsertaPrecios,
		"insert into precios values('%s',%d,0,0,0,'%s');",
		SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
		pintIdPublicoEnGeneral,
		SiscomObtenDato(lLCSiscomPro2TipoPrecio,"nmbtipoprecio"));
	SiscomAnexaRegistroPro2(pLCSiscomSqlPrim,
	 			 pLCSiscomSqlAct,
				 pintPtrNRegistros,
				 "ComandoSQL,EdoRegistro",
				 lchrArrCadInsertaPrecios,
				 "");
	sprintf(lchrArrCadInsertaExistencia,
		"insert into existencias values('%s',0,%s);",
		SiscomObtenDato(pLCSiscomPro2,"CveProducto"),
		SiscomObtenDato(pLCSiscomPro2Expendio,"idempresa"));
	SiscomAnexaRegistroPro2(pLCSiscomSqlPrim,
	 			pLCSiscomSqlAct,
				 pintPtrNRegistros,
				 "ComandoSQL,EdoRegistro",
				 lchrArrCadInsertaExistencia,
				 "");

    }
  }
}

void EstadoRegistroProductoMatriz(int pintEdoConexion,
				  LCamposSiscomPro2 *pLCSiscomPro2Expendio,
				  LCamposSiscomPro2 *pLCSiscomPro2SqlEnviados)
{
   if(SiscomObtenDato(pLCSiscomPro2Expendio,"matriz")[0])
   {
     SiscomLog("Es la matriz ......... ");
   }

}

int HayUnExpendioSinConexion(int pintEdoConexion,int pintUnoSinConexion)
{
     if(!pintEdoConexion && !pintUnoSinConexion)
     return 1;
     else
     return 0;

}
int RegistrandoProductoExpendios(LCamposSiscomPro2 *pLCSiscomPro2,
			     	  LCamposSiscomPro2 *pLCSiscomPro2Expendios,
			     	  LCamposSiscomPro2 *pLCSiscomPro2IniTipoPrecio,
			     	  int pintIdPublicoEnGeneral,
				  LCamposSiscomPro2 **pLCSiscomPro2EdoConExpPrim,
				  LCamposSiscomPro2 **pLCSiscomPro2EdoConExpAct)
{
int lintNRegistros=0,lintEdoConexion,lintUnoSinConexion=0;
LCamposSiscomPro2 *lLCSiscomPro2SqlPrim=0,
		  *lLCSiscomPro2SqlAct=0,
		  *lLCSiscomPro2Expendio;

for(lLCSiscomPro2Expendio=pLCSiscomPro2Expendios;
    lLCSiscomPro2Expendio;
    lLCSiscomPro2Expendio=lLCSiscomPro2Expendio->SCP2PtrSig)
{
SiscomLog("Enviando Productos al Expendio %s %d (%s)",
	SiscomObtenDato(lLCSiscomPro2Expendio,"diripsvrad"),
	SiscomObtenDatoInt(lLCSiscomPro2Expendio,"ptocomad"),
	SiscomObtenDato(lLCSiscomPro2Expendio,"matriz"));
GenerandoSqlsRegistroProductos(pLCSiscomPro2,
			       lLCSiscomPro2Expendio,
			       pLCSiscomPro2IniTipoPrecio,
			       pintIdPublicoEnGeneral,
			       &lintNRegistros,
			       &lLCSiscomPro2SqlPrim,
			       &lLCSiscomPro2SqlAct);
lintEdoConexion=InsertandoAlExpendio(lintNRegistros,
		     lLCSiscomPro2Expendio,
		     lLCSiscomPro2SqlPrim,
		     pLCSiscomPro2EdoConExpPrim,
		     pLCSiscomPro2EdoConExpAct);
EstadoRegistroProductoMatriz(lintEdoConexion,lLCSiscomPro2Expendio,lLCSiscomPro2SqlPrim); 
if(!lintUnoSinConexion)
 lintUnoSinConexion=HayUnExpendioSinConexion(lintEdoConexion,lintUnoSinConexion);
lLCSiscomPro2SqlPrim=lLCSiscomPro2SqlAct=0;
lintNRegistros++;
}

return lintUnoSinConexion;
}
