#ifndef Z_OPERACIONES_GEMINI_H
#define Z_OPERACIONES_GEMINI_H

#include <zSiscomElectronica.h>

class zSiscomConexion;

class zOperacionesGemini : public zSiscomElectronica
{
public:
    zOperacionesGemini(zSiscomConexion *pzSiscomCon,
                       const char *pchrPtrFuncion,
                       const char *pchrPtrModulo = "libSiscomElectronicaGemini.so");
    ~zOperacionesGemini();
};

#endif // Z_OPERACIONES_GEMINI_H
