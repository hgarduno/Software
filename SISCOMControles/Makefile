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






Archivos_QT_ControlFecha=\
		 CPP/MOC_CPP_IMP_QControlFecha.cpp 


Archivos_O_ControlFecha= \
			O/MOC_CPP_IMP_QControlFecha.o  \
			O/IMP_QControlFecha.o

Archivos_QT_ControlFecha2=CPP/MOC_CPP_IMP_QControlFecha2.cpp  
Archivos_O_ControlFecha2=O/MOC_CPP_IMP_QControlFecha2.o O/IMP_PluginControlFecha2.o O/IMP_QControlFecha2.o

Archivos_O_Extra_ControlDireccion=O/IMP_PluginControlDireccion.o
Archivos_O_Extra_ControlNombres=O/IMP_PluginControlNombres.o

Archivos_O_Prueba=O/PruebaControl.o

Archivos_O_SISCOMComunControles=O/LibSISCOMComunControles.o


Archivos_QT_Plugin=

Archivos_O_Plugin=O/IMP_PluginControlFecha.o

OpCompilacion=-c -pipe -Wall -W -O2 -D_REENTRANT -fPIC  -DQT_NO_DEBUG -DQT_THREAD_SUPPORT -DQT_PLUGIN -DQT_SHARED $(DEBUG) $(OpCSiscom)

Include= -I $(QTDIR)/include -I . -I H -I $(SISCOM_LIB_DIR)/Include

Bibliotecas=-L $(QTDIR)/lib -L . -L $(SISCOM_LIB_DIR) -lqt-mt -lSISCOMComunControles  -lSISCOMDesarrolloQ++ -lSISCOMDesarrollo++

OpModulos=-shared $(DEBUG) $(OpCSiscom)

$(eval $(call ArchivosBibliotecaQTForma,ControlDireccion))
$(eval $(call ArchivosBibliotecaQTForma,ControlNombres))


all:DirectorioO 			\
	libSISCOMComunControles.so \
	QControlFecha.so \
	libControlFecha2.so \
	libControlDireccion.so \
	libControlNombres.so \
	PruebaControl \
	Copia

DirectorioO:
	-mkdir O
$(eval $(call EnlaceBibliotecaQTForma,ControlDireccion))
$(eval $(call EnlaceBibliotecaQTForma,ControlNombres))

Copia:
	cp libControlFecha.so $(QTDIR)/plugins/designer/
	cp libControlDireccion.so $(QTDIR)/plugins/designer
	cp libControlNombres.so $(QTDIR)/plugins/designer
	cp libSISCOMComunControles.so $(QTDIR)/plugins/designer
	cp H/UIC_H_QControl*.h $(SISCOM_LIB_DIR)/Include
	cp H/IMP_QControl*.h $(SISCOM_LIB_DIR)/Include
	
des:
	@echo $(Archivos_QT_QControlDireccion) $(Archivos_O_QControlDireccion)


libControlFecha2.so:$(Archivos_QT_ControlFecha2) \
		     $(Archivos_O_ControlFecha2)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_ControlFecha2) $(Bibliotecas)
QControlFecha.so:$(Archivos_QT_ControlFecha)  \
		 $(Archivos_O_ControlFecha)   \
		 $(Archivos_QT_Plugin)  \
		 $(Archivos_O_Plugin)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o libControlFecha.so $(Archivos_O_ControlFecha) $(Archivos_O_Plugin) $(Bibliotecas)

libSISCOMComunControles.so:$(Archivos_O_SISCOMComunControles)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_SISCOMComunControles)  $(Bibliotecas)
	
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

O/%.o:CPP/%.cpp
	@echo Compilando $<
	@$(CXX) $(OpCompilacion) $(Include) -o $@ $<

PruebaControl:$(Archivos_O_Prueba)
	@echo Enlazando $@
	$(CXX) $(OpCSiscom) -o $@ $(Archivos_O_Prueba) -L. -lControlFecha -lControlDireccion $(Bibliotecas)

clean:
	rm O/*.o
	rm CPP/UIC_CPP*
	rm CPP/MOC_CPP*
