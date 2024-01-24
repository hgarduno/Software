#include <SiscomPersonasSQL.h>

void SiscomRegistraPersona(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SQLAct,
		  *lLCSiscomPro2SQLPrim;
int lintNRegistros;
char lchrArrSQL[256];
lLCSiscomPro2SQLPrim=SiscomArgumentoOperacionPrim(
			"SisSQLPersona",
			pSAgsSiscom);

lLCSiscomPro2SQLAct=SiscomArgumentoOperacionAct(
			"SisSQLPersona",
			pSAgsSiscom);
lintNRegistros=SiscomArgumentosNumeroRegistros(
			"SisSQLPersona",
			pSAgsSiscom);
/*
 *
 * Por la compatibilidad con la base de datos del 
 * sistema de electronica se colocaron los nombres
 * de los campos ya que la tabla de personas de
 * este sistema tiene estos mismos campos pero 
 * en posiciones diferentes
 *
 *
 */
sprintf(lchrArrSQL,
"insert into Personas(idpersona,nombre,apaterno,amaterno)  values(%s,'%s','%s','%s');",
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Nombre"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"APaterno"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"AMaterno"));

SiscomAnexaRegistroPro2(
	&lLCSiscomPro2SQLPrim,
	&lLCSiscomPro2SQLAct,
	&lintNRegistros,
	"ComandoSQL,EdoRegistro",
	lchrArrSQL,
	"");

SiscomAsignaInformacionArgumento(
		"SisSQLPersona",
		pSAgsSiscom,
		lLCSiscomPro2SQLPrim,
		lLCSiscomPro2SQLAct,
		lintNRegistros);
}

void SiscomActualizaPersona(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SQLAct,
		  *lLCSiscomPro2SQLPrim;
int lintNRegistros;
char lchrArrSQL[256];
lLCSiscomPro2SQLPrim=SiscomArgumentoOperacionPrim(
			"SisSQLPersona",
			pSAgsSiscom);

lLCSiscomPro2SQLAct=SiscomArgumentoOperacionAct(
			"SisSQLPersona",
			pSAgsSiscom);
lintNRegistros=SiscomArgumentosNumeroRegistros(
			"SisSQLPersona",
			pSAgsSiscom);
sprintf(lchrArrSQL,
"update personas set nombre='%s',apaterno='%s', amaterno='%s' where idpersona=%s ",
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Nombre"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"APaterno"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"AMaterno"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"));

SiscomAnexaRegistroPro2(
	&lLCSiscomPro2SQLPrim,
	&lLCSiscomPro2SQLAct,
	&lintNRegistros,
	"ComandoSQL,EdoRegistro",
	lchrArrSQL,
	"");

SiscomAsignaInformacionArgumento(
		"SisSQLPersona",
		pSAgsSiscom,
		lLCSiscomPro2SQLPrim,
		lLCSiscomPro2SQLAct,
		lintNRegistros);
}

void SiscomActualizaPersonaNormalizada(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SQLAct,
		  *lLCSiscomPro2SQLPrim;
LCamposSiscomPro2 *lLCSiscomPro2Nor;
int lintNRegistros;
char lchrArrSQL[256];
lLCSiscomPro2SQLPrim=SiscomArgumentoOperacionPrim(
			"SisSQLPersona",
			pSAgsSiscom);

lLCSiscomPro2SQLAct=SiscomArgumentoOperacionAct(
			"SisSQLPersona",
			pSAgsSiscom);
lintNRegistros=SiscomArgumentosNumeroRegistros(
			"SisSQLPersona",
			pSAgsSiscom);
lLCSiscomPro2Nor=SiscomArgumentoOperacionPrim("SisNormalizado",
                                               pSAgsSiscom);
sprintf(lchrArrSQL,
"update personanormalizada 				\
 set nombre='%s',apaterno='%s', amaterno='%s' 		\
 where idpersona=%s ",
SiscomObtenDato(lLCSiscomPro2Nor,"Nombre"),
SiscomObtenDato(lLCSiscomPro2Nor,"APaterno"),
SiscomObtenDato(lLCSiscomPro2Nor,"AMaterno"),
SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"));

SiscomAnexaRegistroPro2(
	&lLCSiscomPro2SQLPrim,
	&lLCSiscomPro2SQLAct,
	&lintNRegistros,
	"ComandoSQL,EdoRegistro",
	lchrArrSQL,
	"");

SiscomAsignaInformacionArgumento(
		"SisSQLPersona",
		pSAgsSiscom,
		lLCSiscomPro2SQLPrim,
		lLCSiscomPro2SQLAct,
		lintNRegistros);
}
void SiscomRegistraPersonaEnNormalizados(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Nor;
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim,
		  *lLCSiscomPro2SQLAct;
int lintNRegistros;
char lchrArrSQL[256];
lLCSiscomPro2Nor=SiscomArgumentoOperacionPrim(
		 "SisNormalizado",
		 pSAgsSiscom);
SiscomObtenInformacionArgumento(
		"SisSQLPersona",
		pSAgsSiscom,
		&lLCSiscomPro2SQLPrim,
		&lLCSiscomPro2SQLAct,
		&lintNRegistros);

sprintf(lchrArrSQL,
	"insert into personanormalizada values(%s,'%s','%s','%s');",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"),
	SiscomObtenDato(lLCSiscomPro2Nor,"Nombre"),
	SiscomObtenDato(lLCSiscomPro2Nor,"APaterno"),
	SiscomObtenDato(lLCSiscomPro2Nor,"AMaterno"));
SiscomAnexaRegistroPro2(
	&lLCSiscomPro2SQLPrim,
	&lLCSiscomPro2SQLAct,
	&lintNRegistros,
	"ComandoSQL,EdoRegistro",
	lchrArrSQL,
	"");
SiscomAsignaInformacionArgumento(
		"SisSQLPersona",
		pSAgsSiscom,
		lLCSiscomPro2SQLPrim,
		lLCSiscomPro2SQLAct,
		lintNRegistros);

}


void SQLSiscomBuscaNombreCompleto(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];
LCamposSiscomPro2 *lLCSiscomPro2Nor=0;
lLCSiscomPro2Nor=SiscomArgumentoOperacionPrim("SisNormalizado",
                                               pSAgsSiscom);
sprintf(lchrArrSQL,
"								\
select b.* 							\
from personanormalizada as a inner join				\
     personas as b using(idpersona)				\
where	a.nombre='%s'			and 			\
	a.apaterno='%s' 		and			\
	a.amaterno='%s'",
SiscomObtenDato(lLCSiscomPro2Nor,"Nombre"),
SiscomObtenDato(lLCSiscomPro2Nor,"APaterno"),
SiscomObtenDato(lLCSiscomPro2Nor,"AMaterno"));
SiscomMensajesLog2("%s",lchrArrSQL);
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
void SQLSiscomBuscaTodosNombreAPaterno(SArgsSiscom *pSAgsSiscom)
{

char lchrArrSQL[512];
LCamposSiscomPro2 *lLCSiscomPro2Nor=0;
lLCSiscomPro2Nor=SiscomArgumentoOperacionPrim("SisNormalizado",
                                               pSAgsSiscom);
SiscomMensajesLog2("SQLSiscomBuscaNombreCompleto");

sprintf(lchrArrSQL,
"								\
select b.* 							\
from personanormalizada as a inner join				\
     personas as b using(idpersona)				\
where  a.apaterno like '%%%s%%' and a.nombre like '%%%s%%'",
SiscomObtenDato(lLCSiscomPro2Nor,"APaterno"),
SiscomObtenDato(lLCSiscomPro2Nor,"Nombre"));
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
void SQLSiscomBuscaTodosAPaterno(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[512];
LCamposSiscomPro2 *lLCSiscomPro2Nor=0;
lLCSiscomPro2Nor=SiscomArgumentoOperacionPrim("SisNormalizado",
                                               pSAgsSiscom);
SiscomMensajesLog2("SQLSiscomBuscaNombreCompleto");

sprintf(lchrArrSQL,
"								\
select b.* 							\
from personanormalizada as a inner join				\
     personas as b using(idpersona)				\
where  a.apaterno like '%%%s%%'",
SiscomObtenDato(lLCSiscomPro2Nor,"APaterno"));
SiscomEjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}


