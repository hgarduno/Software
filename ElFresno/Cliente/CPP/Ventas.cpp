#include <Ventas.h>
#include <Personas.h>
#include <Cotizaciones.h>
#include <Empresas.h>
#include <CQSiscomCom.h>


Venta::Venta(CQProductosCotizacion *pCQProductos,
	     CQ_Persona *pCQPCliente,
	     CQ_Persona *pCQPVendedor,
	     Empresa *pExpendio):
	CQPProductos(pCQProductos),
	CQPCliente(pCQPCliente),
	chrPtrEdoRegistro("0"),
	EExpendio(pExpendio),
	CQPVendedor(pCQPVendedor)
{


}

void Venta::PonProductos(CQProductosCotizacion *pCQProductos)
{
	CQPProductos=pCQProductos;
}
void Venta::PonCliente(CQ_Persona *pCQPCliente)
{
	CQPCliente=pCQPCliente;
}

CQProductosCotizacion *Venta::ObtenProductos()
{
	return CQPProductos;
}
CQ_Persona *Venta::ObtenCliente()
{
	return CQPCliente;
}
CQ_Persona *Venta::ObtenVendedor()
{
	return CQPVendedor;
}
Empresa *Venta::ObtenExpendio()
{
	return EExpendio;
}
const char *Venta::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}
CQVentas::CQVentas()
{

}

CQCtrVentas::CQCtrVentas(CSISCOMDatComunicaciones *pCSisDatCom,
			 CQCtrVentas::CtrVentas pCQCtrOperacion,
			 Venta *pVenta):
		CSisDatCom(pCSisDatCom),
		chrPtrFormatoVentas("%s%s%s%s%s%s%s%s%s%s"),
		intNumFormatoVentas(10)
{
	switch(pCQCtrOperacion)
	{
		case CQCtrVentas::RegistrarVenta:
			RegistrarLaVenta(pVenta);
		break;
	}
}
void CQCtrVentas::RegistrarLaVenta(Venta *pVenta)
{
ProductoCotizacion *lP_Producto;
CQPrecios lCQPrecios;
Precio *lP_Precio;
	CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						   intNumFormatoVentas);
	CQOGSvrSiscom->AnexaRegistro(chrPtrFormatoVentas,
				     "RegistraVenta",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "");

	CQOGSvrSiscom->AnexaRegistro(chrPtrFormatoVentas,
				     "",
				     pVenta->ObtenVendedor()->ObtenIdPersona(),
				     pVenta->ObtenCliente()->ObtenIdPersona(),
				     pVenta->ObtenExpendio()->ObtenIdEmpresa(),
				     pVenta->ObtenProductos()->ObtenImporteTotal(),
				     "",
				     "",
				     "",
				     "",
				     "");
				     


	for(lP_Producto=pVenta->ObtenProductos()->first();
	    lP_Producto;
	    lP_Producto=pVenta->ObtenProductos()->next())
	{
	  lCQPrecios=lP_Producto->ObtenProducto()->ObtenPrecios();
	  lP_Precio=lCQPrecios.at(0);
	
	  CQOGSvrSiscom->AnexaRegistro(chrPtrFormatoVentas,
				       "",
				       "",
				       "",
				       "",
				       "",
				       lP_Producto->ObtenProducto()->ObtenClave(),
				       lP_Producto->ObtenCantidad(),
				       lP_Precio->ObtenPrecio(),
				       lP_Producto->ObtenImporte(),
				       "0");
				       

	}


	CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
}
