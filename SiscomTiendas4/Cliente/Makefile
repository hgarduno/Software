include $(DIRDesarrolloHGE)/SISCOMComunYUtilerias/MakefileQTSiscomDesarrollo3.mk
OpCompilacion=	-c 			\
		-pipe			\
		-W			\
		-O2			\
		-D_REENTRANT		\
		-fPIC			\
		-DQT_NO_DEBUG		\
		-DQT_THREAD_SUPPORT	\
		-DQT_PLUGIN 		\
		-DQT_SHARED		\
		$(DEBUG)		\
		$(OpCSiscom)
	
Include=-I $(QTDIR)/include		\
	-I.				\
	-I H				\
	-I $(SISCOM_LIB_DIR)/Include  	\
	-I $(DIRLIBSISCOM2)/H 

OpModulos=-shared  $(DEBUG) $(OpCSiscom)
OpEnlace=$(DEBUG) $(OpCSiscom)
Pantallas_Tiendas4=					\
			RegProducto			\
			Familias			\
			ActualizaProductos		\
			Precios				\
			PrecioProducto			\
			RegistroEmpresa			\
			Compras				\
			Ventas				\
			CapturaCantidad			\
			ReporteVentas			\
			Devoluciones			\
			Caja				\
			ComprasRegistradas		\
			ReporteExistencias		\
			RegistroEmpleado		\
			RegistroClientes		\
			Pedidos				\
			InformacionPedido		\
			RegistrarEntrega		\
			Ventas3Qt			\
			CotizaVdys			\
			SeleccionaCliente		\
			Paquetes			\
			PaquetesRegistrados		\
			ProductosPaquete		\
			AnexarProducto			\
			OrdenServicio			\
			AnexaDireccion			\
			RegistroClientes2		\
			RemisionFactura			\
			ResultadosBusqueda		\
			RegistroEmpresas2		\
			CapturaDireccionE		\
			CapturaContactoE		\
			CapturaMedioComunicacionE	\
			ActualizaPrecios
			
Pantallas_AplicacionTiendas4=Pedidos 		\
			     InformacionPedido
			#\
			FirmaSistema			\
			Firmate
Siscom_Tiendas4=SiscomTiendas4


Archivos_QT_PantallasSistema=			\
	$(call ArchivosQTSistemaFormas,$(Pantallas_Tiendas4))	\
	CPP/MOC_CPP_CQSisPreciosTabla.cpp			\
	CPP/MOC_IMP_CapturaCantidad3Qt.cpp			\
	CPP/MOC_CPP_CQSisPreciosTabla3Qt.cpp			\
	CPP/MOC_SiscomTiendas41.cpp				\
	CPP/MOC_QSisManDirecciones.cpp



Archivos_O_PantallasSistema=					\
	$(call ArchivosOSistemaFormas,$(Pantallas_Tiendas4))	\
	O/SiscomTiendas41.o					\
	O/CQSisPerfilUtilizacion.o				\
	O/CQSisPreciosTabla.o					\
	O/CQSisPreciosTabla3Qt.o				\
	O/CQSisImprimeTicket.o					\
	O/MOC_CPP_CQSisPreciosTabla.o				\
	O/MOC_IMP_CapturaCantidad3Qt.o				\
	O/MOC_CPP_CQSisPreciosTabla3Qt.o			\
	O/MOC_SiscomTiendas41.o					\
	O/MOC_QSisManDirecciones.o				\
	O/IMP_CapturaCantidad3Qt.o				\
	O/CQSisOpTiendas43Qt.o					\
	O/QSisManDirecciones.o					\
	O/CQSisDirecciones2.o


Archivos_QT_SiscomTiendas4=				\
	$(call ArchivosQTSistema,$(Siscom_Tiendas4))	\
	$(call ArchivosQTSistemaFormas,$(Pantallas_AplicacionTiendas4)) 
Archivos_O_SiscomTiendas4=							\
	$(call ArchivosOSistema,$(Siscom_Tiendas4)) 				\
	$(call ArchivosOSistemaFormas,$(Pantallas_AplicacionTiendas4))		\
	O/Principal.o								\
	O/SiscomTiendas41.o							\
	O/MOC_SiscomTiendas41.o							\
	O/CQSisPerfilUtilizacion.o						\
	O/CQSisEmpleados.o							\
	O/CQSisComunesTiendas3Qt.o						\

ControlesTiendas4= Tiendas4s
Archivos_QT_ControlTiendas4sExtra=CPP/MOC_QCtrlProductos.cpp			\
				  CPP/MOC_QCtrlPrecios.cpp			\
				  CPP/MOC_QCtrlFamilias.cpp			\
				  CPP/MOC_QCtrlMedComunicacion.cpp		\
				  CPP/MOC_QCtrlEmpresas.cpp			\
				  CPP/MOC_QCtrlContactos.cpp			\
				  CPP/MOC_QCtrlFormaPago.cpp			\
				  CPP/MOC_QCtrlClientes.cpp			\
				  CPP/MOC_QCtrlOrdenes.cpp			\
				  CPP/MOC_QCtrlCotizas.cpp			\
				  CPP/MOC_QCtrlProductos3Qt.cpp			\
				  CPP/MOC_QCtrlClientes3Qt.cpp			\
				  CPP/MOC_QCtrlContactos3Qt.cpp			\
				  CPP/MOC_QCtrlFormaPago3Qt.cpp			\
				  CPP/MOC_QCtrlPrecios3Qt.cpp			\
				  CPP/MOC_CQSisComunPaquetes.cpp		\
				  CPP/MOC_QCtrlPreciosProductos.cpp
Archivos_O_ControlTiendas4sExtra=O/MOC_QCtrlProductos.o				\
				 O/MOC_QCtrlPrecios.o				\
				 O/MOC_QCtrlFamilias.o				\
				 O/MOC_QCtrlMedComunicacion.o			\
				 O/MOC_QCtrlEmpresas.o				\
				 O/MOC_QCtrlContactos.o				\
				 O/MOC_QCtrlFormaPago.o				\
				 O/MOC_QCtrlClientes.o				\
				 O/MOC_QCtrlOrdenes.o				\
				 O/MOC_QCtrlCotizas.o				\
				 O/MOC_QCtrlProductos3Qt.o			\
				 O/MOC_QCtrlClientes3Qt.o			\
				 O/MOC_QCtrlContactos3Qt.o			\
				 O/MOC_QCtrlFormaPago3Qt.o			\
				 O/MOC_QCtrlPrecios3Qt.o			\
				 O/MOC_QCtrlPreciosProductos.o			\
				 O/QCtrlProductos.o				\
				 O/QCtrlPrecios.o				\
				 O/QCtrlFamilias.o				\
				 O/QCtrlMedComunicacion.o			\
				 O/QCtrlEmpresas.o				\
				 O/QCtrlContactos.o				\
				 O/QCtrlFormaPago.o				\
				 O/QCtrlClientes.o				\
				 O/QCtrlOrdenes.o				\
				 O/QCtrlCotizas.o				\
				 O/QCtrlProductos3Qt.o				\
				 O/QCtrlClientes3Qt.o				\
				 O/QCtrlContactos3Qt.o				\
				 O/QCtrlFormaPago3Qt.o				\
				 O/QCtrlPrecios3Qt.o				\
				 O/QCtrlPreciosProductos.o			\
				 O/CQSisOpTiendas4.o				\
				 O/CQSisOpTiendas43Qt.o				\
				 O/CQSisDatoPrecio.o				\
				 O/CQSisObjetosTiendas4.o			\
				 O/CQSisEmpleados.o				\
				 O/CQSisVentas.o				\
				 O/CQSisOrVendidas.o				\
				 O/CQSisProdCotiza.o				\
				 O/CQSisCompras.o				\
				 O/CQSisReportes.o				\
				 O/CQSisContactos.o				\
				 O/CQSisPrecios.o				\
				 O/CQSisFormaPago.o				\
				 O/CQSisProductos.o				\
				 O/CQSisEmpresas.o				\
				 O/CQSisEmpresas2.o				\
				 O/CQSisClientes.o				\
				 O/CQSisFamilias.o				\
				 O/CQSisOrdenes.o				\
				 O/CQSisPedidos.o				\
				 O/CQSisComunesTiendas3Qt.o			\
				 O/CQSisProdCotiza3Qt.o				\
				 O/CQSisVentas3Qt.o				\
				 O/CQSisClientes3Qt.o				\
				 O/CQSisPaquetes.o				\
				 O/CQSisResponsableVehiculo.o			\
				 O/MOC_CQSisComunPaquetes.o 			\
				 O/CQSisComunPaquetes.o


Archivos_ControlesTienda4=$(call ArchivosControlQT,$(ControlesTiendas4))	\
			    $(Archivos_ControlesExtra)

Bibliotecas=	-L$(QTDIR)/lib 			\
		-L$(QTDIR)/plugins/designer	\
	    	-L$(DIRLIBSISCOM2)		\
		-L$(SISCOM_LIB_DIR)		\
	    	-lqt-mt				\
	    	-lSiscomDesarrollo2		\
	    	-lSepomexCliente		\
	    	-lSiscomComunicaciones++	\
		-lControlSepomexComunicas	\
	    	-lQSiscomSepomex++		\
		-lControlTiendas4s		\
		-lControlFechaDesarrollo2	\
		-lSiscomDesarrollo3Qt++		\
		-lSISCOMDesarrolloQ++
BibliotecasControles=				\
		-L$(QTDIR)/lib 			\
		-L$(QTDIR)/plugins/designer	\
	    	-L$(DIRLIBSISCOM2)		\
	    	-lqt-mt				\
	    	-lSiscomComunicaciones++	\
		-lSiscomDesarrollo3Qt++		\
	    	-lSiscomDesarrollo2		#\
	    	-lSiscomClasesGenerales++	\


BibliotecasAplicacion=								\
		-L $(QTDIR)/plugins/designer 					\
		-L $(QTDIR)/lib							\
		-L $(DIRLIBSISCOM2)						\
		-lQCtrlServidoresSiscom						\
		-lQCtrlUsuarios							\
		-lQCtrlPerfiles							\
		-lqt-mt								\
		-lSiscomFirmateSistema						\
		-lControlTiendas4s						\
		-lSiscomDesarrollo3Qt++		\
	    	-lSiscomComunicaciones++	\
		-lControlSepomexComunicas

Binarios=									\
		$(Archivos_ControlesTienda4)					\
		$(call DependenciaControles,$(ControlesTiendas4))		\
		SO/libPantallasSiscomTiendas4.so				\
		SiscomTiendas4							\
		#InformacionSeid 
Archivos_H_Controles=\
$(DIRDesarrolloHGE)/SISCOMElectronica/SiscomElectronica2/Cliente/H/QCtrlEscuelas.h 

Archivos_O_InformacionSeid=O/InformacionSeid.o
all:$(Binarios) Copia

Copia:$(Archivos_H_Controles)
	@for X in $(Achivos_H_Controles);	\
  do 					\
      ln -fs $$X $(DIRLIBSISCOM2)/H;	\
  done
  

des:
	@echo $(Archivos_ControlesTienda4)

InformacionSeid:$(Archivos_O_InformacionSeid)
	@echo Generando $@
	@$(CXX) $(OpEnlace) -o$@ 		\
	$(Archivos_O_InformacionSeid) 		\
	$(BibliotecasAplicacion)		\
	-L$(QTDIR)/plugins/designer		\
	-lControlTiendas4s

SO/libPantallasSiscomTiendas4.so:$(Archivos_QT_PantallasSistema)	\
				  $(Archivos_O_PantallasSistema)
	@echo Generando $@ 
	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_PantallasSistema) 	\
	 $(Bibliotecas)	
Prueba:
	@echo $(Archivos_QT_SiscomTiendas4)
	@echo $(Archivos_O_SiscomTiendas4)
SiscomTiendas4:$(Archivos_QT_SiscomTiendas4)	\
	       $(Archivos_O_SiscomTiendas4)
	@echo Generando $@
	$(CXX) $(OpEnlace) -o$@ 		\
	$(Archivos_O_SiscomTiendas4) 		\
	$(BibliotecasAplicacion)
$(eval $(call GeneraControles,$(ControlesTiendas4)))
clean:
	-@rm O/*
	-@rm CPP/MOC_*
	-@rm CPP/UIC_CPP*
	-@rm $(Binarios)
cleanControles:
	-@rm $(Archivos_ControlesTienda4)
	

