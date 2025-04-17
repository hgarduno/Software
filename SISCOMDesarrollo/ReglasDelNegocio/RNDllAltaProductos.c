#include <stdio.h>
#include <RNADFuncionesComunes.h>
#include <RNDllAltaProductos.h>
void RNDllEjecutaReplicacionProductos(STRUCTLtaProductos *,int ,char *);
int RNDLLRealizaAltaProductos(PARDEPURACION int pintSocket,int pintTuberia[],int pintPuerto,char *pchrPtrDirIPSAD)
{
	int lintNRegistros;
	static char lchrArrCadena[1000],lchrArrCadenaProtocolo[1000];
	char lchrCadena[10];
	int lintSocketSAD;
	char a='*';
	STRUCTLtaProductos *lstcLtaProductosPtrReg=NULL;
	STRUCTError lstcErrorReg;
	printf("Alta Productos  \n\n");

	RNADObtenDatosAltaProducto(PDEPURACION pintSocket,&lintNRegistros,&lstcLtaProductosPtrReg,&lstcErrorReg);
//	RNADFormaCadenaAltaProductos(PDEPURACION lstcLtaProductosPtrReg,lintNRegistros,lchrArrCadena,&lstcErrorReg);
	RNDllUneEncabezadoYProductos(PDEPURACION pintTuberia[0],lchrArrCadena,lchrArrCadenaProtocolo,&lstcErrorReg);	
	RNDllEnviaDatosAlServidorAD(PDEPURACION pintPuerto,pchrPtrDirIPSAD,lstcLtaProductosPtrReg,lintNRegistros,lchrArrCadenaProtocolo,&lstcErrorReg);
	Write(pintSocket,&a,1);
}
int RNDllUneEncabezadoYProductos(PARDEPURACION int pintTuberia,char *pchrPtrCadProductos,char *pchrPtrRegreso,STRUCTError *pstcErrorPtrReg)
{
	static char lchrArrCadena[1000];
	char lchrArrTamano[6];
	int lintTamano;
	memset(lchrArrCadena,0,999);
	Read(pintTuberia,lchrArrTamano,5);
	lchrArrTamano[5]=0;
	lintTamano=atoi(lchrArrTamano);	
	Read(pintTuberia,lchrArrCadena,lintTamano);
	sprintf(pchrPtrRegreso,"%05d%s%s",lintTamano,lchrArrCadena,pchrPtrCadProductos);
}
int RNDllEnviaDatosAlServidorAD(PARDEPURACION int pintPuerto,char *pchrPtrDirIPSAD,STRUCTLtaProductos *pstcLtaProductosPtrDat,int pintNRegistros,char *pchrPtrEncabezado,STRUCTError *pstcErrorPtrReg)
{
	char a;
	int lintSocketClienteAD;
	SISCOMConectateServidor(PDEPURACION pintPuerto,pchrPtrDirIPSAD,&lintSocketClienteAD,pstcErrorPtrReg);	
	Write(lintSocketClienteAD,pchrPtrEncabezado,strlen(pchrPtrEncabezado));
	RNADEnviaDatosDelProducto(PDEPURACION lintSocketClienteAD,pintNRegistros,5,pstcLtaProductosPtrDat,NULL);
	Read(lintSocketClienteAD,&a,1);
	RNDllEjecutaReplicacionProductos(pstcLtaProductosPtrDat,pintNRegistros,pchrPtrEncabezado);
}
void RNDllEjecutaReplicacionProductos(STRUCTLtaProductos *pstcLtaProductosPtrDat,int pintNRegistros,char *pchrPtrEncabezado)
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
		      Write(lintSocketADSvrRep, pchrPtrEncabezado, strlen(pchrPtrEncabezado));
			RNADEnviaDatosDelProducto(PDEPURACION lintSocketADSvrRep,pintNRegistros,5,pstcLtaProductosPtrDat,NULL);
		   }
	}
}

