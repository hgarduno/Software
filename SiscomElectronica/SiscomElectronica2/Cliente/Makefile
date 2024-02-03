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


Pantallas_SiscomElectronica2=				\
				RegistroClientes


ControlesSiscomElectronica2=				\
				Escuelas

Archivos_QT_PantallasSiscomElectronica2=		\
	$(call ArchivosQTSistemaFormas,$(Pantallas_SiscomElectronica2))

Archivos_O_PantallasSiscomElectronica2=			\
	$(call ArchivosOSistemaFormas,$(Pantallas_SiscomElectronica2))



Archivos_ControlesExtra=

Archivos_ControlesSiscomElectronica2=					\
	$(call ArchivosControlQT,$(ControlesSiscomElectronica2))	\
	$(Archivos_O_ControlesExtra)


Binarios=$(Archivos_ControlesSiscomElectronica2) 			\
	 $(call DependenciaControles,$(ControlesSiscomElectronica2))	\
	  SO/libPantallasSiscomElectronica2.so


Bibliotecas=	-L$(QTDIR)/lib 			\
		-L$(QTDIR)/plugins/designer	\
	    	-L$(DIRLIBSISCOM2)		\
	    	-lqt-mt				\
	    	-lSiscomDesarrollo2		\
	    	-lSepomexCliente		\
	    	-lSiscomComunicaciones++	\
	    	-lQSiscomSepomex++		\
		-lControlEscuelas



BibliotecasControles=				\
		-L$(QTDIR)/lib 			\
	    	-L$(DIRLIBSISCOM2)		\
	    	-lqt-mt				\
		-lSiscomDesarrollo3Qt++

Archivos_H_Controles=\
$(DIRDesarrolloHGE)/SiscomElectronica/SiscomElectronica2/Cliente/H/QCtrlEscuelas.h 


#all:$(Binarios) Copia
all:$(Archivos_ControlesSiscomElectronica2)	\
	Copia					\
	 $(call DependenciaControles,$(ControlesSiscomElectronica2))	\
	  SO/libPantallasSiscomElectronica2.so
	



Copia:$(Archivos_H_Controles)
	@for X in $(Archivos_H_Controles) ;	\
	do					\
 	ln -fs $$X $(DIRLIBSISCOM2)/H;		\
 	done




SO/libPantallasSiscomElectronica2.so:$(Archivos_QT_PantallasSiscomElectronica2) \
				     $(Archivos_O_PantallasSiscomElectronica2)
	@echo 'Generando $@'
	@$(CXX) $(OpModulos) -o $@ 				\
		$(Archivos_O_PantallasSiscomElectronica2) 	\
		$(Bibliotecas)

$(eval $(call GeneraControles,$(ControlesSiscomElectronica2)))

clean:
	@echo 'Eliminando archivos'
	@-rm CPP/MOC_CPP_*.cpp
	@-rm CPP/UIC_CPP_*.cpp
	@-rm UI/*.ui~
	@-rm H/UIC_H_*.h
	@-rm O/*.o
	@-rm SO/*.so
