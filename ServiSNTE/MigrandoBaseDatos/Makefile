Archivos_O_MigrandoBaseDatos=O/EjecutaSql.o 		\
			     O/Principal.o 		\
			     O/GeneraInserciones.o	\
			     O/InsercionesArchivoSql.o



Include=-I H  -I $(DirDesarrollo4)/SiscomDesarrollo4/H -I $(DirDesarrollo4)/SiscomDesarrollo4/PostgresSql/H -I $(DIRPOSTGRESQL)/include
OpcionesC=-g -c $(DEBUG) -fPIC 
ifeq ($(SistemaOperativo),Linux)
OpcionesLd=$(DEBUG) -fPIC -g
else
OpcionesShared=-shared $(DEBUG) -fPIC -flat_namespace -undefined suppress
endif
Bibliotecas=-L$(DirDesarrollo4)/SiscomDesarrollo4 				\
	     -L$(DirDesarrollo4)/SiscomDesarrollo4/PostgresSql 			\
	     -lSiscomOperaciones  						\
	     -lSiscomDesarrollo4 						\
	     -lSiscomPostgresSql

all:MigrandoBaseDatos


MigrandoBaseDatos:$(Archivos_O_MigrandoBaseDatos)
	@echo 'LD $@'
	@gcc $(OpcionesLd) -o $@ $(Archivos_O_MigrandoBaseDatos) $(Bibliotecas)

O/%.o:C/%.c
	@echo CC $<
	@gcc $(OpcionesC) $(Include) -o $@ $<

clean:	
	-rm O/*
