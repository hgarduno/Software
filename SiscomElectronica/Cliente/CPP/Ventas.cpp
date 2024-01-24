#include <Ventas.h>
VentasE::VentasE(SiscomDatCom *pSisDatCom,
		 const char *pchrPtrIdEmpleado,
		 ProductosE &pProductos)
{

SiscomGeneralOperacionesSrv lSGenOp(pSisDatCom,
				   (QPtrList<SiscomInformacion>*)&pProductos);
	pProductos.at(0)->SiscomActualizaCampo("IdUnidad",pchrPtrIdEmpleado);
	lSGenOp.SiscomEjecutaEnvio("RegistraVentas");
//	GeneraDispositivosCotizados((const SiscomComunicaSrv *)lSGenOp,pProductos);
}

void VentasE::GeneraDispositivosCotizados(
			const SiscomComunicaSrv *pSComunicaSrv,
			ProductosE &pProductos)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
/*
	pProductos.clear();
	for(;
	    !lSRegistrosPro2.SiscomEsElUltimoRegistro();
	    ++lSRegistrosPro2)
	  pProductos <<
	  new ProductoE(lSRegistrosPro2["CveProducto"],
	  		 lSRegistrosPro2["Descripcion"],
			 "",
			 "",
			 lSRegistrosPro2["Precio"],
			 lSRegistrosPro2["NmbTipoPrecio"],
			 lSRegistrosPro2["Cantidad"],
			 lSRegistrosPro2["Existencia"],
			 "",
			 lSRegistrosPro2["IdExpendio"],
			 lSRegistrosPro2["ImporteCantidad"],
			 lSRegistrosPro2["SePuedeVender"],
			 lSRegistrosPro2["NumJuegos"]);
*/
delete pSComunicaSrv;
}
						
