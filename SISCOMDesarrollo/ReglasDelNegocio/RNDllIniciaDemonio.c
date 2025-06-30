#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <EstructurasSISCOM.h>
#include <errno.h>
#include <string.h>
int errno;
/*
 Para solicitar la informacion de los procesos me tendre que conectar al 
 servidor de acceso a datos, entonces es importante considerar que para
 obtener esta informacion se utilizaran sockets
 */
void AsignaMemoriaParaArgumentos(char ***,int );
int CargaProcesosYDll(int,unsigned long,int,char *,char *,char ***);
unsigned long CreaMemoriaCompartida(void **,int );
void LeeNombresDeProcesosYCopiaSHM(void *);
unsigned CuantosProcesosExisten();
void GeneraArgumentos(int ,char *,int,char *,unsigned long,char ***);
int IniciaMemSHM(unsigned long *);
void CargaServidoresDeReplicacion(void *);
void AlmacenaSHMId(unsigned long);
int CargaProcesosYDll(int pintSocket,unsigned long plngSHMID,int pintPtoSvrAD,char *pchrPtrDirIPSvrAD,char *pchrPtrBinario,char ***pchrPtrArgs)
{
AsignaMemoriaParaArgumentos(pchrPtrArgs,8);
GeneraArgumentos(pintSocket,pchrPtrBinario,pintPtoSvrAD,pchrPtrDirIPSvrAD,plngSHMID,pchrPtrArgs);

}
void CargaServidoresDeReplicacion(void *pvidPtrMemoria)
{
FILE *lFlePtrArchivo;
const char *lchrPtrDirSvrSISCOM=getenv("SVRSISCOM");
char lchrArrNmbArchivo[1024];
int lintI=0;
StcServidoresRep *lstcServidoresRepPtrInfo=(StcServidoresRep *)(pvidPtrMemoria+15*sizeof(STRUCTProcesosYDll));
	if(lchrPtrDirSvrSISCOM)
	{
		sprintf(lchrArrNmbArchivo,"%s/.SvrReplicacionSISCOM.siscom.txt",lchrPtrDirSvrSISCOM);
		if(!(lFlePtrArchivo=fopen(lchrArrNmbArchivo,"r")))
		 {
			 printf("Error al abrir el archivo %s\n",lchrArrNmbArchivo);
			 return ;
		 }
		printf("Los Servidores a los que se replicara\n");
		while(fscanf(lFlePtrArchivo,"%d\t%s",&(lstcServidoresRepPtrInfo+lintI)->intPuertoAD,
					             (lstcServidoresRepPtrInfo+lintI)->chrArrDirIPAD)!=EOF)
		{
			printf("%d\t%s\n",(lstcServidoresRepPtrInfo+lintI)->intPuertoAD,
					(lstcServidoresRepPtrInfo+lintI)->chrArrDirIPAD);
			lintI++;

		}
		fclose(lFlePtrArchivo);
	}
	else
	{

	}

}
int IniciaMemSHM(unsigned long *plngPtrReg)
{
void *lvidSHMDatos;
*plngPtrReg=CreaMemoriaCompartida(&lvidSHMDatos,CuantosProcesosExisten());
LeeNombresDeProcesosYCopiaSHM(lvidSHMDatos);
CargaServidoresDeReplicacion(lvidSHMDatos);
}
void AlmacenaSHMID(unsigned long punslngSHMId)
{
	FILE *lFlePtrArchivoIdSHM;
	const char *lchrPtrDirSvrSISCOM=getenv("SVRSISCOM");
	char lchrArrNmbArchivo[1024];
	if(lchrPtrDirSvrSISCOM)
	{	
	sprintf(lchrArrNmbArchivo,"%s/.SHMIDServidorSiscom.shmid",lchrPtrDirSvrSISCOM);
	  if(!(lFlePtrArchivoIdSHM=fopen(lchrArrNmbArchivo,"w")))
	  {	  
	    printf("AlmacenaSHMID:%s",strerror(errno));
	    return;
	  }
	  printf("El IdSHM en el archivo %s\n",lchrArrNmbArchivo);
	  fprintf(lFlePtrArchivoIdSHM,"%ld",punslngSHMId);
	  fclose(lFlePtrArchivoIdSHM);
	 }
	else
	printf("No Se Ha Definido la variable de Ambiente SVRSISCOM, y no se cargaran los servidores de replicacion\n");

}	
void GeneraArgumentos(int pintSocket,char *pchrPtrBinario,int pintPtoSvrAD,char *pchrPtrDirIPSvrAD,unsigned long punslngSHMID,char ***pchrPtrArgs)
{
	//SISCOMObtenNombreDelBinario(pchrPtrBinario,(*pchrPtrArgs)[0]);
	strcpy(pchrPtrBinario,"RNProcesoAtiende.bin");
	strcpy((*pchrPtrArgs)[0],"RNProcesoAtiende.bin");			
	sprintf((*pchrPtrArgs)[1],"-A%d",pintSocket);
	sprintf((*pchrPtrArgs)[2],"-B%ld",punslngSHMID);
	sprintf((*pchrPtrArgs)[3],"-C%d",pintPtoSvrAD);
	sprintf((*pchrPtrArgs)[4],"-D%s",pchrPtrDirIPSvrAD);
	(*pchrPtrArgs)[5]=NULL;

}
void AsignaMemoriaParaArgumentos(char ***pchrPtrArgv,int pintArgc)
{
	int lintI;
	if((*pchrPtrArgv=(char **)malloc(sizeof(char *)*(pintArgc))))
	{
		for(lintI=0;lintI<pintArgc;lintI++)
		(*pchrPtrArgv)[lintI]=(char *)malloc(256);
	}


}
unsigned CuantosProcesosExisten()
{

return 25;
}
unsigned long CreaMemoriaCompartida(void **pvidPtrMemoria,int pintNumeroDeProcesos)
{
	unsigned long lunslngSHMID;
	unsigned long lunslngTamSHM;
	lunslngTamSHM=(pintNumeroDeProcesos)*sizeof(STRUCTProcesosYDll);
	lunslngTamSHM+=15*sizeof(StcServidoresRep);	
	if((lunslngSHMID=shmget(getpid(),lunslngTamSHM,IPC_CREAT|0666))!=-1)
	{
		if((*pvidPtrMemoria=shmat(lunslngSHMID,0,0))==(void *)-1)
		printf("Error al pegar el segmento de memoria compartida\n");
	}
	AlmacenaSHMID(lunslngSHMID);
return lunslngSHMID;
}
void LeeNombresDeProcesosYCopiaSHM(void *pvidMemoria)
{
STRUCTProcesosYDll lSTRUCTProcesosYDllDatos[]={ {
						 "libADDllRealizaAltaDeProductos.so",
						 "ADDllRealizaAltaDeProductos",
						 1
						},
						
						{
						 "libADDllSistemaDeConsultas.so",
					 	 "ADDllCNSIdentificaConsulta",
						  2	
					         	 
						},
						{
						  "libADDllRealizaAltaDeProductos.so",
						  "ADDllRealizaAltaCompras",
						  3
						},
						{
						  "libADDllRealizaAltaDeProductos.so",
						  "ADDllRealizaAltaVentas",
						  4
							},
						{
						  "libADDllAltaMaquinas.so",
						  "ADDllRealizaAltaMaquinas",
						  5
						},
						{
						  "libADDllAltaAditamentos.so",
						  "ADDllRealizaAltaAditamentos",
						  6
						},
						{
						  "libADDllAltaClientesTextil.so",
						  "ADDllRealizaAltaClientesTextil",
						  7
						},
						{
						  "libADDllAltaColores.so",
						  "ADDllRealizaAltaColores",
						  8
						},
						{
						  "libADDllAltaDiagramaTextil.so",
						  "ADDllRealizaAltaDiagramaTextil",
						  9
						},
						{
						  "libADDllAltaTiposLetras.so",
						  "ADDllRealizaAltaTiposLetras",
						  10
						},
						{
						  "libADDllAltaMarcaDispositivos.so",
						  "ADDllRealizaAltaMarcaDispositivos",
						  11
						},
						{
						  "libADDllAltaMercantiles.so",
						  "ADDllRealizaAltaMercantiles",
						  12
						},
						{
						  "",
						  "",
						  13
						},
							
						{
						  "**libADDllAltaBitacora.so",
						  "**ADDllRealizaAltaBitacora",
						  14
						},
						{
						  "**libADDllAltaAgenda.so",
						  "**ADDllRealizaAltaAgenda",
						  15
						}

					      };
memcpy(pvidMemoria,lSTRUCTProcesosYDllDatos,sizeof(STRUCTProcesosYDll)*15);
}
