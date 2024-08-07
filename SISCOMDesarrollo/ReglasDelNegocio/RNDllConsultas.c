#include <RNDllConsultas.h>
#include <RNDllConsultasHGE.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
static char *gchrPtrConsultas[]={
                                 "Compras",
                                 "FechasCompras*",
                                 "Productos",
                                 "Productos*",
				 "ComprasXProducto",
				 "Clientes*",
				 "EstadisticasGanNDisp*"
 															                                 };
int gintFechasCompras=0;
#define NCONSULTAS 7
int RNDllCNSIdentificaConsulta(PARDEPURACION int pintSocket,int pintTuberia[],int pintPuertoAD,char *pchrPtrDIPSvrAD,STRUCTError *pstcErrorPtrReg)
{
char ***lchrPtrCadenaRegreso;
char lchrArrCadenaFormateada[1500],lchrArrCadenaTipoPrecio[1500];
int lintNRegistros,lintNColumnas;
int i;
STRUCTCantidadYProducto lstcCantidadYProductoDat[100];
#ifdef DEBUG
	        //strcat(pchrPtrTabulador,"\t");
	        SISCOMImprimeFuncionYArgumentos(pchrPtrTabulador,"%00F%0inint%0inint*%0inint%0inchar*%","RNDllCNSIdentificaConsulta",pintSocket,pintTuberia,pintPuertoAD,pchrPtrDIPSvrAD);
#endif
        SISCOMObtenInformacionDelProtocolo(PDEPURACION pintSocket,&lintNRegistros,&lintNColumnas,&lchrPtrCadenaRegreso,pstcErrorPtrReg);
	printf("\n\t Consultando %s\n",lchrPtrCadenaRegreso[0][0]);
	SISCOMQuitaComa(PDEPURACION lchrPtrCadenaRegreso[0][0],lchrArrCadenaFormateada);
	for(i=0;i<NCONSULTAS;i++)
	if(!strcmp(lchrArrCadenaFormateada,gchrPtrConsultas[i]))
	{	
	switch(i)
	{
		case 0:
			
                        RNDllCNSFormaCamposConsulta(PDEPURACION lchrPtrCadenaRegreso[0][0],lchrArrCadenaFormateada,lstcCantidadYProductoDat,pstcErrorPtrReg);
			RNDllCNSConsultaCompras(PDEPURACION pintSocket,pintTuberia,lchrArrCadenaFormateada,pintPuertoAD ,pchrPtrDIPSvrAD,pstcErrorPtrReg);	
		break;	
		case 1:
			gintFechasCompras=1;
	                sprintf(lchrArrCadenaFormateada,"%04d%04d%04d%04d%04d%s",1,1,1,1,strlen(gchrPtrConsultas[i]),gchrPtrConsultas[i]);
			RNDllCNSConsultaCompras(PDEPURACION pintSocket,pintTuberia,lchrArrCadenaFormateada,pintPuertoAD ,pchrPtrDIPSvrAD,pstcErrorPtrReg);	
		break;	
		case 2:
                        RNDllCNSFormaCamposConsulta(PDEPURACION lchrPtrCadenaRegreso[0][0],lchrArrCadenaFormateada,lstcCantidadYProductoDat,pstcErrorPtrReg);
	                RNDllCNSConsultaProductos(PDEPURACION pintSocket,pintTuberia,lchrArrCadenaFormateada,lstcCantidadYProductoDat,pintPuertoAD,pchrPtrDIPSvrAD,pstcErrorPtrReg);
	        break;	
		case 3:
	                  sprintf(lchrArrCadenaFormateada,"%04d%04d%04d%04d%04d%s",1,1,1,1,strlen(gchrPtrConsultas[i]),gchrPtrConsultas[i]);
	                  RNDllCNSConsultaProductos(PDEPURACION pintSocket,pintTuberia,lchrArrCadenaFormateada,NULL,pintPuertoAD,pchrPtrDIPSvrAD,pstcErrorPtrReg);
		break;
		case 4:
			
                        RNDllCNSFormaCamposConsulta(PDEPURACION lchrPtrCadenaRegreso[0][0],lchrArrCadenaFormateada,lstcCantidadYProductoDat,pstcErrorPtrReg);
                         RNDllCNSCotizaOrden(PDEPURACION pintSocket,pintTuberia,lchrArrCadenaFormateada,lstcCantidadYProductoDat,pintPuertoAD,pchrPtrDIPSvrAD,pstcErrorPtrReg);
		break;	
		case 5:
				
	                sprintf(lchrArrCadenaFormateada,"%04d%04d%04d%04d%04d%s",1,1,1,1,strlen(gchrPtrConsultas[i]),gchrPtrConsultas[i]);
			RNDllCNSConsultaClientes(PDEPURACION pintSocket,pintTuberia,lchrArrCadenaFormateada,pintPuertoAD ,pchrPtrDIPSvrAD);			   
			
		break;
		case 6:
	                sprintf(lchrArrCadenaFormateada,"%04d%04d%04d%04d%04d%s",1,1,1,1,strlen(gchrPtrConsultas[i]),gchrPtrConsultas[i]);
			 RNDllCNSConsultaEstGananciaNDisp(PDEPURACION pintSocket,pintTuberia,lchrArrCadenaFormateada,pintPuertoAD ,pchrPtrDIPSvrAD);
		break;
	}
	}	
}
int RNDllCNSConsultaCompras(PARDEPURACION int pintSocket,int pintTuberia[],char *pchrPtrCadenaConsulta,int pintPuerto,char *pchrPtrDirIPSvrAD,STRUCTError *pstcErrorPtrReg)
{
char lchrArrEncabezado[500],lchrArrTamano[6],lchrArrEncabezado1[500];
int lintSocketAD;
STRUCTLtaCompras *lstcLtaComprasPtrPrim=NULL;
int lintNRegistros;
char lchrCaracter='*';
#ifdef DEBUG
	strcat(pchrPtrTabulador,"\t");
       SISCOMImprimeFuncionYArgumentos(pchrPtrTabulador,"%00F%","RNDllCNSConsultaCompras");
#endif
	RNADLeeCabeceraProtocolo(PDEPURACION pintTuberia[0],lchrArrEncabezado);
	sprintf(lchrArrTamano,"%05d",strlen(lchrArrEncabezado));
	sprintf(lchrArrEncabezado1,"%s%s%s",lchrArrTamano,lchrArrEncabezado,pchrPtrCadenaConsulta);
	SISCOMConectateServidor(PDEPURACION pintPuerto,pchrPtrDirIPSvrAD,&lintSocketAD,NULL);
	Write(lintSocketAD,lchrArrEncabezado1,strlen(lchrArrEncabezado1));
        RNADGeneraListaCompras(PDEPURACION lintSocketAD,&lintNRegistros,&lstcLtaComprasPtrPrim,pstcErrorPtrReg);
	if(gintFechasCompras)
        RNDllCNSEliminaFechasDuplicadas(PDEPURACION &lstcLtaComprasPtrPrim,&lintNRegistros);
	RNADEnviaRegistrosDeCompras(PDEPURACION pintSocket,lintNRegistros,8,lstcLtaComprasPtrPrim,pstcErrorPtrReg);
	Write(pintSocket,&lchrCaracter,1);
	close(lintSocketAD);
	close(pintSocket);
		
}
int RNDllCNSConsultaProductos(PARDEPURACION int pintSocket,int pintTuberia[],char *pchrPtrCadenaConsulta,STRUCTCantidadYProducto *pstcCantidadYProductoPtrDat,int pintPuerto,char *pchrPtrDIPSvrAD,STRUCTError *pstcErrorPtrReg)
{
char lchrArrEncabezado[500],lchrArrTamano[6],lchrArrEncabezado1[500];
int lintSocketAD;
char lchrCaracter;
STRUCTLtaProductos *lstcLtaProductosPrim;
STRUCTError lstcErrorReg;
int lintNRegistros;
#ifdef DEBUG
        //strcat(pchrPtrTabulador,"\t");
        SISCOMImprimeFuncionYArgumentos(pchrPtrTabulador,"%00F%","RNDllCNSConsultaProductos");
#endif
	RNADLeeCabeceraProtocolo(PDEPURACION pintTuberia[0],lchrArrEncabezado);
	sprintf(lchrArrTamano,"%05d",strlen(lchrArrEncabezado));
	sprintf(lchrArrEncabezado1,"%s%s%s",lchrArrTamano,lchrArrEncabezado,pchrPtrCadenaConsulta);
	SISCOMConectateServidor(PDEPURACION pintPuerto,pchrPtrDIPSvrAD,&lintSocketAD,NULL);
	Write(lintSocketAD,lchrArrEncabezado1,strlen(lchrArrEncabezado1));
#define CONSIN00	
#ifdef CONSIN
	
	while(lchrCaracter!='*')
	{
		Read(lintSocketAD,&lchrCaracter,1);
		Write(pintSocket,&lchrCaracter,1);
	}		
#else	
	RNADObtenDatosAltaProducto(PDEPURACION lintSocketAD,&lintNRegistros,&lstcLtaProductosPrim,&lstcErrorReg);
	sprintf(lchrArrEncabezado,"%04d%04d",lintNRegistros,5);
	Write(pintSocket,lchrArrEncabezado,strlen(lchrArrEncabezado));
	printf("\n\n\nRespondiendo al cliente \n");
	while(lstcLtaProductosPrim)
	{
	 if(pstcCantidadYProductoPtrDat)
	 {
	   if(!pstcCantidadYProductoPtrDat->intCantidad)
	    pstcCantidadYProductoPtrDat++;	   
	   if(!strcmp(pstcCantidadYProductoPtrDat->chrArrCveProducto,lstcLtaProductosPrim->stcProductosDat.chrArrClaveProd))
   	   sprintf(lstcLtaProductosPrim->stcProductosDat.chrArrCantidad,"%d",pstcCantidadYProductoPtrDat->intCantidad);		      
	   pstcCantidadYProductoPtrDat++;
	 }	
  	  RNADFormaCadenaProtocoloXRegistroProducto(PDEPURACION lstcLtaProductosPrim->stcProductosDat,lchrArrEncabezado,&lstcErrorReg);	    
	  lstcLtaProductosPrim=lstcLtaProductosPrim->stcLtaProductosSig;
	  Write(pintSocket,lchrArrEncabezado,strlen(lchrArrEncabezado));
	}
#endif	
}
int RNDllCNSCotizaOrden(PARDEPURACION int pintSocket,int pintTuberia[],char *pchrPtrCadenaConsulta,STRUCTCantidadYProducto *pstcCantidadYProductoPtrDat,int pintPuerto,char *pchrPtrDirIPSvrAD,STRUCTError *pstcErrorPtrReg)
{
char lchrArrEncabezado[1500],lchrArrTamano[6],lchrArrEncabezado1[1500];
int lintSocketAD;
STRUCTLtaCompras *lstcLtaComprasPtrPrim=NULL;
STRUCTLtaCompras *lstcLtaComprasPtrPrimSalida=NULL;
int lintNRegistros;
char lchrCaracter='*';
#ifdef DEBUG
       strcat(pchrPtrTabulador,"\t");
       SISCOMImprimeFuncionYArgumentos(pchrPtrTabulador,"%00F%","RNDllCNSConsultaCompras");
#endif
	RNADLeeCabeceraProtocolo(PDEPURACION pintTuberia[0],lchrArrEncabezado);
	sprintf(lchrArrTamano,"%05d",strlen(lchrArrEncabezado));
	sprintf(lchrArrEncabezado1,"%s%s%s",lchrArrTamano,lchrArrEncabezado,pchrPtrCadenaConsulta);
	SISCOMConectateServidor(PDEPURACION pintPuerto,pchrPtrDirIPSvrAD,&lintSocketAD,NULL);
	Write(lintSocketAD,lchrArrEncabezado1,strlen(lchrArrEncabezado1));
        RNADGeneraListaCompras(PDEPURACION lintSocketAD,&lintNRegistros,&lstcLtaComprasPtrPrim,pstcErrorPtrReg);
        RNDllCNSObtenPrecios(PDEPURACION lstcLtaComprasPtrPrim,&lstcLtaComprasPtrPrimSalida,&lintNRegistros,pstcErrorPtrReg);
	RNDllCNSEnviaCotizacion(PDEPURACION pintSocket,lstcLtaComprasPtrPrimSalida,pstcCantidadYProductoPtrDat,lintNRegistros,pstcErrorPtrReg);
	Write(pintSocket,&lchrCaracter,1);

}
int RNDllCNSEnviaCotizacion(PARDEPURACION int pintSocketCliente,STRUCTLtaCompras *pstcLtaComprasPtrPrim,STRUCTCantidadYProducto *pstcCantidadYProductoPtrDat,int pintNRegistros,STRUCTError *pstcErrorPtrReg)
{
float lfltImporteTotal=0.0,lfltImporte=0.0;
STRUCTCotizacion lstcCotizacionReg;
STRUCTLtaCotizacion *lstcLtaCotizacionPtrPrim=NULL,*lstcLtaCotizacionPtrDat=NULL;
int lintI;
int lintJ;
#ifdef DEBUG
       strcat(pchrPtrTabulador,"\t");
       SISCOMImprimeFuncionYArgumentos(pchrPtrTabulador,"%00F%","RNDllCNSEnviaCotizacion");
#endif
       for(lintI=0;lintI<pintNRegistros;lintI++)
       {
	for(lintJ=0;lintJ<pintNRegistros;lintJ++)
	 if(!strcmp(pstcLtaComprasPtrPrim->stcCompras.chrArrCveProducto,pstcCantidadYProductoPtrDat[lintJ].chrArrCveProducto))
	 break;
        RNADLlenaCotizacion(PDEPURACION pstcLtaComprasPtrPrim->stcCompras,pstcCantidadYProductoPtrDat[lintJ],&lstcCotizacionReg,&lfltImporteTotal,pstcErrorPtrReg);
	lfltImporte+=lfltImporteTotal;
	sprintf(lstcCotizacionReg.chrArrImporteTotal,"%.3f",lfltImporte);
	 RNADCreaListaCotizacion(PDEPURACION lstcCotizacionReg ,&lstcLtaCotizacionPtrPrim,&lstcLtaCotizacionPtrDat,pstcErrorPtrReg);
	 printf("\n\tEl precio total %.3f %s",lfltImporte,lstcCotizacionReg.chrArrCantidad);
	 pstcLtaComprasPtrPrim=pstcLtaComprasPtrPrim->stcLtaComprasPtrSig;
       }
        RNADEnviaCotizacion(PDEPURACION pintSocketCliente,pintNRegistros,6,lstcLtaCotizacionPtrPrim,pstcErrorPtrReg);
}
int RNDllCNSFormaCamposConsulta(PARDEPURACION char *pchrPtrCadena,char *pchrPtrCadenaFormato,STRUCTCantidadYProducto *pstcCantidadYProductoReg,STRUCTError *pstcErrorReg)
{
      char *lchrPtrRegreso;
      char lchrArrCadena[1000];
      char lchrArrRespaldo[1000];
      char *lchrPtrRespaldo=lchrArrRespaldo;
      int lintPos,lintPos1=0,lintTam=0,lintNCampo=1;
      int i=0; 
      static int lintPVez=0;
#ifdef DEBUG
	        //strcat(pchrPtrTabulador,"\t");
       SISCOMImprimeFuncionYArgumentos(pchrPtrTabulador,"%00F%","RNDllCNSFormaCamposConsulta");
#endif
//        RNFormaCadenaTipoDePrecio(pchrPtrCadena,lchrPtrRespaldo);
//	printf("\n\n\tLa cadenota es %s\n",lchrPtrRespaldo);
        strcpy(lchrPtrRespaldo,pchrPtrCadena);
        while(lchrPtrRegreso)
        {
           if((lchrPtrRegreso=strstr(lchrPtrRespaldo,",")))
           {
               lintPos=lchrPtrRegreso-lchrPtrRespaldo;
               strcpy(lchrArrCadena,lchrPtrRespaldo);
               lchrArrCadena[lintPos]=0;
	       if(lintPVez)
	       {
		     lchrArrCadena[lintPos-2]=0;
		     lintPos-=2;
		     lintPVez=0;  
	       }
	       RNDllCNSObtenCantidad(PDEPURACION lchrArrCadena,pstcCantidadYProductoReg+i);
	       SISCOMFormaDatosProtocoloCHAR(PDEPURACION lchrArrCadena,lintNCampo++,1,&lintTam,pchrPtrCadenaFormato+lintPos1);
	       lintPos1+=lintTam;
               lchrPtrRegreso++;
               strcpy(lchrPtrRespaldo,lchrPtrRegreso);
	       i++;
            }
             else
	     {
               strcpy(lchrArrCadena,lchrPtrRespaldo);
	       RNDllCNSObtenCantidad(PDEPURACION lchrArrCadena,pstcCantidadYProductoReg+i);
	       SISCOMFormaDatosProtocoloCHAR(PDEPURACION lchrArrCadena,lintNCampo++,1,&lintTam,pchrPtrCadenaFormato+lintPos1);
	       i++;
	     }

       }
	
	sprintf(lchrArrCadena,"%04d%04d",1,lintNCampo-1);
	sprintf(lchrArrRespaldo,"%s",pchrPtrCadenaFormato);
	sprintf(pchrPtrCadenaFormato,"%s%s",lchrArrCadena,lchrArrRespaldo);
}
int RNDllCNSObtenCantidad(PARDEPURACION char *pchrPtrCadena,STRUCTCantidadYProducto *pstcCantidadYProductoReg)
{
	char *lchrPtrRegreso;
	char lchrArrCadena[100];
	int lintPos;
	strcpy(lchrArrCadena,pchrPtrCadena);
#ifdef DEBUG
	        //strcat(pchrPtrTabulador,"\t");
       SISCOMImprimeFuncionYArgumentos(pchrPtrTabulador,"%00F%","RNDllCNSObtenCantidad");
#endif
		if((lchrPtrRegreso=strstr(lchrArrCadena,"*")))
		{
			lintPos=lchrPtrRegreso-pchrPtrCadena;
			lchrArrCadena[lintPos]=0;
			pstcCantidadYProductoReg->intCantidad=atoi(lchrArrCadena);
			strcpy(lchrArrCadena,pchrPtrCadena+lintPos+1);
			strcpy(pchrPtrCadena,lchrArrCadena);
			strcpy(pstcCantidadYProductoReg->chrArrCveProducto,pchrPtrCadena);
			if((lchrPtrRegreso=strstr(pchrPtrCadena,";")))
			{	
			   lintPos=lchrPtrRegreso-pchrPtrCadena;
		   	   pchrPtrCadena[lintPos]=0; 	   
		  	   pstcCantidadYProductoReg->chrTipoPrecio=*(++lchrPtrRegreso);	 
			   strcpy(pstcCantidadYProductoReg->chrArrCveProducto,pchrPtrCadena);
			}   
			
		}	
		else
		{
			pstcCantidadYProductoReg->intCantidad=atoi(lchrArrCadena);
			strcpy(pstcCantidadYProductoReg->chrArrCveProducto,pchrPtrCadena);
		}
	printf("\n\n%s  %d\n",pstcCantidadYProductoReg->chrArrCveProducto, pstcCantidadYProductoReg->intCantidad);	
}
int SISCOMQuitaComa(PARDEPURACION char *pchrPtrEntrada,char *pchrPtrSalida)
{

	char *pchrPtrRegreso;
	if((pchrPtrRegreso=strstr(pchrPtrEntrada,",")))
	{
		strcpy(pchrPtrSalida,pchrPtrEntrada);
		pchrPtrSalida[pchrPtrRegreso-pchrPtrEntrada]=0;
	}
	else
	strcpy(pchrPtrSalida,pchrPtrEntrada);

}
int RNDllCNSEliminaFechasDuplicadas(PARDEPURACION STRUCTLtaCompras **pstcLtaComprasPtrPrim,int *pintPtrRegN)
{
	STRUCTLtaCompras *lstcLtaComprasPtrRes=NULL;
	STRUCTLtaCompras *lstcLtaComprasPtrPivote=*pstcLtaComprasPtrPrim;
	STRUCTLtaCompras *lstcLtaComprasPtrDat=(*pstcLtaComprasPtrPrim)->stcLtaComprasPtrSig;
	STRUCTLtaCompras *lstcLtaComprasPtrPivotePrim=*pstcLtaComprasPtrPrim;
	int lintCuantos=0;
#ifdef DEBUG
	        //strcat(pchrPtrTabulador,"\t");
       SISCOMImprimeFuncionYArgumentos(pchrPtrTabulador,"%00F%","RNDllCNSEliminaFechasDuplicadas");
#endif
	printf("\nEliminando fechas repetidas");
	while(lstcLtaComprasPtrPivote)
	{
		printf("\nEliminando las fechas repetidos de %s",lstcLtaComprasPtrPivote->stcCompras.chrArrFechaCompra); 
	while(lstcLtaComprasPtrDat)
	{
		if(!strcmp(lstcLtaComprasPtrPivote->stcCompras.chrArrFechaCompra,lstcLtaComprasPtrDat->stcCompras.chrArrFechaCompra))
		{
		   lstcLtaComprasPtrPivote->stcLtaComprasPtrSig=lstcLtaComprasPtrDat->stcLtaComprasPtrSig;
		   lintCuantos++; 
		   printf("\n\tEliminando fechas");
		}
		lstcLtaComprasPtrDat=lstcLtaComprasPtrDat->stcLtaComprasPtrSig;
	}
	   if(lstcLtaComprasPtrPivote)
	   lstcLtaComprasPtrPivote=lstcLtaComprasPtrPivote->stcLtaComprasPtrSig;	
	   if(lstcLtaComprasPtrPivote)
	   lstcLtaComprasPtrDat=lstcLtaComprasPtrPivote->stcLtaComprasPtrSig;
	}
	*pintPtrRegN=*pintPtrRegN-lintCuantos;
	*pstcLtaComprasPtrPrim=lstcLtaComprasPtrPivotePrim;
	printf("\nSe enviaran %d",*pintPtrRegN);
}
int RNDllEliminaClavesDuplicadas(STRUCTLtaCompras **pstcLtaComprasPtrPrimDatos,int *pintNRegistros)
{
STRUCTLtaCompras *lstcLtaComprasPtrDatos=*pstcLtaComprasPtrPrimDatos;
STRUCTLtaCompras *lstcLtaComprasPtrDatRes=*pstcLtaComprasPtrPrimDatos;
STRUCTLtaCompras *lstcLtaComprasPtrSig=lstcLtaComprasPtrDatRes->stcLtaComprasPtrSig;
STRUCTLtaCompras *lstcLtaComprasPtrCambio=NULL;
*pintNRegistros=0;
	while(lstcLtaComprasPtrDatos)
	{
		(*pintNRegistros)++;
	  while(lstcLtaComprasPtrSig)
	  {
		if(!strcmp(lstcLtaComprasPtrDatos->stcCompras.chrArrCveProducto,lstcLtaComprasPtrSig->stcCompras.chrArrCveProducto))
		{
		printf("\nActual %f  Siguiente %f",atof(lstcLtaComprasPtrDatos->stcCompras.chrArrPVenta),atof(lstcLtaComprasPtrSig->stcCompras.chrArrPVenta));	
		*lstcLtaComprasPtrDatos=atof(lstcLtaComprasPtrDatos->stcCompras.chrArrPVenta)>atof(lstcLtaComprasPtrSig->stcCompras.chrArrPVenta) ? *lstcLtaComprasPtrDatos : *lstcLtaComprasPtrSig; 
		lstcLtaComprasPtrDatos->stcLtaComprasPtrSig=lstcLtaComprasPtrSig->stcLtaComprasPtrSig;
		lstcLtaComprasPtrSig=lstcLtaComprasPtrDatos->stcLtaComprasPtrSig;
		}
		else
		lstcLtaComprasPtrSig=lstcLtaComprasPtrSig->stcLtaComprasPtrSig;
		
			
	  }	  
	 if(lstcLtaComprasPtrDatos&&lstcLtaComprasPtrDatos->stcLtaComprasPtrSig)
	 { 
	   lstcLtaComprasPtrDatos=lstcLtaComprasPtrDatos->stcLtaComprasPtrSig;
	   lstcLtaComprasPtrSig=lstcLtaComprasPtrDatos->stcLtaComprasPtrSig;
	 }
	 else
         return ;
	   
		   
	}	

}
int RNDllCNSObtenPrecios(PARDEPURACION STRUCTLtaCompras *pstcLtaComprasPtrPrim,STRUCTLtaCompras **pstcLtaComprasPtrPrimSalida,int *pintNRegistros,STRUCTError *pstcErrorPtrReg)
{
STRUCTLtaCompras *lstcLtaComprasPtrPrimProducto=pstcLtaComprasPtrPrim;	
STRUCTLtaCompras *lstcLtaComprasPtrSegProducto=pstcLtaComprasPtrPrim->stcLtaComprasPtrSig ? pstcLtaComprasPtrPrim->stcLtaComprasPtrSig:NULL;	
STRUCTLtaCompras *lstcLtaComprasPtrPivote=lstcLtaComprasPtrPrimProducto;	
STRUCTLtaCompras *lstcLtaComprasPtrPrim=NULL;	
STRUCTLtaCompras *lstcLtaComprasPtrDat=NULL;	
STRUCTLtaCompras *lstcLtaComprasPtrPrimListaOriginal=pstcLtaComprasPtrPrim;	
STRUCTLtaCompras *lstcLtaComprasPtrPrimAEnviar=NULL;	
STRUCTLtaCompras *lstcLtaComprasPtrAEnviar=NULL;	
float lfltPrecioPivote=0.0,lfltPrecioSeg,lfltPrecioRes;
int lintReasigna=1;
#ifdef DEBUG
	        //strcat(pchrPtrTabulador,"\t");
       SISCOMImprimeFuncionYArgumentos(pchrPtrTabulador,"%00F%","RNDllCNSObtenPrecios");
#endif
*pintNRegistros=0;       
	while(lstcLtaComprasPtrPrimProducto)
	{
	   if(lstcLtaComprasPtrPivote)
	   {	   
	    lfltPrecioPivote=atof(lstcLtaComprasPtrPivote->stcCompras.chrArrPVenta);	
#ifdef DEBUG

	    printf("\n\t\tPivote %s %s %s",lstcLtaComprasPtrPivote->stcCompras.chrArrCveProducto,
					 lstcLtaComprasPtrPivote->stcCompras.chrArrFechaCompra,
					 lstcLtaComprasPtrPivote->stcCompras.chrArrPVenta);
#endif 
	   }
	 if(lstcLtaComprasPtrSegProducto&&!strcmp(lstcLtaComprasPtrPrimProducto->stcCompras.chrArrCveProducto,lstcLtaComprasPtrSegProducto->stcCompras.chrArrCveProducto))
	 {	
	  while(lstcLtaComprasPtrSegProducto)
	  {
	     if(!strcmp(lstcLtaComprasPtrPrimProducto->stcCompras.chrArrCveProducto,lstcLtaComprasPtrSegProducto->stcCompras.chrArrCveProducto))
	     {
#ifdef DEBUG
	    printf("\n\t\t\tEl para comparar  %s %s %s",lstcLtaComprasPtrSegProducto->stcCompras.chrArrCveProducto,
					 lstcLtaComprasPtrSegProducto->stcCompras.chrArrFechaCompra,
					 lstcLtaComprasPtrSegProducto->stcCompras.chrArrPVenta);
	                 lfltPrecioSeg=atof(lstcLtaComprasPtrSegProducto->stcCompras.chrArrPVenta);
#endif 	 
			  if(lfltPrecioPivote<lfltPrecioSeg)
			  {
	                   lstcLtaComprasPtrPivote=lstcLtaComprasPtrSegProducto;
			   lintReasigna=1;
#ifdef DEBUG			   
			   printf("\n\t\t\t\t%s %s %s",lstcLtaComprasPtrPivote->stcCompras.chrArrCveProducto,
						 lstcLtaComprasPtrPivote->stcCompras.chrArrFechaCompra,
						 lstcLtaComprasPtrPivote->stcCompras.chrArrPVenta);
#endif
			  }
	     }		  
		   lstcLtaComprasPtrSegProducto=lstcLtaComprasPtrSegProducto->stcLtaComprasPtrSig;	
	  }
	    if(lintReasigna)	
	    {
	    RNADCreaListaDeCompras(PDEPURACION lstcLtaComprasPtrPivote->stcCompras,pstcLtaComprasPtrPrimSalida,&lstcLtaComprasPtrDat,pstcErrorPtrReg);	
	    lintReasigna=0;
	    (*pintNRegistros)++;
	    }
	    while(lstcLtaComprasPtrPrimProducto&&lstcLtaComprasPtrPrimProducto->stcLtaComprasPtrSig&&!strcmp(lstcLtaComprasPtrPrimProducto->stcCompras.chrArrCveProducto,lstcLtaComprasPtrPrimProducto->stcLtaComprasPtrSig->stcCompras.chrArrCveProducto))
	    {		    
	    lstcLtaComprasPtrPrimProducto=lstcLtaComprasPtrPrimProducto->stcLtaComprasPtrSig;
	    lstcLtaComprasPtrPivote=lstcLtaComprasPtrPrimProducto->stcLtaComprasPtrSig;
	    }
	 }
	 else
	 { 
	    lstcLtaComprasPtrPrimProducto=lstcLtaComprasPtrPrimProducto->stcLtaComprasPtrSig;
	    if(lstcLtaComprasPtrPrimProducto)
	    lstcLtaComprasPtrSegProducto=lstcLtaComprasPtrPrimProducto->stcLtaComprasPtrSig;
	 }

	}
#ifdef DEBUG
	printf("\n\t\t\t\tEl numero de registros %d",*pintNRegistros);
#endif
       if(*pintNRegistros==0||lintReasigna)
       {
	       lstcLtaComprasPtrPrimProducto=pstcLtaComprasPtrPrim;
	    while(lstcLtaComprasPtrPrimProducto)
	    {	    
	    RNADCreaListaDeCompras(PDEPURACION lstcLtaComprasPtrPrimProducto->stcCompras,pstcLtaComprasPtrPrimSalida,&lstcLtaComprasPtrDat,pstcErrorPtrReg);	
	    (*pintNRegistros)++;
	    lstcLtaComprasPtrPrimProducto=lstcLtaComprasPtrPrimProducto->stcLtaComprasPtrSig;
	    }
       }
       
#ifdef DEBUG
	printf("\n\t\tLa lista Original\t\tLista Ha enviar");
#endif
	lstcLtaComprasPtrAEnviar=lstcLtaComprasPtrDat;
	lstcLtaComprasPtrPrimAEnviar=*pstcLtaComprasPtrPrimSalida;
#define CUAL
#ifdef CUAL	
	RNDllEliminaClavesDuplicadas(&lstcLtaComprasPtrPrimListaOriginal,pintNRegistros);
	*pstcLtaComprasPtrPrimSalida=lstcLtaComprasPtrPrimListaOriginal;
       while(lstcLtaComprasPtrPrimListaOriginal)
       {
#ifdef DEBUG
	printf("\n\t\t\t %s\t\t\t\t%s",lstcLtaComprasPtrPrimListaOriginal->stcCompras.chrArrCveProducto,
			           lstcLtaComprasPtrPrimAEnviar ? lstcLtaComprasPtrPrimAEnviar->stcCompras.chrArrCveProducto:"" );
#endif
	lstcLtaComprasPtrPrimListaOriginal=lstcLtaComprasPtrPrimListaOriginal->stcLtaComprasPtrSig;
	if(lstcLtaComprasPtrPrimAEnviar)
	lstcLtaComprasPtrPrimAEnviar=lstcLtaComprasPtrPrimAEnviar->stcLtaComprasPtrSig;
       }
#else       
       printf("\nNada");
#endif 	 
}
