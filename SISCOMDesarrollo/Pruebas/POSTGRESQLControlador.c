#include<POSTGRESQLComunes.h>
#include <POSTGRESQLControlador.h>
void ControladorComandoSQL(const char *pchrPtrBD,
			   StcLtaRegComSISCOM *pSLRCSisDat)
{
const char *lchrPtrRegreso;
PGconn *lPGCConexion=0;
PGresult *lPGREdo;
StcLtaRegComSISCOM *lSLRCSisDat=pSLRCSisDat;
	if(!(lchrPtrRegreso=POSTGRESQLConectateBD(pchrPtrBD,
				       &lPGCConexion)))
	{
 
		while(lSLRCSisDat)
		{
		  if((lchrPtrRegreso=POSTGRESQLEjecutaComandoSQL(lPGCConexion,
				   	       (const char *)lSLRCSisDat->chrPtrRegistro[0],
					       &lPGREdo)))
		      lSLRCSisDat->chrPtrRegistro[1]=(char *)strdup(lchrPtrRegreso);
		  lSLRCSisDat=lSLRCSisDat->LSRCSISCOMPtrSig;

		}

	}
}
void CreaRegistro(PGresult *pPGRResult,
		  int pintNumCols,
		  int pintNumRegs,
		  StcLtaRegComSISCOM **pSLRCSisPrimReg)
{
char **lchrPtrRegistro;
StcLtaRegComSISCOM *lSLRCSisActual=0;
int lintContador,
    lintContadorJ;
	          for(lintContadorJ=0;lintContadorJ<pintNumRegs;lintContadorJ++)
		  {
		    lchrPtrRegistro=(char **)malloc(sizeof(char *)*(pintNumCols+1));
		    for(lintContador=0;
			lintContador<pintNumCols;
			lintContador++)
		    lchrPtrRegistro[lintContador]=PQgetvalue(pPGRResult,
				                             lintContadorJ,
							     lintContador);
		    SISCOMCreaListaRegCom(lchrPtrRegistro,
				          pSLRCSisPrimReg,
					  &lSLRCSisActual);
		  }
}
void ControladorEjecutaConsulta(const char *pchrPtrBD,
				StcLtaRegComSISCOM *pSLRCSisDat,
				StcLtaRegComSISCOM **pSLRCSisReg)
{
const char *lchrPtrRegreso;
PGconn *lPGCConexion=0;
PGresult *lPGREdo;
char lchrArrNmbCns[7];
StcLtaRegComSISCOM *lSLRCSisDat=pSLRCSisDat;
int lintNumCols;
int lintNumRegs;
sprintf(lchrArrNmbCns,"%ld",getpid());
	if(!(lchrPtrRegreso=POSTGRESQLConectateBD(pchrPtrBD,
				       &lPGCConexion)))
	{
		while(lSLRCSisDat)
		{
		    if((lchrPtrRegreso=POSTGRESQLEjecutaConsulta(
					lPGCConexion,
					lchrArrNmbCns,
					(const char *)lSLRCSisDat->chrPtrRegistro[0],
					&lintNumCols,
					&lintNumRegs,
					&lPGREdo)))
			CreaRegistro(lPGREdo,
				     lintNumCols,
				     lintNumRegs,
				     pSLRCSisReg);
		  lSLRCSisDat=lSLRCSisDat->LSRCSISCOMPtrSig;
				     
		}
	}
}
