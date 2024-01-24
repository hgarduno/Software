#include <stdio.h>
#include <unistd.h>


#include <SiscomDesarrollo2.h>


#include <Procesa.h>
#include <ActualizaAplicacion.h>
#include <errno.h>

int erno;

				
int main(int pintArgc,
	 char **pchrPtrArgv)

{
int lintSocket=atoi(pchrPtrArgv[1]);
char lchrArrBuffer[5];
char *lchrPtrOperacion;
int lintContador;
SSiscomOperaciones *lSSiscomOp;
	
	
	SiscomLeeOperacion(lintSocket,
			   &lchrPtrOperacion);
	OperacionesActualiza(&lSSiscomOp);
	for(lintContador=0;
	    lintContador<lSSiscomOp->intNumOperaciones;
	    lintContador++)
	if(!strcmp((lSSiscomOp+lintContador)->chrPtrOperacion,
	           lchrPtrOperacion))
	{
	     (lSSiscomOp+lintContador)->Operacion(lintSocket);
	     return 1;
	}
	printf("MAIN:Operacion {%s} No Soportada\n",
		lchrPtrOperacion);
		

}
