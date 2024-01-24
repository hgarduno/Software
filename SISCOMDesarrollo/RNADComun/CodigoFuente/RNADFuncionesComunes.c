#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sys/time.h>
#include <time.h>
#include <RNADFuncionesComunes.h>
#include <stdlib.h>
int RNADLeeDatosDeLaOperacion(PARDEPURACION int pintSocket,STRUCTDatosDeLaOperacion *pstcDatosDeLaOperacion,STRUCTError *pstcErrorPtrReg)
{
	int lintTamano;
	char lchrCadena[10];
	char ***lchrDatosProtocolo;
	int lintNRegistros,lintNColumnas;
	int i,j;
#ifdef DEBUG
        strcat(PDEPURACION "\t");
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADLeeDatosDeLaOperacion");
#endif	
	Read(pintSocket,lchrCadena,5);
	lchrCadena[5]=0;
	lintTamano=atoi(lchrCadena);
	Read(pintSocket,lchrCadena,9);
	lchrCadena[9]=0;
	SISCOMObtenInformacionDelProtocolo(PDEPURACION pintSocket,&lintNRegistros,&lintNColumnas,&lchrDatosProtocolo,pstcErrorPtrReg);
	strcpy(pstcDatosDeLaOperacion->chrArrMovimiento,lchrDatosProtocolo[0][0]);
	strcpy(pstcDatosDeLaOperacion->chrArrUsuario,lchrDatosProtocolo[0][1]);
	strcpy(pstcDatosDeLaOperacion->chrArrPassword,lchrDatosProtocolo[0][2]);
	strcpy(pstcDatosDeLaOperacion->chrArrNomDll,lchrDatosProtocolo[0][3]);
	strcpy(pstcDatosDeLaOperacion->chrArrNomFuncion,lchrDatosProtocolo[0][4]);
#ifdef DEBUG
        strcat(PDEPURACION "\t");
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%000STRUCTDatosDeLaOperacion%","",*pstcDatosDeLaOperacion);
#endif	
SISCOMLiberaCharPtr(PDEPURACION lintNRegistros,lintNColumnas,lchrDatosProtocolo);	
			
}
int RNADCargaDllYEjecutaFuncion(PARDEPURACION char *pchrPtrNomDll,char *pchrPtrFuncion,int pintSocket,int pintTuberia[],int pintPuertoSAD,char *pchrPtrDirIPSAD,STRUCTError *stcErrorPtrReg)
{
	        int (*SISCOMEjecutaMovimiento)(PARDEPURACION int ,int[],int,char *);
		void *Funcion;
		void *lvidDll;
		int lintRegreso;
		 if(!(lvidDll=dlopen(pchrPtrNomDll,RTLD_LAZY)))
		  printf("dlopen() *%s*\n*%s*\n",dlerror(),pchrPtrNomDll);
	         if(!(SISCOMEjecutaMovimiento=(int (*)(PARDEPURACION int,int [],int,char *))dlsym(lvidDll,pchrPtrFuncion)))
		 printf("dlsym *%s*\n*%s*\n",dlerror(),pchrPtrFuncion);
	         SISCOMEjecutaMovimiento(PDEPURACION pintSocket,pintTuberia,pintPuertoSAD,pchrPtrDirIPSAD);
		 lintRegreso=dlclose(lvidDll);
}
int RNADFormaCadenaConsultaYConsultaSVR(PARDEPURACION int pintPuertoAD,char *pchrPtrDirIPAD,char *pchrPtrUsuario,char *pchrPtrPassword,char *pchrPtrDllAD,char *pchrPtrNmbFuncion,char *pchrPtrConsulta,int *pintSocketAD)
{
char lchrArrEncabezado[1024];
char lchrArrCadenaEnvio[2048];
char lchrArrConsulta[1024];
int lintSocketAD;
	RNADFormaCadenaEncabezado(PDEPURACION pchrPtrUsuario,pchrPtrPassword,"libADDllSistemaDeConsultas.so","ADDllCNSIdentificaConsulta","1",lchrArrEncabezado);
	sprintf(lchrArrCadenaEnvio, "%04d%04d%04d%04d%04d%s%04d%04d%04d%s%04d%04d%04d%s", 
			      1,
			      3, 
			      1, 
			      1, 
			      strlen(pchrPtrDllAD), 
			      pchrPtrDllAD, 
			      2, 
			      1, 
			      strlen(pchrPtrNmbFuncion), 
			      pchrPtrNmbFuncion, 
			      3, 
			      1, 
			      strlen(pchrPtrConsulta), 
			      pchrPtrConsulta);
sprintf(lchrArrConsulta,"%s%s",lchrArrEncabezado,lchrArrCadenaEnvio);	
SISCOMConectateServidor(PDEPURACION pintPuertoAD,pchrPtrDirIPAD,&lintSocketAD,0);
Write(lintSocketAD,lchrArrConsulta,strlen(lchrArrConsulta));
*pintSocketAD=lintSocketAD;
}
int RNADFormaCadenaYRealizaAltaSVR(PARDEPURACION int pintPuertoAD,char *pchrPtrDirIPAD,char *pchrPtrUsuario,char *pchrPtrPassword,char *pchrPtrNombDll,char *pchrPtrNombFuncion,char *pchrPtrMovimiento,int  *pintPtrSocketSVR)
{
int lintSocketAD;	
char lchrArrEncabezado[1024];
RNADFormaCadenaEncabezado(PDEPURACION pchrPtrUsuario,pchrPtrPassword,pchrPtrNombDll,pchrPtrNombFuncion,pchrPtrMovimiento,lchrArrEncabezado);
SISCOMConectateServidor(PDEPURACION pintPuertoAD,pchrPtrDirIPAD,&lintSocketAD,0);
Write(lintSocketAD,lchrArrEncabezado,strlen(lchrArrEncabezado));
*pintPtrSocketSVR=lintSocketAD;


}
int RNADFormaCadenaEncabezado(PARDEPURACION char *pchrPtrUsuario,char *pchrPtrPassword,char *pchrPtrNombDll,char *pchrPtrNombFuncion,char *pchrPtrMovimiento,char *pchrPtrEncabezado)
{
int llngTamano=0;
int llngReg;
char lchrArrCadena[500];
char lchrArrTamano[6];
	sprintf(lchrArrCadena,"%05dSISCOMCOM00010005",llngTamano);
	llngTamano=strlen(lchrArrCadena);
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pchrPtrMovimiento,1,1,&llngReg,lchrArrCadena+llngTamano);llngTamano+=llngReg;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pchrPtrUsuario,2,1,&llngReg,lchrArrCadena+llngTamano);llngTamano+=llngReg;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pchrPtrPassword,3,1,&llngReg,lchrArrCadena+llngTamano);llngTamano+=llngReg;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pchrPtrNombDll,4,1,&llngReg,lchrArrCadena+llngTamano);llngTamano+=llngReg;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pchrPtrNombFuncion,5,1,&llngReg,lchrArrCadena+llngTamano);llngTamano+=llngReg;
	lchrArrCadena[llngTamano]=0;
	sprintf(lchrArrTamano,"%05d",llngTamano);
	strncpy(lchrArrCadena,lchrArrTamano,5);
	strcpy(pchrPtrEncabezado,lchrArrCadena);



}
int RNADFormaProtocoloEncabezado(PARDEPURACION int pintPipe,STRUCTDatosDeLaOperacion pstcDatosDeLaOperacionReg,STRUCTError *pstcErrorReg)
{
	int llngTamano=0;
	int llngReg;
	char lchrArrCadena[500];
	char lchrArrTamano[6];
#ifdef DEBUG
	       //strcat(pchrPtrTabulador,"\t");
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%0inSTRUCTDatosDeLaOperacion%","RNADFormaProtocoloEncabezado",pstcDatosDeLaOperacionReg);
#endif
	
	sprintf(lchrArrCadena,"%05dSISCOMCOM00010005",llngTamano);
	llngTamano=strlen(lchrArrCadena);
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcDatosDeLaOperacionReg.chrArrMovimiento,1,1,&llngReg,lchrArrCadena+llngTamano);llngTamano+=llngReg;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcDatosDeLaOperacionReg.chrArrUsuario,2,1,&llngReg,lchrArrCadena+llngTamano);llngTamano+=llngReg;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcDatosDeLaOperacionReg.chrArrPassword,3,1,&llngReg,lchrArrCadena+llngTamano);llngTamano+=llngReg;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcDatosDeLaOperacionReg.chrArrNomDll,4,1,&llngReg,lchrArrCadena+llngTamano);llngTamano+=llngReg;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcDatosDeLaOperacionReg.chrArrNomFuncion,5,1,&llngReg,lchrArrCadena+llngTamano);llngTamano+=llngReg;
	lchrArrCadena[llngTamano]=0;
	sprintf(lchrArrTamano,"%05d",llngTamano);
	strncpy(lchrArrCadena,lchrArrTamano,5);
	Write(pintPipe,lchrArrCadena,strlen(lchrArrCadena));
}
int RNADObtenDatosAltaProducto(PARDEPURACION int pintSocket,int *pintPtrNRegistros,STRUCTLtaProductos **pstcLtaProductosReg,STRUCTError *pstcErrorReg)
{
	STRUCTLtaProductos *lstcLtaProductosPtrPrim;
	static int lintNRegistros,lintNCampos;
	char lchrArrDato[16];
	int lintI;
	static STRUCTProductos lstcProductosReg;
	STRUCTLtaProductos *lstcLtaProductosPtrDat;
#ifdef DEBUG
       //strcat(pchrPtrTabulador,"\t");
       SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADObtenDatosAltaProducto");
#endif
	Read(pintSocket,lchrArrDato,4);
	lchrArrDato[4]=0;
	lintNRegistros=*pintPtrNRegistros=atoi(lchrArrDato);
	Read(pintSocket,lchrArrDato,4);
	lchrArrDato[4]=0;
	lintNCampos=atoi(lchrArrDato);
	lstcLtaProductosPtrPrim=lstcLtaProductosPtrDat=0;	
	for(lintI=0;lintI<lintNRegistros;lintI++)
	{
	 	RNADObtenDatosDelProducto(PDEPURACION pintSocket,&lstcProductosReg,pstcErrorReg);
		RNADAsignaMemoriaLtaProducto(PDEPURACION &lstcLtaProductosPtrDat,lstcProductosReg,pstcErrorReg);		
		if(!lstcLtaProductosPtrPrim)
		   *pstcLtaProductosReg=lstcLtaProductosPtrPrim=lstcLtaProductosPtrDat;
		else
		{
		   (*pstcLtaProductosReg)->stcLtaProductosSig=lstcLtaProductosPtrDat;
	   	   (*pstcLtaProductosReg)= (*pstcLtaProductosReg)->stcLtaProductosSig;	   
		    
		}
		
	}
	*pstcLtaProductosReg=lstcLtaProductosPtrPrim;
}
int RNADAsignaMemoriaLtaProducto(PARDEPURACION STRUCTLtaProductos **pstcLtaProductosPtrReg,STRUCTProductos pstcProductosDat,STRUCTError *pstcErrorPtrReg)
{
#ifdef DEBUG
         strcat(pchrPtrTabulador,"\t");
         SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%0inSTRUCTProductos%","RNADAsignaMemoriaLtaProducto",pstcProductosDat);
#endif
	if( ((*pstcLtaProductosPtrReg)=(STRUCTLtaProductos *)malloc(sizeof(STRUCTLtaProductos) ) ) )
	{
		(*pstcLtaProductosPtrReg)->stcProductosDat=pstcProductosDat;
		(*pstcLtaProductosPtrReg)->stcLtaProductosSig=NULL;
	}
	else
	{
		printf("Se termino la memoria \n");
	}


}
int RNADCreaListaDatosDelProducto(PARDEPURACION STRUCTProductos pstcProductosDat,STRUCTLtaProductos **pstcLtaProductosPtrPrim,
				  STRUCTLtaProductos **pstcLtaProductosPtrDat,STRUCTError *pstcErrorReg)
{
STRUCTLtaProductos *lstcLtaProductosPtrReg=NULL;
#ifdef DEBUG
	           //    strcat(pchrPtrTabulador,"\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADCreaListaDatosDelProducto");
#endif
	RNADAsignaMemoriaLtaProducto(PDEPURACION &lstcLtaProductosPtrReg,pstcProductosDat,pstcErrorReg);
	if(!*pstcLtaProductosPtrPrim)
	*pstcLtaProductosPtrPrim=*pstcLtaProductosPtrDat=lstcLtaProductosPtrReg;
	else
	{	
		(*pstcLtaProductosPtrDat)->stcLtaProductosSig=lstcLtaProductosPtrReg;
		(*pstcLtaProductosPtrDat)=(*pstcLtaProductosPtrDat)->stcLtaProductosSig;
	}	


}
int RNADObtenDatosDelProducto(PARDEPURACION int pintSocket,STRUCTProductos *pstcProductosPtrReg,STRUCTError *pstcErrorReg)
{
#ifdef DEBUG
	  //     strcat(pchrPtrTabulador,"\t");
            //   SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADObtenDatosDelProducto");
#endif
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocket,pstcProductosPtrReg->chrArrClaveProd,NULL);	
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocket,pstcProductosPtrReg->chrArrNomDelProducto,NULL);	
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocket,pstcProductosPtrReg->chrArrClaveProv,NULL);	
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocket,pstcProductosPtrReg->chrArrDescProd,NULL);	
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocket,pstcProductosPtrReg->chrArrCantidad,NULL);	
#ifdef  DEBUG
        // SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%0inSTRUCTProductos%","RNADObtenDatosDelProducto",*pstcProductosPtrReg);
	
#endif
}
int RNADFormaCadenaDatosDeLaOperacion(PARDEPURACION STRUCTDatosDeLaOperacion pstcDatosDeLaOperacionDat,char *pchrPtrCadena,STRUCTError *pstcErrorPtrReg)
{
	int lintPos;
	int lintTamano;
	sprintf(pchrPtrCadena,"00000SISCOMCOM%04d%04d",1,NODATOSOPERACION);
	lintPos=strlen(pchrPtrCadena);
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcDatosDeLaOperacionDat.chrArrMovimiento,1,1,&lintTamano,pchrPtrCadena+lintPos);lintPos+=lintTamano;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcDatosDeLaOperacionDat.chrArrUsuario,2,1,&lintTamano,pchrPtrCadena+lintPos);lintPos+=lintTamano;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcDatosDeLaOperacionDat.chrArrPassword,3,1,&lintTamano,pchrPtrCadena+lintPos);lintPos+=lintTamano;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcDatosDeLaOperacionDat.chrArrNomDll,4,1,&lintTamano,pchrPtrCadena+lintPos);lintPos+=lintTamano;
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcDatosDeLaOperacionDat.chrArrNomFuncion,5,1,&lintTamano,pchrPtrCadena+lintPos);lintPos+=lintTamano;
}
int RNADCopiaDatosDelProducto(PARDEPURACION char *pchrPtrCvePrd,char *pchrPtrNmbPrd,char *pchrPtrCvePrv,char *pchrPtrDscPrd,STRUCTProductos *pstcProductosPtrReg)
{
#ifdef DEBUG
	   //    strcat(pchrPtrTabulador,"\t");
              SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%0INchar*%0INchar*%0INchar*%0INchar*%000STRUCTProductos*%","RNADCopiaDatosDelProducto",
			                      pchrPtrCvePrd,pchrPtrNmbPrd,pchrPtrCvePrv,pchrPtrDscPrd,pstcProductosPtrReg);
	     
#endif
	strcpy(pstcProductosPtrReg->chrArrClaveProd,pchrPtrCvePrd);
	strcpy(pstcProductosPtrReg->chrArrNomDelProducto,pchrPtrNmbPrd);
	strcpy(pstcProductosPtrReg->chrArrClaveProv,pchrPtrCvePrv);
	strcpy(pstcProductosPtrReg->chrArrDescProd,pchrPtrDscPrd);
	pstcProductosPtrReg->chrArrCantidad[0]=0;
	
}
int RNADEnviaDatosDelProducto(PARDEPURACION int pintSocketCliente,int pintNRegistros,int pintNCampos,STRUCTLtaProductos *pstcLtaProductosPtrLta,STRUCTError *pstcErrorPtrReg)
{
	int lintI,lintTam;
	int lintPos=0;
	char lchrArrCadena[1000];
#ifdef DEBUG
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%0INint%","RNADFormaCadenaAltaProductos",pintNRegistros);
#endif
	sprintf(lchrArrCadena,"%04d%04d",pintNRegistros,pintNCampos);
	Write(pintSocketCliente,lchrArrCadena,strlen(lchrArrCadena));
	
	while(pstcLtaProductosPtrLta)
	{
	  SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaProductosPtrLta->stcProductosDat.chrArrClaveProd,1,1,&lintTam,lchrArrCadena+lintPos);lintPos+=lintTam;
          SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaProductosPtrLta->stcProductosDat.chrArrNomDelProducto,2,1,&lintTam,lchrArrCadena+lintPos);lintPos+=lintTam;
         SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaProductosPtrLta->stcProductosDat.chrArrClaveProv,3,1,&lintTam,lchrArrCadena+lintPos);lintPos+=lintTam;
         SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaProductosPtrLta->stcProductosDat.chrArrDescProd,4,1,&lintTam,lchrArrCadena+lintPos);lintPos+=lintTam;
	 SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaProductosPtrLta->stcProductosDat.chrArrCantidad,5,1,&lintTam,lchrArrCadena+lintPos);lintPos+=lintTam;
	 printf("\nla cadena de productos es \n\n%s\n",lchrArrCadena);
	 Write(pintSocketCliente,lchrArrCadena,strlen(lchrArrCadena)); 
	 lintPos=0;
	 pstcLtaProductosPtrLta=pstcLtaProductosPtrLta->stcLtaProductosSig;
	}
}
int RNADFormaCadenaAltaProductos(PARDEPURACION STRUCTLtaProductos *pstcLtaProductosPtrLta,int pintNRegistros,char *pchrPtrCadena,STRUCTError *pstcErrorPtrReg)
{
int lintI,lintTam;
int lintPos;
#ifdef DEBUG        
SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%0INint%","RNADFormaCadenaAltaProductos",pintNRegistros);
#endif
sprintf(pchrPtrCadena,"%04d%04d",pintNRegistros,5);
lintPos=strlen(pchrPtrCadena);
while(pstcLtaProductosPtrLta)
{
        SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaProductosPtrLta->stcProductosDat.chrArrClaveProd,1,1,&lintTam,pchrPtrCadena+lintPos);lintPos+=lintTam;
        SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaProductosPtrLta->stcProductosDat.chrArrNomDelProducto,2,1,&lintTam,pchrPtrCadena+lintPos);lintPos+=lintTam;
        SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaProductosPtrLta->stcProductosDat.chrArrClaveProv,3,1,&lintTam,pchrPtrCadena+lintPos);lintPos+=lintTam;
        SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaProductosPtrLta->stcProductosDat.chrArrDescProd,4,1,&lintTam,pchrPtrCadena+lintPos);lintPos+=lintTam;
        SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaProductosPtrLta->stcProductosDat.chrArrCantidad,5,1,&lintTam,pchrPtrCadena+lintPos);lintPos+=lintTam;
         pstcLtaProductosPtrLta=pstcLtaProductosPtrLta->stcLtaProductosSig;
	 printf("\n\nLa cadena de productos %s\n",pchrPtrCadena);
 }
}
int RNADFormaCadenaProtocoloXRegistroProducto(PARDEPURACION STRUCTProductos pstcProductosDat,char *pchrPtrCadena,STRUCTError *stcErrorPtrReg)
{
	int lintPos=0;
	int lintTam;
#ifdef DEBUG
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%0inSTRUCTProductos%","RNADFormaCadenaProtocoloXRegistroProducto",pstcProductosDat);
#endif
	 SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcProductosDat.chrArrClaveProd,1,1,&lintTam,pchrPtrCadena+lintPos);
	 lintPos+=lintTam;
	 SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcProductosDat.chrArrNomDelProducto,2,1,&lintTam,pchrPtrCadena+lintPos);
	 lintPos+=lintTam; 
	 SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcProductosDat.chrArrClaveProv,3,1,&lintTam,pchrPtrCadena+lintPos);
	 lintPos+=lintTam;
	 SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcProductosDat.chrArrDescProd,4,1,&lintTam,pchrPtrCadena+lintPos);
	 lintPos+=lintTam;
	 SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcProductosDat.chrArrCantidad,5,1,&lintTam,pchrPtrCadena+lintPos);
	 lintPos+=lintTam;
	 printf("\n\nLa cadena de productos %s\n",pchrPtrCadena);
	 
}
int RNADImprimeSTRUCTDatosDeLaOperacion(STRUCTDatosDeLaOperacion pstcDatosDeLaOperacionDat)
{

    printf("[STRUCTDatosDeLaOperacion] ");
    printf("{chrArrMovimiento=%s,",pstcDatosDeLaOperacionDat.chrArrMovimiento);
    printf("chrArrUsuario=%s,",pstcDatosDeLaOperacionDat.chrArrUsuario);
    printf("chrArrPassword=%s,",pstcDatosDeLaOperacionDat.chrArrPassword);
    printf("chrArrNomDll=%s,",pstcDatosDeLaOperacionDat.chrArrNomDll);
    printf("chrArrNomFuncion=%s}",pstcDatosDeLaOperacionDat.chrArrNomFuncion);

}
int RNADImprimeSTRUCTProductosPtr(STRUCTProductos *pstcProductos)
{
	printf("[STRUCTProductos*]%x,",pstcProductos);

}
int RNADImprimeSTRUCTProductos(STRUCTProductos pstcProductos)
{
    printf("[STRUCTProductos]\n");
    printf("{\nchrArrClaveProd=%s,\n",pstcProductos.chrArrClaveProd);
    printf("chrArrNomDelProducto=%s,\n", pstcProductos.chrArrNomDelProducto);
    printf("chrArrClaveProv=%s,\n",pstcProductos.chrArrClaveProv);
    printf("chrArrDescProd=%s\n}\n", pstcProductos.chrArrDescProd);
}
int RNADImprimeSTRUCTLtaProductosPtr(STRUCTLtaProductos *pstcLtaProductos)
{
    printf("[STRUCTLtaProductos]\n{\n");
    RNADImprimeSTRUCTProductos(pstcLtaProductos->stcProductosDat);
    printf("stcLtaProductosSig=%x\n}\n",pstcLtaProductos->stcLtaProductosSig);
}
int RNADLeeCabeceraProtocolo(PARDEPURACION int pintSocket,char *pchrPtrCadena)
{
int lintTamProtocolo;
char lchrArrCadena[6];
	Read(pintSocket,lchrArrCadena,5);
	lchrArrCadena[5]=0;
	lintTamProtocolo=atoi(lchrArrCadena);
	Read(pintSocket,pchrPtrCadena,lintTamProtocolo-5);
	pchrPtrCadena[lintTamProtocolo-5]=0;
#ifdef DEBUG
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%0inchar*%","RNADLeeCabeceraProtocolo",pchrPtrCadena);
#endif	
}
int RNADAnexaErrorALaLista(PARDEPURACION STRUCTLtaErrorAltaProductos **pstcLtaErrorAltaProductosPtrDat,
		           STRUCTLtaErrorAltaProductos **pstcLtaErrorAltaProductosPtrPrim,
			   STRUCTError pstcErrorDat,STRUCTProductos pstcProductosDat)
{
   if(!(*pstcLtaErrorAltaProductosPtrPrim))	
   {
   RNADAsignaMemoriaErrorAltaProductos(PDEPURACION pstcLtaErrorAltaProductosPtrPrim,pstcErrorDat,pstcProductosDat);
   *pstcLtaErrorAltaProductosPtrDat=*pstcLtaErrorAltaProductosPtrPrim;
   }
   else
   RNADAsignaMemoriaErrorAltaProductos(PDEPURACION &((*pstcLtaErrorAltaProductosPtrDat)->stcLtaErrorAltaProductosSig),pstcErrorDat,pstcProductosDat);

}
int RNADAsignaMemoriaErrorAltaProductos(PARDEPURACION STRUCTLtaErrorAltaProductos **pstcLtaErrorAltaProductosPtrDat,
				        STRUCTError pstcErrorDat,STRUCTProductos pstcProductosDat)
{
	if((*pstcLtaErrorAltaProductosPtrDat=(STRUCTLtaErrorAltaProductos *)malloc(sizeof(STRUCTLtaErrorAltaProductos))))
	{
		(*pstcLtaErrorAltaProductosPtrDat)->stcErrorDat=pstcErrorDat;
                (*pstcLtaErrorAltaProductosPtrDat)->stcProductosDat=pstcProductosDat;
		(*pstcLtaErrorAltaProductosPtrDat)->stcLtaErrorAltaProductosSig=NULL;

	}
}
int RNADAsignaMemoriaCompras(PARDEPURACION STRUCTCompras pstcComprasDat,STRUCTLtaCompras **pstcLtaComprasPtrReg,STRUCTError *pstcErrorPtrReg)
{
#ifdef DEBUG
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADAsignaMemoriaCompras");
#endif
	
	if((*pstcLtaComprasPtrReg=(STRUCTLtaCompras *)malloc(sizeof(STRUCTLtaCompras ))))
	{

		(*pstcLtaComprasPtrReg)->stcCompras=pstcComprasDat;
		(*pstcLtaComprasPtrReg)->stcLtaComprasPtrSig=NULL;
	}	
	else;
}
int RNADAsignaMemoriaCharPtr(PARDEPURACION char **pchrPtrMemoria,int pintTamano,STRUCTError *pstcErrorPtrReg)
{


}
int RNADCreaListaDeCompras(PARDEPURACION STRUCTCompras pstcComprasDat,STRUCTLtaCompras **pstcLtaComprasPtrRegPrim,STRUCTLtaCompras **pstcLtaComprasPtrRegDat,STRUCTError *pstcErrorPtrReg)
{
STRUCTLtaCompras *lstcLtaComprasPtrDat=NULL;	
	
#ifdef DEBUG
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADCreaListaDeCompras");
#endif
	RNADAsignaMemoriaCompras(PDEPURACION pstcComprasDat,&lstcLtaComprasPtrDat,pstcErrorPtrReg);
	if(!*pstcLtaComprasPtrRegPrim)
	*pstcLtaComprasPtrRegDat=*pstcLtaComprasPtrRegPrim=lstcLtaComprasPtrDat;	
	else
	{
	(*pstcLtaComprasPtrRegDat)->stcLtaComprasPtrSig=lstcLtaComprasPtrDat;
	(*pstcLtaComprasPtrRegDat)=(*pstcLtaComprasPtrRegDat)->stcLtaComprasPtrSig;
	}
}
int RNADFormaCadenaCompras(PARDEPURACION STRUCTLtaCompras *pstcLtaComprasPtrReg,char **pchrPtrCadenaReg,STRUCTError *pstcErrorPtrReg)
{
/*int lintNRegistros=0,lintNColumnas=0;	
int lintTamano=0,lintPos=0;
*pchrPtrCadenaReg=(char *)malloc(20);
sprintf(*pchrPtrCadenaReg,"%04d%04d",lintNRegistros,lintNColumnas);
lintPos=strlen(*pchrPtrCadenaReg);
	while(pstcLtaComprasPtrReg)
	{
		SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstc.chrArrClaveProd,1,1,&lintTam,pchrPtrCadena+lintPos);		
		
	}*/
}

int RNADEnviaRegistrosDeCompras(PARDEPURACION int pintSocketCliente,int pintNRegistros,int pintNCampos,STRUCTLtaCompras *pstcLtaComprasPtrDat,STRUCTError *pstcErrorPtrReg)
{
int lintTam,lintPos=0;	
char lchrArrCadena[1000];
int i;
#ifdef DEBUG
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADEnviaRegistrosDeCompras");
#endif
    if(!pintNRegistros)	
    RNADRegistroVacioCompras(PDEPURACION pintSocketCliente);
    else
    {	    
		
	sprintf(lchrArrCadena,"%04d%04d",pintNRegistros,pintNCampos);
	Write(pintSocketCliente,lchrArrCadena,strlen(lchrArrCadena));
	while(pstcLtaComprasPtrDat)
	{
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaComprasPtrDat->stcCompras.chrArrCveProducto,1,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaComprasPtrDat->stcCompras.chrArrCveProveedor,2,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaComprasPtrDat->stcCompras.chrArrPVenta,3,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaComprasPtrDat->stcCompras.chrArrPCompra,4,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaComprasPtrDat->stcCompras.chrArrCveVendedor,5,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaComprasPtrDat->stcCompras.chrArrCantidad,6,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaComprasPtrDat->stcCompras.chrArrFechaCompra,7,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaComprasPtrDat->stcCompras.chrArrFormaDePago,8,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaComprasPtrDat->stcCompras.chrArrPMayoreo,9,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaComprasPtrDat->stcCompras.chrArrExistencia,10,1,&lintTam,lchrArrCadena+lintPos);
	lintPos=0;
	Write(pintSocketCliente,lchrArrCadena,strlen(lchrArrCadena));
	pstcLtaComprasPtrDat=pstcLtaComprasPtrDat->stcLtaComprasPtrSig;
	}
    }

}
int RNADRegistroVacioCompras(PARDEPURACION int pintSocketCliente)
{
char lchrArrCadena[200];
int lintTam,lintPos=0;
	sprintf(lchrArrCadena,"%04d%04d",1,10);
	Write(pintSocketCliente,lchrArrCadena,strlen(lchrArrCadena));
#ifdef DEBUG
		 SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADRegistroVacioCompras");
#endif 
        SISCOMFormaDatosProtocoloCHAR(PDEPURACION "*",1,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION "*",2,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION "*",3,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION "*",4,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION "*",5,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION "*",6,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION "*",7,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION "*",8,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION "*",9,1,&lintTam,lchrArrCadena+lintPos);
	lintPos+=lintTam;			
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION "*",10,1,&lintTam,lchrArrCadena+lintPos);
	Write(pintSocketCliente,lchrArrCadena,strlen(lchrArrCadena));
printf("No se que pasa %s\n",lchrArrCadena);
			


}
int RNADLlenaCompras(PARDEPURACION char *pchrPtrCveProducto,char *pchrPtrCveProveedor,char *pchrPtrPVenta,char *pchrPtrPCompra,
		     char *pchrPtrCveVendedor,char *pchrPtrCantidad,char *pchrPtrFechaCompra,char *pchrPtrFormaDePago,char *pchrPtrPMayoreo,char *pchrPtrExistencia,STRUCTCompras *pstcComprasPtrReg)
{
	
#ifdef DEBUG
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%000char*%000char*%000char*%000char*%000char*%","RNADLlenaCompras",pchrPtrCveProducto,pchrPtrCveProveedor,pchrPtrPVenta,pchrPtrPMayoreo,pchrPtrExistencia);
#endif	
	strcpy(pstcComprasPtrReg->chrArrCveProducto,pchrPtrCveProducto);
	strcpy(pstcComprasPtrReg->chrArrCveProveedor,pchrPtrCveProveedor);
	strcpy(pstcComprasPtrReg->chrArrPVenta,pchrPtrPVenta);
	strcpy(pstcComprasPtrReg->chrArrPCompra,pchrPtrPCompra);
	strcpy(pstcComprasPtrReg->chrArrCveVendedor,pchrPtrCveVendedor);
	strcpy(pstcComprasPtrReg->chrArrCantidad,pchrPtrCantidad);
	strcpy(pstcComprasPtrReg->chrArrFechaCompra,pchrPtrFechaCompra);
	strcpy(pstcComprasPtrReg->chrArrFormaDePago,pchrPtrFormaDePago);
	strcpy(pstcComprasPtrReg->chrArrPMayoreo,pchrPtrPMayoreo);	
	strcpy(pstcComprasPtrReg->chrArrExistencia,pchrPtrExistencia);
}
int RNADObtenRegistroDeCompras(PARDEPURACION int pintSocketCliente,STRUCTCompras *pstcComprasPtrReg,STRUCTError *pstcErrorPtrReg)
{
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcComprasPtrReg->chrArrCveProducto,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcComprasPtrReg->chrArrCveProveedor,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcComprasPtrReg->chrArrPVenta,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcComprasPtrReg->chrArrPCompra,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcComprasPtrReg->chrArrCveVendedor,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcComprasPtrReg->chrArrCantidad,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcComprasPtrReg->chrArrFechaCompra,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcComprasPtrReg->chrArrFormaDePago,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcComprasPtrReg->chrArrPMayoreo,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcComprasPtrReg->chrArrExistencia,NULL);
	
#ifdef DEBUG
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%000char*%000char*%000char*%000char*%000char*%000char*%","RNADObtenRegistroDeCompras",
			                pstcComprasPtrReg->chrArrCveProducto,pstcComprasPtrReg->chrArrFechaCompra,
					pstcComprasPtrReg->chrArrCveProveedor,pstcComprasPtrReg->chrArrFormaDePago,
					pstcComprasPtrReg->chrArrPMayoreo,pstcComprasPtrReg->chrArrExistencia);
#endif	
}
int RNADGeneraListaCompras(PARDEPURACION int pintSocketCliente,int *pintPtrNRegistros,STRUCTLtaCompras **pstcLtaComprasPtrPrim,STRUCTError *pstcErrorPtrReg)
{
STRUCTLtaCompras *lstcLtaComprasPtrDat=NULL;	
STRUCTCompras lstcComprasReg;
char lchrArrNRegistros[10];
int lintI;
#ifdef DEBUG
	        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADGeneraListaCompras");
#endif
		SISCOMLeeDatos(PDEPURACION pintSocketCliente,8,lchrArrNRegistros,0);
		lchrArrNRegistros[4]=0;
		*pintPtrNRegistros=atoi(lchrArrNRegistros);
		for(lintI=0;lintI<*pintPtrNRegistros;lintI++)
		{
                 RNADObtenRegistroDeCompras(PDEPURACION pintSocketCliente,&lstcComprasReg,pstcErrorPtrReg);
                 RNADCreaListaDeCompras(PDEPURACION lstcComprasReg,pstcLtaComprasPtrPrim,&lstcLtaComprasPtrDat,pstcErrorPtrReg);
		}	
		
}
int RNADAsignaMemoriaLtaCotizacion(PARDEPURACION STRUCTCotizacion pstcCotizacionDat,STRUCTLtaCotizacion **pstcLtaCotizacionPtrReg,STRUCTError *pstcErrorPtrReg)
{
#ifdef DEBUG
	        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADAsignaMemoriaLtaCotizacion");
#endif
	if((*pstcLtaCotizacionPtrReg=(STRUCTLtaCotizacion *)malloc(sizeof(STRUCTLtaCotizacion ))))	
	{
           (*pstcLtaCotizacionPtrReg)->stcCotizacionDat=pstcCotizacionDat;
	   (*pstcLtaCotizacionPtrReg)->stcLtaCotizacionPtrSig=NULL;
	}	
}
int RNADCreaListaCotizacion(PARDEPURACION STRUCTCotizacion pstcCotizacionDat,STRUCTLtaCotizacion **pstcLtaCotizacionPtrPrim,STRUCTLtaCotizacion **pstcLtaCotizacionPtrDat,STRUCTError *pstcErrorPtrReg)
{
STRUCTLtaCotizacion *lstcLtaCotizacionPtrReg;	
#ifdef DEBUG
	        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADCreaListaCotizacion");
#endif
		RNADAsignaMemoriaLtaCotizacion(PDEPURACION pstcCotizacionDat,&lstcLtaCotizacionPtrReg,pstcErrorPtrReg);
		if(!*pstcLtaCotizacionPtrPrim)
		*pstcLtaCotizacionPtrPrim=*pstcLtaCotizacionPtrDat=lstcLtaCotizacionPtrReg;
		else
		{
		   (*pstcLtaCotizacionPtrDat)->stcLtaCotizacionPtrSig=lstcLtaCotizacionPtrReg;
	   	   *pstcLtaCotizacionPtrDat = (*pstcLtaCotizacionPtrDat)->stcLtaCotizacionPtrSig;
	
		}
}
int RNADEnviaCotizacion(PARDEPURACION int pintSocket,int pintNRegistros,int pintNCampos,STRUCTLtaCotizacion *pstcLtaCotizacionPtrReg,STRUCTError *pstcErrorPtrReg)
{
char lchrArrCadena[1000];
int lintPos=0,lintTam=0;
#ifdef DEBUG
	        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADEnviaCotizacion");
#endif
		sprintf(lchrArrCadena,"%04d%04d",pintNRegistros,pintNCampos);
		Write(pintSocket,lchrArrCadena,strlen(lchrArrCadena));
                while(pstcLtaCotizacionPtrReg)
		{
	         SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaCotizacionPtrReg->stcCotizacionDat.chrArrCveProducto,1,1,&lintTam,lchrArrCadena+lintPos);
	         lintPos+=lintTam;			
	         SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaCotizacionPtrReg->stcCotizacionDat.chrArrCantidad,2,1,&lintTam,lchrArrCadena+lintPos);
	         lintPos+=lintTam;			
	         SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaCotizacionPtrReg->stcCotizacionDat.chrArrCostoUnitario,3,1,&lintTam,lchrArrCadena+lintPos);
	         lintPos+=lintTam;			
	         SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaCotizacionPtrReg->stcCotizacionDat.chrArrCostoTotal,4,1,&lintTam,lchrArrCadena+lintPos);
	         lintPos+=lintTam;			
	         SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaCotizacionPtrReg->stcCotizacionDat.chrArrImporteTotal,5,1,&lintTam,lchrArrCadena+lintPos);
	         lintPos+=lintTam;			
	         SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaCotizacionPtrReg->stcCotizacionDat.chrArrPMayoreo,6,1,&lintTam,lchrArrCadena+lintPos);
	         lintPos+=lintTam;			
	         SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaCotizacionPtrReg->stcCotizacionDat.chrArrExistencia,7,1,&lintTam,lchrArrCadena+lintPos);
	         lintPos+=lintTam;			
		 Write(pintSocket,lchrArrCadena,strlen(lchrArrCadena));
		 lintPos=lintTam=0;
		 pstcLtaCotizacionPtrReg=pstcLtaCotizacionPtrReg->stcLtaCotizacionPtrSig;

		}		
}
int RNADGeneraListaCotizacion(PARDEPURACION int pintSocketCliente,int *pintPtrNRegistros,STRUCTLtaCotizacion **pstcLtaCotizacionPtrPrim,STRUCTError *pstcErrorPtrReg)
{
int lintI;	
char lchrArrNRegistros[10];
STRUCTCotizacion lstcCotizacionDat;
STRUCTLtaCotizacion *lstcLtaCotizacionPtrReg=NULL;
#ifdef DEBUG
	        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADGeneraListaCotizacion");
#endif
		SISCOMLeeDatos(PDEPURACION pintSocketCliente,8,lchrArrNRegistros,0);
                lchrArrNRegistros[4]=0;
		*pintPtrNRegistros=atoi(lchrArrNRegistros);
		for(lintI=0;lintI<*pintPtrNRegistros;lintI++)
		{
			RNADObtenRegistroCotizacion(PDEPURACION pintSocketCliente,&lstcCotizacionDat,pstcErrorPtrReg);
                        RNADCreaListaCotizacion(PDEPURACION lstcCotizacionDat,pstcLtaCotizacionPtrPrim,&lstcLtaCotizacionPtrReg,pstcErrorPtrReg);
		}

}
int RNADLlenaCotizacion(PARDEPURACION STRUCTCompras pstcComprasDat,STRUCTCantidadYProducto pstcCantidadYProductoDat,STRUCTCotizacion *pstcCotizacionPtrReg,float *pfltPtrCostoTotal,STRUCTError *pstcErrorPtrReg)
{
float lfltPVenta;	
float lfltPMayoreo;
#ifdef DEBUG
	        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADLlenaCotizacion");
#endif
		lfltPVenta=atof(pstcComprasDat.chrArrPVenta);
		lfltPMayoreo=atof(pstcComprasDat.chrArrPMayoreo);
		*pfltPtrCostoTotal=pstcCantidadYProductoDat.chrTipoPrecio=='M' ? lfltPMayoreo*(float )pstcCantidadYProductoDat.intCantidad:lfltPVenta*(float )pstcCantidadYProductoDat.intCantidad;
		strcpy(pstcCotizacionPtrReg->chrArrCveProducto,pstcComprasDat.chrArrCveProducto);
		sprintf(pstcCotizacionPtrReg->chrArrCantidad,"%d",pstcCantidadYProductoDat.intCantidad);
		sprintf(pstcCotizacionPtrReg->chrArrCostoUnitario,"%.3f",lfltPVenta);
		sprintf(pstcCotizacionPtrReg->chrArrCostoTotal,"%.3f",*pfltPtrCostoTotal);
		sprintf(pstcCotizacionPtrReg->chrArrImporteTotal,"%.3f",0.0);
		sprintf(pstcCotizacionPtrReg->chrArrPMayoreo,"%.3f",lfltPMayoreo);
		strcpy(pstcCotizacionPtrReg->chrArrExistencia,pstcComprasDat.chrArrExistencia);
	
}
int RNADObtenRegistroCotizacion(PARDEPURACION int pintSocketCliente,STRUCTCotizacion *pstcCotizacionPtrReg,STRUCTError *pstcErrorReg)
{

#ifdef DEBUG
	        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADObtenRegistroCotizacion");
#endif

	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcCotizacionPtrReg->chrArrCveProducto,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcCotizacionPtrReg->chrArrCantidad,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcCotizacionPtrReg->chrArrCostoUnitario,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcCotizacionPtrReg->chrArrCostoTotal,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcCotizacionPtrReg->chrArrImporteTotal,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcCotizacionPtrReg->chrArrPMayoreo,NULL);
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcCotizacionPtrReg->chrArrExistencia,NULL);

	printf("\n%s %s",pstcCotizacionPtrReg->chrArrCveProducto,pstcCotizacionPtrReg->chrArrCantidad);

}
int RNFormaCadenaTipoDePrecio(char *pchrPtrPCantidad,char *pchrPtrCSalida)
{
	char *lchrPtrRegreso;
	int lintPosicion=0;
	int lintSuma=0;
	int lintPosEntrada=0;
	int lintPosSalida=0;
	int lintNCaracteres=0;
	memset(pchrPtrCSalida,0,strlen(pchrPtrPCantidad));
	while((lchrPtrRegreso=strstr(pchrPtrPCantidad+lintSuma,",")))
	{
	  lintPosEntrada=lchrPtrRegreso-(pchrPtrPCantidad+lintSuma);
	  strncpy(pchrPtrCSalida+lintPosSalida,pchrPtrPCantidad+lintSuma,lintPosEntrada);
	  lintSuma+=++lintPosEntrada;
	  strcat(pchrPtrCSalida,";m,");
	  lintPosSalida=strlen(pchrPtrCSalida);
	}
       strcat(pchrPtrCSalida,pchrPtrPCantidad+lintSuma);
       strcat(pchrPtrCSalida,";m");
}
int RNADFechasDelPrecio(PARDEPURACION char *pchrPtrFechaHoy,char *pchrPtrFechaMesAnterior)
{
time_t regTime;
struct tm *stctm;
int lintMes,lintAno;
regTime=time(NULL);
stctm=gmtime(&regTime);
sprintf(pchrPtrFechaHoy,"%d.%d.%d",stctm->tm_year+1900,stctm->tm_mday,stctm->tm_mon+1);
if(stctm->tm_mon+1)
{
lintMes=stctm->tm_mon;
lintAno=stctm->tm_year+1900;
}
else
{	
lintMes=12;
lintAno=stctm->tm_year+1900-1;
}

sprintf(pchrPtrFechaMesAnterior,"%d.%d.%d",lintAno,stctm->tm_mday,lintMes);


}
int RNADLlenaCliente(PARDEPURACION char *pchrPtrCveCliente,char *pchrPtrNombre,char *pchrPtrDireccion,STRUCTCliente *pstcClientePtrDat)
{
#ifdef DEBUG
                SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","");
#endif	
		strcpy(pstcClientePtrDat->chrArrCveCliente,pchrPtrCveCliente);
		strcpy(pstcClientePtrDat->chrArrNmbCliente,pchrPtrNombre);
		strcpy(pstcClientePtrDat->chrArrDirCliente,pchrPtrDireccion);
}
int RNADAsignaMemoriaLtaCliente(PARDEPURACION STRUCTCliente pstcClienteDat,STRUCTLtaCliente **pstcLtaClientePtrDat)
{
#ifdef DEBUG
                SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADAsignaMemoriaLtaCliente");
#endif	
		if((*pstcLtaClientePtrDat=(STRUCTLtaCliente *)malloc(sizeof(STRUCTLtaCliente ))))
		{
			(*pstcLtaClientePtrDat)->stcClienteDat=pstcClienteDat;
			(*pstcLtaClientePtrDat)->stcLtaClienteSig=NULL;
		}	
		else
		fprintf(stdout,"Error al asignar memoria para la LtaCliente\n");
}
int RNADCreaLtaCliente(PARDEPURACION STRUCTCliente pstcClienteDat, STRUCTLtaCliente **pstcLtaClientePtrPrim,STRUCTLtaCliente **pstcLtaClientePtrUlt)
{
STRUCTLtaCliente *lstcLtaClientePtrReg=NULL;	
	RNADAsignaMemoriaLtaCliente(PDEPURACION pstcClienteDat,&lstcLtaClientePtrReg);
#ifdef DEBUG
                SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADCreaLtaCliente");
#endif	
	if((*pstcLtaClientePtrPrim)==NULL)
	*pstcLtaClientePtrPrim=*pstcLtaClientePtrUlt=lstcLtaClientePtrReg;
	else
	{
	  (*pstcLtaClientePtrUlt)->stcLtaClienteSig=lstcLtaClientePtrReg;
	  (*pstcLtaClientePtrUlt)=(*pstcLtaClientePtrUlt)->stcLtaClienteSig;
	  (*pstcLtaClientePtrUlt)->stcLtaClienteSig=NULL;

	}	
}
int RNADObtenRegistroCliente(PARDEPURACION int pintSocketCliente,STRUCTCliente *pstcClientePtrReg)
{
#ifdef DEBUG
                SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADObtenRegistroCliente");
#endif	
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcClientePtrReg->chrArrCveCliente,NULL);	
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcClientePtrReg->chrArrNmbCliente,NULL);	
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcClientePtrReg->chrArrDirCliente,NULL);	
}
int RNADGeneraLtaCliente(PARDEPURACION int pintSocketCliente,int *pintPtrNRegistros,STRUCTLtaCliente **pstcLtaClientePtrPrim)
{
int lintI;
char lchrArrNRegistros[10];
STRUCTLtaCliente *lstcLtaClientePtrUlt=NULL;	
STRUCTCliente lstcClienteReg;
#ifdef DEBUG
	                SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADGeneraLtaCliente");
#endif
        SISCOMLeeDatos(PDEPURACION pintSocketCliente,8,lchrArrNRegistros,0);
        lchrArrNRegistros[4]=0;
        *pintPtrNRegistros=atoi(lchrArrNRegistros);
	for(lintI=0;lintI<*pintPtrNRegistros;lintI++)
	{
	   RNADObtenRegistroCliente(PDEPURACION pintSocketCliente,&lstcClienteReg);
	   RNADCreaLtaCliente(PDEPURACION lstcClienteReg,pstcLtaClientePtrPrim,&lstcLtaClientePtrUlt);
	}

										
			
}
int RNADEnviaClientes(PARDEPURACION int pintSocket,int pintNRegistros,int pintNCampos,STRUCTLtaCliente *pstcLtaClientePtrReg)
{
char lchrArrCadenita[10000];
int lintPos=0,lintTam=0;
int lintTamCad;
#ifdef DEBUG
                SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADEnviaClientes");
#endif	
		
sprintf(lchrArrCadenita,"%04d%04d",pintNRegistros,pintNCampos);
lintTamCad=strlen(lchrArrCadenita);
               Write(pintSocket,lchrArrCadenita,lintTamCad);

	while(pstcLtaClientePtrReg)
	{
	 SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaClientePtrReg->stcClienteDat.chrArrCveCliente,1,1,&lintTam,lchrArrCadenita+lintPos);
	 lintPos+=lintTam;
	 SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaClientePtrReg->stcClienteDat.chrArrNmbCliente,2,1,&lintTam,lchrArrCadenita+lintPos);
	 lintPos+=lintTam;
	 SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaClientePtrReg->stcClienteDat.chrArrDirCliente,3,1,&lintTam,lchrArrCadenita+lintPos);
         Write(pintSocket,lchrArrCadenita,strlen(lchrArrCadenita));
         lintPos=lintTam=0;
         pstcLtaClientePtrReg=pstcLtaClientePtrReg->stcLtaClienteSig;
 	}
}

int RNADLlenaStcEstGananciaNDisp(PARDEPURACION char *pchrPtrCveProducto,char *pchrPtrNoDispositivos,char *pchrPtrGanancia,STRUCTEstGananciaNDisp *pstcEstGananciaNDispPtrReg)
{
#ifdef DEBUG
                SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADLlenaStcEstGananciaNDisp");
#endif	
	strcpy(pstcEstGananciaNDispPtrReg->chrArrCveProducto,pchrPtrCveProducto);
	strcpy(pstcEstGananciaNDispPtrReg->chrArrNoDispositivos,pchrPtrNoDispositivos);
	strcpy(pstcEstGananciaNDispPtrReg->chrArrGanancia,pchrPtrGanancia);	
}
int RNADAsignaMemoriaLtaEstGananciaNDisp(PARDEPURACION STRUCTEstGananciaNDisp pstcEstGananciaNDispDat,STRUCTLtaEstGananciaNDisp **pstcLtaEstGananciaNDispPtrReg)
{
#ifdef DEBUG
                SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADAsignaMemoriaLtaEstGananciaNDisp");
#endif
		if((*pstcLtaEstGananciaNDispPtrReg=(STRUCTLtaEstGananciaNDisp *)malloc(sizeof(STRUCTLtaEstGananciaNDisp))))
		{
			(*pstcLtaEstGananciaNDispPtrReg)->stcEstGananciaNDispDat=pstcEstGananciaNDispDat;
			(*pstcLtaEstGananciaNDispPtrReg)->stcLtaEstGananciaNDispSig=NULL;	
		}
		else
			printf("\nSe genero un error al asigna la memoria\n");
		
}
int RNADCreaLtaEstGananciaNDisp(PARDEPURACION STRUCTEstGananciaNDisp pstcEstGananciaNDispDat,STRUCTLtaEstGananciaNDisp **pstcLtaEstGananciaNDispPtrPrim,STRUCTLtaEstGananciaNDisp **pstcLtaEstGananciaNDispPtrUlt)
{
STRUCTLtaEstGananciaNDisp *lstcLtaEstGananciaNDispPtrReg=NULL;	
	RNADAsignaMemoriaLtaEstGananciaNDisp(PDEPURACION pstcEstGananciaNDispDat,&lstcLtaEstGananciaNDispPtrReg);
#ifdef DEBUG
                SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADCreaLtaEstGananciaNDisp");
#endif
	 if(!(*pstcLtaEstGananciaNDispPtrPrim))
	 *pstcLtaEstGananciaNDispPtrPrim=*pstcLtaEstGananciaNDispPtrUlt=lstcLtaEstGananciaNDispPtrReg;
	 else
	 {
	 	(*pstcLtaEstGananciaNDispPtrUlt)->stcLtaEstGananciaNDispSig=lstcLtaEstGananciaNDispPtrReg;
		*pstcLtaEstGananciaNDispPtrUlt=(*pstcLtaEstGananciaNDispPtrUlt)->stcLtaEstGananciaNDispSig;
		(*pstcLtaEstGananciaNDispPtrUlt)->stcLtaEstGananciaNDispSig=NULL;
	 }	 
		
}
int RNADObtenRegistroLtaEstGananciaNDisp(PARDEPURACION int pintSocketCliente,STRUCTEstGananciaNDisp *pstcEstGananciaNDispPtrReg)
{
#ifdef DEBUG
                SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADObtenRegistroLtaEstGananciaNDisp");
#endif	
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcEstGananciaNDispPtrReg->chrArrCveProducto,NULL);	
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcEstGananciaNDispPtrReg->chrArrNoDispositivos,NULL);	
	SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente,pstcEstGananciaNDispPtrReg->chrArrGanancia,NULL);	
}
int RNADGeneraLtaEstGananciaNDisp(PARDEPURACION int pintSocketCliente,int *pintPtrNRegistros,STRUCTLtaEstGananciaNDisp **pstcLtaEstGananciaNDispPtrPrim)
{
int lintI=0;	
char lchrArrNRegistros[10];
STRUCTLtaEstGananciaNDisp *lstcLtaEstGananciaNDispPtrReg=NULL;
STRUCTEstGananciaNDisp lstcEstGananciaNDispDat;
#ifdef DEBUG
                        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADGeneraLtaEstGananciaNDisp");
#endif
       SISCOMLeeDatos(PDEPURACION pintSocketCliente,8,lchrArrNRegistros,0);
       lchrArrNRegistros[4]=0;
       *pintPtrNRegistros=atoi(lchrArrNRegistros);
       for(lintI=0;lintI<*pintPtrNRegistros;lintI++)
       {
         RNADObtenRegistroLtaEstGananciaNDisp(PDEPURACION pintSocketCliente,&lstcEstGananciaNDispDat);
         RNADCreaLtaEstGananciaNDisp(PDEPURACION lstcEstGananciaNDispDat,pstcLtaEstGananciaNDispPtrPrim,&lstcLtaEstGananciaNDispPtrReg);
       }
}
int RNADEnviaLtaEstGananciaNDisp(PARDEPURACION int pintSocket,int pintNRegistros,int pintNCampos,STRUCTLtaEstGananciaNDisp *pstcLtaEstGananciaNDispPtrDat)
{
char lchrArrCadenita[10000];
int lintPos=0,lintTam=0;
int lintTamCad;
#ifdef DEBUG
                SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADEnviaLtaEstGananciaNDisp");
#endif

		sprintf(lchrArrCadenita,"%04d%04d",pintNRegistros,pintNCampos);
		lintTamCad=strlen(lchrArrCadenita);
		Write(pintSocket,lchrArrCadenita,lintTamCad);
               while(pstcLtaEstGananciaNDispPtrDat)
               {
                SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaEstGananciaNDispPtrDat->stcEstGananciaNDispDat.chrArrCveProducto,1,1,&lintTam,lchrArrCadenita+lintPos);
                lintPos+=lintTam;
               SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaEstGananciaNDispPtrDat->stcEstGananciaNDispDat.chrArrNoDispositivos,2,1,&lintTam,lchrArrCadenita+lintPos);
                lintPos+=lintTam;
                SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaEstGananciaNDispPtrDat->stcEstGananciaNDispDat.chrArrGanancia,3,1,&lintTam,lchrArrCadenita+lintPos);
                Write(pintSocket,lchrArrCadenita,strlen(lchrArrCadenita));
                lintPos=lintTam=0;
                pstcLtaEstGananciaNDispPtrDat=pstcLtaEstGananciaNDispPtrDat->stcLtaEstGananciaNDispSig;
               }
}
int RNADObtenDllConsultaYFuncion(PARDEPURACION char *pchrPtrCadenaRegreso,char *pchrPtrNmbDllAEjecutar,char *pchrPtrNmbFuncion)
{
int lintI;
	for(lintI=0;*pchrPtrCadenaRegreso!=',';lintI++,*pchrPtrCadenaRegreso++)
		pchrPtrNmbDllAEjecutar[lintI]=*pchrPtrCadenaRegreso;
	*pchrPtrCadenaRegreso++;
	pchrPtrNmbDllAEjecutar[lintI]=0;
	for(lintI=0;*pchrPtrCadenaRegreso!=',';lintI++,*pchrPtrCadenaRegreso++)
	 pchrPtrNmbFuncion[lintI]=*pchrPtrCadenaRegreso;
	*pchrPtrCadenaRegreso++;
	pchrPtrNmbFuncion[lintI]=0;


}
