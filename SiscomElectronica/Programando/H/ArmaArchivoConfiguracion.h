#ifndef __ARMAARCHIVOCONFIGURACION_H__
#define __ARMAARCHIVOCONFIGURACION_H__
#include <SiscomLineaComandos.h>
#include <SiscomFuncionesComunes.h>
#include <SiscomErrores.h>
#include <SiscomDesarrolloMacros.h>
void Argumentos(int pintArgc,char **pchrPtrArgv,StcSiscomOpciones **pStcPtrSisOpciones);

SiscomRegistroProL *FormandoRegistro(StcSiscomOpciones *pStcPtrSisOpciones);
void FormaArchivo(StcSiscomOpciones *pStcPtrSisOpciones,
		  SiscomRegistroProL *pSisRegProLPtrPrim);
#endif
