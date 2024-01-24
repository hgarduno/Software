#ifndef __RNTIPOSPRECIOS_H__
#define __RNTIPOSPRECIOS_H__
#include <FuncionesComunes.h>
#define RN_TiposPrecios_NmbTipoPrecio			1
#define RN_TiposPrecios_Descripcion			2
#define RN_TiposPrecios_Tipo				3
#define RN_TiposPrecios_EdoRegistroTiposPrecios 	4

const char *ObenNmbTipoPrecioTiposPrecios(char **);
const char *ObtenDescripcionTiposPrecios(char **);
const char *ObtenTipoTiposPrecios(char **);
const char *ObtenEdoRegistroTiposPrecios(char **);

StcLtaRegComSISCOM *RegistraTiposPrecios(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *ConsultaTiposPrecios(int , const char *, StcLtaRegComSISCOM *, int *);
StcLtaRegComSISCOM *GeneraRespuestaTiposPrecios(int *);

#endif
