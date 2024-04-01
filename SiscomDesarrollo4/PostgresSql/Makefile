OpC=$(DEBUG) -c -fPIC $(OpCSiscom) 
OpShared=$(DEBUG) -shared $(OpCSiscom)
Include=-I H				\
	-I $(DIRDesarrolloHGE)/SiscomDesarrollo4/H 	\
	-I $(DIRPOSTGRESQL)/include 
Binarios=libSiscomPostgresSql.so
Bibliotecas=-L$(DIRDesarrolloHGE)/SiscomDesarrollo4/ -lSiscomDesarrollo4 -L$(DIRPOSTGRESQL)/lib -lpq
Archivos_O_SiscomPostgresSql=O/PostgresAccesoDatos.o 

all:DirectorioO $(Binarios)

libSiscomPostgresSql.so:$(Archivos_O_SiscomPostgresSql)
	$(CC) $(OpShared)  -o $@ $(Archivos_O_SiscomPostgresSql) $(Bibliotecas)	



O/%.o:C/%.c
	$(CC) $(OpC) -o $@ $< $(Include)


clean:
	-rm O/*
	-rm $(Binarios)
DirectorioO:
	-mkdir O
