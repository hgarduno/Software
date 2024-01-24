#include <RNVentas.h>
#include <RNVarios.h>

const char *ObtenIdExpendioVenta(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Venta_IdExpendio];
}

const char *ObtenProductoVenta(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Venta_Producto];
}

const char *ObtenCantidadVenta(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Venta_Cantidad];
}

const char *ObtenImporteVenta(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Venta_Importe];
}
const char *ObtenImporteOrdenVenta(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Venta_ImporteOrden];
}
const char *ObtenPrecioVenta(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Venta_Precio];
}

const char *ObtenVendedorVenta(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Venta_Vendedor];
}

const char *ObtenClienteVenta(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Venta_Cliente];
}

const char *ObtenEdoRegistroVenta(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RN_Venta_EdoRegistro];
}
const char *ConsultaDatosDelVendedor(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
					const char *pchrPtrFirma)
{
char lchrArrConsulta[256];
StcLtaRegComSISCOM *lSLRCSisDatReg;
	sprintf(lchrArrConsulta,
		"select	*	\
		 from	firmas	\
		 where firma='%s'",
		pchrPtrFirma);
	
	lSLRCSisDatReg=ConsultaGenericaALaBaseElFresno(pintPtoComAD,
					       pchrPtrDirIpSvr,
					       lchrArrConsulta);
	return lSLRCSisDatReg->chrPtrRegistro[1];

}
StcLtaRegComSISCOM *RegistraVenta(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     StcLtaRegComSISCOM *pSLRCSisDat,
				     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0,
		   *lSLRCSisDatRegreso=0;
int lintContador;
int lintNRegistros=0;
long llngIdFamilia;	
char lchrArrBuffer[256];
const char *lchrPtrIdExpendio,
	   *lchrPtrIdCliente,
	   *lchrPtrIdVendedor,
	   *lchrPtrImporteOrden;
long llngIdVenta;
char lchrArrFechaHoraHoy[25];
*pintPtrNRegistros=0;

	SISCOMImprimeContenidoCom2(stdout,
				   "RegistraVenta",
				   '|',
				   '\n',
				    pSLRCSisDat);
	for(lintContador=0;
	    pSLRCSisDat;
	    lintContador++,
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
	{
	   if(!lintContador)
	   { lchrPtrIdExpendio=ObtenIdExpendioVenta(pSLRCSisDat->chrPtrRegistro);
	     lchrPtrIdCliente=ObtenClienteVenta(pSLRCSisDat->chrPtrRegistro);
	     lchrPtrIdVendedor=ObtenVendedorVenta(pSLRCSisDat->chrPtrRegistro);
	     lchrPtrImporteOrden=ObtenImporteOrdenVenta(pSLRCSisDat->chrPtrRegistro);
	     llngIdVenta=SISCOMObtenNumeroUnico();
	     SISCOMObtenFechaHoraActualAAAADDMM(lchrArrFechaHoraHoy);
	    SISCOMAnexaRegistroFormateandoParaEnvio(
		&lSLRCSisDatPrim,
		&lSLRCSisDatActual,
		&lintNRegistros,
		lchrArrBuffer,
		"insert into ImporteOrden values(%ld,%s);",
		llngIdVenta,
		ObtenImporteOrdenVenta(pSLRCSisDat->chrPtrRegistro));
 
	   }
	   else
	   {
	   SISCOMAnexaRegistroFormateandoParaEnvio(
		&lSLRCSisDatPrim,
		&lSLRCSisDatActual,
		&lintNRegistros,
		lchrArrBuffer,
		"insert into ventas values(%s,%ld,'%s','%s',%s,%s,%s,%s,%s);",
		lchrPtrIdExpendio,
		llngIdVenta,
		lchrArrFechaHoraHoy,
		ObtenProductoVenta(pSLRCSisDat->chrPtrRegistro),
		ObtenCantidadVenta(pSLRCSisDat->chrPtrRegistro),
		ObtenImporteVenta(pSLRCSisDat->chrPtrRegistro),
		ObtenPrecioVenta(pSLRCSisDat->chrPtrRegistro),
		lchrPtrIdVendedor,
		lchrPtrIdCliente);
	    SISCOMAnexaRegistroFormateandoParaEnvio(
		&lSLRCSisDatPrim,
		&lSLRCSisDatActual,
		&lintNRegistros,
		lchrArrBuffer,
		"update existencias set Existencia=Existencia-%s	\
		 where CveProducto='%s' and	\
		       IdExpendio=%s",
		 ObtenCantidadVenta(pSLRCSisDat->chrPtrRegistro),
		 ObtenProductoVenta(pSLRCSisDat->chrPtrRegistro),
		 lchrPtrIdExpendio);
		
	   }
		
		
		
	
	}
	SISCOMImprimeContenidoCom2(stdout,
				   "RegistraVenta",
				   '|',
				   '\n',
				    lSLRCSisDatPrim);
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADAltaGenericaElFresno.so",
                                      "ADComandosAlta",
                                      lintNRegistros,
                                      lSLRCSisDatPrim,
                                      &lSLRCSisDatRegreso,
                                      pintPtrNRegistros);	
	return GeneraRespuestaVenta(pintPtrNRegistros);
}
StcLtaRegComSISCOM *ConsultaVenta(int pintPtoComAD,
				     const char *pchrPtrDirIpSvr,
				     StcLtaRegComSISCOM *pSLRCSisDat,
				     int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0,
		   *lSLRCSisDatRegreso=0;
int lintContador;
int lintNRegistros=0;
long llngIdFamilia;	
char lchrArrBuffer[256];
	SISCOMAnexaRegistroFormateandoParaEnvio(
                        &lSLRCSisDatPrim,
                        &lSLRCSisDatActual,
                        &lintNRegistros,
                        lchrArrBuffer,
                        "select * from familias");
		
	SISCOMEnviaInformacionAlSvrAD(pintPtoComAD,
                                      pchrPtrDirIpSvr,
                                      "hgarduno",
                                      "hgarduno",
                                      "libADConsultaGenericaElFresno.so",
                                      "ADConsultas",
                                      lintNRegistros,
                                      lSLRCSisDatPrim,
                                      &lSLRCSisDatRegreso,
                                      pintPtrNRegistros);	
	return lSLRCSisDatRegreso;
}
StcLtaRegComSISCOM *GeneraRespuestaVenta(int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatPrim=0,
		   *lSLRCSisDatActual=0;

char lchrArrBuffer[256];
	*pintPtrNRegistros=0;
	SISCOMAnexaRegistroFormateandoParaEnvio(&lSLRCSisDatPrim,
                                               &lSLRCSisDatActual,
                                               pintPtrNRegistros,
                                               lchrArrBuffer,
                                               "%ld",
                                               0);

	return lSLRCSisDatPrim;
}
