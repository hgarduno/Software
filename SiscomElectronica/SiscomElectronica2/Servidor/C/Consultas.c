#include <Consultas.h>
#include <Escuelas.h>
#include <Compras.h>
#include <Empleados.h>
#include <Alumnos.h>
#include <PagoCambio.h>
#include <VentasCaja.h>
#include <SeguridadCajas.h>
#include <ControladorOrdenes.h>
#include <ControladorOrdenes2.h>
#include <Ganancias.h>
#include <Facturas.h>
#include <Proveedores2.h>
#include <Ordenes.h>
#include <Contabilidad.h>
#include <Transferencias.h>
#include <ReporteSemestral.h>
#include <Expendios.h>
#include <Bodegas.h>
#include <Clientes.h>
#include <ReportePorExistenciaMinima.h>
#include <ExistenciasProductos.h>
#include <Sepomex.h>
#include <ComunElectronica2.h>
#include <SiscomSeguridad.h>
#include <SincronizaExpendio.h>
#include <PuntosPromocionesCliente.h>
#include <MotivoInventario.h>
#include <ProgramacionInventario.h>
#include <OrdenesCajaCentralizada.h>
#include <SiscomFuncionesComunes.h>
#include <Consultas.h>
#include <Servicios.h>
#include <Cursos.h>
#include <ProgramacionPlacas.h>
#include <stdlib.h>
void (*ComunicacionAccesoDatosSepomex)(SArgsSiscom *);
void (*ComunicacionSeguridad)(SArgsSiscom *);
SiscomOperaciones2 *OPConsultas()
{
SiscomOperaciones2 *lSOpPtrGimnasio=0;
lSOpPtrGimnasio=(SiscomOperaciones2 *)malloc(sizeof(SiscomOperaciones2)*100);
SiscomAnexaOperacionAlArreglo2(ConsultasElectronica2,lSOpPtrGimnasio);
return lSOpPtrGimnasio;

}
void ConsultasElectronica2(SArgsSiscom *pSAgsSiscom)
{
SSiscomOperaciones2 *lSSOperaciones=0;
SiscomOperaciones2 *lSOpPtrCnsGimnasios=0;
SiscomLeeEntradaOperaciones2(pSAgsSiscom);
SiscomCopiaArgumentosConsulta(pSAgsSiscom);
SiscomContenidoProtocolo(pSAgsSiscom->LCSiscomPro2Dat);
ComunicacionAccesoDatosSepomex=ComunicacionExpendioConsulta;
ComunicacionSeguridad=ComunicacionExpendioConsulta;
SiscomAnexaOperacion2("EscuelasExpendio",OPEscuelas(),&lSSOperaciones);
SiscomAnexaOperacion2("HistoricoCompras",OpCompras(),&lSSOperaciones);
SiscomAnexaOperacion2("HistoricoComprasExistenciaMinima",
		      OpComprasExistenciaMinima(),
		      &lSSOperaciones);
SiscomAnexaOperacion2("EmpleadosSiscom",OPEmpleados(),&lSSOperaciones);
SiscomAnexaOperacion2("CalculaCambio",OpCalculaCambio(),&lSSOperaciones);
SiscomAnexaOperacion2("VentasPorCaja",OpVentasPorCaja(),&lSSOperaciones);
SiscomAnexaOperacion2("VentasPorCajaFecha",
		       OpVentasPorCajaFecha(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("CajasRegistradas",OpCajasRegistradas(),&lSSOperaciones);
SiscomAnexaOperacion2("CajasYControles",
		       OpCajasYControles(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("ControlesCaja",
		       OpControlesCaja(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("ProductosOrden",
		       OpProductosOrden(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("Ganancias",
		       OpGanancia(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("FacturasCompras",
		       OpFacturasComprasPorFecha(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("ProveedoresRegistrados",
		       OpProveedores(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("DetalleFactura",
		       OpDetalleFactura(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("BuscaFacturas",
		       OpBuscaFacturas(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("OrdenesVendidasSiscom",
		       OpOrdenesVendidasSiscom(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("DetalleOrden",
		       OpDetalleOrden(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("EjecutaProcesoContabilidad",
		       OpEjecutaContabilidad(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("Transferencias",
		       OpTransferencias(),
		       &lSSOperaciones);


SiscomAnexaOperacion2("ReporteSemestral",
		       OpReporteSemestral(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("AlumnosExpendio",
		       OPAlumnosExpendio(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("ReportePorExistenciaMinima",
		       OpReportePorExistenciaMinima(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("ExpendiosSiscom",
		       OPExpendios(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("BodegasExpendio",
		       OPBodegas(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("ExistenciaProductoBodega",
		       OPExistenciaProductoBodega(),
		       &lSSOperaciones);


SiscomAnexaOperacion2("ExistenciasProductos",
		       OpExistenciasProductos(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("ExistenciasProductosPorCasiClave",
		       OpExistenciasProductosPorCasiClave(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("ExistenciasExpendio",
		       OpExistenciasExpendio(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("ExistenciasProductosBodega",
		       OpExistenciasProductosBodega(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("ProductosPorcentajeExistenciaMinima",
		       OpProductosPorcentajeExMinima(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("PuntosPromocionCliente",
		       OpPuntosPromocionesCliente(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("ClientesSiscom",
		       OpClientes(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("MotivoInventario",
                       OPMotivoInventario(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("InventariosProgramados",
                       OpInventariosProgramados(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("SincronizaExpendio",
		       OpSincronizaExpendio(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("Cursos",
		       OpCursos(),
		       &lSSOperaciones);
SiscomAnexaOperacion2("FechasCursos",
		       OpFechasCursos(),
		       &lSSOperaciones);


SiscomAnexaOperacion2("CursosProgramados",
		       OpCursosProgramados(),
		       &lSSOperaciones);


SiscomAnexaOperacion2("AlumnosInscritosCurso",
		       OpAlumnosInscritosCurso(),
		       &lSSOperaciones);


SiscomAnexaOperacion2("DisponibilidadCursos",
		       OpDisponibilidadCursos(),
		       &lSSOperaciones);

SiscomAnexaOperacion2("ProgramacionPlacas",
		       OpProgramacionPlacas(),
		       &lSSOperaciones);


SiscomAnexaOperacion2("ServiciosSiscom",
		       OpServicios(),
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

SiscomAnexaOperacion2("SiscomInfoVariable",
		       SiscomOpInfoVariable(),
		       &lSSOperaciones);

lSOpPtrCnsGimnasios=SiscomOperaciones2CualEjecuta(
                                pSAgsSiscom->chrPtrArgConsulta[0],
				lSSOperaciones,
				ConsultaNoSoportada,
				pSAgsSiscom);
SiscomOperaciones2Ejecuta(lSOpPtrCnsGimnasios,pSAgsSiscom);
}

void ConsultaNoSoportada(SArgsSiscom *pSAgsSiscom)
{
SiscomLog("------");
}
