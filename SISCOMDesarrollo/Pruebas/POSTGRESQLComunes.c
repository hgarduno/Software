#include <POSTGRESQLComunes.h>

const char *POSTGRESQLConectateBD(const char *pchrPtrNmbBD,
				  PGconn **pPGCPtrConexion)
{
PGresult *lPGRReg=0;
char *lchrPtrRegreso=0;
	  *pPGCPtrConexion=PQsetdb(0,0,0,0,pchrPtrNmbBD);
	  if(PQstatus(*pPGCPtrConexion)==CONNECTION_BAD)
	  {
		lchrPtrRegreso=PQerrorMessage(*pPGCPtrConexion);
		PQfinish(*pPGCPtrConexion);
	 }
   return lchrPtrRegreso;
}
const char *POSTGRESQLEjecutaComandoSQL(PGconn *pPGCPtrConexion,
					const char *pchrPtrComandoSQL,
					PGresult **pPGRRegreso)
{
const char *lchrPtrRegreso=0;
	*pPGRRegreso=PQexec(pPGCPtrConexion,
			    pchrPtrComandoSQL);
	if(PQresultStatus(*pPGRRegreso)!=PGRES_COMMAND_OK)
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
const char *lchrPtrRegreso;
char lchrArrCadConsulta[1024];
char lchrArrNmbCursor[128];
char lchrArrFetch[256];
	if((lchrPtrRegreso=POSTGRESQLEjecutaComandoSQL(pPGCPtrConexion,
						       "begin",
						       pPGRPtrResul)))
	{
	  sprintf(lchrArrNmbCursor,
		  "Cursor%s",pchrPtrNmbConsulta);
	  sprintf(lchrArrCadConsulta,
		  "declare %s cursor for %s",
		  lchrArrNmbCursor,
		  pchrPtrConsulta);
	  sprintf(lchrArrFetch,
		  "fetch all in %s",
		  lchrArrNmbCursor);

	  if((lchrPtrRegreso=POSTGRESQLEjecutaComandoSQL(pPGCPtrConexion,
					  		 lchrArrFetch,
							 pPGRPtrResul)))
	  {
	     if((lchrPtrRegreso=POSTGRESQLEjecutaComandoSQL(pPGCPtrConexion,
					  		 lchrArrCadConsulta,
							 pPGRPtrResul)))
	     {
	        *pintPtrNumColumnas=PQnfields(*pPGRPtrResul);
		*pintPtrNumReg=PQntuples(*pPGRPtrResul);
	     }
	     else
	     {
	     printf("%s\n",lchrPtrRegreso);
	     return lchrPtrRegreso;
	     }
	  }
	  else
	  {
	  printf("%s\n",lchrPtrRegreso);
	     return lchrPtrRegreso;
	  }
	}
	else
	{
	printf("%s\n",lchrPtrRegreso);
	     return lchrPtrRegreso;
	}
}
