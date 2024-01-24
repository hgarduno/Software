#include <SQLPersonas.h>
#include <stdlib.h>
#include <string.h>
void SQLPersonaEnNormalizada(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[1024];
LCamposSiscomPro2 *lLCSiscomPro2Normalizada;
LCamposSiscomPro2 *lLCSiscomPro2EnNormalizada;
int lintNEnNormalizada;
lLCSiscomPro2Normalizada=SiscomArgumentoOperacionPrim(
			   "PersonaNormalizada",
			   pSAgsSiscom);

						     
sprintf(lchrArrSQL,
	"select * 						\
	 from personanormalizada				\
	 where Nombre='%s' 	and				\
	       APaterno='%s'	and				\
	       AMaterno='%s'",
	SiscomObtenDato(lLCSiscomPro2Normalizada,"Nombre"),
	SiscomObtenDato(lLCSiscomPro2Normalizada,"APaterno"),
	SiscomObtenDato(lLCSiscomPro2Normalizada,"AMaterno"));
SiscomConsultaBaseDatosSinDatosConexion(
	lchrArrSQL,
	pSAgsSiscom->chrArrDirIpAD,
	pSAgsSiscom->intPtoComAD,
	&lLCSiscomPro2EnNormalizada,
	&lintNEnNormalizada);

SiscomAsignaArgumentoOperacionPrim(
	"PersonaEnNormalizada",
	lLCSiscomPro2EnNormalizada,
	pSAgsSiscom);


	
}
