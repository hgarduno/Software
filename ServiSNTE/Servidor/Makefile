Archivos_O_SiscomServiSNTE=O/SiscomServiSNTE.o			\
			   O/ComunSiscomServiSNTE.o		\
			   O/CargaNominaEmpleados.o		\
			   O/CargaBaseDeDatosMaestros.o		\
			   O/Catalogos.o			\
			   O/Calculos.o				\
			   O/Personas.o				\
			   O/Direcciones.o			\
			   O/Camiones.o				\
			   O/Departamentos.o			\
			   O/Productos.o			\
			   O/Cotizando.o			\
			   O/Ventas.o				\
			   O/Compras.o				\
			   O/Precios.o				\
			   O/Inventario.o			\
			   O/Clientes.o				\
			   O/Transferencias.o			\
			   O/Reportes.o				\
			   O/Apartados.o			\
			   O/Creditos.o				\
			   O/FijaFechaCompra.o			\
			   O/ActualizacionSistema.o		\
			   O/SiscomAdministracionSeguridad.o 	\
			   O/ContratosBeneficios.o		\
			   O/MediosComunicacion.o		\
			   O/DatosGenerales.o			\
			   O/Empleo.o				\
			   O/CargoPublico.o			\
			   O/GeneralesContratoBeneficios.o	\
			   O/ReferenciasPersonales.o		\
			   O/PosicionesImpresion.o		\
			   O/CentroTrabajo.o			\
			   O/Folio.o				\
			   O/CancelacionFolios.o		\
			   O/AdministracionServiSNTE.o		\
			   O/SaldosMovimientos.o		\
			   O/SqlCatalogos.o			\
			   O/SqlPersonas.o			\
			   O/SqlDirecciones.o			\
			   O/SqlCamiones.o			\
			   O/SqlDepartamentos.o			\
			   O/SqlProductos.o			\
			   O/SqlVentas.o			\
			   O/SqlCompras.o			\
			   O/SqlPrecios.o			\
			   O/SqlInventario.o			\
			   O/SqlClientes.o      		\
			   O/SqlTransferencias.o      		\
			   O/SqlReportes.o			\
			   O/SqlApartados.o			\
			   O/SqlCreditos.o			\
			   O/SqlFechaCompra.o			\
			   O/SqlTiendas.o			\
			   O/SqlActualizacionSistema.o		\
			   O/SqlSiscomAdministracionSeguridad.o \
			   O/SqlContratosBeneficios.o		\
			   O/SqlMediosComunicacion.o		\
			   O/SqlDatosGenerales.o		\
			   O/SqlEmpleo.o			\
			   O/SqlCargoPublico.o			\
			   O/SqlGeneralesContratoBeneficios.o	\
			   O/SqlReferenciasPersonales.o		\
			   O/SqlCentroTrabajo.o			\
			   O/SqlPosicionesImpresion.o		\
			   O/SqlFolio.o				\
			   O/SqlCancelacionFolios.o		\
			   O/SqlAdministracionServiSNTE.o	\
			   O/SqlSaldosMovimientos.o


Archivos_O_SiscomServiSNTEMemoria=O/SiscomServiSNTEMemoria.o	\
				  O/ComunSiscomServiSNTE.o	\
				  O/SqlServidores.o



Include=-I H  -I $(DIRDesarrolloHGE)/SiscomDesarrollo4/H
OpcionesC= -c $(DEBUG) -fPIC  
ifeq ($(SistemaOperativo),Linux)
OpcionesShared=-shared $(DEBUG) -fPIC 
else
OpcionesShared=-shared $(DEBUG) -fPIC -flat_namespace -undefined suppress
endif
Bibliotecas=-L$(DIRDesarrolloHGE)/SiscomDesarrollo4 -lSiscomOperaciones  -lSiscomDesarrollo4

all:DirectorioO libSiscomServiSNTE.so libSiscomServiSNTEMemoria.so 


libSiscomServiSNTE.so:$(Archivos_O_SiscomServiSNTE)
	@echo 'LD $@'
	@gcc $(OpcionesShared) -o $@ $(Archivos_O_SiscomServiSNTE) $(Bibliotecas)


libSiscomServiSNTEMemoria.so:$(Archivos_O_SiscomServiSNTEMemoria)
	@echo 'LD $@'
	@gcc $(OpcionesShared) -o $@ $(Archivos_O_SiscomServiSNTEMemoria) $(Bibliotecas)

O/%.o:C/%.c
	@echo CC $<
	@gcc $(OpcionesC) $(Include) -o $@ $<

clean:	
	-rm *.so
	-rm O/*
DirectorioO:
	-mkdir O
