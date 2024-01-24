#include<ADFuncionesComunesPostgreSQL.h>
#include<stdio.h>
#include <stdlib.h>
PGconn *POSTGRESQLConectate(PARDEPURACION STRUCTError *pstcErrorPtrReg)
{
PGresult *lPGresultReg=NULL;
PGconn *lPGconnReg=NULL;
char *lchrArrBaseDeDatos=getenv("BASESISCOM");
lPGconnReg=PQsetdb(NULL,NULL,NULL,NULL,lchrArrBaseDeDatos);
  if (PQstatus(lPGconnReg) == CONNECTION_BAD)
  {
    printf("Error al conectarse a la base de datos '%s' Error.\n", "Siscom");
    printf("\n%s\n", PQerrorMessage(lPGconnReg));
    PQfinish(lPGconnReg);
    exit(1);
  }
  return lPGconnReg;
}
int POSTGRESQLEjecutaFuncion(PARDEPURACION PGconn *pPGconnPtr,PGresult **pPGresultPtrReg,char *pchrPtrEjecuta,STRUCTError *pstcErrorPtrReg)
{
		printf("POSTGRESQLEjecutaFuncion:%s\n",pchrPtrEjecuta);
        	*pPGresultPtrReg=PQexec(pPGconnPtr,pchrPtrEjecuta);
		printf("Realmente lo ejecuton\n");

	       return POSTGRESQLEvaluaEstatus(PDEPURACION pPGconnPtr,*pPGresultPtrReg,pstcErrorPtrReg);	

}
int POSTGRESQLEvaluaEstatus(PARDEPURACION PGconn *pPGconnPtrConexion,PGresult *pPGresultPtrReg,STRUCTError *pstcErrorPtrReg)
{
	if(PQresultStatus(pPGresultPtrReg)!=PGRES_COMMAND_OK)
	{
		 printf("\t%s\n",PQerrorMessage(pPGconnPtrConexion));
		 if(pstcErrorPtrReg)
		 sprintf(pstcErrorPtrReg->chrErrorLogico,"%s",PQerrorMessage(pPGconnPtrConexion));
		 return 1;
	}
	return 0;
}
