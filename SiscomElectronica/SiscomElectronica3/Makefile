include $(DIRDesarrolloHGE)/SISCOMComunYUtilerias/MakefileQTSiscomDesarrollo3.mk
#OpCompilaciones{
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
#}	
Include=-I $(QTDIR)/include						\
	-I.								\
	-I H								\
	-I $(SISCOM_LIB_DIR)/Include  					\
	-I $(DIRLIBSISCOM2)/H 						\
	-I $$QtInclude							\
	-I $(DirectorioSiscomElectronica)/Cliente/H			\
	-I $(DIRDesarrolloHGE)/SiscomComunicaciones++/H			\
	-I $(DIRDesarrolloHGE)/SiscomDesarrollo4Qt++/H			\
	-I $(DIRDesarrolloHGE)/SiscomDesarrollo4++/H


OpModulos=-shared -rdynamic  $(DEBUG) $(OpCSiscom)
OpEnlace=$(DEBUG) $(OpCSiscom)


Pantallas_SiscomElectronica3=				\
				ComprasProducto		\
				RangoPorcentajes3	\
				SueldosEmpleados	\
				CapturaSueldo


ControlesSiscomElectronica3=				\
				SiscomElectronica3


## Domingo 31 De Julio 2011
## Se agrega una macro para simplificar el manejo de 
## los controles, como podemos observar para el caso
## del control QCtrlAlumnos, en esta macro solo 
## agregamos Alumnos, y mediante la macro ArchivosClasesQT y
## ArchivosOClasesQT podremos generar los nombres de los
## archivos tanto el MOC_QCtr, como QCtrl .o etc 
## y bastara con agregar los controles a Archivos_ClasesSiscomElectronica3
## 

Archivos_ClasesSiscomElectronica3=Alumnos 			\
				  MotivoInventario		\
				  Cursos			\
				  FechasCursos			\
				  ServiciosSiscom		\
				  ProgramacionCursos		\
				  ExplicacionPromocion		\
				  OrigenCompra 			\
				  ProductosSE			\
				  EscuelasSE			\
				  EstadosImpresosSE		\
				  TiposProductoSE		\
				  GastosSE			\
				  CuentaDinero			\
				  ExpendiosSE			\
				  ProveedoresSE			\
				  ClientesMayoreo		\
				  FormaPagoSat			\
				  UsoCFDISat			\
				  MetodoPagoSat			\
				  RFCs				\
				  MateriasSE			\
				  CajasUbicacion		\
				  Estantes			\
				  OrdenesFavoritas		\
				  EstadosPedidosClienteSE	\
				  RegimenFiscal			\
				  Bodegas4			\
				  CmbBodegas4			\
				  ClavesProveedores


Archivos_QT_PantallasSiscomElectronica3=		\
	$(call ArchivosQTSistemaFormas,$(Pantallas_SiscomElectronica3))

Archivos_O_PantallasSiscomElectronica3=			\
	$(call ArchivosOSistemaFormas,$(Pantallas_SiscomElectronica3))	\
	O/CQSisSueldos.o						\
	O/CQSisCursosDiaHora.o						\
	O/CQSisCostoCurso.o


Archivos_QT_ControlSiscomElectronica3Extra=				\
	CPP/MOC_QCtrlProdSiscomElectronica.cpp				\
	CPP/MOC_QCtrlEmpleados.cpp					\
	CPP/MOC_QCtrlExpendios.cpp					\
	CPP/MOC_QCtrlBodegas.cpp					\
	CPP/MOC_QCtrlCmbBodegas.cpp					\
	CPP/MOC_QCtrlEstadisticasSemanalesVentas.cpp			\
	CPP/MOC_QtSisBotonOrden.cpp					\
	$(call ArchivosClasesQT,$(Archivos_ClasesSiscomElectronica3))
Archivos_O_ControlSiscomElectronica3Extra=				\
	O/MOC_QCtrlProdSiscomElectronica.o				\
	O/MOC_QCtrlEmpleados.o						\
	O/MOC_QCtrlExpendios.o						\
	O/MOC_QCtrlBodegas.o						\
	O/MOC_QCtrlCmbBodegas.o						\
	O/QCtrlCmbBodegas.o						\
	O/MOC_QCtrlEstadisticasSemanalesVentas.o			\
	O/MOC_QtSisBotonOrden.o						\
	O/QCtrlProdSiscomElectronica.o					\
	O/QCtrlEmpleados.o						\
	O/QCtrlExpendios.o						\
	O/QCtrlBodegas.o						\
	O/QCtrlEstadisticasSemanalesVentas.o				\
	O/CQSis3QtOperaciones.o						\
	O/Sis3QtProductos.o						\
	O/QtSisBotonOrden.o						\
	O/QtSisBotonOrdenList.o						\
	$(call ArchivosOClasesQT,$(Archivos_ClasesSiscomElectronica3))
Archivos_ControlesSiscomElectronica3=					\
	$(call ArchivosControlQT,$(ControlesSiscomElectronica3))	\
	$(Archivos_O_ControlesExtra)


Binarios=$(Archivos_ControlesSiscomElectronica3) 			\
	 $(call DependenciaControles,$(ControlesSiscomElectronica3))	\
	  SO/libPantallasSiscomElectronica3.so


Bibliotecas=	-L$(QTDIR)/lib 					\
		-L$(QTDIR)/plugins/designer			\
	    	-L$(DIRLIBSISCOM2)				\
	    	-lqt-mt						\
		-lControlSiscomElectronica3			\
		-lSiscomDesarrollo3Qt++



BibliotecasControles=						\
		-L$(QTDIR)/lib 					\
	    	-L$(DIRLIBSISCOM2)				\
		-L$(DIRDesarrolloHGE)/SiscomComunicaciones++	\
		-L$(DIRDesarrolloHGE)/SiscomDesarrollo4++	\
		-L$(DIRDesarrolloHGE)/SiscomDesarrollo4Qt++	\
	    	-lqt-mt						\
		-lSiscomDesarrollo3Qt++				\
		-l:libSiscomComunicaciones++.so.1.0.0		\
		-lSiscomDesarrollo4Qt++				\
		-lSiscomDesarrollo4++


all:DirectoriosO $(Binarios) 

DirectoriosO:
	-mkdir O
	-mkdir SO
Muestra:
	echo $(Binarios)
	echo $(Archivos_O_ControlSiscomElectronica3Extra)
	for X in $(Archivos_O_ControlSiscomElectronica3Extra) \
	 echo $X 



SO/libPantallasSiscomElectronica3.so:$(Archivos_QT_PantallasSiscomElectronica3) \
				     $(Archivos_O_PantallasSiscomElectronica3)
	@echo 'Generando $@'
	@$(CXX) $(OpModulos) -o $@ 				\
		$(Archivos_O_PantallasSiscomElectronica3) 	\
		$(Bibliotecas)

$(eval $(call GeneraControles,$(ControlesSiscomElectronica3)))

clean:
	@echo 'Eliminando archivos'
	@-rm CPP/MOC_CPP_*.cpp
	@-rm CPP/UIC_CPP_*.cpp
	@-rm UI/*.ui~
	@-rm H/UIC_H_*.h
	@-rm O/*.o
	@-rm SO/*.so
