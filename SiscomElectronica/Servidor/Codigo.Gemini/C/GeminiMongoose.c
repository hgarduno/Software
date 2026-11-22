#include <GeminiMongoose.h>
#include <GeminiSoporteSiscomDesarrollo4.h>
#include <GeminiPedidoWeb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

static void GeminiRespondeRegistroPedidoHttp(int pintSocket, int pintStatusCode, const char *pstrContentType, const char *pstrBody) {
    char lstrResponse[16384];
    int lintRespLen = snprintf(lstrResponse, sizeof(lstrResponse),
        "HTTP/1.1 %d OK\r\n"
        "Content-Type: %s\r\n"
        "Content-Length: %d\r\n"
        "Connection: close\r\n"
        "\r\n"
        "%s",
        pintStatusCode, pstrContentType, (int) strlen(pstrBody), pstrBody);

    send(pintSocket, lstrResponse, lintRespLen, 0);
}

/* Base para manejar la nueva especificacion de Pedidos */
static void GeminiRegistraPedidosHttp(struct mg_http_message *hm, int pintSocket) {
    if (hm->body.len > 0) {
        /*LogSiscom("Peticion JSON Recibida en /api/pedidos: %s",  hm->body.buf); */
	SiscomRegistroProL *lSisRegProLPtrRegreso=GeminiJSonASiscomRegistroProL(hm->body.buf);
	GeminiLogSiscomRegistroLJSon(lSisRegProLPtrRegreso);
	GeminiRegistraPedido(lSisRegProLPtrRegreso);

    } else {
        LogSiscom("Peticion JSON Recibida en /api/pedidos: (Cuerpo vacio)");
    }

    /* TODO: Implementar extraccion de JSON y logica de negocio segun especificacion */
    const char *lstrJsonResponse = "{\"codigo\":200,\"mensaje\":\"Base lista para API Pedidos\",\"datos\":{\"id_pedido\":\"PENDIENTE\"}}";
    GeminiRespondeRegistroPedidoHttp(pintSocket, 200, "application/json; charset=utf-8", lstrJsonResponse);
}

/* Arreglo global de rutas actualizado con el nuevo tipo de dato */
static zGeminiSiscomHttp gzRutasHttp[] = {
    { "/api/pedidos", GeminiRegistraPedidosHttp },
    { NULL, NULL }
};

int GeminiEsPeticionWeb(int pintSocket) {
    char lcharBuffer[1024];
    ssize_t lssizeBytesRead;
    struct mg_http_message lstructHttpMsg;
    int lintEsWeb = 0;

    LogSiscom("Verificando si el socket %d corresponde a una peticion web", pintSocket);

    lssizeBytesRead = recv(pintSocket, lcharBuffer, sizeof(lcharBuffer) - 1, MSG_PEEK);
    if (lssizeBytesRead > 0) {
        lcharBuffer[lssizeBytesRead] = '\0';
        if (mg_http_parse(lcharBuffer, (size_t) lssizeBytesRead, &lstructHttpMsg) > 0) {
            LogSiscom("Socket %d identificado como peticion web", pintSocket);
            lintEsWeb = 1;
        }
    }

    return lintEsWeb;
}

int GeminiProcesaClienteWeb(int pintSocket) {
    char lcharBuffer[4096];
    ssize_t lssizeBytesRead;
    struct mg_http_message lstructHttpMsg;
    int lintI = 0;
    int lintEncontrado = 0;

    LogSiscom("Iniciando procesamiento HTTP para socket %d", pintSocket);

    lssizeBytesRead = recv(pintSocket, lcharBuffer, sizeof(lcharBuffer) - 1, 0);
    if (lssizeBytesRead > 0) {
        lcharBuffer[lssizeBytesRead] = '\0';

        if (mg_http_parse(lcharBuffer, (size_t) lssizeBytesRead, &lstructHttpMsg) > 0) {
            while (gzRutasHttp[lintI].chrPtrRuta != NULL) {
                if (mg_match(lstructHttpMsg.uri, mg_str(gzRutasHttp[lintI].chrPtrRuta), NULL)) {
                    gzRutasHttp[lintI].fnOperacion(&lstructHttpMsg, pintSocket);
                    lintEncontrado = 1;
                    break;
                }
                lintI++;
            }

            if (!lintEncontrado) {
                const char *lstrError = "{\"codigo\":404,\"mensaje\":\"Endpoint no encontrado en Siscom API\"}";
                GeminiRespondeRegistroPedidoHttp(pintSocket, 404, "application/json; charset=utf-8", lstrError);
            }

            LogSiscom("Respuesta enviada exitosamente para socket %d", pintSocket);
        }
    }

    close(pintSocket);
    return 1;
}

