#include <SQLEmpleados.h>

void SQLFirma(SArgsSiscom *pSAgsSiscom)
{

SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SisSQLPersona",
				   SQLGeneraRegistroFirma);
}
void SQLUsuario(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SisSQLPersona",
				   SQLGeneraRegistroUsuario);
}
void SQLPersonaPerfil(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SisSQLPersona",
				   SQLGeneraRegistroPersonaPerfil);
}
void SQLAdicionales(SArgsSiscom *pSAgsSiscom)
{
SiscomGeneraInsercionActualizacion(pSAgsSiscom,
				   "SisSQLPersona",
				   SQLGeneraRegistroAdicionales);
}
void SQLGeneraRegistroUsuario(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into Usuarios values(%s,1,%s,'%s','%s','%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"IdPerfil"),
	SiscomObtenDato(pLCSiscomPro2,"Nombre"),
	SiscomObtenDato(pLCSiscomPro2,"APaterno"),
	SiscomObtenDato(pLCSiscomPro2,"AMaterno"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
void SQLGeneraRegistroFirma(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into Firmas values(%s,'%s','%s',0);",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"Firma"),
	SiscomObtenDato(pLCSiscomPro2,"Password"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}


void SQLGeneraRegistroPersonaPerfil(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into PersonaPerfil values(%s,%s);",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"IdPerfil"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}


void SQLGeneraRegistroAdicionales(LCamposSiscomPro2 *pLCSiscomPro2,
				   LCamposSiscomPro2 **pLCSiscomPro2Prim,
				   LCamposSiscomPro2 **pLCSiscomPro2Act,
				   int *pintPtrNRegistros)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,
	"insert into Adicionales values(%s,'%s');",
	SiscomObtenDato(pLCSiscomPro2,"IdPersona"),
	SiscomObtenDato(pLCSiscomPro2,"RFC"));
SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQL,
			"");
}
void SQLEmpleadosRegistrados(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];
sprintf(lchrArrSQL,"\
select personas.*,								\
       firmas.firma,								\
       firmas.password,								\
       personaperfil.idperfil,							\
       adicionales.rfc								\
from	personas inner join 							\
        personaperfil using(idpersona) inner join				\
	firmas on (personas.idpersona=firmas.idusuario) inner join		\
	adicionales using(idpersona)						\
where idperfil in(select idperfil 						\
                  from perfiles 						\
		  where nmbperfil='%s');",
pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
