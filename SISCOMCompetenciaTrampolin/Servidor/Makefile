

Archivos_SiscomTrampolin=					\
			O/SiscomTrampolin.o  			\
			O/Gimnasios.o				\
			O/RegistraPersona.o			\
			O/RegistraDireccion.o			\
			O/RegistraMedioComunicacion.o		\
			O/RegistraGimnasio.o			\
			O/RegistraJuez.o			\
			O/RegistraCompetidor.o			\
			O/RegistraCompetencia.o			\
			O/RegistraGimnasta.o			\
			O/RegistraCalificacion.o		\
			O/RegistraRondas.o			\
			O/ActualizaCalificaciones.o		\
			O/ActualizaGimnasta.o			\
			O/ConsultasGimnasio.o			\
			O/Entrenadores.o			\
			O/Gimnastas.o				\
			O/Competencias.o			\
			O/ConsultaPersonas.o			\
			O/Compitiendo.o				\
			O/Jueces.o				\
			O/Calificaciones.o			\
			O/ClasificaGimnastas.o			\
			O/ResultadosCompetencia.o		\
			O/Grupos.o				\
			O/GimnastasCompetencia01.o		\
			O/Rondas.o				\
			O/Rotaciones.o				\
			O/SqlRotaciones.o

Archivos_O_MemoriaComun=

Bibliotecas=-L$(DIRLIBSISCOM2)  \
		-lSiscomDesarrollo2  \
		-lSiscomSeguridad3Prot2   \
		-lSiscomSepomex

Include=-IH \
	-I $(DIRDesarrolloHGE)/SISCOMDesarrollo2/H \
	-I$(DIRDesarrolloHGE)/SISCOMDesarrollo2/Servidor/H 
OpC= -c  $(DEBUG) $(OpCSiscom)
OpShared= -shared $(DEBUG) $(OpCSiscom)
OpBinarios= $(DEBUG) $(OpCSiscom)

Binarios= 					\
	 libSiscomTrampolin.so   		

	 	

all: $(Binarios) 

libSiscomTrampolin.so:$(Archivos_SiscomTrampolin)
	@echo Generando $@
	@$(GCC) $(OpShared) -o $@ $(Archivos_SiscomTrampolin) $(Bibliotecas)

O/%.o:C/%.c
	@echo CC `basename $@`
	@$(GCC) $(OpC) -o $@ $< $(Include) 

clean:
	-rm $(Binarios)
	-rm O/*.o
	
	
