#include <ConsultasTiendas4.h>
#include <ComunSiscomTiendas4.h>
#include <SiscomAplicaciones.h>
#include <SiscomDirecciones.h>
#include <SiscomMediosComunicacion.h>
#include <Familias.h>
#include <Productos.h>
#include <Precios.h>
#include <MediosComunicacion.h>
#include <Empresas.h>
#include <FormaPago.h>
#include <Compras.h>
#include <Clientes.h>
#include <Reportes.h>
#include <Ordenes.h>
#include <Existencias.h>
#include <Sepomex.h>
#include <Paquetes.h>
#include <BusquedaProductos.h>
#include <DatosProductosPorFamilia.h>

#include <Pedidos.h>


#include <stdlib.h>
SiscomOperaciones2 *OperacionesConsultasTiendas4()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ConsultaTiendas4,lSOpPtrGimnasio);
return lSOpPtrGimnasio;
}

void ConsultaTiendas4(SArgsSiscom *pSAgsSiscom)
{
SSiscomOperaciones2 *lSSOperaciones=0;
SiscomOperaciones2 *lSOpPtrCnsGimnasios=0;
SiscomLeeEntradaOperaciones2(pSAgsSiscom);
SiscomCopiaArgumentosConsulta(pSAgsSiscom);
SiscomAnexaOperacion2("Familias",FamiliasRegistradas(),&lSSOperaciones);
SiscomAnexaOperacion2("Productos",ProductosRegistrados(),&lSSOperaciones);
SiscomAnexaOperacion2("Precios",OPPreciosRegistrados(),&lSSOperaciones);
SiscomAnexaOperacion2("IniciaPrecios",OPIniciaPrecios(),&lSSOperaciones);
SiscomAnexaOperacion2("PreciosProducto",OPPreciosProducto(),&lSSOperaciones);
SiscomAnexaOperacion2("ActualizaPrecioProducto",OPActualizaPrecioProducto(),&lSSOperaciones);
SiscomAnexaOperacion2("Medios",OPConsultaMedios(),&lSSOperaciones);
SiscomAnexaOperacion2("Proveedores",OPProveedores(),&lSSOperaciones);
SiscomAnexaOperacion2("ContactosProveedor",OPContactosProveedores(),&lSSOperaciones);
SiscomAnexaOperacion2("FormaPago",OPConsultaFormasPago(),&lSSOperaciones);
SiscomAnexaOperacion2("UltimaCompraProducto",OPUltimaCompraProducto(),&lSSOperaciones);
SiscomAnexaOperacion2("ClientesRegistrados",OPClientesRegistrados(),&lSSOperaciones);
SiscomAnexaOperacion2("ReporteVentas",OPReporteVentas(),&lSSOperaciones);
SiscomAnexaOperacion2("OrdenVendida",OPOrdenVendida(),&lSSOperaciones);
SiscomAnexaOperacion2("Ordenes",OPOrdenesVendidas(),&lSSOperaciones);
SiscomAnexaOperacion2("ExistenciaProductos",OPExistenciaProductos(),&lSSOperaciones);
SiscomAnexaOperacion2("ReporteDetalleVentas",OPDetalleVentas(),&lSSOperaciones);
SiscomAnexaOperacion2("ComprasRegistradas",OPCompras(),&lSSOperaciones);
SiscomAnexaOperacion2("DetalleCompra",OPDetalleCompra(),&lSSOperaciones);
SiscomAnexaOperacion2("DireccionesPersona",
		       OPSiscomAplicacionesDirecciones(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("MediosComunicacionPersona",
		       OPSiscomAplicacionesMediosComunicacion(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("PedidosCliente",
		       OPedidosCliente(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("PaquetesRegistrados",
		       OPaquetesDisponibles(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("ProductosDelPaquete",
		       OProductosDelPaquete(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("SepomexEstados",
		      SepomexEstados(),
		      &lSSOperaciones);

SiscomAnexaOperacion2("SepomexMunicipios",
		       SepomexMunicipios(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("SepomexAsentamientos",
		       SepomexAsentamientos(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("DireccionesCliente",
		       OPDireccionesCliente(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("ProductosPorAproximacion",
		      OpProductosPorAproximacion(),
		      &lSSOperaciones);

SiscomAnexaOperacion2("DatosProductosPorFamilia",
		      ODatosProductosPorFamilia(),
		      &lSSOperaciones);
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);

lSOpPtrCnsGimnasios=SiscomOperaciones2CualEjecuta(
				pSAgsSiscom->chrPtrArgConsulta[0],
				lSSOperaciones,
				ConsultaNoSoportada,
				pSAgsSiscom);
if(lSOpPtrCnsGimnasios)
{
SiscomLog("Ejecutando %s",pSAgsSiscom->chrPtrArgConsulta[0]);
SiscomOperaciones2Ejecuta(lSOpPtrCnsGimnasios,pSAgsSiscom);
}
else
SiscomLog("No Se encontro la operacion");
}
void ConsultaNoSoportada(SArgsSiscom *pSAgsSiscom)
{
SiscomMensajesLog2("ConsultaNoSoportada");
}
