#include <ConsultaPersonas.h>

void AsignaArgumentosPersonas(SArgsSiscom *pSAgsSiscom)
{
SiscomAsignaMemoriaArgumentosOperaciones(2,pSAgsSiscom);
SiscomIniciaMemoriaArgumentoOperacion(0,"C_Normalizado",pSAgsSiscom);

}
void CopiaParametrosAFormatoPersonas(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Prim=0,
		  *lLCSiscomPro2Act=0;
int lintNRegistros=0;


SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNRegistros,
			"Nombre,	\
			 APaterno,	\
			 AMaterno,	\
			 IdPersona",
			 pSAgsSiscom->chrPtrArgConsulta[2],
			 pSAgsSiscom->chrPtrArgConsulta[3],
			 pSAgsSiscom->chrPtrArgConsulta[4],
			 "");
pSAgsSiscom->LCSiscomPro2Dat=lLCSiscomPro2Prim;


}
