#include <Pedidos.h>
#include <Cotizaciones.h>
#include <Vehiculos.h>
#include <CQSiscomCom.h>
#include <Personas.h>
Pedido::Pedido(CQ_Persona *pCQPCliente,
	       CQProductosCotizacion *pCQPCotizacion,
	       const char *pchrPtrVendedor):
		CQPCliente(pCQPCliente),
		chrPtrVendedor(pchrPtrVendedor),
		CQPCotizacion(pCQPCotizacion),
		chrPtrFechaEntrega("")
{


}
Pedido::Pedido(CQ_Persona *pCQPCliente,
	       const char *pchrPtrNumPedido,
	       const char *pchrPtrFechaRegistro,
	       const char *pchrPtrImportePedido,
	       const char *pchrPtrTipoPrecio):
	CQPCliente(pCQPCliente),
	chrPtrNumPedido(pchrPtrNumPedido),
	chrPtrFechaRegistro(pchrPtrFechaRegistro),
	chrPtrImportePedido(pchrPtrImportePedido),
	chrPtrTipoPrecio(pchrPtrTipoPrecio),
		chrPtrFechaEntrega("")
{

}
void Pedido::PonFormaPago(const char *pchrPtrFormaPago)
{
	chrPtrFormaPago=pchrPtrFormaPago;
}
void Pedido::PonFechaEntrega(const char *pchrPtrFechaEntrega)
{
	chrPtrFechaEntrega=pchrPtrFechaEntrega;
}
void Pedido::PonChofer(CQ_Persona *pCQPChofer)
{
	CQChofer=pCQPChofer;
}
void Pedido::PonAutorizo(CQ_Persona *pCQAutorizo)
{
	CQAutorizo=pCQAutorizo;
}
void Pedido::PonRevPedChofer(CQ_Persona *pCQPRevPedChofer)
{
	CQRevPedChofer=pCQPRevPedChofer;
}
void Pedido::PonVendedor(CQ_Persona *pCQVendedor)
{
	CQVendedor=pCQVendedor;
}
void Pedido::PonVehiculo(Vehiculo *pVehiculo)
{
	VVehiculo=pVehiculo;
}
void Pedido::PonNumPedido(const char *pchrPtrNumPedido)
{
	chrPtrNumPedido=pchrPtrNumPedido;
}	
void Pedido::PonEdoRegistro(const char *pchrPtrEdoRegistro)
{
	chrPtrEdoRegistro=pchrPtrEdoRegistro;
}
void Pedido::PonProductos(CQProductosCotizacion *pCQPCotizacion)
{
   CQPCotizacion=pCQPCotizacion;
}
void Pedido::PonImportePedido(const char *pchrPtrImportePedido)
{
	chrPtrImportePedido=pchrPtrImportePedido;
}
void Pedido::PonContactoCliente(const char *pchrPtrContactoCliente)
{
	chrPtrContactoCliente=pchrPtrContactoCliente;
}

CQ_Persona *Pedido::ObtenChofer()
{
	return CQChofer;
}	
CQ_Persona *Pedido::ObtenAutorizo()
{
	return CQAutorizo;
}
CQ_Persona *Pedido::ObtenCliente()
{
	return CQPCliente;
}
CQ_Persona *Pedido::ObtenRevPedChofer()
{
	return CQRevPedChofer;
}
CQ_Persona *Pedido::ObtenVendedor()
{
	return CQVendedor;
}
Vehiculo *Pedido::ObtenVehiculo()
{
	return VVehiculo;
}
CQProductosCotizacion *Pedido::ObtenProductos()
{
	return CQPCotizacion;
}
const char *Pedido::ObtenNumPedido()
{
	return chrPtrNumPedido;
}
const char *Pedido::ObtenFechaEntrega()
{
	return chrPtrFechaEntrega;
}
const char *Pedido::ObtenImporteDelPedido()
{
	return chrPtrImportePedido;
}
const char *Pedido::ObtenFechaRegistro()
{
	return chrPtrFechaRegistro;
}
const char *Pedido::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}
const char *Pedido::ObtenFormaPago()
{
	return chrPtrFormaPago;
}
const char *Pedido::ObtenTipoPrecio()
{
	return chrPtrTipoPrecio;
}
const char *Pedido::ObtenIdVendedor()
{
	return chrPtrVendedor;
}
const char *Pedido::ObtenContactoCliente()
{
	return chrPtrContactoCliente;
}
CQPedidos::CQPedidos()
{

}
CQCtrPedidos::CQCtrPedidos(CSISCOMDatComunicaciones *pCSisDatCom,
			   CQCtrPedidos::CtrPedidos pCQOperacion,
			   QStringList pQSLParametros,
			   CQPedidos *pCQPedidos):
			CSisDatCom(pCSisDatCom)
{
	switch(pCQOperacion)
	{
		case CQCtrPedidos::PedidosSinAutorizarDelDia:
			ConsultarLosPedidos(pQSLParametros,pCQPedidos);	
			AnalizaRespuestaConsulta(pCQPedidos);
		break;
		case CQCtrPedidos::PedidosDelVehiculo:
			ConsultarLosPedidos(pQSLParametros,pCQPedidos);
			AnalizaRespuestaConsulta(pCQPedidos);
		break;
		case CQCtrPedidos::AsignaVehiculo:
			ConsultarLosPedidos(pQSLParametros,pCQPedidos);
			AnalizaRespuestaConsulta(pCQPedidos);
		break;
		case CQCtrPedidos::DetallePedido:
			ConsultarLosPedidos(pQSLParametros,pCQPedidos);
			AnalizaRespuestaDetallePedido(pCQPedidos);
		break;
		case CQCtrPedidos::ActualizaFechaEntrega:
			ConsultarLosPedidos(pQSLParametros,pCQPedidos);
		break;
		case CQCtrPedidos::OperacionPedidos:
			OperacionDeLosPedidos(pQSLParametros,pCQPedidos);
		break;
	}
		
}
CQCtrPedidos::CQCtrPedidos(CSISCOMDatComunicaciones *pCSisDatCom,
			   CQCtrPedidos::CtrPedidos pCQOperacion,
			   CQPedidos *pCQPedidos):
			CSisDatCom(pCSisDatCom),
			intParametrosEnvio(11),
			chrPtrParametrosEnvio("%s%s%s%s%s%s%s%s%s%s%s")
{
	switch(pCQOperacion)
	{
		case CQCtrPedidos::Registrar:
			RegistrarLosPedidos(pCQPedidos);
	
		break;
		case CQCtrPedidos::ActualizaPedido:
			EnviaActualizaPedido(pCQPedidos);
			DetalleDelPedido(pCQPedidos->at(0)->ObtenProductos());
			EnviaActualizacionPedido();
		break;
	}


}
void CQCtrPedidos::EnviaRegistroFechaEntrega(CQPedidos *pCQPedidos)
{
CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						   intParametrosEnvio);
	CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosEnvio,
				     "ActualizaRegistraFechaEntregaPedido",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "");
CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosEnvio,
				     "",
				     pCQPedidos->at(0)->ObtenNumPedido(),
				     pCQPedidos->at(0)->ObtenFechaEntrega(),
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "");

	 CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();

}
void CQCtrPedidos::EnviaActualizacionPedido()
{

	 CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
}
void CQCtrPedidos::EnviaActualizaPedido(CQPedidos *pCQPedidos)
{
CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						   intParametrosEnvio);
	CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosEnvio,
				     "ActualizaPedido",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "");
CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosEnvio,
				     "",
				     pCQPedidos->at(0)->ObtenNumPedido(),
				     "",
				     pCQPedidos->at(0)->ObtenImporteDelPedido(),
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "");



}
void CQCtrPedidos::AnalizaRespuestaDetallePedido(CQPedidos *pCQPedidos)
{
Pedido *lPPedido;
CQ_Persona *lCQPersona;
ProductoCotizacion *lPCotizacion;
Producto *lPProducto;
TipoPrecio *lTPrecio;
Precio *lPPrecio;
CQProductosCotizacion *lCQPCotizacion;
int lintContador=0;
const char *lchrPtrNumPedido;
	lCQPCotizacion=new CQProductosCotizacion;
	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	       QSLRegistro.count()==11)
	{
	 /*
	  MuestraContenidoRegistro(QSLRegistro,"AnalizaRespuestaDetallePedido");
	  printf("%d\n",QSLRegistro.count());
	  */
	  if(!lintContador)
	  {
	  lCQPersona=new CQ_Persona((const char *)QSLRegistro[8],
			  	    (const char *)QSLRegistro[9],
				    (const char *)QSLRegistro[10],
				    "",
				    "",
				    (const char *)QSLRegistro[0]);
	  lintContador++;
	  lchrPtrNumPedido=(const char *)QSLRegistro[1];
	  }
	  lTPrecio=new TipoPrecio((const char *)QSLRegistro[5],"","");
	  lPPrecio=new Precio((const char *)QSLRegistro[6],
			      "",
			      (const char *)QSLRegistro[7],
			      lTPrecio);
	  lPProducto=new Producto((const char *)QSLRegistro[2],"");
	  lPProducto->AnexaPrecio(lPPrecio);
	  lPCotizacion=new ProductoCotizacion(lPProducto,
			  		      (const char *)QSLRegistro[3],
					      "",
					      (const char *)QSLRegistro[4],
					      "");
	  lCQPCotizacion->append(lPCotizacion);
	}
	lPPedido= new 	Pedido(lCQPersona,
				       lCQPCotizacion,
				       "hsanchez");
	lPPedido->PonNumPedido(lchrPtrNumPedido);
	pCQPedidos->append(lPPedido);

}

void CQCtrPedidos::EnviaRegistroVacio()
{
		CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosEnvio,
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "");


}
void CQCtrPedidos::RegistroGeneralPedido(Pedido *pPedido)
{
CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosEnvio,
				     "",
				     pPedido->ObtenCliente()->ObtenIdPersona(),
				     pPedido->ObtenIdVendedor(),
				     pPedido->ObtenProductos()->ObtenImporteTotal(),
				     "",
				     "",
				     "",
				     "",
				     "",
				     pPedido->ObtenFechaEntrega(),
				     pPedido->ObtenContactoCliente());

}
void CQCtrPedidos::RegistrarLosPedidos(CQPedidos *pCQPedidos)
{
Pedido *lP_Pedido;
	CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						   intParametrosEnvio);
	CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosEnvio,
				     "RegistraPedidos",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "",
				     "");
	for(lP_Pedido=pCQPedidos->first();
	    lP_Pedido;
	    lP_Pedido=pCQPedidos->next())
	{
		RegistroGeneralPedido(lP_Pedido);
		DetalleDelPedido(lP_Pedido->ObtenProductos());
	}

	 CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
}
void CQCtrPedidos::DetalleDelPedido(CQProductosCotizacion *pCQPCotizacion)
{
ProductoCotizacion *lP_Cotizacion;
CQPrecios lCQPrecios;
Precio *lP_Precio;
   for(lP_Cotizacion=pCQPCotizacion->first();
       lP_Cotizacion;
	lP_Cotizacion=pCQPCotizacion->next())
   {
	lCQPrecios=lP_Cotizacion->ObtenProducto()->ObtenPrecios();
	lP_Precio=lCQPrecios.at(0);
	CQOGSvrSiscom->AnexaRegistro(chrPtrParametrosEnvio,
				     "",
				     "",
				     "",
				     "",
				     lP_Cotizacion->ObtenProducto()->ObtenClave(),
				     lP_Cotizacion->ObtenCantidad(),
				     lP_Cotizacion->ObtenImporte(),
				     lP_Precio->ObtenTipoPrecio()->ObtenNmbTipoPrecio(),
				     "",
				     "",
				     "");
	   
    }
    EnviaRegistroVacio();
}

void CQCtrPedidos::OperacionDeLosPedidos(QStringList pQSLParametros,
				       CQPedidos *pCQPedidos)
{
int lintContador;
CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						   2);
	CQOGSvrSiscom->AnexaRegistro("%s%s",
				     "OperacionesPedidos",
				     "");

	for(lintContador=0;lintContador<pQSLParametros.size();lintContador++)
	 CQOGSvrSiscom->AnexaRegistro("%s%s",
				      "",
				      (const char *)pQSLParametros[lintContador]);
	 CQOGSvrSiscom->AnexaRegistro("%s%s",
				      "",
				      "");
	

	 CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();


}
void CQCtrPedidos::ConsultarLosPedidos(QStringList pQSLParametros,
				       CQPedidos *pCQPedidos)
{
int lintContador;
CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
                                                  "libRNSistemaElFresno.so",
                                                  "RNOperacionesElFresno",
						   2);
	CQOGSvrSiscom->AnexaRegistro("%s%s",
				     "ConsultaPedidos",
				     "");

	for(lintContador=0;lintContador<pQSLParametros.size();lintContador++)
	 CQOGSvrSiscom->AnexaRegistro("%s%s",
				      "",
				      (const char *)pQSLParametros[lintContador]);
	

	 CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();


}
void CQCtrPedidos::AnalizaRespuestaConsulta(CQPedidos *pCQPedidos)
{
CQ_Persona *lCQPersona;
Vehiculo *lV_Vehiculo;
Pedido *lP_Pedido;
	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	      QSLRegistro.count()==47)
	{
	  lCQPersona=new CQ_Persona((const char *)QSLRegistro[12],
				    (const char *)QSLRegistro[13],
				    (const char *)QSLRegistro[14],
				    (const char *)QSLRegistro[15],
				    (const char *)QSLRegistro[16],
				    (const char *)QSLRegistro[17]);
	  lP_Pedido=new Pedido(lCQPersona,
					(const char *)QSLRegistro[0],
					(const char *)QSLRegistro[7],
					(const char *)QSLRegistro[9],
				        (const char *)QSLRegistro[18]);
	  lP_Pedido->PonFormaPago((const char *)QSLRegistro[45]);
	  lP_Pedido->PonFechaEntrega((const char *)QSLRegistro[8]);

	  lP_Pedido->PonVehiculo(new Vehiculo((const char *)QSLRegistro[6],
					      (const char *)QSLRegistro[19],
					      (const char *)QSLRegistro[20]));

	  lP_Pedido->PonChofer(new CQ_Persona((const char *)QSLRegistro[21],
					      (const char *)QSLRegistro[22],	
					      (const char *)QSLRegistro[23],	
					      (const char *)QSLRegistro[24],	
					      (const char *)QSLRegistro[26],	
					      (const char *)QSLRegistro[25]));
	  lP_Pedido->PonAutorizo(new CQ_Persona((const char *)QSLRegistro[27],
						(const char *)QSLRegistro[28],
						(const char *)QSLRegistro[29],
						(const char *)QSLRegistro[30],
						(const char *)QSLRegistro[32],
						(const char *)QSLRegistro[31]));

	  lP_Pedido->PonRevPedChofer(new CQ_Persona((const char *)QSLRegistro[33],
				  		    (const char *)QSLRegistro[34],
				  		    (const char *)QSLRegistro[35],
				  		    (const char *)QSLRegistro[36],
				  		    (const char *)QSLRegistro[37],
				  		    (const char *)QSLRegistro[38]));
	  lP_Pedido->PonVendedor(new CQ_Persona((const char *)QSLRegistro[39],
				  		    (const char *)QSLRegistro[40],
				  		    (const char *)QSLRegistro[41],
				  		    (const char *)QSLRegistro[42],
				  		    (const char *)QSLRegistro[43],
				  		    (const char *)QSLRegistro[44]));
	  lP_Pedido->PonContactoCliente((const char *)QSLRegistro[46]);
		

	  pCQPedidos->append(lP_Pedido);
	  
	}
}
