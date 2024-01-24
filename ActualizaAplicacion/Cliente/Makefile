include ../../SISCOMComunYUtilerias/MakefileQTSiscomDesarrollo3.mk

OpCompilacion=-g -c  -pipe -Wall -W -O2 -D_REENTRANT  -DQT_NO_DEBUG -DQT_THREAD_SUPPORT -DQT_SHARED $(DEBUG) $(OpCSiscom)
OpModulos=-shared -g $(DEBUG) $(OpCSiscom)
Include=-I $(QTDIR)/include -I. -I H -I $(DIRDesarrolloHGE)/SISCOMDesarrollo2/H 

Aplicacion=O/AplicacionVersion3.o 
BibliotecasAplicacion=-L $(DIRDesarrolloHGE)/SISCOMDesarrollo2 \
		      -L $(QTDIR)/lib  \
		      -LSO  \
		      -lSiscomDesarrollo2  \
		      -lCliente  \
		      -lqt-mt

BibliotecaSiscomDesarrollo=-L$(DIRDesarrolloHGE)/SISCOMDesarrollo2 \
			    -lSiscomDesarrollo2  \
			    -lSiscomComunicaciones++

Bibliotecas_Cliente=-LSO -lClienteAAplicacion -lCapturaInformacion -lCapEstacion -lNotTransmision


ArchivosBibliotecaAAplicacion=O/CreaDirectorio.o  \
			      O/TransfiereArchivos.o  \
			      O/Estaciones.o \
			      O/TransfiereAEstaciones.o

$(eval $(call ArchivosBibliotecaQTForma,Cliente))
$(eval $(call ArchivosBibliotecaQTForma,CapturaInformacion))
$(eval $(call ArchivosBibliotecaQTForma,CapEstacion))
$(eval $(call ArchivosBibliotecaQTForma,NotTransmision))

Binarios=SO/libClienteAAplicacion.so \
	 SO/libNotTransmision.so \
	 SO/libCapturaInformacion.so \
	 SO/libCapEstacion.so \
	 SO/libCliente.so  \
	 Aplicacion

all: $(Binarios)

SO/libClienteAAplicacion.so:$(ArchivosBibliotecaAAplicacion)
	@echo Generando $@
	@$(CXX) $(OpModulos) -o $@  $(ArchivosBibliotecaAAplicacion) \
				    $(BibliotecaSiscomDesarrollo)
Aplicacion:SO/libCliente.so O/AplicacionVersion3.o 
	@echo Generando Aplicacion
	@$(CXX) -o Aplicacion O/AplicacionVersion3.o $(BibliotecasAplicacion)

$(eval $(call EnlaceBibliotecaQTForma,Cliente))
$(eval $(call EnlaceBibliotecaQTForma,CapturaInformacion))
$(eval $(call EnlaceBibliotecaQTForma,CapEstacion))
$(eval $(call EnlaceBibliotecaQTForma,NotTransmision))


clean:
	-rm $(Binarios)
	-rm O/*.o
