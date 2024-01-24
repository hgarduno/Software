

Archivos_SiscomSepomex=O/Sepomex.o 	\
		       O/SqlSepomex.o
		

Bibliotecas=-L$(DIRLIBSISCOM2)  \
		-lSiscomDesarrollo2  \
		-lSiscomSeguridad3Prot2
Include=-IH \
	-I $(DIRDesarrolloHGE)/SISCOMDesarrollo2/H \
	-I$(DIRDesarrolloHGE)/SISCOMDesarrollo2/Servidor/H
OpC=-g -c  $(DEBUG) $(OpCSiscom)
OpShared=-g -shared $(DEBUG) $(OpCSiscom)
OpBinarios=-g  $(DEBUG) $(OpCSiscom)

Binarios= \
	 libSiscomSepomex.so    
	 	

all: $(Binarios)  Copia


Copia:
	ln -fs $(DIRDesarrolloHGE)/Sepomex/Servidor/libSiscomSepomex.so $(DIRLIBSISCOM2)/
	ln -fs $(DIRDesarrolloHGE)/Sepomex/Servidor/H/*.h $(DIRLIBSISCOM2)/Servidor/H
libSiscomSepomex.so:$(Archivos_SiscomSepomex)
	@echo Generando $@
	@$(GCC) $(OpShared) -o $@ $(Archivos_SiscomSepomex) $(Bibliotecas)

O/%.o:C/%.c
	@echo Compilando $<
	@$(GCC) $(OpC) -o $@ $< $(Include) 

clean:
	-rm $(Binarios)
	-rm O/*.o
	
	
