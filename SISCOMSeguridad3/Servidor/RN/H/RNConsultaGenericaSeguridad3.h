#ifndef __RNCONSULTAGENERICA_H__
#define __RNCONSULTAGENERICA_H__
#include <FuncionesComunes.h>
int RNConsultaGenerica(int ,int [],int ,char *);
StcLtaRegComSISCOM *VerificaAplicacion(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *ConsultaObjetosDeLaForma(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *VerificaQueEsteRegistradaLaAplicacion(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *ConsultaPantallasAplicacion(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *ObtenPerfilesAplicacion(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *ObtenPerfilesAplicacionConPantallas(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *ConsultaUsuariosXPerfil(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *ConsultaObjetosEnBD(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *ConsultaObjetosXNombre(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *ValidaFirma(int ,const char *,StcLtaRegComSISCOM *,int *);
StcLtaRegComSISCOM *ValidaPerfil(int ,const char *,StcLtaRegComSISCOM *,int *);


StcLtaRegComSISCOM *RegistraUsuarioDeUnaAplicacion(int ,const char *,StcLtaRegComSISCOM *,int *);

#endif
