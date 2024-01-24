

ArchivosServidorGeneral=O/ServidorGeneral.o

ArchivosBibliotecaAAplicacion=O/ActualizaAplicacion.o
ArchivosBibliotecaSistemaGeneral=O/SistemaGeneralLib.o

BibliotecasSistemaGeneral=-L$(DIRDesarrolloHGE)/SISCOMDesarrollo2 \
			    -lSiscomDesarrollo2  \
			    -ldl			\
			    -lm
Bibliotecas=-L$(DIRDesarrolloHGE)/SISCOMDesarrollo2  -lSiscomDesarrollo2
Include=-IH -I $(DIRDesarrolloHGE)/SISCOMDesarrollo2/H -I$(DIRDesarrolloHGE)/SiscomDesarrollo4/H
OpC=-g -c   $(DEBUG) $(OpCSiscom)
OpBinarios=-g -rdynamic $(DEBUG) $(OpCSiscom)

Binarios= \
	 ServidorGeneral 

all: $(Binarios) 

ServidorGeneral:$(ArchivosServidorGeneral)
	$(GCC) $(OpBinarios) -o ServidorGeneral $(ArchivosServidorGeneral) $(BibliotecasSistemaGeneral)
O/%.o:C/%.c
	$(GCC) $(OpC) -o $@ $< $(Include) 

clean:
	-rm $(Binarios)
	-rm O/*.o
	

