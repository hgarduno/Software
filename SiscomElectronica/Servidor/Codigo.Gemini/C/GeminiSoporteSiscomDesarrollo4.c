#include <GeminiSoporteSiscomDesarrollo4.h>
#include <SiscomDesarrollo4.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <json-c/json.h>

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

typedef struct {
    SiscomRegistroProL *lista;
    SiscomRegistroProL *regAct;
    SiscomCampoProL *camAct;
    struct json_object *jsonContenedor;
    struct json_object *jsonRegAct;
    int esArreglo;
} StcGeminiPilaToJson;
/* ========================================================================= */

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

char *GeminiSiscomRegistroProLAJson(SiscomRegistroProL *pSisRegProLPtr)
{
    if (!pSisRegProLPtr)
    {
        return strdup("{}");
    }

    StcGeminiPilaToJson lPila[MAX_PILA_NIVELES];
    int lTop = 0;

    lPila[lTop].lista = pSisRegProLPtr;
    lPila[lTop].regAct = pSisRegProLPtr;
    lPila[lTop].camAct = pSisRegProLPtr->SiscomCamProLPtrDato;

    lPila[lTop].esArreglo = (pSisRegProLPtr->SiscomRegProLPtrSig != NULL) ? 1 : 0;
    if (!lPila[lTop].esArreglo && pSisRegProLPtr->SiscomCamProLPtrDato && pSisRegProLPtr->SiscomCamProLPtrDato->chrPtrNmbCampo && !strcmp(pSisRegProLPtr->SiscomCamProLPtrDato->chrPtrNmbCampo, "Valor"))
    {
        lPila[lTop].esArreglo = 1;
    }

    lPila[lTop].jsonContenedor = lPila[lTop].esArreglo ? json_object_new_array() : json_object_new_object();
    lPila[lTop].jsonRegAct = NULL;

    struct json_object *lJsonRoot = lPila[lTop].jsonContenedor;

    while (lTop >= 0)
    {
        StcGeminiPilaToJson *lFila = &lPila[lTop];

        if (lFila->regAct == NULL)
        {
            struct json_object *lContenedorTerminado = lFila->jsonContenedor;
            lTop--;

            if (lTop >= 0)
            {
                StcGeminiPilaToJson *lPadre = &lPila[lTop];
                const char *lchrNmbCampo = lPadre->camAct->chrPtrNmbCampo;
                struct json_object *lTarget = lPadre->jsonRegAct ? lPadre->jsonRegAct : lPadre->jsonContenedor;

                if (lPadre->esArreglo && (!lchrNmbCampo || !strcmp(lchrNmbCampo, "Valor")))
                {
                    json_object_array_add(lTarget, lContenedorTerminado);
                }
                else
                {
                    json_object_object_add(lTarget, lchrNmbCampo ? lchrNmbCampo : "Desconocido", lContenedorTerminado);
                }

                lPadre->camAct = lPadre->camAct->SiscomCamProLPtrSig;
            }
            continue;
        }

        if (lFila->camAct == NULL)
        {
            if (lFila->esArreglo && lFila->jsonRegAct)
            {
                json_object_array_add(lFila->jsonContenedor, lFila->jsonRegAct);
                lFila->jsonRegAct = NULL;
            }

            lFila->regAct = lFila->regAct->SiscomRegProLPtrSig;
            if (lFila->regAct)
            {
                lFila->camAct = lFila->regAct->SiscomCamProLPtrDato;
            }
            continue;
        }

        SiscomCampoProL *lCam = lFila->camAct;
        const char *lNmbCampo = lCam->chrPtrNmbCampo;

        if (lFila->esArreglo && lFila->jsonRegAct == NULL && (!lNmbCampo || strcmp(lNmbCampo, "Valor") != 0))
        {
            lFila->jsonRegAct = json_object_new_object();
        }

        struct json_object *lTarget = lFila->jsonRegAct ? lFila->jsonRegAct : lFila->jsonContenedor;

        if (lCam->vidPtrSubPrim)
        {
            if (lTop < MAX_PILA_NIVELES - 1)
            {
                int lNextTop = lTop + 1;
                SiscomRegistroProL *lSubLista = (SiscomRegistroProL *)lCam->vidPtrSubPrim;

                lPila[lNextTop].lista = lSubLista;
                lPila[lNextTop].regAct = lSubLista;
                lPila[lNextTop].camAct = lSubLista ? lSubLista->SiscomCamProLPtrDato : NULL;

                int lEsArrSub = (lSubLista && lSubLista->SiscomRegProLPtrSig != NULL) ? 1 : 0;
                if (!lEsArrSub && lSubLista && lSubLista->SiscomCamProLPtrDato && lSubLista->SiscomCamProLPtrDato->chrPtrNmbCampo && !strcmp(lSubLista->SiscomCamProLPtrDato->chrPtrNmbCampo, "Valor"))
                {
                    lEsArrSub = 1;
                }

                lPila[lNextTop].esArreglo = lEsArrSub;
                lPila[lNextTop].jsonContenedor = lEsArrSub ? json_object_new_array() : json_object_new_object();
                lPila[lNextTop].jsonRegAct = NULL;

                lTop = lNextTop;
            }
            else
            {
                lFila->camAct = lFila->camAct->SiscomCamProLPtrSig;
            }
            continue;
        }
        else
        {
            const char *lDato = lCam->chrPtrDato ? lCam->chrPtrDato : "";
            struct json_object *lValJson = json_object_new_string(lDato);

            if (lFila->esArreglo && (!lNmbCampo || !strcmp(lNmbCampo, "Valor")))
            {
                json_object_array_add(lTarget, lValJson);
            }
            else
            {
                json_object_object_add(lTarget, lNmbCampo ? lNmbCampo : "Desconocido", lValJson);
            }

            lFila->camAct = lFila->camAct->SiscomCamProLPtrSig;
        }
    }

    const char *lchrPtrJson = json_object_to_json_string_ext(lJsonRoot, JSON_C_TO_STRING_PRETTY);
    char *lchrPtrResultado = lchrPtrJson ? strdup(lchrPtrJson) : strdup("{}");
    json_object_put(lJsonRoot);

    return lchrPtrResultado;
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