#include <stdio.h>
#include <RNADFuncionesComunesEZS.h>

int RNADAsignaMemoriaVentas(PARDEPURACION STRUCTVentas pstcVentasDat, STRUCTLtaVentas **pstcLtaVentasPtrReg, STRUCTError *pstcErrorPtrReg)
{
#ifdef DEBUG
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADAsignaMemoriaVentas");
#endif

 if ((*pstcLtaVentasPtrReg = (STRUCTLtaVentas *)malloc(sizeof(STRUCTLtaVentas))))
    {
     (*pstcLtaVentasPtrReg)->stcVentas = pstcVentasDat;
     (*pstcLtaVentasPtrReg)->stcLtaVentasPtrSig = NULL;
    }

}

int RNADGeneraListaVentas(PARDEPURACION int pintSocketCliente,int *pintPtrNRegistros,STRUCTLtaVentas **pstcLtaVentasPtrPrim,STRUCTError *pstcErrorPtrReg)
{
 STRUCTLtaVentas *lstcLtaVentasPtrDat = NULL;
 STRUCTVentas lstcVentasReg;
 char lchrArrNRegistros[10];
 int lintI;
#ifdef DEBUG
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADGeneraListaVentas");
#endif
 SISCOMLeeDatos(PDEPURACION pintSocketCliente, 8, lchrArrNRegistros, 0);
 lchrArrNRegistros[4] = 0;
 *pintPtrNRegistros = atoi(lchrArrNRegistros);
 for (lintI = 0; lintI < *pintPtrNRegistros; lintI++)
     {
      RNADObtenRegistroDeVentas(PDEPURACION pintSocketCliente, &lstcVentasReg, pstcErrorPtrReg);
      RNADCreaListaDeVentas(PDEPURACION lstcVentasReg, pstcLtaVentasPtrPrim, &lstcLtaVentasPtrDat, pstcErrorPtrReg);
     }
}

int RNADCreaListaDeVentas(PARDEPURACION STRUCTVentas pstcVentasDat, STRUCTLtaVentas **pstcLtaVentasPtrRegPrim, STRUCTLtaVentas **pstcLtaVentasPtrRegDat, STRUCTError *pstcErrorPtrReg)
{
STRUCTLtaVentas *lstcLtaVentasPtrDat=NULL;

#ifdef DEBUG
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADCreaListaDeVentas");
#endif
	RNADAsignaMemoriaVentas(PDEPURACION pstcVentasDat, &lstcLtaVentasPtrDat, pstcErrorPtrReg);
	if (!*pstcLtaVentasPtrRegPrim)
	   *pstcLtaVentasPtrRegDat = *pstcLtaVentasPtrRegPrim = lstcLtaVentasPtrDat;
	else
	   {
	    (*pstcLtaVentasPtrRegDat)->stcLtaVentasPtrSig = lstcLtaVentasPtrDat;
	    (*pstcLtaVentasPtrRegDat) = (*pstcLtaVentasPtrRegDat)->stcLtaVentasPtrSig;
	   }
}

int RNADFormaCadenaVentas(PARDEPURACION STRUCTLtaVentas *pstcLtaVentasPtrReg, char **pchrPtrCadenaReg, STRUCTError *pstcErrorPtrReg)
{

}

int RNADLlenaVentas(PARDEPURACION char *pchrPtrFechaVenta, char *pchrPtrCveVenta, char *pchrPtrCveProducto, char *pchrPtrCantidad, char *pchrPtrCveCliente, char *pchrPtrPUnitario, char *pchrPtrPTotal,char *pchrPtrNOrden, STRUCTVentas *pstcVentasPtrReg)
{
#ifdef DEBUG
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%000char*%000char*%000char*%000char*%000char*%","RNADLlenaVentas", pchrPtrCveProducto, pchrPtrCantidad, pchrPtrCveCliente, pchrPtrPUnitario, pchrPtrPTotal);
#endif

	strcpy(pstcVentasPtrReg->chrArrFechaVenta, pchrPtrFechaVenta);
	strcpy(pstcVentasPtrReg->chrArrCveVenta, pchrPtrCveVenta);
	strcpy(pstcVentasPtrReg->chrArrCveProducto, pchrPtrCveProducto);
	strcpy(pstcVentasPtrReg->chrArrCantidad, pchrPtrCantidad);
	strcpy(pstcVentasPtrReg->chrArrCveCliente, pchrPtrCveCliente);
	strcpy(pstcVentasPtrReg->chrArrPUnitario, pchrPtrPUnitario);
	strcpy(pstcVentasPtrReg->chrArrPTotal, pchrPtrPTotal);
	strcpy(pstcVentasPtrReg->chrArrNOrden, pchrPtrNOrden);

}

int RNADEnviaRegistrosDeVentas(PARDEPURACION int pintSocketCliente, int pintNRegistros, int pintNCampos, STRUCTLtaVentas *pstcLtaVentasPtrDat, STRUCTError *pstcErrorPtrReg)
{
int lintTam, lintPos = 0;
char lchrArrCadena[1000];
int i;

#ifdef DEBUG
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","RNADEnviaRegistrosDeVentas");
#endif

 sprintf(lchrArrCadena, "%04d%04d", pintNRegistros, pintNCampos);
 printf("\n\nCadena %s\n\n", lchrArrCadena);
 Write(pintSocketCliente, lchrArrCadena, strlen(lchrArrCadena));
 while (pstcLtaVentasPtrDat)
       {
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaVentasPtrDat->stcVentas.chrArrFechaVenta, 1, 1, &lintTam, lchrArrCadena + lintPos);
	lintPos += lintTam; 
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaVentasPtrDat->stcVentas.chrArrCveVenta, 2, 1, &lintTam, lchrArrCadena + lintPos);
	lintPos += lintTam; 
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaVentasPtrDat->stcVentas.chrArrCveProducto, 3, 1, &lintTam, lchrArrCadena + lintPos);
	lintPos += lintTam; 
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaVentasPtrDat->stcVentas.chrArrCantidad, 4, 1, &lintTam, lchrArrCadena + lintPos);
	lintPos += lintTam; 
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaVentasPtrDat->stcVentas.chrArrCveCliente, 5, 1, &lintTam, lchrArrCadena + lintPos);
	lintPos += lintTam; 
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaVentasPtrDat->stcVentas.chrArrPUnitario, 6, 1, &lintTam, lchrArrCadena + lintPos);
	lintPos += lintTam; 
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaVentasPtrDat->stcVentas.chrArrPTotal, 7, 1, &lintTam, lchrArrCadena + lintPos);
	lintPos += lintTam; 
	SISCOMFormaDatosProtocoloCHAR(PDEPURACION pstcLtaVentasPtrDat->stcVentas.chrArrNOrden, 8, 1, &lintTam, lchrArrCadena + lintPos);
	lintPos = 0;
	printf("\n***%s***\n",lchrArrCadena);
	Write(pintSocketCliente, lchrArrCadena, strlen(lchrArrCadena));
	pstcLtaVentasPtrDat = pstcLtaVentasPtrDat->stcLtaVentasPtrSig;
       }

}

int RNADObtenRegistroDeVentas(PARDEPURACION int pintSocketCliente, STRUCTVentas *pstcVentasPtrReg, STRUCTError *pstcErrorPtrReg)
{
 SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente, pstcVentasPtrReg->chrArrFechaVenta, NULL);
 SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente, pstcVentasPtrReg->chrArrCveVenta, NULL);
 SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente, pstcVentasPtrReg->chrArrCveProducto, NULL);
 SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente, pstcVentasPtrReg->chrArrCantidad, NULL);
 SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente, pstcVentasPtrReg->chrArrCveCliente, NULL);
 SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente, pstcVentasPtrReg->chrArrPUnitario, NULL);
 SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente, pstcVentasPtrReg->chrArrPTotal, NULL);
 SISCOMObtenDatoProtocoloCHAR(PDEPURACION pintSocketCliente, pstcVentasPtrReg->chrArrNOrden, NULL);

#ifdef DEBUG
SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%000char*%000char*%000char*%000char*%000char*%000char*%000char%","RNADObtenRegistroDeVentas",
	       	pstcVentasPtrReg->chrArrFechaVenta, pstcVentasPtrReg->chrArrCveVenta, pstcVentasPtrReg->chrArrCveProducto,
		pstcVentasPtrReg->chrArrCantidad, pstcVentasPtrReg->chrArrCveCliente, pstcVentasPtrReg->chrArrPUnitario,pstcVentasPtrReg->chrArrNOrden);
#endif
}
