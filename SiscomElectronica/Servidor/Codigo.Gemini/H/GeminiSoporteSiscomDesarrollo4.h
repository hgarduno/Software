#ifndef _GEMINISOPORTESISCOMDESARROLLO4_H
#define _GEMINISOPORTESISCOMDESARROLLO4_H

#include <SiscomDesarrolloMacros.h>
#include <SiscomProtocoloComunicaciones.h>

#define GeminiJSonLog(cadena, cveproducto) \
    GeminiJSonRespuestaALog(__FILE__, __FUNCTION__, __LINE__, cadena, cveproducto)

#define GeminiLogSiscomRegistroLJSon(pSiscomRegProLPtrJSon)\
    GaminiRegistroProtocoloJSonLog(__FILE__, __FUNCTION__, __LINE__, pSiscomRegProLPtrJSon)

void GeminiJSonRespuestaALog(const char *pchrPtrArchivo,
                             const char *pchrPtrFuncion,
                             int pintLinea,
                             const char *pchrPtrRespuestaJson,
                             const char *pchrPtrCveProducto);

SiscomRegistroProL *GeminiJSonASiscomRegistroProL(const char *pchrPtrJsonStr);

char *GeminiSiscomRegistroProLAJson(SiscomRegistroProL *pSisRegProLPtr);

void GaminiRegistroProtocoloJSonLog(const char *pchrPtrArchivo,
                                    const char *pchrPtrFuncion,
                                    int pintNoLinea,
                                    SiscomRegistroProL *pSisRegProLPtrJSon);

const char *GeminiDatoRamaRegistroProLJSon(SiscomRegistroProL *pSisRegProLPtrJSon, const char *pchrPtrRutaJerarquica);

SiscomRegistroProL *GeminiListaRama(SiscomRegistroProL *pSisRegProLPtrJSon, const char *pchrPtrRutaJerarquica);

#endif


