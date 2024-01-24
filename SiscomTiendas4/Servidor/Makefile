

Archivos_SiscomTiendas4=					\
			O/ComunSiscomTiendas4.o			\
			O/SiscomTiendas4.o  			\
			O/ConsultasTiendas4.o			\
			O/Familias.o				\
			O/Productos.o				\
			O/Precios.o				\
			O/Personas.o				\
			O/Empresas.o				\
			O/MediosComunicacion.o			\
			O/FormaPago.o				\
			O/Compras.o				\
			O/Clientes.o				\
			O/Cotiza.o				\
			O/Ventas.o				\
			O/Reportes.o				\
			O/Ordenes.o				\
			O/Devoluciones.o			\
			O/Existencias.o				\
			O/Empleados.o				\
			O/Errores.o				\
			O/AsignaAsesor.o			\
			O/Pedidos.o				\
			O/Paquetes.o				\
			O/Impresion.o				\
			O/BusquedaProductos.o			\
			O/DatosProductosPorFamilia.o		\
			O/SQLFamilias.o				\
			O/SQLProductos.o			\
			O/SQLPrecios.o				\
			O/SQLEmpresas.o				\
			O/SQLMediosComunicacion.o		\
			O/SQLPersonas.o				\
			O/SQLFormaPago.o			\
			O/SQLCompras.o				\
			O/SQLClientes.o				\
			O/SQLCotiza.o				\
			O/SQLVentas.o				\
			O/SQLReportes.o				\
			O/SQLOrdenes.o				\
			O/SQLDevoluciones.o			\
			O/SQLExistencias.o			\
			O/SQLAsignaAsesor.o			\
			O/SQLPedidos.o				\
			O/SqlPaquetes.o				\
			O/SqlBusquedaProductos.o		\
			O/SqlDatosProductosPorFamilia.o

Archivos_O_MemoriaComun=


Archivos_O_DisparadorAsterisk=					\
			O/DisparadorAsterisk.o 			\
			O/PrinDisparadorAsterisk.o
Archivos_O_ImpresionSeid=O/ImpresionSeid.o			\
			 O/ImpresionFacturaSeid.o
Bibliotecas=-L$(DIRLIBSISCOM2)  		\
		-lSiscomDesarrollo2  		\
		-lSiscomSeguridad3Prot2   	\
		-lSiscomSepomex			\
		-lSiscomAplicacionesSvr 	\
		-lcups
BibliotecasImpresionSeid=				\
			-L$(DIRLIBSISCOM2)  		\
			-lSiscomDesarrollo2  		#\
			-lps 
BibliotecasDisparadorAsterisk=-L$(DIRLIBSISCOM2)	 	\
			      -lSiscomDesarrollo2		\
			      -lm

Include=-IH 							\
	-I $(DIRDesarrolloHGE)/SISCOMDesarrollo2/H 		\
	-I$(DIRDesarrolloHGE)/SISCOMDesarrollo2/Servidor/H 
OpC= -c  $(DEBUG) $(OpCSiscom)
OpShared= -shared $(DEBUG) $(OpCSiscom)
OpBinarios= $(DEBUG) $(OpCSiscom)

Binarios= 					\
	 libSiscomTiendas4.so   		\
	 libImpresionSeid.so			\
	 DisparadorAsterisk

	 	

all: $(Binarios) 

libImpresionSeid.so:$(Archivos_O_ImpresionSeid)
	@echo Generando $@
	@$(GCC) $(OpShared) -o $@ $(Archivos_O_ImpresionSeid) $(BibliotecasImpresionSeid)

DisparadorAsterisk:$(Archivos_O_DisparadorAsterisk)
	@echo Generando $@
	@$(GCC) $(OpBinarios) -o $@ $(Archivos_O_DisparadorAsterisk) $(BibliotecasDisparadorAsterisk)
libSiscomTiendas4.so:$(Archivos_SiscomTiendas4)
	@echo Generando $@
	@$(GCC) $(OpShared) -o $@ $(Archivos_SiscomTiendas4) $(Bibliotecas)
O/%.o:C/%.c
	@echo CC `basename $@`
	@$(GCC) $(OpC) -o $@ $< $(Include) 

clean:
	-rm $(Binarios)
	-rm O/*.o
	
	
