


all:Manuales.GZ


Manuales.GZ:man1/SArgsSiscom.1.gz man1/SiscomModuloOperacion.1.gz
	
man1/%.1:./%
	cp $< $@
man1/%1.gz:man1/%.1
	gzip $$
