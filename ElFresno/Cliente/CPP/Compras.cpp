#include <Compras.h>
#include <Empresas.h>
Compra::Compra(const char *pchrPtrFecha,
	       const char *pchrPtrFechaPago,
	       const char *pchrPtrFormaPago,
	       const char *pchrPtrNumFactura,
	       Empresa *pEProveedor,
	       Empresa *pExpendio):
	chrPtrFechaCompra(pchrPtrFecha),
	chrPtrFechaPago(pchrPtrFechaPago),
	chrPtrNumFactura(pchrPtrNumFactura),
	chrPtrFormaPago(pchrPtrFormaPago),
	E_Expendio(pExpendio),
	E_Proveedor(pEProveedor)
{


}
void Compra::PonProveedor(Empresa *pEProveedor)
{
	E_Proveedor=pEProveedor;
}
void Compra::AnexaProducto(ProductoCotizacion *pProdCotizacion)
{
	CQProdCotizacion.append(pProdCotizacion);
}

const CQProductosCotizacion &Compra::ObtenProductosCompra()
{
	return CQProdCotizacion;
}
const char *Compra::ObtenFechaPago()
{
	return chrPtrFechaPago;
}
const char *Compra::ObtenFecha()
{
	return chrPtrFechaCompra;
}
const char *Compra::ObtenNumFactura()
{
	return chrPtrNumFactura;
}
const char *Compra::ObtenFormaPago()
{
	return chrPtrFormaPago;
}
Empresa *Compra::ObtenProveedor()
{
	return E_Proveedor;
}
Empresa *Compra::ObtenExpendio()
{
	return E_Expendio;
}
void Compra::EliminaProducto(int pintNProducto)
{
	CQProdCotizacion.remove(pintNProducto);
}
CQCompras::CQCompras()
{

}

CQCtrCompras::CQCtrCompras(CSISCOMDatComunicaciones *pCSisDatCom,
			   QStringList pQSLArgumentos,
			   CQCompras *pCQCompras):
		CSisDatCom(pCSisDatCom)
{
	IniciaRegistroEnvio();
	IniciaComunicaciones();
	EnviaParametrosOperacion(pQSLArgumentos);
	EnviaCompras(pCQCompras);
	EnviaInformacion();
	AnalizaRespuesta(pCQCompras);
}
void CQCtrCompras::IniciaComunicaciones()
{
CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						  SISCOMRegEnvio.count());
	SISCOMRegEnvio["Servicio"]->PonContenido("OperacionesCompras");
	AnexaRegistro();
}
void CQCtrCompras::EnviaParametrosOperacion(QStringList pQSLArgumentos)
{

int lintContador;
	for(lintContador=0;
	    lintContador<pQSLArgumentos.size();
	    lintContador++)
	{
	 SISCOMRegEnvio["ParametroOperacion"]->PonContenido(
			(const char *)pQSLArgumentos[lintContador]
			);
	 AnexaRegistro();
	}
	AnexaRegistroVacio();
}
void CQCtrCompras::EnviaCompras(CQCompras *pCQCompras)
{
Compra *lC_Compra;
ProductoCotizacion *lProdCotizacion;
CQProductosCotizacion lCQProdCotizacion;
Producto *lPProducto;
CQPrecios lCQPrecios;
		for(lC_Compra=pCQCompras->first();
		    lC_Compra;
		    lC_Compra=pCQCompras->next())
		{
		 lCQProdCotizacion=lC_Compra->ObtenProductosCompra();
		 for(lProdCotizacion=lCQProdCotizacion.first();
		     lProdCotizacion;
		     lProdCotizacion=lCQProdCotizacion.next())
		 {
		     lPProducto=lProdCotizacion->ObtenProducto();
		     lCQPrecios=lPProducto->ObtenPrecios();
		     SISCOMRegEnvio["Fecha"]->PonContenido(lC_Compra->ObtenFecha());
		     SISCOMRegEnvio["CveProducto"]->PonContenido(lPProducto->ObtenClave());
		     SISCOMRegEnvio["Cantidad"]->PonContenido(lProdCotizacion->ObtenCantidad());
		     SISCOMRegEnvio["Importe"]->PonContenido(lProdCotizacion->ObtenImporte());
		     SISCOMRegEnvio["Proveedor"]->PonContenido(lC_Compra->ObtenProveedor()->ObtenIdEmpresa());
			
		     SISCOMRegEnvio["ConProveedor"]->PonContenido("");
		     SISCOMRegEnvio["Responsable"]->PonContenido("");
		     SISCOMRegEnvio["IdExpendio"]->PonContenido(lC_Compra->ObtenExpendio()->ObtenIdEmpresa());
		     SISCOMRegEnvio["FormaPago"]->PonContenido(lC_Compra->ObtenFormaPago());
		     SISCOMRegEnvio["NumFactura"]->PonContenido(lC_Compra->ObtenNumFactura());
		     SISCOMRegEnvio["FechaPago"]->PonContenido(lC_Compra->ObtenFechaPago());
		     SISCOMRegEnvio["Precio"]->PonContenido(lCQPrecios.at(0)->ObtenPrecio());
		     AnexaRegistro();

		 }
		  AnexaRegistroVacio();
		}
	
}
void CQCtrCompras::EnviaInformacion()
{

	CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
}
void CQCtrCompras::AnalizaRespuesta(CQCompras *pCQCompras)
{

}
void CQCtrCompras::AnexaRegistro()
{
	CQOGSvrSiscom->AnexaRegistro(SISCOMRegEnvio.ObtenRegistro());
	SISCOMRegEnvio.LimpiaRegistro();
}
void CQCtrCompras::AnexaRegistroVacio()
{
	SISCOMRegEnvio.LimpiaRegistro();
	AnexaRegistro();
}
void CQCtrCompras::IniciaRegistroEnvio()
{
	SISCOMRegEnvio << 
	new SISCOMCampoEnvio("Servicio") <<
	new SISCOMCampoEnvio("ParametroOperacion") <<
	new SISCOMCampoEnvio("Fecha") <<
	new SISCOMCampoEnvio("CveProducto") <<
	new SISCOMCampoEnvio("Cantidad") <<
	new SISCOMCampoEnvio("Importe")  <<
	new SISCOMCampoEnvio("Proveedor") <<
	new SISCOMCampoEnvio("ConProveedor") <<
	new SISCOMCampoEnvio("Responsable") <<
	new SISCOMCampoEnvio("IdExpendio") <<
	new SISCOMCampoEnvio("FormaPago") <<
	new SISCOMCampoEnvio("NumFactura") <<
	new SISCOMCampoEnvio("FechaPago") <<
	new SISCOMCampoEnvio("Precio") ;
}
