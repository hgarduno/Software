#include <SiscomElectronica.h>
#include <ServidorGeneral.h>
#include <Consultas.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <Errores.h>
#include <Sepomex.h>
#include <Empleados.h>
#include <ImporteDenominaciones.h>
#include <VentasCaja.h>
#include <SeguridadCajas.h>
#include <Devoluciones.h> 
#include <ProductosSinOrden.h>
#include <Facturas.h>
#include <Ordenes.h>
#include <Impresion.h>
#include <Bodegas.h>
#include <Clientes.h>
#include <OrdenesAFacturar.h>
#include <Expendios.h>
#include <CambiaEliminaClave.h>
#include <PuntosPromocionesCliente.h>
#include <PromocionesElectronica.h>
#include <TomaPromociones.h>
#include <ActualizaDatosAlumno.h>
#include <RastreaProducto.h>
#include <ProgramacionInventario.h>
#include <OrdenesCajaCentralizada.h>
#include <IniciaExpendios.h>
#include <Ordenes.h>
#include <ProductosSinOrden.h>
#include <SalidaMaterial.h>
#include <ProductosNoSincronizados.h>
#include <Cursos.h>
#include <Servicios.h>
#include <ActualizaExpendio.h>
#include <ImprimeComprobanteCurso.h>
#include <OrigenCompra.h>
#include <Transferencias.h>
#include <PedidoMaterial.h>
#include <ClavesProveedores.h>
#include <AnalisisOrdenCompra.h>
#include <ManejadorKits.h>
#include <ProductosFaltantes.h>
/*
 *  Ciudad de Mexico a 30 de Julio del 2021 
 *  En medio del Covid , seguimos ...
 * Revisar porque al poner esta linea 
 * marca los errores de conflicto de declaracion
 * de funciones 
 * #include <CorteCaja.h> *
 *
 */
#include <SiscomElectronica2/Servidor/H/CorteCaja.h>
#include <SiscomElectronica4.h>


#include <ProgramacionPlacas.h>
void Principal(int pintSocket)
{
SSiscomOperaciones *lSSiscomOp=0;
int lintContador;
char *lchrPtrOperacion=0;
int lintNRegistros;
int lintVersionProtocolo;
SSiscomOperaciones2 *lSOpPtrOperaciones=0;
SiscomOperaciones2 *lSOpPtrSistema;
SArgsSiscom lSArgsSiscomDat;
	memset(&lSArgsSiscomDat,0,sizeof(SArgsSiscom));
	OperacionesSistemaGeneral(&lSSiscomOp);
	if((lintVersionProtocolo=SiscomVersionProtocolo(pintSocket))==2)   
	{
	SiscomLeeNumeroRegistros(pintSocket,
				 &lintNRegistros);	
	SiscomLeeOperacion(pintSocket,
                           &lchrPtrOperacion);
	SiscomLog("La Operacion (%s)",lchrPtrOperacion);
	for(lintContador=0;
            lintContador<lSSiscomOp->intNumOperaciones;
            lintContador++)
        if(!strcmp((lSSiscomOp+lintContador)->chrPtrOperacion,
                   lchrPtrOperacion))
        {
             (lSSiscomOp+lintContador)->Operacion(pintSocket,lintNRegistros);
             return ;
        }
	AsignaOperacionesVersion2(pintSocket,
				  lintNRegistros,
				  &lSOpPtrOperaciones,
				  &lSArgsSiscomDat);
	ManejadorErrores(&lSArgsSiscomDat);
	SiscomLog("(%s)",lchrPtrOperacion);
	lSOpPtrSistema=SiscomOperaciones2CualEjecuta(
				lchrPtrOperacion,
				lSOpPtrOperaciones,
				SiscomErrorOperacion2,
				&lSArgsSiscomDat);

	SiscomOperaciones2Ejecuta(lSOpPtrSistema,
				  &lSArgsSiscomDat);
	}
	else
	if(lintVersionProtocolo==4)
	SiscomProtocoloVersion4(pintSocket);
}

void AsignaOperacionesVersion2(int pintSocket,
			       int pintNRegistros,
			       SSiscomOperaciones2 **pSSOperaciones2,
			       SArgsSiscom *pSArgsSiscom)
{
pSArgsSiscom->intSocketCliente=pintSocket;
pSArgsSiscom->intNRegistrosDat=pintNRegistros;
SiscomAnexaOperacion2("ConsultasSiscomElectronica2",
		      OPConsultas(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraAlumno",
		      OPRegistraAlumno(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("RegistraSueldo",
		      OpCambiaSueldo(),
		      pSSOperaciones2);
SiscomAnexaOperacion2("ImporteDenominacion",
		       OpImporteDenominacion(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistraImporteCaja",
		       OpRegistraImporteCaja(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("RegistraCorteCaja",
		       OpRegistraCorteCaja(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("ActualizaEdoControlCaja",
		       OpActualizaEdoControlCaja(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("CalculaDevolucion",
		       OpCalculaDevolucion(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("EjecutaDevolucion",
		       OpEjecutaDevolucion(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistraProductoSinOrden",
		       OpRegistraProductosSinOrden(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("ActualizaNumeroFactura",
		       OpActualizaNumeroFactura(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("AnexarOrdenContabilidad",
		       OpAnexarOrdenContabilidad(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("AnexaFacturasContabilidad",
		       OpAnexaFacturasCompras(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("ImprimeTicketVenta",
		       OpImprimeTicketVenta(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("TransfiereBodegaExpendio",
		       OPTransfiereBodegaExpendio(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("InventarioBodega",
		       OPInventarioBodega(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistraClienteFisica",
		       OPRegistraCliente(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistraClienteMoral",
		       OPRegistraClienteMoral(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("OrdenesAFactuar",
		       OpOrdenesAFacturar(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistroExpendio",
		       OpRegistraExpendio(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("ActualizaDatosExpendio",
		       OpActualizaDatosExpendio(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("IniciaDatosExpendio",
		       OpIniciaDatosExpendio(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("CambiaClave",
		       OpCambiaClave(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("EliminaProducto",
		       OpEliminaClave(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistraPromocion",
		       OpRegistraPromocion(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("ValidaPuntosPromocionesSel",
		       OpValidaPuntosPSelecionadas(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("TomaPromociones",
		       OpTomaPromociones(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("ObtenDatosAlumno",
		       OpDatosAlumno(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("ActualizaDatosAlumno",
		       OpActualizaDatosAlumno(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RastreaProducto",
		       OpRastreaProducto(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistraProgramacionInventario",
		       OpRegistraProgramacionInventario(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("OrdenesPendientes",
		       OpOrdenesPendientes(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("VendeOrdenCajaCentral",
		       OpVendeOrdenCajaCentral(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("MotivosSalidas",
		       OpMotivosSalidas(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistraSalidaMaterial",
		       OpRegistraSalidaMaterial(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("ProductosNoSincronizados",
		       OPProductosNoSincronizados(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("EnviaSincronizacionProductos",
		       OpEnviaSincronizacionProductos(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistraAlumnoCurso",
		       OpRegistraAlumnoCurso(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("FechasCostosCursos",
		       OpFechasCostosCursos(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("CostosCurso",
		       OpCostosCurso(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("AlumnoYaRegistrado",
		       OpAlumnoYaRegistrado(),
		       pSSOperaciones2);


SiscomAnexaOperacion2("ValidaCamposMinimosRegistroAlumno",
		       OpValidaCamposMinimosRegistroAlumno(),
		       pSSOperaciones2);


SiscomAnexaOperacion2("InscribeClienteCurso",
		       OpInscribeClienteCurso(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("VentasCursos",
		       OpVentasCursos(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("RegistraAlumno2",
		       OPRegistraAlumno2(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("RegistraAlumnoServicio",
		       OpRegistraAlumnoServicio(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("AlumnosServiciosSinRegistroSalida",
		       OpAlumnosServicioSinRegSalida(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("RegistraSalidaAlumnoServicio",
		       OpRegistraSalidaServicio(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("RegistraProgramacionCursos",
		       OpRegistraProgramacionCursos(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("CursosProgramadosFechaRegistro",
		       OpCursosProgramadosFechaRegistro(),
		       pSSOperaciones2);


SiscomAnexaOperacion2("ProductosEnMatrizNoExpendio",
		       OpProductosNoExpendio(),
		       pSSOperaciones2);


SiscomAnexaOperacion2("SincronizaProductosAlExpendio",
		       OpSincronizaProductosNoExpendio(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistraAlumnoSiscom",
		       OPRegistraAlumnoSiscom(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("ImprimeComprobanteCurso",
		       OpImprimeComprobanteCurso(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistraHorarioCurso",
		       OpRegistraHorarioCurso(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("ProgramandoCurso",
		       OpProgramandoCurso(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("ConsultaCursosProgramados",
		       OpConsultaCursosProgramados(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("ExplicacionPromocion",
		       OpExplicacionPromocion(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("RegistraCostosCurso",
		       OpRegistraCostosCurso(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("OrigenCompra",
		       OpOrigenCompra(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistraFactura",
		       OpRegistraFactura(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("ReEnviaTransferencia",
		       OpReEnviaTransferencia(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("RegistraPedidoMaterial",
		       OpRegistraPedidoMaterial(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("PedidosExpendios",
		       OpPedidosExpendios(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("ActualizaEstadoPedidoMaterial",
		       OpActualizaEstadoPedido(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("ActualizaCantidadProductoPedido",
		       OpActualizaCantidadProductoPedido(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("ImprimePedido",
		       OpImprimePedido(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("ClavesProveedor",
		       OpClavesProveedores(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("ActualizaClaveProveedor",
		       OpActualizaClaveProveedor(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("DatosComprasProducto",
		       OpDatosComprasProducto(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("ValidaExistenciaExpendio",
		       OpValidaExistenciaExpendio(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RecibePedido",
		       OpRecibePedidoMaterial(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("RegistraTipoProducto",
		       OpRegistraTipoProducto(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("ProductosAlTipoProducto",
		       OpRegistraProductosTipoProducto(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("ProductosFaltantes",
		       OpProductosFaltantes(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("PedidosPendientesPorEnviarAMatriz",
		       OpPedidosPendientesPorEnviarAMatriz(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("DetallePedidoPendientePorEnviarAMatriz",
		       OpDetallePedidoPendientePorEnviarAMatriz(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("EnviaPedidoPendientePorEnviarAMatriz",
		       OpEnviaPedidoPendientePorEnviarAMatriz(),
		       pSSOperaciones2);
SiscomAnexaOperacion2("EnviaPedidoPendientePorEnviarAMatriz",
		       OpEnviaPedidoPendientePorEnviarAMatriz(),
		       pSSOperaciones2);

SiscomAnexaOperacion2("EntregaPlaca",
		       OpEntregarPlaca(),
		       pSSOperaciones2);
}

void SiscomErrorOperacion2(SArgsSiscom *pSAgsSisPtr)
{
SiscomLog("Porque no esta soportada");
SiscomLog("Operacion No Soportada");
}
void OperacionesSistemaGeneral(SSiscomOperaciones **pSSiscomOp)
{
	SiscomIniciaOperaciones(100,pSSiscomOp);
	SiscomAnexaOperacion("ConsultaPersonas",
			     ConsultaPersonas,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaProductos",
			     ConsultaProductos,
			     pSSiscomOp);
	SiscomAnexaOperacion("CotizaDispositivos",
			     CotizaDispositivos,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaEscuelas",
			     ConsultaEscuelas,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaMaterias",
			     ConsultaMaterias,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaPracticas",
			     ConsultaPracticas,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaEmpresas",
			     ConsultaEmpresas,
			     pSSiscomOp);
	SiscomAnexaOperacion("AsignaEmpleadosExp",
			     AsignaEmpleadosExp,
			     pSSiscomOp);
	SiscomAnexaOperacion("RegistraVentas",
			     RegistraVentas,
			     pSSiscomOp);
	SiscomAnexaOperacion("RegistraDatosClienteF",
			     RegistraDatosClienteF,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaDatosClienteF",
			     ConsultaDatosClienteF,
			     pSSiscomOp);
	SiscomAnexaOperacion("RegistraInventario",
			     RegistraInventario,
			     pSSiscomOp);
	SiscomAnexaOperacion("RegistraCompras",
			     RegistraCompras,
			     pSSiscomOp);
	SiscomAnexaOperacion("RegistraEscuelas",
			     RegistraEscuelas,
			     pSSiscomOp);
	SiscomAnexaOperacion("RegistraMaterias",
			     RegistraMaterias,
			     pSSiscomOp);
	SiscomAnexaOperacion("RegistraPracticas",
			     RegistraPracticas,
			     pSSiscomOp);
	SiscomAnexaOperacion("RegistraDetallePractica",
			     RegistraDetallePractica,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaFamilias",
			     ConsultaFamilias,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaUnidades",
			     ConsultaUnidades,
			     pSSiscomOp);
	SiscomAnexaOperacion("ActualizaProducto",
			     ActualizaProducto,
			     pSSiscomOp);
	SiscomAnexaOperacion("RegistraFamilias",
			     RegistraFamilias,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaSeguridad3Pro2",
			     ConsultaSeguridad3Pro2,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaSeguridad3Pro2Version2",
			     ConsultaSeguridad3Pro2Version2,
			     pSSiscomOp);
	SiscomAnexaOperacion("RegistraEmpresas",
			     RegistraEmpresas,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaReportesVentas",
			     ConsultaReportesVentas,
			     pSSiscomOp);
	
	SiscomAnexaOperacion("ConsultaProductosDescripcion",
			     ConsultaProductosDescripcion,
			     pSSiscomOp);
	SiscomAnexaOperacion("RegistraProductos",
			     RegistraProductos,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaTipoPrecios",
			     ConsultaTipoPrecios,
			     pSSiscomOp);
	SiscomAnexaOperacion("ActualizaPrecio",
			     ActualizaPrecio,
			     pSSiscomOp);
	SiscomAnexaOperacion("TransfiereProductos",
			     TransfiereProductos,
			     pSSiscomOp);
	SiscomAnexaOperacion("RegistraPersonas",
			     RegistraPersonas,
			     pSSiscomOp);
	SiscomAnexaOperacion("IniciaExpendio",
			     IniciaExpendio,
			     pSSiscomOp);
	SiscomAnexaOperacion("CambiaEstadoFirma",
			     CambiaEstadoFirma,
			     pSSiscomOp);
	SiscomAnexaOperacion("ActualizaExistenciaMinima",
			     ActualizaExistenciaMinima,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaVentasPorHora",
			     ConsultaVentasPorHora,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaControladorOrdenes",
			     ConsultaControladorOrdenes,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaSepomex",
			      ConsultaSepomex,
			     pSSiscomOp);
	SiscomAnexaOperacion("ConsultaSeguridad3Pro2",
			      ConsultaSeguridad3Pro2,
			      pSSiscomOp);

	SiscomAnexaOperacion("ValidaExistencia",
			     ValidaExistencia,
			     pSSiscomOp);
	SiscomAnexaOperacionesAlFinal(gSSiscomOpSistema,pSSiscomOp);
}
