#include <RNCotizaciones.h>
#include <RNVarios.h>
#include <stdlib.h>

const char *ObtenCliente(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RNCotizaciones_Cliente];
}

const char *ObtenProductoCotizacion(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RNCotizaciones_Producto];
}

const char *ObtenCantidad(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RNCotizaciones_Cantidad];
}
const char *ObtenNmbTipoPrecioCotizacion(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RNCotizaciones_NmbTipoPrecio];
}
const char *ObtenIdExpendio(char **pchrPtrRegistro)
{
	return pchrPtrRegistro[RNCotizaciones_IdExpendio];
}
const char *RNCotizacionesObtenPrecioVenta(StcLtaRegComSISCOM *pSLRCSisDatCom)
{
	return pSLRCSisDatCom->chrPtrRegistro[6];
}
void FormaCadenaDatosParaCotizar(const StcLtaRegComSISCOM *pSLRCSisDatCom,
				 char *pchrPtrCadena)
{
char lchrArrCondicion[128];
	sprintf(pchrPtrCadena,
		"select	a.CveProducto,							\
			b.Existencia,							\
			c.Precio,							\
			d.*  								\
		from	 Productos as a 						\
			 left outer join existencias as b using(CveProducto) 	\
			 inner join Precios as c using(CveProducto) 			\
			 inner join TipoPrecio as d using(NmbTipoPrecio)		\
		where	 IdPersona='%s' and						\
			 NmbTipoPrecio='%s' and						\
			 b.idExpendio=%s    and						\
			 CveProducto in(",
		ObtenCliente(pSLRCSisDatCom->chrPtrRegistro),
		ObtenNmbTipoPrecioCotizacion(pSLRCSisDatCom->chrPtrRegistro),
		ObtenIdExpendio(pSLRCSisDatCom->chrPtrRegistro));


	
	for(	;
		pSLRCSisDatCom;
	    	pSLRCSisDatCom=pSLRCSisDatCom->LSRCSISCOMPtrSig)
	{
		if(!pSLRCSisDatCom->LSRCSISCOMPtrSig)
		 sprintf(lchrArrCondicion,
			 "'%s');",
			ObtenProductoCotizacion(pSLRCSisDatCom->chrPtrRegistro));
		else
		sprintf(lchrArrCondicion,
			"'%s',",
			ObtenProductoCotizacion(pSLRCSisDatCom->chrPtrRegistro));
				
		strcat(pchrPtrCadena,lchrArrCondicion);
	}

}
void ObtenDatosParaCotizar(int pintPtoComAD,
			   const char *pchrPtrDirIpSvr,
			   StcLtaRegComSISCOM *pSLRCSisDat,
			   StcLtaRegComSISCOM **pSLRCSisDatReg)
{
char lchrArrCadCotizacion[4196];
	FormaCadenaDatosParaCotizar(pSLRCSisDat,lchrArrCadCotizacion);
	*pSLRCSisDatReg=ConsultaGenericaALaBaseElFresno(pintPtoComAD,
					pchrPtrDirIpSvr,
					lchrArrCadCotizacion);
}
const char *ObtenPrecioAlQueSeVende(StcLtaRegComSISCOM *pSLRCSisDatCom,
			     StcLtaRegComSISCOM *pSLRCSisCotizacion)
{
const char *lchrPtrPrecioVenta;
	if((lchrPtrPrecioVenta=RNCotizacionesObtenPrecioVenta(pSLRCSisDatCom))[0])
	 return lchrPtrPrecioVenta;
	else
	return pSLRCSisCotizacion->chrPtrRegistro[2];


}
StcLtaRegComSISCOM *FormaRespuestaCotizacion(const StcLtaRegComSISCOM *pSLRCSisDat,
					     const StcLtaRegComSISCOM *pSLRCSisDatPCotizacion,
					     int *pintPtrNRegistros)
{
const StcLtaRegComSISCOM *lSLRCSisDatPCotizar;
StcLtaRegComSISCOM *lSLRCSisPrimRespuesta=0,
		   *lSLRCSisActualRespuesta=0;
float lfltImporte,
      lfltImporteOrden=0.0;

	*pintPtrNRegistros=0;
 	for(;
	    pSLRCSisDat;
	    pSLRCSisDat=pSLRCSisDat->LSRCSISCOMPtrSig)
	  for(lSLRCSisDatPCotizar=pSLRCSisDatPCotizacion;
	      lSLRCSisDatPCotizar;
	      lSLRCSisDatPCotizar=lSLRCSisDatPCotizar->LSRCSISCOMPtrSig)
	 {
	    if(!strcmp(ObtenProductoCotizacion(pSLRCSisDat->chrPtrRegistro),
					       lSLRCSisDatPCotizar->chrPtrRegistro[0]))
	    {
	    	printf("FormaRespuestaCotizacion:Cantidad %s ? Existencia %s\n",
			pSLRCSisDat->chrPtrRegistro[3],
			lSLRCSisDatPCotizar->chrPtrRegistro[1]);	
		lfltImporte=atof(ObtenCantidad(pSLRCSisDat->chrPtrRegistro))*
			    /*
			    atof(lSLRCSisDatPCotizar->chrPtrRegistro[2]);	
			    */
			    atof(ObtenPrecioAlQueSeVende(pSLRCSisDat,lSLRCSisDatPCotizar));
		lfltImporteOrden+=lfltImporte;
		SISCOMAnexaRegistroLEnvio(&lSLRCSisPrimRespuesta,
					  &lSLRCSisActualRespuesta,
					  8,
					  "%s%s%s%f%s%s%s%s",
					  ObtenProductoCotizacion(pSLRCSisDat->chrPtrRegistro),
					  ObtenCantidad(pSLRCSisDat->chrPtrRegistro),
					  lSLRCSisDatPCotizar->chrPtrRegistro[1],
					  lfltImporte,
					  lSLRCSisDatPCotizar->chrPtrRegistro[2],
					  lSLRCSisDatPCotizar->chrPtrRegistro[3],
					  lSLRCSisDatPCotizar->chrPtrRegistro[4],
					  (atoi(pSLRCSisDat->chrPtrRegistro[3])<=
					   atoi(lSLRCSisDatPCotizar->chrPtrRegistro[1]))?
					   "Si" : "No");
					   
		(*pintPtrNRegistros)++;
	    }
			
	 }
		
		SISCOMAnexaRegistroLEnvio(&lSLRCSisPrimRespuesta,
					  &lSLRCSisActualRespuesta,
					  7,
					  "%s%s%s%f%s%s%s",
					  "TotalCotizacion",
					  "",
					  "",
					  lfltImporteOrden,
					  "",
					  "",
					  ""); 
		(*pintPtrNRegistros)++;
	SISCOMImprimeContenidoCom2(stdout,
			 	   "ResultadoCotizacion",
				   '|',
				   '\n',
				   lSLRCSisPrimRespuesta);
	return lSLRCSisPrimRespuesta;

}
StcLtaRegComSISCOM *EjecutaCotizacion(int pintPtoComAD,
		                      const char *pchrPtrDirIp,
				      StcLtaRegComSISCOM *pSLRCSisDat,
				      int *pintPtrNRegistros)
{
StcLtaRegComSISCOM *lSLRCSisDatParaCotizar=0;
		SISCOMImprimeContenidoCom2(stdout,
					 "EjecutaCotizacion",
					 '|',
					 '\n',
					 pSLRCSisDat);
		ObtenDatosParaCotizar(pintPtoComAD,
				      pchrPtrDirIp,
				      pSLRCSisDat,
				      &lSLRCSisDatParaCotizar);
		
		SISCOMImprimeContenidoCom2(stdout,
					 "EjecutaCotizacion:DatosParaCotizar",
					 '|',
					 '\n',
					 lSLRCSisDatParaCotizar);
		return FormaRespuestaCotizacion(pSLRCSisDat,
						lSLRCSisDatParaCotizar,
						pintPtrNRegistros);
}
