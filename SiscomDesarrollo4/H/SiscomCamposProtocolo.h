#ifndef __SISCOMCAMPOSPROTOCOLO_H__
#define __SISCOMCAMPOSPROTOCOLO_H__
#include <SiscomProtocoloComunicaciones.h>

const char *SiscomCampoRegistroAsociado(const char *pchrPtrCampo,
			const char *pchrPtrCampoAsociado,
			const SiscomRegistroProL *pSiscomRegProLPtrActual);
const char *SiscomCampoRegistro(const char *pchrPtrCampo,
				const SiscomRegistroProL *pSiscomRegProLPtrActual);

SiscomCampoProL *SiscomDuplicaEstructuraRegistro(const SiscomRegistroProL *pSiscomRegProLPtrActual);
#endif
