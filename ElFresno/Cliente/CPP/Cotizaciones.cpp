#include <Cotizaciones.h>
#include <CQSiscomCom.h>

/*
 *   Se de integrar a esta clase un campo para el NmbTipoPrecio, de cada
 *   producto para que se pueda realizar la cotizacion, con lo que la
 *   clase que se encarga de enviar la cotizacion ya no tomara como argumento
 *   este dato, sino lo tomara de cada producto para cotizar
 */

ProductoCotizacion::ProductoCotizacion(Producto *pProducto,
					 const char *pchrPtrCantidad,
					 const char *pchrPtrExistencia,
					 const char *pchrPtrImporte,
					 const char *pchrPtrSePuedeVender):
			P_Producto(pProducto),
			chrPtrCantidad(pchrPtrCantidad),
			chrPtrExistencia(pchrPtrExistencia),
			chrPtrImporte(pchrPtrImporte),
			chrPtrSePuedeVender(pchrPtrSePuedeVender)
{

}
const char *ProductoCotizacion::ObtenCantidad()
{
	return chrPtrCantidad;

}
const char *ProductoCotizacion::ObtenExistencia()
{
	return chrPtrExistencia;

}
const char *ProductoCotizacion::ObtenImporte()
{
	return chrPtrImporte;

}
const char *ProductoCotizacion::ObtenSePuedeVender()
{
	return chrPtrSePuedeVender;

}
Producto *ProductoCotizacion::ObtenProducto()
{
	return P_Producto;
}
void ProductoCotizacion::PonCantidad(const char *pchrPtrCantidad)
{
	chrPtrCantidad=pchrPtrCantidad;
}
void ProductoCotizacion::PonExistencia(const char *pchrPtrExistencia)
{
	chrPtrExistencia=pchrPtrExistencia;
}
void ProductoCotizacion::PonImporte(const char *pchrPtrImporte)
{
	chrPtrImporte=pchrPtrImporte;
}
void ProductoCotizacion::PonSePuedeVender(const char *pchrPtrSePuedeVender)
{
	chrPtrSePuedeVender=pchrPtrSePuedeVender;
}
CQProductosCotizacion::CQProductosCotizacion()
{

}
CQProductosCotizacion::~CQProductosCotizacion()
{
	printf("CQProductosCotizacion::~CQProductosCotizacion(%d)\n",count());
}
const char *CQProductosCotizacion::ObtenImporteTotal()
{
	return chrPtrImporteTotal;
}
void CQProductosCotizacion::PonImporteTotal(const char *pchrPtrImporteTotal)
{
	chrPtrImporteTotal=pchrPtrImporteTotal;
}
ProductoCotizacion *CQProductosCotizacion::operator[](const char *pchrPtrCveProducto)
{
ProductoCotizacion *lP_ProductoCot;

		for(lP_ProductoCot=first();
		    lP_ProductoCot;	
		    lP_ProductoCot=next())
		if(!strcmp(lP_ProductoCot->ObtenProducto()->ObtenClave(),
			   pchrPtrCveProducto))
		 return lP_ProductoCot;

	return 0;


}
CQCtrCotizacion::CQCtrCotizacion(CSISCOMDatComunicaciones *pCSisDatCom,
				 CQCtrCotizacion::CtrCotizacion pCQCOperacion,
				 const char *pchrPtrIdCliente,
				 const char *pchrPtrNmbTipoPrecio,
				 const char *pchrPtrExpendio,
				 CQProductosCotizacion *pCQPCotizacion):
		CSisDatCom(pCSisDatCom),
		chrPtrParametrosCotizacion("%s%s%s%s%s%s%s"),
		intNumParametrosCotizacion(7)
{
	switch(pCQCOperacion)
	{
		case CQCtrCotizacion::Cotiza:
			EjecutaCotizacion(pchrPtrIdCliente,
					  pchrPtrNmbTipoPrecio,
					  pchrPtrExpendio,
					  pCQPCotizacion);
			AsignaRespuestaCotizacion(pCQPCotizacion);
		break;
	}
}
const char *CQCtrCotizacion::ObtenPrecio(ProductoCotizacion *pPCotizacion)
{
CQPrecios lCQPrecios=pPCotizacion->ObtenProducto()->ObtenPrecios();
Precio *lPPrecio=lCQPrecios.at(0);
	if(lPPrecio)
	  return lPPrecio->ObtenPrecio();
	else
	return  "";
}
void CQCtrCotizacion::EjecutaCotizacion(const char *pchrPtrIdCliente,
					const char *pchrPtrNmbTipoPrecio,
					const char *pchrPtrExpendio,
				        CQProductosCotizacion *pCQPCotizacion)
{
ProductoCotizacion *lP_PCotizacion;

CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                            "libRNSistemaElFresno.so",
                                            "RNOperacionesElFresno",
					    intNumParametrosCotizacion);
	CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosCotizacion,
				     "EjecutaCotizacion",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "");
	for(lP_PCotizacion=pCQPCotizacion->first();
	    lP_PCotizacion;
	    lP_PCotizacion=pCQPCotizacion->next())
	CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosCotizacion,
				     "",
				     pchrPtrIdCliente,
				     lP_PCotizacion->ObtenProducto()->ObtenClave(),
				     lP_PCotizacion->ObtenCantidad(),
				     pchrPtrNmbTipoPrecio,
				     pchrPtrExpendio,
				     ObtenPrecio(lP_PCotizacion));
	CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
}
void CQCtrCotizacion::AsignaRespuestaCotizacion(CQProductosCotizacion *pCQPCotizacion)
{
  ProductoCotizacion *lP_ProductoCot;

		while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
		       QSLRegistro.count()==8)
		{
		      if(QSLRegistro[0]=="TotalCotizacion")
		      pCQPCotizacion->PonImporteTotal((const char *)QSLRegistro[3]); 
		      else
		      {
		      lP_ProductoCot=(*pCQPCotizacion)[(const char *)QSLRegistro[0]];
		      if(lP_ProductoCot)
		      {
		 	lP_ProductoCot->PonCantidad((const char *)QSLRegistro[1]);
			lP_ProductoCot->PonExistencia((const char *)QSLRegistro[2]);
			lP_ProductoCot->PonImporte((const char *)QSLRegistro[3]);
			lP_ProductoCot->ObtenProducto()->PonPrecio(0,
				new Precio("",
					   "",
					   (const char *)QSLRegistro[4],
					   new TipoPrecio((const char *)QSLRegistro[5],
							  (const char *)QSLRegistro[6],
							  (const char *)QSLRegistro[7])
					  ));
			lP_ProductoCot->PonSePuedeVender((const char *)QSLRegistro[7]);
		      }
		      }
		}	
	
}
