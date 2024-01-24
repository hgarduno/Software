#ifndef __ESTRUCTURASSISCOM__H_
#define __ESTRUCTURASSISCOM__H_

typedef struct STRUCTError
{
int intNumError;
int intSiContinua;
char chrNmbFuncion[200];
char chrErrorLogico[1024];

}STRUCTError;
typedef struct STRUCTProcesoYDll
{
char chrArrNombreProceso[256];
char chrArrNombreDll[256];
unsigned long lngTipoDeMovimiento;
}STRUCTProcesosYDll;
#define EAARCHIVOW	0000001
#define EAARCHIVOL	0000002
#define EAMEMORIA	0000003
#define ENOCONTINUA	0000004
#define ESICONTINUA	0000005
void LlenaEstructuraDeError(int,int,char *,char *,STRUCTError *);
int SeDetectoError(STRUCTError );
int ImprimeSTRUCTProcesosYDll(STRUCTProcesosYDll);
typedef struct stcDatos
{
	char *chtPtrDato[200];
	int intNDatos;

}STRUCTDatos;
typedef struct LtaStcDatos
{
    STRUCTDatos stcDatos;
    struct LtaStcDatos *stcLtaDatosPtrSig;
}STRUCTLtaDatos;

typedef struct StcServidoresRep
{
	int intPuertoAD;
	char chrArrDirIPAD[25];
}StcServidoresRep;

#endif 
