#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <ADDllIniciaDemonio.h>
int ADDllConexionBDYCopiaSHM(PARDEPURACION unsigned long *plngPtrRegSHMID)
{
	PGconn *lPGconnPtrConexion;
	void *lvidPtrConexion;
	STRUCTError lstcErrorReg;
	char lchrArrRegreso[]="\n\t";
	SISCOMCreaSegmentoSHM(PDEPURACION getpid(),sizeof(lPGconnPtrConexion),plngPtrRegSHMID,&lvidPtrConexion,&lstcErrorReg);
	lPGconnPtrConexion=PQsetdb(NULL,NULL,NULL,NULL,"Siscom");
	        if (PQstatus(lPGconnPtrConexion) == CONNECTION_BAD)
		{
		   printf("Error al conectarse a la base de datos '%s' Error.\n", "Siscom");
		   printf("%s", PQerrorMessage(lPGconnPtrConexion));
		   PQfinish(lPGconnPtrConexion);
		   exit(1);
		}
	memcpy(lvidPtrConexion,lPGconnPtrConexion,sizeof(lPGconnPtrConexion));	
}
int ADDllGeneraArgumentos(PARDEPURACION int pintSocket,unsigned long plngSHMID,char *pchrPtrBinario,char ***pchrPtrArgs)
{
	SISCOMAsignaMemoriaARGS(PDEPURACION 3,256,pchrPtrArgs);
	strcpy((*pchrPtrArgs)[0],pchrPtrBinario);
	sprintf((*pchrPtrArgs)[1],"-A%d",pintSocket);
	sprintf((*pchrPtrArgs)[2],"-B%ld",plngSHMID);
}
