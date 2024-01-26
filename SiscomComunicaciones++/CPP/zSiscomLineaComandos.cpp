#include <zSiscomLineaComandos.h>
#include <zSiscomDesarrollo4.h>
#include <zSiscomCampo.h>
#include <string.h>
zSiscomLineaComandos::zSiscomLineaComandos(int pintArgc,
					   char **pchrPtrArgv)
{
 if(pintArgc>1)
 AnalizaArgumentos(pintArgc,pchrPtrArgv);
}
void zSiscomLineaComandos::AgregaOpcion(char **pchrPtrArgv)
{
const unsigned  char *lchrPtrOpcion;
zSiscomRegistro *lzSisRegOpcion=new zSiscomRegistro;
 lchrPtrOpcion=(const unsigned char *)*pchrPtrArgv;
(*lzSisRegOpcion) 					<< 
new zSiscomCampo("Opcion",++lchrPtrOpcion) 		<<
new zSiscomCampo("Argumento",(const unsigned char *)*(pchrPtrArgv+1));
(*this) << lzSisRegOpcion;
}
void zSiscomLineaComandos::AnalizaArgumentos(int pintArgc,
					     char **pchrPtrArgv)
{
const char *lchrPtrOpcion;
while(*pchrPtrArgv)
{
   lchrPtrOpcion=*pchrPtrArgv;
   if(*lchrPtrOpcion=='-')
     AgregaOpcion(pchrPtrArgv);
pchrPtrArgv++;
}
}
const char *zSiscomLineaComandos::operator[](const char *pchrPtrOpcion)
{
zSiscomRegistro *lzSisRegRegistro;
if(NNodos())
{
for(lzSisRegRegistro=Primer();
    lzSisRegRegistro;
    lzSisRegRegistro=Siguiente())
{
   if(!strcmp((const char *)(*lzSisRegRegistro)["Opcion"],pchrPtrOpcion))  
    return (const char *)(*lzSisRegRegistro)["Argumento"];
}
}
else
return 0;
}

int zSiscomLineaComandos::EstaLaOpcion(const char *pchrPtrOpcion)
{
zSiscomRegistro *lzSisRegRegistro;
if(NNodos())
{
for(lzSisRegRegistro=Primer();
    lzSisRegRegistro;
    lzSisRegRegistro=Siguiente())
{
   if(!strcmp((const char *)(*lzSisRegRegistro)["Opcion"],pchrPtrOpcion))  
    return 1;
}
}

return 0;
}
