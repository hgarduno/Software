#####################
#####################
#####################
#####################
# Al momento de generar un control, es muy importante que se realice de la siguiente
# forma:
# Tomar como plantilla los archivos en qt-rc/tools/designer/examples/filechooser/widget y
# qt-src/tools/designer/examples/filechooser/plugin
# Al momento de editar estos archivos ser debera sustituir en las clases del plugin
# y del widget FileChooser por el nombre de la clase que se debera implantar 
# es necesario antes de hacer cualquier cosa, verificar que el nuevo control se 
# integre al qt, ya que al desarrollar los controles de sepomex, no se tomo esta
# precaucion, y se incurrio en el error, de que la integracion con el designer 
# no estaba bien, lo que trajo como consecuencia que el control no se mostrara 
# en las formas en tiempo de desarrollo.
#
# 2007-08-18  Queretaro









define ArchivosBibliotecaQTForma
Archivos_QT_$(1)=H/UIC_H_Q$(1).h \
		 CPP/UIC_CPP_Q$(1).cpp \
		 CPP/MOC_CPP_Q$(1).cpp \
		 CPP/MOC_CPP_IMP_Q$(1).cpp
Archivos_O_$(1)=O/UIC_CPP_Q$(1).o \
		O/MOC_CPP_Q$(1).o \
		O/MOC_CPP_IMP_Q$(1).o \
		O/IMP_Q$(1).o
endef 
define EnlaceBibliotecaQTForma
lib$(1).so:$(Archivos_QT_$(1)) \
	   $(Archivos_O_$(1)) \
	   $(Archivos_O_Extra_$(1)) \
	   $(Archivos_QT_Extra_$(1))
	@echo Generando lib$(1).so
	@$(CXX) $(OpModulos) -o lib$(1).so $(Archivos_O_$(1)) $(Archivos_O_Extra_$(1)) $(Bibliotecas)
endef

Archivos_QT_ServidoresSiscom=CPP/MOC_CPP_QCtrlServidoresSiscom.cpp
Archivos_O_ServidoresSiscom=O/MOC_CPP_QCtrlServidoresSiscom.o 		\
			    O/QCtrlServidoresSiscom.o			\
			    O/QCtrlPluginServidoresSiscom.o

Archivos_QT_PruebaControl=CPP/MOC_CPP_PruebaControl.cpp 
Archivos_O_PruebaControl=O/MOC_CPP_PruebaControl.o \
			 O/PruebaControl.o \
			 O/PruebaPlugin.o

Archivos_QT_OperacionesPersonas=CPP/MOC_CPP_QSisOperacionesPersonas.cpp 
Archivos_O_OperacionesPersonas=O/MOC_CPP_QSisOperacionesPersonas.o \
			       O/QSisOperacionesPersonas.o \
			       O/PluginOperacionesPersonas.o
Archivos_QT_Sepomex=CPP/MOC_CPP_QSisSepomex.cpp
Archivos_O_Sepomex=O/QSisSepomex.o 		\
		   O/PluginSepomex.o 		\
		   O/MOC_CPP_QSisSepomex.o 

Archivos_QT_ControlFecha=\
		 CPP/MOC_CPP_IMP_QControlFecha.cpp 	\
		 CPP/MOC_CPP_QCtrlFechaHora.cpp		\
		 CPP/MOC_CPP_QCtrlRangoHora.cpp



Archivos_O_ControlFecha= \
			O/MOC_CPP_IMP_QControlFecha.o  	\
			O/MOC_CPP_QCtrlFechaHora.o	\
			O/MOC_CPP_QCtrlRangoHora.o	\
			O/QCtrlFechaHora.o		\
			O/QCtrlRangoHora.o		\
			O/IMP_QControlFecha.o

			

Archivos_QT_ControlSepomexDireccion=\
		 CPP/MOC_CPP_IMP_QControlSepomexDireccion.cpp 


Archivos_O_ControlSepomexDireccion= \
			O/MOC_CPP_IMP_QControlSepomexDireccion.o  \
			O/IMP_QControlSepomexDireccion.o \
			O/IMP_PluginControlSepomexDireccion.o


Archivos_QT_ControlFecha2=CPP/MOC_CPP_IMP_QControlFecha2.cpp CPP/QCtrlFechaHora.cpp  
Archivos_O_ControlFecha2=O/MOC_CPP_IMP_QControlFecha2.o O/IMP_PluginControlFecha2.o O/IMP_QControlFecha2.o O/QCtrlFechaHora.o O/MOC_QCtrlFechaHora.o

Archivos_O_Extra_ControlDireccion=O/IMP_PluginControlDireccion.o
Archivos_O_Extra_ControlNombres=O/IMP_PluginControlNombres.o

Archivos_O_SISCOMComunControles=O/LibSISCOMComunControles.o


Archivos_QT_Plugin=

Archivos_O_Plugin=O/IMP_PluginControlFecha.o

OpCompilacion=-c -pipe -Wall -W -O2 -D_REENTRANT -fPIC  -DQT_NO_DEBUG -DQT_THREAD_SUPPORT -DQT_PLUGIN -DQT_SHARED  $(DEBUG) $(OpCSiscom)

Include= -I $(QTDIR)/include -I . -I H -I $(DIRLIBSISCOM2)/H   -I $$QtInclude

Bibliotecas=-L $(QTDIR)/lib 			\
	     -L .  				\
	     -L $(DIRLIBSISCOM2) 		\
	     -lqt-mt   				\
	     -lSiscomDesarrollo2  		\
	     -lSiscomDesarrollo3Qt++		\
	     -lSepomexCliente
BibliotecasControlFecha=				\
		-L $(QTDIR)/lib 			\
	     	-L .  					\
	     	-L $(DIRLIBSISCOM2) 			\
	     	-lqt-mt   				\
	     	-lSiscomComunicaciones++ 		\
	     	-lSiscomDesarrollo2  			\
	     	-lSISCOMComunControlesDesarrollo2	

OpModulos=-shared $(DEBUG) $(OpCSiscom)

$(eval $(call ArchivosBibliotecaQTForma,ControlDireccion))
$(eval $(call ArchivosBibliotecaQTForma,ControlNombres))


#all:libSISCOMComunControlesDesarrollo2.so \
#      libPruebaControl.so		\
#	l bSepomexDireccion.so \
#	libControlSepomexDireccion.so \
#	libControlNombres.so	\
#	libControlDireccion.so  \
#	PruebaControl #\
#	Copia

all:\
	$(DIRLIBSISCOM2)/libSISCOMComunControlesDesarrollo2.so 		\
	$(QTDIR)/plugins/designer/libControlFechaDesarrollo2.so 	\
	$(QTDIR)/plugins/designer/libQSiscomSepomex++.so 	 	\
	$(QTDIR)/plugins/designer/libQSiscomOperacionesPersonas.so 	\
	$(QTDIR)/plugins/designer/libQCtrlServidoresSiscom.so		\
	Copia								

$(eval $(call EnlaceBibliotecaQTForma,ControlDireccion))
$(eval $(call EnlaceBibliotecaQTForma,QControlNombres))


Copia:
	@echo Copiando Archivos Cabecera
	@ln -sf $(DIRDesarrolloHGE)/SISCOMControles2/H/IMP_QControl*.h $(DIRLIBSISCOM2)/H
	@ln -sf $(DIRDesarrolloHGE)/SISCOMControles2/H/QSis*.h $(DIRLIBSISCOM2)/H
	@ln -sf $(DIRDesarrolloHGE)/SISCOMControles2/H/QCtrl*.h $(DIRLIBSISCOM2)/H

$(QTDIR)/plugins/designer/libQSiscomOperacionesPersonas.so:$(Archivos_QT_OperacionesPersonas) \
							$(Archivos_O_OperacionesPersonas)
	@echo LD $@
	@$(CXX) $(OpModulos) -o$@ \
	$(Archivos_O_OperacionesPersonas) \
	$(Bibliotecas)

$(QTDIR)/plugins/designer/libQSiscomSepomex++.so:$(Archivos_QT_Sepomex) \
					      $(Archivos_O_Sepomex)
	@echo Generando $@
	$(CXX) $(OpModulos) -o$@ $(Archivos_O_Sepomex) $(Bibliotecas)
$(QTDIR)/plugins/designer/libPruebaControl.so:$(Archivos_QT_PruebaControl) \
					      $(Archivos_O_PruebaControl)
	@echo LD $@
	@$(CXX) $(OpModulos) -o$@ $(Archivos_O_PruebaControl) $(Bibliotecas)
libControlSepomexDireccion.so:$(Archivos_QT_ControlSepomexDireccion) \
			      $(Archivos_O_ControlSepomexDireccion)
	
	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_ControlSepomexDireccion) \

$(QTDIR)/plugins/designer/libControlFechaDesarrollo2.so:\
		 $(Archivos_QT_ControlFecha)  	\
		 $(Archivos_O_ControlFecha)   	\
		 $(Archivos_QT_Plugin)  	\
		 $(Archivos_O_Plugin)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o$@  		\
		$(Archivos_O_ControlFecha) 	\
		$(Archivos_O_Plugin) 		\
		$(BibliotecasControlFecha)
$(QTDIR)/plugins/designer/libQCtrlServidoresSiscom.so:$(Archivos_QT_ServidoresSiscom) \
						      $(Archivos_O_ServidoresSiscom)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_ServidoresSiscom) \
	$(Bibliotecas)


#$(QTDIR)/plugins/designer/libControlFechaDesarrollo2.so:\
				$(Archivos_QT_ControlFecha2) \
#				$(Archivos_O_ControlFecha2)
#	@echo Generando $@
#	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_ControlFecha2) $(Bibliotecas)
#
$(DIRLIBSISCOM2)/libSISCOMComunControlesDesarrollo2.so:$(Archivos_O_SISCOMComunControles)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_SISCOMComunControles)  
	
H/UIC_H_%.h:UI/%.ui
	@echo UIC $<
	@$(UIC) -o $@ $<
CPP/UIC_CPP_%.cpp:UI/%.ui
	@echo UIC [IMP] $@
	@$(UIC) -impl H/UIC_H_$*.h -o $@ $<

CPP/MOC_CPP_%.cpp:H/UIC_H_%.h
	@echo MOC $@
	@$(MOC) -o $@ $<
CPP/MOC_CPP_IMP_%.cpp:H/IMP_%.h
	@echo MOC $@
	@$(MOC) -o $@ $<

CPP/MOC_CPP_%.cpp:H/%.h
	@echo MOC $@
	@$(MOC) -o $@ $<
O/%.o:CPP/%.cpp
	@echo Compilando $<
	$(CXX) $(OpCompilacion) $(Include) -o $@ $<

PruebaControl:$(Archivos_O_Prueba)
	@echo Enlazando $@
	@$(CXX) -o $@ $(Archivos_O_Prueba) -L. \
	-lControlFechaDesarrollo2 \
	-lControlSepomexDireccion  \
	$(Bibliotecas) 

clean:
	@-rm O/*.o
	@-rm CPP/UIC_CPP*
	@-rm CPP/MOC_CPP*
	@-rm $(DIRLIBSISCOM2)/libSISCOMComunControlesDesarrollo2.so
	@-rm $(QTDIR)/plugins/designer/libControlFechaDesarrollo2.so
	@-rm $(QTDIR)/plugins/designer/libQSiscomSepomex++.so
