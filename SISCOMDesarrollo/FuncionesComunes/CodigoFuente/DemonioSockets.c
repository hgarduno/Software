#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <DemonioSockets.h>
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
static unsigned long lusnlngIDSHM;
unsigned int gintNProcesos=0;
int gintSocketCliente;
int main(int pintArgc,char **pchrPtrArgv)
{
int lintPto,lintNProcesos,lintTamano,lintI=0;
int lintSocketReg,lintSocketComunicaciones;
char lchrArrProcesoC[1024],lchrArrNomDll[1024],lchrArrNomFuncion[256],lchrArrNomFISHM[256];
int lintPtoSvrAD;
char lchrArrDirIPSvrAD[20];
char **lchrPtrRegArgs;
int lintIdProceso;
STRUCTError lSTRUCTErrorReg;
struct sockaddr_in lsockaddr_inDir,lsocaddr_inReg;
FILE *lFlePtrSalidaEstandar;
memset(lchrArrProcesoC,0,1023);
memset(lchrArrNomDll,0,1023);
memset(lchrArrNomFuncion,0,254);
memset(lchrArrNomFISHM,0,254);
printf("Iniciando...\n");
SISCOMLeeArgumentosDemonioSockets(pintArgc,pchrPtrArgv,&lintPto,lchrArrProcesoC,&lintNProcesos,lchrArrNomDll,lchrArrNomFuncion,lchrArrNomFISHM,&lintPtoSvrAD,lchrArrDirIPSvrAD,&lSTRUCTErrorReg);
printf("Despues SISCOMLeeArgumentosDemonioSockets\n");
if(lchrArrNomFISHM[0])
SISCOMIniciaSHM(&lusnlngIDSHM,lchrArrNomDll,lchrArrNomFISHM);
lsockaddr_inDir.sin_port=htons(lintPto);
lsockaddr_inDir.sin_family =AF_INET;
lsockaddr_inDir.sin_addr.s_addr=INADDR_ANY;
lintTamano=sizeof(struct sockaddr_in);
signal(30,SISCOMInstalaManejadorDeSenales);
signal(SIGSEGV,SISCOMInstalaManejadorDeSenales);
signal(SIGTERM,SISCOMInstalaManejadorDeSenales);
	if( (gintSocketCliente=lintSocketReg=socket(PF_INET,SOCK_STREAM,0) ) ==-1)
	{
	printf("Error al crear el socket\n");
	exit(0);
	}
	else
	if((bind(lintSocketReg,(struct sockaddr *)&lsockaddr_inDir,sizeof(struct sockaddr_in)))==-1)
	{
	printf("Error al enlazar el socket\n");
	exit(0);
	}
	else
	if((listen(lintSocketReg,lintNProcesos))==-1)
	printf("Error al ponerse a la escucha\n");
	else;
	signal(SIGCHLD,SIG_IGN);
	if(!(lintIdProceso=fork()))
	{	
	   ReDireccionaSalidaEstandar(lintPto);
	  while(1)
	 {
	   if((lintSocketComunicaciones=accept(lintSocketReg,(struct sockaddr *)&lsocaddr_inReg,&lintTamano))!=-1)
	   { 	   
	         if(lchrArrNomDll[0])
	         SISCOMCargaDllYEjecutaFunciones(lintSocketComunicaciones,lusnlngIDSHM,lintPtoSvrAD,lchrArrDirIPSvrAD,lchrArrNomDll,lchrArrNomFuncion,lchrArrProcesoC,&lchrPtrRegArgs);
	         else
	         SISCOMCreaArgumentosSinDLL(lchrArrProcesoC,lintSocketComunicaciones,lintPtoSvrAD,lchrArrDirIPSvrAD,&lchrPtrRegArgs);	    
	         SISCOMAtiendeClientes(lchrArrProcesoC,lchrPtrRegArgs,lintSocketComunicaciones,&lSTRUCTErrorReg);
	    }
	   close(lintSocketComunicaciones);
	 }
	}
	else
	AlmacenaPid(lintIdProceso,lintPto);
close(lintSocketComunicaciones);	
return 0;
}
FILE *ReDireccionaSalidaEstandar(int pintPuerto)
{
char lchrArrArchivo[1024];
sprintf(lchrArrArchivo,
	"DemonioDeConexiones.%d.log",
	 pintPuerto);
return freopen(lchrArrArchivo,"a+",stdout);
}
void AlmacenaPid(int pintIdProceso,int pintPuertoCom)
{
const char *lchrPtrDirSvrSiscom=getenv("DIRSVRSISCOM");
FILE *lFlePtrArchivo;
char lchrArrNmbArchivo[1024];
	sprintf(lchrArrNmbArchivo,
		"%s/DemonioDeConexiones.%d",lchrPtrDirSvrSiscom,pintPuertoCom);
	if((lFlePtrArchivo=fopen(lchrArrNmbArchivo,"w")))
	{
		fprintf(lFlePtrArchivo,"%d",pintIdProceso);
		fclose(lFlePtrArchivo);
	}


	


}
int SISCOMAtiendeClientes(char *pchrPtrBinario,char **pchrPtrArgs,int pintSocketComunicaciones,STRUCTError *pSTRUCTErrorPtrReg)
{
pid_t lpid_tProceso;
int lintI=0;

		lpid_tProceso=fork();
		if(lpid_tProceso)
		{	
		close(pintSocketComunicaciones);
		}
		if(!lpid_tProceso)
		if(execvp(pchrPtrBinario,pchrPtrArgs)==-1)
		{
		printf("Error al cargar el proceso %s ",pchrPtrBinario);		
		while(pchrPtrArgs[lintI])
		printf("%s ",pchrPtrArgs[lintI++]);
		printf("\n");
		}
		
gintNProcesos++;

}
int SISCOMLeeArgumentosDemonioSockets(int pintArgc,char **pchrPtrArgv,int *pintPtrPuerto,char *pchrPtrProceso,
					int *pintPtrNProceso,char *pchrPtrNomDLL,char *pchrPtrFunciones,char *pchrPtrIniciaSHM,int *pintPtrPtoAD,char *pchrPtrDirIPSvrAD,STRUCTError *pSTRUCTErrorPtrReg)
{
int lintCaracter;
pSTRUCTErrorPtrReg->intNumError=0;
if(pintArgc<4)
{
SISCOMModoDeUsoDemonio();	
exit(1);
}
	while( (lintCaracter=getopt(pintArgc,pchrPtrArgv,":A:B:C:D:E:F:G:H:"))!=-1)
	{
		switch(lintCaracter)
		{
		    case 'A':
			      *pintPtrPuerto=atoi(optarg);
			      if(!*pintPtrPuerto)
			      LlenaEstructuraDeError(1,0,"SISCOMLeeArgumentosDemonioSockets","",pSTRUCTErrorPtrReg);	      
			      
	    	    break;
		    case 'B':
		    	      strcpy(pchrPtrProceso,optarg);	
			      if(pchrPtrProceso[0]==0)
				LlenaEstructuraDeError(2,0,"SISCOMLeeArgumentosDemonioSockets","",pSTRUCTErrorPtrReg);      
			   
                    break;
		    case 'C':
		    	     *pintPtrNProceso=atoi(optarg);
			     if(!*pintPtrPuerto)
				     LlenaEstructuraDeError(3,0,"SISCOMLeeArgumentosDemonioSockets","",pSTRUCTErrorPtrReg);
                    break;
		    case 'D':
		    	    strcpy(pchrPtrNomDLL,optarg);
	    	    break;	    
		    case 'E':
		    	   strcpy(pchrPtrFunciones,optarg);
		    break;
		    case 'F':
		    	  strcpy(pchrPtrIniciaSHM,optarg);
		    break;
                    case 'G':
		    	  *pintPtrPtoAD=atoi(optarg);	
		    break;
                    case 'H':
		    	  strcpy(pchrPtrDirIPSvrAD,optarg);	
		    break;
		    
		    default:
		    	   LlenaEstructuraDeError(4,0,"SISCOMLeeArgumentosDemonioSockets","",pSTRUCTErrorPtrReg);	
			    		    

		}

	}
	return SeDetectoError(*pSTRUCTErrorPtrReg);
}
int SISCOMCargaDllYEjecutaFunciones(int pintSocket,unsigned long plngSHMID,int pintPuertoAD,char *pchrPtrDirIPSvrAD,char *pchrPtrNomDll,char *pchrPtrFunciones,char *pchrPtrBinario,char ***pchrPtrRegArgs)
{
void *lvidDll;
int (*SISCOMFuncion)(int,unsigned long,int ,char *,char *,char ***);
	if(!(lvidDll=dlopen(pchrPtrNomDll,RTLD_LAZY)))
	printf("Error al cargar la dll %s\n",pchrPtrNomDll);
	else	
	if(!(SISCOMFuncion=dlsym(lvidDll,pchrPtrFunciones)))
	printf("La funcion %s no existe en la DLL\n",pchrPtrFunciones);	
	else
	SISCOMFuncion(pintSocket,plngSHMID,pintPuertoAD,pchrPtrDirIPSvrAD,pchrPtrBinario,pchrPtrRegArgs);
	dlclose(lvidDll);
	
}
int SISCOMIniciaSHM(unsigned long *pusnlngIDSHM,char *pchrPtrDll,char *pchrPtrFuncion)
{
void *lvidDll;
int (*SISCOMIniciaMemSHM)(unsigned long *);
	if(!(lvidDll=dlopen(pchrPtrDll,RTLD_LAZY)))
	printf("Error al carga la dll %s\n",pchrPtrDll);
	else
	if(!(SISCOMIniciaMemSHM=dlsym(lvidDll,pchrPtrFuncion)))
	printf("La funcion %s no existe en la Dll \n",pchrPtrFuncion);
	SISCOMIniciaMemSHM(pusnlngIDSHM);
	dlclose(lvidDll);
}
int SISCOMCreaArgumentosSinDLL(char *pchrPtrBinario,int pintPto,int pintPtoSvrAD,char *pchrPtrDirIPSvrAD,char ***pchrPtrArgs)
{
int lintI,lintPos;
char lchrArrCadena[256];
char *lchrPtrRegreso;

	if((*pchrPtrArgs=(char **)malloc(sizeof(char *)*4)))
	{
	 for(lintI=0;lintI<4;lintI++)
	  if(!((*pchrPtrArgs)[lintI]=(char *)malloc(256)) )
	  printf("Error al asignar memoria para los argumentos \n");
	 if(lchrPtrRegreso=strstr(lchrArrCadena,".bin"))
	 {
	     lintPos=atoi(lchrPtrRegreso);
	     while(lchrPtrRegreso[lintPos--]!='/');
	     strcpy((*pchrPtrArgs)[0],pchrPtrBinario+lintPos+1);
	 }
	 sprintf((*pchrPtrArgs)[1],"-A%d",pintPto);
	 sprintf((*pchrPtrArgs)[2],"-B%d",pintPtoSvrAD);
	 sprintf((*pchrPtrArgs)[3],"-C%s",pchrPtrDirIPSvrAD);
	 
	} 

}
void SISCOMInstalaManejadorDeSenales(int pintSenal)
{
	switch(pintSenal)
	{
		case 30:
				printf("Se ha detenido el demonio de conexiones\n");
				printf("Ahora se eliminaran los segmentos de memoria Compartida\n");
				fflush(stdout);
				shmctl(lusnlngIDSHM,IPC_RMID,0);
				close(gintSocketCliente);

				exit(30);
				
		break;
		case SIGCHLD:
				printf("*****************************************************\n");
				printf("************************Termino %ld\n",getpid());
		break;
		case SIGSEGV:
				printf("El Demonio de Conexiones recibio fallo de memoria\n");
				exit(SIGSEGV);
		break;
		case SIGTERM:
				printf("El demonio De Conexiones termi \n");
				exit(SIGTERM);
		break;
	}

}

int SISCOMModoDeUsoDemonio()
{
printf("\nPrograma  que se ejecuta como demonio, y permite la comunicacion via TCP/IP, permite levantar");
printf("\ninstancias de un proceso determinado para atender a los clientes que se conectan al demonio");
printf("\nAdemas este programa carga una dll, que puede contener dos funciones una que inicie segmentos de memoria compartida");
printf("\nla otra funcion podra formar los argumentos que se le pasaran al proceso, cada proceso podra aceptar dos argumentos");
printf("\nel descriptor del socket y el identificador de SHM");
printf("\nModo de empleo");
printf("\nDemonioDeConexiones.bin -APto -BProcesoHijo.bin -C#Procesos -DNomDll -EIniArgs -FIniSHM\n");
printf("Donde:\n\t[Pto], es un puerto valido donde respondera el servidor");
printf("\n\t[ProcesoHijo.bin], es el nombre del programa binario que se atendera a los clientes, se levantara");
printf("\n\t                   despues de aceptar cada conexion, los argumentos que se pasan a este proceso ");
printf("\n\t                   se deben formar mediante la funcion de nombre IniArgs, que se pasa en el argumento");
printf("\n\t		       -E. Si no se especifica nombre de Dll, funcion de inicio de argumentos y funcion");
printf("\n\t                   de inicio de segmentos de memoria compartida, entonces el unico argumento que se pasara");
printf("\n\t                   es el descriptor del socket donde se acepto la conexion");
printf("\n\t[#Procesos], es un numero entero que representa los clientes que se podran atender simultaneamente");
printf("\n\t[NomDll], el nombre de la dll, que contiene las funciones que  formara los argumentos para");
printf("\n\t          cada instancia que atendera al cliente, y en caso de que se requiera memoria compartida(SHM)");
printf("\n\t          se debe anexar una funcion que realice la inicializacion de la SHM");
printf("\n\t[IniArgs], es el nombre de la funcion que formara los argumentos del proceso que atiende a los clientes");
printf("\n\t[IniSHM], es el nombre de la funcion que iniciara los segmentos de memoria compartida, esta funcion se ejecuta");
printf("\n\t          al inicio del proceso\n");

}
