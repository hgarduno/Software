#include <RNDllConsultasHGE.h>
int RNDllCNSConsultaClientes(PARDEPURACION int pintSocket,int pintTuberia[],char *pchrArrCadenaFormateada,int pintPuertoAD ,char *pchrPtrDIPSvrAD)
{
char lchrArrEncabezado[500],lchrArrTamano[6],lchrArrEncabezado1[500];
char lchrArrCadena[10];
int lintSocketAD;
STRUCTLtaCliente *lstcLtaClientePtrPrim=0;
int lintNRegistros;
char lchrCaracter='*';
#ifdef DEBUG
		
	       SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNDllCNSConsultaClientes");
#endif
          RNADLeeCabeceraProtocolo(PDEPURACION pintTuberia[0],lchrArrEncabezado);
          sprintf(lchrArrTamano,"%05d",strlen(lchrArrEncabezado));
          sprintf(lchrArrEncabezado1,"%s%s%s",lchrArrTamano,lchrArrEncabezado,pchrArrCadenaFormateada);
          SISCOMConectateServidor(PDEPURACION pintPuertoAD,pchrPtrDIPSvrAD,&lintSocketAD,0);
          Write(lintSocketAD,lchrArrEncabezado1,strlen(lchrArrEncabezado1));
	  RNADGeneraLtaCliente(PDEPURACION lintSocketAD,&lintNRegistros,&lstcLtaClientePtrPrim); 
	  RNADEnviaClientes(PDEPURACION pintSocket,lintNRegistros,3,lstcLtaClientePtrPrim);
}

int RNDllCNSConsultaEstGananciaNDisp(PARDEPURACION int pintSocket,int pintTuberia[],char *pchrArrCadenaFormateada,int pintPuertoAD ,char *pchrPtrDIPSvrAD)
{
char lchrArrEncabezado[500],lchrArrTamano[6],lchrArrEncabezado1[500];
char lchrArrCadena[10];
int lintSocketAD;
STRUCTLtaEstGananciaNDisp *lstcLtaEstGananciaNDispPtrPrim=0;
int lintNRegistros;
char lchrCaracter='*';
#ifdef DEBUG

               SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNDllCNSConsultaClientes");
#endif
              RNADLeeCabeceraProtocolo(PDEPURACION pintTuberia[0],lchrArrEncabezado);
              sprintf(lchrArrTamano,"%05d",strlen(lchrArrEncabezado));
              sprintf(lchrArrEncabezado1,"%s%s%s",lchrArrTamano,lchrArrEncabezado,pchrArrCadenaFormateada);
              SISCOMConectateServidor(PDEPURACION pintPuertoAD,pchrPtrDIPSvrAD,&lintSocketAD,0);
              Write(lintSocketAD,lchrArrEncabezado1,strlen(lchrArrEncabezado1));
	      RNADGeneraLtaEstGananciaNDisp(PDEPURACION lintSocketAD,&lintNRegistros,&lstcLtaEstGananciaNDispPtrPrim);
	      RNADEnviaLtaEstGananciaNDisp(PDEPURACION pintSocket,lintNRegistros,3,lstcLtaEstGananciaNDispPtrPrim);

}
