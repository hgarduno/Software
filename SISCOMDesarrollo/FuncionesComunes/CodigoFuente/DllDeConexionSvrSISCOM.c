#include <stdio.h>
#include <DllDeConexionSvrSISCOM.h>
STRUCTLtaProductos *gstcLtaProductosListaPrim=NULL,*gstcLtaProductosListaDat=NULL;
int gintSocketSvr;
int lintNRegistros=0;


int CLIConectateSvrSISCOM(PARDEPURACION int pintPto,char *pchrPtrDirIP,char *pchrPtrUsuario,char *pchrPtrPassword,int pintMovimiento)
{
STRUCTDatosDeLaOperacion lstcOperacion;
#ifdef DEBUG
           //    strcat(pchrPtrTabulador,"\t");
         SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","CLIConectateSvrSISCOM");
#endif 
	SISCOMConectateServidor(PDEPURACION pintPto,pchrPtrDirIP,&gintSocketSvr,NULL);
	sprintf(lstcOperacion.chrArrMovimiento,"%d",pintMovimiento);
	strcpy(lstcOperacion.chrArrUsuario,pchrPtrUsuario);
	strcpy(lstcOperacion.chrArrPassword,pchrPtrPassword);
	strcpy(lstcOperacion.chrArrNomDll,"libRNDllAltaProductos.so");
	strcpy(lstcOperacion.chrArrNomFuncion,"RNDLLRealizaAltaProductos");	
	RNADFormaProtocoloEncabezado(PDEPURACION gintSocketSvr,lstcOperacion,NULL);

}
int CLIEnviaDatosAltaSVR()
{
char lchrArrCadena[1000];
#ifdef DEBUG
char pchrPtrTabulador[100];
#endif 
//RNADFormaCadenaAltaProductos(PDEPURACION  gstcLtaProductosListaPrim,lintNRegistros,lchrArrCadena,NULL);
//Write(gintSocketSvr,lchrArrCadena,strlen(lchrArrCadena));
RNADEnviaDatosDelProducto(PDEPURACION gintSocketSvr,lintNRegistros,5,gstcLtaProductosListaPrim,NULL);
}
int CLIIntroduceDatosProductos(PARDEPURACION char *pchrPtrCvePrd,char *pchrPtrCvePrv,char *pchrPtrDscCta,char *pchrPtrFamilia)
{
STRUCTProductos lstcProductosReg;	
#ifdef DEBUG
           //    strcat(pchrPtrTabulador,"\t");
                  SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%000char*%000char*%000char*%000char*%","CLIIntroduceDatosProductos",pchrPtrCvePrd,pchrPtrCvePrv,pchrPtrDscCta,pchrPtrFamilia);
#endif
RNADCopiaDatosDelProducto(PDEPURACION pchrPtrCvePrd,pchrPtrDscCta,pchrPtrCvePrv,pchrPtrFamilia,&lstcProductosReg);
	if(!gstcLtaProductosListaPrim)
	{
	 RNADAsignaMemoriaLtaProducto(PDEPURACION &gstcLtaProductosListaPrim,lstcProductosReg,NULL);
	 gstcLtaProductosListaDat=gstcLtaProductosListaPrim;
	}
	else
	{
	 RNADAsignaMemoriaLtaProducto(PDEPURACION &gstcLtaProductosListaDat->stcLtaProductosSig,lstcProductosReg,NULL);
	 gstcLtaProductosListaDat=gstcLtaProductosListaDat->stcLtaProductosSig;
	}
	lintNRegistros++;
}


