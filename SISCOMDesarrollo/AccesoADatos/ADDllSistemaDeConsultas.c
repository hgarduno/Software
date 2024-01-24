#include <ADDllSistemaDeConsultas.h>
#include <ADDllSistemaDeConsultasHGE.h>
#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
static char *gchrPtrConsultas[]={
                                  "Compras",
				  "FechasCompras*", 
				  "Productos",
				  "Productos*",	  
				  "ComprasXProducto",
				  "Clientes*",
				  "EstadisticasGanNDisp*"
				  
                                 };  	  
#define NCONSULTAS 7			  	  	  
int ADDllCNSIdentificaConsulta(PARDEPURACION int pintSocketCliente,int pintTuberia[],int pintPuerto,char *pchrPtrDirIp)
{
STRUCTError lstcErrorReg;
char ***lchrPtrCadenaRegreso;
char lchrArrCadenaConsulta[1000]="";
char lchrArrCadenaConsulta1[1000];
int lintNRegistros,lintNColumnas;
int i;
#ifdef DEBUG
        strcat(PDEPURACION "\t");
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","ADDllCNSIdentificaConsulta");
#endif
	SISCOMObtenInformacionDelProtocolo(PDEPURACION pintSocketCliente,&lintNRegistros,&lintNColumnas,&lchrPtrCadenaRegreso,&lstcErrorReg);
	printf("\n\nLa consulta %s\n",lchrPtrCadenaRegreso[0][0]);
	for(i=0;i<NCONSULTAS;i++)
	if(!strcmp(lchrPtrCadenaRegreso[0][0],gchrPtrConsultas[i]))
	switch(i)
	{
		case 0:
			  ADDllCNSFormaCadenaConsultaCompras(PDEPURACION lchrPtrCadenaRegreso[0][1],lchrArrCadenaConsulta);
                          ADDllCNSCompras(PDEPURACION pintSocketCliente,lchrArrCadenaConsulta,&lstcErrorReg);
		break;
		case 1:
                          ADDllCNSCompras(PDEPURACION pintSocketCliente," order by dtefechacompra",&lstcErrorReg);
		break;
		case 2:
	                   ADDllCNSFormaCadenaConsulta(PDEPURACION lintNColumnas,lchrPtrCadenaRegreso[0],lchrArrCadenaConsulta);
	                   ADDllCNSProductos(PDEPURACION pintSocketCliente,lchrArrCadenaConsulta,&lstcErrorReg);
		break;
		case 3:
	                  lchrArrCadenaConsulta[0]=' ';
	                  ADDllCNSProductos(PDEPURACION pintSocketCliente,lchrArrCadenaConsulta,&lstcErrorReg);
		break;		
		case 4:
			  ADDllCNSFormaCadenaCotizacion(PDEPURACION lintNColumnas,lchrPtrCadenaRegreso[0],lchrArrCadenaConsulta);
                          ADDllCNSCompras(PDEPURACION pintSocketCliente,lchrArrCadenaConsulta,&lstcErrorReg);
		break;
		case 5:
		 	printf("Si se llama =======================\n");
			ADDllCNSClientes(PDEPURACION pintSocketCliente,"");
		break;
		case 6:
			ADDllCNSEstGananciasNDisp(PDEPURACION pintSocketCliente,"");
		break;
	}	

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
char lchrArrFechaHoy[15],lchrArrFechaMesAnterior[15];
RNADFechasDelPrecio(PDEPURACION lchrArrFechaHoy,lchrArrFechaMesAnterior);
sprintf(pchrPtrSalida,"where a.chrCveProducto = b.chrCveProducto and (a.dteFechaCompra>='%s' and a.dteFechaCompra<='%s') and (  ",lchrArrFechaMesAnterior,lchrArrFechaHoy);
for(lintI=1;lintI<pintNProductos;lintI++)
{
	sprintf(lchrArrCadena," a.chrCveProducto = '%s' or",pchrPtrEntrada[lintI]);
	strcat(pchrPtrSalida,lchrArrCadena);
	
}
	
lintPos=strlen(pchrPtrSalida);
strcpy(pchrPtrSalida+lintPos -2 ,") ");
strcat(pchrPtrSalida,"order by a.chrCveProducto");

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
	for(lintI=1;lintI<pintNProductos;lintI++)
	{
	   	
	   sprintf(lchrArrProducto," b.chrCveProducto='%s' or",pchrPtrProductos[lintI]);
   	   strcat(pchrPtrRegreso,lchrArrProducto);	   
	   
	  
	}	
	
lintPos=strlen(pchrPtrRegreso);
strcpy(pchrPtrRegreso+lintPos-2,")");
}
int ADDllCNSProductos(PARDEPURACION int pintSocketCliente,char *pchrPtrConsulta,STRUCTError *pstcErrorPtrReg)
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
	ADDllConsultasPostgreSQL(PDEPURACION lstcDatosDeLaOperacionDat,pchrPtrConsulta,&lstcLtaProductosReg,&lintNRegistros,&lintNColumnas,pstcErrorPtrReg);
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
int ADDllCNSCompras(PARDEPURACION int pintSocketCliente,char *pchrPtrCadenaConsulta,STRUCTError *pstcErrorPtrReg)
{
    STRUCTLtaCompras *lstcLtaComprasPtrPrim=NULL;	
    STRUCTDatosDeLaOperacion lstcDatosDeLaOperacionDat;
    int lintTamano;
    int lintNRegistros,lintNColumnas;
    char lchrArrCadena[255];
    char lchrFin='*';
    int (*ADDllConsultaComprasPostgreSQL)(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTLtaCompras **,int *,int *,STRUCTError *);
    void *lvidRegresoDll;
#ifdef DEBUG
    strcat(PDEPURACION "\t");
   SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","ADDllCNSCompras");
#endif
     if(!(lvidRegresoDll=dlopen("libADDllConsultasPostgreSQL.so",RTLD_LAZY)))
      printf("\n%s ",dlerror());
       ADDllConsultaComprasPostgreSQL=(int (*)(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTLtaCompras **,int *,int *,STRUCTError *))dlsym(lvidRegresoDll,"ADDllConsultaComprasPostgreSQL");
    if(!ADDllConsultaComprasPostgreSQL)
      printf("\n%s\n",dlerror());
    ADDllConsultaComprasPostgreSQL(PDEPURACION lstcDatosDeLaOperacionDat,pchrPtrCadenaConsulta,&lstcLtaComprasPtrPrim,&lintNRegistros,&lintNColumnas,pstcErrorPtrReg);
    RNADEnviaRegistrosDeCompras(PDEPURACION pintSocketCliente,lintNRegistros,10,lstcLtaComprasPtrPrim,pstcErrorPtrReg);
    Write(pintSocketCliente,&lchrFin,1);
	dlclose(lvidRegresoDll);	
//close(pintSocketCliente);    	
}
