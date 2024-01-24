#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ADSistemaDeConsultas.h>
int main(int pintArgc,char **pchrPtrArgv)
{
	
}
int ADRealizaConsulta(int pintSocket,char *pchrPtrNomDll,STRUCTError *pSTRUCTErrorPtrReg)
{
	STRUCTListaProcesosYDll *strListaProcesosYDll;
	int lintQueProceso;
	int (*SISCOMEjecutaConsulta)(int,STRUCTListaProcesosYDll **,STRUCTError *);
	SISCOMCargaDllYBuscaFuncion(pchrPtrNomDll,char *pchrPtrFunciones,&SISCOMEjecutaConsulta);
	ADObtenDatosConsultaProcesosYDll(pintSocket,&lintQueProceso,pSTRUCTErrorPtrReg);
	SISCOMEjecutaConsulta(lintQueProceso,&strListaProcesosYDll,pSTRUCTErrorPtrReg);
	ADRespondeConsultaProcesosYDll(pintSocket,strListaProcesosYDll,pSTRUCTErrorPtrReg);
        	
}
int  ADObtenDatosConsultaProcesosYDll(int pintSocket,int *pintPtrMov,STRUCTError *pSTRUCTErrorPtrReg)
{

}
int ADEjecutaConsultaProcesosYDll(char *pchrPtrNomDll,int pintMov,STRUCTListaProcesosYDll **pstcListaProcesosYDllPtrReg,STRUCTError *pstcErrorReg)
{
	
}
int ADRespondeConsultaProcesosYDll(int pintSocket,STRUCTListaProcesosYDll *pstcListaProcesosYDll,STRUCTError *pstcErrorPtrReg)
{
	
}
int ADLeeArgumentosSistemaDeConsultas(int pintArgc,char **pchrPtrArgv,int *pintSocket,char *pchrPtrNomDll,int *pintCualConsulta,STRUCTError *pSTRUCTErrorPtrReg)
{
	char lchrCaracter;
	while((lchrCaracter=getopt(pintArgc,pchrPtrArgv,":A:B:C:"))!=-1)
	{
		switch(lchrCaracter)
		{
			case 'A':
				 *pintSocket=atoi(optarg);	
			break;
			case 'B':
				strcpy(pchrPtrNomDll,optarg);
			break;	
			case 'C':
				*pintCualConsulta=atoi(optarg);	
			break;
				
			
		}
	}

}

