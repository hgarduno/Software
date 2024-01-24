#include <SqlFormaPago.h>

#include <stdlib.h>
#include <string.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomMacrosOperaciones.h>
#include <SiscomCamposProtocolo.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomConfiguracionServidor.h>
#include <SiscomInsercionesSql.h>
#include <ComunSiscomElectronica4.h>


int SqlActualizaPagoTransferencia(SiscomOperaciones *pSisOpePtrDato)
{
char lchrArrBuffer[256],
        lchrArrSql[256];
int lintPuerto;
SiscomAgregaSentenciasSqlDelAsociado("SqlPagoTransferencia",
                                      "Envio",
                                     lchrArrBuffer,
                                     lchrArrSql,
                                     pSisOpePtrDato,
                                     UpdatePagoTransferencia);
SiscomEnviaRegistrosAlServidorBD("SqlPagoTransferencia",
                                  lchrArrBuffer,
                                  pSisOpePtrDato);
return 0;
}

void UpdatePagoTransferencia(SiscomOperaciones *pSisOpePtrDato,
			     SiscomRegistroProL *pSisRegProLPtrDato,
			     char *pchrPtrSql)
{
sprintf(pchrPtrSql,
	"update PagoTransferencia set sereflejo=%s where idventa=%s;",
	SiscomObtenCampoRegistroProLChar("Estado",pSisRegProLPtrDato),
	SiscomObtenCampoRegistroProLChar("IdVenta",pSisRegProLPtrDato));
}
