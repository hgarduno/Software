Archivos_SiscomElectronica2=O/Errores.o				\
			    O/ComunElectronica2.o		\
			    O/Consultas.o			\
			    O/Escuelas.o			\
			    O/Alumnos.o				\
			    O/Empleados.o			\
			    O/Compras.o				\
			    O/PagoCambio.o			\
			    O/ImporteDenominaciones.o		\
			    O/VentasCaja.o			\
			    O/CorteCaja.o			\
			    O/SeguridadCajas.o			\
			    O/ControladorOrdenes2.o		\
			    O/Devoluciones.o			\
			    O/Ganancias.o			\
			    O/ProductosSinOrden.o		\
			    O/Facturas.o			\
			    O/Proveedores2.o			\
			    O/Ordenes.o				\
			    O/Contabilidad.o			\
			    O/Direcciones.o			\
			    O/Transferencias.o			\
			    O/ReporteSemestral.o		\
			    O/ReportePorExistenciaMinima.o	\
			    O/Impresion.o			\
			    O/Expendios.o			\
			    O/Bodegas.o				\
			    O/Clientes.o			\
			    O/OrdenesAFacturar.o		\
			    O/SincronizaExpendio.o		\
			    O/IniciaExpendios.o			\
			    O/CambiaEliminaClave.o		\
			    O/ExistenciasProductos.o		\
			    O/PromocionesElectronica.o		\
			    O/PuntosPromocionesCliente.o	\
			    O/TomaPromociones.o			\
			    O/ActualizaDatosAlumno.o		\
			    O/RastreaProducto.o			\
			    O/MotivoInventario.o		\
			    O/ProgramacionInventario.o		\
			    O/OrdenesCajaCentralizada.o		\
			    O/SalidaMaterial.o			\
			    O/ProductosNoSincronizados.o	\
			    O/Cursos.o				\
			    O/Servicios.o			\
			    O/ActualizaExpendio.o		\
			    O/ImprimeComprobanteCurso.o		\
			    O/ManejoCapacitores.o		\
			    O/OrigenCompra.o			\
			    O/RegistraCursos.o			\
			    O/PedidoMaterial.o			\
			    O/ClavesProveedores.o		\
			    O/AnalisisOrdenCompra.o		\
			    O/ManejadorKits.o			\
			    O/ProductosFaltantes.o		\
			    O/ProgramacionPlacas.o		\
			    O/SqlSeguridadCajas.o		\
			    O/SQLEscuelas.o			\
			    O/SQLAlumnos.o			\
			    O/SqlCompras.o			\
			    O/SqlEmpleados.o			\
			    O/SqlVentasCaja.o			\
			    O/SqlCorteCaja.o			\
			    O/SqlControladorOrdenes.o		\
			    O/SqlDevoluciones.o			\
			    O/SqlGanancias.o			\
			    O/SqlFacturas.o			\
			    O/SqlProveedores.o			\
			    O/SqlOrdenes.o			\
			    O/SqlContabilidad.o			\
			    O/SqlTransferencias.o		\
			    O/SqlReporteSemestral.o		\
			    O/SqlReportePorExistenciaMinima.o	\
			    O/SqlExpendios.o			\
			    O/SqlBodegas.o			\
			    O/SqlClientes.o			\
			    O/SqlOrdenesAFacturar.o		\
			    O/SqlIniciaExpendios.o		\
			    O/SqlImpresion.o			\
			    O/SqlCambiaEliminaClave.o		\
			    O/SqlExistenciasProductos.o		\
			    O/SqlPromocionesElectronica.o	\
			    O/SqlPuntosPromocionesClientes.o	\
			    O/SqlTomaPromocion.o		\
			    O/SqlRastreaProducto.o		\
			    O/SqlMotivoInventario.o		\
			    O/SqlProgramacionInventario.o	\
			    O/SqlCajaCentralizada.o		\
			    O/SqlMotivosSalidas.o		\
			    O/SqlSalidaMaterial.o		\
			    O/SqlProductosNoSincronizados.o	\
			    O/SqlCursos.o			\
			    O/SqlServicios.o			\
			    O/SqlActualizaExpendio.o		\
			    O/SqlManejoCapacitores.o		\
			    O/SqlOrigenCompra.o			\
			    O/SqlEmpresas.o			\
			    O/SqlCorreos.o			\
			    O/SqlTelefonos.o			\
			    O/SqlPedidoMaterial.o		\
			    O/SqlClavesProveedores.o		\
			    O/SqlManejadorKits.o		\
			    O/SqlProductosFaltantes.o		\
			    O/SqlOrdenCompra.o			\
			    O/SqlProgramacionPlacas.o


Bibliotecas=-L$(DIRLIBSISCOM2)  		\
		-lSiscomDesarrollo2  		\
		-lSiscomSeguridad3Prot2   	\
		-lSiscomSepomex			\
		-lSiscomAplicacionesSvr		\
		-lcups

Include=-IH 							\
	-I $(DIRDesarrolloHGE)/SISCOMDesarrollo2/H 		\
	-I$(DIRDesarrolloHGE)/SISCOMDesarrollo2/Servidor/H 	\
	-I$(DIRDesarrolloHGE)/SISCOMElectronica/Servidor/H	\
	-I$(DIRDesarrolloHGE)/SISCOMSeguridad3/Servidor2/H	\
	-I$(DIRDesarrolloHGE)/Sepomex/Servidor/H		\
	-I$(DIRDesarrolloHGE)/SiscomAplicaciones/Servidor/H	\
	-I$(DirectorioSiscomElectronica)/Servidor/H
OpC= -c  $(DEBUG) $(OpCSiscom)
OpShared= -shared $(DEBUG) $(OpCSiscom)
OpBinarios= $(DEBUG) $(OpCSiscom)

Binarios= 					\
	 libSiscomElectronica2.so   		

	 	

all:DirectorioO $(Binarios) 

DirectorioO:
	-mkdir O
libSiscomElectronica2.so:$(Archivos_SiscomElectronica2)
	@echo Generando $@
	@$(GCC) $(OpShared) -o $@ $(Archivos_SiscomElectronica2) $(Bibliotecas)
O/%.o:C/%.c
	@echo CC `basename $@`
	@$(GCC) $(OpC) -o $@ $< $(Include) 

clean:
	-rm $(Binarios)
	-rm O/*.o
	
	

all:
