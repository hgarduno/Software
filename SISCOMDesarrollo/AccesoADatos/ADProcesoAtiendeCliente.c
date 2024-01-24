#include <stdio.h>
#include <unistd.h>
#include <ADProcesoAtiendeCliente.h>
#include <signal.h>
void ManejadorSenales(int );
int main(int pintArgc,char **pchrPtrArgv)
{
	int lintSocketCliente;
	char lchrArrNomDll[256],lchrArrFuncion[256];
	int lintTuberia[2];
	STRUCTError lstcErrorReg;
	STRUCTDatosDeLaOperacion lstcDatosDeLaOperacionReg;
	char lchrArrRegreso[2048];
		
	signal(SIGSEGV,ManejadorSenales);
	signal(SIGPIPE,ManejadorSenales);
	ADLeeArgumentosProcesosAtiendeCliente(DATODEP pintArgc,pchrPtrArgv,&lintSocketCliente,&lstcErrorReg);
	RNADLeeDatosDeLaOperacion(DATODEP lintSocketCliente,&lstcDatosDeLaOperacionReg,&lstcErrorReg);	
	pipe(lintTuberia);
	ADCopiaDatosDeLaOperacionALaTuberia(DATODEP lintTuberia[1],lstcDatosDeLaOperacionReg,&lstcErrorReg);
	printf("%s %s\n",
		lstcDatosDeLaOperacionReg.chrArrNomDll,
		lstcDatosDeLaOperacionReg.chrArrNomFuncion);		
	RNADCargaDllYEjecutaFuncion(DATODEP lstcDatosDeLaOperacionReg.chrArrNomDll,lstcDatosDeLaOperacionReg.chrArrNomFuncion,lintSocketCliente,0,0,NULL,&lstcErrorReg);
#ifdef DEBUG
#ifdef ARCHIVOLOG
	fclose(lfleRedSTDOUT);
#endif 
#endif
 
}
int ADCopiaDatosDeLaOperacionALaTuberia(PARDEPURACION int lintTuberia,STRUCTDatosDeLaOperacion pstcDatosDeLaOperacionReg,STRUCTError *pstcErrorPtrReg)
{
	char lchrArrCadena[1000];
	int lintTamano;
#ifdef DEBUG
      strcat(PDEPURACION "\t");
      SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%0inSTRUCTDatosDeLaOperacion%","ADCopiaDatosDeLaOperacionALaTuberia",pstcDatosDeLaOperacionReg);
#endif
	RNADFormaCadenaDatosDeLaOperacion(PDEPURACION pstcDatosDeLaOperacionReg,lchrArrCadena,pstcErrorPtrReg);
	Write(lintTuberia,lchrArrCadena,strlen(lchrArrCadena));
	 

}
int ADLeeArgumentosProcesosAtiendeCliente(PARDEPURACION int pintArgc,char **pchrPtrArgv,int *pintPtrSocket,STRUCTError *pstcErrorPtrReg)
{
int lchrCaracter;

	while((lchrCaracter=getopt(pintArgc,pchrPtrArgv,":A:B:"))!=-1)
	{
		switch(lchrCaracter)
		{
			case 'A':
				  *pintPtrSocket=atoi(optarg);	
			break;
			case 'B':
			break;
		}

	}

}

void ManejadorSenales(int pintSenal)
{
      switch(pintSenal)
      {
        case SIGSEGV:
        printf("\n\nEl servidor de Acceso A Datos recibio segmentacion de memoria\n");
        exit(0);
	break;
	case SIGPIPE:
	printf("\n\nEl servidor de Acceso A Datos Perdio La Conexion Con Reglas del negocio \n");
        exit(0);

	break;
      }
}

