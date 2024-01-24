############## Bueno ahora si hay que realizar cambios
############## Bueno para mas cambios es necesario 


all:Compila NivelUtilizacion

Compila:
	@cd Cliente/ ; make
	@cd Servidor/ ; make
clean:
	@cd Cliente; make clean
	@cd Servidor; make clean
ClienteClean:
	@cd Cliente; make clean
CleanControles:
	@cd Cliente; make cleanControles
ServidorClean:
	@cd Servidor;make clean

NivelUtilizacion:
	@cd Cliente; make -f MakefileNivelesUtilizacion

Prueba:
	@cd Cliente; make Prueba
