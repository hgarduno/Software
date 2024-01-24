
Archivos_O_IconosSiscomElectronica=O/IconosSiscomElectronica.o
Include=-I H
OpCompilacion=$(DEBUG) $(OpCSiscom) -c
OpEnlace+=$(OpCSiscom) -shared
all:DirectoriosO libIconosSiscomElectronica.so 


DirectoriosO:O

O:
	@mkdir O

libIconosSiscomElectronica.so:$(Archivos_O_IconosSiscomElectronica)
	@echo Generando $@
	@$(GCC) $(OpEnlace) -o$@ $(Archivos_O_IconosSiscomElectronica)
O/%.o:C/%.c
	@echo 'Compilando $<'
	@$(GCC) $(OpCompilacion) $(Include) -o $@ $<
