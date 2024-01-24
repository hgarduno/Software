DirModulos=$(HOME)/.linux/SISCOMTiendas/ModulosSistemaTiendas
BibliotecasAD=-L $(DirModulos) -lControladorComandosSQL -lpq

ArchivosObjBControlador=POSTGRESQLControlador.o POSTGRESQLComunes.o
Include=-I $(DIRPOSTGRESQL)/include -I . -I $(SISCOM_LIB_DIR)/Include
all:\
	    $(DirModulos)/libControladorComandosSQL.so \
	    Pruebas \
            PruebasBiblioteca++ \
	    $(DirModulos)/libRNDllEliminaProductos.so \
	    $(DirModulos)/libADDllEliminaProductos.so 
Pruebas:PruebaNvasFunciones.c
	gcc -g -o Pruebas PruebaNvasFunciones.c -I $(SISCOM_LIB_DIR)/Include -L$(SISCOM_LIB_DIR) -lSISCOMDesarrollo.1.0 -ldl

PruebasBiblioteca++:PruebaBiblioteca++.cpp
	g++ -g -o PruebasBiblioteca++  PruebaBiblioteca++.cpp -I$(SISCOM_LIB_DIR)/Include -L$(SISCOM_LIB_DIR) -l SISCOMDesarrollo++
$(DirModulos)/libRNDllEliminaProductos.so:RNDllEliminaProductos.c
	cc -shared -o $@ $<  -L$(SISCOM_LIB_DIR)  -lSISCOMDesarrollo.1.0 -ldl -I$(SISCOM_LIB_DIR)/Include


$(DirModulos)/libADDllEliminaProductos.so:ADDllEliminaProductos.c $(DirModulos)/libControladorComandosSQL.so
	cc -shared -o $@ $<  $(Include)  -L$(SISCOM_LIB_DIR)  -lSISCOMDesarrollo.1.0 -ldl -I$(SISCOM_LIB_DIR)/Include $(BibliotecasAD)
$(DirModulos)/libControladorComandosSQL.so:$(ArchivosObjBControlador)
	cc -shared -o $@  $(ArchivosObjBControlador)
mas:
	@echo $(ArchivosObjBControlador)
%.o:%.c
	cc -c -o $@ $< $(Include)
