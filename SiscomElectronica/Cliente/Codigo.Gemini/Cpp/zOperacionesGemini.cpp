#include <zOperacionesGemini.h>

zOperacionesGemini::zOperacionesGemini(zSiscomConexion *pzSiscomCon,
                                       const char *pchrPtrFuncion,
                                       const char *pchrPtrModulo)
    : zSiscomElectronica(pzSiscomCon, pchrPtrFuncion, pchrPtrModulo)
{
}

zOperacionesGemini::~zOperacionesGemini()
{
}
