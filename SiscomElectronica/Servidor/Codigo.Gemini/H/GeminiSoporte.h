
#ifndef _GEMINI_SOPORTE_H
#define _GEMINI_SOPORTE_H
#include <SiscomDesarrolloMacros.h>
#include <SiscomProtocoloComunicaciones.h>

#define GeminiJSonLog(cadena, cveproducto) \
    GeminiJSonRespuestaALog(__FILE__, __FUNCTION__, __LINE__, cadena, cveproducto)

#define GeminiLogSiscomRegistroLJSon(pSiscomRegProLPtrJSon)\
GaminiRegistroProtocoloJSonLog(__FILE__, __FUNCTION__, __LINE__, pSiscomRegProLPtrJSon)

void GeminiRegistroCargaMasivaLog(SiscomRegistroProL *pSisRegProLPtrProductos);

void GeminiImprimeInsertSkuSql(SiscomRegistroProL *pSisRegProLPtrProducto);

void GeminiApikey(const char *pchrPtrRutaArchivo, char *pchrPtrApikey);
void GeminiUrl(const char *pchrPtrRutaArchivo, char *pchrPtrUrl);
void GeminiCargamasivaEspecificacion(const char *pchrPtrRutaArchivo, char **pchrPtrPtrEspec);
void GeminiCargaMasivaPrompt(const char *pchrPtrRutaArchivo, char **pchrPtrPtrPrompt);
void GeminiCargaImagenBase64(const char *pchrPtrArchivoImagen, char **pchrPtrPtrBase64);
void GeminiFiltraProductos(SiscomRegistroProL *pSisRegProLPtrProductos,
                            const char *pchrPtrFamilia,
                            SiscomRegistroProL **pSisRegProLPtrFiltradosPrim,
                            SiscomRegistroProL **pSisRegProLPtrFiltradosAct);
void GeminiImagenesProducto(const char *pchrPtrArchivo,
                            SiscomRegistroProL **pSisRegProLPtrImagenesPrim,
                            SiscomRegistroProL **pSisRegProLPtrImagenesAct);

const char *GeminiRegistroCveFamilia(const char **pchrPtrRegistro);
const char *GeminiRegistroPeso(const char **pchrPtrRegistro);
const char *GeminiRegistroFamilia(const char **pchrPtrRegistro);
const char *GeminiRegistroPrecioVenta(const char **pchrPtrRegistro);
const char *GeminiRegistroPrecio30Iva(const char **pchrPtrRegistro);
const char *GeminiRegistroPrecio40Iva(const char **pchrPtrRegistro);
const char *GeminiRegistroPrecio50Iva(const char **pchrPtrRegistro);

void GeminiJSonRespuestaALog(const char *pchrPtrArchivo,
                             const char *pchrPtrFuncion,
                             int pintLinea,
                             const char *pchrPtrRespuestaJson,
                             const char *pchrPtrCveProducto);

SiscomRegistroProL *GeminiJSonASiscomRegistroProL(const char *pchrPtrJsonStr);
void GaminiRegistroProtocoloJSonLog(const char *pchrPtrArchivo,
                                 const char *pchrPtrFuncion,
                                 int pintNoLinea,
                                 SiscomRegistroProL *pSisRegProLPtrJSon);

const char *GeminiDatoRamaRegistroProLJSon(SiscomRegistroProL *pSisRegProLPtrJSon, const char *pchrPtrRutaJerarquica);
SiscomRegistroProL *GeminiListaRama(SiscomRegistroProL *pSisRegProLPtrJSon, const char *pchrPtrRutaJerarquica);

void GeminiMuestraGeneralesRegresoProducto(SiscomRegistroProL *pSisRegProLPtrJSon);
void GeminiConsultaProductosSiscom(SiscomRegistroProL *pSisRegProLPtrJSon);
void GeminiActualizaDatosProductoRaiz(SiscomRegistroProL *pSisRegProLPtrProductoActual, SiscomRegistroProL *pSisRegProLPtrGeminiRespuesta);

void GeminiGeneraXlxs(SiscomRegistroProL *pSisRegProLPtrProductos, const char *pchrPtrArchivoSalida);

#endif



