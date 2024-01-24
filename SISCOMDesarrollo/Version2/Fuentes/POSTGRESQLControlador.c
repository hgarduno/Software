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
					       0,
					       &lPGREdo)))
		   {
		      fprintf(stderr,"ControladorComandoSQL:{%s}[%s]\n",
			      lSLRCSisDat->chrPtrRegistro[0],
			      lchrPtrRegreso);
		      lSLRCSisDat->chrPtrRegistro[1]=(char *)strdup(lchrPtrRegreso);
		   }

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
		    lchrPtrRegistro[lintContador]=0;
		    SISCOMCreaListaRegCom(lchrPtrRegistro,
				          pSLRCSisPrimReg,
					  &lSLRCSisActual);
		  }
}
void ControladorEjecutaConsulta(const char *pchrPtrBD,
				StcLtaRegComSISCOM *pSLRCSisDat,
				int *pintPtrNumColumnas,
				int *pintPtrNumRegistros,
				StcLtaRegComSISCOM **pSLRCSisReg)
{
const char *lchrPtrRegreso;
PGconn *lPGCConexion=0;
PGresult *lPGREdo;
char lchrArrNmbCns[7];
StcLtaRegComSISCOM *lSLRCSisDat=pSLRCSisDat;
sprintf(lchrArrNmbCns,"%05d",getpid());
	if(!(lchrPtrRegreso=POSTGRESQLConectateBD(pchrPtrBD,
				       &lPGCConexion)))
	{
		while(lSLRCSisDat)
		{

		    if(!(lchrPtrRegreso=POSTGRESQLEjecutaConsulta(
					lPGCConexion,
					lchrArrNmbCns,
					(const char *)lSLRCSisDat->chrPtrRegistro[0],
					pintPtrNumColumnas,
					pintPtrNumRegistros,
					&lPGREdo)))
			CreaRegistro(lPGREdo,
				     *pintPtrNumColumnas,
				     *pintPtrNumRegistros,
				     pSLRCSisReg);
		  lSLRCSisDat=lSLRCSisDat->LSRCSISCOMPtrSig;
				     
		}
	}
}
