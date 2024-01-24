#ifndef __FRIPRO_H__
#define __FRIPRO_H__

#include <SiscomFuncionesComunes.h>
#include <SiscomErrores.h>
#include <SiscomDesarrolloMacros.h>
#include <SiscomLineaComandos.h>


void Argumentos(int pintArgc,char **pchrPtrArgv,StcSiscomOpciones **pStcPtrSisOpciones,
                SiscomRegistroProL **pSisRegProLPtrConfig);
void AgregandoDirFacturacionDelAmbiente(StcSiscomOpciones **pStcPtrSisOpciones);
void AgregandoBinarioPhp(StcSiscomOpciones **pStcPtrSisOpciones);
void LeyendoConfiguracion(StcSiscomOpciones **pStcPtrSisOpciones,SiscomRegistroProL **);

void ImporteMasIva(StcSiscomOpciones **pStcPtrSisOpciones);
#endif
