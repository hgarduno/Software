#ifndef __ZOPERACIONQACTION_H__
#define __ZOPERACIONQACTION_H__
#include <zSiscomOperaciones.h>
class zMenu;
class zOperacionQAction:public zSiscomOperaciones
{
public:
    zOperacionQAction(zSiscomConexion *,zMenu *);
    void PreparaEnvio();

};



#endif
