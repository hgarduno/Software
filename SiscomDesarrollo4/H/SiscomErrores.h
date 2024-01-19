#ifndef __SISCOMERRORES_H__
#define __SISCOMERRORES_H__
typedef struct siscomError
{
    char chrArrArchivo[256];
    char chrArrFuncion[256];
    int intNLinea;
    int intCodigoError;
    char chrArrMensajeError[256];
}SiscomError;

int SiscomErrorG(const char *pchrPtrArchivo,
		 const char *pchrPtrFuncion,
		 int pintNLinea,
		 int pintCodigoError,
		 const char *pchrPtrMensajeError);


extern SiscomError gSiscomErrorSistema;
#endif
