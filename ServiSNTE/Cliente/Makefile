

all:Cliente Plugin Compila


Compila:
	make -f MakefilePlugin
	make -f MakefileApp
Cliente:ServiSNTEApp.pro
	$(QTDIR)/bin/qmake -o MakefileApp ServiSNTEApp.pro


Plugin:ServiSNTE.pro
	$(QTDIR)/bin/qmake -o MakefilePlugin ServiSNTE.pro


clean:
	@make -f MakefilePlugin distclean
	@make -f MakefileApp   distclean
