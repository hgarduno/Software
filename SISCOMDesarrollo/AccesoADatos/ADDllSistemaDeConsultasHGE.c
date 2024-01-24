#include <ADDllSistemaDeConsultasHGE.h>
#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>
int ADDllCNSClientes(PARDEPURACION int pintSocketCliente,char *pchrPtrConsulta)
{
STRUCTLtaCliente *lstcLtaClienteReg=NULL;
STRUCTDatosDeLaOperacion lstcDatosDeLaOperacionDat;
int lintTamano;
int lintNRegistros,lintNColumnas;
char lchrArrCadena[255];
char lchrFin='*';
int (*ADDllConsultaClientesPostgreSQL)(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTLtaCliente **,int *,int *,STRUCTError *);
void *lvidRegresoDll;	
#ifdef DEBUG
	strcat(PDEPURACION "\t");
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","ADDllCNSClientes");
#endif
if(!(lvidRegresoDll=dlopen("libADDllConsultasPostgreSQL.so",RTLD_LAZY)))
printf("\n%s ",dlerror());
ADDllConsultaClientesPostgreSQL=(int (*)(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTLtaCliente **,int *,int *,STRUCTError *))dlsym(lvidRegresoDll,"ADDllConsultaClientesPostgreSQL");
if(!ADDllConsultaClientesPostgreSQL)
printf("\n%s\n",dlerror());
ADDllConsultaClientesPostgreSQL(PDEPURACION lstcDatosDeLaOperacionDat,pchrPtrConsulta,&lstcLtaClienteReg,&lintNRegistros,&lintNColumnas,0);
RNADEnviaClientes(PDEPURACION pintSocketCliente,lintNRegistros,lintNColumnas,lstcLtaClienteReg);
dlclose(lvidRegresoDll);
//close(pintSocketCliente);
}
int ADDllCNSEstGananciasNDisp(PARDEPURACION int pintSocketCliente,char *pchrPtrConsulta)
{
STRUCTLtaEstGananciaNDisp *lstcLtaEstGananciaNDispPtrUlt=NULL;	
STRUCTDatosDeLaOperacion lstcDatosDeLaOperacionDat;
int lintTamano;
int lintNRegistros,lintNColumnas;
char lchrArrCadena[255];
char lchrFin='*';
int (*ADDllConsultaEstGananciaNDispositivosPostgreSQL)(PARDEPURACION STRUCTDatosDeLaOperacion ,char *,STRUCTLtaEstGananciaNDisp **,int *,int *,STRUCTError *);
void *lvidRegresoDll;
#ifdef DEBUG
        strcat(PDEPURACION "\t");
        SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%","ADDllCNSEstGananciasNDisp");
#endif
if(!(lvidRegresoDll=dlopen("libADDllConsultasPostgreSQL.so",RTLD_LAZY)))
printf("\n%s ",dlerror());
ADDllConsultaEstGananciaNDispositivosPostgreSQL=(int (*)(PARDEPURACION STRUCTDatosDeLaOperacion,char *,STRUCTLtaEstGananciaNDisp **,int *,int *,STRUCTError *))dlsym(lvidRegresoDll,"ADDllConsultaEstGananciaNDispositivosPostgreSQL");
if(!ADDllConsultaEstGananciaNDispositivosPostgreSQL)
printf("\n%s\n",dlerror());
ADDllConsultaEstGananciaNDispositivosPostgreSQL(PDEPURACION lstcDatosDeLaOperacionDat,pchrPtrConsulta,&lstcLtaEstGananciaNDispPtrUlt,&lintNRegistros,&lintNColumnas,0);
RNADEnviaLtaEstGananciaNDisp(PDEPURACION pintSocketCliente,lintNRegistros,lintNColumnas,lstcLtaEstGananciaNDispPtrUlt);
dlclose(lvidRegresoDll);
close(pintSocketCliente);
}
