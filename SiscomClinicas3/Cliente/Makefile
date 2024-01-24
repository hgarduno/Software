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
	-I $(DIRLIBSISCOM2)/H 		\
	-I $(HOME)/SiscomTiendas4/Cliente/H

OpModulos=-shared  $(DEBUG) $(OpCSiscom)
OpEnlace=$(DEBUG) $(OpCSiscom)

Siscom_Clinicas3=SiscomClinicas3

Archivos_QT_SiscomClinicas3=					\
	$(call ArchivosQTSistema,$(Siscom_Clinicas3))		

Archivos_O_SiscomClinicas3=					\
	$(call ArchivosOSistema,$(Siscom_Clinicas3))		\
	O/Principal.o

Pantallas_SiscomClinicas3=				\
				RegistroPersonas	\
				Servicios		\
				TiposPrecios		\
				PerfilConsultaMedico	\
				Recepcion		\
				ControladorPacientes	\
				CentroMedico		\
				CentroMedico2		\
				ObservacionesConsulta	\
				Receta			\
				RecetasConsulta		\
				Cobra			\
				PreciosServicios	\
				Expedientes		\
				Recetas			\
				VentasMedico		\
				PersonasSimilares	\
				ManDatPersonales	\
				Hospitalizacion		\
				MovimientosRecepcion	

Archivos_O_ControlRecetasExtra=O/QSisReceta.o		\
			       O/MOC_QSisReceta.o	
Archivos_QT_ControlRecetasExtra=CPP/MOC_QSisReceta.cpp

Archivos_O_ControlClinicasExtra=				\
				O/QSisExpediente.o		\
				O/QSisResultadosGen.o		\
				O/QSisImporteServicios.o	\
				O/QSisEstsMedico.o		\
				O/QSisPacientes.o		\
				O/MOC_QSisExpediente.o		\
				O/MOC_QSisResultadosGen.o	\
				O/MOC_QSisImporteServicios.o	\
				O/MOC_QSisEstsMedico.o		\
				O/MOC_QSisPacientes.o
Archivos_QT_ControlClinicasExtra=CPP/MOC_QSisExpediente.cpp		\
				 CPP/MOC_QSisResultadosGen.cpp		\
				 CPP/MOC_QSisImporteServicios.cpp 	\
				 CPP/MOC_QSisEstsMedico.cpp
ControlesSiscomClinicas3=Personas			\
			 Servicios			\
			 Recetas			\
			 EstadisticaMedicos		\
			 Clinicas

Archivos_QT_PantallasSiscomClinicas3=		\
	$(call ArchivosQTSistemaFormas,$(Pantallas_SiscomClinicas3))

Archivos_O_PantallasSiscomClinicas3=			\
	$(call ArchivosOSistemaFormas,$(Pantallas_SiscomClinicas3)) 	\
	O/CQSisPersonas.o						\
	O/CQSisServicios.o						\
	O/CQSisEstadoConsulta.o						\
	O/CQSisRecetas.o						\
	O/CQSisMatHosp.o



Archivos_ControlesExtra=						\
	O/CQSisObjetos.o						\
	O/CQSisTipoPrecio.o						\
	O/CQSisExpedientes.o						\
	O/CQSisConsultas.o						\
	O/CQSisCotizando.o						\
	O/CQSisPreciosServicios.o


Archivos_ControlesSiscomClinicas3=					\
	$(call ArchivosControlQT,$(ControlesSiscomClinicas3))		\
	$(Archivos_O_ControlesExtra)


Binarios=$(Archivos_ControlesSiscomClinicas3) 				\
	 $(call DependenciaControles,$(ControlesSiscomClinicas3))	\
	  SO/libPantallasSiscomClinicas3.so				\
	  SiscomClinicas


Bibliotecas=	-L$(QTDIR)/lib 			\
		-L$(QTDIR)/plugins/designer	\
	    	-L$(DIRLIBSISCOM2)		\
	    	-lqt-mt				\
	    	-lSiscomDesarrollo2		\
	    	-lSepomexCliente		\
	    	-lSiscomComunicaciones++	\
	    	-lQSiscomSepomex++		\
		-lControlTiendas4s		\
		-lControlPersonas		\
		-lControlServicios		\
		-lControlRecetas		\
		-lControlEstadisticaMedicos	\
		-lControlClinicas		\
		-lControlSepomexComunicas	\
		-lControlFechaDesarrollo2


BibliotecasControles=				\
		-L$(QTDIR)/lib 			\
	    	-L$(DIRLIBSISCOM2)		\
	    	-lqt-mt				\
	    	-lSiscomComunicaciones++	\
	    	-lSiscomDesarrollo2		#\
	    	-lSiscomClasesGenerales++	\

BibliotecasAplicacion=-L $(DIRLIBSISCOM2)		\
		      -L $(QTDIR)/lib			\
		      -L $(QTDIR)/plugins/designer 	\
			-lSiscomFirmateSistema		\
			-lqt-mt
Archivos_H_Controles=


all:$(Binarios) #Copia


Copia:$(Archivos_H_Controles)
	@for X in $(Archivos_H_Controles) ;	\
	do					\
 	ln -fs $$X $(DIRLIBSISCOM2)/H;		\
 	done

Prueba:
	@echo $(Archivos_QT_SiscomClinicas3)
	@echo $(Archivos_O_SiscomClinicas3)
SiscomClinicas:$(Archivos_QT_SiscomClinicas3)	\
	       $(Archivos_O_SiscomClinicas3)
	@echo Generando $@			
	@$(CXX) $(OpEnlace) -o$@ 		\
	$(Archivos_O_SiscomClinicas3) 		\
	$(BibliotecasAplicacion)
SO/libPantallasSiscomClinicas3.so:$(Archivos_QT_PantallasSiscomClinicas3) \
				     $(Archivos_O_PantallasSiscomClinicas3)
	@echo 'Generando $@'
	@$(CXX) $(OpModulos) -o $@ 				\
		$(Archivos_O_PantallasSiscomClinicas3) 	\
		$(Bibliotecas)

$(eval $(call GeneraControles,$(ControlesSiscomClinicas3)))

clean:
	@echo 'Eliminando archivos'
	@-rm CPP/MOC_*.cpp
	@-rm CPP/MOC_CPP_*.cpp
	@-rm CPP/UIC_CPP_*.cpp
	@-rm UI/*.ui~
	@-rm H/UIC_H_*.h
	@-rm O/*.o
	@-rm SO/*.so
