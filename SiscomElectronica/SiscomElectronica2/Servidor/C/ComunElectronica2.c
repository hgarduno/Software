#include <ComunElectronica2.h>
#include <ComunElectronica.h>
#include <ServidorGeneral.h>
#include <string.h>
#include <stdlib.h>
#include <SiscomModuloOperaciones.h>


void ComunicacionExpendioConsulta(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBase[25];
if(pSAgsSiscom->chrPtrArgConsulta &&
   pSAgsSiscom->chrPtrArgConsulta[1] &&
   pSAgsSiscom->chrPtrArgConsulta[1][0])
ElectronicaComunicacionExpendio2(pSAgsSiscom->chrPtrArgConsulta[1],
				 &pSAgsSiscom->intPtoComAD,
				 pSAgsSiscom->chrArrDirIpAD,
				 lchrArrBase);
else
{
strcpy(pSAgsSiscom->chrArrDirIpAD,gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos);
pSAgsSiscom->intPtoComAD=gSSiscomConfiguracionSvr.intPtoAccesoDatos;
}

}

void ComunicacionExpendio(const char *pchrPtrIdExpendio,
			  SArgsSiscom *pSAgsSiscom)
{
char lchrArrBase[25];
ElectronicaComunicacionExpendio2(pchrPtrIdExpendio,
				 &pSAgsSiscom->intPtoComAD,
				 pSAgsSiscom->chrArrDirIpAD,
				 lchrArrBase);


}

void SiscomComunicacionMatriz(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBase[25];
SiscomDatosComunicacionMatriz(&pSAgsSiscom->intPtoComAD,
			 pSAgsSiscom->chrArrDirIpAD,
				 lchrArrBase);
}

void ComunicacionExpendioRegistra(SArgsSiscom *pSAgsSiscom)
{
ElectronicaComunicacionExpendio(pSAgsSiscom->LCSiscomPro2Dat,
			 &pSAgsSiscom->intPtoComAD,
			 pSAgsSiscom->chrArrDirIpAD);
}

void ComunicacionExpendio3(SArgsSiscom *pSAgsSiscom)
{
char lchrArrBase[50];
   SiscomComunicacionExpendio2(
   	SiscomCampoRegistroPrincipal(pSAgsSiscom->LCSiscomPro2SREntrada,"IdExpendio"),
	&pSAgsSiscom->intPtoComAD,
	pSAgsSiscom->chrArrDirIpAD,
	lchrArrBase);
}
void SiscomComunicacionExpendio2(const char *pchrPtrIdExpendio,
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
	    	/*
	    	SiscomLog("Se encontro el expendio:%s %s",
			   SiscomObtenDato(lLCSiscomPro2,"ptocomad"),
			   SiscomObtenDato(lLCSiscomPro2,"diripsvrad"));
		*/
		*pintPtrPtoCom=atoi(SiscomObtenDato(lLCSiscomPro2,"ptocomad"));
		strcpy(pchrPtrDirIpSvr,SiscomObtenDato(lLCSiscomPro2,"diripsvrad"));
		if(pchrPtrBaseDatos)
		strcpy(pchrPtrBaseDatos,SiscomObtenDato(lLCSiscomPro2,"basedatos"));
		return ;
	    }
	    	

	}
	SiscomLog("No se encontro el expendio:%s",pchrPtrIdExpendio);
}

void SqlAExpendioAsignaArgumento(const char *pchrPtrIdExpendio,
				     const char *pchrPtrArgumento,
				     const char *pchrPtrSql,
				     SArgsSiscom *pSAgsSiscom)
{
int lintPtoCom;
char lchrArrDirIp[25];
char lchrArrBaseDatos[128];
LCamposSiscomPro2 *lLCSiscomPro2Reg;
int lintNRegRegreso;
SiscomComunicacionExpendio2(pchrPtrIdExpendio,
			    &lintPtoCom,
			    lchrArrDirIp,
			    lchrArrBaseDatos);
SiscomConsultaBaseDatosSinDatosConexion(
		pchrPtrSql,
		lchrArrDirIp,
		lintPtoCom,
		&lLCSiscomPro2Reg,
		&lintNRegRegreso);
SiscomAsignaArgumentoOperacionPrim(pchrPtrArgumento,lLCSiscomPro2Reg,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros(pchrPtrArgumento,lintNRegRegreso,pSAgsSiscom);
}

const char *SqlEnviaSentenciasArgumento(const char *pchrPtrIdExpendio,
				 const char *pchrPtrArgumento,
				 SArgsSiscom *pSAgsSiscom)
{
int lintPtoCom;
char lchrArrDirIp[25];
char lchrArrBaseDatos[128];
LCamposSiscomPro2 *lLCSiscomPro2Reg=0,
		  *lLCSiscomPro2Dat;

int lintNRegRegreso=0,
    lintSocket;
char *lchrPtrEdoConexion=0;
SiscomComunicacionExpendio2(pchrPtrIdExpendio,
			    &lintPtoCom,
			    lchrArrDirIp,
			    lchrArrBaseDatos);
SiscomLog("Enviando a %s:%d",lchrArrDirIp,lintPtoCom);
SiscomInformacionServidorConRespuesta(
	lintPtoCom,
	lchrArrDirIp,
	"Inserciones",
	SiscomArgumentosNumeroRegistros(pchrPtrArgumento,pSAgsSiscom),
	(lLCSiscomPro2Dat=SiscomArgumentoOperacionPrim(pchrPtrArgumento,pSAgsSiscom)),
	&lchrPtrEdoConexion,
	&lintSocket,
	&lLCSiscomPro2Reg,
	&lintNRegRegreso);
AsignaEstadoInsercion(lLCSiscomPro2Reg,
		      lLCSiscomPro2Dat);
return lchrPtrEdoConexion;
}

void SqlEnviaSentenciasCampoRegreso(const char *pchrPtrIdExpendio,
				 SArgsSiscom *pSAgsSiscom)
{
int lintPtoCom;
char lchrArrDirIp[25];
char lchrArrBaseDatos[128];
LCamposSiscomPro2 *lLCSiscomPro2Reg,
		  *lLCSiscomPro2Dat;

int lintNRegRegreso,
    lintSocket;
char *lchrPtrEdoConexion=0;
SiscomComunicacionExpendio2(pchrPtrIdExpendio,
			    &lintPtoCom,
			    lchrArrDirIp,
			    lchrArrBaseDatos);
SiscomInformacionServidorConRespuesta(
	lintPtoCom,
	lchrArrDirIp,
	"Inserciones",
	pSAgsSiscom->intNumRegRegreso,
	pSAgsSiscom->LCSiscomPro2Regreso,
	&lchrPtrEdoConexion,
	&lintSocket,
	&lLCSiscomPro2Reg,
	&lintNRegRegreso);
AsignaEstadoInsercion(pSAgsSiscom->LCSiscomPro2Regreso,
		      lLCSiscomPro2Reg);

}

void SiscomDatosComunicacionMatriz(int *pintPtrPtoCom,
			      char *pchrPtrDirIpSvr,
			      char *pchrPtrBaseDatos)
{
LCamposSiscomPro2 *lLCSiscomPro2=*gLCSiscomPro2Memoria; 
const char *lchrPtrMatriz;
	for( ;
		lLCSiscomPro2;
		lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig
		)
	{
	   lchrPtrMatriz=SiscomObtenDato(lLCSiscomPro2,"matriz");	
	    if(*lchrPtrMatriz)
	    {
		*pintPtrPtoCom=atoi(SiscomObtenDato(lLCSiscomPro2,"ptocomad"));
		strcpy(pchrPtrDirIpSvr,SiscomObtenDato(lLCSiscomPro2,"diripsvrad"));
		if(pchrPtrBaseDatos)
		strcpy(pchrPtrBaseDatos,SiscomObtenDato(lLCSiscomPro2,"basedatos"));
		SiscomLog("La Matriz:%s:%d",
			   pchrPtrDirIpSvr,
			   *pintPtrPtoCom);
		return ;
	    }
	    	

	}
	SiscomLog("No se encontraron los datos de la matriz ");
	SiscomLog("Verificar registro en la tabla Matriz");
}

void SiscomDatosComunicacionMatriz2(int *pintPtrPtoCom,
			      char *pchrPtrDirIpSvr,
			      char *pchrPtrBaseDatos,
			      char *pchrPtrIdMatriz)
{
LCamposSiscomPro2 *lLCSiscomPro2=*gLCSiscomPro2Memoria; 
const char *lchrPtrMatriz;
	for( ;
		lLCSiscomPro2;
		lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig
		)
	{
	   lchrPtrMatriz=SiscomObtenDato(lLCSiscomPro2,"matriz");	
	    if(*lchrPtrMatriz)
	    {
	    	if(pintPtrPtoCom)
		*pintPtrPtoCom=atoi(SiscomObtenDato(lLCSiscomPro2,"ptocomad"));
		if(pchrPtrDirIpSvr)
		strcpy(pchrPtrDirIpSvr,SiscomObtenDato(lLCSiscomPro2,"diripsvrad"));
		if(pchrPtrBaseDatos)
		strcpy(pchrPtrBaseDatos,SiscomObtenDato(lLCSiscomPro2,"basedatos"));
		if(pchrPtrIdMatriz)
		strcpy(pchrPtrIdMatriz,SiscomObtenDato(lLCSiscomPro2,"idempresa"));
		return ;
	    }
	}
	SiscomLog("No se encontraron los datos de la matriz ");
	SiscomLog("Verificar registro en la tabla Matriz");
}


void SemestreAnterior(char *pchrPtrFechaIni,
		      char *pchrPtrFechaFin)
{
int lintAno=0,
    lintMes=0,
    lintDia=0;
int lintAnoIniSemestre,
    lintMesIniSemestre,
    lintDiaIniSemestre;

int lintAnoFinSemestre,
    lintMesFinSemestre,
    lintDiaFinSemestre;

SiscomObtenFechaHoyINT(&lintDia,&lintMes,&lintAno);
if(lintMes>7)
{
lintAnoIniSemestre=lintAno;
lintMesIniSemestre=1;
lintDiaIniSemestre=1;

lintAnoFinSemestre=lintAno;
lintMesFinSemestre=7;
lintDiaFinSemestre=31;
}
else
{
lintAnoIniSemestre=lintAno-1;
lintMesIniSemestre=8;
lintDiaIniSemestre=1;

lintAnoFinSemestre=lintAno-1;
lintMesFinSemestre=12;
lintDiaFinSemestre=31;
}


sprintf(pchrPtrFechaIni,
	"%04d-%02d-%02d",
	lintAnoIniSemestre,
	lintMesIniSemestre,
	lintDiaIniSemestre);

sprintf(pchrPtrFechaFin,
	"%04d-%02d-%02d",
	lintAnoFinSemestre,
	lintMesFinSemestre,
	lintDiaFinSemestre);
}
void SemestreActual(char *pchrPtrFechaIni,
		      char *pchrPtrFechaFin)
{
int lintAno,
    lintMes,
    lintDia;
int lintAnoIniSemestre,
    lintMesIniSemestre,
    lintDiaIniSemestre;

int lintAnoFinSemestre,
    lintMesFinSemestre,
    lintDiaFinSemestre;

SiscomObtenFechaHoyINT(&lintDia,&lintMes,&lintAno);
if(lintMes>7)
{
lintAnoIniSemestre=lintAno;
lintMesIniSemestre=8;
lintDiaIniSemestre=1;

lintAnoFinSemestre=lintAno;
lintMesFinSemestre=12;
lintDiaFinSemestre=31;
}
else
if(lintMes==1)
{

lintAnoIniSemestre=lintAno;
lintMesIniSemestre=1;
lintDiaIniSemestre=1;

lintAnoFinSemestre=lintAno;
lintMesFinSemestre=7;
lintDiaFinSemestre=31;

}
else
{
lintAnoIniSemestre=lintAno;
lintMesIniSemestre=1;
lintDiaIniSemestre=1;

lintAnoFinSemestre=lintAno-1;
lintMesFinSemestre=7;
lintDiaFinSemestre=31;
}

sprintf(pchrPtrFechaIni,
	"%04d-%02d-%02d",
	lintAnoIniSemestre,
	lintMesIniSemestre,
	lintDiaIniSemestre);

sprintf(pchrPtrFechaFin,
	"%04d-%02d-%02d",
	lintAnoFinSemestre,
	lintMesFinSemestre,
	lintDiaFinSemestre);
}




void SqlGenerandoProductosSiscomExpendio(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
			     int *pintPtrNRegSql)
{

while(pLCSiscomPro2Dat)
{
  SqlInsertIntoProductosSiscom(pLCSiscomPro2Dat,
  			 pLCSiscomPro2SqlPrim,
			 pLCSiscomPro2SqlAct,
			 pintPtrNRegSql);
  SqlInsertIntoPreciosSiscom(pLCSiscomPro2Dat,
  			 pLCSiscomPro2SqlPrim,
			 pLCSiscomPro2SqlAct,
			 pintPtrNRegSql);
  SqlInsertIntoExistenciasSiscom(pLCSiscomPro2Dat,
  			 pLCSiscomPro2SqlPrim,
			 pLCSiscomPro2SqlAct,
			 pintPtrNRegSql);
  
pLCSiscomPro2Dat=pLCSiscomPro2Dat->SCP2PtrSig;
}


}

void SqlInsertIntoProductosSiscom(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
			     int *pintPtrNRegSql)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"insert into Productos values('%s','%s',%s,%s);",
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	SiscomObtenDato(pLCSiscomPro2Dat,"DscProducto"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdUnidad"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdFamilia"));
SiscomAnexaRegistroPro2(pLCSiscomPro2SqlPrim,
			pLCSiscomPro2SqlAct,
			pintPtrNRegSql,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
void SqlInsertIntoPreciosSiscom(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
			     int *pintPtrNRegSql)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"insert into precios 							\n\
	 select '%s',								\n\
	 	(select idpersona from personas where rfc=\'GENERAL\'),		\n\
		0,								\n\
		0,								\n\
		0,								\n\
		nmbtipoprecio							\n\
	 from tipoprecio",
	 SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"));
SiscomAnexaRegistroPro2(pLCSiscomPro2SqlPrim,
			pLCSiscomPro2SqlAct,
			pintPtrNRegSql,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");

}
void SqlInsertIntoExistenciasSiscom(LCamposSiscomPro2 *pLCSiscomPro2Dat,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlPrim,
			     LCamposSiscomPro2 **pLCSiscomPro2SqlAct,
			     int *pintPtrNRegSql)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"insert into existencias values('%s',0,%s);",
	SiscomObtenDato(pLCSiscomPro2Dat,"CveProducto"),
	SiscomObtenDato(pLCSiscomPro2Dat,"IdExpendio"));
SiscomAnexaRegistroPro2(pLCSiscomPro2SqlPrim,
			pLCSiscomPro2SqlAct,
			pintPtrNRegSql,
			"ComandoSQL,EdoRegistro",
			lchrArrSql,
			"");
}
