#include <RNCompras.h>
#include <stdlib.h>

const char *RN_Compras_ObtenFecha(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[2];
}

const char *RN_Compras_ObtenCveProducto(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[3];
}
const char *RN_Compras_ObtenCantidad(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[4];
}
const char *RN_Compras_ObtenImporte(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[5];
}

const char *RN_Compras_ObtenProveedor(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[6][0] ? 
	       pSLRCSisDat->chrPtrRegistro[6]:"0" ;
}

const char *RN_Compras_ObtenConProveedor(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[7][0] ? 
	       pSLRCSisDat->chrPtrRegistro[7] :
	       "0";
}

const char *RN_Compras_ObtenResponsable(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[8][0] ?
		pSLRCSisDat->chrPtrRegistro[8] :
		"0";
}

const char *RN_Compras_ObtenIdExpendio(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[9];
}

const char *RN_Compras_ObtenFormaPago(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[10];
}

const char *RN_Compras_ObtenNumFactura(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[11];
}

const char *RN_Compras_ObtenFechaPago(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[12];
}

const char *RN_Compras_ObtenPrecio(StcLtaRegComSISCOM *pSLRCSisDat)
{
	return pSLRCSisDat->chrPtrRegistro[13];
}








StcLtaRegComSISCOM *OperacionesCompras(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     StcLtaRegComSISCOM *pSLRCSisDat,
				     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisRegreso=0;
StcOperacionesAlSistemaSISCOM lSOASistemaSiscom[]=
		{{
		  EsRegistroCompras,
		  RegistraCompras,
		  RespuestaGeneralCompras
		  }
		};
	SISCOMImprimeContenidoCom2(stdout,
				  "OperacionesCompras",
				  '|',
				  '\n',
				  pSLRCSisDat);
	SISCOMSeleccionaYEjecutaOperacionAlSistema(pintPtoComAD,
						   pchrPtrDirIpSvr,
						   lSOASistemaSiscom,
						   1,
						   pSLRCSisDat,
						   &lSLRCSisRegreso,
						   pintPtrNRegistros);
	
	return lSLRCSisRegreso;

}

int EsRegistroCompras(char **pchrPtrParametros,
			char *pchrPtrConsulta,
			StcLtaRegComSISCOM *pSLRCSisDatEntrada,
			StcLtaRegComSISCOM **pSLRCSisDatSalida,
			int *pintPtrNumRegSalida)
{
StcLtaRegComSISCOM *lSLRCSisActual=0;
char lchrArrBuffer[512];	
char lchrArrImporte[20];
char lchrArrFechaHoy[25];
float lfltImporteTotal=0.0,
      lfltImporte;
char *lchrPtrFormaPago,
     *lchrPtrFechaPago,
     *lchrPtrNumFactura;
	printf("EsRegistroCompras:{%s}\n",pchrPtrParametros[0]);
	if(!strcmp(pchrPtrParametros[0],
		   "RegistrarCompras"))
	{
	   SISCOMObtenFechaHoraActualAAAADDMM(lchrArrFechaHoy);
	   *pintPtrNumRegSalida=0;
	   for(;
		pSLRCSisDatEntrada;
		pSLRCSisDatEntrada=pSLRCSisDatEntrada->LSRCSISCOMPtrSig)
	   {
	
	     if(!SISCOMEsRegistroVacio(pSLRCSisDatEntrada->chrPtrRegistro))
	     {
	     lchrPtrFormaPago=RN_Compras_ObtenFormaPago(pSLRCSisDatEntrada);
	     lchrPtrFechaPago=RN_Compras_ObtenFechaPago(pSLRCSisDatEntrada);
	     lchrPtrNumFactura=RN_Compras_ObtenNumFactura(pSLRCSisDatEntrada);
	     sprintf(lchrArrImporte,
		     "%.2f",
		     (lfltImporte=atof(RN_Compras_ObtenCantidad(pSLRCSisDatEntrada))*
		     atof(RN_Compras_ObtenPrecio(pSLRCSisDatEntrada)))); 
		lfltImporteTotal+=lfltImporte;
	     SISCOMAnexaRegistroFormateandoParaEnvio(
			pSLRCSisDatSalida,
			&lSLRCSisActual,
			pintPtrNumRegSalida,
			lchrArrBuffer,
			"insert into Compras values('%s','%s',%s,%s,%s,%s,%s,'%s','%s',%s,%s);",
			lchrArrFechaHoy,
			RN_Compras_ObtenCveProducto(pSLRCSisDatEntrada),
			RN_Compras_ObtenCantidad(pSLRCSisDatEntrada),
			lchrArrImporte,
			RN_Compras_ObtenProveedor(pSLRCSisDatEntrada),
			RN_Compras_ObtenConProveedor(pSLRCSisDatEntrada),
			RN_Compras_ObtenResponsable(pSLRCSisDatEntrada),
			RN_Compras_ObtenIdExpendio(pSLRCSisDatEntrada),
			RN_Compras_ObtenFormaPago(pSLRCSisDatEntrada),
			RN_Compras_ObtenNumFactura(pSLRCSisDatEntrada),
			RN_Compras_ObtenPrecio(pSLRCSisDatEntrada));
		SISCOMAnexaRegistroFormateandoParaEnvio(
			pSLRCSisDatSalida,
			&lSLRCSisActual,
			pintPtrNumRegSalida,
			lchrArrBuffer,
			"insert into Existencias values('%s',%s,%s);",
			RN_Compras_ObtenCveProducto(pSLRCSisDatEntrada),
			"0",
			RN_Compras_ObtenIdExpendio(pSLRCSisDatEntrada));
		SISCOMAnexaRegistroFormateandoParaEnvio(
			pSLRCSisDatSalida,
			&lSLRCSisActual,
			pintPtrNumRegSalida,
			lchrArrBuffer,
			"update existencias			\
			 	set Existencia=Existencia+%s	\
			 where CveProducto='%s' and 		\
			       idExpendio=%s",
			RN_Compras_ObtenCantidad(pSLRCSisDatEntrada),
			RN_Compras_ObtenCveProducto(pSLRCSisDatEntrada),
			RN_Compras_ObtenIdExpendio(pSLRCSisDatEntrada) );
			 
	     }
	       if(!strcmp(lchrPtrFormaPago,"Credito") &&
		  !SISCOMEsRegistroVacio(pSLRCSisDatEntrada->chrPtrRegistro))
	        SISCOMAnexaRegistroFormateandoParaEnvio(
			pSLRCSisDatSalida,
			&lSLRCSisActual,
			pintPtrNumRegSalida,
			lchrArrBuffer,
			"insert into CuentasPorPagar values('%s','%s',%s);",
			lchrPtrNumFactura,
			lchrPtrFechaPago,
			SISCOMNumeroACadena(lfltImporteTotal));
		         	
	   }
	 return 1;
	}
	else
	return 0;
}
void RegistraCompras(int pintPtoComAD,
			const char *pchrPtrDirIpSvr,
			const char *pchrPtrConsulta,
			StcLtaRegComSISCOM *pSLRCSisDatEntrada,
			int pintNRegistros,
			StcLtaRegComSISCOM **pSLRCSisDatSalida,
			int *pintPtrNRegSalida)
{

	
	SISCOMImprimeContenidoCom2(stdout,
				   "RegistraCompras",
				  '|',
				  '\n',
				   pSLRCSisDatEntrada);
	
	  SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
			  		pchrPtrDirIpSvr,
					"hgarduno",
					"hgarduno",
					"libADAltaGenericaElFresno.so",
					"ADComandosAlta",
					pintNRegistros,
					pSLRCSisDatEntrada,
					pSLRCSisDatSalida,
					pintPtrNRegSalida);
}
void RespuestaGeneralCompras(int pintPtoComAD,
				const char *pchrPtrDirIpSvr,
				int pintNRegEntrada,
				StcLtaRegComSISCOM *pSLRCSisDatEntrad,
				StcLtaRegComSISCOM **pSLRCSisDatSalida,
				int *pintPtrNDatSalida)
{



}

