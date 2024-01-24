#include<POSTGRESQLComunes.h>
#include <POSTGRESQLControlador.h>
#include <stdlib.h>
#include <string.h>
void ControladorComandoSQL(const char *pchrPtrBD,
			   const char *pchrPtrPtoBD,
			   LCamposSiscomPro2 *pLCSiscomPro2)
{
const char *lchrPtrRegreso;
PGconn *lPGCConexion=0;
PGresult *lPGREdo;
	if(!(lchrPtrRegreso=POSTGRESQLConectateBD(
					pchrPtrBD,
					pchrPtrPtoBD,
				       &lPGCConexion)))
	{
	   for(;
		pLCSiscomPro2;
	 	pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
		{
		  if((lchrPtrRegreso=POSTGRESQLEjecutaComandoSQL(
				        lPGCConexion,
				   	SiscomObtenDato(pLCSiscomPro2,"ComandoSQL"),
					1,
					&lPGREdo)))
		   {
		      SiscomLog("%s,%s", 
		      		lchrPtrRegreso, 
				SiscomObtenDato(pLCSiscomPro2,"ComandoSQL"));	
		      SiscomAsignaDatoCampo("EdoRegistro",
		                            pLCSiscomPro2->SCSiscomPro2->intNumCampos,
					    lchrPtrRegreso,
					    pLCSiscomPro2->SCSiscomPro2);
		   }
		   

		}
	}
}
void AsignaNombresAlRegistro(PGresult *pPGResult,
			     int pintNCampos,
			     SCampoSiscomPro2 **pSCSiscomPro2)
{
int lintContador;
char **lchrPtrCampos;
	*pSCSiscomPro2=(SCampoSiscomPro2 *)malloc(sizeof(SCampoSiscomPro2 )*(pintNCampos+1));
	lchrPtrCampos=(char **)malloc(sizeof(char *)*(pintNCampos+1));
	
	for(lintContador=0;
	    lintContador<pintNCampos;
	    lintContador++)
	    lchrPtrCampos[lintContador]=PQfname(pPGResult,lintContador); 
	lchrPtrCampos[lintContador]=0;
	SiscomAsignaDatosCampoAlCampo(lchrPtrCampos,*pSCSiscomPro2);
	(*pSCSiscomPro2)->intNumCampos=pintNCampos;

	lchrPtrCampos[pintNCampos]=0;

}
void CreaRegistro(PGresult *pPGRResult,
		  int pintNumCols,
		  int pintNumRegs,
		  SCampoSiscomPro2 *pSCSiscomPro2,
		  LCamposSiscomPro2 **pLCSiscomPro2Prim,
		  LCamposSiscomPro2 **pLCSiscomPro2Act)
{
int lintContador,
    lintContadorJ,
    lintTamano;
SCampoSiscomPro2 *lSCSiscomPro2;

	          for(lintContadorJ=0;lintContadorJ<pintNumRegs;lintContadorJ++)
		  {
		    for(lintContador=0;
			lintContador<pintNumCols;
			lintContador++)
		    {
			SiscomAsignaDatoCampo(
				(pSCSiscomPro2+lintContador)->chrPtrNmbCampo,
				pintNumCols,
				PQgetvalue(pPGRResult,
					    lintContadorJ,
					    lintContador),
				pSCSiscomPro2);
		    }
		    lSCSiscomPro2=(SCampoSiscomPro2 *)malloc((lintTamano=sizeof(SCampoSiscomPro2 )*
							     pSCSiscomPro2->intNumCampos));
		    memcpy(lSCSiscomPro2,
			    pSCSiscomPro2,
			    lintTamano);
		    SiscomCreaListaCamposPro2(lSCSiscomPro2,
					    pLCSiscomPro2Prim,
					    pLCSiscomPro2Act);
		  }
}

void ControladorEjecutaConsulta(const char *pchrPtrBD,
				const char *pchrPtrPtoBD,
				LCamposSiscomPro2 *pLCSiscomPro2,
				int *pintPtrNumColumnas,
				int *pintPtrNumRegistros,
				LCamposSiscomPro2 **pLCSiscomPr2Reg)
{
const char *lchrPtrRegreso;
PGconn *lPGCConexion=0;
PGresult *lPGREdo;
char lchrArrNmbCns[56];
SCampoSiscomPro2 *lSCSiscomPro2;
LCamposSiscomPro2 *lLCSiscomPro2=0;
sprintf(lchrArrNmbCns,"%05d",getpid());
	if(!(lchrPtrRegreso=POSTGRESQLConectateBD(pchrPtrBD,
					pchrPtrPtoBD,
				       &lPGCConexion)))
	{
	   for(;
		pLCSiscomPro2;
	 	pLCSiscomPro2=pLCSiscomPro2->SCP2PtrSig)
		{
		    if(!(lchrPtrRegreso=POSTGRESQLEjecutaConsulta(
					lPGCConexion,
					lchrArrNmbCns,
					SiscomObtenDato(pLCSiscomPro2,"ConsultaSQL"),
					pintPtrNumColumnas,
					pintPtrNumRegistros,
					&lPGREdo))) 
		    {
		 	AsignaNombresAlRegistro(lPGREdo,
						*pintPtrNumColumnas,
						&lSCSiscomPro2);
						
			CreaRegistro(lPGREdo,
				     *pintPtrNumColumnas,
				     *pintPtrNumRegistros,
				     lSCSiscomPro2,
				     pLCSiscomPr2Reg,
				     &lLCSiscomPro2);
		   }
		   else
		   {
		     SiscomLog("Error:%s",lchrPtrRegreso); 
		    }
				     
		}
	}
	else
	  SiscomLog("NO se pudo conectar a la base:%s %s",
	  	    pchrPtrBD,
		    pchrPtrPtoBD);
}
