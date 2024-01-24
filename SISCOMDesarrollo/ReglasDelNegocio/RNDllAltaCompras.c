#include <stdio.h>
#include <unistd.h>
#include <RNDllAltaCompras.h>
#include <stdlib.h>
int RNDllRealizaAltaCompras(PARDEPURACION int pintSocketCliente,int pintTuberia[],int pintPuerto,char *pchrPtrDirIP)
{
char lchrCaracter='*';
int lintI;
int lintNRegistros;
int lintSocketAD;
STRUCTLtaCompras *lstcLtaComprasPtrPrim=NULL;
STRUCTError lstcErrorReg;
#ifdef DEBUG
                strcat(pchrPtrTabulador,"\t");
	        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNDllRealizaAltaCompras");
#endif
		 RNADGeneraListaCompras(PDEPURACION pintSocketCliente,&lintNRegistros,&lstcLtaComprasPtrPrim,&lstcErrorReg);
 		 RNDllPrecioCompraConIVA(PDEPURACION lstcLtaComprasPtrPrim); 
                 RNDllEnviaAltaComprasAD(PDEPURACION lstcLtaComprasPtrPrim,&lintSocketAD,lintNRegistros,pintTuberia,pintPuerto,pchrPtrDirIP);
		 lstcLtaComprasPtrPrim=0;
		 RNADGeneraListaCompras(PDEPURACION lintSocketAD,&lintNRegistros,&lstcLtaComprasPtrPrim,&lstcErrorReg);
		 if(lstcLtaComprasPtrPrim)
		 RNADEnviaRegistrosDeCompras(PDEPURACION pintSocketCliente,lintNRegistros,10,lstcLtaComprasPtrPrim,&lstcErrorReg);
		 else
		 Write(pintSocketCliente,&lchrCaracter,1);

}
int RNDllPrecioCompraConIVA(PARDEPURACION STRUCTLtaCompras *pstcLtaComprasPtrPrim)
{
STRUCTLtaCompras *lstcLtaComprasPtrDat=pstcLtaComprasPtrPrim;	
float lfltPCompraConIVA;
char *lchrPtrRegreso;
	while(lstcLtaComprasPtrDat)
	{	
	 if((lchrPtrRegreso=strstr(lstcLtaComprasPtrDat->stcCompras.chrArrPCompra,"+IVA")))
	 {
		lstcLtaComprasPtrDat->stcCompras.chrArrPCompra[lchrPtrRegreso-lstcLtaComprasPtrDat->stcCompras.chrArrPCompra]=0;
		lfltPCompraConIVA=1.50*atof(lstcLtaComprasPtrDat->stcCompras.chrArrPCompra);
		sprintf(lstcLtaComprasPtrDat->stcCompras.chrArrPCompra,"%.3f",lfltPCompraConIVA);
	 }
	 lstcLtaComprasPtrDat=lstcLtaComprasPtrDat->stcLtaComprasPtrSig; 
	} 
}
int  RNDllEnviaAltaComprasAD(PARDEPURACION STRUCTLtaCompras *pstcLtaComprasPtrDat,int *pintPtrSocketAD,int pintNRegistros,int pintTuberia[],int pintPuerto,char *pchrPtrDirIP)
{
int lintSocketClienteAD;	
STRUCTError lstcErrorReg;
char lchrArrEncabezado[500],lchrArrEncabezado1[500];
char lchrArrTamEncabezado[6];
int lintTamEncabezado;
#ifdef DEBUG
    strcat(pchrPtrTabulador,"\t");
    SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNDllEnviaAltaComprasAD");
#endif
    SISCOMConectateServidor(PDEPURACION pintPuerto,pchrPtrDirIP,&lintSocketClienteAD,&lstcErrorReg);			
    Read(pintTuberia[0],lchrArrTamEncabezado,5);
    lchrArrTamEncabezado[5]=0;
    lintTamEncabezado=atoi(lchrArrTamEncabezado);
    Read(pintTuberia[0],lchrArrEncabezado,lintTamEncabezado);
    lchrArrEncabezado[lintTamEncabezado-5]=0; 
    sprintf(lchrArrEncabezado1,"%05d%s",lintTamEncabezado,lchrArrEncabezado);
    Write(lintSocketClienteAD,lchrArrEncabezado1,lintTamEncabezado);
    RNADEnviaRegistrosDeCompras(PDEPURACION lintSocketClienteAD,pintNRegistros,10,pstcLtaComprasPtrDat,&lstcErrorReg);
    *pintPtrSocketAD=lintSocketClienteAD;
}
