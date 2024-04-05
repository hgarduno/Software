OpCompilacion+=-c -pipe  -W -O2 -D_REENTRANT -fPIC  -DQT_NO_DEBUG -DQT_THREAD_SUPPORT -DQT_PLUGIN -DQT_SHARED  $(DEBUG)   $(OpCSiscom)
Include+=-I H -I $(QTDIR)/include -I $(SISCOM_LIB_DIR)/Include -I . -I $(DIRLIBSISCOM2)/H  -I $$QtInclude
OpEnlaceMod+=-shared -rdynamic $(OpCSiscom)
OpEnlace+=$(OpCSiscom)
Bibliotecas=-L SO  -L $(SISCOM_LIB_DIR)  -L $(QTDIR)/lib   -lSISCOMDesarrollo++ -lSISCOMSeguridad3Q++  -lSISCOMDesarrolloQ++  -lqt-mt  -lqui  
BibliotecasSeguridad=-L SO  -L $(SISCOM_LIB_DIR)  -L $(QTDIR)/lib   -lSISCOMDesarrollo++ -lSISCOMDesarrolloQ++  -lqt-mt  -lqui  
BibliotecasDesarrollo=-L SO 						\
			     -lSISCOMControladorDeFormasYObj  		\
			    -lSISCOMAplicacionSeguridad3 		\
			     -lSISCOMSoporteAplicacionSeguridad  	\
			     -lSISCOMPerfiles 				\
			     -lSISCOMUsuarios 				\
			     -lSISCOMFirmas 				\
			     -lSISCOMActualizaPantalla

BibliotecasProtocolo2=-L$(DIRLIBSISCOM2) 	\
		      -lSiscomComunicaciones++ 	\
		      -lSiscomDesarrollo2	\
		      -lSiscomClasesGenerales++
ABibliotecaSeguridad=O/GeneralBibliotecaSeguridad3.o
APrueba=O/Prueba.o

Archivos_QT_ModuloActualizaPantalla=H/UIC_H_ActualizaPantalla.h \
				    CPP/UIC_CPP_ActualizaPantalla.cpp \
				    CPP/MOC_CPP_ActualizaPantalla.cpp \
				    CPP/MOC_CPP_IMP_ActualizaPantalla.cpp

Archivos_O_ModuloActualizaPantalla=O/UIC_CPP_ActualizaPantalla.o \
				   O/MOC_CPP_ActualizaPantalla.o \
				   O/MOC_CPP_IMP_ActualizaPantalla.o \
				   O/IMP_ActualizaPantalla.o 
Archivos_QT_ModuloFirmas=H/UIC_H_Firmas.h \
		   CPP/UIC_CPP_Firmas.cpp \
		   CPP/MOC_CPP_Firmas.cpp \
	 	   CPP/MOC_CPP_IMP_Firmas.cpp
Archivos_O_ModuloFirmas=O/UIC_CPP_Firmas.o \
			O/MOC_CPP_Firmas.o \
		        O/IMP_Firmas.o \
			O/MOC_CPP_IMP_Firmas.o
			
		        

Archivos_QT_PruebaGUI=H/UIC_H_PruebaGUI.h \
		      \
		      CPP/UIC_CPP_PruebaGUI.cpp \
		      CPP/MOC_CPP_PruebaGUI.cpp \
		      CPP/MOC_CPP_IMP_PruebaGUI.cpp 
Archivos_O_PruebaGUI=O/UIC_CPP_PruebaGUI.o \
		     O/MOC_CPP_PruebaGUI.o \
		     O/MOC_CPP_IMP_PruebaGUI.o \
		     O/IMP_PruebaGUI.o \
		     O/PrincipalPruebasGUI.o

Archivos_QT_AplicacionSeguridad=H/UIC_H_ControladorSeguridad.h \
				\
				CPP/UIC_CPP_ControladorSeguridad.cpp \
				CPP/MOC_CPP_ControladorSeguridad.cpp \
				CPP/MOC_CPP_IMP_ControladorSeguridad.cpp
Archivos_QT_ModuloPerfiles=H/UIC_H_Perfiles.h \
		     \
		     CPP/UIC_CPP_Perfiles.cpp \
		     CPP/MOC_CPP_Perfiles.cpp \
		     CPP/MOC_CPP_IMP_Perfiles.cpp  \
		     \
		     H/UIC_H_PerfilReferencia.h \
		     CPP/UIC_CPP_PerfilReferencia.cpp \
		     CPP/MOC_CPP_PerfilReferencia.cpp \
		     CPP/MOC_CPP_IMP_PerfilReferencia.cpp 


Archivos_O_ModuloPerfiles=O/UIC_CPP_Perfiles.o \
			  O/MOC_CPP_Perfiles.o \
			  O/MOC_CPP_IMP_Perfiles.o \
			  O/IMP_Perfiles.o \
			  O/UIC_CPP_PerfilReferencia.o \
			  O/MOC_CPP_PerfilReferencia.o \
			  O/MOC_CPP_IMP_PerfilReferencia.o \
			  O/IMP_PerfilReferencia.o

Archivos_QT_ModuloUsuarios=H/UIC_H_Usuarios.h \
			   CPP/UIC_CPP_Usuarios.cpp \
			   CPP/MOC_CPP_Usuarios.cpp \
			   CPP/MOC_CPP_IMP_Usuarios.cpp 

Archivos_O_ModuloUsuarios=O/UIC_CPP_Usuarios.o \
			  O/MOC_CPP_Usuarios.o \
			  O/MOC_CPP_IMP_Usuarios.o \
			  O/IMP_Usuarios.o 

Archivos_O_AplicacionSeguridad=O/PrincipalSeguridad.o  \
			       O/MOC_CPP_ControladorSeguridad.o \
			       O/UIC_CPP_ControladorSeguridad.o \
			       O/MOC_CPP_IMP_ControladorSeguridad.o \
			       O/IMP_ControladorSeguridad.o
Archivos_QT_ModuloControladorFormasYObj=\
			       H/UIC_H_ControlFormas.h \
				\
			       H/UIC_H_CapturaDatos.h \
				\
			       H/UIC_H_ObjetosEjecucion.h \
				\
			       H/UIC_H_SelIconos.h \
				\
			       CPP/UIC_CPP_ControlFormas.cpp \
			       CPP/MOC_CPP_ControlFormas.cpp \
			       CPP/MOC_CPP_IMP_ControlFormas.cpp \
				\
			       CPP/UIC_CPP_CapturaDatos.cpp \
			       CPP/MOC_CPP_CapturaDatos.cpp \
			       CPP/MOC_CPP_IMP_CapturaDatos.cpp \
			       CPP/MOC_CPP_IMP_SIN_UI_MenuOperaciones.cpp \
				\
				CPP/UIC_CPP_ObjetosEjecucion.cpp \
			        CPP/MOC_CPP_ObjetosEjecucion.cpp \
				CPP/MOC_CPP_IMP_ObjetosEjecucion.cpp \
				\
				CPP/UIC_CPP_SelIconos.cpp \
				CPP/MOC_CPP_SelIconos.cpp \
				CPP/MOC_CPP_IMP_SelIconos.cpp 
				
				
			        

				
Archivos_O_ModulosControladorFormasYObj=\
			       O/UIC_CPP_ControlFormas.o \
			       O/MOC_CPP_ControlFormas.o \
			       O/MOC_CPP_IMP_ControlFormas.o \
			       O/IMP_ControlFormas.o  \
			       \
			       O/UIC_CPP_CapturaDatos.o \
			       O/MOC_CPP_CapturaDatos.o \
			       O/MOC_CPP_IMP_CapturaDatos.o\
			       O/IMP_CapturaDatos.o \
			       O/IMP_SIN_UI_MenuOperaciones.o  \
			       O/MOC_CPP_IMP_SIN_UI_MenuOperaciones.o  \
			       O/UIC_CPP_ObjetosEjecucion.o \
			       O/MOC_CPP_ObjetosEjecucion.o \
			       O/MOC_CPP_IMP_ObjetosEjecucion.o \
			       O/IMP_ObjetosEjecucion.o \
			       O/UIC_CPP_SelIconos.o  \
			       O/MOC_CPP_SelIconos.o \
			       O/MOC_CPP_IMP_SelIconos.o \
			       O/IMP_SelIconos.o



				
Archivos_QT_ModuloAplicacionSeguridad3=\
				H/UIC_H_Aplicaciones.h \
				\
				CPP/UIC_CPP_Aplicaciones.cpp \
				CPP/MOC_CPP_Aplicaciones.cpp \
				CPP/MOC_CPP_IMP_Aplicaciones.cpp 
				
Archivos_O_ModuloAplicacionSeguridad3=\
			        O/UIC_CPP_Aplicaciones.o \
				O/MOC_CPP_Aplicaciones.o \
				O/MOC_CPP_IMP_Aplicaciones.o \
				O/IMP_Aplicaciones.o
			       
Archivos_O_ModuloSoporteAplicacionSeguridad=O/SoporteAplicacionSeguridad.o
Archivos_Seguridad3Prot2=O/Seguridad3Protocolo2.o 

####################### Controles de Seguridad3  ####################
Archivos_QT_ControlPerfiles=CPP/MOC_QCtrlPerfiles.cpp
Archivos_O_ControlPerfiles=O/MOC_QCtrlPerfiles.o  	\
			   O/QCtrlPerfiles.o		\
			   O/QCtrlPluginPerfiles.o

Archivos_QT_ControlUsuarios=CPP/MOC_QCtrlUsuarios.cpp 
Archivos_O_ControlUsuarios=O/MOC_QCtrlUsuarios.o	\
			   O/QCtrlUsuarios.o		\
			   O/QCtrlPluginUsuarios.o	

BibliotecasControles=-L $(DIRLIBSISCOM2) 		\
		     -L $(QTDIR)/lib			\
			-lqt-mt				\
			-lSiscomComunicaciones++      #\
			-lSiscomClasesGenerales++
			#-lSiscomSeguridad3Prot2++	\
#######################################################################

all:DirectorioO $(SISCOM_LIB_DIR)/libSISCOMSeguridad3Q++.so  	\
    SO/libSISCOMControladorDeFormasYObj.so 		\
    SO/libSISCOMAplicacionSeguridad3.so 		\
    SO/libSISCOMSoporteAplicacionSeguridad.so		\
    SO/libSISCOMPerfiles.so 				\
    SO/libSISCOMUsuarios.so  				\
    SO/libSISCOMFirmas.so 				\
    SO/libSISCOMActualizaPantalla.so 			\
    B/Prueba 						\
    B/SistemaDeSeguridad3  				\
    $(QTDIR)/plugins/designer/libQCtrlPerfiles.so	\
    $(QTDIR)/plugins/designer/libQCtrlUsuarios.so	\
    Copia
DirectorioO:
	-mkdir O
	-mkdir SO
Copia:
	#ln -sf $(DIRDesarrolloHGE)/SISCOMSeguridad3/Cliente/H/Seguridad3Protocolo2.h $(DIRLIBSISCOM2)/H/Seguridad3Protocolo2.h
	ln -sf $(DIRDesarrolloHGE)/SISCOMSeguridad3/Cliente/H/QCtrlPerfiles.h $(DIRLIBSISCOM2)/H/QCtrlPerfiles.h
	ln -sf $(DIRDesarrolloHGE)/SISCOMSeguridad3/Cliente/H/QCtrlUsuarios.h $(DIRLIBSISCOM2)/H/QCtrlUsuarios.h

B/PruebasGUI:$(Archivos_QT_PruebaGUI) $(Archivos_O_PruebaGUI)
	@echo Enlazando $@ 
	@$(CXX) $(OpEnlace) -o $@ $(Archivos_O_PruebaGUI) $(Bibliotecas) $(BibliotecasDesarrollo)
SO/libSISCOMFirmas.so:$(Archivos_QT_ModuloFirmas)  $(Archivos_O_ModuloFirmas)
	@echo Enlazando $@
	@$(CXX) $(OpEnlaceMod) -o $@ $(Archivos_O_ModuloFirmas) $(Bibliotecas)
		
SO/libSISCOMActualizaPantalla.so:$(Archivos_QT_ModuloActualizaPantalla)  $(Archivos_O_ModuloActualizaPantalla)
	@echo Enlazando $@
	@$(CXX) $(OpEnlaceMod) -o $@ $(Archivos_O_ModuloActualizaPantalla) $(Bibliotecas)
SO/libSISCOMSoporteAplicacionSeguridad.so:$(Archivos_O_ModuloSoporteAplicacionSeguridad)
	@echo Enlazando $@
	@$(CXX) $(OpEnlaceMod) -o $@ $(Archivos_O_ModuloSoporteAplicacionSeguridad) $(Bibliotecas)
$(SISCOM_LIB_DIR)/libSISCOMSeguridad3Q++.so:$(ABibliotecaSeguridad)\
			     $(SISCOM_LIB_DIR)/libSISCOMDesarrollo++.so \
			     $(SISCOM_LIB_DIR)/libSISCOMDesarrolloQ++.so
		
	@echo Enlazando $@
	@$(CXX) $(OpEnlaceMod) -o $@ $(ABibliotecaSeguridad) $(BibliotecasSeguridad)
	@echo Copiando Cabeceras
	@cp H/GeneralBibliotecaSeguridad3.h $(SISCOM_LIB_DIR)/Include

SO/libSISCOMAplicacionSeguridad3.so:$(Archivos_QT_ModuloAplicacionSeguridad3)  \
				    $(Archivos_O_ModuloAplicacionSeguridad3)
	@echo Enlazando $@
	@$(CXX) $(OpEnlaceMod) -o $@ $(Archivos_O_ModuloAplicacionSeguridad3) $(Bibliotecas)

SO/libSISCOMPerfiles.so:$(Archivos_QT_ModuloPerfiles)\
				       $(Archivos_O_ModuloPerfiles)
	@echo Enlazando $@
	@$(CXX) $(OpEnlaceMod) -o $@ $(Archivos_O_ModuloPerfiles) $(Bibliotecas)

SO/libSISCOMUsuarios.so:$(Archivos_QT_ModuloUsuarios)\
				       $(Archivos_O_ModuloUsuarios)
	@echo Enlazando $@
	@$(CXX) $(OpEnlaceMod) -o $@ $(Archivos_O_ModuloUsuarios) $(Bibliotecas)


SO/libSISCOMControladorDeFormasYObj.so:$(Archivos_QT_ModuloControladorFormasYObj)\
				       $(Archivos_O_ModulosControladorFormasYObj)
	@echo Enlazando $@
	@$(CXX) $(OpEnlaceMod) -o $@ $(Archivos_O_ModulosControladorFormasYObj) $(Bibliotecas)

$(QTDIR)/plugins/designer/libQCtrlPerfiles.so:$(Archivos_QT_ControlPerfiles)	\
					      $(Archivos_O_ControlPerfiles)
	@echo Enlazando $@
	@$(CXX) $(OpEnlaceMod) -o $@ $(Archivos_O_ControlPerfiles) 	\
	 $(BibliotecasControles)

$(QTDIR)/plugins/designer/libQCtrlUsuarios.so:$(Archivos_QT_ControlUsuarios)	\
					      $(Archivos_O_ControlUsuarios)
	@echo Enlazando $@
	@$(CXX) $(OpEnlaceMod) -o $@ $(Archivos_O_ControlUsuarios) 	\
	 $(BibliotecasControles)
	
B/SistemaDeSeguridad3:							\
		      	$(Archivos_QT_AplicacionSeguridad) 		\
		      	$(Archivos_O_AplicacionSeguridad) 		\
		      	$(SISCOM_LIB_DIR)/libSISCOMSeguridad3Q++.so 	\
		      	SO/libSISCOMControladorDeFormasYObj.so 		\
          	      	SO/libSISCOMAplicacionSeguridad3.so 		\
	              	SO/libSISCOMSoporteAplicacionSeguridad.so 	\
			SO/libSISCOMUsuarios.so
	@echo Enlazando $@ 
	$(CXX) $(OpEnlace) -o $@ $(Archivos_O_AplicacionSeguridad) $(Bibliotecas) $(BibliotecasDesarrollo)

B/Prueba:$(APrueba) $(SISCOM_LIB_DIR)/libSISCOMSeguridad3Q++.so SO/libSISCOMControladorDeFormasYObj.so \
          SO/libSISCOMAplicacionSeguridad3.so \
	  SO/libSISCOMSoporteAplicacionSeguridad.so
	@echo Enlazando $@ 
	@$(CXX) $(OpEnlace) -o $@ $(APrueba) $(Bibliotecas) $(BibliotecasDesarrollo)
O/%.o:CPP/%.cpp
	@echo Compilando $<
	@$(GCC) $(OpCompilacion) $(Include) -o $@ $< 
$(DIRLIBSISCOM2)/libSiscomSeguridad3Prot2++.so:$(Archivos_Seguridad3Prot2)
	@echo Enlazando $@ 
	@$(CXX) $(OpEnlaceMod) -o $@ $(Archivos_Seguridad3Prot2) $(BibliotecasProtocolo2) 
H/UIC_H%.h:UI/UI%.ui
	@echo UIC $<
	@$(UIC) -o $@ $<
CPP/UIC_CPP%.cpp:UI/UI%.ui
	@echo UIC [IMP] $<
	@$(UIC) -o$@ -impl H/UIC_H$*.h  $<
CPP/MOC_CPP%.cpp:H/UIC_H%.h
	@echo MOC $<
	@$(MOC) -o $@ $<
CPP/MOC_CPP_IMP%.cpp:H/IMP%.h
	@echo MOC $<
	@$(MOC) -o $@ $<

CPP/MOC_QCtrl%.cpp:H/QCtrl%.h
	@echo MOC $<
	@$(MOC) -o $@ $<

clean:
	-rm CPP/UIC_CPP* CPP/MOC_CPP* H/UIC_H* O/*

