#include <stdio.h>
#include <ADDllRealizaAltaDeProductos.h>
#include <dlfcn.h>

int ADDllRealizaAltaVentas(PARDEPURACION int pintSocketCliente,int pintTuberia[],int pintPuerto,char *pchrPtrDirIP)
{
	ADDllRealizaAltaVentasEZS(PDEPURACION pintSocketCliente,pintTuberia,pintPuerto,pchrPtrDirIP);

}
int ADDllRealizaAltaCompras(PARDEPURACION int pintSocketCliente,int pintTuberia[],int pintPuerto,char *pchrPtrDirIP)
{
STRUCTError lstcErrorReg;
int lintNRegistros;
STRUCTLtaCompras *lstcLtaComprasPtrPrim=NULL,*lstcLtaComprasPtrPrimError=NULL;
int (*POSTGRESQLInsertaCompras)(PARDEPURACION STRUCTDatosDeLaOperacion ,STRUCTLtaCompras *,STRUCTLtaCompras **,int *);
void *lvidDll;
int lintNRechazados;
char a='*';
STRUCTDatosDeLaOperacion lstcDatosDeLaOperacionReg;	
#ifdef DEBUG
        //strcat(PDEPURACION "\t");
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","ADDllRealizaAltaDeProductos");
#endif
	 if(!(lvidDll=dlopen("libADDllInsercionesPostgreSQL.so",RTLD_LAZY)))
	  printf("%s\n",dlerror());
	 else
	 POSTGRESQLInsertaCompras=(int (*)(PARDEPURACION STRUCTDatosDeLaOperacion,STRUCTLtaCompras *,STRUCTLtaCompras **,int *))dlsym(lvidDll,"POSTGRESQLInsertaCompras");
	 if(!POSTGRESQLInsertaCompras)
	 printf("%s\n",dlerror());
	RNADGeneraListaCompras(PDEPURACION pintSocketCliente,&lintNRegistros,&lstcLtaComprasPtrPrim,&lstcErrorReg);
	POSTGRESQLInsertaCompras(PDEPURACION lstcDatosDeLaOperacionReg,lstcLtaComprasPtrPrim,&lstcLtaComprasPtrPrimError,&lintNRechazados);
	printf("\nafaffddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd   %d %x\n",lintNRegistros,lstcLtaComprasPtrPrimError);
	if(lstcLtaComprasPtrPrimError)
        RNADEnviaRegistrosDeCompras(PDEPURACION pintSocketCliente,lintNRechazados,10,lstcLtaComprasPtrPrimError,&lstcErrorReg);
	else
	{
	 printf("Enviando registro vacio\n");	
	 RNADRegistroVacioCompras(PDEPURACION pintSocketCliente);	
	}
	
}
int ADDllRealizaAltaDeProductos(PARDEPURACION int pintSocketCliente,int pintTuberia[],int pintPuerto,char *pchrPtrDirIp)
{
char a='*';	
int lintNRegistros;
STRUCTLtaProductos *lstcLtaProductosPtrReg;
STRUCTError lstcErrorReg;
STRUCTDatosDeLaOperacion lstcDatosDeLaOperacionReg;
STRUCTLtaErrorAltaProductos *lstcLtaErrorAltProductosReg;
#ifdef DEBUG
        strcpy(PDEPURACION "\n");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","ADDllRealizaAltaDeProductos");
#endif
		
RNADObtenDatosAltaProducto(PDEPURACION pintSocketCliente,&lintNRegistros,&lstcLtaProductosPtrReg,&lstcErrorReg);
//RNADLeeDatosDeLaOperacion(PDEPURACION pintTuberia[0],&lstcDatosDeLaOperacionReg,&lstcErrorReg);
ADDllInsertaDatos(PDEPURACION lstcDatosDeLaOperacionReg,lstcLtaProductosPtrReg,&lstcLtaErrorAltProductosReg);
Write(pintSocketCliente,&a,1);
}
int ADDllInsertaDatos(PARDEPURACION STRUCTDatosDeLaOperacion pstcDatosDeLaOperacionPtrReg,STRUCTLtaProductos *pstcLtaProductosPtrReg,STRUCTLtaErrorAltaProductos **pstcLtaErrorAltProductosPtrReg)
{
	
	int (*InsertaProductos)(PARDEPURACION STRUCTDatosDeLaOperacion,STRUCTLtaProductos*,STRUCTLtaErrorAltaProductos **);
	void *lvidDll;
#ifdef DEBUG
	        strcpy(PDEPURACION "\n");
		SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","ADDllInsertaDatos");
#endif
			
	if(!(lvidDll=dlopen("libADDllInsercionesPostgreSQL.so",RTLD_LAZY)))
	printf("%s\n",dlerror());
	else
	InsertaProductos=(int (*)(PARDEPURACION STRUCTDatosDeLaOperacion,STRUCTLtaProductos*,STRUCTError *))dlsym(lvidDll,"POSTGRESQLInsertaProductos");
	if(!InsertaProductos)
	printf("%s\n",dlerror());
	InsertaProductos(PDEPURACION pstcDatosDeLaOperacionPtrReg,pstcLtaProductosPtrReg,pstcLtaErrorAltProductosPtrReg);
}
