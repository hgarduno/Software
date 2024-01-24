#include <stdio.h>
#include <ADDllRealizaAltaDeProductosEZS.h>
#include <dlfcn.h>

int ADDllRealizaAltaVentasEZS(PARDEPURACION int pintSocketCliente, int pintTuberia[], int pintPuerto, char *pchrPtrDirIP)
{
 void *lvidDll;
 int lintNRegistros;
 STRUCTError lstcErrorReg;
 STRUCTLtaVentas *lstcLtaVentasPtrPrim = NULL;
 STRUCTDatosDeLaOperacion lstcDatosDeLaOperacionReg;
 
 int (*POSTGRESQLInsertaVentas)(PARDEPURACION STRUCTDatosDeLaOperacion, STRUCTLtaVentas *, STRUCTError *);
 
#ifdef DEBUG
	strcat(PDEPURACION "\t");
	SISCOMImprimeFuncionYArgumentos(PDEPURACION "%00F%", "ADDllRealizaAltaVentasEZS");
#endif
printf("Ya esta\n");
 if (!(lvidDll = dlopen("libADDllInsercionesPostgreSQLEZS.so", RTLD_LAZY)))
    printf("%s\n", dlerror());
 else
    POSTGRESQLInsertaVentas = (int (*)(PARDEPURACION STRUCTDatosDeLaOperacion, STRUCTLtaVentas *, STRUCTError *))dlsym(lvidDll, "POSTGRESQLInsertaVentas");
 if (!POSTGRESQLInsertaVentas)
    printf("%s\n", dlerror());
 RNADGeneraListaVentas(PDEPURACION pintSocketCliente, &lintNRegistros, &lstcLtaVentasPtrPrim, &lstcErrorReg);
 POSTGRESQLInsertaVentas(PDEPURACION lstcDatosDeLaOperacionReg, lstcLtaVentasPtrPrim, &lstcErrorReg);
}
