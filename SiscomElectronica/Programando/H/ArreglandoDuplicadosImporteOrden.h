#ifndef __ARREGLANDODUPLICADOSIMPORTEORDEN_H__
#define __ARREGLANDODUPLICADOSIMPORTEORDEN_H__
#include <stdio.h>
#define TAMANOBUFFER 512
typedef struct CTIDIdVenta
{
	char chrArrCTID[25];
	char chrArrIdVenta[TAMANOBUFFER];
}zCTIDIdVenta;



FILE *AbreArchivo(const char *pchrPtrArchivo);
const char *NombreArchivo(int,char **pchrPtrArgv);
void ObtenCTIDIdVenta(const char *pchrPtrLinea,char *pchrPtrCTID,char *pchrPtrIdVenta);

int CargaInformacion(FILE *pFlePtrArchivo,zCTIDIdVenta **pzCTIDIdVentaReg);
void ObtenIdsVentaDuplicados(const char *pchrPtrSqlDelete,int pintNRegistros,zCTIDIdVenta *pzCTDIdVenta);




#endif
