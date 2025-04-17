#ifndef __RNALTAGENERICA_H__
#define __RNALTAGENERICA_H__
#include <FuncionesComunes.h>
int RNAltaGenerica(int ,int [],int ,char *);
StcLtaRegComSISCOM *RegistraAplicacion(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *RegistraObjetosDeLaAplicacion(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *ActualizaObjetosDeLaAplicacion(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *ActualizaAplicacion(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *RegistraPerfiles(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *RegistraUsuarios(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *RegistraFirmas(int ,const char *,StcLtaRegComSISCOM *,int *);



#define LOGSeguridad3(...) printf("(%s) (%s) (%d) ",__FILE__,__FUNCTION__,__LINE__) ;printf(__VA_ARGS__);
#endif
