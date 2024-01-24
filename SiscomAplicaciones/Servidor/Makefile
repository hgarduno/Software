
OpC=-c $(DEBUG) $(OpCSiscom)
OpEnlace= -shared $(DEBUG) $(OpCSiscom) 
Include=-I $(DIRLIBSISCOM2)/H -I H -I $(DIRLIBSISCOM2)/Servidor/H
Bibliotecas=-L $(DIRLIBSISCOM2)/ -lSiscomDesarrollo2
Archivos_O_Servidor=			\
	O/SiscomPersonas.o		\
	O/SiscomFirmas.o		\
	O/SiscomDirecciones.o		\
	O/SiscomMediosComunicacion.o	\
	O/SiscomBusquedas.o		\
	O/SiscomPersonasSQL.o		\
	O/SiscomFirmasSQL.o		\
	O/SQLDirecciones.o		\
	O/SQLMediosComunicacion.o	


all: $(DIRLIBSISCOM2)/libSiscomAplicacionesSvr.so  Copia


$(DIRLIBSISCOM2)/libSiscomAplicacionesSvr.so:$(Archivos_O_Servidor)
	@echo Generando $@
	@$(CC) $(OpEnlace) $(Bibliotecas) -o$@ $(Archivos_O_Servidor)

O/%.o:C/%.c
	@echo Compilando $<
	@$(CC) $(OpC) $(Include) -o $@ $<

Copia:
	ln -sf $(DIRDesarrolloHGE)/SiscomAplicaciones/Servidor/H/Siscom*.h $(DIRLIBSISCOM2)/Servidor/H/
