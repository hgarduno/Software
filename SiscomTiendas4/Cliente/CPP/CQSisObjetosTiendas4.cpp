#include <CQSisObjetosTiendas4.h>
#include <CQSisEmpresas.h>
#include <CQSisContactos.h>
#include <CQSisFormaPago.h>
#include <CQSisProductos.h>
#include <CQSisFamilias.h>
#include <CQSisCompras.h>
#include <CQSisClientes.h>
#include <CQSisReportes.h>
#include <CQSisOrdenes.h>
#include <CQSisPrecios.h>
#include <CQSisContactos.h>
#include <CQSisProdCotiza.h>
#include <CQSisPedidos.h>
ObjetosTiendas4::ObjetosTiendas4()
{

}

CQSisProducto *ObjetosTiendas4::Producto(
				SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisProducto(
	    new CQSisFamilia(
	    	   (*pSRegistrosPro2)["idfamilia"],
	    	   (*pSRegistrosPro2)["familia"],
	    	   ""),
	   (*pSRegistrosPro2)["idproducto"],
	   (*pSRegistrosPro2)["clave"],
	   (*pSRegistrosPro2)["dscproducto"]);
}
CQSisEmpresa *ObjetosTiendas4::Empresa(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisEmpresa(
		(*pSRegistrosPro2)["idempresa"],
		(*pSRegistrosPro2)["razonsocial"]);
}
CQSisContacto *ObjetosTiendas4::Contacto(
			CQSisEmpresa *pCQSEProveedor,
			SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisContacto(
		new SisPersona(
		(*pSRegistrosPro2)["nombre"],
		(*pSRegistrosPro2)["apaterno"],
		(*pSRegistrosPro2)["amaterno"],
		(*pSRegistrosPro2)["idpersona"]),
		pCQSEProveedor);

}
CQSisFormaPago *ObjetosTiendas4::FormaPago(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisFormaPago(
		(*pSRegistrosPro2)["idformapago"],
		(*pSRegistrosPro2)["nombre"],
		(*pSRegistrosPro2)["diassigpago"]);
}
CQSisCompra *ObjetosTiendas4::Compra(SiscomRegistrosPro2 *pSRegistrosPro2)
{
CQSisEmpresa *lCQSProveedor=Empresa(pSRegistrosPro2);

return new CQSisCompra(
		Producto(pSRegistrosPro2),
		lCQSProveedor,
		Contacto(lCQSProveedor,pSRegistrosPro2),
		FormaPago(pSRegistrosPro2),
		(*pSRegistrosPro2)["idcompra"],
		(*pSRegistrosPro2)["cantidad"],
		(*pSRegistrosPro2)["preciocompra"],
		(*pSRegistrosPro2)["factura"],
		(*pSRegistrosPro2)["fecha"],
		"");
}
CQSisCliente *ObjetosTiendas4::Cliente(SiscomRegistrosPro2 *pSRegistrosPro2)
{
	if(QString((*pSRegistrosPro2)["tipopersona"])=="Fisica")
	return new CQSisCliente(
			new SisPersona(
			(*pSRegistrosPro2)["nombre"],
			(*pSRegistrosPro2)["apaterno"],
			(*pSRegistrosPro2)["amaterno"],
			(*pSRegistrosPro2)["idpersona"])
			);
			
	if(QString((*pSRegistrosPro2)["tipopersona"])=="Moral")
	return new CQSisCliente(
		     new CQSisEmpresa(
		     	(*pSRegistrosPro2)["identificador"],
		     	(*pSRegistrosPro2)["razonsocial"]),
		      Contacto(pSRegistrosPro2));
}
CQSisRepVenta *ObjetosTiendas4::ReporteVenta(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisRepVenta(
		(*pSRegistrosPro2)["ordenes"],
		(*pSRegistrosPro2)["total"],
		(*pSRegistrosPro2)["fecha"]);
}
CQSisOrden *ObjetosTiendas4::Orden(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisOrden(Cliente(pSRegistrosPro2),
		      FormaPago(pSRegistrosPro2),
		      (*pSRegistrosPro2)["idventa"],
		      (*pSRegistrosPro2)["fecha"],
		      (*pSRegistrosPro2)["importe"]);
}
CQSisPrecio *ObjetosTiendas4::Precio(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisPrecio((*pSRegistrosPro2)["idprecio"],
		       (*pSRegistrosPro2)["nmbprecio"],
		       "");
}
CQSisContacto *ObjetosTiendas4::Contacto(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisContacto(new SisPersona((*pSRegistrosPro2)["nomcontacto"],
					(*pSRegistrosPro2)["apatcontacto"],
					"",
					(*pSRegistrosPro2)["idcontacto"]));

}
CQSisProdCotiza *ObjetosTiendas4::ProdCotiza(SiscomRegistrosPro2 *pSRegistrosPro2)
{

return new CQSisProdCotiza(Producto(pSRegistrosPro2),
			   (*pSRegistrosPro2)["cantidad"],
			   (*pSRegistrosPro2)["precio"],
			   (*pSRegistrosPro2)["importe"],
			   "",
			   "");


}

void ObjetosTiendas4::ProdsCotiza(SiscomRegistrosPro2 *pSRegistrosPro2,
				   CQSisLstProdCotiza *pCQSLPCotiza)
{
for(;
    !pSRegistrosPro2->SiscomEsElUltimoRegistro();
    ++(*pSRegistrosPro2))
  (*pCQSLPCotiza) << ProdCotiza(pSRegistrosPro2);
}

CQSisPedido *ObjetosTiendas4::Pedido(SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new CQSisPedido(
		(*pSRegistrosPro2)["idventa"],
		(*pSRegistrosPro2)["idempleado"],
		(*pSRegistrosPro2)["idcliente"],
		(*pSRegistrosPro2)["observaciones"],
		(*pSRegistrosPro2)["fecha"],
		(*pSRegistrosPro2)["importe"]);

}
void ObjetosTiendas4::Pedidos(SiscomRegistrosPro2 *pSRegistrosPro2,
			      CQSisLstPedido *pCQSLPedidos)
{
 for(;
     !pSRegistrosPro2->SiscomEsElUltimoRegistro();
     ++(*pSRegistrosPro2))
    (*pCQSLPedidos) << Pedido(pSRegistrosPro2);
}
