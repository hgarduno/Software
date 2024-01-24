

AAltaGenericaRN=O/RNAltaGenericaSeguridad3.o
AConsultaGenericaRN=O/RNConsultaGenericaSeguridad3.o
AAltaGenericaAD=O/ADComandosAlta.o
AConsultaGenericaAD=O/ADConsultas.o

AAltaGeneriaRNSinAD=O/RNAltaGenericaSeguridad3SinAD.o


BibliotecasSvr=-L $(SISCOM_LIB_DIR) -lSISCOMDesarrollo.1.0 
BibliotecasSvrAD=-L $(SISCOM_LIB_DIR) -L$(DIRPOSTGRESQL)/lib -lSISCOMDesarrollo.1.0 -lControladorComandosSQL -lpq
IncludeSvr=-I $(SISCOM_LIB_DIR)/Include -I RN/H -I $(DIRPOSTGRESQL)/include -I AD/H
OpCompilacionSvr=-c $(DEBUG) $(OpCSiscom)
OpModSvr=-shared $(DEBUG) $(OpCSiscom)

Archivos_O_SistemaElFresno=O/RNSistemaElFresno.o  \
			   O/RNPersonas.o \
			   O/RNFamilias.o \
			   O/RNUnidades.o \
			   O/RNProductos.o \
			   O/RNVarios.o \
			   O/RNTiposPrecios.o \
			   O/RNPrecios.o \
			   O/RNCotizaciones.o \
			   O/RNVentas.o \
			   O/RNPedidos.o \
			   O/RNVehiculos.o \
			   O/RNComunFresno.o \
			   O/RNChoferes.o \
			   O/RNEmpresas.o  \
			   O/RNCompras.o  \
			   O/RNVentasExpendio.o \
			   O/RNFacturacion.o \
			   O/RNPersonas2.o

all:\
    SO/libRNSistemaElFresno.so  \
    SO/libADAltaGenericaElFresno.so  \
    SO/libADConsultaGenericaElFresno.so  

SO/libRNSistemaElFresno.so:$(Archivos_O_SistemaElFresno)
	@echo Enlazando $@
	@$(GCC) $(OpModSvr) -o $@ $(Archivos_O_SistemaElFresno) $(BibliotecasSvr)

SO/libADAltaGenericaElFresno.so:$(AAltaGenericaAD)
	@echo Enlazando $@
	@$(GCC) $(OpModSvr) -o $@ $(AAltaGenericaAD) $(BibliotecasSvrAD)

SO/libADConsultaGenericaElFresno.so:$(AConsultaGenericaAD)
	@echo Enlazando $@
	@$(GCC) $(OpModSvr) -o $@ $(AConsultaGenericaAD) $(BibliotecasSvrAD)


O/%.o:RN/C/%.c
	@echo Compilando $<
	@$(GCC) $(OpCompilacionSvr) $(IncludeSvr) -o $@ $<
O/%.o:AD/C/%.c
	@echo Compilando $<
	@$(GCC) $(OpCompilacionSvr) $(IncludeSvr) -o $@ $<

clean:
	@echo RM O
	@-rm O/*.o
	@echo RM SO
	@-rm SO/*.so
