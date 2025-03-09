include MakefileQtSiscomControles3

Biblioteca2=O/SiscomProtocolo2.o 			\
	    O/SiscomProtocolo2SubRegistros.o		\
	    O/SiscomModuloOperaciones.o 		\
	    O/SiscomModuloOperacionesSubRegistros.o	\
	   O/SiscomFuncionesComunes.o  			\
	   O/SiscomOperacionesDirectorios.o  		\
	   O/SiscomCpuInfo.o				\
	   O/SiscomTransformaImporteALetra.o		\
	   O/SiscomLineaComandos.o			\
	   O/SiscomSqlOperaciones2.o			\
	   O/SiscomNormalizacion.o

Biblioteca2CXX_QT=CPP/MOC_SISCOMVentanaPrincipal3.cpp
Biblioteca2CXX=					\
		O/SISCOMVentanaPrincipal3.o	\
		O/MOC_SISCOMVentanaPrincipal3.o	\
		O/SiscomRegistrosPro2.o		\
		O/SiscomRegistroPro2.o		\
		O/SiscomCampoPro2.o		\
		O/SiscomComunicaSrv.o		\
		O/SiscomDatCom.o		\
		O/SiscomOperaciones.o		\
		O/SiscomInformacion.o		\
		O/SiscomGeneralOperacionesSrv.o	\
		O/SISCOMComunicaciones++.o 	\
		O/Seguridad3Protocolo2.o	\
		O/QSisOperacionPersona.o 	\
		O/QSisIconDatosPersona.o 	\
		O/QSisBibliotecaOpPersonas.o	\
		O/QSisIteradorPersonas.o	\
		O/SisPersonas.o			\
		O/SisDirecciones.o		\
		O/SisMedioComunicacion.o	\
		O/SisDatPersonales.o

ArchivosPostgresql=O/POSTGRESQLComunes.o O/POSTGRESQLControlador.o
Include=-IH -I$(DIRPOSTGRESQL)/include -I$(QTDIR)/include  -I Servidor/H -I $$QtInclude -I SISCOMDesarrollo2
OpC=$(DEBUG) -c  $(OpCSiscom)
OpCXX=$(DEBUG) -c -pipe -Wall -W -O2 -D_REENTRANT  -DQT_NO_DEBUG -DQT_THREAD_SUPPORT -DQT_SHARED $(OpCSiscom)

OpShared=$(DEBUG) -shared  -rdynamic $(OpCSiscom) $(OpCSiscom)
OpBinarios=$(DEBUG)  $(OpCSiscom)
Archivos_Qt_SiscomDesarrollo3=CPP/MOC_SiscomImprime.cpp 		\
			      CPP/MOC_SiscomVentanaPrincipal.cpp	\
			      CPP/MOC_SiscomQAction.cpp
Archivos_SiscomDesarrollo3=O/SiscomCampos3.o				\
			   O/SiscomRegistros3.o				\
			   O/SiscomRegistros4.o				\
			   O/SiscomOperaciones3.o 			\
			   O/SiscomDatCom.o				\
			   O/SiscomParametroConsulta3.o			\
			   O/SiscomDesarrollo3Qt++.o			\
			   O/SiscomTableItemColor.o			\
			   O/SiscomImprime.o				\
			   O/SiscomCpuInfo3.o				\
			   O/SiscomArchivoIni.o				\
			   O/SiscomVariableIni.o			\
			   O/SiscomVariablesIni.o			\
			   O/SiscomClaseIni.o				\
			   O/SiscomClasesIni.o				\
			   O/SiscomPopupMenu.o				\
			   O/SiscomCreaModuloValidacionCpuInfo.o 	\
			   O/SiscomVentanaPrincipal.o			\
			   O/SiscomQAction.o				\
			   O/SiscomModulo.o				\
			   O/SiscomModulos.o				\
			   O/OpSeguridad3.o				\
			   O/CQSisPersonasProt3.o			\
			   O/MOC_SiscomImprime.o			\
			   O/MOC_SiscomVentanaPrincipal.o		\
			   O/MOC_SiscomQAction.o
BibliotecasSiscomDesarrollo3=-L $(QTDIR)/lib -lqt-mt

Binarios=libSiscomDesarrollo2.so  		\
	 libSiscomComunicaciones++.so  		\
	 libSiscomDesarrolloPostgresql.so 	\
	 libSiscomDesarrollo3Qt++.so



### Tepotzotlan Mexico Sabado 13 de junio 2009
### Con la generacion de la version 3 del sistema base de desarrollo Siscom, se
### decidio, integrar una biblioteca en el directorio de desarrollo actual, que 
### incluyera los controles Qt, esto para simplificar la migracion de controles
### al nuevo esquema de desarrollo, ya que la principal premisa, es evitar la dependencia
### de bibliotecas de las versiones anteriores de desarrollo

Controles_SiscomDesarrollo3Qt=Siscom3Nombres
Archivos_O_SiscomDesarrollo3QtControles=O/QtPluginSiscomControlesVersion3.o


all:DirectorioO $(Binarios) ServidorSiscom

DirectorioO:
	-mkdir O
des:
	echo $(Binarios)

$(QTDIR)/plugins/designer/libSiscomDesarrollo3QtControles.so:$(Archivos_O_SiscomDesarrollo3QtControles)
	@echo 'Generando $@'	
ServidorSiscom:

	cd Servidor;make

libSiscomDesarrollo3Qt++.so:$(Archivos_SiscomDesarrollo3)   \
			    $(Archivos_Qt_SiscomDesarrollo3)
	$(CXX) $(OpShared) -o $@ $(Archivos_SiscomDesarrollo3) $(BibliotecasSiscomDesarrollo3)
	
libSiscomDesarrollo2.so:$(Biblioteca2)
	$(GCC) $(OpShared) -o libSiscomDesarrollo2.so $(Biblioteca2)

libSiscomComunicaciones++.so:$(Biblioteca2CXX) $(Biblioteca2CXX_QT)
	$(CXX) $(OpShared) -o libSiscomComunicaciones++.so $(Biblioteca2CXX)  #-L . -lSiscomDesarrollo2
libSiscomDesarrolloPostgresql.so:$(ArchivosPostgresql)
	$(GCC) $(OpShared) -o $@ $(ArchivosPostgresql)  \
	-L $(DIRPOSTGRESQL)/lib -lpq 
O/%.o:C/%.c
	$(GCC) $(OpC) -o $@ $< $(Include) 

O/%.o:CPP/%.cpp
	$(CXX) $(OpCXX) -o $@ $< $(Include) 

CPP/MOC_%.cpp:H/%.h
	@echo MOC `basename $@`
	@$(MOC) -o $@ $<
clean:
	-rm $(Binarios)
	-rm O/*.o
	-cd Servidor;make clean
	

