#include <stdio.h>
#include <unistd.h>
#include <RNDllAltaVentas.h>
#include <RNADFuncionesComunesEZS.h>
void RNDllEjecutaReplicacionAltaVentas(STRUCTLtaVentas *pstcLtaVentasPtrDat,char *pchrPtrEncabezado,int );

int RNDllRealizaAltaVentas(PARDEPURACION int pintSocketCliente, int pintTuberia[], int pintPuerto, char *pchrPtrDirIP)
{
char lchrCaracter;
int lintI;
int lintNRegistros;
STRUCTLtaVentas *lstcLtaVentasPtrPrim = NULL;
STRUCTError lstcErrorReg;

#ifdef DEBUG
	strcat(pchrPtrTabulador, "\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%", "RNDllRealizaAltaVentas");
#endif

 RNADGeneraListaVentas(PDEPURACION pintSocketCliente, &lintNRegistros, &lstcLtaVentasPtrPrim, &lstcErrorReg);
 RNDllEnviaAltaVentasAD(PDEPURACION lstcLtaVentasPtrPrim, lintNRegistros, pintTuberia, pintPuerto, pchrPtrDirIP);
}

int RNDllEnviaAltaVentasAD(PARDEPURACION STRUCTLtaVentas *pstcLtaVentasPtrDat,int pintNRegistros,int pintTuberia[],int pintPuerto,char *pchrPtrDirIP)
{
int lintSocketClienteAD;	
STRUCTError lstcErrorReg;
char lchrArrEncabezado[500], lchrArrEncabezado1[500];
char lchrArrTamEncabezado[6];
int lintTamEncabezado;

#ifdef DEBUG
	strcat(pchrPtrTabulador,"\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNDllEnviaAltaVentasAD");
#endif

 SISCOMConectateServidor(PDEPURACION pintPuerto, pchrPtrDirIP, &lintSocketClienteAD, &lstcErrorReg);			
 Read(pintTuberia[0], lchrArrTamEncabezado, 5);
 lchrArrTamEncabezado[5] = 0;
 lintTamEncabezado=atoi(lchrArrTamEncabezado);
 Read(pintTuberia[0], lchrArrEncabezado, lintTamEncabezado);
 lchrArrEncabezado[lintTamEncabezado-5] = 0; 
 sprintf(lchrArrEncabezado1, "%05d%s", lintTamEncabezado, lchrArrEncabezado);
 Write(lintSocketClienteAD, lchrArrEncabezado1, lintTamEncabezado);
 RNADEnviaRegistrosDeVentas(PDEPURACION lintSocketClienteAD, pintNRegistros, 7, pstcLtaVentasPtrDat, &lstcErrorReg);
 RNDllEjecutaReplicacionAltaVentas(pstcLtaVentasPtrDat,lchrArrEncabezado1,pintNRegistros);
}
void RNDllEjecutaReplicacionAltaVentas(STRUCTLtaVentas *pstcLtaVentasPtrDat,char *pchrPtrEncabezado,int pintNRegistros)
{
	StcServidoresRep *lstcServidoresRepPtrInfo;
	void *lvidPtrMemoria;
	int lintSocketADSvrRep;
	int lintI;
	int lintTamEncabezado;
	STRUCTError lstcErrorReg;
	if(SISCOMObtenSHMSvrReplicacion(&lvidPtrMemoria))
	{
		lstcServidoresRepPtrInfo=(StcServidoresRep *)(lvidPtrMemoria+15*sizeof(STRUCTProcesosYDll));
		   for(lintI=1;lintI<=(lstcServidoresRepPtrInfo+0)->intPuertoAD;lintI++)
	           {
		      SISCOMConectateServidor(PDEPURACION (lstcServidoresRepPtrInfo+lintI)->intPuertoAD, (lstcServidoresRepPtrInfo+lintI)->chrArrDirIPAD, &lintSocketADSvrRep, &lstcErrorReg);	   			
		      lintTamEncabezado = atoi(pchrPtrEncabezado);
		      Write(lintSocketADSvrRep, pchrPtrEncabezado, strlen(pchrPtrEncabezado));
		      RNADEnviaRegistrosDeVentas(PDEPURACION lintSocketADSvrRep, pintNRegistros, 7, pstcLtaVentasPtrDat, &lstcErrorReg);
		   }
	}
}
