#include <POSTGRESQLComunes.h>

const char *POSTGRESQLConectateBD(const char *pchrPtrNmbBD,
				  PGconn **pPGCPtrConexion)
{
PGresult *lPGRReg=0;
char *lchrPtrRegreso=0;
	  *pPGCPtrConexion=PQsetdb(0,(char *)getenv("PtoPostgres"),0,0,pchrPtrNmbBD);
	  if(PQstatus(*pPGCPtrConexion)==CONNECTION_BAD)
	  {
		lchrPtrRegreso=PQerrorMessage(*pPGCPtrConexion);
		PQfinish(*pPGCPtrConexion);
	 }
   return lchrPtrRegreso;
}
const char *POSTGRESQLEjecutaComandoSQL(PGconn *pPGCPtrConexion,
					const char *pchrPtrComandoSQL,
					int pintEvaluaEstatus,
					PGresult **pPGRRegreso)
{
const char *lchrPtrRegreso=0;
	*pPGRRegreso=PQexec(pPGCPtrConexion,
			    pchrPtrComandoSQL);
	if(pintEvaluaEstatus && PQresultStatus(*pPGRRegreso)!=PGRES_COMMAND_OK)
	lchrPtrRegreso=PQerrorMessage(pPGCPtrConexion);
	
	return lchrPtrRegreso;

}
const char *POSTGRESQLEjecutaConsulta(PGconn *pPGCPtrConexion,
				      const char *pchrPtrNmbConsulta,
				      const char *pchrPtrConsulta,
				      int *pintPtrNumColumnas,
				      int *pintPtrNumReg,
				      PGresult **pPGRPtrResul)
{
const char *lchrPtrRegreso=0;
char *lchrPtrCadConsulta;
char lchrArrNmbCursor[128];
char lchrArrFetch[256];

lchrPtrCadConsulta=(char *)malloc(strlen(pchrPtrConsulta)+256);
	if(!(lchrPtrRegreso=POSTGRESQLEjecutaComandoSQL(pPGCPtrConexion,
						       "begin",
						       1,
						       pPGRPtrResul)))
	{
	  sprintf(lchrArrNmbCursor,
		  "Cursor%s",pchrPtrNmbConsulta);
	  sprintf(lchrPtrCadConsulta,
		  "declare %s cursor for %s",
		  lchrArrNmbCursor,
		  pchrPtrConsulta);
	  sprintf(lchrArrFetch,
		  "fetch all in %s",
		  lchrArrNmbCursor);
	   PQclear(*pPGRPtrResul);
	  if(!(lchrPtrRegreso=POSTGRESQLEjecutaComandoSQL(pPGCPtrConexion,
					  		 lchrPtrCadConsulta,
						         1,
							 pPGRPtrResul)))
	  {
	      PQclear(*pPGRPtrResul);
	     if(!(lchrPtrRegreso=POSTGRESQLEjecutaComandoSQL(pPGCPtrConexion,
					  		 lchrArrFetch,
							 0,
							 pPGRPtrResul)))
	     {
	        *pintPtrNumColumnas=PQnfields(*pPGRPtrResul);
		*pintPtrNumReg=PQntuples(*pPGRPtrResul);
		return lchrPtrRegreso;
	     }
	     else
	     {
	     printf("%x\n",lchrPtrRegreso);
	     return lchrPtrRegreso;
	     }
	  }
	  else
	  {
	  printf("POSTGRESQLEjecutaConsulta:[fetch]%s\n",lchrPtrRegreso);
	     return lchrPtrRegreso;
	  }
	}
	else
	{
	printf("POSTGRESQLEjecutaConsulta:[begin]%s\n",lchrPtrRegreso);
	     return lchrPtrRegreso;
	}
    
}
