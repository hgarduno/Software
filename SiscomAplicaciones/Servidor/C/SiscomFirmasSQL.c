#include <SiscomFirmasSQL.h>

void SiscomFirmaYaRegistrada(SArgsSiscom *pSAgsSiscom)
{
char lchrArrCadena[256];
char *lchrPtrEdoConexion;
char *lchrPtrOperacionRespuesta;
int lintSocket;
int lintNRegRespuesta;
LCamposSiscomPro2 *lLCSiscomPro2Base=0;
	sprintf(lchrArrCadena,
		"select * 			\
		 from firmas 			\
		 where firma='%s'", 
		  SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Firma"));

	SiscomConsultaBaseDeDatos(
			lchrArrCadena,
			pSAgsSiscom->chrArrDirIpAD,
			pSAgsSiscom->intPtoComAD,
			&lchrPtrEdoConexion,
			&lintSocket,
			&lintNRegRespuesta,
			&lchrPtrOperacionRespuesta,
			&lLCSiscomPro2Base);
	pSAgsSiscom->intCodigoRetorno=lLCSiscomPro2Base ? 5:0;


}

void SiscomRegistraUsuario(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SQLAct,
		  *lLCSiscomPro2SQLPrim;
int lintNRegistros;
char lchrArrSQL[256];

SiscomObtenInformacionArgumento(
		"SisSQLPersona",
		pSAgsSiscom,
		&lLCSiscomPro2SQLPrim,
		&lLCSiscomPro2SQLAct,
		&lintNRegistros);
sprintf(lchrArrSQL,
	"insert into Usuarios values(%s,%s,%s,'%s','%s','%s');",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdAplicacion"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPerfil"),
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
void SiscomRegistraFirma(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SQLAct,
		  *lLCSiscomPro2SQLPrim;
int lintNRegistros;
char lchrArrSQL[256];

SiscomObtenInformacionArgumento(
		"SisSQLPersona",
		pSAgsSiscom,
		&lLCSiscomPro2SQLPrim,
		&lLCSiscomPro2SQLAct,
		&lintNRegistros);
sprintf(lchrArrSQL,
	"insert into Firmas values(%s,'%s','%s',0);",
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Firma"),
	SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Password"));

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
