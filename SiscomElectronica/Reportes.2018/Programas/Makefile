

CFLAGS=-c $(DEBUG) 


Include=-IH -I $(DIRDesarrolloHGE)/SiscomDesarrollo4/H  		\
	-I$(DIRDesarrolloHGE)/SiscomDesarrollo4/PostgresSql/H	\
	-I$(DIRPOSTGRESQL)/include

Libs=-L $(DIRDesarrolloHGE)/SiscomDesarrollo4 		\
     -L $(DIRDesarrolloHGE)/SiscomDesarrollo4/PostgresSql	\
     -L $(DIRPOSTGRESQL)/lib				\
	-lSiscomDesarrollo4				\
	-lSiscomPostgresSql				\
	-lpq



Archivos_O_ReportesVentas=O/VentasExpendio.o O/Soporte.o O/Reportes.o


all:VentasExpendio


VentasExpendio:$(Archivos_O_ReportesVentas)
	gcc $(DEBUG) -o $@ $(Archivos_O_ReportesVentas) $(Libs)



O/%.o:C/%.c
	gcc $(CFLAGS) -o $@ $< $(Include)

clean:
	-rm VentasExpendio 
	-rm O/*
