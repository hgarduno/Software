#ifndef GEMINI_MONGOOSE_H
#define GEMINI_MONGOOSE_H

#include <sys/socket.h>
#include <unistd.h>
#include <stdint.h>
#include "mongoose.h"
#include <SiscomDesarrolloMacros.h>

/* Definicion actualizada de la estructura y apuntador a funcion */
typedef void (*GeminiSiscomEntradaHttp)(struct mg_http_message *hm, int pintSocket);

typedef struct {
    const char *chrPtrRuta;
    GeminiSiscomEntradaHttp fnOperacion;
} zGeminiSiscomHttp;

int GeminiEsPeticionWeb(int pintSocket);
int GeminiProcesaClienteWeb(int pintSocket);

#endif /* GEMINI_MONGOOSE_H */