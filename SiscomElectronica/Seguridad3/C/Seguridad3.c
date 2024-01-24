#include <Seguridad3.h>
#include <SiscomDesarrolloMacros.h>

#include <OperacionesSeguridad.h>
#include <ComunesSeguridad3.h>
#include <ActualizaPerfil.h>
#include <string.h>
#include <stdlib.h>
FILE *gPtrFleArchivoLog;
int gintSocketProtocoloLog;
SiscomError gSiscomErrorSistema;


int main(int pintArgc,char **pchrPtrArgv)
{
StcSiscomOpciones *lStcPtrSisOpciones;
gPtrFleArchivoLog=stdout;
SiscomAnalizaOpciones(pchrPtrArgv,pintArgc,&lStcPtrSisOpciones);
LanzaEjecuciones(lStcPtrSisOpciones);
}
void LanzaEjecuciones(StcSiscomOpciones *pStcPtrSisOpciones)
{
StcOpSeguridad3 lStcOpSeguridad[100];  
StcOpSeguridad3 *lStcOpSeguridadPaso=lStcOpSeguridad;
memset(lStcOpSeguridad,0,sizeof(StcOpSeguridad3)*100);
OperacionesSeguridad(lStcOpSeguridadPaso);

while(lStcOpSeguridadPaso->Operacion)
{
    if(lStcOpSeguridadPaso->SePuedeEjecutar(&pStcPtrSisOpciones))
     lStcOpSeguridadPaso->Operacion(pStcPtrSisOpciones);
   lStcOpSeguridadPaso++;
}
}
void RegistraUsuario(StcSiscomOpciones *pStcPtrSisOpciones)
{
int lintSocket;
if((lintSocket=Conectate(pStcPtrSisOpciones,
			 "libSiscomElectronica4.so",
			 "RegistraUsuario")))
{
LogSiscom("Registrando al usuario");

}
}
void OperacionesSeguridad(StcOpSeguridad3 *pStcPtrOpSeguridad)
{
AgregaOperacionSeguridad3(pStcPtrOpSeguridad++,SePuedeRegistrarUsuario,RegistraUsuario);
AgregaOperacionSeguridad3(pStcPtrOpSeguridad++, SePuedeActualizarPerfil,ActualizaPerfil);
AgregaOperacionSeguridad3(pStcPtrOpSeguridad++, SeConsultaPerfiles,ConsultaPerfiles);
    
}



void AgregaOperacionSeguridad3(StcOpSeguridad3 *pStcPtrOpSeguridad,
			       int (*pSePuedeEjecutar)(StcSiscomOpciones **),
			       void (*Operacion)(StcSiscomOpciones *))
{
   pStcPtrOpSeguridad->SePuedeEjecutar=pSePuedeEjecutar;
   pStcPtrOpSeguridad->Operacion=Operacion;
}
