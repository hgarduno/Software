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
	-I $$QtInclude

OpModulos=-shared  $(DEBUG) $(OpCSiscom)
OpEnlace=$(DEBUG) $(OpCSiscom)


BibliotecasAplicacion=-L $(QTDIR)/plugins/designer 				\
		-lQCtrlServidoresSiscom						\
		-lQCtrlUsuarios							\
		-lQCtrlPerfiles
BibliotecasControles=				\
		-L$(QTDIR)/lib 			\
	    	-L$(DIRLIBSISCOM2)		\
		-L$(QTDIR)/plugins/designer	\
	    	-lqt-mt				\
	    	-lSiscomComunicaciones++	\
	    	-lSiscomDesarrollo2		\
		-lQSiscomSepomex++
### biblioteca de SiscomFirmateSistema  a
### SiscomAplicaciones++, ya que en ella se almacenaran
### todas la clases de interfaz grafica


Pantallas_SiscomFirmateSistema=				\
			FirmaSistema			\
			Firmate				\
			BuscaPersonas

Archivos_QT_ControlSepomexComunicasExtra=		\
			CPP/MOC_QSisDirecciones.cpp	\
			CPP/MOC_QSisTelefonos.cpp
Archivos_O_ControlSepomexComunicasExtra=		\
			O/QSisDirecciones.o		\
			O/QSisTelefonos.o		\
			O/MOC_QSisDirecciones.o		\
			O/MOC_QSisTelefonos.o
ControlesAplicaciones=SepomexComunicas
Archivos_ControlesExtra=			\
		O/CQSisDirecciones.o		\
	        O/CQSisMedsComunicacion.o	\
		O/CQSisObjetosAplicaciones.o
			

Archivos_ControlesAplicaciones=				\
	$(call ArchivosControlQT,$(ControlesAplicaciones))


Archivos_H_SiscomFirmateSistema=							\
	$(DIRDesarrolloHGE)/SiscomAplicaciones/Cliente/H/UIC_H_FirmaSistema.h 		\
	$(DIRDesarrolloHGE)/SiscomAplicaciones/Cliente/H/IMP_FirmaSistema.h 		\
	$(DIRDesarrolloHGE)/SiscomAplicaciones/Cliente/H/UIC_H_Firmate.h		\
	$(DIRDesarrolloHGE)/SiscomAplicaciones/Cliente/H/IMP_Firmate.h			\
	$(DIRDesarrolloHGE)/SiscomAplicaciones/Cliente/H/QSisDirecciones.h		\
	$(DIRDesarrolloHGE)/SiscomAplicaciones/Cliente/H/QCtrlSepomexComunicas.h	\
	$(DIRDesarrolloHGE)/SiscomAplicaciones/Cliente/H/CQSisSepomexComunicas.h	\
	$(DIRDesarrolloHGE)/SiscomAplicaciones/Cliente/H/CQSisDirecciones.h		\
	$(DIRDesarrolloHGE)/SiscomAplicaciones/Cliente/H/QSisTelefonos.h		\
	$(DIRDesarrolloHGE)/SiscomAplicaciones/Cliente/H/CQSisBuscaPersonas.h		\
	$(DIRDesarrolloHGE)/SiscomAplicaciones/Cliente/H/UIC_H_BuscaPersonas.h		\
	$(DIRDesarrolloHGE)/SiscomAplicaciones/Cliente/H/IMP_BuscaPersonas.h
Archivos_QT_SiscomFirmateSistema=		\
	$(call ArchivosQTSistemaFormas, $(Pantallas_SiscomFirmateSistema))
Archivos_O_SiscomFirmateSistema=		\
	$(call ArchivosOSistemaFormas,$(Pantallas_SiscomFirmateSistema))	\
	O/CQSisBuscaPersonas.o


all:DirectorioO $(DIRLIBSISCOM2)/libSiscomFirmateSistema.so 		\
    $(Archivos_ControlesAplicaciones)				\
    $(call DependenciaControles,$(ControlesAplicaciones))	\
    Copia

DirectorioO:
	-mkdir O


$(DIRLIBSISCOM2)/libSiscomFirmateSistema.so:$(Archivos_QT_SiscomFirmateSistema) \
					    $(Archivos_O_SiscomFirmateSistema)
	@echo LDD $@
	@$(CXX) $(OpEnlace) $(OpModulos) -o $@ 		\
	$(Archivos_O_SiscomFirmateSistema) 		\
	$(BibliotecasAplicacion)
		
$(eval $(call GeneraControles,$(ControlesAplicaciones)))

Copia:$(Archivos_H_SiscomFirmateSistema)
	@ln -fs $(Archivos_H_SiscomFirmateSistema) $(DIRLIBSISCOM2)/H


clean:
	@echo Eliminando Archivos
	@-rm O/*.o
	@-rm CPP/MOC*.cpp
	@-rm CPP/UIC_CPP_*.cpp
	@-rm H/UIC_H_*.h
