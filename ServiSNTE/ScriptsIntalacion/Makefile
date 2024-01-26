Archivos_O_CreaEnlaces=.O/CreaEnlaces.o


SistemaOperativo=$(shell uname -m)
ifeq ($(SistemaOperativo),i686)
NombreBinario=CreaEnlaces.32.Bits
endif

ifeq ($(SistemaOperativo),x86)
NombreBinario=CreaEnlaces.32.Bits
endif
ifeq ($(SistemaOperativo),x86_64)
NombreBinario=CreaEnlaces
endif


all:$(NombreBinario)


$(NombreBinario):$(Archivos_O_CreaEnlaces)

$(NombreBinario):$(Archivos_O_CreaEnlaces)
	gcc -o $(NombreBinario)  $(Archivos_O_CreaEnlaces)	

.O/%.o:%.c
	gcc -o $@ $< -c
clean:
	-rm .O/*
	-rm $(NombreBinario)




