OpC=-c $(DEBUG) $(OpCSiscom) 

ifeq ($(SistemaOperativo),Linux)
OpShared=$(DEBUG)  -shared $(OpCSiscom)  
else
OpShared=$(DEBUG) -shared $(OpCSiscom) -flat_namespace -undefined suppress
endif


Archivos_O_SiscomDesarrollo4=O/SiscomFuncionesComunes.o 	\
			     O/SiscomManejoLog.o		\
			     O/SiscomArchivosIni.o		\
			     O/SiscomErrores.o			\
			     O/SiscomProtocoloComunicaciones.o	\
			     O/SiscomCamposProtocolo.o		\
			     O/SiscomRecibeArchivo.o		\
			     O/SiscomEnviaArchivo.o		\
			     O/SiscomOperacionesDirectorios.o	\
			     O/SiscomLineaComandos.o		\
			     O/SiscomNormalizacion.o

Archivos_O_SiscomOperaciones=O/SiscomOperaciones.o  		\
			     O/SiscomInsercionesSql.o		\
			     O/SiscomLogOperaciones.o		\
			     O/SiscomReplicacion.o

Archivos_O_Pruebas=O/Pruebas.o 
Archivos_O_ClienteEnvio=O/ClienteEnvio.o

Archivos_O_ServidorSiscom=O/SiscomServidor.o
Include=-I H
Bibliotecas=-ldl 		\
	   -L. -lSiscomDesarrollo4  -lSiscomOperaciones
Binarios=libSiscomDesarrollo4.so 		\
	 libSiscomOperaciones.so 		\
	 ServidorSiscom				\
	 Pruebas				\
	 ClienteEnvio

all:$(Binarios)  ModuloPostgres

libSiscomOperaciones.so:$(Archivos_O_SiscomOperaciones)
	$(CC) $(OpShared) -o $@ $(Archivos_O_SiscomOperaciones)
	
libSiscomDesarrollo4.so:$(Archivos_O_SiscomDesarrollo4)
	$(CC) $(OpShared)  -o $@ $(Archivos_O_SiscomDesarrollo4)
Pruebas:$(Archivos_O_ClienteEnvio)
	$(CC) -o $@ $(OpCSiscom) $(DEBUG) $(Archivos_O_ClienteEnvio) -L. -lSiscomDesarrollo4  -lSiscomOperaciones
ClienteEnvio:$(Archivos_O_ClienteEnvio)
	$(CC) -o $@ $(OpCSiscom) $(DEBUG) $(Archivos_O_ClienteEnvio) -L. -lSiscomDesarrollo4  -lSiscomOperaciones
ServidorSiscom:$(Archivos_O_ServidorSiscom)
	$(CC) $(OpCSiscom) $(DEBUG) -o $@ $(Archivos_O_ServidorSiscom) $(Bibliotecas)

ModuloPostgres:
	@(cd PostgresSql; make )
O/%.o:C/%.c
	$(CC) $(OpC) -o $@ $< $(Include)


clean:
	-rm -rf O/*.o 
	-rm $(Binarios)

