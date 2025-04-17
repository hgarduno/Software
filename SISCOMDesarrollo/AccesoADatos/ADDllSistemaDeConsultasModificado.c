#include <ADDllSistemaDeConsultasModificado.h>
#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
#include <string.h>
int ADDllCNSClientes(PARDEPURACION int pintSocketCliente,char ***pchrPtrConsulta,STRUCTError *pstcErrorPtrReg)
{
STRUCTLtaCliente *lstcLtaClienteReg=NULL;
STRUCTDatosDeLaOperacion lstcDatosDeLaOperacionDat;
int lintTamano;
int lintNRegistros,lintNColumnas;
char lchrArrCadena[255];
char lchrFin='*';
int (*ADDllConsultaClientesPostgreSQL)(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTLtaCliente **,int *,int *,STRUCTError *);
void *lvidRegresoDll;	
#ifdef DEBUG
	strcat(PDEPURACION "\t");
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","ADDllCNSClientes");
#endif
if(!(lvidRegresoDll=dlopen("libADDllConsultasPostgreSQL.so",RTLD_LAZY)))
printf("\n%s ",dlerror());
ADDllConsultaClientesPostgreSQL=(int (*)(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTLtaCliente **,int *,int *,STRUCTError *))dlsym(lvidRegresoDll,"ADDllConsultaClientesPostgreSQL");
if(!ADDllConsultaClientesPostgreSQL)
printf("\n%s\n",dlerror());
ADDllConsultaClientesPostgreSQL(PDEPURACION lstcDatosDeLaOperacionDat,pchrPtrConsulta[0][2],&lstcLtaClienteReg,&lintNRegistros,&lintNColumnas,0);
RNADEnviaClientes(PDEPURACION pintSocketCliente,lintNRegistros,lintNColumnas,lstcLtaClienteReg);
dlclose(lvidRegresoDll);
//close(pintSocketCliente);
}
int ADDllCNSEstGananciasNDisp(PARDEPURACION int pintSocketCliente,char ***pchrPtrConsulta,STRUCTError *pstcErrorPtrReg)
{
STRUCTLtaEstGananciaNDisp *lstcLtaEstGananciaNDispPtrUlt=NULL;	
STRUCTDatosDeLaOperacion lstcDatosDeLaOperacionDat;
int lintTamano;
int lintNRegistros,lintNColumnas;
char lchrArrCadena[255];
char lchrFin='*';
int (*ADDllConsultaEstGananciaNDispositivosPostgreSQL)(PARDEPURACION STRUCTDatosDeLaOperacion ,char *,STRUCTLtaEstGananciaNDisp **,int *,int *,STRUCTError *);
void *lvidRegresoDll;
#ifdef DEBUG
        strcat(PDEPURACION "\t");
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","ADDllCNSEstGananciasNDisp");
#endif
if(!(lvidRegresoDll=dlopen("libADDllConsultasPostgreSQL.so",RTLD_LAZY)))
printf("\n%s ",dlerror());
ADDllConsultaEstGananciaNDispositivosPostgreSQL=(int (*)(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTLtaEstGananciaNDisp **,int *,int *,STRUCTError *))dlsym(lvidRegresoDll,"ADDllConsultaEstGananciaNDispositivosPostgreSQL");
if(!ADDllConsultaEstGananciaNDispositivosPostgreSQL)
printf("\n%s\n",dlerror());
ADDllConsultaEstGananciaNDispositivosPostgreSQL(PDEPURACION lstcDatosDeLaOperacionDat,pchrPtrConsulta[0][2],&lstcLtaEstGananciaNDispPtrUlt,&lintNRegistros,&lintNColumnas,0);
RNADEnviaLtaEstGananciaNDisp(PDEPURACION pintSocketCliente,lintNRegistros,lintNColumnas,lstcLtaEstGananciaNDispPtrUlt);
dlclose(lvidRegresoDll);
close(pintSocketCliente);
}
int ADDllCNSFormaCadenaConsultaCompras(PARDEPURACION char *pchrPtrFecha,char *pchrPtrCadenaConsulta)
{
	sprintf(pchrPtrCadenaConsulta,"where a.chrCveProducto=b.chrCveProducto and dteFechaCompra='%s' order by a.dteFechaCompra",pchrPtrFecha);

#ifdef DEBUG
        strcat(PDEPURACION "\t");
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%000char*%","ADDllCNSFormaCadenaConsultaCompras",pchrPtrCadenaConsulta);
#endif
}
int ADDllCNSFormaCadenaCotizacion(PARDEPURACION int pintNProductos,char **pchrPtrEntrada,char *pchrPtrSalida)
{
int lintI,lintPos=0;
char lchrArrCadena[500];
strcpy(pchrPtrSalida,"where a.chrCveProducto = b.chrCveProducto  and (  ");
for(lintI=0;pchrPtrEntrada[lintI];lintI++)
	printf("--%s--\n",pchrPtrEntrada[lintI]);
memset(lchrArrCadena,500,0);
for(lintI=3;pchrPtrEntrada[lintI];lintI++)
{
	sprintf(lchrArrCadena," a.chrCveProducto = '%s' or",pchrPtrEntrada[lintI]);
	strcat(pchrPtrSalida,lchrArrCadena);
	printf("%s\n",pchrPtrSalida);
	
}
printf("Salio del ciclo\n");	
lintPos=strlen(pchrPtrSalida);
strcpy(pchrPtrSalida+lintPos -2 ,") order by a.chrCveProducto");
printf("****((((((((((((( %s\n",pchrPtrSalida);

#ifdef DEBUG
        strcat(PDEPURACION "\t");
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%000char*%","ADDllCNSFormaCadenaCotizacion",pchrPtrSalida);
#endif
}
int ADDllCNSFormaCadenaConsulta(PARDEPURACION int pintNProductos,char **pchrPtrProductos,char *pchrPtrRegreso)
{
int lintI;
int lintPos=0;
char lchrArrProducto[100];
sprintf(pchrPtrRegreso,"%s","and (");
	for(lintI=1;pchrPtrProductos[lintI];lintI++)
	{
	   	
	   sprintf(lchrArrProducto," b.chrCveProducto='%s' or",pchrPtrProductos[lintI]);
   	   strcat(pchrPtrRegreso,lchrArrProducto);	   
	   
	  
	}	
	
lintPos=strlen(pchrPtrRegreso);
strcpy(pchrPtrRegreso+lintPos-2,")");
}
int ADDllCNSProductos(PARDEPURACION int pintSocketCliente,char ***pchrPtrConsulta,STRUCTError *pstcErrorPtrReg)
{
	STRUCTLtaProductos *lstcLtaProductosReg;
	STRUCTDatosDeLaOperacion lstcDatosDeLaOperacionDat;
	int lintTamano;
	int lintNRegistros,lintNColumnas;
	char lchrArrCadena[255];
	char lchrFin='*';
	int (*ADDllConsultasPostgreSQL)(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTLtaProductos **,int *,int *,STRUCTError *);
	void *lvidRegresoDll;
#ifdef DEBUG
       strcat(PDEPURACION "\t");
       SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","ADDllCNSProductos");
#endif
	if(!(lvidRegresoDll=dlopen("libADDllConsultasPostgreSQL.so",RTLD_LAZY)))
	printf("\n%s ",dlerror());
	ADDllConsultasPostgreSQL=(int (*)(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTLtaProductos **,int *,int *,STRUCTError *))dlsym(lvidRegresoDll,"ADDllConsultasPostgreSQL");
	if(!ADDllConsultasPostgreSQL)
	printf("\n%s\n",dlerror());
	ADDllConsultasPostgreSQL(PDEPURACION lstcDatosDeLaOperacionDat,pchrPtrConsulta[0][2],&lstcLtaProductosReg,&lintNRegistros,&lintNColumnas,pstcErrorPtrReg);
	sprintf(lchrArrCadena,"%04d%04d",lintNRegistros,lintNColumnas);
	lintTamano=strlen(lchrArrCadena);
	Write(pintSocketCliente,lchrArrCadena,lintTamano);
	while(lstcLtaProductosReg)
	{
	RNADFormaCadenaProtocoloXRegistroProducto(PDEPURACION lstcLtaProductosReg->stcProductosDat,lchrArrCadena,pstcErrorPtrReg);
	Write(pintSocketCliente,lchrArrCadena,strlen(lchrArrCadena));
	 lstcLtaProductosReg=lstcLtaProductosReg->stcLtaProductosSig;
	}
	dlclose(lvidRegresoDll);	
Write(pintSocketCliente,&lchrFin,1);
close(pintSocketCliente);	
}
int ADDllCNSCompras(PARDEPURACION int pintSocketCliente,char ***pchrPtrCadenaConsulta,STRUCTError *pstcErrorPtrReg)
{
    STRUCTLtaCompras *lstcLtaComprasPtrPrim=NULL;	
    STRUCTDatosDeLaOperacion lstcDatosDeLaOperacionDat;
    int lintTamano;
    int lintNRegistros,lintNColumnas;
    char lchrArrCadena[255];
    char lchrArrCadenaConsulta[8192];
    char lchrFin='*';
    int (*ADDllConsultaComprasPostgreSQL)(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTLtaCompras **,int *,int *,STRUCTError *);
    void *lvidRegresoDll;
#ifdef DEBUG
    strcat(PDEPURACION "\t");
   SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","ADDllCNSCompras");
#endif
   printf("\nIntentando cargar la dll del postgresql\n");
     if(!(lvidRegresoDll=dlopen("libADDllConsultasPostgreSQL.so",RTLD_LAZY)))
      printf("\n%s ",dlerror());
       ADDllConsultaComprasPostgreSQL=(int (*)(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTLtaCompras **,int *,int *,STRUCTError *))dlsym(lvidRegresoDll,"ADDllConsultaComprasPostgreSQL");
    if(!ADDllConsultaComprasPostgreSQL)
      printf("\n%s\n",dlerror());
/*    {
	    int lintI=0;
	    for(lintI=0;pchrPtrCadenaConsulta[0][lintI];lintI++)
	    printf("[%d] %s\n",lintI,pchrPtrCadenaConsulta[0][lintI]);
	    pchrPtrCadenaConsulta[0][lintI-1]=0;
    }*/
    
  printf("La cadena %s\n",pchrPtrCadenaConsulta[0][2]); 
  
    if(!strcmp("FechasCompras*",pchrPtrCadenaConsulta[0][2])) 
    {
	    strcpy(lchrArrCadenaConsulta," order by dtefechacompra");
	    printf("Formando la cadena de consulta %s\n",lchrArrCadenaConsulta);
    }
    else
    ADDllCNSFormaCadenaCotizacion(PDEPURACION 0,pchrPtrCadenaConsulta[0],lchrArrCadenaConsulta);
    ADDllConsultaComprasPostgreSQL(PDEPURACION lstcDatosDeLaOperacionDat,lchrArrCadenaConsulta,&lstcLtaComprasPtrPrim,&lintNRegistros,&lintNColumnas,pstcErrorPtrReg);
    RNADEnviaRegistrosDeCompras(PDEPURACION pintSocketCliente,lintNRegistros,10,lstcLtaComprasPtrPrim,pstcErrorPtrReg);
    Write(pintSocketCliente,&lchrFin,1);
	dlclose(lvidRegresoDll);	
//close(pintSocketCliente);    	
}
