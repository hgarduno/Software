#include <SiscomErrores.h>
#include <string.h>
int SiscomErrorG(const char *pchrPtrArchivo,
		 const char *pchrPtrFuncion,
		 int pintNLinea,
		 int pintCodigoError,
		 const char *pchrPtrMensajeError)
{
    strcpy(gSiscomErrorSistema.chrArrArchivo,pchrPtrArchivo);
    strcpy(gSiscomErrorSistema.chrArrFuncion,pchrPtrFuncion);
    gSiscomErrorSistema.intNLinea=pintNLinea;
    gSiscomErrorSistema.intCodigoError=pintCodigoError;
    strcpy(gSiscomErrorSistema.chrArrMensajeError,pchrPtrMensajeError);
    return pintCodigoError;
}
