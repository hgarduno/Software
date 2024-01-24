#include <stdio.h>
#include <stdlib.h>
#include <ADDllInsercionesPostgreSQL.h>
#include <ADFuncionesComunesPostgreSQL.h>
int POSTGRESQLInsertaProductos(PARDEPURACION STRUCTDatosDeLaOperacion pstcDatosDeLaOperacionDat,STRUCTLtaProductos *pstcLtaProductosPtrDat,STRUCTLtaErrorAltaProductos **pstcLtaErrorAltaProductosPtrReg)
{
PGconn     *lPGconnConexion=NULL;
PGresult   *lPGresultRes=NULL;
STRUCTError lstcErrorReg;
STRUCTLtaErrorAltaProductos *lstcLtaErrorAltaProductosPtrPrim=NULL;
char lchrArrCadena[1024];
#ifdef DEBUG
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","POSTGRESQLInsertaProductos");
#endif
lPGconnConexion=POSTGRESQLConectate(PDEPURACION &lstcErrorReg);
	   	while(pstcLtaProductosPtrDat)
	{
	  sprintf(lchrArrCadena,"insert into Productos(chrCveProducto,chrDscCorta,chrFamilia) values('%s','%s','%s')",pstcLtaProductosPtrDat->stcProductosDat.chrArrClaveProd,
						   pstcLtaProductosPtrDat->stcProductosDat.chrArrDescProd,
						   pstcLtaProductosPtrDat->stcProductosDat.chrArrNomDelProducto);
	   POSTGRESQLEjecutaFuncion(PDEPURACION lPGconnConexion,&lPGresultRes,lchrArrCadena,&lstcErrorReg); 
	   
	   if(!POSTGRESQLEvaluaEstatus(PDEPURACION lPGconnConexion,lPGresultRes,&lstcErrorReg))
	   {
	   sprintf(lchrArrCadena,"insert into ProductoYProveedor(chrCveProducto,chrCveProveedor) values('%s','%s')",
			   			   pstcLtaProductosPtrDat->stcProductosDat.chrArrClaveProd,
			      			   pstcLtaProductosPtrDat->stcProductosDat.chrArrClaveProv);
	   POSTGRESQLEjecutaFuncion(PDEPURACION lPGconnConexion,&lPGresultRes,lchrArrCadena,&lstcErrorReg); 
	   POSTGRESQLEvaluaEstatus(PDEPURACION lPGconnConexion,lPGresultRes,&lstcErrorReg);
	   }
	   else
	 	printf("POSTGRESQLInsertaProductos:%s\n",lchrArrCadena);
	   pstcLtaProductosPtrDat=pstcLtaProductosPtrDat->stcLtaProductosSig;
	}
PQfinish(lPGconnConexion);
*pstcLtaErrorAltaProductosPtrReg=lstcLtaErrorAltaProductosPtrPrim;
}
int POSTGRESQLInsertaCompras(PARDEPURACION STRUCTDatosDeLaOperacion pstcDatosDeLaOperacionDat,STRUCTLtaCompras *pstcLtaComprasPtrPrim,STRUCTLtaCompras **pstcLtaComprasPtrRegPrim,int *pintPtrNRechazados)
{
PGconn     *lPGconnConexion;
PGresult   *lPGresultRes;
STRUCTLtaCompras *lstcLtaComprasPtrPrim=0;
STRUCTLtaCompras *lstcLtaComprasPtrDat=0;
STRUCTError lstcErrorReg;
STRUCTError *pstcErrorPtrReg=&lstcErrorReg;
char lchrArrCadSQL[1024];
#ifdef DEBUG
	    //    strcat(PDEPURACION "\t");
            SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","POSTGRESQLInsertaCompras");
#endif
lPGconnConexion=POSTGRESQLConectate(PDEPURACION pstcErrorPtrReg);
*pintPtrNRechazados=0;
			while(pstcLtaComprasPtrPrim)
			{
			   sprintf(lchrArrCadSQL,"insert into Compra(dtefechacompra,chrcveproducto,chrcveproveedor,intcantidad,numprccompra,numprcventa,numprcmayoreo,chrcvefrmpago,chrcvecontacto) values('%s','%s','%s',%s,%s,%s,%s,'%s','%s')",
			   pstcLtaComprasPtrPrim->stcCompras.chrArrFechaCompra,
			   pstcLtaComprasPtrPrim->stcCompras.chrArrCveProducto,
			   pstcLtaComprasPtrPrim->stcCompras.chrArrCveProveedor,
			   (pstcLtaComprasPtrPrim->stcCompras.chrArrCantidad),
			   (pstcLtaComprasPtrPrim->stcCompras.chrArrPCompra),
			   (pstcLtaComprasPtrPrim->stcCompras.chrArrPVenta),
			   (pstcLtaComprasPtrPrim->stcCompras.chrArrPMayoreo),
			   pstcLtaComprasPtrPrim->stcCompras.chrArrFormaDePago,
			   pstcLtaComprasPtrPrim->stcCompras.chrArrCveVendedor);
			   if(POSTGRESQLEjecutaFuncion(PDEPURACION lPGconnConexion,&lPGresultRes,lchrArrCadSQL,pstcErrorPtrReg))
			   { 	  
				  strcpy(pstcLtaComprasPtrPrim->stcCompras.chrArrExistencia,pstcErrorPtrReg->chrErrorLogico);
				  RNADCreaListaDeCompras(PDEPURACION pstcLtaComprasPtrPrim->stcCompras,&lstcLtaComprasPtrPrim,&lstcLtaComprasPtrDat,pstcErrorPtrReg);
				  (*pintPtrNRechazados)++;
				  printf("Se genero un error *******************************************\n");
			   }
			   else
                           POSTGRESQLActualizaInventarioXCompras(PDEPURACION lPGconnConexion,pstcLtaComprasPtrPrim->stcCompras,pstcErrorPtrReg);
			   pstcLtaComprasPtrPrim=pstcLtaComprasPtrPrim->stcLtaComprasPtrSig;
			}
PQfinish(lPGconnConexion);
*pstcLtaComprasPtrRegPrim=lstcLtaComprasPtrPrim;
}
int POSTGRESQLActualizaInventarioXCompras(PARDEPURACION PGconn *pPGconn,STRUCTCompras pstcComprasDat,STRUCTError *pstcErrorPtrReg)
{
char lchrArrCadenaSQL[512];
PGresult *lPGresult;
const char *lchrPtrRegreso;
#ifdef DEBUG
//    strcat(PDEPURACION "\t");
                SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","POSTGRESQLActualizaInventarioXCompras");
#endif
		  sprintf(lchrArrCadenaSQL,"update inventario set intExistencia =intExistencia + cast ( %s  as numeric ) where chrCveProducto='%s'",pstcComprasDat.chrArrCantidad,pstcComprasDat.chrArrCveProducto,pstcComprasDat.chrArrCveProducto);
		  printf("La cadena de actualizacion es 88888888888888888888888888888 %s\n",lchrArrCadenaSQL);
		  lPGresult=PQexec(pPGconn,lchrArrCadenaSQL);
		  if(PQresultStatus(lPGresult)!=PGRES_COMMAND_OK)
		  {
			printf("%s\n",lchrArrCadenaSQL);  
			printf("%s\n",PQerrorMessage(pPGconn));
			
		  }
		  lchrPtrRegreso=PQcmdTuples(lPGresult);
		 if(lchrPtrRegreso[0]=='0')
	        {
			sprintf(lchrArrCadenaSQL,"insert into Inventario(chrcveproducto,intexistencia,intexistenciamin)\
						  values('%s',%s,%s)",
					          pstcComprasDat.chrArrCveProducto,pstcComprasDat.chrArrCantidad,"4");
			POSTGRESQLEjecutaFuncion(PDEPURACION pPGconn,&lPGresult,lchrArrCadenaSQL,pstcErrorPtrReg); 
	        }

		
}
