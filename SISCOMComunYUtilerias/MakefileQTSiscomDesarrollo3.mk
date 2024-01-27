define ArchivosBibliotecaQTForma
Archivos_QT_$(1)=H/UIC_H_$(1).h \
		 CPP/UIC_CPP_$(1).cpp \
		 CPP/MOC_CPP_$(1).cpp \
		 CPP/MOC_CPP_IMP_$(1).cpp
Archivos_O_$(1)=O/UIC_CPP_$(1).o \
		O/MOC_CPP_$(1).o \
		O/MOC_CPP_IMP_$(1).o \
		O/IMP_$(1).o
endef 
define EnlaceBibliotecaQTForma
SO/lib$(1).so:$(Archivos_QT_$(1)) \
	   $(Archivos_QT_Extra_$(1)) \
	   $(Archivos_O_$(1)) \
	   $(Archivos_O_Extra_$(1))
	@echo Generando lib$(1).so
	@$(CXX) $(OpModulos) -o SO/lib$(1).so $(Archivos_O_$(1)) $(Archivos_O_Extra_$(1)) $(Bibliotecas) $(Bibliotecas_$(1))
endef

define ArchivosQTSistemaFormas
$(foreach Pantalla,$(1),H/UIC_H_$(Pantalla).h) 		\
$(foreach Pantalla,$(1),CPP/UIC_CPP_$(Pantalla).cpp)	\
$(foreach Pantalla,$(1),CPP/MOC_CPP_$(Pantalla).cpp)	\
$(foreach Pantalla,$(1),CPP/MOC_CPP_IMP_$(Pantalla).cpp)	
endef
			
define ArchivosOSistemaFormas
$(foreach Pantalla,$(1),O/UIC_CPP_$(Pantalla).o)		\
$(foreach Pantalla,$(1),O/MOC_CPP_$(Pantalla).o)		\
$(foreach Pantalla,$(1),O/MOC_CPP_IMP_$(Pantalla).o)		\
$(foreach Pantalla,$(1),O/IMP_$(Pantalla).o)
endef

define ArchivosQTSistema
$(foreach Archivo,$(1),CPP/MOC_$(Archivo).cpp)
endef

define ArchivosOSistema
$(foreach Archivo,$(1),O/$(Archivo).o)			\
$(foreach Archivo,$(1),O/MOC_$(Archivo).o)
endef
# Martes 23 de Octubre del 2012
# Con la nueva estructura de integrar en un solo
# archivo Plugin todos los controles de la aplicacion
# se modifico la Macro ArchivosControlQT para eliminar
# de cada entrada estos archivos


define ArchivosControlQT2
$(foreach Archivo,$(1),CPP/MOC_QCtrl$(Archivo).cpp)		\
$(foreach Archivo,$(1),O/QCtrl$(Archivo).o)			\
$(foreach Archivo,$(1),O/MOC_QCtrl$(Archivo).o)			\
$(foreach Archivo,$(1),O/CQSis$(Archivo).o)
endef

define ArchivosControlQT
$(foreach Archivo,$(1),CPP/MOC_QCtrl$(Archivo).cpp)		\
$(foreach Archivo,$(1),O/QCtrl$(Archivo).o)			\
$(foreach Archivo,$(1),O/MOC_QCtrl$(Archivo).o)			\
$(foreach Archivo,$(1),O/QCtrlPlugin$(Archivo).o) 		\
$(foreach Archivo,$(1),O/CQSis$(Archivo).o)
endef

# Domingo 31 Julio 2011
# Se pasa solo el Nombre por ejemplo 
# QCtrlAlumnos, se debera pasar Alumno, y debera
# existir el archivo QCtrlAlumnos.h
define ArchivosClasesQT
$(foreach Archivo,$(1),CPP/MOC_QCtrl$(Archivo).cpp)
endef 

define ArchivosOClasesQT2
$(foreach Archivo,$(1),O/QCtrl$(Archivo).o)		\
$(foreach Archivo,$(1),O/MOC_QCtrl$(Archivo).o)		\
$(foreach Archivo,$(1),O/CQSis$(Archivo).o)
endef 
define ArchivosOClasesQT
$(foreach Archivo,$(1),O/QCtrl$(Archivo).o)		\
$(foreach Archivo,$(1),O/MOC_QCtrl$(Archivo).o)
endef 
define ArchivosQTControl
CPP/MOC_QCtrl$(1).cpp	
endef
define ArchivosOControl
O/QCtrl$(1).o		\
O/MOC_QCtrl$(1).o	\
O/QCtrlPlugin$(1).o	\
O/CQSis$(1).o
endef

define ArchivosOPlugin
O/QCtrlPlugin$(1).o
endef


# Los controles de una aplicaciones en una
# sola biblioteca

define GeneraControles2
$(QTDIR)/plugins/designer/libControl$(1).so:							\
					    $$(Archivos_QT_Controlitos$(1)Extra)		\
					    $$(call ArchivosOPlugin,$(1))			\
					    $$(call ArchivosControlQT2,$(Controlitos$(1))) 	\
		 			    $$(call ArchivosOClasesQT2,$(Controlitos$(1)))	\
					    $$(Archivos_O_Controlitos$(1)Extra)
	@echo Generando $$@
	$$(CXX) $$(OpModulos) -o $$@				\
		 $$(call ArchivosOPlugin,$(1))			\
		 $$(call ArchivosOClasesQT2,$(Controlitos$(1)))	\
		 $$(Archivos_O_Controlitos$(1)Extra)		\
		 $$(BibliotecasControles)
endef


define GeneraControl
$(QTDIR)/plugins/designer/libControl$(1).so:$$(call ArchivosQTControl,$(1))	\
					    $$(Archivos_QT_Control$(1)Extra)    \
					    $$(call ArchivosOControl,$(1))  	\
					    $$(Archivos_O_Control$(1)Extra)	\
					    $$(Archivos_ControlesExtra)		
	@echo Generando $$@
	@$$(CXX) $$(OpModulos) -o $$@			\
		 $$(call ArchivosOControl,$(1))		\
		 $$(Archivos_ControlesExtra)		\
		 $$(Archivos_O_Control$(1)Extra)	\
		 $$(BibliotecasControles)
endef

define GeneraControles
$(foreach Control,$(1),$(eval $(call GeneraControl,$(Control))))
endef

define DependenciaControles
$(foreach Control,$(1),$(QTDIR)/plugins/designer/libControl$(Control).so)
endef






H/UIC_H_%.h:UI/%.ui
	@echo UIC `basename $@`
	@$(UIC) -o $@ $<
CPP/UIC_CPP_%.cpp:UI/%.ui
	@echo UIC [IMP] `basename $@`
	@$(UIC) -impl H/UIC_H_$*.h -o $@ $<

CPP/MOC_CPP_%.cpp:H/UIC_H_%.h
	@echo MOC `basename $@`
	@$(MOC) -o $@ $<
CPP/MOC_CPP_IMP_%.cpp:H/IMP_%.h
	@echo MOC `basename $@`
	@$(MOC) -o $@ $<

O/%.o:CPP/%.cpp
	@echo CXX `basename $@`
	@$(CXX) $(OpCompilacion) $(Include) -o $@ $<
CPP/MOC_%.cpp:H/%.h
	@echo MOC `basename $@`
	@$(MOC) -o $@ $<

CPP/MOC_CPP_%.cpp:H/%.h
	@echo MOC `basename $@`
	@$(MOC) -o $@ $<



