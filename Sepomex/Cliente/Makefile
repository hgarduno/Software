include ../../SISCOMComunYUtilerias/MakefileQTSiscomDesarrollo3.mk

OpModulos=-shared $(OpCSiscom)
OpCompilacion=-c  $(OpCSiscom)
Bibliotecas=-L $(DIRLIBSISCOM2) 	\
	    -L $(QTDIR)/lib 		\
	    -lSiscomComunicaciones++  	\
	    -lSiscomDesarrollo2		\
	    -lqt-mt

BibliotecasPrueba=-LSO/ -lSepomexCliente
Include= -I $(DIRLIBSISCOM2)/H -I H -I . -I $(QTDIR)/include -I $$QtInclude


#Archivos_O_Lib_SepomexCliente=O/SepomexEstados.o  \
#			      O/SepomexMunicipios.o \
#			      O/SepomexTAsentamientos.o  \
#			      O/SepomexAsentamientos.o

Archivos_O_Lib_SepomexCliente=O/CQSisSepomex.o 

Archivos_O_PruebasSepomex=O/PruebasSepomex.o

Binarios=SO/libSepomexCliente.so #\
	 PruebaSepomex

all:DirectorioO $(Binarios) Copia


Copia:SO/libSepomexCliente.so
	cp SO/libSepomexCliente.so $(DIRLIBSISCOM2)/
	#cp H/*.h $(DIRLIBSISCOM2)/H
	@-ln -fs $(DIRDesarrolloHGE)/Sepomex/Cliente/H/*.h $(DIRLIBSISCOM2)/H
	
SO/libSepomexCliente.so:$(Archivos_O_Lib_SepomexCliente)
	@echo LD $@
	@$(CXX) -o $@ $(OpModulos) $(Archivos_O_Lib_SepomexCliente) $(Bibliotecas)

PruebaSepomex:$(Archivos_O_PruebasSepomex)
	@echo LD $@
	@$(CXX) $(OpCSiscom) -o $@  $(Archivos_O_PruebasSepomex) $(Bibliotecas) $(BibliotecasPrueba)

clean:
	@-rm SO/*.so
	@-rm O/*.o
DirectorioO:
	-mkdir O
	-mkdir SO
