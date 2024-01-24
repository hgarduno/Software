#include <ADDllManejadorDeSistemaDeConsultas.h>
#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
int ADDllCNSIdentificaConsulta(PARDEPURACION int pintSocketCliente,int pintTuberia[],int pintPuerto,char *pchrPtrDirIp)
{
STRUCTError lstcErrorReg;
char ***lchrPtrCadenaRegreso;
char lchrArrCadenaConsulta[2500];
char lchrArrCadenaConsulta1[2500];
int lintNRegistros,lintNColumnas;
void *lvidPtrCargaDll;
int (*ADDllRealizaConsulta)(PARDEPURACION int,char ***,STRUCTError *);
int lintI;

	SISCOMObtenInformacionDelProtocolo(PDEPURACION pintSocketCliente,&lintNRegistros,&lintNColumnas,&lchrPtrCadenaRegreso,&lstcErrorReg);

	if(!(lvidPtrCargaDll=dlopen(lchrPtrCadenaRegreso[0][0],RTLD_LAZY)))
	{
		printf("%s\n",dlerror());
		exit(0);
	}
	else
	if(!(ADDllRealizaConsulta=(int (*)(PARDEPURACION int,char ***,STRUCTError *))dlsym(lvidPtrCargaDll,lchrPtrCadenaRegreso[0][1])))
	{
		printf("%s\n",dlerror());
		exit(0);
	}
	else
	ADDllRealizaConsulta(PDEPURACION pintSocketCliente,lchrPtrCadenaRegreso,&lstcErrorReg);	
	dlclose(lvidPtrCargaDll);
}
