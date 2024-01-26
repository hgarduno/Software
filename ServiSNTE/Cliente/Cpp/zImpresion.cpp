#include <zImpresion.h>
#include <string.h>
zImpresion::zImpresion()
{


}

const char *zImpresion::operator[](const char *pchrPtrCampo)
{
zSiscomRegistro *lzSisRegCampo;
for(lzSisRegCampo=Primer();
    lzSisRegCampo;
    lzSisRegCampo=Siguiente())
{
   if(lzSisRegCampo->EstaElCampoEnElRegistro(pchrPtrCampo))
   return (const char *)lzSisRegCampo->Campo(pchrPtrCampo);
}
return 0;
}
