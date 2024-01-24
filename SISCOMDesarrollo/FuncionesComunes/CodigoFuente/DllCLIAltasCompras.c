#include <stdio.h>
#include <unistd.h>
#include <DllCLIAltasCompras.h>
int gintSocketCliente;
int gintNRegistros=0;
STRUCTLtaCompras *gstcLtaComprasPtrPrim=NULL,*gstcLtaComprasPtrDat=NULL;
int DllCLIConectateSvrSISCOMAltaCompras(PARDEPURACION int pintPto,char *pchrPtrDirIP,char *pchrPtrUsuario,char *pchrPtrPassword,int pintMovimiento)
{
STRUCTDatosDeLaOperacion lstcOperacion;
#ifdef DEBUG
	           //    strcat(pchrPtrTabulador,"\t");
             SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","DllCLIConectateSvrSISCOMAltaCompras");
#endif
        SISCOMConectateServidor(PDEPURACION pintPto,pchrPtrDirIP,&gintSocketCliente,NULL);
        sprintf(lstcOperacion.chrArrMovimiento,"%d",pintMovimiento);
        strcpy(lstcOperacion.chrArrUsuario,pchrPtrUsuario);
        strcpy(lstcOperacion.chrArrPassword,pchrPtrPassword);
        strcpy(lstcOperacion.chrArrNomDll,"libRNDllAltaCompras.so");
        strcpy(lstcOperacion.chrArrNomFuncion,"RNDllRealizaAltaCompras");
        RNADFormaProtocoloEncabezado(PDEPURACION gintSocketCliente,lstcOperacion,NULL);
}
int DllCLIAnexaDatosDeCompra(PARDEPURACION char *pchrPtrCveProducto,char *pchrPtrCveProveedor,char *pchrPtrPVenta,char *pchrPtrPCompra,
		                     char *pchrPtrCveVendedor,char *pchrPtrCantidad,char *pchrPtrFechaCompra,char *pchrPtrFormaDePago,char *pchrPtrPMayoreo)
{
STRUCTCompras lstcComprasDat;	
STRUCTError lstcErrorReg;
#ifdef DEBUG
	           //    strcat(pchrPtrTabulador,"\t");
             SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%000char*%000char*%000char*%000char*%000char*%000char*%000char*%000char*%","DllCLIAnexaDatosDeCompra",pchrPtrCveProducto,pchrPtrCveProveedor,pchrPtrPVenta,pchrPtrPCompra,pchrPtrCveVendedor,pchrPtrCantidad,pchrPtrFechaCompra,pchrPtrFormaDePago);
#endif
	 RNADLlenaCompras(PDEPURACION pchrPtrCveProducto,pchrPtrCveProveedor,pchrPtrPVenta,pchrPtrPCompra,pchrPtrCveVendedor,pchrPtrCantidad,pchrPtrFechaCompra,pchrPtrFormaDePago,pchrPtrPMayoreo,"",&lstcComprasDat);
	RNADCreaListaDeCompras(PDEPURACION lstcComprasDat,&gstcLtaComprasPtrPrim,&gstcLtaComprasPtrDat,&lstcErrorReg);	
gintNRegistros++;	 
}
int DllCLIEnviaDatosDeCompraSvr(PARDEPURACION int pintAlgo)
{
STRUCTError lstcErrorReg;
#ifdef DEBUG
	           //    strcat(pchrPtrTabulador,"\t");
             SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","DllCLIEnviaDatosDeCompraSvr");
#endif
	     

	 RNADEnviaRegistrosDeCompras(PDEPURACION gintSocketCliente,gintNRegistros,8,gstcLtaComprasPtrPrim,&lstcErrorReg);
	 RNADGeneraListaCompras(PDEPURACION gintSocketCliente,&gintNRegistros,&gstcLtaComprasPtrPrim,&lstcErrorReg);
	 close(gintSocketCliente);
}
