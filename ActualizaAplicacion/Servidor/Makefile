

ArchivosBibliotecaSistemaGeneral=O/SistemaGeneralLib.o
ArchivosBibliotecaAccesoDatos=O/SistemaAccesoDatos.o

BibliotecasProcesa=-L. -L$(DIRDesarrolloHGE)/SISCOMDesarrollo2 -lSiscomDesarrollo2 -lActualizaAplicacion
BibliotecasSistemaGeneral=-L. -L$(DIRDesarrolloHGE)/SISCOMDesarrollo2  -lSiscomDesarrollo2  -ldl
Bibliotecas=-L$(DIRDesarrolloHGE)/SISCOMDesarrollo2  -lSiscomDesarrollo2
BibliotecasAccesoDatos=-L$(DIRDesarrolloHGE)/SISCOMDesarrollo2 \
			 -lSiscomDesarrolloPostgresql
Include=-IH -I $(DIRDesarrolloHGE)/SISCOMDesarrollo2/H -I$(DIRDesarrolloHGE)/SISCOMDesarrollo2/Servidor/H
OpC=-g -c  $(DEBUG) $(OpCSiscom)
OpShared=-g -shared $(DEBUG) $(OpCSiscom)
OpBinarios=-g  $(DEBUG) $(OpCSiscom)

Binarios= \
	 libSistemaGeneral.so   \
	 libAccesoDatos.so 
	 	

all: $(Binarios) 

libAccesoDatos.so:$(ArchivosBibliotecaAccesoDatos)
	@echo Generando $@
	@$(GCC) $(OpShared) -o libAccesoDatos.so $(ArchivosBibliotecaAccesoDatos)  \
				$(BibliotecasAccesoDatos)
libSistemaGeneral.so:$(ArchivosBibliotecaSistemaGeneral)
	@echo Generando $@
	@$(GCC) $(OpShared) -o libSistemaGeneral.so $(ArchivosBibliotecaSistemaGeneral) $(Biblioteca2)


O/%.o:C/%.c
	@echo Compilando $<
	@$(GCC) $(OpC) -o $@ $< $(Include) 

clean:
	-rm $(Binarios)
	-rm O/*.o
	

