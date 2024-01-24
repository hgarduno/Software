#include <Servidor.h>


int errno;
FILE *gPtrFleArchivoLog;
int main(int pintArgc,
	 char **pchrPtrArgv)
{

struct sockaddr_in lSSocAddrInReg;
gPtrFleArchivoLog=stdout;
int lintSocket,
	lintTamano,
	lintSocketCliente,
	lintIdProceso;


	if((lintSocket=IniciaServidorComunicaciones(4545))<0)
	{

	}
	else
	{
	 lintTamano=sizeof(struct sockaddr_in);
	  signal(SIGCHLD,SIG_IGN);
	   while(1)
	   {
	         if((lintSocketCliente=accept(lintSocket,
					      (struct sockaddr *)&lSSocAddrInReg,
					      &lintTamano))<0)
	 	 {

		 }
		 else
		 {
		 if(!(lintIdProceso=fork()))
		  ProcesaInformacion(lintSocketCliente);
	         else
		   close(lintSocketCliente);
		}
					      
	   } 

	}


}
void ProcesaInformacion(int pintSocket)

{
char lchrArrSocket[5];
	sprintf(lchrArrSocket,
		"%d",
		pintSocket);
	if(execl("Procesa","Procesa",lchrArrSocket,0)<0)
	{
	 fprintf(gPtrFleArchivoLog,
		  "EXECL:%s\n",
		  strerror(errno));
	  return ;	
	}


}
int IniciaServidorComunicaciones(int pintPtoCom)
{
int lintSocket;
int lintTamano;
struct sockaddr_in lSSocAddrInDir;


	if((lintSocket=socket(PF_INET,SOCK_STREAM,0) )<0)
	{
	  fprintf(gPtrFleArchivoLog,
		  "SOCKET:%s\n",
		  strerror(errno));
	  return -1;	
		   
	}
	else
	{
	 lSSocAddrInDir.sin_port=htons(pintPtoCom);
	 lSSocAddrInDir.sin_family=AF_INET;
	 lSSocAddrInDir.sin_addr.s_addr=INADDR_ANY;
	 if(bind(lintSocket,
		 (struct sockaddr *)&lSSocAddrInDir,
		 sizeof(struct sockaddr_in))<0)
	 {
	  fprintf(gPtrFleArchivoLog,
		  "BIND:%s\n",
		  strerror(errno));
	  return -1;	


	 }
	 else
 	   if(listen(lintSocket,100)<0)
	  {
		fprintf(gPtrFleArchivoLog,
		  "LISTEN:%s\n",
		  strerror(errno));
	  return -1;	

	  }

	 
	}
	return lintSocket;	
}
