##################################################################################################
#######################################     MACROS     ###########################################
##################################################################################################
# se agreo
## mas
DIRFUNCOMUNES      = FuncionesComunes/CodigoFuente
DIRFUNCOMUNESRNAD  = RNADComun/CodigoFuente
DIRRN              = ReglasDelNegocio
DIRAD              = AccesoADatos
DIROBJS            = Objetos
DIRBINARIOS        = Servidor
MAKE               = make
#CC                 = cc
OPC		   =-c $(DEBUG) $(OpCSiscom) #-DDEBUG $(DEBUG) #-DARCHIVOLOG
OPCDEPURACION	   =
INCLUDESISCOM      = -IArchivosCabecera -IFuncionesComunes/ArchivosCabecera -IRNADComun/ArchivosCabecera \
		     -IArchivosCabecera/PostgreSQL -I/usr/include/pgsql -I /usr/include/postgresql/  -I /LibSISCOMDesarrollo1.0/Include -I $(DIRPOSTGRESQL)/include

VPATH=$(DIRFUNCOMUNES) $(DIRRN) $(DIRAD) $(DIROBJS) $(DIRBINARIOS) $(DIRFUNCOMUNESRNAD)

export DIRFUNCOMUNES DIRBINARIOS DIRRN DIRAD MAKE CC INCLUDESISCOM DIROBJS DIRFUNCOMUNESRNAD VPATH OPC OPCDEPURACION


##################################################################################################
#######################################     REGLAS     ###########################################
##################################################################################################

all:HGEOBJS EZSOBJS HGEBINARIOS EZSBINARIOS #COPIA_LIB_Y_BIN

HGEOBJS:
	@echo MAKE [Makefile.HGE.Objetos]
	@$(MAKE)  -f Makefile.HGE.Objetos
	@echo MAKE [Makefile.BibliotecaSISCOM]
	@$(MAKE)  -f Makefile.BibliotecaSISCOM
	@echo MAKE [Makefile.BibliotecaSISCOM++]
	@$(MAKE)  -f Makefile.BibliotecaSISCOM++
	@echo MAKE [Makefile.BibliotecaSISCOMQ++]
	@$(MAKE)  -f Makefile.BibliotecaSISCOMQ++
	@echo MAKE [Makefile.SoporteVersion2]
	@(cd Version2/; $(MAKE)  -f Makefile.SoporteVersion2)

HGEBINARIOS:
	@$(MAKE)  -f Makefile.HGE.Binarios	
EZSOBJS:
	@$(MAKE)  -f Makefile.EZS.Objetos
EZSBINARIOS:
	@$(MAKE)  -f Makefile.EZS.Binarios


##################################################################################################
########################     Opcion para copiar los archivos .bin y .so    #######################
##################################################################################################

COPIA_LIB_Y_BIN:
	cp -f $(DIRBINARIOS)/*.so /usr/SISCOMVentas/lib
	cp -f $(DIRBINARIOS)/*.bin /usr/SISCOMVentas/bin


##################################################################################################
############################     Opcion para limpiar los Directorios    ##########################
##################################################################################################

clean:
	rm $(DIROBJS)/*.o
	rm $(DIRBINARIOS)/*.bin


##################################################################################################
#############################     Opcion para crear los directorios    ###########################
##################################################################################################

creadir:
	mkdir $(DIROBJS)
	mkdir $(DIRBINARIOS)
