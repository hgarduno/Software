##### Archivo Make para compilador todos los proyectos
##### Siscom comenzando con las bibliotecas y proyectos
##### Comunes.
##### Se toma esta determinacion, ya que al dia de hoy es
##### muy tardado compilar todas las aplicaciones sobre
##### todo cuando se raliza una modificacion en la bibliotecas
##### de desarrollo.

# Para lograr que el todos los proyectos se compilen desde
# un solo Makefile, se realizaron los siguientes cambios.
#
# Los siguientes archivos cabecera se movieron del directorio
# de sus proyectos al H, de SISCOMDesarrollo2, esto, se debera
#
#-rw-r--r-- 1 hgarduno hgarduno  3497 May 23 11:24 Seguridad3Protocolo2.h
#-rw-r--r-- 1 hgarduno hgarduno   550 May 23 11:26 SisPersonas.h
#-rw-r--r-- 1 hgarduno hgarduno   517 May 23 11:26 SisMedioComunicacion.h
#-rw-r--r-- 1 hgarduno hgarduno   859 May 23 11:26 SisDirecciones.h
#-rw-r--r-- 1 hgarduno hgarduno   511 May 23 11:26 SisDatPersonales.h
# SISCOMControles2/H/QSisOperacionesPersonas.h
#
#En el futuro se buscara integrar en una sola biblioteca toda la
#funcionalidad de los proyectos comunes, esto nos permitira tener
#una mejor administracion, del codigo fuente, y en el proceso de 
#instalacion, se simplificara, los primeros proyectos que se deberan
#integrar son el SISCOMSeguridad3, SiscomClasesGenerales etc.
#De estos proyectos se deberan integrar, en la biblioteca 
#libSiscomComunicaciones++.so la funcionalidad de la Biblioteca
# libSiscomSeguridad3Prot2++.so y asi para todos los proyectos
# que sean comunes, la biblioteca que expondra la funcionalidad
# a las demas aplicaciones se debera agregar a 
# libSiscomComunicaciones++.so, en el caso de que sean bibliotecas
# de C++
#
# Los archivos cabecera anteriormente comentados se deberan eliminar
# de sus directorios actuales una vez que se realicen las pruebas
# de compilacion
#


all: SiscomDesarrollo4.HGarduno		\
     SiscomDesarrollo1			\
     SiscomDesarrollo2			\
     ActualizaAplicacion1		\
     SiscomSeguridad3			\
     SiscomSepomex1			\
     SISCOMControles1			\
     SiscomControles2			\
     SiscomAplicaciones1		\
     SISCOMElectronica1			\
     SiscomTiendas41			\
     SiscomClinicas31			\
     ActualizaAplicacion1		\
     SISCOMCompetenciaTrampolin1	\
     ElFresno1
SiscomDesarrollo4.HGarduno:
	make -f MakefileDesarrollo4
SISCOMControles1:
	cd SISCOMControles; make
ActualizaAplicacion1:
	cd ActualizaAplicacion ; make
SISCOMCompetenciaTrampolin1:
	cd SISCOMCompetenciaTrampolin ;make
ElFresno1:
	#export LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):$(SISCOM_LIB_DIR):;cd ElFresno;make
	cd ElFresno;make
ActualizaAplicacion1:
	cd ActualizaAplicacion; make
SiscomTiendas41:
	cd SiscomTiendas4;make 


SiscomDesarrollo1:
	cd SISCOMDesarrollo; make 

SiscomDesarrollo2:
	cd SISCOMDesarrollo2;make
SiscomSepomex1:
	cd Sepomex;make 
SiscomControles2:
	cd SISCOMControles2;make
SiscomClasesGenerales1:
	cd SISCOMClasesGenerales;make
SiscomSeguridad3:
	cd SISCOMSeguridad3;make

SiscomAplicaciones1:
	cd SiscomAplicaciones; make
SISCOMElectronica1:
	cd $(DirectorioSiscomElectronica) ; make

clean:
	@-cd SISCOMDesarrollo; make clean
	@-cd SISCOMDesarrollo2; make clean
	@-cd Sepomex; make clean
	@-cd SISCOMControles2; make clean
	#@-cd SISCOMClasesGenerales; make clean
	@-cd SISCOMSeguridad3; make clean
	@-cd SiscomAplicaciones; make clean
	@-cd SiscomElectronica; make clean
	@-cd SiscomClinicas3;make clean
	@-cd SiscomTiendas4;make clean
	@-cd ElFresno;make clean
	@-cd ActualizaAplicacion;make clean
	@-cd SISCOMControles;make clean
	@-find . -type l  -exec rm {} \;
	@-rm $(DIRLIBSISCOM2)/*.so    
	@make -f MakefileDesarrollo4 clean
