

Os_CambiaCaracteres=O/CambiaCaracteres.o






CambiaCaracteres:$(Os_CambiaCaracteres)
	@printf "Enlazando %s\n" $@
	cc -o $@ $(Os_CambiaCaracteres) 


O/%.o:C/%.c
	@printf "Compilando %s\n" $< 
	@cc -c -o $@ $< 

