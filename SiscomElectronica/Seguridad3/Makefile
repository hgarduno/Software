
CFLAGS=-c $(DEBUG) 
CXXFLAGS=-c $(DEBUG)



Include=-IH -I $(DirDesarrollo4)/SiscomDesarrollo4/H 
IncludeCxx=-IH  -I $(DIRLIBSISCOM2)/H/ -I $(QTDIR)/include \
	   -I $(DirDesarrollo4)/SiscomComunicaciones++/H

Libs=-L $(DirDesarrollo4)/SiscomDesarrollo4 		\
	-lSiscomDesarrollo4			

LibsCxx=-L $(QTDIR)/lib 						\
	-L $(DIRLIBSISCOM2)  						\
	-L $(DirDesarrollo4)/SiscomComunicaciones++			\
	-L $(DirDesarrollo4)/SiscomDesarrollo4++			\
	-lSiscomDesarrollo3Qt++ -lqt-mt 				\
	-l:libSiscomComunicaciones++.so.1.0.0				\
	-lSiscomDesarrollo4++



Archivos_O_Seguridad3=O/Seguridad3.o  			\
			O/OperacionesSeguridad.o 	\
			O/ComunesSeguridad3.o 		\
			O/ActualizaPerfil.o
Archivos_O_GeneraMenus=O/GeneraMenus.o O/zMenus.o O/ComunMenus.o O/zQAction.o O/zOperacionQAction.o

all:Seguridad3 GeneraMenus


Seguridad3:$(Archivos_O_Seguridad3)
	@echo GCC -o  $@
	@gcc $(DEBUG) -o $@ $(Archivos_O_Seguridad3) $(Libs)

GeneraMenus:$(Archivos_O_GeneraMenus)
	@echo GCC -o $@
	@g++ -o$@ $(Archivos_O_GeneraMenus) $(LibsCxx) 

O/%.o:C/%.c
	@echo GCC -o $@
	@gcc $(CFLAGS) -o $@ $< $(Include)

O/%.o:Cxx/%.cpp
	@echo GCC -o $@
	@g++ $(CXXFLAGS) -o $@ $< $(IncludeCxx) 

clean:
	-rm $(Archivos_O_Seguridad3)
	-rm $(Archivos_O_GeneraMenus)
	-rm Seguridad3
	-rm GeneraMenus
