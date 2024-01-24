



all:Compila Copia

Copia:
	@cd SiscomElectronica2; make Copia

Compila:
	@cd SiscomElectronica2; make
	@cd SiscomElectronica3; make
	@cd Cliente/ ; make
	@cd Servidor/ ; make
	@cd Cliente/Iconos; make
	@ln -sf Cliente/Iconos/*.so Cliente/SO
clean:
	@cd Cliente; make clean
	@cd Servidor; make clean
	@cd SiscomElectronica2;make clean
	@cd SiscomElectronica3;make clean
ClienteClean:
	@cd Cliente; make clean
SiscomElectronica3Clean:
	@cd SiscomElectronica3 ;make clean
	
