#include <stdio.h>
#include <unistd.h>
#include <DllCLIAltasVentas.h>
#include <RNADFuncionesComunesEZS.h>

//Variables globales

int gintSocketCliente;
int gintNRegistros = 0;
STRUCTLtaVentas *gstcLtaVentasPtrPrim = NULL, *gstcLtaVentasPtrDat = NULL;

//Terminan variables globales

int DllCLIEliminaAnterior(PARDEPURACION int Algo)
{
	gstcLtaVentasPtrPrim=gstcLtaVentasPtrDat=NULL;

}
int DllCLIConectateSvrSISCOMAltaVentas(PARDEPURACION int pintPto, char *pchrPtrDirIP, char *pchrPtrUsuario, char *pchrPtrPassword, int pintMovimiento)
{
STRUCTDatosDeLaOperacion lstcOperacion;

#ifdef DEBUG
//    strcat(pchrPtrTabulador,"\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","DllCLIConectateSvrSISCOMAltaVentas");
#endif
        SISCOMConectateServidor(PDEPURACION pintPto, pchrPtrDirIP, &gintSocketCliente, NULL);
        sprintf(lstcOperacion.chrArrMovimiento, "%d", pintMovimiento);
        strcpy(lstcOperacion.chrArrUsuario, pchrPtrUsuario);
        strcpy(lstcOperacion.chrArrPassword, pchrPtrPassword);
        strcpy(lstcOperacion.chrArrNomDll, "libRNDllAltaVentas.so");
        strcpy(lstcOperacion.chrArrNomFuncion, "RNDllRealizaAltaVentas");
        RNADFormaProtocoloEncabezado(PDEPURACION gintSocketCliente, lstcOperacion, NULL);
}

int DllCLIAnexaDatosDeVenta(PARDEPURACION  char *pchrPtrFechaVenta, char *pchrPtrCveVenta, char *pchrPtrCveProducto, char *pchrPtrCantidad, char *pchrPtrCveCliente, char *pchrPtrPUnitario, char *pchrPtrPTotal,char *pchrPtrNOrden)
{
STRUCTVentas lstcVentasDat;
STRUCTError lstcErrorReg;

#ifdef DEBUG
//    strcat(pchrPtrTabulador,"\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%000char*%000char*%000char*%000char*%000char*%000char*%000char*%","DllCLIAnexaDatosDeVenta", pchrPtrFechaVenta, pchrPtrCveVenta, pchrPtrCveProducto, pchrPtrCantidad, pchrPtrCveCliente, pchrPtrPUnitario, pchrPtrPTotal);
#endif

 RNADLlenaVentas(PDEPURACION pchrPtrFechaVenta, pchrPtrCveVenta, pchrPtrCveProducto, pchrPtrCantidad, pchrPtrCveCliente, pchrPtrPUnitario, pchrPtrPTotal,pchrPtrNOrden, &lstcVentasDat);
 RNADCreaListaDeVentas(PDEPURACION lstcVentasDat, &gstcLtaVentasPtrPrim, &gstcLtaVentasPtrDat, &lstcErrorReg);
 gintNRegistros++;
}

int DllCLIEnviaDatosDeVentaSvr(PARDEPURACION int pintAlgo)
{
STRUCTError lstcErrorReg;
#ifdef DEBUG
//    strcat(pchrPtrTabulador,"\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","DllCLIEnviaDatosDeVentaSvr");
#endif

	 RNADEnviaRegistrosDeVentas(PDEPURACION gintSocketCliente, gintNRegistros, 7, gstcLtaVentasPtrPrim, &lstcErrorReg);
	 close(gintSocketCliente);
}
