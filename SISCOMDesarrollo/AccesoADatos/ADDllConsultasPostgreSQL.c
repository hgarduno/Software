#include <ADDllConsultasPostgreSQL.h>
#include <stdio.h>
#include <stdlib.h>
int ADDllConsultaEstGananciaNDispositivosPostgreSQL(PARDEPURACION STRUCTDatosDeLaOperacion pstcDatosDeLaOperacionDat,char *pchrPtrConsulta,STRUCTLtaEstGananciaNDisp **pstcLtaEstGananciaNDispPtrPrim,int *pintPtrNRegistros,int *pintPtrNColumnas,STRUCTError *pstcErrorPtrReg)
{
PGconn *conexion;
PGresult *resultado;
STRUCTEstGananciaNDisp lstcEstGananciaNDispDat;
STRUCTLtaEstGananciaNDisp *lstcLtaEstGananciaNDispPtrUlt=NULL;
int lintI,lintJ;
char *lchrPtrCveProducto,*lchrPtrGanancia,*lchrPtrNoDispositivos;
char lchrArrConsulta[1000];
char *lchrArrBaseDeDatos=getenv("BASESISCOM");
conexion=PQsetdb(NULL,NULL,NULL,NULL,lchrArrBaseDeDatos);
resultado=PQexec(conexion,"begin");
PQclear(resultado);
//
//sprintf(lchrArrConsulta,"declare CursorCNSEstGananciasNDisp cursor for\
//		   	 select sum( (-a.numprccompra+b.numprcunitario)*b.intCantidad ) as Ganancia , a.chrCveProducto,\
//			 sum(b.intCantidad) as NoDisVendidos \
//			 from compra as a,venta as b \
//			 where a.chrcveproducto=b.chrCveProducto and \
//			 a.numprccompra=( select max(numprccompra) from compra  where chrcveproducto=a.ChrCveProducto ) and \
//			 a.chrCveProducto=b.chrCveProducto \
//			 group by a.chrCveProducto");
//sprintf(lchrArrConsulta,"declare CursorCNSEstGananciasNDisp cursor for select chrCveProducto,numprcunitario,intCantidad from venta");
sprintf(lchrArrConsulta,"declare CursorCNSEstGananciasNDisp cursor for\
			 select a.Ganancia,b.Cantidad,a.chrCveProducto from GananciaYProducto as a,CantidadYProducto as b where a.chrCveProducto=b.chrCveProducto");
printf("\nafdassafsaf %s",lchrArrConsulta);
resultado=PQexec(conexion,lchrArrConsulta);
if(PQresultStatus(resultado)!=PGRES_COMMAND_OK)
printf("\n%s",              PQerrorMessage(conexion));
PQclear(resultado);
PQexec(conexion,"fetch all in CursorCNSEstGananciasNDisp");
*pintPtrNRegistros=PQntuples(resultado);
*pintPtrNColumnas=PQnfields(resultado);
printf("\nResultadossssssssssssssss %d",*pintPtrNRegistros);
for(lintI=0;lintI<*pintPtrNRegistros;lintI++)
{
    	
    lchrPtrGanancia=PQgetvalue(resultado,lintI,0);
    lchrPtrCveProducto=PQgetvalue(resultado,lintI,1);
    lchrPtrNoDispositivos=PQgetvalue(resultado,lintI,2);
    printf("\n %s",lchrPtrCveProducto);
    RNADLlenaStcEstGananciaNDisp(PDEPURACION lchrPtrCveProducto,lchrPtrNoDispositivos,lchrPtrGanancia,&lstcEstGananciaNDispDat);
    RNADCreaLtaEstGananciaNDisp(PDEPURACION lstcEstGananciaNDispDat,pstcLtaEstGananciaNDispPtrPrim,&lstcLtaEstGananciaNDispPtrUlt);
}
 PQclear(resultado);
 PQexec(conexion,"end");
 PQclear(resultado);
 PQfinish(conexion);
}
																//                                                                    
int ADDllConsultaClientesPostgreSQL(PARDEPURACION STRUCTDatosDeLaOperacion pstcDatosDeLaOperacionDat,char *pchrPtrConsulta,STRUCTLtaCliente **pstcLtaClientePtrPrim,int *pintPtrNRegistros,int *pintPtrNColumnas,STRUCTError *pstcErrorPtrReg)
{
PGconn *conexion;
PGresult *resultado;
STRUCTCliente lstcClienteDat;
STRUCTLtaCliente *lstcLtaClienteUlt=NULL;
int lintI,lintJ;
char *lchrPtrCveCliente,*lchrPtrNmbCliente,*lchrPtrDirCliente;
char lchrArrConsulta[1000];
char *lchrArrBaseDeDatos=getenv("BASESISCOM");
conexion=PQsetdb(NULL,NULL,NULL,NULL,lchrArrBaseDeDatos);
resultado=PQexec(conexion,"begin");
PQclear(resultado);
	sprintf(lchrArrConsulta,"declare CursorCNSClientes cursor for select * from cliente");
	resultado=PQexec(conexion,lchrArrConsulta);
	PQclear(resultado);
	PQexec(conexion,"fetch all in CursorCNSClientes");
	*pintPtrNRegistros=PQntuples(resultado);
	*pintPtrNColumnas=PQnfields(resultado);
	for(lintI=0;lintI<*pintPtrNRegistros;lintI++)
	{
		
	  lchrPtrCveCliente=PQgetvalue(resultado,lintI,0);
	  lchrPtrNmbCliente=PQgetvalue(resultado,lintI,1);
	  lchrPtrDirCliente=PQgetvalue(resultado,lintI,2);
	  SISCOMQuitaEspacios(PDEPURACION lchrPtrCveCliente);
//	  SISCOMQuitaEspacios(PDEPURACION lchrPtrNmbCliente);
//	  SISCOMQuitaEspacios(PDEPURACION lchrPtrDirCliente);
	  RNADLlenaCliente(PDEPURACION lchrPtrCveCliente,lchrPtrNmbCliente,lchrPtrDirCliente,&lstcClienteDat);
	  RNADCreaLtaCliente(PDEPURACION lstcClienteDat,pstcLtaClientePtrPrim,&lstcLtaClienteUlt);
	}
	PQclear(resultado);
	PQexec(conexion,"end");
	PQclear(resultado);
	PQfinish(conexion);

}
int ADDllConsultaComprasPostgreSQL(PARDEPURACION STRUCTDatosDeLaOperacion pstcDatosDeLaOperacionDat,char *pchrPtrConsulta,STRUCTLtaCompras **pstcLtaComprasPtrPrim,int *pintPtrNRegistros,int *pintPtrNColumnas,STRUCTError *pstcErrorPtrReg)
{
PGconn *conexion;
PGresult *resultado;
STRUCTCompras lstcComprasDat;
STRUCTLtaCompras *lstcLtaComprasPtrDat=NULL;
int i,j;
char *lchrPtrCveProducto, *lchrPtrCantidad, *lchrPtrPCompra, *lchrPtrPVenta, *lchrPtrCveProveedor, *lchrPtrCveVendedor, *lchrPtrFormaDePago, *lchrPtrFechaCompra,*lchrPtrPMayoreo,*lchrPtrExistencia;
char lchrArrCadenaConsulta[10000];
char *lchrArrBaseDeDatos=getenv("BASESISCOM");
conexion=PQsetdb(NULL,NULL,NULL,NULL,lchrArrBaseDeDatos);
resultado=PQexec(conexion,"begin");
PQclear(resultado);
		sprintf(lchrArrCadenaConsulta,"declare CursorCNSCompras cursor for select a.*,b.intExistencia from Compra as a,Inventario as b %s ",pchrPtrConsulta);
		resultado=PQexec(conexion,lchrArrCadenaConsulta);
		PQclear(resultado);
		PQexec(conexion,"fetch all in CursorCNSCompras");
		*pintPtrNRegistros=PQntuples(resultado);
		*pintPtrNColumnas=PQnfields(resultado);
		printf("El numero de registros %d\n",*pintPtrNRegistros);
		for(i=0;i<*pintPtrNRegistros;i++)
		{
		   lchrPtrFechaCompra=PQgetvalue(resultado,i,0);
		   lchrPtrCveProducto=PQgetvalue(resultado,i,1);
		   lchrPtrCveProveedor=PQgetvalue(resultado,i,2);
		   lchrPtrCantidad=PQgetvalue(resultado,i,3);
		   lchrPtrPCompra=PQgetvalue(resultado,i,4);
		   lchrPtrPVenta=PQgetvalue(resultado,i,5);
		   lchrPtrPMayoreo=PQgetvalue(resultado,i,6);	
		   lchrPtrFormaDePago=PQgetvalue(resultado,i,7);
		   lchrPtrCveVendedor=PQgetvalue(resultado,i,8);
		   lchrPtrExistencia=PQgetvalue(resultado,i,9);
		   SISCOMQuitaEspacios(PDEPURACION lchrPtrFechaCompra);
		   SISCOMQuitaEspacios(PDEPURACION lchrPtrCveProducto);
		   SISCOMQuitaEspacios(PDEPURACION lchrPtrCveProveedor);
		   SISCOMQuitaEspacios(PDEPURACION lchrPtrCantidad);
		   SISCOMQuitaEspacios(PDEPURACION lchrPtrPCompra);
		   SISCOMQuitaEspacios(PDEPURACION lchrPtrPVenta);
		   SISCOMQuitaEspacios(PDEPURACION lchrPtrPMayoreo);
		   //SISCOMQuitaEspacios(PDEPURACION lchrPtrFormaDePago);
		   SISCOMQuitaEspacios(PDEPURACION lchrPtrCveVendedor);
                   RNADLlenaCompras(PDEPURACION lchrPtrCveProducto,lchrPtrCveProveedor,lchrPtrPVenta,lchrPtrPCompra,lchrPtrCveVendedor,lchrPtrCantidad,lchrPtrFechaCompra,lchrPtrFormaDePago,lchrPtrPMayoreo,lchrPtrExistencia,&lstcComprasDat);
                   RNADCreaListaDeCompras(PDEPURACION lstcComprasDat,pstcLtaComprasPtrPrim,&lstcLtaComprasPtrDat,pstcErrorPtrReg);
		}

	PQclear(resultado);
	PQexec(conexion,"end");
	PQclear(resultado);
	PQfinish(conexion);
}
int ADDllConsultasPostgreSQL(PARDEPURACION STRUCTDatosDeLaOperacion pstcDatosDeLaOperacionDat,char *pchrPtrConsulta,STRUCTLtaProductos **pstcLtaProductosPtrReg,int *pintNRegistros,int *pintNColumnas,STRUCTError *pstcErrorPtrReg)
{
PGconn *conexion;
PGresult *resultado;
STRUCTProductos productos;
STRUCTLtaProductos *ltaproductosprim=NULL,*ltaproductosdat=NULL;
char *lchrPtrCveProducto;
char *lchrPtrCveProveedor;
char *lchrPtrDescripcion;
char *lchrPtrFamilia;
int i,j;
char lchrArrCadenaConsulta[1000];
char *lchrArrBaseDeDatos=getenv("BASESISCOM");
conexion=PQsetdb(NULL,NULL,NULL,NULL,lchrArrBaseDeDatos);
resultado=PQexec(conexion,"begin");
PQclear(resultado);
sprintf(lchrArrCadenaConsulta,"declare Con Cursor for \
			       select a.chrCveProveedor,b.chrCveProducto,b.chrDscCorta,b.chrFamilia \
			       from productoyproveedor as a,productos as b\
			       where a.chrCveProducto=b.chrCveProducto %s",pchrPtrConsulta);
printf("La cadena de consulta es %s\n",lchrArrCadenaConsulta); 
resultado=PQexec(conexion,lchrArrCadenaConsulta);
		
PQclear(resultado);
PQexec(conexion,"fetch all in con");
*pintNRegistros=PQntuples(resultado);
*pintNColumnas=PQnfields(resultado);
	for(i=0;i<*pintNRegistros;i++)
	{
	lchrPtrCveProveedor=PQgetvalue(resultado,i,0);
        lchrPtrCveProducto=PQgetvalue(resultado,i,1);
        lchrPtrDescripcion=PQgetvalue(resultado,i,2);
        lchrPtrFamilia= PQgetvalue(resultado,i,3);
        SISCOMQuitaEspacios(PDEPURACION lchrPtrCveProducto);
        SISCOMQuitaEspacios(PDEPURACION lchrPtrCveProveedor);
        SISCOMQuitaEspacios(PDEPURACION lchrPtrFamilia);
	//SISCOMQuitaEspacios(PDEPURACION lchrPtrDescripcion);	
	RNADCopiaDatosDelProducto(PDEPURACION lchrPtrCveProducto,
			          lchrPtrFamilia,
				  lchrPtrCveProveedor,
				  lchrPtrDescripcion,
				  &productos);
	RNADAsignaMemoriaLtaProducto(PDEPURACION &ltaproductosdat,productos,pstcErrorPtrReg);
	   if(!ltaproductosprim)
	    {
		ltaproductosprim=ltaproductosdat;
		*pstcLtaProductosPtrReg=ltaproductosdat;
	    }
	    else
	    {
		(*pstcLtaProductosPtrReg)->stcLtaProductosSig=ltaproductosdat;
		(*pstcLtaProductosPtrReg)=(*pstcLtaProductosPtrReg)->stcLtaProductosSig;
	    }

	}
	PQclear(resultado);
	PQexec(conexion,"end");
	PQclear(resultado);
	PQfinish(conexion);

	*pstcLtaProductosPtrReg=ltaproductosprim;
}
/*
int ADDllConsultasPostgreSQL(PARDEPURACION STRUCTDatosDeLaOperacion pstcDatosDeLaOperacionDat,STRUCTLtaProductos **pstcLtaProductosPtrReg,int *pintNRegistros,int *pintNColumnas,STRUCTError *pstcErrorPtrReg)
{
	PGconn *lPGconnPtrConexion=NULL;
	PGresult   *lPGresultPtrReg=NULL;
	STRUCTProductos lstcProductosReg;
	STRUCTLtaProductos *pstcLtaProductosPtrPrim=NULL,*pstcLtaProductosPtrDat=NULL;
	int lintI,lintJ;
	char *lchrPtrCveProducto;
	char *lchrPtrCveProveedor;
	char *lchrPtrFamilia;
	char *lchrPtrDescripcion;
#ifdef DEBUG
       strcat(PDEPURACION "\t");
       SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","ADDllConsultasPostgreSQL");
#endif
	POSTGRESQLConectate(PDEPURACION &lPGconnPtrConexion,pstcErrorPtrReg);
	POSTGRESQLEjecutaFuncion(PDEPURACION lPGconnPtrConexion,&lPGresultPtrReg,"begin",pstcErrorPtrReg);
        POSTGRESQLEjecutaFuncion(PDEPURACION lPGconnPtrConexion,&lPGresultPtrReg,
	"declare Con cursor for select a.chrCveProveedor,b.chrCveProducto,b.chrDscCorta,b.chrFamilia from productoyproveedor as a, productos as b where a.chrCveProducto=b.chrCveProducto  order by a.chrCveProducto",pstcErrorPtrReg);
//	PQclear(lPGresultPtrReg);
        POSTGRESQLEjecutaFuncion(PDEPURACION lPGconnPtrConexion,&lPGresultPtrReg,"fetch all in Con",pstcErrorPtrReg);
	//*pintNColumnas= PQnfields(lPGresultPtrReg);
	*pintNRegistros=PQntuples(lPGresultPtrReg);
	printf("\nLos registros %d\n",*pintNRegistros);
	for(lintI=0;lintI<*pintNRegistros;lintI++)
	{	
		
	lchrPtrCveProveedor=PQgetvalue(lPGresultPtrReg,lintI,0);
	lchrPtrCveProducto=PQgetvalue(lPGresultPtrReg,lintI,1);
	lchrPtrDescripcion=PQgetvalue(lPGresultPtrReg,lintI,2);
	lchrPtrFamilia= PQgetvalue(lPGresultPtrReg,lintI,3);
	SISCOMQuitaEspacios(PDEPURACION lchrPtrCveProducto);
	SISCOMQuitaEspacios(PDEPURACION lchrPtrCveProveedor);
	SISCOMQuitaEspacios(PDEPURACION lchrPtrFamilia);
//	SISCOMQuitaEspacios(PDEPURACION lchrPtrDescripcion);
	RNADCopiaDatosDelProducto(PDEPURACION lchrPtrCveProducto,
			          lchrPtrFamilia,
				  lchrPtrCveProveedor,
				  lchrPtrDescripcion,
				  &lstcProductosReg);
	
	RNADAsignaMemoriaLtaProducto(PDEPURACION &pstcLtaProductosPtrDat,lstcProductosReg,pstcErrorPtrReg);
	    if(!pstcLtaProductosPtrPrim)
	    {
		pstcLtaProductosPtrPrim=pstcLtaProductosPtrDat;
		*pstcLtaProductosPtrReg=pstcLtaProductosPtrDat;
	    }
	    else
	    {
		(*pstcLtaProductosPtrReg)->stcLtaProductosSig=pstcLtaProductosPtrDat;
		(*pstcLtaProductosPtrReg)=(*pstcLtaProductosPtrReg)->stcLtaProductosSig;
	    }	 
	}
	
//	PQclear(lPGresultPtrReg);
//	POSTGRESQLEjecutaFuncion(PDEPURACION lPGconnPtrConexion,&lPGresultPtrReg,"close Con",pstcErrorPtrReg);
//	PQclear(lPGresultPtrReg);
//	POSTGRESQLEjecutaFuncion(PDEPURACION lPGconnPtrConexion,&lPGresultPtrReg,"end",pstcErrorPtrReg);
	*pstcLtaProductosPtrReg=pstcLtaProductosPtrPrim;
//	PQfinish(lPGconnPtrConexion);	
}*/
