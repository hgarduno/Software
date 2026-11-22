#include <GeminiSoporte.h>
#include <GeminiSoporteRegistroProductoCargaMasiva.h>
#include <SiscomDesarrollo4.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <json-c/json.h>
#include <xlsxwriter.h>

extern FILE *gPtrFleArchivoLog;

/* ========================================================================= */
/* Estructuras locales para evitar recursividad en procesamiento JSON y Logs */
/* ========================================================================= */
#define MAX_PILA_NIVELES 256

typedef struct {
    struct json_object *jsonObj;
    SiscomRegistroProL **ptrPrim;
    SiscomRegistroProL **ptrAct;
} StcGeminiPilaJson;

typedef struct {
    SiscomRegistroProL *registro;
    char nmbPadre[128];
} StcGeminiPilaLog;
/* ========================================================================= */

void GeminiRegistroCargaMasivaLog(SiscomRegistroProL *pSisRegProLPtrProductos)
{
    SiscomRegistroProL *lSisRegProLPtrAct = pSisRegProLPtrProductos;
    SiscomCampoProL *lSisCamProLAct;

    if (!pSisRegProLPtrProductos) return;

    /* Imprimir Encabezados Alineados */
    printf("%-20s | %-20s | %-35s | %-15s | %-15s | %-15s\n",
           "CveProducto", "Sku", "Nombre General", "Precio Venta", "Peso", "Num Imagenes");
   /* 
    lSisCamProLAct = pSisRegProLPtrProductos->SiscomCamProLPtrDato;
    while (lSisCamProLAct)
    {
        const char *lchrPtrNmbCampo = lSisCamProLAct->chrPtrNmbCampo ? lSisCamProLAct->chrPtrNmbCampo : "Desconocido";
        printf(" | %-20.20s", lchrPtrNmbCampo);
        lSisCamProLAct = lSisCamProLAct->SiscomCamProLPtrSig;
    }
    printf("\n");
*/
    /* Imprimir Filas de Datos */
    while (lSisRegProLPtrAct)
    {
        const char *lchrPtrCveProducto = CveProductoCM(lSisRegProLPtrAct);
        const char *lchrPtrSku = SkuCM(lSisRegProLPtrAct);
        const char *lchrPtrNombreGeneral = NombreGeneralCM(lSisRegProLPtrAct);
        const char *lchrPtrPrecioVenta = PrecioVentaCM(lSisRegProLPtrAct);
        const char *lchrPtrPeso = PesoCM(lSisRegProLPtrAct);

        int lintNumImagenes = 0;
        SiscomCampoProL *lSisCamImagenes = SiscomObtenCampoRegistroProL("Imagenes", lSisRegProLPtrAct);
        if (lSisCamImagenes && lSisCamImagenes->vidPtrSubPrim)
        {
            lintNumImagenes = ((SiscomRegistroProL *)lSisCamImagenes->vidPtrSubPrim)->intNRegistros;
        }

        if (!lchrPtrCveProducto) lchrPtrCveProducto = "Sin Informacion";
        if (!lchrPtrSku) lchrPtrSku = "Sin Informacion";
        if (!lchrPtrNombreGeneral) lchrPtrNombreGeneral = "Sin Informacion";
        if (!lchrPtrPrecioVenta) lchrPtrPrecioVenta = "Sin Informacion";
        if (!lchrPtrPeso) lchrPtrPeso = "Sin Informacion";

        printf("%-20.20s | %-20.20s | %-35.35s | %-15.15s | %-15.15s | %-15d\n",
               lchrPtrCveProducto,
               lchrPtrSku,
               lchrPtrNombreGeneral,
               lchrPtrPrecioVenta,
               lchrPtrPeso,
               lintNumImagenes);

        lSisRegProLPtrAct = lSisRegProLPtrAct->SiscomRegProLPtrSig;
    }
}

void GeminiImprimeInsertSkuSql(SiscomRegistroProL *pSisRegProLPtrProducto)
{
    const char *lchrPtrCveProducto = CveProductoCM(pSisRegProLPtrProducto);
    const char *lchrPtrSku = SkuCM(pSisRegProLPtrProducto);
    const char *lchrPtrGtin = GtinCM(pSisRegProLPtrProducto);

    if (!lchrPtrCveProducto) lchrPtrCveProducto = "";
    if (!lchrPtrSku) lchrPtrSku = "";
    if (!lchrPtrGtin) lchrPtrGtin = "";

    printf("INSERT INTO SKU(CveProducto, Sku, Gtin) VALUES('%s', '%s', '%s');\n",
           lchrPtrCveProducto,
           lchrPtrSku,
           lchrPtrGtin);
}

void GeminiApikey(const char *pchrPtrRutaArchivo, char *pchrPtrApikey)
{
    SiscomArchivoParaConfiguracion(pchrPtrRutaArchivo, pchrPtrApikey);
}

void GeminiUrl(const char *pchrPtrRutaArchivo, char *pchrPtrUrl)
{
    SiscomArchivoParaConfiguracion(pchrPtrRutaArchivo, pchrPtrUrl);
}

void GeminiCargamasivaEspecificacion(const char *pchrPtrRutaArchivo, char **pchrPtrPtrEspec)
{
    FILE *lptrFleArchivo = fopen(pchrPtrRutaArchivo, "rb");
    if (!lptrFleArchivo)
    {
        *pchrPtrPtrEspec = NULL;
        return;
    }

    fseek(lptrFleArchivo, 0, SEEK_END);
    long llSzArchivo = ftell(lptrFleArchivo);
    rewind(lptrFleArchivo);

    *pchrPtrPtrEspec = malloc(llSzArchivo + 1);
    if (!*pchrPtrPtrEspec)
    {
        fclose(lptrFleArchivo);
        return;
    }

    long llLeidos = fread(*pchrPtrPtrEspec, 1, llSzArchivo, lptrFleArchivo);
    (*pchrPtrPtrEspec)[llLeidos] = '\0';

    fclose(lptrFleArchivo);
}

void GeminiCargaMasivaPrompt(const char *pchrPtrRutaArchivo, char **pchrPtrPtrPrompt)
{
    FILE *lptrFleArchivo = fopen(pchrPtrRutaArchivo, "rb");
    if (!lptrFleArchivo)
    {
        *pchrPtrPtrPrompt = NULL;
        return;
    }

    fseek(lptrFleArchivo, 0, SEEK_END);
    long llSzArchivo = ftell(lptrFleArchivo);
    rewind(lptrFleArchivo);

    *pchrPtrPtrPrompt = malloc(llSzArchivo + 1);
    if (!*pchrPtrPtrPrompt)
    {
        fclose(lptrFleArchivo);
        return;
    }

    long llLeidos = fread(*pchrPtrPtrPrompt, 1, llSzArchivo, lptrFleArchivo);
    (*pchrPtrPtrPrompt)[llLeidos] = '\0';

    fclose(lptrFleArchivo);
}

void GeminiCargaImagenBase64(const char *pchrPtrArchivoImagen, char **pchrPtrPtrBase64)
{
    FILE *lptrFleArchivo = fopen(pchrPtrArchivoImagen, "rb");
    if (!lptrFleArchivo)
    {
        *pchrPtrPtrBase64 = NULL;
        return;
    }

    fseek(lptrFleArchivo, 0, SEEK_END);
    long llSzArchivo = ftell(lptrFleArchivo);
    rewind(lptrFleArchivo);

    unsigned char *lchrArrPtrBytes = malloc(llSzArchivo);
    if (!lchrArrPtrBytes)
    {
        fclose(lptrFleArchivo);
        *pchrPtrPtrBase64 = NULL;
        return;
    }

    long llLeidos = fread(lchrArrPtrBytes, 1, llSzArchivo, lptrFleArchivo);
    fclose(lptrFleArchivo);

    const char *lchrArrTablasBase64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    long llSzBase64 = 4 * ((llSzArchivo + 2) / 3);
    char *lchrPtrResultado = malloc(llSzBase64 + 1);
    if (!lchrPtrResultado)
    {
        free(lchrArrPtrBytes);
        *pchrPtrPtrBase64 = NULL;
        return;
    }

    long i = 0, j = 0;
    while (i < llLeidos)
    {
        uint32_t l_octeto_a = i < llLeidos ? (unsigned char)lchrArrPtrBytes[i++] : 0;
        uint32_t l_octeto_b = i < llLeidos ? (unsigned char)lchrArrPtrBytes[i++] : 0;
        uint32_t l_octeto_c = i < llLeidos ? (unsigned char)lchrArrPtrBytes[i++] : 0;

        uint32_t l_tripleta = (l_octeto_a << 0x10) + (l_octeto_b << 0x08) + l_octeto_c;

        lchrPtrResultado[j++] = lchrArrTablasBase64[(l_tripleta >> 18) & 0x3F];
        lchrPtrResultado[j++] = lchrArrTablasBase64[(l_tripleta >> 12) & 0x3F];
        lchrPtrResultado[j++] = i > llLeidos + 1 ? '=' : lchrArrTablasBase64[(l_tripleta >> 6) & 0x3F];
        lchrPtrResultado[j++] = i > llLeidos ? '=' : lchrArrTablasBase64[l_tripleta & 0x3F];
    }

    lchrPtrResultado[j] = '\0';
    free(lchrArrPtrBytes);
    *pchrPtrPtrBase64 = lchrPtrResultado;
}

void GeminiFiltraProductos(SiscomRegistroProL *pSisRegProLPtrProductos,
                            const char *pchrPtrFamilia,
                            SiscomRegistroProL **pSisRegProLPtrFiltradosPrim,
                            SiscomRegistroProL **pSisRegProLPtrFiltradosAct)
{
    *pSisRegProLPtrFiltradosPrim = 0;
    *pSisRegProLPtrFiltradosAct = 0;

    if (!pchrPtrFamilia)
        return;

    int lintFiltroImagenes = !strcmp(pchrPtrFamilia, "ConImagenes");
    int lintFiltroNombreGeneral = !strcmp(pchrPtrFamilia, "SinNombreGeneral");

    while (pSisRegProLPtrProductos)
    {
        int lintAgrega = 0;

        if (lintFiltroImagenes)
        {
            SiscomCampoProL *lSisCamImagenes = SiscomObtenCampoRegistroProL("Imagenes", pSisRegProLPtrProductos);
            if (lSisCamImagenes && lSisCamImagenes->vidPtrSubPrim)
            {
                if (((SiscomRegistroProL *)lSisCamImagenes->vidPtrSubPrim)->intNRegistros > 0)
                {
                    lintAgrega = 1;
                }
            }
        }
        else if (lintFiltroNombreGeneral)
        {
            const char *lchrPtrNombreGeneral = NombreGeneralCM(pSisRegProLPtrProductos);
	    LogSiscom("(%s)",lchrPtrNombreGeneral);
            if (lchrPtrNombreGeneral && lchrPtrNombreGeneral[0] != '\0')
            {
                lintAgrega = 1;
            }
        }
        else
        {
            if (!SiscomComparaCadenaCampoRegistroProL((char *)pchrPtrFamilia, 
                                                     "Categoria", 
                                                     pSisRegProLPtrProductos))
            {
                lintAgrega = 1;
            }
        }

        if (lintAgrega)
        {
            SiscomNodoRegistroPro(pSisRegProLPtrProductos->SiscomCamProLPtrDato,
                                  pSisRegProLPtrFiltradosPrim,
                                  pSisRegProLPtrFiltradosAct);
        }

        pSisRegProLPtrProductos = pSisRegProLPtrProductos->SiscomRegProLPtrSig;
    }
}

void GeminiImagenesProducto(const char *pchrPtrArchivo,
                            SiscomRegistroProL **pSisRegProLPtrImagenesPrim,
                            SiscomRegistroProL **pSisRegProLPtrImagenesAct)
{
    char lchrArrBuffer[512];
    SiscomAnexaRegistroPro(pSisRegProLPtrImagenesPrim,
                          pSisRegProLPtrImagenesAct,
                          lchrArrBuffer,
                          "Archivo,",
                          pchrPtrArchivo,
                          (const char *)0);
}

const char *GeminiRegistroCveFamilia(const char **pchrPtrRegistro)
{
    return *(pchrPtrRegistro + 0);
}

const char *GeminiRegistroPeso(const char **pchrPtrRegistro)
{
    return *(pchrPtrRegistro + 1);
}

const char *GeminiRegistroFamilia(const char **pchrPtrRegistro)
{
    return *(pchrPtrRegistro + 2);
}

const char *GeminiRegistroPrecioVenta(const char **pchrPtrRegistro)
{
    return *(pchrPtrRegistro + 3);
}

const char *GeminiRegistroPrecio30Iva(const char **pchrPtrRegistro)
{
    return *(pchrPtrRegistro + 5);
}

const char *GeminiRegistroPrecio40Iva(const char **pchrPtrRegistro)
{
    return *(pchrPtrRegistro + 6);
}

const char *GeminiRegistroPrecio50Iva(const char **pchrPtrRegistro)
{
    return *(pchrPtrRegistro + 7);
}

void GeminiJSonRespuestaALog(const char *pchrPtrArchivo,
                             const char *pchrPtrFuncion,
                             int pintLinea,
                             const char *pchrPtrRespuestaJson,
                             const char *pchrPtrCveProducto)
{
    if (!gPtrFleArchivoLog)
        return;

    fprintf(gPtrFleArchivoLog, "%-25s %-25s %-10d %-15s\n",
            pchrPtrArchivo ? pchrPtrArchivo : "",
            pchrPtrFuncion ? pchrPtrFuncion : "",
            pintLinea,
            pchrPtrCveProducto ? pchrPtrCveProducto : "");

    struct json_object *ljsonObjPtrParsed = json_tokener_parse(pchrPtrRespuestaJson);
    if (ljsonObjPtrParsed)
    {
        struct json_object *ljsonObjPtrUsage = NULL;
        int lintPromptTokens = 0, lintCandidatesTokens = 0, lintTotalTokens = 0;
        if (json_object_object_get_ex(ljsonObjPtrParsed, "usageMetadata", &ljsonObjPtrUsage))
        {
            struct json_object *ljsonObjTemp = NULL;
            if (json_object_object_get_ex(ljsonObjPtrUsage, "promptTokenCount", &ljsonObjTemp))
                lintPromptTokens = json_object_get_int(ljsonObjTemp);
            if (json_object_object_get_ex(ljsonObjPtrUsage, "candidatesTokenCount", &ljsonObjTemp))
                lintCandidatesTokens = json_object_get_int(ljsonObjTemp);
            if (json_object_object_get_ex(ljsonObjPtrUsage, "totalTokenCount", &ljsonObjTemp))
                lintTotalTokens = json_object_get_int(ljsonObjTemp);
        }

        fprintf(gPtrFleArchivoLog, "%-20s %-22s %-15s\n",
                "PromptTokens", "CandidatesTokens", "TotalTokens");
        fprintf(gPtrFleArchivoLog, "%-20d %-22d %-15d\n",
                lintPromptTokens, lintCandidatesTokens, lintTotalTokens);

        const char *lchrPtrModelVersion = "";
        struct json_object *ljsonObjModelVersion = NULL;
        if (json_object_object_get_ex(ljsonObjPtrParsed, "modelVersion", &ljsonObjModelVersion))
        {
            lchrPtrModelVersion = json_object_get_string(ljsonObjModelVersion);
        }

        struct json_object *ljsonObjPtrPromptFeedback = NULL;
        const char *lchrPtrPromptFeedbackStr = "NONE";
        if (json_object_object_get_ex(ljsonObjPtrParsed, "promptFeedback", &ljsonObjPtrPromptFeedback))
        {
            lchrPtrPromptFeedbackStr = "PRESENT";
        }

        fprintf(gPtrFleArchivoLog, "%-15s %-15s %-25s\n", "ModelVersion", "PromptFeedback", "FinishReason");

        struct json_object *ljsonObjPtrCandidates = NULL;
        if (json_object_object_get_ex(ljsonObjPtrParsed, "candidates", &ljsonObjPtrCandidates))
        {
            int larrLen = json_object_array_length(ljsonObjPtrCandidates);
            for (int i = 0; i < larrLen; i++)
            {
                struct json_object *ljsonObjCandidate = json_object_array_get_idx(ljsonObjPtrCandidates, i);
                const char *lchrPtrFinishReason = "";
                struct json_object *ljsonObjFinishReason = NULL;
                if (json_object_object_get_ex(ljsonObjCandidate, "finishReason", &ljsonObjFinishReason))
                {
                    lchrPtrFinishReason = json_object_get_string(ljsonObjFinishReason);
                }

                fprintf(gPtrFleArchivoLog, "%-15s %-15s %-25s\n", 
                        lchrPtrModelVersion ? lchrPtrModelVersion : "", 
                        lchrPtrPromptFeedbackStr, 
                        lchrPtrFinishReason ? lchrPtrFinishReason : "");

                struct json_object *ljsonObjSafetyRatings = NULL;
                if (json_object_object_get_ex(ljsonObjCandidate, "safetyRatings", &ljsonObjSafetyRatings))
                {
                    fprintf(gPtrFleArchivoLog, "  [SafetyRatings]\n");
                    int lsafetyLen = json_object_array_length(ljsonObjSafetyRatings);
                    for (int s = 0; s < lsafetyLen; s++)
                    {
                        struct json_object *ljsonObjRating = json_object_array_get_idx(ljsonObjSafetyRatings, s);
                        struct json_object *ljsonObjCategory = NULL, *ljsonObjProbability = NULL;
                        const char *lchrPtrCategory = "";
                        const char *lchrPtrProbability = "";
                        if (json_object_object_get_ex(ljsonObjRating, "category", &ljsonObjCategory))
                            lchrPtrCategory = json_object_get_string(ljsonObjCategory);
                        if (json_object_object_get_ex(ljsonObjRating, "probability", &ljsonObjProbability))
                            lchrPtrProbability = json_object_get_string(ljsonObjProbability);

                        fprintf(gPtrFleArchivoLog, "    %-30s : %s\n", lchrPtrCategory, lchrPtrProbability);
                    }
                }

                struct json_object *ljsonObjContent = NULL;
                if (json_object_object_get_ex(ljsonObjCandidate, "content", &ljsonObjContent))
                {
                    struct json_object *ljsonObjParts = NULL;
                    if (json_object_object_get_ex(ljsonObjContent, "parts", &ljsonObjParts))
                    {
                        int lpartsLen = json_object_array_length(ljsonObjParts);
                        for (int j = 0; j < lpartsLen; j++)
                        {
                            struct json_object *ljsonObjPart = json_object_array_get_idx(ljsonObjParts, j);
                            struct json_object *ljsonObjText = NULL;
                            if (json_object_object_get_ex(ljsonObjPart, "text", &ljsonObjText))
                            {
                                const char *lchrPtrText = json_object_get_string(ljsonObjText);
                                char *lchrPtrJsonLimpio = strdup(lchrPtrText);
                                char *lchrPtrInicio = strstr(lchrPtrJsonLimpio, "```json");
                                if (lchrPtrInicio)
                                {
                                    lchrPtrInicio += 7;
                                }
                                else
                                {
                                    lchrPtrInicio = strstr(lchrPtrJsonLimpio, "```");
                                    if (lchrPtrInicio) lchrPtrInicio += 3;
                                    else lchrPtrInicio = lchrPtrJsonLimpio;
                                }
                                char *lchrPtrFin = strstr(lchrPtrInicio, "```");
                                if (lchrPtrFin) *lchrPtrFin = '\0';

                                struct json_object *ljsonObjContenidoInterno = json_tokener_parse(lchrPtrInicio);
                                if (ljsonObjContenidoInterno)
                                {
                                    const char *lchrPtrPretty = json_object_to_json_string_ext(ljsonObjContenidoInterno, JSON_C_TO_STRING_PRETTY);
                                    if (lchrPtrPretty)
                                    {
                                        fprintf(gPtrFleArchivoLog, "%s\n", lchrPtrPretty);
                                    }
                                    json_object_put(ljsonObjContenidoInterno);
                                }
                                else
                                {
                                    fprintf(gPtrFleArchivoLog, "%s\n", lchrPtrInicio);
                                }
                                free(lchrPtrJsonLimpio);
                            }
                        }
                    }
                }
            }
        }
        else
        {
            const char *lchrPtrJsonStr = json_object_to_json_string_ext(ljsonObjPtrParsed, JSON_C_TO_STRING_PRETTY);
            if (lchrPtrJsonStr)
            {
                fprintf(gPtrFleArchivoLog, "%s\n", lchrPtrJsonStr);
            }
        }
        json_object_put(ljsonObjPtrParsed);
    }
    else
    {
        fprintf(gPtrFleArchivoLog, "%-20s %-22s %-15s\n",
                "PromptTokens", "CandidatesTokens", "TotalTokens");
        fprintf(gPtrFleArchivoLog, "%-20d %-22d %-15d\n", 0, 0, 0);
        fprintf(gPtrFleArchivoLog, "%s\n", pchrPtrRespuestaJson ? pchrPtrRespuestaJson : "(null)");
    }
    fflush(gPtrFleArchivoLog);
}

SiscomRegistroProL *GeminiJSonASiscomRegistroProL(const char *pchrPtrJsonStr)
{
    if (!pchrPtrJsonStr)
    {
        return NULL;
    }

    struct json_object *ljsonObjPtrParsed = json_tokener_parse(pchrPtrJsonStr);
    if (!ljsonObjPtrParsed)
    {
        return NULL;
    }

    SiscomRegistroProL *lSisRegProLPrim = NULL;
    SiscomRegistroProL *lSisRegProLAct = NULL;

    StcGeminiPilaJson lPila[MAX_PILA_NIVELES];
    int lTop = 0;

    lPila[lTop].jsonObj = ljsonObjPtrParsed;
    lPila[lTop].ptrPrim = &lSisRegProLPrim;
    lPila[lTop].ptrAct = &lSisRegProLAct;

    while (lTop >= 0)
    {
        struct json_object *lCurrentJson = lPila[lTop].jsonObj;
        SiscomRegistroProL **lCurPrim = lPila[lTop].ptrPrim;
        SiscomRegistroProL **lCurAct = lPila[lTop].ptrAct;
        lTop--;

        if (!lCurrentJson) continue;

        enum json_type ljsonType = json_object_get_type(lCurrentJson);

        if (ljsonType == json_type_array)
        {
            int larrLen = json_object_array_length(lCurrentJson);
            for (int i = 0; i < larrLen; i++)
            {
                struct json_object *ljsonObjItem = json_object_array_get_idx(lCurrentJson, i);
                if (ljsonObjItem)
                {
                    SiscomCampoProL *lSisCamProLPrim = NULL;
                    SiscomCampoProL *lSisCamProLAct = NULL;

                    enum json_type lItemType = json_object_get_type(ljsonObjItem);
                    
                    if (lItemType == json_type_object)
                    {
                        json_object_object_foreach(ljsonObjItem, lchrKey, ljsonVal)
                        {
                            const char *lchrValStr = "";
                            int lintEsAnidado = 0;
                            
                            if (ljsonVal)
                            {
                                enum json_type lType = json_object_get_type(ljsonVal);
                                if (lType == json_type_string) 
                                {
                                    lchrValStr = json_object_get_string(ljsonVal);
                                } 
                                else 
                                {
                                    lchrValStr = json_object_to_json_string(ljsonVal);
                                    if (lType == json_type_object || lType == json_type_array) 
                                        lintEsAnidado = 1;
                                }
                            }
                            
                            SiscomNodoCampoPro(lchrKey, lchrValStr, &lSisCamProLPrim, &lSisCamProLAct);
                            
                            if (lintEsAnidado && lTop < (MAX_PILA_NIVELES - 1))
                            {
                                lTop++;
                                lPila[lTop].jsonObj = ljsonVal;
                                lPila[lTop].ptrPrim = (SiscomRegistroProL **)&(lSisCamProLAct->vidPtrSubPrim);
                                lPila[lTop].ptrAct = (SiscomRegistroProL **)&(lSisCamProLAct->vidPtrSubAct);
                            }
                        }
                    }
                    else
                    {
                        const char *lchrValStr = "";
                        int lintEsAnidado = 0;
                        if (lItemType == json_type_string) 
                        {
                            lchrValStr = json_object_get_string(ljsonObjItem);
                        } 
                        else 
                        {
                            lchrValStr = json_object_to_json_string(ljsonObjItem);
                            if (lItemType == json_type_array) 
                                lintEsAnidado = 1;
                        }
                        
                        SiscomNodoCampoPro("Valor", lchrValStr, &lSisCamProLPrim, &lSisCamProLAct);
                        
                        if (lintEsAnidado && lTop < (MAX_PILA_NIVELES - 1))
                        {
                            lTop++;
                            lPila[lTop].jsonObj = ljsonObjItem;
                            lPila[lTop].ptrPrim = (SiscomRegistroProL **)&(lSisCamProLAct->vidPtrSubPrim);
                            lPila[lTop].ptrAct = (SiscomRegistroProL **)&(lSisCamProLAct->vidPtrSubAct);
                        }
                    }
                    
                    SiscomNodoRegistroPro(lSisCamProLPrim, lCurPrim, lCurAct);
                }
            }
        }
        else if (ljsonType == json_type_object)
        {
            SiscomCampoProL *lSisCamProLPrim = NULL;
            SiscomCampoProL *lSisCamProLAct = NULL;

            json_object_object_foreach(lCurrentJson, lchrKey, ljsonVal)
            {
                const char *lchrValStr = "";
                int lintEsAnidado = 0;

                if (ljsonVal)    
                {            
                    enum json_type lType = json_object_get_type(ljsonVal);
                    if (lType == json_type_string) 
                    {
                        lchrValStr = json_object_get_string(ljsonVal);
                    } 
                    else 
                    {
                        lchrValStr = json_object_to_json_string(ljsonVal);
                        if (lType == json_type_object || lType == json_type_array) 
                            lintEsAnidado = 1;
                    }
                }

                SiscomNodoCampoPro(lchrKey, lchrValStr, &lSisCamProLPrim, &lSisCamProLAct);
                
                if (lintEsAnidado && lTop < (MAX_PILA_NIVELES - 1))
                {
                    lTop++;
                    lPila[lTop].jsonObj = ljsonVal;
                    lPila[lTop].ptrPrim = (SiscomRegistroProL **)&(lSisCamProLAct->vidPtrSubPrim);
                    lPila[lTop].ptrAct = (SiscomRegistroProL **)&(lSisCamProLAct->vidPtrSubAct);
                }
            }
            
            SiscomNodoRegistroPro(lSisCamProLPrim, lCurPrim, lCurAct);
        }    
    }
    
    json_object_put(ljsonObjPtrParsed);
    return lSisRegProLPrim;
}

void GaminiRegistroProtocoloJSonLog(const char *pchrPtrArchivo,
                                     const char *pchrPtrFuncion,
                                     int pintNoLinea,
                                     SiscomRegistroProL *pSiscomRegProLPtrRegistro)
{
    if (!gPtrFleArchivoLog)
        return;

    fprintf(gPtrFleArchivoLog, "%-25s %-25s %-10d\n",
            pchrPtrArchivo ? pchrPtrArchivo : "",
            pchrPtrFuncion ? pchrPtrFuncion : "",
            pintNoLinea);

    if (!pSiscomRegProLPtrRegistro)
    {
        fprintf(gPtrFleArchivoLog, "Registro de protocolo NULL\n");
        fflush(gPtrFleArchivoLog);
        return;
    }

    StcGeminiPilaLog lPila[MAX_PILA_NIVELES];
    int lTop = 0;

    lPila[lTop].registro = pSiscomRegProLPtrRegistro;
    strncpy(lPila[lTop].nmbPadre, "RAIZ", 127);
    lPila[lTop].nmbPadre[127] = '\0';

    while (lTop >= 0)
    {
        SiscomRegistroProL *lSisRegAct = lPila[lTop].registro;
        char lchrNmbPadre[128];
        strncpy(lchrNmbPadre, lPila[lTop].nmbPadre, 128);
        lTop--;

        int lIntNumReg = 0;

        while (lSisRegAct)
        {
            fprintf(gPtrFleArchivoLog, "--- Registro [%d] [Anidado en: %s] ---\n", lIntNumReg++, lchrNmbPadre);
            SiscomCampoProL *lSisCamAct = lSisRegAct->SiscomCamProLPtrDato;
            
            while (lSisCamAct)
            {
                fprintf(gPtrFleArchivoLog, "    %-20s : %s\n",
                        lSisCamAct->chrPtrNmbCampo ? lSisCamAct->chrPtrNmbCampo : "",
                        lSisCamAct->chrPtrDato ? lSisCamAct->chrPtrDato : "");
                
                if (lSisCamAct->vidPtrSubPrim && lTop < (MAX_PILA_NIVELES - 1))
                {
                     lTop++;
                     lPila[lTop].registro = (SiscomRegistroProL *)lSisCamAct->vidPtrSubPrim;
                     strncpy(lPila[lTop].nmbPadre, lSisCamAct->chrPtrNmbCampo ? lSisCamAct->chrPtrNmbCampo : "DESCONOCIDO", 127);
                     lPila[lTop].nmbPadre[127] = '\0';
                }
                
                lSisCamAct = lSisCamAct->SiscomCamProLPtrSig;
            }
            lSisRegAct = lSisRegAct->SiscomRegProLPtrSig;
        }
    }
	
    fflush(gPtrFleArchivoLog);
}

const char *GeminiDatoRamaRegistroProLJSon(SiscomRegistroProL *pSisRegProLPtrJSon, const char *pchrPtrRutaJerarquica)
{
    if (!pSisRegProLPtrJSon || !pchrPtrRutaJerarquica)
    {
        return "";
    }

    char lchrArrRuta[1024];
    strncpy(lchrArrRuta, pchrPtrRutaJerarquica, sizeof(lchrArrRuta) - 1);
    lchrArrRuta[sizeof(lchrArrRuta) - 1] = '\0';

    char *lchrPtrToken = strtok(lchrArrRuta, "/");
    SiscomRegistroProL *lSisRegProLAct = pSisRegProLPtrJSon;
    
    while (lchrPtrToken && lSisRegProLAct)
    {
        size_t lSztLen = strlen(lchrPtrToken);
        if (lSztLen >= 3 && lchrPtrToken[0] == '[' && lchrPtrToken[lSztLen - 1] == ']') 
        {
            int lintIndice = atoi(lchrPtrToken + 1);
            int lIntContador = 0;
            
            while (lSisRegProLAct && lIntContador < lintIndice) 
            {
                lSisRegProLAct = lSisRegProLAct->SiscomRegProLPtrSig;
                lIntContador++;
            }
            
            if (!lSisRegProLAct)
            {
                return ""; 
            }
            
            lchrPtrToken = strtok(NULL, "/");
            
            if (!lchrPtrToken)
            {
                SiscomCampoProL *lSisCam = lSisRegProLAct->SiscomCamProLPtrDato;
                while (lSisCam)
                {
                    if (lSisCam->chrPtrNmbCampo && !strcmp(lSisCam->chrPtrNmbCampo, "Valor"))
                    {
                        return lSisCam->chrPtrDato ? lSisCam->chrPtrDato : "";
                    }
                    lSisCam = lSisCam->SiscomCamProLPtrSig;
                }
                
                if (lSisRegProLAct->SiscomCamProLPtrDato)
                {
                    return lSisRegProLAct->SiscomCamProLPtrDato->chrPtrDato ? lSisRegProLAct->SiscomCamProLPtrDato->chrPtrDato : "";
                }
                
                return "";
            }
            continue;
        }

        SiscomCampoProL *lSisCamProLAct = lSisRegProLAct->SiscomCamProLPtrDato;
        int lintEncontrado = 0;

        while (lSisCamProLAct)
        {
            if (lSisCamProLAct->chrPtrNmbCampo && !strcmp(lSisCamProLAct->chrPtrNmbCampo, lchrPtrToken))
            {
                lintEncontrado = 1;
                lchrPtrToken = strtok(NULL, "/");
                
                if (lchrPtrToken) 
                {
                    lSisRegProLAct = (SiscomRegistroProL *)lSisCamProLAct->vidPtrSubPrim;
                } 
                else 
                {
                    return lSisCamProLAct->chrPtrDato ? lSisCamProLAct->chrPtrDato : "";
                }
                break;
            }
            lSisCamProLAct = lSisCamProLAct->SiscomCamProLPtrSig;
        }

        if (!lintEncontrado)
        {
            return "";
        }
    }

    return "";
}

SiscomRegistroProL *GeminiListaRama(SiscomRegistroProL *pSisRegProLPtrJSon, const char *pchrPtrRutaJerarquica)
{
    if (!pSisRegProLPtrJSon || !pchrPtrRutaJerarquica)
    {
        return NULL;
    }

    char lchrArrRuta[1024];
    strncpy(lchrArrRuta, pchrPtrRutaJerarquica, sizeof(lchrArrRuta) - 1);
    lchrArrRuta[sizeof(lchrArrRuta) - 1] = '\0';

    char *lchrPtrToken = strtok(lchrArrRuta, "/");
    SiscomRegistroProL *lSisRegProLAct = pSisRegProLPtrJSon;
    
    while (lchrPtrToken && lSisRegProLAct)
    {
        size_t lSztLen = strlen(lchrPtrToken);
        if (lSztLen >= 3 && lchrPtrToken[0] == '[' && lchrPtrToken[lSztLen - 1] == ']') 
        {
            int lintIndice = atoi(lchrPtrToken + 1);
            int lIntContador = 0;
            
            while (lSisRegProLAct && lIntContador < lintIndice) 
            {
                lSisRegProLAct = lSisRegProLAct->SiscomRegProLPtrSig;
                lIntContador++;
            }
            
            if (!lSisRegProLAct)
            {
                return NULL; 
            }
            
            lchrPtrToken = strtok(NULL, "/");
            
            if (!lchrPtrToken)
            {
                return lSisRegProLAct;
            }
            continue;
        }

        SiscomCampoProL *lSisCamProLAct = lSisRegProLAct->SiscomCamProLPtrDato;
        int lintEncontrado = 0;

        while (lSisCamProLAct)
        {
            if (lSisCamProLAct->chrPtrNmbCampo && !strcmp(lSisCamProLAct->chrPtrNmbCampo, lchrPtrToken))
            {
                lintEncontrado = 1;
                lchrPtrToken = strtok(NULL, "/");
                
                if (lchrPtrToken) 
                {
                    lSisRegProLAct = (SiscomRegistroProL *)lSisCamProLAct->vidPtrSubPrim;
                } 
                else 
                {
                    return (SiscomRegistroProL *)lSisCamProLAct->vidPtrSubPrim;
                }
                break;
            }
            lSisCamProLAct = lSisCamProLAct->SiscomCamProLPtrSig;
        }

        if (!lintEncontrado)
        {
            return NULL;
        }
    }

    return NULL;
}

void GeminiMuestraGeneralesRegresoProducto(SiscomRegistroProL *pSisRegProLPtrJSon)
{
    const char *lchrPtrNombreGen;
    const char *lchrPtrDescripcion;
    const char *lchrPtrSlogan;
    const char *lchrPtrMarca;

    if (!gPtrFleArchivoLog)
        return;

    lchrPtrNombreGen = GeminiDatoRamaRegistroProLJSon(pSisRegProLPtrJSon, "nombre_general");
    lchrPtrDescripcion = GeminiDatoRamaRegistroProLJSon(pSisRegProLPtrJSon, "descripcion");
    lchrPtrSlogan = GeminiDatoRamaRegistroProLJSon(pSisRegProLPtrJSon, "slogan");
    lchrPtrMarca = GeminiDatoRamaRegistroProLJSon(pSisRegProLPtrJSon, "marca");

    fprintf(gPtrFleArchivoLog, "Nombre General : %s\n", lchrPtrNombreGen ? lchrPtrNombreGen : "");
    fprintf(gPtrFleArchivoLog, "Descripcion    : %s\n", lchrPtrDescripcion ? lchrPtrDescripcion : "");
    fprintf(gPtrFleArchivoLog, "Slogan         : %s\n", lchrPtrSlogan ? lchrPtrSlogan : "");
    fprintf(gPtrFleArchivoLog, "Marca          : %s\n", lchrPtrMarca ? lchrPtrMarca : "");
    fflush(gPtrFleArchivoLog);
}

static void GeminiLimpiaComillas(const char *pchrPtrOrigen, char *pchrPtrDestino, size_t psztMax)
{
    if (!pchrPtrOrigen || psztMax == 0)
    {
        if (psztMax > 0) pchrPtrDestino[0] = '\0';
        return;
    }
    size_t i = 0, j = 0;
    while (pchrPtrOrigen[i] && j < (psztMax - 1))
    {
        if (pchrPtrOrigen[i] != '"')
        {
            if (pchrPtrOrigen[i] == '\n' || pchrPtrOrigen[i] == '\r') 
            {
                if (j == 0 || pchrPtrDestino[j-1] != ' ') {
                    pchrPtrDestino[j++] = ' ';
                }
            } 
            else 
            {
                pchrPtrDestino[j++] = pchrPtrOrigen[i];
            }
        }
        i++;
    }
    pchrPtrDestino[j] = '\0';
}

static void GeminiFormateaDatoAnidado(SiscomRegistroProL *pSisRegProLPtrJSon, const char *pchrPtrRama, char *pchrPtrBuffer, size_t psztMaxBuffer)
{
    SiscomRegistroProL *lSisRegRama;
    char lchrArrTempResult[4096];
    
    lchrArrTempResult[0] = '\0';
    pchrPtrBuffer[0] = '\0';
    lSisRegRama = GeminiListaRama(pSisRegProLPtrJSon, pchrPtrRama);
    
    if (lSisRegRama)
    {
        while (lSisRegRama)
        {
            SiscomCampoProL *lSisCam = lSisRegRama->SiscomCamProLPtrDato;
            while (lSisCam)
            {
                char lchrTemp[1024];
                char lchrNmbLimpio[256];
                char lchrDatoLimpio[768];
                
                GeminiLimpiaComillas(lSisCam->chrPtrNmbCampo ? lSisCam->chrPtrNmbCampo : "", lchrNmbLimpio, sizeof(lchrNmbLimpio));
                GeminiLimpiaComillas(lSisCam->chrPtrDato ? lSisCam->chrPtrDato : "", lchrDatoLimpio, sizeof(lchrDatoLimpio));
                
                snprintf(lchrTemp, sizeof(lchrTemp), "%s : %s | ", lchrNmbLimpio, lchrDatoLimpio);
                
                if (strlen(lchrArrTempResult) + strlen(lchrTemp) < sizeof(lchrArrTempResult))
                {
                    strcat(lchrArrTempResult, lchrTemp);
                }
                lSisCam = lSisCam->SiscomCamProLPtrSig;
            }
            lSisRegRama = lSisRegRama->SiscomRegProLPtrSig;
        }
        
        size_t lSztLen = strlen(lchrArrTempResult);
        if (lSztLen >= 3 && lchrArrTempResult[lSztLen - 1] == ' ' && lchrArrTempResult[lSztLen - 2] == '|' && lchrArrTempResult[lSztLen - 3] == ' ')
        {
            lchrArrTempResult[lSztLen - 3] = '\0';
        }
    }
    else
    {
        const char *lchrPtrValor = GeminiDatoRamaRegistroProLJSon(pSisRegProLPtrJSon, pchrPtrRama);
        if (lchrPtrValor)
        {
            GeminiLimpiaComillas(lchrPtrValor, lchrArrTempResult, sizeof(lchrArrTempResult));
        }
    }

    if (lchrArrTempResult[0] != '\0')
    {
        snprintf(pchrPtrBuffer, psztMaxBuffer, "\"%s\"", lchrArrTempResult);
    }
}

static void GeminiFormateaDatoSimpleCSV(const char *pchrPtrOrigen, char *pchrPtrDestino, size_t psztMaxBuffer)
{
    if (!pchrPtrOrigen || psztMaxBuffer == 0)
    {
        if (psztMaxBuffer > 0) pchrPtrDestino[0] = '\0';
        return;
    }

    char lchrArrTemp[4096];
    size_t i = 0, j = 0;
    
    while (pchrPtrOrigen[i] && j < (sizeof(lchrArrTemp) - 1))
    {
        if (pchrPtrOrigen[i] != '"')
        {
            if (pchrPtrOrigen[i] == '\n' || pchrPtrOrigen[i] == '\r')
            {
                if (j == 0 || lchrArrTemp[j - 1] != ' ')
                {
                    lchrArrTemp[j++] = ' ';
                }
            }
            else
            {
                lchrArrTemp[j++] = pchrPtrOrigen[i];
            }
        }
        i++;
    }
    lchrArrTemp[j] = '\0';

    if (lchrArrTemp[0] != '\0')
    {
        snprintf(pchrPtrDestino, psztMaxBuffer, "\"%s\"", lchrArrTemp);
    }
    else
    {
        pchrPtrDestino[0] = '\0';
    }
}

void GeminiActualizaDatosProductoRaiz(SiscomRegistroProL *pSisRegProLPtrProductoActual, SiscomRegistroProL *pSisRegProLPtrGeminiRespuesta)
{
    char lchrArrParametrosPrincipales[4096];
    char lchrArrEspecificacionesTecnicas[4096];
    char lchrArrRecomendaciones[4096];

    char lchrArrNombreGeneral[1024];
    char lchrArrDescripcion[4096];
    char lchrArrSlogan[1024];
    char lchrArrMarca[256];

    const char *lchrPtrNombreGeneral;
    const char *lchrPtrDescripcion;
    const char *lchrPtrSlogan;
    const char *lchrPtrMarca;

    if (!pSisRegProLPtrProductoActual || !pSisRegProLPtrGeminiRespuesta)
    {
        return;
    }

    lchrPtrNombreGeneral = GeminiDatoRamaRegistroProLJSon(pSisRegProLPtrGeminiRespuesta, "nombre_general");
    lchrPtrDescripcion = GeminiDatoRamaRegistroProLJSon(pSisRegProLPtrGeminiRespuesta, "descripcion");
    lchrPtrSlogan = GeminiDatoRamaRegistroProLJSon(pSisRegProLPtrGeminiRespuesta, "slogan");
    lchrPtrMarca = GeminiDatoRamaRegistroProLJSon(pSisRegProLPtrGeminiRespuesta, "marca");

    GeminiFormateaDatoSimpleCSV(lchrPtrNombreGeneral, lchrArrNombreGeneral, sizeof(lchrArrNombreGeneral));
    GeminiFormateaDatoSimpleCSV(lchrPtrDescripcion, lchrArrDescripcion, sizeof(lchrArrDescripcion));
    GeminiFormateaDatoSimpleCSV(lchrPtrSlogan, lchrArrSlogan, sizeof(lchrArrSlogan));
    GeminiFormateaDatoSimpleCSV(lchrPtrMarca, lchrArrMarca, sizeof(lchrArrMarca));

    GeminiFormateaDatoAnidado(pSisRegProLPtrGeminiRespuesta, "parametros_principales", lchrArrParametrosPrincipales, sizeof(lchrArrParametrosPrincipales));
    GeminiFormateaDatoAnidado(pSisRegProLPtrGeminiRespuesta, "especificaciones_tecnicas", lchrArrEspecificacionesTecnicas, sizeof(lchrArrEspecificacionesTecnicas));
    GeminiFormateaDatoAnidado(pSisRegProLPtrGeminiRespuesta, "recomendaciones", lchrArrRecomendaciones, sizeof(lchrArrRecomendaciones));

    if (lchrArrNombreGeneral[0] != '\0')
    {
        NombreGeneralAsigna(pSisRegProLPtrProductoActual, lchrArrNombreGeneral);
    }
    
    if (lchrArrDescripcion[0] != '\0')
    {
        DescripcionAsigna(pSisRegProLPtrProductoActual, lchrArrDescripcion);
    }
    
    if (lchrArrSlogan[0] != '\0')
    {
        SubtituloAsigna(pSisRegProLPtrProductoActual, lchrArrSlogan);
    }
    
    if (lchrArrMarca[0] != '\0')
    {
        MarcaAsigna(pSisRegProLPtrProductoActual, lchrArrMarca);
    }

    if (lchrArrParametrosPrincipales[0] != '\0')
    {
        ParametrosPrincipalesAsigna(pSisRegProLPtrProductoActual, lchrArrParametrosPrincipales);
    }

    if (lchrArrEspecificacionesTecnicas[0] != '\0')
    {
        EspecificacionesTecnicasAsigna(pSisRegProLPtrProductoActual, lchrArrEspecificacionesTecnicas);
    }

    if (lchrArrRecomendaciones[0] != '\0')
    {
        RecomendacionesAsigna(pSisRegProLPtrProductoActual, lchrArrRecomendaciones);
    }
}

static void GeminiEscribeCeldaSinComillas(lxw_worksheet *pWorksheet, int pintFila, int pintCol, const char *pchrPtrDato)
{
    if (!pchrPtrDato)
    {
        worksheet_write_string(pWorksheet, pintFila, pintCol, "", NULL);
        return;
    }

    size_t lSztLen = strlen(pchrPtrDato);
    if (lSztLen >= 2 && pchrPtrDato[0] == '"' && pchrPtrDato[lSztLen - 1] == '"')
    {
        char lchrArrBuffer[8192];
        size_t lSztCopia = lSztLen - 2;
        if (lSztCopia >= sizeof(lchrArrBuffer))
        {
            lSztCopia = sizeof(lchrArrBuffer) - 1;
        }
        strncpy(lchrArrBuffer, pchrPtrDato + 1, lSztCopia);
        lchrArrBuffer[lSztCopia] = '\0';
        worksheet_write_string(pWorksheet, pintFila, pintCol, lchrArrBuffer, NULL);
    }
    else
    {
        worksheet_write_string(pWorksheet, pintFila, pintCol, pchrPtrDato, NULL);
    }
}

void GeminiGeneraXlxs(SiscomRegistroProL *pSisRegProLPtrProductos, const char *pchrPtrArchivoSalida)
{
    int lintContadorProd = 0;

    if (!pchrPtrArchivoSalida || !pchrPtrArchivoSalida[0])
    {
        printf("Error: Archivo de salida xlsx no especificado.\n");
        if (gPtrFleArchivoLog)
        {
            fprintf(gPtrFleArchivoLog, "[GeminiGeneraXlxs] ERROR: Archivo de salida xlsx no especificado.\n");
            fflush(gPtrFleArchivoLog);
        }
        return;
    }

    if (gPtrFleArchivoLog)
    {
        fprintf(gPtrFleArchivoLog, "============================================================\n");
        fprintf(gPtrFleArchivoLog, "[GeminiGeneraXlxs] Inicio de generacion XLSX: %s\n", pchrPtrArchivoSalida);
        fprintf(gPtrFleArchivoLog, "============================================================\n");
        fflush(gPtrFleArchivoLog);
    }

    lxw_workbook  *lptrWorkbook  = workbook_new(pchrPtrArchivoSalida);
    lxw_worksheet *lptrWorksheet = workbook_add_worksheet(lptrWorkbook, NULL);
   /* 
    worksheet_freeze_panes(lptrWorksheet, 1, 3);
    */
    
    int lintFila = 0;
    worksheet_write_string(lptrWorksheet, lintFila, 0, "CveProducto", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 1, "Sku", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 2, "Gtin", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 3, "NombreGeneral", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 4, "Descripcion", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 5, "Categoria", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 6, "Marca", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 7, "UnidadMedida", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 8, "PrecioVenta", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 9, "Presentacion", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 10, "RequiereSerie", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 11, "RequiereLote", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 12, "RequiereCaducidad", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 13, "Subtitulo", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 14, "ParametrosPrincipales", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 15, "EspecificacionesTecnicas", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 16, "Recomendaciones", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 17, "Peso", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 18, "Largo", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 19, "Ancho", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 20, "Alto", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 21, "FamiliaDescuento", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 22, "FamPoliticasInventario", NULL);
    worksheet_write_string(lptrWorksheet, lintFila, 23, "SkusProveedores", NULL);

    lintFila++;

    while (pSisRegProLPtrProductos)
    {
        lintContadorProd++;

        const char *lchrPtrCveProducto = CveProductoCM(pSisRegProLPtrProductos);
        const char *lchrPtrSku = SkuCM(pSisRegProLPtrProductos);
        const char *lchrPtrGtin = GtinCM(pSisRegProLPtrProductos);
        const char *lchrPtrNombreGen = NombreGeneralCM(pSisRegProLPtrProductos);
        const char *lchrPtrDesc = DescripcionCM(pSisRegProLPtrProductos);
        const char *lchrPtrCat = CategoriaCM(pSisRegProLPtrProductos);
        const char *lchrPtrMarca = MarcaCM(pSisRegProLPtrProductos);
        const char *lchrPtrUnidad = UnidadMedidaCM(pSisRegProLPtrProductos);
        const char *lchrPtrPrecio = PrecioVentaCM(pSisRegProLPtrProductos);
        const char *lchrPtrPresentacion = PresentacionCM(pSisRegProLPtrProductos);
        const char *lchrPtrReqSerie = RequiereSerieCM(pSisRegProLPtrProductos);
        const char *lchrPtrReqLote = RequiereLoteCM(pSisRegProLPtrProductos);
        const char *lchrPtrReqCaducidad = RequiereCaducidadCM(pSisRegProLPtrProductos);
        const char *lchrPtrSubtitulo = SubtituloCM(pSisRegProLPtrProductos);
        const char *lchrPtrParamPrinc = ParametrosPrincipalesCM(pSisRegProLPtrProductos);
        const char *lchrPtrEspecTec = EspecificacionesTecnicasCM(pSisRegProLPtrProductos);
        const char *lchrPtrRecomendaciones = RecomendacionesCM(pSisRegProLPtrProductos);
        const char *lchrPtrPeso = PesoCM(pSisRegProLPtrProductos);
        const char *lchrPtrLargo = LargoCM(pSisRegProLPtrProductos);
        const char *lchrPtrAncho = AnchoCM(pSisRegProLPtrProductos);
        const char *lchrPtrAlto = AltoCM(pSisRegProLPtrProductos);
        const char *lchrPtrFamDesc = FamiliaDescuentoCM(pSisRegProLPtrProductos);
        const char *lchrPtrFamPolInv = FamPoliticasInventarioCM(pSisRegProLPtrProductos);
        const char *lchrPtrSkusProv = SkusProveedoresCM(pSisRegProLPtrProductos);

        if (gPtrFleArchivoLog)
        {
            fprintf(gPtrFleArchivoLog, "--- [GeminiGeneraXlxs] Producto #%d (Fila Excel: %d) ---\n", lintContadorProd, lintFila);
            
            /* DUMP RAW DEL REGISTRO PARA DEPURACION DE CAMPOS FALTANTES */
            fprintf(gPtrFleArchivoLog, "  >>> INICIO DUMP RAW DE CAMPOS EN EL REGISTRO <<<\n");
            SiscomCampoProL *lSisCamDbg = pSisRegProLPtrProductos->SiscomCamProLPtrDato;
            while (lSisCamDbg)
            {
                fprintf(gPtrFleArchivoLog, "    Campo: '%-25s' | Dato: '%s'\n", 
                        lSisCamDbg->chrPtrNmbCampo ? lSisCamDbg->chrPtrNmbCampo : "(NULL)",
                        lSisCamDbg->chrPtrDato ? lSisCamDbg->chrPtrDato : "(NULL)");
                lSisCamDbg = lSisCamDbg->SiscomCamProLPtrSig;
            }
            fprintf(gPtrFleArchivoLog, "  >>> FIN DUMP RAW DE CAMPOS EN EL REGISTRO <<<\n\n");

            fprintf(gPtrFleArchivoLog, "  [Col 00] CveProducto           : %s\n", lchrPtrCveProducto ? lchrPtrCveProducto : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 01] Sku                   : %s\n", lchrPtrSku ? lchrPtrSku : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 02] Gtin                  : %s\n", lchrPtrGtin ? lchrPtrGtin : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 03] NombreGeneral         : %s\n", lchrPtrNombreGen ? lchrPtrNombreGen : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 04] Descripcion           : %s\n", lchrPtrDesc ? lchrPtrDesc : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 05] Categoria             : %s\n", lchrPtrCat ? lchrPtrCat : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 06] Marca                 : %s\n", lchrPtrMarca ? lchrPtrMarca : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 07] UnidadMedida          : %s\n", lchrPtrUnidad ? lchrPtrUnidad : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 08] PrecioVenta           : %s\n", lchrPtrPrecio ? lchrPtrPrecio : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 09] Presentacion          : %s\n", lchrPtrPresentacion ? lchrPtrPresentacion : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 10] RequiereSerie         : %s\n", lchrPtrReqSerie ? lchrPtrReqSerie : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 11] RequiereLote          : %s\n", lchrPtrReqLote ? lchrPtrReqLote : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 12] RequiereCaducidad     : %s\n", lchrPtrReqCaducidad ? lchrPtrReqCaducidad : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 13] Subtitulo             : %s\n", lchrPtrSubtitulo ? lchrPtrSubtitulo : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 14] ParametrosPrincipales : %s\n", lchrPtrParamPrinc ? lchrPtrParamPrinc : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 15] EspecificacionesTecnicas: %s\n", lchrPtrEspecTec ? lchrPtrEspecTec : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 16] Recomendaciones       : %s\n", lchrPtrRecomendaciones ? lchrPtrRecomendaciones : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 17] Peso                  : %s\n", lchrPtrPeso ? lchrPtrPeso : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 18] Largo                 : %s\n", lchrPtrLargo ? lchrPtrLargo : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 19] Ancho                 : %s\n", lchrPtrAncho ? lchrPtrAncho : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 20] Alto                  : %s\n", lchrPtrAlto ? lchrPtrAlto : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 21] FamiliaDescuento      : %s\n", lchrPtrFamDesc ? lchrPtrFamDesc : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 22] FamPoliticasInventario: %s\n", lchrPtrFamPolInv ? lchrPtrFamPolInv : "(NULL)");
            fprintf(gPtrFleArchivoLog, "  [Col 23] SkusProveedores       : %s\n", lchrPtrSkusProv ? lchrPtrSkusProv : "(NULL)");
            fflush(gPtrFleArchivoLog);
        }

        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 0, lchrPtrCveProducto);
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 1, lchrPtrSku);
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 2, lchrPtrGtin);
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 3, lchrPtrNombreGen ? lchrPtrNombreGen : "");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 4, lchrPtrDesc ? lchrPtrDesc : "");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 5, lchrPtrCat ? lchrPtrCat : "");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 6, lchrPtrMarca ? lchrPtrMarca : "");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 7, lchrPtrUnidad ? lchrPtrUnidad : "");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 8, lchrPtrPrecio ? lchrPtrPrecio : "0.00");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 9, lchrPtrPresentacion ? lchrPtrPresentacion : "");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 10, lchrPtrReqSerie ? lchrPtrReqSerie : "0");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 11, lchrPtrReqLote ? lchrPtrReqLote : "0");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 12, lchrPtrReqCaducidad ? lchrPtrReqCaducidad : "0");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 13, lchrPtrSubtitulo ? lchrPtrSubtitulo : "");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 14, lchrPtrParamPrinc ? lchrPtrParamPrinc : "");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 15, lchrPtrEspecTec ? lchrPtrEspecTec : "");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 16, lchrPtrRecomendaciones ? lchrPtrRecomendaciones : "");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 17, lchrPtrPeso ? lchrPtrPeso : "0.00");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 18, lchrPtrLargo ? lchrPtrLargo : "0.00");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 19, lchrPtrAncho ? lchrPtrAncho : "0.00");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 20, lchrPtrAlto ? lchrPtrAlto : "0.00");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 21, lchrPtrFamDesc ? lchrPtrFamDesc : "");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 22, lchrPtrFamPolInv ? lchrPtrFamPolInv : "");
        GeminiEscribeCeldaSinComillas(lptrWorksheet, lintFila, 23, lchrPtrSkusProv ? lchrPtrSkusProv : "");

        lintFila++;
        pSisRegProLPtrProductos = pSisRegProLPtrProductos->SiscomRegProLPtrSig;
    }

    workbook_close(lptrWorkbook);

    if (gPtrFleArchivoLog)
    {
        fprintf(gPtrFleArchivoLog, "============================================================\n");
        fprintf(gPtrFleArchivoLog, "[GeminiGeneraXlxs] Fin de generacion XLSX. Total productos procesados: %d\n", lintContadorProd);
        fprintf(gPtrFleArchivoLog, "============================================================\n");
        fflush(gPtrFleArchivoLog);
    }
}
