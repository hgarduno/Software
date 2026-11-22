
/* 
 * Correccion de errores de compilacion: Se ha ajustado el orden de los parametros 
 * al invocar SiscomObtenCampoRegistroProLChar y SiscomObtenRegistrosCampoProL 
 * pasando primero el nombre del campo (const char *) y despues el apuntador al 
 * registro (SiscomRegistroProL *), respetando la firma del framework.
 * 
 * Actualizacion: Se elimino la declaracion explicita de SiscomRegistroProtocoloLog
 * ya que es una macro definida en SiscomDesarrolloMacros.h y causaba error de sintaxis 
 * al expandirse en el prototipo.
 */

#include <GeminiPedidoWeb.h>

/* Funciones auxiliares para imprimir recursivamente en el log de SiscomDesarrollo4 */
static void GeminiSiscomImprimeIndentacion(int pintNivel)
{
    int lintI;
    for(lintI = 0; lintI < pintNivel; lintI++)
    {
        fprintf(gPtrFleArchivoLog, "  ");
    }
}

static void GeminiSiscomImprimeEstructuraPrompt(SiscomRegistroProL *pSiscomRegProL, int pintNivel)
{
    SiscomRegistroProL *lSiscomRegProL = pSiscomRegProL;
    SiscomCampoProL *lSiscomCampoProL;
    int lintNodo = 0;

    while(lSiscomRegProL)
    {
        GeminiSiscomImprimeIndentacion(pintNivel);
        fprintf(gPtrFleArchivoLog, "- Nodo [%d]:\n", lintNodo++);
        
        lSiscomCampoProL = lSiscomRegProL->SiscomCamProLPtrDato;
        while(lSiscomCampoProL)
        {
            GeminiSiscomImprimeIndentacion(pintNivel + 1);
            if(lSiscomCampoProL->chrPtrNmbCampo)
            {
                fprintf(gPtrFleArchivoLog, "Campo: \"%s\"", lSiscomCampoProL->chrPtrNmbCampo);
            }
            
            if(lSiscomCampoProL->vidPtrSubPrim)
            {
                fprintf(gPtrFleArchivoLog, " -> SubRegistros Anidados:\n");
                GeminiSiscomImprimeEstructuraPrompt((SiscomRegistroProL *)lSiscomCampoProL->vidPtrSubPrim, pintNivel + 2);
            }
            else
            {
                fprintf(gPtrFleArchivoLog, " = \"%s\"\n", lSiscomCampoProL->chrPtrDato ? lSiscomCampoProL->chrPtrDato : "null");
            }
            lSiscomCampoProL = lSiscomCampoProL->SiscomCamProLPtrSig;
        }
        lSiscomRegProL = lSiscomRegProL->SiscomRegProLPtrSig;
    }
}

void GeminiSiscomProtcoloLog(const char *pchrPtrArchivo, const char *pchrPtrFuncion, int pintLinea, SiscomRegistroProL *pRegistroPtr)
{
    if (!gPtrFleArchivoLog) return;

    fprintf(gPtrFleArchivoLog, "\n================================================================================\n");
    fprintf(gPtrFleArchivoLog, "Copia y pega el siguiente texto como prompt:\n");
    fprintf(gPtrFleArchivoLog, "================================================================================\n");
    fprintf(gPtrFleArchivoLog, "Actua como un desarrollador experto en C para SiscomDesarrollo4.\n");
    fprintf(gPtrFleArchivoLog, "Desarrolla una funcion que me regrese esta estructura en un SiscomRegistroProL.\n");
    fprintf(gPtrFleArchivoLog, "Contexto de ejecucion: Archivo %s, Funcion %s, Linea %d\n\n", pchrPtrArchivo, pchrPtrFuncion, pintLinea);
    fprintf(gPtrFleArchivoLog, "Estructura de datos capturada en pRegistroPtr:\n");
    
    if(!pRegistroPtr)
    {
        fprintf(gPtrFleArchivoLog, " (Estructura SiscomRegistroProL VACIA / NULL)\n");
    }
    else
    {
        GeminiSiscomImprimeEstructuraPrompt(pRegistroPtr, 0);
    }
    
    fprintf(gPtrFleArchivoLog, "================================================================================\n\n");
    fflush(gPtrFleArchivoLog);
}

SiscomRegistroProL *GeminiOrdenVentaSiscom(void)
{
    SiscomRegistroProL *lSiscomRegProLOrdenPrim = NULL, *lSiscomRegProLOrdenAct = NULL;
    SiscomRegistroProL *lSiscomRegProLFormaPagoPrim = NULL, *lSiscomRegProLFormaPagoAct = NULL;
    SiscomRegistroProL *lSiscomRegProLTransferenciaPrim = NULL, *lSiscomRegProLTransferenciaAct = NULL;
    SiscomRegistroProL *lSiscomRegProLProductosPrim = NULL, *lSiscomRegProLProductosAct = NULL;
    SiscomRegistroProL *lSiscomRegProLClientePrim = NULL, *lSiscomRegProLClienteAct = NULL;
    SiscomRegistroProL *lSiscomRegProLEscuelaPrim = NULL, *lSiscomRegProLEscuelaAct = NULL;
    SiscomRegistroProL *lSiscomRegProLCelularPrim = NULL, *lSiscomRegProLCelularAct = NULL;
    SiscomRegistroProL *lSiscomRegProLPedidoPrim = NULL, *lSiscomRegProLPedidoAct = NULL;
    SiscomRegistroProL *lSiscomRegProLEstadoPedidoPrim = NULL, *lSiscomRegProLEstadoPedidoAct = NULL;
    SiscomRegistroProL *lSiscomRegProLPuntoEntregaPrim = NULL, *lSiscomRegProLPuntoEntregaAct = NULL;
    SiscomRegistroProL *lSiscomRegProLDireccionPuntoEntregaPrim = NULL, *lSiscomRegProLDireccionPuntoEntregaAct = NULL;
    SiscomRegistroProL *lSiscomRegProLDireccionPedidoPrim = NULL, *lSiscomRegProLDireccionPedidoAct = NULL;
    SiscomRegistroProL *lSiscomRegProLExpendioPrim = NULL, *lSiscomRegProLExpendioAct = NULL;
    
    char lchrArrBuffer[1024];

    /* Sub-estructura Transferencia */
    SiscomAnexaRegistroPro(&lSiscomRegProLTransferenciaPrim, &lSiscomRegProLTransferenciaAct, lchrArrBuffer,
                           "YaSeReflejo,Observaciones,Importe",
                           (char *)0, (char *)0, (char *)0);

    /* Sub-estructura FormaPago */
    SiscomAnexaRegistroPro(&lSiscomRegProLFormaPagoPrim, &lSiscomRegProLFormaPagoAct, lchrArrBuffer,
                           "Telefono,Observaciones,Tarjeta,Transferencia,Efectivo,Total,PorPagar,Combinada,PagoCompleto",
                           (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
    SiscomRegistrosAlCampo("Transferencia", lSiscomRegProLTransferenciaPrim, lSiscomRegProLTransferenciaAct, lSiscomRegProLFormaPagoPrim);

    /* Sub-estructura Productos */
    SiscomAnexaRegistroPro(&lSiscomRegProLProductosPrim, &lSiscomRegProLProductosAct, lchrArrBuffer,
                           "Clave,Descripcion,Existencia,ExiBodega,TipoProducto,IdProducto,IdCaja,Caja,Estante,Productos,Cantidad,Precio,Importe,IdConsecutivo,SePuedeVender,SePuedeVenderDefProd,PrecioEspecial",
                           (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);

    /* Sub-estructura Escuela */
    SiscomAnexaRegistroPro(&lSiscomRegProLEscuelaPrim, &lSiscomRegProLEscuelaAct, lchrArrBuffer,
                           "idescuela,nombre,idempresa",
                           (char *)0, (char *)0, (char *)0);

    /* Sub-estructura Celular */
    SiscomAnexaRegistroPro(&lSiscomRegProLCelularPrim, &lSiscomRegProLCelularAct, lchrArrBuffer,
                           "IdTelefono,Telefono",
                           (char *)0, (char *)0);

    /* Sub-estructura Cliente */
    SiscomAnexaRegistroPro(&lSiscomRegProLClientePrim, &lSiscomRegProLClienteAct, lchrArrBuffer,
                           "IdPersona,Nombre,APaterno,AMaterno,TipoPersona,TipoCliente,Escuela,Celular,Correo,Direccion,RFC,Mayoreo",
                           (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
    SiscomRegistrosAlCampo("Escuela", lSiscomRegProLEscuelaPrim, lSiscomRegProLEscuelaAct, lSiscomRegProLClientePrim);
    SiscomRegistrosAlCampo("Celular", lSiscomRegProLCelularPrim, lSiscomRegProLCelularAct, lSiscomRegProLClientePrim);

    /* Sub-estructura EstadoPedido */
    SiscomAnexaRegistroPro(&lSiscomRegProLEstadoPedidoPrim, &lSiscomRegProLEstadoPedidoAct, lchrArrBuffer,
                           "IdEstado,Descripcion,Fecha,Accion",
                           (char *)0, (char *)0, (char *)0, (char *)0);

    /* Sub-estructura Direccion (para PuntoEntrega) */
    SiscomAnexaRegistroPro(&lSiscomRegProLDireccionPuntoEntregaPrim, &lSiscomRegProLDireccionPuntoEntregaAct, lchrArrBuffer,
                           "IdDireccion,Calle,Numero,NumeroInt,Delegacion,Colonia,Estado,CP,Calle1,Calle2,Referencias,EdoRegistro,IdDireccion0",
                           (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);

    /* Sub-estructura PuntoEntrega */
    SiscomAnexaRegistroPro(&lSiscomRegProLPuntoEntregaPrim, &lSiscomRegProLPuntoEntregaAct, lchrArrBuffer,
                           "IdPuntoEntrega,PuntoEntrega,Direccion",
                           (char *)0, (char *)0, (char *)0);
    SiscomRegistrosAlCampo("Direccion", lSiscomRegProLDireccionPuntoEntregaPrim, lSiscomRegProLDireccionPuntoEntregaAct, lSiscomRegProLPuntoEntregaPrim);

    /* Sub-estructura Direccion (directa para Pedido) */
    SiscomAnexaRegistroPro(&lSiscomRegProLDireccionPedidoPrim, &lSiscomRegProLDireccionPedidoAct, lchrArrBuffer,
                           "IdDireccion,Calle,Numero,NumeroInt,Delegacion,Colonia,Estado,CP,Calle1,Calle2,Referencias,EdoRegistro,IdDireccion0",
                           (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);

    /* Sub-estructura Pedido (Incluye PuntoEntrega y Direccion de forma integra) */
    SiscomAnexaRegistroPro(&lSiscomRegProLPedidoPrim, &lSiscomRegProLPedidoAct, lchrArrBuffer,
                           "FechaHoraE,SePagaCon,Cambio,Observaciones,EstadoPedido,TipoEntrega,PuntoEntrega,Direccion",
                           (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);
    SiscomRegistrosAlCampo("EstadoPedido", lSiscomRegProLEstadoPedidoPrim, lSiscomRegProLEstadoPedidoAct, lSiscomRegProLPedidoPrim);
    SiscomRegistrosAlCampo("PuntoEntrega", lSiscomRegProLPuntoEntregaPrim, lSiscomRegProLPuntoEntregaAct, lSiscomRegProLPedidoPrim);
    SiscomRegistrosAlCampo("Direccion", lSiscomRegProLDireccionPedidoPrim, lSiscomRegProLDireccionPedidoAct, lSiscomRegProLPedidoPrim);

    /* Sub-estructura Expendio */
    SiscomAnexaRegistroPro(&lSiscomRegProLExpendioPrim, &lSiscomRegProLExpendioAct, lchrArrBuffer,
                           "RazonSocial,DirIp,Puerto,IdExpendio,Basae",
                           (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);

    /* Estructura Principal Orden */
    SiscomAnexaRegistroPro(&lSiscomRegProLOrdenPrim, &lSiscomRegProLOrdenAct, lchrArrBuffer,
                           "IdVenta,IdExpendio,IdTipoOrden,FormaPago,IdVendedor,Descripcion,Juegos,JuegosNuevo,JuegosSeparados,JuegosNuevoSeparados,DescuentoOrden,Importe,Productos,Cliente,NumKitsPracticasEtc,NumProductos,Apartado,Cotizacion,Pedido,CircuitoImpreso,MaterialAAreaDiseno,DonacionMaterial,SeImprimeTicket,Fecha,Expendio,ConCuantoPaga,FechaHora",
                           (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0, (char *)0);

    /* Anexar subregistros principales a la orden */
    SiscomRegistrosAlCampo("FormaPago", lSiscomRegProLFormaPagoPrim, lSiscomRegProLFormaPagoAct, lSiscomRegProLOrdenPrim);
    SiscomRegistrosAlCampo("Productos", lSiscomRegProLProductosPrim, lSiscomRegProLProductosAct, lSiscomRegProLOrdenPrim);
    SiscomRegistrosAlCampo("Cliente", lSiscomRegProLClientePrim, lSiscomRegProLClienteAct, lSiscomRegProLOrdenPrim);
    SiscomRegistrosAlCampo("Pedido", lSiscomRegProLPedidoPrim, lSiscomRegProLPedidoAct, lSiscomRegProLOrdenPrim);
    SiscomRegistrosAlCampo("Expendio", lSiscomRegProLExpendioPrim, lSiscomRegProLExpendioAct, lSiscomRegProLOrdenPrim);

    return lSiscomRegProLOrdenPrim;
}

SiscomRegistroProL *GeminiPreparaRegistroParaEjecucion(void)
{
    SiscomRegistroProL *lSiscomRegProLPrim = NULL, *lSiscomRegProLAct = NULL;
    char lchrArrBuffer[256];

    SiscomAnexaRegistroPro(&lSiscomRegProLPrim, &lSiscomRegProLAct, lchrArrBuffer,
                           "ModuloServidor,Configuracion,Envio",
                           (char *)0, (char *)0, (char *)0);

    return lSiscomRegProLPrim;
}

const char *GeminiIdPedido(SiscomRegistroProL *pRegistro)
{
    const char *lchrPtrIdPedido;
    
    if (!pRegistro) 
    {
        return "";
    }
    
    lchrPtrIdPedido = SiscomObtenCampoRegistroProLChar("id_pedido", pRegistro);
    return lchrPtrIdPedido ? lchrPtrIdPedido : "";
}

const char *GeminiFechaHora(SiscomRegistroProL *pRegistro)
{
    const char *lchrPtrFechaHora;
    
    if (!pRegistro) 
    {
        return "";
    }
    
    lchrPtrFechaHora = SiscomObtenCampoRegistroProLChar("fecha_hora", pRegistro);
    return lchrPtrFechaHora ? lchrPtrFechaHora : "";
}

SiscomRegistroProL *GeminiProductos(SiscomRegistroProL *pRegistro)
{
    if (!pRegistro) 
    {
        return NULL;
    }
    
    return SiscomObtenRegistrosCampoProL("productos", pRegistro);
}

SiscomRegistroProL *GeminiDireccionEnvio(SiscomRegistroProL *pRegistro)
{
    SiscomRegistroProL *lSiscomRegProLEnvio;
    
    if (!pRegistro) 
    {
        return NULL;
    }
    
    lSiscomRegProLEnvio = SiscomObtenRegistrosCampoProL("envio", pRegistro);
    if (lSiscomRegProLEnvio)
    {
        return SiscomObtenRegistrosCampoProL("direccion_entrega", lSiscomRegProLEnvio);
    }
    
    return NULL;
}

SiscomRegistroProL *GeminiCliente(SiscomRegistroProL *pRegistro)
{
    if (!pRegistro) 
    {
        return NULL;
    }
    
    return SiscomObtenRegistrosCampoProL("cliente", pRegistro);
}

void GeminiRegistraPedido(SiscomRegistroProL *pRegistroPtr)
{
    const char *lchrPtrIdPedido;
    const char *lchrPtrFecha;
    SiscomRegistroProL *lSiscomRegProLProductos;
    SiscomRegistroProL *lSiscomRegProLCliente;
    SiscomRegistroProL *lSiscomRegProLDireccion;
    char lchrArrBuffer[256];
    
    if (!pRegistroPtr)
    {
        return;
    }
    
    lchrPtrIdPedido = GeminiIdPedido(pRegistroPtr);
    lchrPtrFecha = GeminiFechaHora(pRegistroPtr);
    lSiscomRegProLProductos = GeminiProductos(pRegistroPtr);
    lSiscomRegProLCliente = GeminiCliente(pRegistroPtr);
    lSiscomRegProLDireccion = GeminiDireccionEnvio(pRegistroPtr);
    
    LogSiscom("================================================================================");
    LogSiscom("Log API Pedidos: Informacion del Registro Recibido");
    LogSiscom("================================================================================");
    LogSiscom("IdPedido : %s", lchrPtrIdPedido);
    LogSiscom("Fecha    : %s", lchrPtrFecha);
    
    if (lSiscomRegProLCliente)
    {
        LogSiscom("--- Estructura de Cliente ---");
        SiscomRegistroProtocoloLog(lchrArrBuffer, lSiscomRegProLCliente);
    }
    
    if (lSiscomRegProLDireccion)
    {
        LogSiscom("--- Estructura de Direccion de Envio ---");
        SiscomRegistroProtocoloLog(lchrArrBuffer, lSiscomRegProLDireccion);
    }
    
    if (lSiscomRegProLProductos)
    {
        LogSiscom("--- Estructura de Productos ---");
        SiscomRegistroProtocoloLog(lchrArrBuffer, lSiscomRegProLProductos);
    }
    
    LogSiscom("================================================================================");
}