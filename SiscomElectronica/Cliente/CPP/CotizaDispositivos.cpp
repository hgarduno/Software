#include <CotizaDispositivos.h>
#include <SiscomDesarrollo3Qt++.h>
CotizaDispositivosE::CotizaDispositivosE(SiscomDatCom *pSisDatCom,
				       ProductosE &pProductos):
				       intEstadoCotizacion(1)
{

SiscomGeneralOperacionesSrv lSGenOp(pSisDatCom,
				   (QPtrList<SiscomInformacion>*)&pProductos);

	lSGenOp.SiscomEjecutaEnvio("CotizaDispositivos");
	GeneraDispositivosCotizados((const SiscomComunicaSrv *)lSGenOp,pProductos);
}

void CotizaDispositivosE::GeneraDispositivosCotizados(
			const SiscomComunicaSrv *pSComunicaSrv,
			ProductosE &pProductos)
{
ProductoE *lProductoE;
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
SiscomEscribeLog3Qt("El numero de registros:%d",
		    lSRegistrosPro2.SiscomObtenNumRegistros());
if(lSRegistrosPro2.SiscomObtenNumRegistros()==1)
intEstadoCotizacion=0;
else
{
intEstadoCotizacion=1;
	pProductos.clear();
	for(;
	    !lSRegistrosPro2.SiscomEsElUltimoRegistro();
	    ++lSRegistrosPro2)
	{
	  
	  lProductoE=new ProductoE(
	  		 lSRegistrosPro2["CveProducto"],
	  		 lSRegistrosPro2["Descripcion"],
			 "",
			 "",
			 lSRegistrosPro2["Precio"],
			 lSRegistrosPro2["NmbTipoPrecio"],
			 lSRegistrosPro2["Cantidad"],
			 lSRegistrosPro2["Existencia"],
			 lSRegistrosPro2["IdCliente"],
			 lSRegistrosPro2["IdExpendio"],
			 lSRegistrosPro2["ImporteCantidad"],
			 lSRegistrosPro2["SePuedeVender"],
			 lSRegistrosPro2["NumJuegos"],
			 "",
			 "",
			 "",
			 "",
			 lSRegistrosPro2["EdoRegistro"],
			 lSRegistrosPro2["IdPractica"],
			 "",
			 "",
			 "",
			 "",
			 lSRegistrosPro2["ClienteFrecuente"],
			 lSRegistrosPro2["PorDescuento"],
			 lSRegistrosPro2["RFC"],
			 "",
			 "",
			 "",
			 "",
			 "",
			 "",
			 lSRegistrosPro2["ExisBodega"],
			 lSRegistrosPro2["PorDescuentoCaja"],
			 lSRegistrosPro2["PorDescuentoCajaOrden"],
			 lSRegistrosPro2["OrdenACaja"],
			 lSRegistrosPro2["CantidadValida"],
			 "",
			 lSRegistrosPro2["EsKit"],
			 lSRegistrosPro2["CveKit"],
			 "",
			 lSRegistrosPro2["IdProductoKit"],
			 lSRegistrosPro2["CantidadKit"],
			 lSRegistrosPro2["ImporteKit"],
			 lSRegistrosPro2["IdTipoProducto"]);
	  	pProductos  << lProductoE;
SiscomEscribeLog3Qt("CveProducto(%s) CveKit (%s) IdProductoKit(%s) Cantidad(%s)",
		    lSRegistrosPro2["CveProducto"],
		    lSRegistrosPro2["CveKit"],
		    lSRegistrosPro2["IdProductoKit"],
		    lSRegistrosPro2["CantidadKit"]);
	}
}

delete pSComunicaSrv;
}
						
int CotizaDispositivosE::EstadoCotizacion()
{
 return intEstadoCotizacion;
}
