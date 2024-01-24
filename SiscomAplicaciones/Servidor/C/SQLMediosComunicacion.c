#include <SQLMediosComunicacion.h>

void SQLSiscomMediosComunicacionReg(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[1024];
sprintf(lchrArrSQL,
"								\
SELECT * 							\
from	comunicacionpersona inner join 				\
	catmediocomunicacion using(idmedio)			\
where idpersona=%s;",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}


void SQLSiscomRegistraMedioComunicacion(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SQLMedioComunicacion",
				   SQLGeneraSiscomRegistraMedioComunicacion);
}

void SQLGeneraSiscomRegistraMedioComunicacion(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[256];
sprintf(lchrArrSQL,
	"insert into comunicacionpersona values(%s,%s,'%s','%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"IdMedio"),
	SiscomObtenDato(pLCSiscomPro2,"Dato"),
	SiscomObtenDato(pLCSiscomPro2,"Descripcion"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
