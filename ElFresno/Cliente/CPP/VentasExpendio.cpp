#include <VentasExpendio.h>
VentaExpendio::VentaExpendio(const char *pchrPtrCantidad,
			     const char *pchrPtrImporte,
			     const char *pchrPtrCveProducto,
			     const char *pchrPtrPrecioProducto,
			     const char *pchrPtrExistencia):
		chrPtrCantidad(pchrPtrCantidad),
		chrPtrImporte(pchrPtrImporte),
		chrPtrCveProducto(pchrPtrCveProducto),
		chrPtrPrecioProducto(pchrPtrPrecioProducto),
		chrPtrExistencia(pchrPtrExistencia)
{


}
const char *VentaExpendio::ObtenCantidad()
{
	return chrPtrCantidad;
}
const char *VentaExpendio::ObtenImporte()
{
	return chrPtrImporte;
}
const char *VentaExpendio::ObtenCveProducto()
{
	return chrPtrCveProducto;
}

const char *VentaExpendio::ObtenPrecioProducto()
{
	return chrPtrPrecioProducto;
}
const char *VentaExpendio::ObtenExistencia()
{
	return chrPtrExistencia;
}
CQVentasExpendio::CQVentasExpendio()
{

}
void CQVentasExpendio::PonImporteVenta(const char *pchrPtrImporte)
{
	chrPtrImporteVenta=pchrPtrImporte;
}

const char *CQVentasExpendio::ObtenImporteVenta()
{
	return chrPtrImporteVenta;
}
CQCtrVentasExpendio::CQCtrVentasExpendio(CSISCOMDatComunicaciones *pCSisDatCom,
					 QStringList pQSLParametros,
					 CQVentasExpendio *pCQVentas):
			CSisDatCom(pCSisDatCom)
{
		IniciaRegistroEnvio();
		IniciaComunicacion();
		EnviaParametrosOperacion(pQSLParametros);
		EnviaVentasExpendio(pCQVentas);
		EnviaInformacion();
		AnalizaRespuesta(pCQVentas);

}
void CQCtrVentasExpendio::AnalizaRespuesta(CQVentasExpendio *pCQVentas)
{
	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	      QSLRegistro.count()==5)
	{
	 MuestraContenidoRegistro(QSLRegistro,"CQCtrVentasExpendio::AnalizaRespuesta");
	 if(QSLRegistro[2]=="Importe Total")
	     pCQVentas->PonImporteVenta((const char *)QSLRegistro[1]);
	 else
	    pCQVentas->append(
			new VentaExpendio(
			  (const char *)QSLRegistro[0],
			  (const char *)QSLRegistro[1],
			  (const char *)QSLRegistro[2],
			  (const char *)QSLRegistro[3],
			  (const char *)QSLRegistro[4]));
	}
}
void CQCtrVentasExpendio::IniciaComunicacion()
{
CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						  SISCOMRegEnvio.count());
	SISCOMRegEnvio["Servicio"]->PonContenido("OperacionesVentasExpendio");
	AnexaRegistro();
	

}
void CQCtrVentasExpendio::AnexaRegistro()
{
	CQOGSvrSiscom->AnexaRegistro(SISCOMRegEnvio.ObtenRegistro());
	SISCOMRegEnvio.LimpiaRegistro();
}
void CQCtrVentasExpendio::EnviaParametrosOperacion(QStringList pQSLArgumentos)
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
void CQCtrVentasExpendio::AnexaRegistroVacio()
{
	SISCOMRegEnvio.LimpiaRegistro();
	AnexaRegistro();
}
void CQCtrVentasExpendio::EnviaInformacion()
{
	CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
}
void CQCtrVentasExpendio::EnviaVentasExpendio(CQVentasExpendio *)
{

}
void CQCtrVentasExpendio::IniciaRegistroEnvio()
{
	SISCOMRegEnvio <<
	new SISCOMCampoEnvio("Servicio") <<
	new SISCOMCampoEnvio("ParametroOperacion") ;
}

