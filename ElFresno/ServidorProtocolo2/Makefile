

Archivos_ElFresnoProtocolo2=O/ElFresnoProtocolo2.o 	\
			    O/RNCorteExistencias.o 	\
			    O/ConsultasElFresno.o	\
			    O/ComunElFresno.o		\
			    O/Errores.o			\
			    O/Empleados.o		\
			    O/SQLEmpleados.o

Bibliotecas_ElFresnoProtocolo2=				\
	-L. 						\
	-L$(DIRDesarrolloHGE)/SISCOMDesarrollo2  	\
	-lSiscomDesarrollo2  				\
	-lSiscomSeguridad3Prot2				\
	-ldl
Bibliotecas=-L$(DIRDesarrolloHGE)/SISCOMDesarrollo2  -lSiscomDesarrollo2
Include=-IH -I $(DIRDesarrolloHGE)/SISCOMDesarrollo2/H -I$(DIRDesarrolloHGE)/SISCOMDesarrollo2/Servidor/H
OpC=-g -c  $(DEBUG) $(OpCSiscom)
OpShared=-g -shared $(DEBUG) $(OpCSiscom)
OpBinarios=-g  $(DEBUG) $(OpCSiscom)

Binarios= \
	 libElFresnoProtocolo2.so   
	 	

all: $(Binarios) 

libElFresnoProtocolo2.so:$(Archivos_ElFresnoProtocolo2)
	@echo Generando $@
	@$(GCC) $(OpShared) -o $@ 		\
	$(Archivos_ElFresnoProtocolo2)		\
	$(Bibliotecas)				\
	$(Bibliotecas_ElFresnoProtocolo2)


O/%.o:C/%.c
	@echo Compilando $<
	@$(GCC) $(OpC) -o $@ $< $(Include) 

clean:
	-rm $(Binarios)
	-rm O/*.o
	

