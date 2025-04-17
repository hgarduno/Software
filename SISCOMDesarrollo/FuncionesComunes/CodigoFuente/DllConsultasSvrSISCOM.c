#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <DllConsultasSvrSISCOM.h>
int gintSocketSvr;
int gintNRegistros=0;
int gintI=0;
int DllCLIConectateSVR(PARDEPURACION int pintPto,char *pchrPtrDirIP,char *pchrPtrUsuario,char *pchrPtrPassword,int pintMovimiento)
{
STRUCTDatosDeLaOperacion lstcOperacion;
#ifdef DEBUG
           //    strcat(pchrPtrTabulador,"\t");
         SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%0INint%0inchar*%0inchar*%0inchar*%0inint%","DllCLIConectateSVR",pintPto,pchrPtrDirIP,pchrPtrUsuario,pchrPtrPassword,pintMovimiento);
#endif
   SISCOMConectateServidor(PDEPURACION pintPto,pchrPtrDirIP,&gintSocketSvr,NULL);
   sprintf(lstcOperacion.chrArrMovimiento,"%d",pintMovimiento);
   strcpy(lstcOperacion.chrArrUsuario,pchrPtrUsuario);
   strcpy(lstcOperacion.chrArrPassword,pchrPtrPassword);
   strcpy(lstcOperacion.chrArrNomDll,"libRNDllConsultas.so");
   strcpy(lstcOperacion.chrArrNomFuncion,"RNDllCNSIdentificaConsulta");
   RNADFormaProtocoloEncabezado(PDEPURACION gintSocketSvr,lstcOperacion,NULL);
                                                                   


}

int DllCLIRealizaConsulta(PARDEPURACION char *pchrPtrCadenaConsulta)
{
	
	char lchrArrCadenaConsulta[256];
	char lchrCaracter;
	char ***lchrPtrConsulta;
	int i;
	 fd_set rfds;
	 struct timeval tv;
	int valret;
	STRUCTError lstcErrorReg;
#ifdef DEBUG
	           //    strcat(pchrPtrTabulador,"\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%char*%","DllCLIRealizaConsulta",pchrPtrCadenaConsulta);
#endif
		gintI=gintNRegistros=0;
                sprintf(lchrArrCadenaConsulta,"%04d%04d%04d%04d%04d%s",1,1,1,1,(int )strlen(pchrPtrCadenaConsulta),pchrPtrCadenaConsulta);
	        Write(gintSocketSvr,lchrArrCadenaConsulta,strlen(lchrArrCadenaConsulta));	
	        for(i=0;i<8;i++)
		Read(gintSocketSvr,lchrArrCadenaConsulta+i,1);
		lchrArrCadenaConsulta[4]=0;
		gintNRegistros=atoi(lchrArrCadenaConsulta);
		printf("\nLos registros en el cliente %d",gintNRegistros);
}
int DllCLIObtenDatosDelProducto(PARDEPURACION char *pchrPtrCveProducto,char *pchrPtrCveProveedor,char *pchrPtrDescripcion,char *pchrPtrFamilia,char *pchrPtrCantidad)
{
STRUCTProductos lstcProductosReg;
STRUCTError lstcErrorReg;
#ifdef DEBUG
	           //    strcat(pchrPtrTabulador,"\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","DllCLIObtenDatosDelProducto");
#endif
RNADObtenDatosDelProducto(PDEPURACION gintSocketSvr,&lstcProductosReg,&lstcErrorReg);
strcpy(pchrPtrCveProducto,lstcProductosReg.chrArrClaveProd);
strcpy(pchrPtrCveProveedor,lstcProductosReg.chrArrClaveProv);
strcpy(pchrPtrFamilia,lstcProductosReg.chrArrNomDelProducto);
strcpy(pchrPtrDescripcion,lstcProductosReg.chrArrDescProd);
strcpy(pchrPtrCantidad,lstcProductosReg.chrArrCantidad);
gintI++;
}	
int DllCLIObtenRegistrosDeCotizacion(PARDEPURACION char *pchrPtrCveProducto,char *pchrPtrCantidad,char *pchrPtrCostoUnitario,char *pchrPtrCostoTotal,char *pchrPtrImporteTotal,char *pchrPtrPMayoreo,char *pchrPtrExistencia)
{
STRUCTCotizacion lstcCotizacionReg;	
STRUCTError lstcErrorReg;
#ifdef DEBUG
	           //    strcat(pchrPtrTabulador,"\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","DllCLIObtenRegistrosDeCotizacion");
#endif
RNADObtenRegistroCotizacion(PDEPURACION gintSocketSvr,&lstcCotizacionReg,&lstcErrorReg);
strcpy(pchrPtrCveProducto,lstcCotizacionReg.chrArrCveProducto);
strcpy(pchrPtrCantidad,lstcCotizacionReg.chrArrCantidad);
strcpy(pchrPtrCostoUnitario,lstcCotizacionReg.chrArrCostoUnitario);
strcpy(pchrPtrCostoTotal,lstcCotizacionReg.chrArrCostoTotal);
strcpy(pchrPtrImporteTotal,lstcCotizacionReg.chrArrImporteTotal);
strcpy(pchrPtrPMayoreo,lstcCotizacionReg.chrArrPMayoreo);
strcpy(pchrPtrExistencia,lstcCotizacionReg.chrArrExistencia);
printf("\nRegistro De Cotizacion%s %s %s %s %s ",lstcCotizacionReg.chrArrCveProducto,lstcCotizacionReg.chrArrImporteTotal,lstcCotizacionReg.chrArrPMayoreo,lstcCotizacionReg.chrArrCostoTotal,lstcCotizacionReg.chrArrCantidad);	
gintI++;
}
int DllCLIObtenRegistroDeClientes(PARDEPURACION char *pchrPtrCveCliente,char *pchrPtrNmbCliente,char *pchrPtrDireccionCliente)
{
STRUCTCliente lstcClienteReg;	
printf("Enviando los dato al cliente\n\n");
#ifdef DEBUG
	  //    strcat(pchrPtrTabulador,"\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","DllCLIObtenRegistrosDeCotizacion");
#endif
            RNADObtenRegistroCliente(PDEPURACION gintSocketSvr,&lstcClienteReg);
	    strcpy(pchrPtrCveCliente,lstcClienteReg.chrArrCveCliente);
	    strcpy(pchrPtrNmbCliente,lstcClienteReg.chrArrNmbCliente);
	    strcpy(pchrPtrDireccionCliente,lstcClienteReg.chrArrDirCliente);
	    gintI++;

}
int DllCLIEsElUltimoRegistro(PARDEPURACION int pintPar)
{

#ifdef DEBUG
	           //    strcat(pchrPtrTabulador,"\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","DllCLIEsElUltimoRegistro");
#endif
	return gintI<gintNRegistros ? 1 :0;
}
int DllCLIObtenRegistroCompras(PARDEPURACION char *pchrPtrFechaCompra,char *pchrPtrCveProducto,char *pchrPtrCveVendedor,char *pchrPtrCveProveedor,char *pchrPtrPVenta,char *pchrPtrPCompra,char *pchrPtrCantidad,char *pchrPtrFormaDePago,char *pchrPtrPMayoreo)
{
STRUCTCompras lstcComprasReg;
STRUCTError lstcErrorReg;

#ifdef DEBUG
	           //    strcat(pchrPtrTabulador,"\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","DllCLIObtenRegistroCompras");
#endif
	RNADObtenRegistroDeCompras(PDEPURACION gintSocketSvr,&lstcComprasReg,&lstcErrorReg);
	strcpy(pchrPtrFechaCompra,lstcComprasReg.chrArrFechaCompra);
	strcpy(pchrPtrCveProducto,lstcComprasReg.chrArrCveProducto);
	strcpy(pchrPtrCveVendedor,lstcComprasReg.chrArrCveVendedor);
	strcpy(pchrPtrCveProveedor,lstcComprasReg.chrArrCveProveedor);
	strcpy(pchrPtrPVenta,lstcComprasReg.chrArrPVenta);
	strcpy(pchrPtrPCompra,lstcComprasReg.chrArrPCompra);
	strcpy(pchrPtrCantidad,lstcComprasReg.chrArrCantidad);
        strcpy(pchrPtrFormaDePago,lstcComprasReg.chrArrFormaDePago);
	strcpy(pchrPtrPMayoreo,lstcComprasReg.chrArrPMayoreo);
gintI++;
}
int DllCLIObtenRegistroEstGananciaNDisp(PARDEPURACION char *pchrPtrCveProducto,char *pchrPtrNoDispositivos,char *pchrPtrGanancia)
{
STRUCTEstGananciaNDisp lstcEstGananciaNDispReg;
STRUCTError lstcErrorReg;

#ifdef DEBUG
                   //    strcat(pchrPtrTabulador,"\t");
            SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","DllCLIObtenRegistroEstGananciaNDisp");
#endif
	    RNADObtenRegistroLtaEstGananciaNDisp(PDEPURACION gintSocketSvr,&lstcEstGananciaNDispReg);
	    strcpy(pchrPtrCveProducto,lstcEstGananciaNDispReg.chrArrCveProducto);
	    strcpy(pchrPtrNoDispositivos,lstcEstGananciaNDispReg.chrArrNoDispositivos);
	    strcpy(pchrPtrGanancia,lstcEstGananciaNDispReg.chrArrGanancia);
gintI++;	    
}
