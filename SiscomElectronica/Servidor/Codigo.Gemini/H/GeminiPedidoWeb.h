#ifndef GEMINIPEDIDOWEB_H
#define GEMINIPEDIDOWEB_H

#include <stdio.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomDesarrolloMacros.h> /* Incluye las macros LogSiscom y SiscomRegistroProtocoloLog */

/* Variable global de log de SiscomDesarrollo4 */
extern FILE *gPtrFleArchivoLog;

/* Macro para invocar el log con metadatos de archivo, funcion y linea */
#define GeminiSiscomParaPromptLog(pRegistroPtr) \
    GeminiSiscomProtcoloLog(__FILE__, __FUNCTION__, __LINE__, pRegistroPtr)

void GeminiSiscomProtcoloLog(const char *pchrPtrArchivo, const char *pchrPtrFuncion, int pintLinea, SiscomRegistroProL *pRegistroPtr);
SiscomRegistroProL *GeminiOrdenVentaSiscom(void);

/* Funciones de preparacion y obtencion de datos JSon (API Pedidos) */
SiscomRegistroProL *GeminiPreparaRegistroParaEjecucion(void);
const char *GeminiIdPedido(SiscomRegistroProL *pRegistro);
const char *GeminiFechaHora(SiscomRegistroProL *pRegistro);
SiscomRegistroProL *GeminiProductos(SiscomRegistroProL *pRegistro);
SiscomRegistroProL *GeminiDireccionEnvio(SiscomRegistroProL *pRegistro);
SiscomRegistroProL *GeminiCliente(SiscomRegistroProL *pRegistro);

/* Funciones de logica de negocio y debug */
void GeminiRegistraPedido(SiscomRegistroProL *pRegistroPtr);

#endif


