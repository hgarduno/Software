

ArchivosBibliotecaSistemaGeneral=O/ActualizaEstacion.o

BibliotecasProcesa=-L. -L$(DIRDesarrolloHGE)/SISCOMDesarrollo2 -lSiscomDesarrollo2 -lActualizaAplicacion
BibliotecasSistemaGeneral=-L. -L$(DIRDesarrolloHGE)/SISCOMDesarrollo2  -lSiscomDesarrollo2  -ldl
Bibliotecas=-L$(DIRDesarrolloHGE)/SISCOMDesarrollo2  -lSiscomDesarrollo2

Include=-IH -I $(DIRDesarrolloHGE)/SISCOMDesarrollo2/H -I$(DIRDesarrolloHGE)/SISCOMDesarrollo2/Servidor/H 
OpC=-g -c  $(OpCSiscom) $(DEBUG)
OpShared=-g -shared $(OpCSiscom) $(DEBUG)
OpBinarios=-g  $(OpCSiscom) $(DEBUG)

Binarios= \
	 libActualizaEstacion.so   \
	 	

all: $(Binarios) 

libActualizaEstacion.so:$(ArchivosBibliotecaSistemaGeneral)
	@echo Generando $@
	@$(GCC) $(OpShared) -o $@ $(ArchivosBibliotecaSistemaGeneral) $(Biblioteca2)


O/%.o:C/%.c
	@echo Compilando $<
	@$(GCC) $(OpC) -o $@ $< $(Include) 

clean:
	-rm $(Binarios)
	-rm O/*.o
	

