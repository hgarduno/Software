include $(DIRDesarrolloHGE)/SISCOMComunYUtilerias/MakefileQTSiscomDesarrollo3.mk
Archivos_O_ElFresno=						\
		    O/MOC_CfrmFirmaUsuario2.o 			\
		    O/CfrmFirmaUsuario2.o			\
		    O/UIC_CPP_frmFirmaUsuario2.o		\
		    O/MOC_UIC_H_frmFirmaUsuario2.o 		\
		    O/SISCOMVentanaPrincipal.o 			\
		    O/AplicacionVersion3.o 			\
		    O/MOC_SISCOMVentanaPrincipal.o	
Archivos_QT_ElFresno=						\
		     H/frmFirmaUsuario2.h			\
		     CPP/MOC_UIC_H_frmFirmaUsuario2.cpp		\
		     CPP/MOC_CfrmFirmaUsuario2.cpp 		\
		     CPP/MOC_SISCOMVentanaPrincipal.cpp 	\
		     CPP/UIC_CPP_frmFirmaUsuario2.cpp
		     

OpCompilacion=-g -c  $(DEBUG) $(OpCSiscom)
Include=-I $(QTDIR)/include  -I. -I H -I $(SISCOM_LIB_DIR)/Include -I $(DIRLIBSISCOM2)/H 
Bibliotecas=-L $(SISCOM_LIB_DIR) 				\
	      -L . 						\
	      -L $(QTDIR)/lib  					\
	       -L $(DIRLIBSISCOM2) 				\
	       -L Cliente/SO					\
	      -lqui 						\
	     -lSISCOMSeguridad3Q++  				\
	     -lSISCOMDesarrollo++   				\
	     -lSiscomDesarrollo2 				\
	     -lSiscomComunicaciones++
OpModulos=-shared  $(DEBUG) $(OpCSiscom)


Archivos_O_BibliotecaComunElFresno=O/Personas.o \
				   O/Direcciones.o \
				   O/Telefonos.o \
				   O/Apodos.o \
				   O/Correos.o \
				   O/Firmas.o \
				   O/TiposPersona.o \
				   O/Unidades.o \
				   O/Familias.o \
				   O/Productos.o \
				   O/MOC_Familias.o \
				   O/MOC_Unidades.o \
				   O/MOC_Productos.o \
				   O/MOC_TiposPrecios.o \
				   O/MOC_Vehiculos.o \
				   O/MOC_Empresas.o \
				   O/MOC_Choferes.o \
				   O/Precios.o  \
				   O/TiposPrecios.o \
				   O/Cotizaciones.o \
				   O/Ventas.o \
				   O/Empresas.o \
				   O/Pedidos.o \
				   O/Vehiculos.o \
				   O/Choferes.o   \
				   O/Compras.o \
				   O/VentasExpendio.o \
				   O/Facturacion.o \
				   O/OrdenesVentas.o \
				   O/Personas2.o \
				   O/EmpresasProt2.o \
				   O/DireccionesProt2.o \
				   O/Contactos.o \
				   O/MediosComunicacion.o \
				   O/VehiculosProt2.o \
				   O/FamiliasProt2.o \
				   O/UnidadesProt2.o \
				   O/ProductosProt2.o \
				   O/PersonasProt2.o \
				   O/CorteExistencia.o \
				   O/ReporteFechaCorte.o \


				   
Archivos_QT_BibliotecaVentas=CPP/IMP_MOC_Ventas.cpp
Archivos_O_BibliotecaVentas=O/IMP_MOC_Ventas.o  \
			     O/IMP_Ventas.o 
Archivos_QT_BibliotecaRegistraExpendios=CPP/IMP_MOC_RegistraExpendios.cpp
Archivos_O_BibliotecaRegistraExpendios=O/IMP_MOC_RegistraExpendios.o \
				       O/IMP_RegistraExpendios.o
Archivos_QT_BibliotecaPedidos=CPP/IMP_MOC_Pedidos.cpp
Archivos_O_BibliotecaPedidos=O/IMP_MOC_Pedidos.o \
			     O/IMP_Pedidos.o

Archivos_QT_BibliotecaModificaPedido=CPP/IMP_MOC_ModificaPedido.cpp
Archivos_O_BibliotecaModificaPedido=O/IMP_MOC_ModificaPedido.o \
			     O/IMP_ModificaPedido.o


Archivos_QT_BibliotecaComunElFresno=CPP/MOC_Familias.cpp \
				    CPP/MOC_Unidades.cpp \
				    CPP/MOC_Productos.cpp \
				    CPP/MOC_Vehiculos.cpp
#Bibliotecas_VentasPedidos=-LSO -lComunElFresno 



Bibliotecas_AutorizacionPedidos=-L$(QTDIR)/plugins/designer -LSO -lComunElFresno  -lChoferYVehiculo -lModificaPedido -lCapturaFecha -lControlFecha -lRangoFechas -lCapturaFormaPago
Bibliotecas_ModificaProveedor=-LSO -lComunElFresno
Bibliotecas_BuscarClientes=-LSO -lComunElFresno -lResultadoClientes
Bibliotecas_RegistroEmpleados=-LSO -lComunElFresno  -lIntroduceDatos -lConsultaEmpleados -lMuestraEmpleados
Bibliotecas_Familias=-LSO -lComunElFresno  -lIntroduceDatos -lMantenFamilia
Bibliotecas_ManejadorProductos=-LSO -lComunElFresno   -lMantenProductos
Bibliotecas_ManejadorPrecios=-LSO -lComunElFresno -lActualizaPrecios  -lBuscarClientes -lResultadoClientes -lIntroduceDatos
Bibliotecas_Unidades=-LSO -lComunElFresno   -lMantenUnidad
Bibliotecas_ManejadorProveedores=-LSO \
				  -lComunElFresno  \
				  -lCapturaTelefono \
				  -lCapturaContacto \
				  -lBuscaEmpresas \
				  -lModificaProveedor
Bibliotecas_Clientes=-LSO -lComunElFresno  -lIntroduceDatos -lCapturaTelefono -lBuscarClientes -lModificaGenerales -lCapturaDireccion
Bibliotecas_TiposPrecios=-LSO -lComunElFresno  
Bibliotecas_Vehiculos=-LSO -lComunElFresno  
Bibliotecas_VentasPedidos=-LSO -lComunElFresno  -lBuscarClientes -lIntroduceDatos
Bibliotecas_ChoferYVehiculo=-LSO -lComunElFresno  
Bibliotecas_CtrExpendios=-L Cliente/SO -L $(QTDIR)/plugins/designer -LSO -lRegistraExpendios -lCompras -lControlFecha -lVentas -lVentasExpendio  -lVentasFechaCorte
Bibliotecas_VentasExpendio=-L $(QTDIR)/plugins/designer -LSO -lRangoFechas -lControlFecha

Bibliotecas_Facturacion=-LSO -lComunElFresno -lBuscarClientes -lRangoFechas -lIntroduceDatos 
Bibliotecas_Vehiculos=-LSO -lComunElFresno -lMantenVehiculo
Bibliotecas_VentasFechaCorte=-LSO -lFechasCorteExpendio
		


$(eval $(call ArchivosBibliotecaQTForma,MuestraEmpleados))
$(eval $(call ArchivosBibliotecaQTForma,ConsultaEmpleados))
$(eval $(call ArchivosBibliotecaQTForma,MantenProductos))
$(eval $(call ArchivosBibliotecaQTForma,MantenUnidad))
$(eval $(call ArchivosBibliotecaQTForma,MantenFamilia))
$(eval $(call ArchivosBibliotecaQTForma,MantenVehiculo))
$(eval $(call ArchivosBibliotecaQTForma,ModificaProveedor))
$(eval $(call ArchivosBibliotecaQTForma,CapturaDireccion))
$(eval $(call ArchivosBibliotecaQTForma,ModificaGenerales))
$(eval $(call ArchivosBibliotecaQTForma,Facturacion))
$(eval $(call ArchivosBibliotecaQTForma,BuscaEmpresas))
$(eval $(call ArchivosBibliotecaQTForma,VentasExpendio))
$(eval $(call ArchivosBibliotecaQTForma,CapturaFormaPago))
$(eval $(call ArchivosBibliotecaQTForma,CtrExpendios))
$(eval $(call ArchivosBibliotecaQTForma,CapturaContacto))
$(eval $(call ArchivosBibliotecaQTForma,CapturaTelefono))
$(eval $(call ArchivosBibliotecaQTForma,RangoFechas))
$(eval $(call ArchivosBibliotecaQTForma,CapturaFecha))
$(eval $(call ArchivosBibliotecaQTForma,ChoferYVehiculo))
$(eval $(call ArchivosBibliotecaQTForma,TiposPrecios))
$(eval $(call ArchivosBibliotecaQTForma,ResultadoClientes))
$(eval $(call ArchivosBibliotecaQTForma,BuscarClientes))
$(eval $(call ArchivosBibliotecaQTForma,ActualizaPrecios))
$(eval $(call ArchivosBibliotecaQTForma,Unidades))
$(eval $(call ArchivosBibliotecaQTForma,Familias))
$(eval $(call ArchivosBibliotecaQTForma,IntroduceDatos))
$(eval $(call ArchivosBibliotecaQTForma,VentasPedidos))
$(eval $(call ArchivosBibliotecaQTForma,AutorizacionPedidos))
$(eval $(call ArchivosBibliotecaQTForma,CargaPedido))
$(eval $(call ArchivosBibliotecaQTForma,Compras))
$(eval $(call ArchivosBibliotecaQTForma,ManejadorPrecios))
$(eval $(call ArchivosBibliotecaQTForma,Clientes))
$(eval $(call ArchivosBibliotecaQTForma,ManejadorProveedores))
$(eval $(call ArchivosBibliotecaQTForma,ManejadorProductos))
$(eval $(call ArchivosBibliotecaQTForma,RegistroEmpleados))
$(eval $(call ArchivosBibliotecaQTForma,Vehiculos))
$(eval $(call ArchivosBibliotecaQTForma,VentasFechaCorte))
$(eval $(call ArchivosBibliotecaQTForma,FechasCorteExpendio))

all:						\
	SO/libMuestraEmpleados.so		\
	SO/libConsultaEmpleados.so 		\
	SO/libMantenUnidad.so 			\
	SO/libMantenFamilia.so 			\
	SO/libMantenVehiculo.so			\
	SO/libCapturaTelefono.so 		\
	SO/libCapturaContacto.so 		\
	SO/libRangoFechas.so 			\
	SO/libComunElFresno.so 			\
	SO/libMantenProductos.so		\
	SO/libModificaProveedor.so 		\
	SO/libCapturaDireccion.so 		\
	SO/libModificaGenerales.so 		\
	SO/libBuscaEmpresas.so 			\
	SO/libVentasExpendio.so 		\
	SO/libCapturaFormaPago.so 		\
	SO/libCapturaFecha.so 			\
	SO/libChoferYVehiculo.so 		\
	SO/libTiposPrecios.so 			\
	SO/libResultadoClientes.so 		\
	SO/libBuscarClientes.so 		\
	SO/libActualizaPrecios.so 		\
	SO/libIntroduceDatos.so 		\
	SO/libUnidades.so 			\
	SO/libFamilias.so 			\
	SO/libVentasPedidos.so 			\
	SO/libModificaPedido.so 		\
	SO/libAutorizacionPedidos.so 		\
	SO/libCargaPedido.so 			\
	SO/libCompras.so 			\
	SO/libVentas.so 			\
	SO/libManejadorPrecios.so 		\
	SO/libClientes.so 			\
	SO/libManejadorProveedores.so 		\
	SO/libRegistraExpendios.so 		\
	SO/libFechasCorteExpendio.so 		\
	SO/libVentasFechaCorte.so 		\
	SO/libCtrExpendios.so 			\
	SO/libManejadorProductos.so 		\
	SO/libRegistroEmpleados.so 		\
	SO/libVehiculos.so 			\
	SO/libPedidos.so 			\
	SO/libFacturacion.so 			\
	ElFresno


$(eval $(call EnlaceBibliotecaQTForma,MuestraEmpleados))
$(eval $(call EnlaceBibliotecaQTForma,ConsultaEmpleados))
$(eval $(call EnlaceBibliotecaQTForma,MantenProductos))
$(eval $(call EnlaceBibliotecaQTForma,MantenUnidad))
$(eval $(call EnlaceBibliotecaQTForma,MantenFamilia))
$(eval $(call EnlaceBibliotecaQTForma,MantenVehiculo))
$(eval $(call EnlaceBibliotecaQTForma,ModificaProveedor))
$(eval $(call EnlaceBibliotecaQTForma,CapturaDireccion))
$(eval $(call EnlaceBibliotecaQTForma,ModificaGenerales))
$(eval $(call EnlaceBibliotecaQTForma,Facturacion))
$(eval $(call EnlaceBibliotecaQTForma,BuscaEmpresas))
$(eval $(call EnlaceBibliotecaQTForma,VentasExpendio))
$(eval $(call EnlaceBibliotecaQTForma,CapturaFormaPago))
$(eval $(call EnlaceBibliotecaQTForma,CtrExpendios))
$(eval $(call EnlaceBibliotecaQTForma,CapturaContacto))
$(eval $(call EnlaceBibliotecaQTForma,CapturaTelefono))
$(eval $(call EnlaceBibliotecaQTForma,RangoFechas))
$(eval $(call EnlaceBibliotecaQTForma,CapturaFecha))
$(eval $(call EnlaceBibliotecaQTForma,ChoferYVehiculo))
$(eval $(call EnlaceBibliotecaQTForma,TiposPrecios))
$(eval $(call EnlaceBibliotecaQTForma,BuscarClientes))
$(eval $(call EnlaceBibliotecaQTForma,ResultadoClientes))
$(eval $(call EnlaceBibliotecaQTForma,ActualizaPrecios))
$(eval $(call EnlaceBibliotecaQTForma,Unidades))
$(eval $(call EnlaceBibliotecaQTForma,Familias))
$(eval $(call EnlaceBibliotecaQTForma,IntroduceDatos))
$(eval $(call EnlaceBibliotecaQTForma,VentasPedidos))
$(eval $(call EnlaceBibliotecaQTForma,AutorizacionPedidos))
$(eval $(call EnlaceBibliotecaQTForma,CargaPedido))
$(eval $(call EnlaceBibliotecaQTForma,Compras))
$(eval $(call EnlaceBibliotecaQTForma,ManejadorPrecios))
$(eval $(call EnlaceBibliotecaQTForma,Clientes))
$(eval $(call EnlaceBibliotecaQTForma,ManejadorProveedores))
$(eval $(call EnlaceBibliotecaQTForma,ManejadorProductos))
$(eval $(call EnlaceBibliotecaQTForma,RegistroEmpleados))
$(eval $(call EnlaceBibliotecaQTForma,Vehiculos))
$(eval $(call EnlaceBibliotecaQTForma,VentasFechaCorte))
$(eval $(call EnlaceBibliotecaQTForma,FechasCorteExpendio))

Siscom_ElFresno=ElFresno
Archivos_QT_SiscomElFresno=$(call ArchivosQTSistema,$(Siscom_ElFresno))
Archivos_O_SiscomElFresno=$(call ArchivosOSistema,$(Siscom_ElFresno))	\
			   O/AplicacionVersion3.o

SiscomElFresno:$(Archivos_QT_SiscomElFresno) 	\
	       $(Archivos_O_SiscomElFresno)
	@echo Generando $@
	@$(CXX) $(OpEnlace) -o $@ 		\
	$(Archivos_O_SiscomElFresno)		\
	$(BibliotecasAplicacion)

ElFresno:$(Archivos_QT_ElFresno) $(Archivos_O_ElFresno) 
	@echo Creando $@
	@$(CXX) $(OpEnlace) -o $@ 	\
	$(Archivos_O_ElFresno) 		\
	$(Bibliotecas)

SO/libComunElFresno.so:$(Archivos_O_BibliotecaComunElFresno) $(Archivos_QT_BibliotecaComunElFresno)
	@echo Enlazando $@
	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_BibliotecaComunElFresno)  $(Bibliotecas)

SO/libVentas.so:$(Archivos_O_BibliotecaVentas) $(Archivos_QT_BibliotecaVentas)
	@echo Enlazando $@
	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_BibliotecaVentas) -LSO -lVentasPedidos
SO/libPedidos.so:$(Archivos_O_BibliotecaPedidos) $(Archivos_QT_BibliotecaPedidos)
	@echo Enlazando $@
	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_BibliotecaPedidos) -LSO  -L$(QTDIR)/plugins/designer -lVentasPedidos  -lControlFecha

SO/libRegistraExpendios.so:$(Archivos_O_BibliotecaRegistraExpendios) $(Archivos_QT_BibliotecaRegistraExpendios) 
	@echo Enlazando $@
	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_BibliotecaRegistraExpendios)  -LSO -lManejadorProveedores

SO/libModificaPedido.so:$(Archivos_O_BibliotecaModificaPedido) $(Archivos_QT_BibliotecaModificaPedido)
	@echo Enlazando $@
	@$(CXX) $(OpModulos) -o $@ $(Archivos_O_BibliotecaModificaPedido) -LSO  -lVentasPedidos 
#O/%.o:CPP/%.cpp
#	@echo Compilando $<
#	@$(CXX) $(OpCompilacion) -o $@ $< $(Include)

H/frmFirmaUsuario2.h:UI/frmFirmaUsuario2.ui
	@echo UIC $@
	@$(UIC) -o $@ $<
CPP/MOC_%.cpp:H/%.h
	@echo MOC $<
	@$(MOC) -o $@ $<

CPP/IMP_MOC_%.cpp:H/IMP_%.h
	@echo MOC $<
	@$(MOC) -o $@ $<

H/frm%.h:UI/frm%.ui
	@echo UIC $@
	@$(UIC)	-o $@ $<
clean:
	@-rm O/*.o
	@-rm SO/*.so
	@-rm CPP/MOC_*.cpp
	@-rm CPP/UIC_CPP_*.cpp
	@-rm H/UIC_H_*.h
	@-rm ElFresno



