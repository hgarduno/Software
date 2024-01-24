#include <Facturacion.h>
#include <Cotizaciones.h>
#include <Personas.h>
Factura::Factura()
{

}
Factura::Factura(CQProductosCotizacion *pCQPCotizacion,
		 const char *pchrPtrIva,
		 const char *pchrPtrImporteSinIva):
	CQPCotizacion(pCQPCotizacion),
	chrPtrIva(pchrPtrIva),
	chrPtrImporteSinIva(pchrPtrImporteSinIva)
{


}
Factura::Factura(CQProductosCotizacion *pCQPCotizacion,
			 CQ_Persona *pCQPCliente,
		  const char *pchrPtrNumFactura):
	CQPCotizacion(pCQPCotizacion),
	CQPCliente(pCQPCliente),
	chrPtrNumFactura(pchrPtrNumFactura)
{


}
void Factura::PonIva(const char *pchrPtrIva)
{
	chrPtrIva=pchrPtrIva;
}
void Factura::PonImporteSinIva(const char *pchrPtrImporteSinIva)
{
	chrPtrImporteSinIva=pchrPtrImporteSinIva;
}
const char *Factura::ObtenIva()
{
	return chrPtrIva;
}
const char *Factura::ObtenImporteSinIva()
{
	return chrPtrImporteSinIva;
}
CQProductosCotizacion *Factura::ObtenProductos()
{
	return CQPCotizacion;
}
CQ_Persona *Factura::ObtenCliente()
{
	return CQPCliente;
}
const char *Factura::ObtenNumFactura()
{
	return chrPtrNumFactura;
}
void Factura::AnexaOrdenVenta(OrdenVenta *pOVenta)
{
	CQOVenta << pOVenta;
}
const CQOrdenesVenta &Factura::ObtenOrdenesVenta()
{
	return CQOVenta;
}
CQFacturas::CQFacturas()
{

}
CQCtrFacturacion::CQCtrFacturacion(CSISCOMDatComunicaciones *pCSisDatCom,
				   QStringList pQSLParametros,
				   CQFacturas *pCQFFacturas):
		CQFFacturas(pCQFFacturas),
		SISCOMOperacionesEnvio(pCSisDatCom,
					pQSLParametros,
				       "libRNSistemaElFresno.so",
                                       "RNOperacionesElFresno",
                                       "OperacionesFacturacion")
{

	SISCOMEjecutaEnvio();
        AnalizaRespuesta();

}
void CQCtrFacturacion::SISCOMRegistrosEnvio()
{
 printf("CQCtrFacturacion::SISCOMRegistrosEnvio\n");
 SISCOMAnexaRegistroVacio();
}
void CQCtrFacturacion::SISCOMIniciaRegistroEnvio()
{
 SISCOMRegEnvioDat <<
        new SISCOMCampoEnvio("Servicio") <<
        new SISCOMCampoEnvio("ParametrosOperacion") ;

	SISCOMPonRegistroEnvio(SISCOMRegEnvioDat);

}
void CQCtrFacturacion::AnexaFactura()
{
	if(!CQFFacturas->count())
	 CQFFacturas->append(new Factura);

	CQPCotizacionPtr=new CQProductosCotizacion;

}
void CQCtrFacturacion::AnexaOrdenes(QStringList pQSLRegistro)
{
   CQFFacturas->at(0)->AnexaOrdenVenta(new OrdenVenta(
			   		     (const char *)pQSLRegistro[0],
			   		     (const char *)pQSLRegistro[1],
			   		     (const char *)pQSLRegistro[6])
		   			);
}
void CQCtrFacturacion::AnalizaRespuesta()
{
QStringList lQSLRegistro;
int lintNumCampos;
	AnexaFactura();
	while(!SISCOMObtenOperacionServidor()->SiguienteRegistro(lQSLRegistro))
	{
	    MuestraContenidoRegistro(lQSLRegistro,"CQCtrFacturacion::AnalizaRespuesta");
	    if((lintNumCampos=lQSLRegistro.count())==7)    
	    AnexaOrdenes(lQSLRegistro);
	    if((lintNumCampos=lQSLRegistro.count())==5)
	    AnexaProductosDeLaFactura(lQSLRegistro);
	}
	if(lintNumCampos==5)
	   CQFFacturas->append(new Factura(CQPCotizacionPtr,
					   chrPtrIva,
					   chrPtrImporteSinIva));
}
void CQCtrFacturacion::AnexaProductosDeLaFactura(QStringList pQSLRegistro)
{
Producto *lPProducto;
ProductoCotizacion *lPCotizacion;
	if(pQSLRegistro[0]!="Total" &&
	   pQSLRegistro[0]!="IVA"   &&
	   pQSLRegistro[0]!="TotalSinIVA")
	{	
	lPProducto=new Producto((const char *)pQSLRegistro[0],
				(const char *)pQSLRegistro[1]);
	lPProducto->AnexaPrecio(new Precio(
					"",
					"",
					(const char *)pQSLRegistro[3],
					new TipoPrecio("","","")));
	lPCotizacion=new ProductoCotizacion(
					lPProducto,
					(const char *)pQSLRegistro[2],
					"",
					(const char *)pQSLRegistro[4],
					"");
	CQPCotizacionPtr->append(lPCotizacion);
	}
	if(pQSLRegistro[0]=="Total")
	CQPCotizacionPtr->PonImporteTotal((const char *)pQSLRegistro[4]);
	if(pQSLRegistro[0]=="IVA")
	 chrPtrIva=(const char *)pQSLRegistro[4];
	if(pQSLRegistro[0]=="TotalSinIVA")
	 chrPtrImporteSinIva=(const char *)pQSLRegistro[4];
}
