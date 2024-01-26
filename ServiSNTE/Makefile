


all:CompilaCliente  CompilaServidor


CompilaCliente:
	@(cd Cliente ; make)
CompilaServidor:
	@(cd Servidor; make)


clean:
	@(cd Cliente ;make -f MakefilePlugin distclean)
	@(cd Cliente ;make -f MakefileApp distclean)
	@(cd Servidor ;make clean)
ClienteClean:
	@(cd Cliente ;make -f MakefileApp distclean)
	@(cd Cliente ;make -f MakefilePlugin distclean)
	
