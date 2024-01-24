#ifndef __SEGURIDAD3_H__
#define __SEGURIDAD3_H__
#include <SiscomFuncionesComunes.h>
#include <SiscomLineaComandos.h>
#include <SiscomErrores.h>

typedef struct OperacionesSegudida3
{
   int (*SePuedeEjecutar)(StcSiscomOpciones **);
   void (*Operacion)(StcSiscomOpciones *);
}StcOpSeguridad3;


void ArgumentosSeguridad3(int pintArgc,char **pchrPtrArgv,StcSiscomOpciones **pStcPtrSisOpciones);


void AgregaOperacionSeguridad3(StcOpSeguridad3 *pStcPtrOpSeguridad,
			       int (*pSePuedeEjecutar)(StcSiscomOpciones **),
			       void (*Operacion)(StcSiscomOpciones *));
void OperacionesSeguridad(StcOpSeguridad3 *pStcPtrOpSeguridad);
void LanzaEjecuciones(StcSiscomOpciones *pStcPtrSisOpciones);

void RegistraUsuario(StcSiscomOpciones *pStcPtrSisOpciones);
#endif
