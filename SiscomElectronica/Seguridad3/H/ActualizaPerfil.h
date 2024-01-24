#ifndef __ACTUALIZAPERFIL_H__
#define __ACTUALIZAPERFIL_H__
#include <SiscomLineaComandos.h>
#include <SiscomProtocoloComunicaciones.h>
#include <SiscomDesarrolloMacros.h>
void PerfilesSeguridad3(StcSiscomOpciones *,
			SiscomRegistroProL **,
			SiscomRegistroProL **);
void ActualizaPerfil(StcSiscomOpciones *pStcPtrSisOpciones);
void ObtenPerfil(SiscomRegistroProL *pSisRegProLPtrDatos,
		 SiscomRegistroProL **pSisRegProLPtrPerfil);
void ConsultaPerfiles(StcSiscomOpciones *pStcPtrSisOpciones);
#endif
