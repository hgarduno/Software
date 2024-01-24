

Archivos_SiscomClinicas3=					\
			O/SiscomClinicas3.o 			\
			O/ConsultasClinicas3.o			\
			O/Errores.o				\
			O/Empleados.o				\
			O/Servicios.o				\
			O/TipoPrecio.o				\
			O/ComunClinicas3.o			\
			O/Pacientes.o				\
			O/Consultas.o				\
			O/Cotizando.o				\
			O/Precios.o				\
			O/SQLEmpleados.o			\
			O/SQLServicios.o			\
			O/SQLTipoPrecio.o			\
			O/SQLComunClinicas3.o			\
			O/SQLConsultas.o			\
			O/SQLEvolucionConsulta.o		\
			O/SQLExpedientes.o			\
			O/SQLCotizando.o			\
			O/SQLPrecios.o

Archivos_O_MemoriaComun=

Bibliotecas=-L$(DIRLIBSISCOM2)  		\
	    -L$(DIRDesarrolloHGE)/SiscomTiendas4/Servidor	\
		-lSiscomDesarrollo2  		\
		-lSiscomSeguridad3Prot2   	\
		-lSiscomSepomex			\
		-lSiscomTiendas4

Include=-IH 							\
	-I $(DIRDesarrolloHGE)/SISCOMDesarrollo2/H 		\
	-I$(DIRDesarrolloHGE)/SISCOMDesarrollo2/Servidor/H 	\
	-I$(DIRDesarrolloHGE)/SiscomTiendas4/Servidor/H
OpC= -c  $(DEBUG) $(OpCSiscom)
OpShared= -shared $(DEBUG) $(OpCSiscom)
OpBinarios= $(DEBUG) $(OpCSiscom)

Binarios= 					\
	 libSiscomClinicas3.so   		

	 	

all: $(Binarios) 

libSiscomClinicas3.so:$(Archivos_SiscomClinicas3)
	@echo Generando $@
	@$(GCC) $(OpShared) -o $@ $(Archivos_SiscomClinicas3) $(Bibliotecas)
O/%.o:C/%.c
	@echo CC `basename $@`
	@$(GCC) $(OpC) -o $@ $< $(Include) 

clean:
	-rm $(Binarios)
	-rm O/*.o
	
	
