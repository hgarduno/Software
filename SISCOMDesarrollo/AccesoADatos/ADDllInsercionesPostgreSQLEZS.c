#include <stdio.h>
#include <stdlib.h>
#include <ADDllInsercionesPostgreSQLEZS.h>
#include <string.h>
int POSTGRESQLInsertaVentas(PARDEPURACION STRUCTDatosDeLaOperacion pstcDatosDeLaOperacionDat, STRUCTLtaVentas *pstcLtaVentasPtrPrim, STRUCTError *pstcErrorPtrReg)
{
 PGconn     *lPGconnConexion;
 PGresult   *lPGresultRes;
 STRUCTError lstcErrorReg;
 char lchrArrCadSQL[1024];
 char lchrArrCadSQL1[1024];

#ifdef DEBUG
//	strcat(PDEPURACION "\t");
       SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%", "POSTGRESQLInsertaVentas");
#endif
// POSTGRESQLConectate(PDEPURACION &lPGconnConexion,pstcErrorPtrReg);
      lPGconnConexion=POSTGRESQLConectate(PDEPURACION pstcErrorPtrReg);
 
 while (pstcLtaVentasPtrPrim)
       {
	sprintf(lchrArrCadSQL,"insert into Venta(dtefechaventa, chrcveventa, chrcveproducto, intcantidad, chrcvecliente, numprcunitario, numprctotal) values('%s', '%s', '%s', %f, '%s', %.2f, %.2f)",
				   pstcLtaVentasPtrPrim->stcVentas.chrArrFechaVenta,
				   pstcLtaVentasPtrPrim->stcVentas.chrArrCveVenta,
				   pstcLtaVentasPtrPrim->stcVentas.chrArrCveProducto,
				   atof(pstcLtaVentasPtrPrim->stcVentas.chrArrCantidad),
				   pstcLtaVentasPtrPrim->stcVentas.chrArrCveCliente,
				   atof(pstcLtaVentasPtrPrim->stcVentas.chrArrPUnitario),
				   atof(pstcLtaVentasPtrPrim->stcVentas.chrArrPTotal));
	sprintf(lchrArrCadSQL1,"UPDATE preciosventaexistencia SET intexistencia = intexistencia - cast ( %s as numeric ) where chrCveProducto='%s'",pstcLtaVentasPtrPrim->stcVentas.chrArrCantidad,pstcLtaVentasPtrPrim->stcVentas.chrArrCveProducto);
	POSTGRESQLEjecutaFuncion(PDEPURACION lPGconnConexion, &lPGresultRes, lchrArrCadSQL1, pstcErrorPtrReg);
	POSTGRESQLEjecutaFuncion(PDEPURACION lPGconnConexion, &lPGresultRes, lchrArrCadSQL, pstcErrorPtrReg);
	POSTGRESQLActualizaInventarioXVentas(PDEPURACION lPGconnConexion, pstcLtaVentasPtrPrim->stcVentas, pstcErrorPtrReg);
	POSTGRESQLActualizaOrden(PDEPURACION lPGconnConexion, pstcLtaVentasPtrPrim->stcVentas, pstcErrorPtrReg);
	pstcLtaVentasPtrPrim = pstcLtaVentasPtrPrim->stcLtaVentasPtrSig;
       }
 PQfinish(lPGconnConexion);
}

int POSTGRESQLActualizaInventarioXVentas(PARDEPURACION PGconn *pPGconn, STRUCTVentas pstcVentasDat, STRUCTError *pstcErrorPtrReg)
{
 PGresult *lPGresult;
 char lchrArrCadenaSQL[512];
 
#ifdef DEBUG
//	strcat(PDEPURACION "\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","POSTGRESQLActualizaInventarioXVentas");
#endif

 sprintf(lchrArrCadenaSQL,"update inventario set intExistencia = ((select intExistencia from Inventario where chrCveProducto = '%s') - cast (%s as numeric )) where chrCveProducto = '%s'",
			 pstcVentasDat.chrArrCveProducto,
			 pstcVentasDat.chrArrCantidad,
			 pstcVentasDat.chrArrCveProducto);
 lPGresult = PQexec(pPGconn, lchrArrCadenaSQL);
 printf("La actualizacion es %s\n",lchrArrCadenaSQL);
/* if (!strcmp("0", (const char *)PQcmdTuples(lPGresult)))
    {
     sprintf(lchrArrCadenaSQL, "insert into Inventario(chrcveproducto, intexistencia, intexistenciamin) values('%s', %s, %s)",
			       pstcVentasDat.chrArrCveProducto, pstcVentasDat.chrArrCantidad, "4");
     POSTGRESQLEjecutaFuncion(PDEPURACION pPGconn,&lPGresult,lchrArrCadenaSQL,pstcErrorPtrReg);
    }*/
}
int POSTGRESQLActualizaOrden(PARDEPURACION PGconn *pPGconn,STRUCTVentas pstcVentasDat,STRUCTError *pstcErrorPtrReg)
{
 PGresult *lPGresult;
 char lchrArrCadenaSQL[512];
 char lchrArrRegreso[100];
 #ifdef DEBUG
//	strcat(PDEPURACION "\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","POSTGRESQLActualizaOrden");
#endif
 strncpy(lchrArrRegreso,pstcVentasDat.chrArrFechaVenta,10);
 lchrArrRegreso[10]=0;
 sprintf(lchrArrCadenaSQL,"insert into Orden(dteFecha,intNumOrden,chrCveVenta) values('%s', %s, '%s' )",lchrArrRegreso,pstcVentasDat.chrArrNOrden,pstcVentasDat.chrArrCveVenta);
 printf("La actualizacion de la orden es %s\n",lchrArrCadenaSQL);
 
#ifdef DEBUG
//	strcat(PDEPURACION "\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%000char*%","POSTGRESQLActualizaOrden",lchrArrCadenaSQL);
#endif
 	lPGresult = PQexec(pPGconn, lchrArrCadenaSQL);
	POSTGRESQLEvaluaEstatus(PDEPURACION pPGconn,lPGresult,pstcErrorPtrReg);
}
