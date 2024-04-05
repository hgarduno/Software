

AAltaGenericaRN=O/RNAltaGenericaSeguridad3.o
AConsultaGenericaRN=O/RNConsultaGenericaSeguridad3.o
AAltaGenericaAD=O/ADComandosAlta.o
AConsultaGenericaAD=O/ADConsultas.o

AAltaGeneriaRNSinAD=O/RNAltaGenericaSeguridad3SinAD.o

ArchivosSiscomSeguridad3Prot2=O/RNSiscomSeguridad3Prot2.o 	\
			      ../Servidor2/O/SiscomSeguridad.o	\
			      ../Servidor2/O/SqlSeguridad.o


BibliotecasSvr=-L $(SISCOM_LIB_DIR) -lSISCOMDesarrollo.1.0 
BibliotecasSvrAD=-L $(SISCOM_LIB_DIR) -L$(DIRPOSTGRESQL)/lib -lSISCOMDesarrollo.1.0 -lControladorComandosSQL -lpq
BibliotecasProt2=-L$(DIRLIBSISCOM2) \
		  -lSiscomDesarrollo2

IncludeSvr=-I $(SISCOM_LIB_DIR)/Include -I RN/H -I $(DIRPOSTGRESQL)/include -I AD/H -I $(DIRLIBSISCOM2)/H -I $(DIRLIBSISCOM2)/Servidor/H -I ../Servidor2/H
OpCompilacionSvr=-c $(DEBUG) $(OpCSiscom)
OpModSvr=-shared $(DEBUG) $(OpCSiscom)


all:DirectoriosO					\
	SO/libRNAltaGenericaSeguridad3.so 		\
    SO/libRNConsultaGenericaSeguridad3.so 		\
    SO/libADAltaGenericaSeguridad3.so  			\
    SO/libADConsultaGenericaSeguridad3.so  		\
    SO/libRNAltaGenericaSeguridad3SinAD.so 		\
    $(DIRLIBSISCOM2)/libSiscomSeguridad3Prot2.so 	\
    Copia

DirectoriosO:../Servidor2/O
	
../Servidor2/O:
	@mkdir ../Servidor2/O
Copia:
	ln -sf $(DIRDesarrolloHGE)/SISCOMSeguridad3/Servidor/RN/H/RNSiscomSeguridad3Prot2.h $(DIRLIBSISCOM2)/H/RNSiscomSeguridad3Prot2.h
	
$(DIRLIBSISCOM2)/libSiscomSeguridad3Prot2.so:$(ArchivosSiscomSeguridad3Prot2)
	@echo Enlazando $@
	@$(GCC) $(OpModSvr) -o $@ $(ArchivosSiscomSeguridad3Prot2) $(BibliotecasProt2) 

SO/libRNAltaGenericaSeguridad3SinAD.so:$(AAltaGeneriaRNSinAD)
	@echo Enlazando $@
	@$(GCC) $(OpModSvr) -o $@ $(AAltaGeneriaRNSinAD) $(BibliotecasSvr) 
SO/libRNAltaGenericaSeguridad3.so:$(AAltaGenericaRN)
	@echo Enlazando $@
	@$(GCC) $(OpModSvr) -o $@ $(AAltaGenericaRN) $(BibliotecasSvr) 

SO/libRNConsultaGenericaSeguridad3.so:$(AConsultaGenericaRN)
	@echo Enlazando $@
	@$(GCC) $(OpModSvr) -o $@ $(AConsultaGenericaRN) $(BibliotecasSvr) 

SO/libADAltaGenericaSeguridad3.so:$(AAltaGenericaAD)
	@echo Enlazando $@
	@$(GCC) $(OpModSvr) -o $@ $(AAltaGenericaAD) $(BibliotecasSvrAD)

SO/libADConsultaGenericaSeguridad3.so:$(AConsultaGenericaAD)
	@echo Enlazando $@
	@$(GCC) $(OpModSvr) -o $@ $(AConsultaGenericaAD) $(BibliotecasSvrAD)

O/%.o:RN/C/%.c
	@echo Compilando $<
	@$(GCC) $(OpCompilacionSvr) $(IncludeSvr) -o $@ $<
O/%.o:AD/C/%.c
	@echo Compilando $<
	@$(GCC) $(OpCompilacionSvr) $(IncludeSvr) -o $@ $<

../Servidor2/O/%.o:../Servidor2/C/%.c
	@echo Compilando $<
	@$(GCC) $(OpCompilacionSvr) $(IncludeSvr) -o $@ $<
clean:
	@echo RM O
	@-rm O/*.o
	@echo RM SO
	@-rm SO/*.so
DirectoriosO:
	-mkdir O
	-mkdir SO
