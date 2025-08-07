include ../../SISCOMComunYUtilerias/MakefileQTSiscomDesarrollo3.mk
Archivos_O_SISCOMTiendasMini=O/SISCOMVentanaPrincipal.o O/AplicacionVersion3.o O/MOC_SISCOMVentanaPrincipal.o
Archivos_QT_SISCOMTiendasMini=CPP/MOC_SISCOMVentanaPrincipal.cpp

Archivos_O_SISCOMVentasExpendio=O/AplicacionVentasExpendio.o 

Archivos_QT_SISCOMTiendas3=CPP/MOC_SISCOMVentanaPrincipal3.cpp \
			   CPP/MOC_SiscomElectronica.cpp

Archivos_O_SISCOMTiendas3= 					\
			  O/AplicacionTiendas.o			\
			  O/zLineaComandosTiendas.o		\
			  O/zEjecucionTienda.o			\
			  O/zManejadorEjecucion.o		\
			  O/zXY.o				\
			  O/SiscomElectronica.o			\
			  O/MOC_SiscomElectronica.o

Archivos_O_InsertaProductosSaberElectronica=O/InsertaProductosSaberElectronica.o
Archivos_O_libSISCOMTiendas3=O/SISCOMVentanaPrincipal3.o \
			  O/MOC_SISCOMVentanaPrincipal3.o 


BibliotecasTiendas3=-L SO 				\
		    -L $(QTDIR)/plugins/designer	\
		    -L ../SiscomElectronica3/SO		\
		    -lFirmaTiendas 			\
		    -lAccesoSiscomElectronica		\
		    -lSelExpendios 			\
		    -lCapturaRangoFechas 		\
		    -lSiscomElectronicaComun 		\
		    -lCapturaDato 			\
		    -lFirmateExpendio 			\
		    -lSISCOMTiendas3			\
		    -lControlFechaDesarrollo2		\
		    -lPantallasSiscomElectronica2009	\
		    -lPantallasSiscomElectronica3 
Archivos_O_PruebasGrafica=O/PruebasGrafica.o
BibliotecasPruebasGrafica=-LSO -L$(QTDIR)/lib -lqt-mt -lSiscomElectronicaComun -lCapturaDato
#{{Archivos_O_SiscomElectronicaComun=					
Archivos_O_SiscomElectronicaComun=					\
				  O/Personas.o 				\
				  O/ProductosE.o 			\
				  O/CotizaDispositivos.o 		\
				  O/Materias.o				\
				  O/Escuelas.o 				\
				  O/Practicas.o 			\
				  O/EmpresasN.o  			\
				  O/Ventas.o 				\
				  O/DatosClienteF.o			\
				  O/ManInventario.o			\
				  O/ComprasE.o				\
				  O/Familias.o				\
				  O/Unidades.o				\
				  O/Direcciones.o			\
				  O/PuntosHoras.o			\
				  O/MediosComunicacion.o		\
				  O/ReportesVentas.o			\
				  O/TipoPrecios.o			\
				  O/TransfiereProducto.o		\
				  O/MenuOrdenElectronica.o		\
				  O/QEspacioExpendios.o			\
				  O/QControlesGrafica.o			\
				  O/QControlSemanaVenta.o		\
				  O/OrdenesHora.o			\
				  O/GraficaOrdenes.o			\
				  O/ProductosI.o			\
				  O/InventariosDia.o			\
				  O/CSisDatosSemana.o			\
				  O/QControlMesVenta.o			\
				  O/ControladorOrdenes.o		\
				  O/SisProductos2.o			\
				  O/CQSisVentasCaja.o			\
				  O/CQSis3QtComunes.o			\
				  O/CQSisPuntosElectronica.o		\
				  O/CQSisManejoPromociones.o		\
				  O/CQSisPromocionesCliente.o		\
				  O/CQSisFactura.o			\
				  O/CQSisWidgetPedidoExpendio.o		\
				  O/MOC_Familias.o			\
				  O/MOC_Unidades.o			\
				  O/MOC_MenuOrdenElectronica.o 		\
				  O/MOC_ProductosE.o			\
				  O/MOC_TipoPrecios.o			\
				  O/MOC_QEspacioExpendios.o		\
				  O/MOC_QControlesGrafica.o		\
				  O/MOC_CQSisWidgetPedidoExpendio.o	\
				  O/MOC_IMP_ModuloVentas.o		\
				  O/MOC_IMP_ModuloPedido.o		\
				  O/MOC_IMP_ModuloVentasMayoreo.o	\
				  O/MOC_IMP_MenuManejadorOrden.o	\
				  O/MOC_IMP_SeleccionaOrden.o
#}}				  
Archivos_QT_SiscomElectronicaComun=CPP/MOC_MenuOrdenElectronica.cpp 
OpCompilacion=-g -c  $(DEBUG) $(OpCSiscom) -DQT_THREAD_SUPPORT 
OpEnlace+=$(OpCSiscom)

#{{{   Includes 
Include=-I $(QTDIR)/include  					\
	-I. 							\
	-I H 							\
	-I $(SISCOM_LIB_DIR)/Include  				\
	-I $(DIRLIBSISCOM2)/H					\
	-I ../SiscomElectronica3/H				\
	-I SiscomElectronica2/Cliente/H				\
	-I $$QtInclude						\
	-I $(DIRDesarrolloHGE)/SiscomComunicaciones++/H 	\
	-I $(DIRDesarrolloHGE)/SiscomDesarrollo4++/H		\
	-I $(DIRDesarrolloHGE)/SiscomDesarrollo4Qt++/H		\
	-I $(DIRDesarrolloHGE)/SiscomSoporte/Qt/H


#}}}


#{{{ Bibliotecas 
BibliotecasViejas=-L $(SISCOM_LIB_DIR) \
	      -L . -L $(QTDIR)/lib  \
	      -L $(QTDIR)/plugins/designer \
	      -lInterfazSISCOMTiendasFirmaUsuario2 \
	      -lqui \
	     -lSISCOMSeguridad3Q++  \
	     -lSISCOMDesarrollo++  


Bibliotecas= -L SO -L $(QTDIR)/lib  		\
	     -L $(QTDIR)/plugins/designer	\
		-lqt-mt 			\
		-lqui				\
		-lControlSiscomElectronica3	\
		-lControlSepomexComunicas	\
		-lControlEscuelas		\
		-lSiscomSoporte

BibliotecasDesarrollo= \
			-L $(QTDIR)/lib					\
	     		-L $(DIRLIBSISCOM2)				\
			-L $(DIRDesarrolloHGE)/SiscomComunicaciones++	\
			-lSiscomComunicaciones++			\
			-lqt-mt						\
			-lqui						\
			-lSiscomDesarrollo3Qt++				\
			-l:libSiscomComunicaciones++.so.1.0.0
			

			

BibliotecasDesarrolloExtra=-LSO/  			\
			   -L$(QTDIR)/plugins/designer 	\
			   -lCapturaDato  		\
			   -lCapturaRangoFechas 	\
			   -lControlFechaDesarrollo2	\
			   -lPantallasSiscomElectronica2009
Bibliotecas2=-L $(QTDIR)/lib -L SO 		\
		-lqt-mt 			\
		-lVentasElectronica 		\
		-lOrdenElectronica 		\
		-lCNSClientes			\
		-lSiscomElectronicaComun 	\
		-lCotizaDispositivos 		\
		-lSelOrden 			\
		-lCotizaPractica 		\
		-lSelExpendios 			\
		-lCapturaDato 			\
		-lAvisoNoAlcanza 		\
		-lFirmateExpendio
OpModulos=-shared  $(DEBUG) $(OpCSiscom)

Bibliotecas_CNSClientes=-LSO -lSiscomElectronicaComun 
Bibliotecas_VentasElectronica=-LSO 				\
			      -L $(QTDIR)/plugins/designer	\
				-lCNSClientes 			\
				-lCotizaDispositivos  		\
				-lSelOrden  			\
				-lCotizaPractica 		\
				-lSelExpendios 			\
				-lPantallasSiscomElectronica2009 
Bibliotecas_OrdenElectronica=-LSO 			\
				-lCapturaDato 		\
				-lAvisoNoAlcanza 	\
				-lOpcionCerrar  	\
				-lCapturaNoCotizacion	
Bibliotecas_AvisoNoAlcanza=-LSO \
			   -lCapturaDato
Bibliotecas_SelOrden=-LSO \
		       -lOrdenElectronica
Bibliotecas_EmpleadosExpendio=-LSO \
			       -lSelExpendios 
Bibliotecas_FirmateTienda=-LSO/ \
			  -lSiscomElectronicaComun
Bibliotecas_FirmaTiendas=-LSO/ 
Bibliotecas_Compras=-L $(QTDIR)/plugins/designer \
		    -lControlFechaDesarrollo2 	 \
		    -lCapturaIva
Bibliotecas_Inventario=-L SO \
			-lActualizaInventario
Bibliotecas_ContPracticas=-L SO \
			-lContEscuelas \
			-lContMaterias  \
			-lContDeLasPracticas \
			-lMaterialPractica
Bibliotecas_MaterialPractica=-LSO \
			     -lProductoPractica
Bibliotecas_ManejadorProductos=-LSO \
				-lMantenProductos 
Bibliotecas_ManejadorProveedores=-LSO \
				 -lCapturaTelefono \
				 -lCapturaContacto
Bibliotecas_Familias=-LSO \
		         -lCapturaDato
Bibliotecas_CotizaDispositivos=-LSO \
				-lProdSimilares \
				-lCapturaDato
Bibliotecas_ReportesVentas=-LSO \
			    -lCapturaRangoFechas
Bibliotecas_CapturaRangoFechas=-L$(QTDIR)/plugins/designer	\
				-L$(DIRLIBSISCOM2)	   	\
				-lControlFechaDesarrollo2 	\
				-lSISCOMComunControlesDesarrollo2 
Bibliotecas_CotizaPractica=-LSO \
			-lExtNoAlcanzan
Bibliotecas_MaterialAExpendio=-LSO \
				-lSelExpendios
Bibliotecas_RegistroEmpleados=-LSO \
				-lCapturaTelefono \
				-lSelExpendios 
Bibliotecas_CtrExpendios=-LSO \
			  -lSelExpendios \
			  -lSISCOMTiendas3 
Bibliotecas_CtrExistencias=-LSO \
			    -lRangoPorcentaje
Bibliotecas_OrdenesVendidas=-LSO \
			    -lOrdenesPorFecha \
			    -lFacturacion \
			    -lFacturando

#}}}
# Para poder utilizar las macros actuales, para la generacion de los 
# nombres de los archivos, se definira para cada pantalla en la cual
# se utiliza una macro como Pantallas ...., esto debido a que, para 
# el programa SISCOMElectronica, se desarrollo considerando un modulo
# dinamico por cada pantalla :)
#

PantallasOrdenElectronica=CapturaPago  

Archivos_O_Extra_OrdenElectronica=						\
		$(call ArchivosOSistemaFormas,$(PantallasOrdenElectronica))	

Archivos_QT_Extra_OrdenElectronica=						\
		$(call ArchivosQTSistemaFormas,$(PantallasOrdenElectronica))

# Domingo 20 de septiembre del 2009
# Tepotzotlan
# Para los nuevos requerimientos del sistema se agrega
# la manipulacion de las pantallas en la biblioteca 
# libSiscomElectronica2009.so

#{{{ Pantallas_SiscomElectronica2009
Pantallas_SiscomElectronica2009=VentasPorCaja 				\
				FormaPago				\
				ProductosSimilares			\
				CorteCaja 				\
				CapturaDenominacion			\
				AdministracionCajas			\
				SeguridadCajaVentas			\
				CambiaEdoControlCaja			\
				Devoluciones				\
				Ganancias				\
				RegProductoSinOrden			\
				Facturas				\
				BuscaProveedor				\
				CapturaNumFactura			\
				Contabilidad				\
				AnexarFactura				\
				Ordenes					\
				Facturando3				\
				RegistroClientes			\
				HistorialTransferencias			\
				ReporteSemestral			\
				ImprimeReporteSemestral			\
				ImprimeFactura				\
				SelAlumno				\
				RegistroRapidoAlumno			\
				MaterialBodegaExpendio			\
				InventarioBodega			\
				CapturaClientes				\
				OrdenesAFacturar			\
				SincronizaExpendio			\
				ManejadorExpendios			\
				CambiaEliminaClaveProducto		\
				PromocionesElectronica			\
				ActualizaPesosPPunto			\
				PuntosAlumnos				\
				ActualizaDatosAlumno			\
				RastreoProducto				\
				TotalVentasProducto			\
				TotalComprasProducto			\
				TransferenciasBodegasExpendio		\
				TransferenciasExpendioExpendio		\
				ProgramacionInventario			\
				SeleccionaInventario			\
				CapturaExistenciaFisica			\
				ProductosConDesajuste			\
				Caja					\
				SalidaMaterial				\
				ProductosSinSincronizar			\
				ControladorReportesVentasExpendios	\
				RegistroAlumnoCurso			\
				AlumnosInscritosCurso			\
				DisponibilidadCursos			\
				AlumnoRegistrado			\
				ReporteVentasCursos			\
				RegistroClienteSiscom			\
				RegistroAlumnoServicio			\
				ActualizaExpendio			\
				RegistroAlumno				\
				ProgramandoCurso			\
				RegistraProgramaCurso			\
				RegistraCostoCurso			\
				PedidoMaterial				\
				PedidoMaterial4				\
				CapturaObservacionPedidoProducto	\
				PedidosExpendios			\
				ClavesProveedores			\
				OrdenCompras				\
				RecibePedido				\
				ManejadorKits				\
				RegistraKit				\
				ProductosFaltantes			\
				Caja2					\
				PuntoVenta				\
				BalanceFinanciero			\
				AdministracionVentas			\
				FechaHoraEntrega			\
				PedidosPendientes			\
				ProgramacionPlacas			\
				DispositivosVendidos			\
				Facturando4				\
				SeleccionaOrdenFactura			\
				DatosFacturacion			\
				ProductosFaltantes4			\
				ExistenciaExpendios			\
				Pedidos					\
				ManejadorOrden				\
				ClientePedido				\
				ClienteAlumno				\
				AvisoNoAlcanza4				\
				RegistroApartado			\
				CierraApartado				\
				ProductoApartados			\
				DescripcionCotizacion			\
				Cotizaciones				\
				DatosPedido				\
				ManejadorPracticas			\
				SeleccionandoProducto			\
				ClientesRegistrados4			\
				EstadosPedido				\
				ReporteVentas4				\
				TransferenciaExpendioAExpendio		\
				NoAlcanzaProducto			\
				PedidosOtrosExpendios			\
				OrdenesDisponibles			\
				ReportandoVentas			\
				RegistroPlaca				\
				ManejadorImpresos			\
				ReEnvioFactura				\
				ClavesSatSiscom				\
				MaterialAreaDiseno			\
				DonacionMaterial			\
				GastosExpendio				\
				ExpendiosSE				\
				CierreCaja				\
				InventarioExpendio			\
				ComprasImportaciones			\
				CapturaPesoProducto			\
				ActualizaProductoImportado		\
				CierreDia				\
				SePagaOrdenImpreso			\
				RegistroProductosSiscom			\
				MuestraExistenciaExpendios		\
				PreciosExpendios			\
				CotizaImportacion			\
				RegistroCotizacionImportacion		\
				ActualizaProductoCotizacionImportacion	\
				CotizacionImportacionCierre		\
				DescripcionCompraImportacion		\
				SeleccionaCompraImp			\
				OrdenesRegistradas			\
				VendiendoOrden				\
				ClavesProveedor4			\
				OrdenCompraImportacion			\
				DatosPractica				\
				ManejadorProductos4			\
				RegistrarCajaMaterial			\
				OrdenesFavoritas			\
				CorteCajaSucursal			\
				ConExpendiosVenta			\
				PuntosEntrega				\
				ListaPuntosEntrega			\
				AdministradorPedidos			\
				SincronizaProductos			\
				CapturaDescripcionCotizacion		\
				CompraContenedor			\
				FacturaContenedor			\
				CompraContenedor2			\
				ProveedoresCompraImportacion		\
				ActualizaPrecioExpendios		\
				ExpendioOrigen				\
				Faltantes				\
				BodegasSiscom				\
				RegistroParcialComImp			\
				CapturaRangoHora			\
				AccionTraspasoBodegaExp			\
				ModuloBodegas				\
				InventarioBodega4			\
				TransfiereBodegaBodega			\
				ComoPago				\
				PagaConTransferencia			\
				DatosCorteCaja				\
				CapturaDatosFactura			\
				AbonoAApartado				\
				ContandoCortes				\
				ExistenciaSiscom			\
				ConsultaCompras

#}}}




Archivos_QT_PantallasSiscomElectronica2009=					\
	$(call ArchivosQTSistemaFormas,$(Pantallas_SiscomElectronica2009))	\
	CPP/MOC_QtPuntosEntrega.cpp						


#{{{ Archivos_O_PantallasSiscomElectronica2009=
Archivos_O_PantallasSiscomElectronica2009=					\
	$(call ArchivosOSistemaFormas,$(Pantallas_SiscomElectronica2009))	\
	O/CQSisVentasPorCaja.o							\
	O/CQSisCorteCaja.o							\
	O/CQSisCajas.o								\
	O/CQSisSeguridadCajaVentas.o						\
	O/QtSeguridadCajas.o							\
	O/CQSisProductosE3Qt.o							\
	O/CQSisDevoluciones.o							\
	O/CQSisGanancias.o							\
	O/CQSisProductosSinOrden.o						\
	O/CQSisFacturas.o							\
	O/CQSisProveedores.o							\
	O/CQSisOrdenes.o							\
	O/CQSisContabilidad.o							\
	O/CQSisHisTransferencias.o						\
	O/CQSisReporteSemestral.o						\
	O/CQSisProgramacionPlacas.o						\
	O/CQSisImprimeTicket.o							\
	O/CQSisImprimeComprobantePagoCurso.o					\
	O/CQSisProdBodExpendio.o						\
	O/CQSisInventarioBodega.o						\
	O/CQSisClientes.o							\
	O/CQSisExpendios.o							\
	O/CQSisAlumnos.o							\
	O/CQSisProductos4.o							\
	O/CQSisPromociones.o							\
	O/CQSisRastreoProducto.o						\
	O/CQSisProgramacionInventario.o						\
	O/CQSisOrdenCaja.o							\
	O/CQSisDatosOrdenCaja.o							\
	O/CQSisDatosMotivosSalidas.o						\
	O/CQSisMotivosSalidas.o							\
	O/CQSisProductoNoSincronizado.o						\
	O/CQSisPedidoMaterial.o							\
	O/CQSisOrdenCompra.o							\
	O/CQSisOpeOrdenCaja.o							\
	O/CQSisOpeMotivosSalidas.o						\
	O/CQSisOpeSalidaProductos.o						\
	O/CQSisOpeProductoNoSincronizado.o					\
	O/CQSisOpeImprimeComprobanteCurso.o					\
	O/CQSisOpeCursos.o							\
	O/CQSisKits.o								\
	O/CQSisProductoPorTipo.o						\
	O/CQSisProductosFaltantes.o						\
	O/QIconViewItemOrdenCaja.o						\
	O/QtSisImprime.o							\
	O/QtSisImprimeTabla.o							\
	O/QtSisImprimeMargen.o							\
	O/QtSisImprimeHoja.o							\
	O/QtSisImprimeEncabezados.o						\
	O/QtSisImprimeFactura.o							\
	O/QtSisImprimeFacturaCliente.o						\
	O/QtSisImprimeFacturaFecha.o						\
	O/QtSisImprimeFacturaProductos.o					\
	O/QtSisPuntoImpresion.o							\
	O/QtClientePedido.o							\
	O/QtManejadorOrden.o							\
	O/QtCotizaciones.o							\
	O/QtPuntosEntrega.o							\
	O/QtListaPuntosEntrega.o						\
	O/QtDatosPedido.o							\
	O/QtOrdenesRegistradas.o						\
	O/QtToolBoxOrdenes.o							\
	O/QtAdministradorPedidos.o						\
	O/QtSincronizaProductos.o						\
	O/QtCapturaDescripcionCotizacion.o					\
	O/QtCompraContenedor.o							\
	O/QtFacturaContenedor.o							\
	O/QtCapturaFacturaImp.o							\
	O/QtCompraContenedor2.o							\
	O/QtSincronizaExpendio.o						\
	O/QtActualizaPrecioExpendios.o						\
	O/QtExpendioOrigen.o							\
	O/QtRegistroParcialComImp.o						\
	O/QtModuloBodegas.o							\
	O/QtInventarioBodega4.o							\
	O/QtTransfiereBodegaBodega.o						\
	O/QtAbonoAApartado.o							\
	O/QtContandoCortes.o							\
	O/QtExistenciaSiscom.o							\
	O/QtConsultaCompras.o							\
	O/IMP_ModuloVentas.o							\
	O/IMP_ModuloVentasMayoreo.o						\
	O/IMP_ModuloPedido.o							\
	O/IMP_MenuManejadorOrden.o						\
	O/IMP_SeleccionaOrden.o							\
	O/zBodega.o								\
	O/zSiscomElectronica.o							\
	O/zProducto.o								\
	O/zProductoCotizar.o							\
	O/zOrdenVenta.o								\
	O/zOrdenes.o								\
	O/zFactura.o								\
	O/zPersona.o								\
	O/zCliente.o								\
	O/zEmpresa.o								\
	O/zDireccion.o								\
	O/zCorreo.o								\
	O/zTelefono.o								\
	O/zCorreos.o								\
	O/zTelefonos.o								\
	O/zEscuela.o								\
	O/zClienteSiscom.o							\
	O/zProductos.o								\
	O/zExistenciaExpendio.o							\
	O/zExistenciaExpendios.o						\
	O/zApartado.o								\
	O/zCotizacion.o								\
	O/zPedido.o								\
	O/zPractica.o								\
	O/zReporteVentas.o							\
	O/zProductosTransferir.o						\
	O/zProductoTransferir.o							\
	O/zCircuitoImpreso.o							\
	O/zOrdenCompra.o							\
	O/zProductoCompra.o							\
	O/zDatosReEnvioFactura.o						\
	O/zClaveSat.o								\
	O/zMaterialAAreaDiseno.o						\
	O/zDonacionMaterial.o							\
	O/zProductoPedido.o							\
	O/zPedidoExpendio.o							\
	O/zExpendios.o								\
	O/zExpendio.o								\
	O/zDenominacion.o							\
	O/zProductoInventario.o							\
	O/zCierreCaja.o								\
	O/zCompraImportacion.o							\
	O/zProductoImportado.o							\
	O/zProductosImportados.o						\
	O/zProductoSiscom.o							\
	O/zCompraProductoSiscom.o						\
	O/zCambioCaja.o								\
	O/zPrecios.o								\
	O/zProductoPrecio.o							\
	O/zPreciosExpendio.o							\
	O/zPreciosExpendios.o							\
	O/zPrecios2Producto.o							\
	O/zPrecio2Expendio.o							\
	O/zPrecios2Productos.o							\
	O/zPrecio2Expendios.o							\
	O/zCotizacionImportacion.o						\
	O/zCotizacionesImportacion.o						\
	O/zProductoCotImp.o							\
	O/zProductosCotImp.o							\
	O/zConCuantoPago.o							\
	O/zDirecciones.o							\
	O/zComprasImportacion.o							\
	O/zDevolucion.o								\
	O/zClaveProveedor.o							\
	O/zClavesProveedor.o							\
	O/zProductoCompraImportacion.o						\
	O/zCompraImportacionProducto.o						\
	O/zComprasImportacionProducto.o						\
	O/zProductosCompraImportacion.o						\
	O/zCajaMaterial.o							\
	O/zEstante.o								\
	O/zUbicacion.o								\
	O/zProductoImportadoInf.o						\
	O/zOrdenFavorita.o							\
	O/zOrdenesFavoritas.o							\
	O/zTextoWhatsApp.o							\
	O/zConexionExpendio.o							\
	O/zPuntoEntrega.o							\
	O/zPuntosEntrega.o							\
	O/zEscuelas.o								\
	O/zEmpresas.o								\
	O/zContenedor.o								\
	O/zCompraContenedor.o							\
	O/zOpsPuntosEntrega.o							\
	O/zOpsClientePedido.o							\
	O/zOpsAdministradorPedidos.o						\
	O/zCobertura.o								\
	O/zEstadoPedido.o							\
	O/zCotizacionMediaCenter.o						\
	O/zFacturaImportacion.o							\
	O/zPrecio.o								\
	O/zProductoPrecioExpendios.o						\
	O/zListaExpendios.o							\
	O/zCondicionConsultaOrdenes.o						\
	O/zBodegas.o								\
	O/zExistenciaBodega.o							\
	O/zTransfiereBodegaBodega.o						\
	O/zExistenciaBodegaOriDes.o						\
	O/zTransferenciasBodegaBodega.o						\
	O/zFormaPagoTransferencia.o						\
	O/zFormaPagoTarjeta.o							\
	O/zFormaPago.o								\
	O/zCambiosCaja.o							\
	O/zCorteCajaO.o								\
	O/zClientesSiscom.o							\
	O/zCorteCaja.o								\
	O/zCompraParcialImportacion.o						\
	O/zAbonoAApartado.o							\
	O/zAbonos.o								\
	O/zExistenciaVenta.o							\
	O/zExistenciaProducto.o							\
	O/zCompra.o								\
	O/zCompras.o								\
	O/MOC_QtClientePedido.o							\
	O/MOC_QtPuntosEntrega.o							\
	O/MOC_QtListaPuntosEntrega.o						\
	O/MOC_QtDatosPedido.o							\
	O/MOC_QtOrdenesRegistradas.o						\
	O/MOC_QtToolBoxOrdenes.o						\
	O/MOC_QtAdministradorPedidos.o						\
	O/MOC_QtSincronizaProductos.o						\
	O/MOC_QtCapturaDescripcionCotizacion.o					\
	O/MOC_QtCompraContenedor.o						\
	O/MOC_QtFacturaContenedor.o						\
	O/MOC_QtCapturaFacturaImp.o						\
	O/MOC_QtCompraContenedor2.o						\
	O/MOC_QtActualizaPrecioExpendios.o					\
	O/MOC_QtSincronizaExpendio.o						\
	O/MOC_QtExpendioOrigen.o						\
	O/MOC_QtRegistroParcialComImp.o						\
	O/MOC_QtCotizaciones.o							\
	O/MOC_QtModuloBodegas.o							\
	O/MOC_QtInventarioBodega4.o						\
	O/MOC_QtTransfiereBodegaBodega.o					\
	O/MOC_QtAbonoAApartado.o						\
	O/MOC_QtContandoCortes.o						\
	O/MOC_QtExistenciaSiscom.o						\
	O/MOC_QtConsultaCompras.o
	
#}}}

#{{{  Modulos Siscom Tiendas

$(eval $(call ArchivosBibliotecaQTForma,VentasElectronica))
$(eval $(call ArchivosBibliotecaQTForma,OrdenElectronica))
$(eval $(call ArchivosBibliotecaQTForma,CNSClientes))
$(eval $(call ArchivosBibliotecaQTForma,CotizaDispositivos))
$(eval $(call ArchivosBibliotecaQTForma,SelOrden))
$(eval $(call ArchivosBibliotecaQTForma,CotizaPractica))
$(eval $(call ArchivosBibliotecaQTForma,SelExpendios))
$(eval $(call ArchivosBibliotecaQTForma,CapturaDato))
$(eval $(call ArchivosBibliotecaQTForma,AvisoNoAlcanza))
$(eval $(call ArchivosBibliotecaQTForma,FirmaTiendas))
$(eval $(call ArchivosBibliotecaQTForma,AccesoSiscomElectronica))
$(eval $(call ArchivosBibliotecaQTForma,EmpleadosExpendio))
$(eval $(call ArchivosBibliotecaQTForma,FirmateExpendio))
$(eval $(call ArchivosBibliotecaQTForma,DatosClienteF))
$(eval $(call ArchivosBibliotecaQTForma,Compras))
$(eval $(call ArchivosBibliotecaQTForma,Inventario))
$(eval $(call ArchivosBibliotecaQTForma,ActualizaInventario))
$(eval $(call ArchivosBibliotecaQTForma,ContPracticas))
$(eval $(call ArchivosBibliotecaQTForma,ContEscuelas))
$(eval $(call ArchivosBibliotecaQTForma,ContMaterias))
$(eval $(call ArchivosBibliotecaQTForma,ContDeLasPracticas))
$(eval $(call ArchivosBibliotecaQTForma,MaterialPractica))
$(eval $(call ArchivosBibliotecaQTForma,ProductoPractica))
$(eval $(call ArchivosBibliotecaQTForma,ManejadorProductos))
$(eval $(call ArchivosBibliotecaQTForma,MantenProductos))
$(eval $(call ArchivosBibliotecaQTForma,Familias))
$(eval $(call ArchivosBibliotecaQTForma,ManejadorProveedores))
$(eval $(call ArchivosBibliotecaQTForma,CapturaTelefono))
$(eval $(call ArchivosBibliotecaQTForma,CapturaContacto))
$(eval $(call ArchivosBibliotecaQTForma,ProdSimilares))
$(eval $(call ArchivosBibliotecaQTForma,OpcionCerrar))
$(eval $(call ArchivosBibliotecaQTForma,ReportesVentas))
$(eval $(call ArchivosBibliotecaQTForma,CapturaRangoFechas))
$(eval $(call ArchivosBibliotecaQTForma,ManejadorPrecios))
$(eval $(call ArchivosBibliotecaQTForma,ExtNoAlcanzan))
$(eval $(call ArchivosBibliotecaQTForma,RegistroEmpleados))
$(eval $(call ArchivosBibliotecaQTForma,MaterialAExpendio))
$(eval $(call ArchivosBibliotecaQTForma,CapturaIva))
$(eval $(call ArchivosBibliotecaQTForma,CtrExpendios))
$(eval $(call ArchivosBibliotecaQTForma,CtrExistencias))
$(eval $(call ArchivosBibliotecaQTForma,CtrExistenciasMinimas))
$(eval $(call ArchivosBibliotecaQTForma,RangoPorcentaje))
$(eval $(call ArchivosBibliotecaQTForma,Clientes))
$(eval $(call ArchivosBibliotecaQTForma,ProductosInventariar))
$(eval $(call ArchivosBibliotecaQTForma,EstadoInventario))
$(eval $(call ArchivosBibliotecaQTForma,ProgramaInventario))
$(eval $(call ArchivosBibliotecaQTForma,EjecutaInventario))
$(eval $(call ArchivosBibliotecaQTForma,OrdenesVendidas))
$(eval $(call ArchivosBibliotecaQTForma,CapturaNoCotizacion))
$(eval $(call ArchivosBibliotecaQTForma,OrdenesPorFecha))
$(eval $(call ArchivosBibliotecaQTForma,Facturacion))
$(eval $(call ArchivosBibliotecaQTForma,Facturando))
$(eval $(call ArchivosBibliotecaQTForma,OrdenCompra))

#}}

all:    DirectorioO					\
	GeneraCabecerasPrevias				\
	SO/libCapturaRangoFechas.so			\
	SO/libCapturaDato.so				\
	SO/libAvisoNoAlcanza.so				\
	SO/libOpcionCerrar.so				\
	SO/libCapturaNoCotizacion.so			\
	SO/libOrdenElectronica.so 			\
	SO/libSelExpendios.so 				\
	SO/libReportesVentas.so				\
	SO/libPantallasSiscomElectronica2009.so		\
	SO/libFacturando.so				\
	SO/libFacturacion.so				\
	SO/libOrdenesPorFecha.so			\
	SO/libCapturaIva.so				\
	SO/libExtNoAlcanzan.so				\
	SO/libProdSimilares.so				\
	SO/libFirmateExpendio.so			\
	SO/libSiscomElectronicaComun.so 		\
	SO/libFirmaTiendas.so				\
	SO/libAccesoSiscomElectronica.so		\
	SO/libSelOrden.so				\
	SO/libCotizaDispositivos.so 			\
	SO/libCNSClientes.so				\
	SO/libCotizaPractica.so				\
	SO/libVentasElectronica.so			\
	SO/libEmpleadosExpendio.so			\
	SO/libDatosClienteF.so				\
	SO/libCompras.so				\
	SO/libActualizaInventario.so 			\
	SO/libInventario.so 				\
	SO/libProductoPractica.so			\
	SO/libMaterialPractica.so			\
	SO/libContMaterias.so 				\
	SO/libContDeLasPracticas.so 			\
	SO/libContEscuelas.so 				\
	SO/libContPracticas.so				\
	SO/libMantenProductos.so			\
	SO/libManejadorProductos.so			\
	SO/libFamilias.so				\
	SO/libCapturaTelefono.so			\
	SO/libCapturaContacto.so			\
	SO/libManejadorProveedores.so			\
	SO/libManejadorPrecios.so			\
	SO/libRegistroEmpleados.so			\
	SO/libMaterialAExpendio.so			\
	SO/libSISCOMTiendas3.so 			\
	SO/libRangoPorcentaje.so			\
	SO/libCtrExpendios.so				\
	SO/libCtrExistencias.so				\
	SO/libCtrExistenciasMinimas.so			\
	SO/libClientes.so				\
	SO/libProductosInventariar.so			\
	SO/libEstadoInventario.so			\
	SO/libProgramaInventario.so			\
	SO/libEjecutaInventario.so			\
	SO/libOrdenesVendidas.so			\
	SO/libOrdenCompra.so				\
	SISCOMTiendas3
	

#{{{ Modulos Siscom Electronica


$(eval $(call EnlaceBibliotecaQTForma,VentasElectronica))
$(eval $(call EnlaceBibliotecaQTForma,CotizaDispositivos))
$(eval $(call EnlaceBibliotecaQTForma,OrdenElectronica))
$(eval $(call EnlaceBibliotecaQTForma,CNSClientes))
$(eval $(call EnlaceBibliotecaQTForma,SelOrden))
$(eval $(call EnlaceBibliotecaQTForma,CotizaPractica))
$(eval $(call EnlaceBibliotecaQTForma,SelExpendios))
$(eval $(call EnlaceBibliotecaQTForma,CapturaDato))
$(eval $(call EnlaceBibliotecaQTForma,AvisoNoAlcanza))
$(eval $(call EnlaceBibliotecaQTForma,FirmaTiendas))
$(eval $(call EnlaceBibliotecaQTForma,AccesoSiscomElectronica))
$(eval $(call EnlaceBibliotecaQTForma,EmpleadosExpendio))
$(eval $(call EnlaceBibliotecaQTForma,FirmateExpendio))
$(eval $(call EnlaceBibliotecaQTForma,DatosClienteF))
$(eval $(call EnlaceBibliotecaQTForma,Compras))
$(eval $(call EnlaceBibliotecaQTForma,Inventario))
$(eval $(call EnlaceBibliotecaQTForma,ActualizaInventario))
$(eval $(call EnlaceBibliotecaQTForma,ContDeLasPracticas))
$(eval $(call EnlaceBibliotecaQTForma,ContPracticas))
$(eval $(call EnlaceBibliotecaQTForma,ContEscuelas))
$(eval $(call EnlaceBibliotecaQTForma,ContMaterias))
$(eval $(call EnlaceBibliotecaQTForma,MaterialPractica))
$(eval $(call EnlaceBibliotecaQTForma,ProductoPractica))
$(eval $(call EnlaceBibliotecaQTForma,ManejadorProductos))
$(eval $(call EnlaceBibliotecaQTForma,MantenProductos))
$(eval $(call EnlaceBibliotecaQTForma,Familias))
$(eval $(call EnlaceBibliotecaQTForma,ManejadorProveedores))
$(eval $(call EnlaceBibliotecaQTForma,CapturaContacto))
$(eval $(call EnlaceBibliotecaQTForma,CapturaTelefono))
$(eval $(call EnlaceBibliotecaQTForma,ProdSimilares))
$(eval $(call EnlaceBibliotecaQTForma,OpcionCerrar))
$(eval $(call EnlaceBibliotecaQTForma,ReportesVentas))
$(eval $(call EnlaceBibliotecaQTForma,CapturaRangoFechas))
$(eval $(call EnlaceBibliotecaQTForma,ManejadorPrecios))
$(eval $(call EnlaceBibliotecaQTForma,ExtNoAlcanzan))
$(eval $(call EnlaceBibliotecaQTForma,RegistroEmpleados))
$(eval $(call EnlaceBibliotecaQTForma,MaterialAExpendio))
$(eval $(call EnlaceBibliotecaQTForma,CapturaIva))
$(eval $(call EnlaceBibliotecaQTForma,CtrExpendios))
$(eval $(call EnlaceBibliotecaQTForma,CtrExistencias))
$(eval $(call EnlaceBibliotecaQTForma,CtrExistenciasMinimas))
$(eval $(call EnlaceBibliotecaQTForma,RangoPorcentaje))
$(eval $(call EnlaceBibliotecaQTForma,Clientes))
$(eval $(call EnlaceBibliotecaQTForma,ProductosInventariar))
$(eval $(call EnlaceBibliotecaQTForma,EstadoInventario))
$(eval $(call EnlaceBibliotecaQTForma,ProgramaInventario))
$(eval $(call EnlaceBibliotecaQTForma,EjecutaInventario))
$(eval $(call EnlaceBibliotecaQTForma,OrdenesVendidas))
$(eval $(call EnlaceBibliotecaQTForma,CapturaNoCotizacion))
$(eval $(call EnlaceBibliotecaQTForma,OrdenesPorFecha))
$(eval $(call EnlaceBibliotecaQTForma,Facturacion))
$(eval $(call EnlaceBibliotecaQTForma,Facturando))
$(eval $(call EnlaceBibliotecaQTForma,OrdenCompra))

# }}

DirectorioO:
	-mkdir O
	-mkdir SO
InsertaProductosSaberElectronica:$(Archivos_O_InsertaProductosSaberElectronica)
	@echo $@
	@$(CXX) $(OpEnlace) -o $@ $(Archivos_O_InsertaProductosSaberElectronica) \
	$(BibliotecasDesarrollo)		\
	$(Bibliotecas_ManejadorProductos)	\
	$(Bibliotecas_DesarrolloExtra)		\
 	$(BibliotecasTiendas3)	

SO/libSISCOMTiendas3.so:$(Archivos_O_libSISCOMTiendas3)
	@echo Creando $@
	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_libSISCOMTiendas3) $(BibliotecasDesarrollo) 
SISCOMTiendas3:$(Archivos_QT_SISCOMTiendas3) \
		$(Archivos_O_SISCOMTiendas3)
	@echo Creando $@
	@$(CXX) $(OpEnlace) -o $@ 			\
	$(Archivos_O_SISCOMTiendas3) 			\
	$(BibliotecasTiendas3) 				\
	$(BibliotecasDesarrollo)
	@cp SISCOMTiendas3 SISCOMTiendas3Produccion
PruebasGrafica:$(Archivos_O_PruebasGrafica) 
	@echo Creando $@
	@$(CXX) $(OpEnlace) -o $@ $(Archivos_O_PruebasGrafica) $(BibliotecasPruebasGrafica)
	
SISCOMVentasExpendio:$(Archivos_O_SISCOMVentasExpendio)
	@echo Creando $@
	@$(CXX) $(OpEnlace) -o $@ $(Archivos_O_SISCOMVentasExpendio) $(Bibliotecas2) 


SISCOMElectronica:$(Archivos_O_SISCOMTiendasMini) $(Archivos_QT_SISCOMTiendasMini)
	@echo Creando $@
	@$(CXX) $(OpEnlace) -o $@ $(Archivos_O_SISCOMTiendasMini) $(BibliotecasViejas)

SO/libSiscomElectronicaComun.so:$(Archivos_QT_SiscomElectronicaComun) \
				$(Archivos_O_SiscomElectronicaComun) 
	@echo Creando $@
	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_SiscomElectronicaComun) $(BibliotecasDesarrollo)  $(BibliotecasDesarrolloExtra) 

SO/libPantallasSiscomElectronica2009.so:$(Archivos_QT_PantallasSiscomElectronica2009) \
					$(Archivos_O_PantallasSiscomElectronica2009)
	@echo 'Generando $@'
	@$(CXX) $(OpModulos) -o $@				\
		$(Archivos_O_PantallasSiscomElectronica2009)	\
		$(Bibliotecas)					\
		-L ../SiscomElectronica3/SO 			\
		-L $(DIRDesarrolloHGE)/SiscomComunicaciones++	\
		-L $(DIRDesarrolloHGE)/SiscomDesarrollo4++	\
		-L $(DIRDesarrolloHGE)/SiscomDesarrollo4Qt++	\
		-lPantallasSiscomElectronica3			\
		-lOrdenElectronica				\
		-lReportesVentas				\
		-lSiscomComunicaciones++			\
		-lSiscomDesarrollo4++				\
		-lSiscomDesarrollo4Qt++

		

# Tepotzotlan A 16 de Noviembre del 2015 
# Se agrega la apachada para que compile todo el proyecto 
# Debido a la integracion de los modulos originales en las 
# pantallas y al migrar a solo un modulo libSiscomPantallasElectronica2009.so
# se tiene un error, en el que al no generar los archivos de las pantallas que 
# requiere uno de los modulos que se compila previamente, no puede terminarse
# la compilacion

GeneraCabecerasPrevias:
	@(make H/UIC_H_ControladorReportesVentasExpendios.h ;	\
	  make H/IMP_ProductosSimilares.h;			\
	  make H/UIC_H_AccesoSiscomElectronica.h)

CPP/MOC_%.cpp:H/%.h
	@echo MOC $<
	@$(MOC) -o $@ $<

clean:
	@-rm O/*.o
	@-rm SO/*.so
	@-rm CPP/MOC_*.cpp
	@-rm CPP/UIC_CPP_*.cpp
	@-rm H/UIC_H_*.h
	@-rm SISCOMElectronica
	@-rm SISCOMVentasExpendio
muestra:
	echo $(Archivos_O_Extra_OrdenElectronica)
	echo $(Archivos_QT_Extra_OrdenElectronica)
