CFLAGS=-c -g $(OpCSiscom)
INCLUDE=-I H/ -I $(DIRDesarrolloHGE)/SiscomDesarrollo4/H
LIBS=-L$(DIRDesarrolloHGE)/SiscomDesarrollo4 -lSiscomDesarrollo4

ArchivosO=O/ArreglandoDuplicadosImporteOrden.o
Archivos_O_FriPro=O/FriPro.o O/FacturandoFriPro.o
Archivos_O_Configuracion=O/ArmaArchivoConfiguracion.o
Archivos_O_CompraImportacion=O/CompraImportacion.o
Archivos_O_ActualizaPrecios=O/ActualizaPrecios.o

Archivos_InstaladorClienteSiscom=O/PrincipalInstalacionClienteSiscom.o
all:EliminaDuplicados 		\
	FriPro 			\
	ConfiguracionBin	\
	CompraImportacion	\
	ActualizaPrecios	\
	InstaladorClienteSiscom


EliminaDuplicados:$(ArchivosO)
	gcc $(OpCSiscom) -o $@ $(ArchivosO) $(LIBS)

FriPro:$(Archivos_O_FriPro)
	gcc $(OpCSiscom) -o $@ $(Archivos_O_FriPro) $(LIBS)

ConfiguracionBin:$(Archivos_O_Configuracion)
	gcc $(OpCSiscom) -o $@ $(Archivos_O_Configuracion) $(LIBS)
CompraImportacion:$(Archivos_O_CompraImportacion)
	gcc $(OpCSiscom) -o $@ $(Archivos_O_CompraImportacion) $(LIBS)

InstaladorClienteSiscom:$(Archivos_InstaladorClienteSiscom)
	gcc $(OpCSiscom) -o $@ $(Archivos_InstaladorClienteSiscom) $(LIBS)
ActualizaPrecios:$(Archivos_O_ActualizaPrecios)
	gcc $(OpCSiscom) -o $@ $(Archivos_O_ActualizaPrecios) $(LIBS)
O/%.o:C/%.c
	gcc $(CFLAGS) -o $@ $< $(INCLUDE)


clean:
	-rm O/*
	-rm FriPro.SiscomFacturacion
	-rm EliminaDuplicados FriPro

	
