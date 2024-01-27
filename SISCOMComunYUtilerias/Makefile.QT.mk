FormaNombreAQT=$(patsubst $(1)%.$(2),$(3)/$(4)%.$(5),$(6))


FuncionArchivosQT=$(call FormaNombreAQT,frm,ui,Include,frm,h,$(1)       \
           $(call FormaNombreAQT,frm,ui,Fuentes,frm,cpp,$(1))    \
	   $(call FormaNombreAQT,frm,ui,Fuentes,frm,moc.cpp,$(1)) \
	   $(call FormaNombreAQT,frm,ui,Fuentes,Cfrm,moc.cpp,$(1)) )

FuncionArchivosQTObj=$(call FormaNombreAQT,frm,ui,Obj,frm,o,$(1)		\
		     $(call FormaNombreAQT,frm,ui,Obj,Cfrm,o,$(1))		\
		     $(call FormaNombreAQT,frm,ui,Obj,frm,moc.o,$(1))		\
		     $(call FormaNombreAQT,frm,ui,Obj,Cfrm,moc.o,$(1)))

FuncionArchivosQTSinUI=$(call FormaNombreAQT,$(1),h,Fuentes,$(1),moc.cpp,$(2) )
FuncionArchivosQTSinUIObj=$(call FormaNombreAQT,$(1),h,Obj,$(1),moc.o,$(2))  \
			  $(call FormaNombreAQT,$(1),h,Obj,$(1),o,$(2))

define FuncionCompilaBibInterfaz
$(1)/libInterfaz$(2)$(3).so:$$(Archivos$(3)) $$(ArchivosQT$(3)SinUI) $$(ArchivosQT$(3)SinUIObj) $$(ArchivosOExtra$(3)) $$(DepBibliotecas$(3))
	@echo G++ [LD] libInterfaz$(2)$(3).so
	@$(GPP) $(OpM) -o $(1)/libInterfaz$(2)$(3).so $(ArchivosQT$(3)O) $(ArchivosQT$(3)SinUIObj) $(ArchivosOExtra$(3)) $(Bibliotecas) $(Bibliotecas$(3))
endef

define FuncionCreaCompilacionBibInterfaz
ArchivosUI$(1)=$(2)
ArchivosQT$(1)=$$(call FuncionArchivosQT,$$(ArchivosUI$(1)))
ArchivosQT$(1)O=$$(call FuncionArchivosQTObj,$$(ArchivosUI$(1)))
Archivos$(1)=$$(ArchivosQT$(1)) $$(ArchivosQT$(1)O)
endef



Include=-I $(QTDIR)/include -I $(SISCOM_LIB_DIR)/Include $(DIRLIBSISCOM2)/H
BibliotecasQT=-L $(QTDIR)/lib -lqt-mt -L$(SISCOM_LIB_DIR) -lSISCOMDesarrollo++ -L$(SISCOM_LIB_DIR) -lSISCOMDesarrolloQ++
OpC=-g -c  
OpM=-shared $(DEBUG)


Obj/%.o:Fuentes/%.cpp
	@echo GCC $@
	@$(GCC) $(DEBUG) $(OpC) -o $@ $< $(Include)
Include/%.h:UI/%.ui
	@echo UIC $@
	@$(UIC) -o $@ $<
Fuentes/%.cpp:UI/%.ui
	@echo UIC [IMP] $@
	@$(UIC) -impl Include/$*.h -o $@ $<
Fuentes/%.moc.cpp:Include/%.h
	@echo MOC $@
	@$(MOC)  -o $@ $<
	
