include ../../SISCOMComunYUtilerias/MakefileQTSiscomDesarrollo3.mk
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
Pantallas_Trampolin=				\
			Entrenadores		\
			Juez 			\
			Gimnasio 		\
			Gimnastas 		\
			EdoRegGimnasio		\
			EsEntrenadorContacto	\
			Competencia		\
			SelGimnasio		\
			GimnastaCompetencia	\
			BuscaPersonas		\
			GimnastasCompetencia	\
			CalificaGimnasta	\
			Resultados		\
			GimnastasXCompetencia	\
			ActDatCompGimnasta	\
			Rondas			\
			EjecutaCompetencia	\
			ActualizaPersonales	\
			CapActPersonales	\
			CapturaTelefono		\
			CapturaCorreo		\
			CapturaDireccion	\
			RondasCompetencia	\
			ResultadosA		\
			TablaResultados

Siscom_Trampolin=SISCOMVentanaPrincipal3 SiscomTrampolin

Control_Gimnasios=QCtrlGimnasios
Control_Competencias=QCtrlCompetencias

ControlesTrampolin=				\
			Gimnasios 		\
			Competencias		\
			Clase 			\
			Nivel			\
			Grupo			\
			BuscaPersonas		\
			TipoCompetencia		\
			AparatoCompetencia	\
			BuscaPersonas2


Archivos_QT_PantallasSistema=\
	$(call ArchivosQTSistemaFormas,$(Pantallas_Trampolin))	\
	CPP/MOC_QCalCompetencia.cpp				\
	CPP/MOC_QResCompetencia.cpp				\
	CPP/MOC_QGimnastasAparatos.cpp				\
	CPP/MOC_QGimnastasAparato.cpp				\
	CPP/MOC_QCompetenciaAparato.cpp				\
	CPP/MOC_QSoloAparatos.cpp				\
	CPP/MOC_QSisRonda.cpp					\
	CPP/MOC_QOperacionesGenerales.cpp			\
	CPP/MOC_QRotaciones.cpp
Archivos_O_PantallasSistema=					\
	$(call ArchivosOSistemaFormas,$(Pantallas_Trampolin)) 	\
	O/CQSisGimnasios.o					\
	O/CQSisTrampolinComun.o					\
	O/CQSisEntrenadores.o					\
	O/CQSisGimnastas.o					\
	O/CQSisCompetencias.o					\
	O/CQSisClase.o						\
	O/CQSisNivel.o						\
	O/CQSisGrupo.o						\
	O/CQSisJueces.o						\
	O/CQSisCGimnastas.o					\
	O/CQSisOperaciones.o					\
	O/CQSisRonda.o						\
	O/MOC_QCalCompetencia.o					\
	O/MOC_QResCompetencia.o					\
	O/MOC_QGimnastasAparatos.o				\
	O/MOC_QGimnastasAparato.o				\
	O/MOC_QCompetenciaAparato.o				\
	O/MOC_QSoloAparatos.o					\
	O/MOC_QSisRonda.o					\
	O/MOC_QRotaciones.o					\
	O/MOC_QOperacionesGenerales.o				\
	O/QCalCompetencia.o					\
	O/QResCompetencia.o					\
	O/QGimnastasAparatos.o					\
	O/QGimnastasAparato.o					\
	O/QCompetenciaAparato.o					\
	O/QSisRonda.o						\
	O/QSoloAparatos.o					\
	O/QRotaciones.o						\
	O/QOperacionesGenerales.o				\
	O/CQSisRotaciones.o					\
	O/QListBoxItemGimnasia.o				\
	O/SISCOMVentanaPrincipal3.o				

Archivos_QT_SiscomTrampolin=$(call ArchivosQTSistema,$(Siscom_Trampolin))	
Archivos_O_SiscomTrampolin=$(call ArchivosOSistema,$(Siscom_Trampolin)) \
			   O/Principal.o				

Archivos_ControlesExtra=O/CQSisConsultas.o  		\
			O/CQSisEntrenadores.o 		\
			O/CQSisCompitiendo.o		\
			O/CQSisCalificaciones.o		\
			O/CQSisAparato.o
Archivos_O_PruebaForma=O/PruebaForma.o
Archivos_ControlesGimnasios=$(call ArchivosControlQT,$(ControlesTrampolin))	\
			    $(Archivos_ControlesExtra)

Bibliotecas=	-L$(QTDIR)/lib 			\
		-L$(QTDIR)/plugins/designer	\
	    	-L$(DIRLIBSISCOM2)		\
	    	-lqt-mt				\
	    	-lSiscomComunicaciones++	\
	    	-lSiscomDesarrollo2		\
	    	-lSepomexCliente		\
	    	-lQSiscomSepomex++		\
		-lControlGimnasios		\
		-lControlFechaDesarrollo2	\
		-lControlCompetencias		\
		-lControlClase			\
		-lControlNivel			\
		-lControlGrupo			\
		-lControlBuscaPersonas		\
		-lControlBuscaPersonas2		\
		-lControlTipoCompetencia	\
		-lControlAparatoCompetencia	\
		-lSiscomDesarrollo3Qt++
BibliotecasControles=					\
		-L$(QTDIR)/lib 			\
	    	-L$(DIRLIBSISCOM2)		\
	    	-lqt-mt				\
	    	-lSiscomComunicaciones++	\
	    	-lSiscomDesarrollo2		

Binarios=									\
		$(Archivos_ControlesGimnasios)					\
		$(QTDIR)/plugins/designer/libControlGimnasios.so		\
		$(QTDIR)/plugins/designer/libControlCompetencias.so		\
		$(QTDIR)/plugins/designer/libControlClase.so			\
		$(QTDIR)/plugins/designer/libControlNivel.so			\
		$(QTDIR)/plugins/designer/libControlGrupo.so			\
		$(QTDIR)/plugins/designer/libControlBuscaPersonas.so		\
		$(QTDIR)/plugins/designer/libControlBuscaPersonas2.so		\
		$(QTDIR)/plugins/designer/libControlTipoCompetencia.so		\
		$(QTDIR)/plugins/designer/libControlAparatoCompetencia.so	\
		SO/libPantallasSiscomTrampolin.so				\
		SiscomTrampolin						
all:$(Binarios)
des:
	@echo $(Archivos_ControlesGimnasios)
PruebaForma:$(Archivos_O_PruebaForma)
	@echo Generando $@
	$(CXX) $(OpEnlace) -o $@ $(Archivos_O_PruebaForma) \
		$(Bibliotecas) 				   \
		-L SO/ -lPantallasSiscomTrampolin
SO/libPantallasSiscomTrampolin.so:$(Archivos_QT_PantallasSistema)	\
				  $(Archivos_O_PantallasSistema)
	@echo Generando $@ 
	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_PantallasSistema) $(Bibliotecas)


$(QTDIR)/plugins/designer/libControlGimnasios.so:$(call ArchivosQTControl,Gimnasios) \
						  $(call ArchivosOControl,Gimnasios)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o $@ 			\
		$(call ArchivosOControl,Gimnasios) 	\
		$(BibliotecasControles)
$(QTDIR)/plugins/designer/libControlCompetencias.so:$(call ArchivosQTControl,Competencias) \
						    $(call ArchivosOControl,Competencias)  \
						    $(Archivos_ControlesExtra)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o $@ 			\
		$(call ArchivosOControl,Competencias) 	\
		$(Archivos_ControlesExtra)		\
		$(BibliotecasControles)

$(QTDIR)/plugins/designer/libControlClase.so:$(call ArchivosQTControl,Clase) 	\
					     $(call ArchivosOControl,Clase)	\
					     $(Archivos_ControlesExtra)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o $@ 		\
		$(call ArchivosOControl,Clase) 	\
		$(Archivos_ControlesExtra)	\
		$(BibliotecasControles)
$(QTDIR)/plugins/designer/libControlNivel.so:$(call ArchivosQTControl,Nivel) 	\
					     $(call ArchivosOControl,Nivel)	\
					     $(Archivos_ControlesExtra)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o $@ 		\
		$(call ArchivosOControl,Nivel) 	\
		$(Archivos_ControlesExtra)	\
		$(BibliotecasControles)

$(QTDIR)/plugins/designer/libControlGrupo.so:$(call ArchivosQTControl,Grupo) 	\
					     $(call ArchivosOControl,Grupo)	\
					     $(Archivos_ControlesExtra)	
	@echo Generando $@
	@$(CXX) $(OpModulos) -o $@ 		\
		$(call ArchivosOControl,Grupo) 	\
		$(Archivos_ControlesExtra)	\
		$(BibliotecasControles)
$(QTDIR)/plugins/designer/libControlBuscaPersonas2.so:$(call ArchivosQTControl,BuscaPersonas2) 	\
						    $(call ArchivosOControl,BuscaPersonas2)	\
						    $(Archivos_ControlesExtra)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o $@ 			\
		$(call ArchivosOControl,BuscaPersonas2) 	\
		$(Archivos_ControlesExtra)		\
		$(BibliotecasControles)

$(QTDIR)/plugins/designer/libControlBuscaPersonas.so:$(call ArchivosQTControl,BuscaPersonas) 	\
						    $(call ArchivosOControl,BuscaPersonas)	\
						    $(Archivos_ControlesExtra)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o $@ 			\
		$(call ArchivosOControl,BuscaPersonas) 	\
		$(Archivos_ControlesExtra)		\
		$(BibliotecasControles)
$(QTDIR)/plugins/designer/libControlAparatoCompetencia.so:$(call ArchivosQTControl,AparatoCompetencia) 	\
						    $(call ArchivosOControl,AparatoCompetencia)	\
						    $(Archivos_ControlesExtra)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o $@ 			\
		$(call ArchivosOControl,AparatoCompetencia) 	\
		$(Archivos_ControlesExtra)		\
		$(BibliotecasControles)
$(QTDIR)/plugins/designer/libControlTipoCompetencia.so:$(call ArchivosQTControl,TipoCompetencia) 	\
						    $(call ArchivosOControl,TipoCompetencia)	\
						    $(Archivos_ControlesExtra)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o $@ 			\
		$(call ArchivosOControl,TipoCompetencia) 	\
		$(Archivos_ControlesExtra)		\
		$(BibliotecasControles)

SiscomTrampolin:$(Archivos_QT_SiscomTrampolin)		\
		$(Archivos_O_SiscomTrampolin)
	@echo Generando $@
	@$(CXX) $(OpEnlace) -o$@ $(Archivos_O_SiscomTrampolin) $(Bibliotecas)

clean:
	-@rm $(Archivos_QT_PantallasSistema)
	-@rm $(Archivos_O_PantallasSistema)
	-@rm $(Archivos_O_SiscomTrampolin)
	-@rm $(Archivos_QT_SiscomTrampolin)
	-@rm $(Binarios)
cleanControles:
	-@rm $(Archivos_ControlesGimnasios)

