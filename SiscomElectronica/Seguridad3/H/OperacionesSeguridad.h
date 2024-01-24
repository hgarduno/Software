#ifndef __OPERACIONESSEGURIDAD_H__
#define __OPERACIONESSEGURIDAD_H__
#include <SiscomLineaComandos.h>
#include <SiscomProtocoloComunicaciones.h>
int Conectate(StcSiscomOpciones *pStcPtrSisOpciones,const char *,const char *);

void ComunicacionServidor(const char *pchrPtrModulo,
		          const char *pchrPtrFuncion,
			  SiscomRegistroProL **pSisRegProLPtrRegreso);
void FormaComunicacionServidor(const char *pchrPtrModulo,const char *pchrPtrFuncion);
void ModuloServidor(const char *pchrPtrModulo,
		   const char *pchrPtrFuncion,
		   SiscomRegistroProL **pSisRegProLPtrModuloPrim,
		   SiscomRegistroProL **pSisRegProLPtrModuloAct);
void EnviaVersionProtocolo(int pintSocket);


void RegistroUsuario(StcSiscomOpciones *pStcPtrSisOpciones,
		     SiscomRegistroProL *pSisRegProLPtrEnvio);
#endif
