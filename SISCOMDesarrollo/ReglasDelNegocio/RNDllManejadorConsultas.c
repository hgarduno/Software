#include <RNDllConsultas.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
int RNDllCNSIdentificaConsulta(PARDEPURACION int pintSocket,int pintTuberia[],int pintPuertoAD,char *pchrPtrDIPSvrAD,STRUCTError *pstcErrorPtrReg)
{
char ***lchrPtrCadenaRegreso;
char lchrArrCadenaFormateada[1500],lchrArrCadenaTipoPrecio[1500];
int lintNRegistros,lintNColumnas;
int i;
STRUCTCantidadYProducto lstcCantidadYProductoDat[100];
char lchrArrNmbDllAEjecutar[512],lchrArrNmbFuncion[512];
int (*RNDllRealizaConsulta)(PARDEPURACION int,int [],char *,int,char *,STRUCTError *);
void *lvidPtrRegresoDll;
        SISCOMObtenInformacionDelProtocolo(PDEPURACION pintSocket,&lintNRegistros,&lintNColumnas,&lchrPtrCadenaRegreso,pstcErrorPtrReg);
	RNADObtenDllConsultaYFuncion(PDEPURACION lchrPtrCadenaRegreso[0][0],lchrArrNmbDllAEjecutar,lchrArrNmbFuncion);
	if(!(lvidPtrRegresoDll=dlopen(lchrArrNmbDllAEjecutar,RTLD_LAZY)))
	{
		printf("%s\n",dlerror());
		exit(1);
		
	}	
	else
	if(!(RNDllRealizaConsulta=(int (*)(PARDEPURACION int,int [],char *,int,char *,STRUCTError *))dlsym(lvidPtrRegresoDll,lchrArrNmbFuncion)))
         {
		printf("%s\n",dlerror());
		exit(1);
		
	}	
	else
	RNDllRealizaConsulta(PDEPURACION pintSocket,pintTuberia,lchrPtrCadenaRegreso[0][0],pintPuertoAD,pchrPtrDIPSvrAD,pstcErrorPtrReg);	
 	dlclose(lvidPtrRegresoDll);	
	
}
