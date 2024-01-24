#include <stdio.h>
#include <unistd.h>
#include <RNProcesoAtiende.h>
#include <signal.h>
void ManejadorSenales(int );
int main(int pintArgc,char **pchrPtrArgv)
{
	char lchrArrDatos[10000];
	int lintSocketCliente,lintPuertoSvrAD;
	unsigned long lusnlngSHMID;
	int lintTuberia[2];
	char lchrArrNombreDllRN[256],lchrArrNombreFuncionRN[256];
	char lchrArrDirIPSvrAD[20];
	STRUCTDatosDeLaOperacion lstcDatosDeLaOperacionReg;
	STRUCTProcesosYDll *lSTRUCTProcesosYDllMemSHM,lstcProcesosYDllReg;
	STRUCTError lSTRUCTErrorReg;
#ifdef DEBUG
	char pchrPtrTabulador[2024];
#ifdef ARCHIVOLOG
	FILE *lfleRedSTDOUT;
	char lchrArrNombreArchivo[1000];
	sprintf(lchrArrNombreArchivo,"/tmpDemonioSiscom/RNProcesosoAtiende.bin.%ld",getpid());
	lfleRedSTDOUT=freopen(lchrArrNombreArchivo,"a+",stdout);
#endif 
	strcpy(pchrPtrTabulador,"\n\t");
#endif 
	pipe(lintTuberia);
	signal(SIGSEGV,ManejadorSenales);
	signal(SIGPIPE,ManejadorSenales);
#ifdef DEBUG
	printf("\n\nRNProcesoAtiende main () ");
#endif 
	RNLeeParametrosAtiende(PDEPURACION pintArgc,pchrPtrArgv,&lintSocketCliente,&lusnlngSHMID,&lintPuertoSvrAD,lchrArrDirIPSvrAD,&lSTRUCTErrorReg);
	RNMemoriaSHM(PDEPURACION lusnlngSHMID,&lSTRUCTProcesosYDllMemSHM,&lSTRUCTErrorReg);
	RNADLeeDatosDeLaOperacion(PDEPURACION lintSocketCliente,&lstcDatosDeLaOperacionReg,&lSTRUCTErrorReg);
	RNIdentificaMovimiento(PDEPURACION atoi(lstcDatosDeLaOperacionReg.chrArrMovimiento),lSTRUCTProcesosYDllMemSHM,&lstcProcesosYDllReg,&lSTRUCTErrorReg);
	RNCopiaDllYFuncion(PDEPURACION lchrArrNombreDllRN,lchrArrNombreFuncionRN,&lstcDatosDeLaOperacionReg);
	RNCopiaDatosSTRUCTProcesosYDllASTRUCTDatosDeLaOperacion(PDEPURACION lstcProcesosYDllReg,&lstcDatosDeLaOperacionReg);
	RNADFormaProtocoloEncabezado(PDEPURACION lintTuberia[1],lstcDatosDeLaOperacionReg,lSTRUCTErrorReg);
	RNADCargaDllYEjecutaFuncion(PDEPURACION lchrArrNombreDllRN,lchrArrNombreFuncionRN,lintSocketCliente,lintTuberia,lintPuertoSvrAD,lchrArrDirIPSvrAD,&lSTRUCTErrorReg);
#ifdef DEBUG
#ifdef ARCHIVOLOG
	fclose(lfleRedSTDOUT);
#endif 
#endif 	
	
}
void ManejadorSenales(int pintSenal)
{
	switch(pintSenal)
	{
		case SIGSEGV:
				printf("\nEl servidor de Reglas del Negocio Recibio Segmentacion de Memoria \n");
				exit(0);
		break;
		case SIGPIPE:
				printf("\nEl servidor de Reglas del Negocio Perdio la conexion con el cliente  \n");
				exit(0);
		break;

	}

}
int RNCopiaDatosSTRUCTProcesosYDllASTRUCTDatosDeLaOperacion(PARDEPURACION STRUCTProcesosYDll pstcProcesosYDllDat,STRUCTDatosDeLaOperacion *pstcDatosDeLaOperacionPtrReg)
{
#ifdef DEBUG
strcat(pchrPtrTabulador,"\t");	
SISCOMImprimeFuncionYArgumentos(pchrPtrTabulador,"%00F%0INSTRUCTProcesosYDll%0INSTRUCTDatosDeLaOperacion*%","RNCopiaDatosSTRUCTProcesosYDllASTRUCTDatosDeLaOperacion",pstcProcesosYDllDat,pstcDatosDeLaOperacionPtrReg);	
#endif 
	strcpy(pstcDatosDeLaOperacionPtrReg->chrArrNomDll,pstcProcesosYDllDat.chrArrNombreProceso);
	strcpy(pstcDatosDeLaOperacionPtrReg->chrArrNomFuncion,pstcProcesosYDllDat.chrArrNombreDll);

}
int RNCopiaDllYFuncion(PARDEPURACION char *pchrPtrNomDll,char *pchrPtrNomFuncion,STRUCTDatosDeLaOperacion *pstcDatosDeLaOperacionPtrReg)
{
#ifdef DEBUG
strcat(pchrPtrTabulador,"\t");
SISCOMImprimeFuncionYArgumentos(pchrPtrTabulador,"%00F%0INchar*%0inchar*%","RNCopiaDllYFuncion",pchrPtrNomDll,pchrPtrNomFuncion);
#endif
	strcpy(pchrPtrNomDll,pstcDatosDeLaOperacionPtrReg->chrArrNomDll);
	strcpy(pchrPtrNomFuncion,pstcDatosDeLaOperacionPtrReg->chrArrNomFuncion);

}
int RNLeeParametrosAtiende(PARDEPURACION int pintArgc,char **pchrPtrArgv,int *pintSocketCliente,unsigned long *pusnlngSHMID,int *pintPuerto,char *pchrPtrDirIPSvr,STRUCTError *pSTRUCTErrorPtrReg)
{
char lchrCaracter;
	while((lchrCaracter=getopt(pintArgc,pchrPtrArgv,":A:B:C:D:"))!=-1)
	{
		switch(lchrCaracter)
		{
		  case 'A':
			  *pintSocketCliente=atoi(optarg);
		  break;
		  case 'B':
		  	  *pusnlngSHMID=atol(optarg);
		  break;
		  case 'C':
		  	  *pintPuerto=atoi(optarg);	
		  break;
		  case 'D':
		  	  strcpy(pchrPtrDirIPSvr,optarg);	
		  break;

		}

	}

}
int RNMemoriaSHM(PARDEPURACION unsigned long pusnlngSHM,STRUCTProcesosYDll **pSTRUCTProcesosYDllPtrReg,STRUCTError *pSTRUCTErrorPtrReg)
{
	if((*pSTRUCTProcesosYDllPtrReg=(STRUCTProcesosYDll *)shmat(pusnlngSHM,0,0))==(void *)-1)
	printf("Error al pegar la memoria SHM idshm=%ld\n",pusnlngSHM);
}
int RNIdentificaMovimiento(PARDEPURACION int pintMovimiento,STRUCTProcesosYDll *pSHMReg,STRUCTProcesosYDll *pstcProcesosYDllPtrReg,STRUCTError *pSTRUCTErrorPtrReg)
{
	char lchrEncabezado[11];
	STRUCTProcesosYDll lSTRUCTProcesosYDllDat;
	
	memset(&lSTRUCTProcesosYDllDat,0,sizeof(STRUCTProcesosYDll));
	RNBuscaMovimientos(PDEPURACION pSHMReg,pintMovimiento,&lSTRUCTProcesosYDllDat,pSTRUCTErrorPtrReg);
	if(lSTRUCTProcesosYDllDat.lngTipoDeMovimiento)
		*pstcProcesosYDllPtrReg=lSTRUCTProcesosYDllDat;
}
int RNBuscaMovimientos(PARDEPURACION STRUCTProcesosYDll *pSTRUCTProcesosYDllLis,int pintDato,STRUCTProcesosYDll *pSTRUCTProcesosYDllReg,STRUCTError *pSTRUCTErrorPtrReg)
{
	do
	{
		if(pSTRUCTProcesosYDllLis->lngTipoDeMovimiento==pintDato)
		{
		*pSTRUCTProcesosYDllReg=*pSTRUCTProcesosYDllLis;
		break;
		}
	}while(pSTRUCTProcesosYDllLis++);
}
