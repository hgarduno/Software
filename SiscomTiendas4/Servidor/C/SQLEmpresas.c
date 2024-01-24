#include <SQLEmpresas.h>

#include <stdlib.h>
#include <string.h>
void SQLConsultaEmpresaNormalizada(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
LCamposSiscomPro2 *lLCSiscomPro2Normalizado;
int lintNRespuesta;
char lchrArrSQL[1024];

lLCSiscomPro2Normalizado=SiscomArgumentoOperacionPrim("EmpresaNormalizada",pSAgsSiscom);
sprintf(lchrArrSQL,
	"select * 				\
	 from empresanormalizada 		\
	 where RazonSocial='%s'",
	 SiscomObtenDato(lLCSiscomPro2Normalizado,"RazonSocial"));
SiscomConsultaBaseDatosSinDatosConexion(
	  lchrArrSQL,
          pSAgsSiscom->chrArrDirIpAD,
          pSAgsSiscom->intPtoComAD,
          &lLCSiscomPro2Reg,
          &lintNRespuesta);
  SiscomAsignaInformacionArgumento("EmpresaEnNormalizada",
                              pSAgsSiscom,
                              lLCSiscomPro2Reg,
                              0,
                              lintNRespuesta);
}
void SQLEmpresasSimilares(SArgsSiscom *pSAgsSiscom)
{
char **lchrPtrCadenas;
char lchrArrBuffer[1024];
char lchrArrSQL[1024];
char lchrArrPaso[256];
LCamposSiscomPro2 *lLCSiscomPro2Normalizado;
LCamposSiscomPro2 *lLCSiscomPro2Reg=0;
int lintContador;
int lintNRespuesta;
lLCSiscomPro2Normalizado=SiscomArgumentoOperacionPrim("EmpresaNormalizada",pSAgsSiscom);

	if(lLCSiscomPro2Normalizado &&
	   (SiscomAnalizaCadenas(
		(const char *)SiscomObtenDato(lLCSiscomPro2Normalizado,"RazonSocial"),
		' ',
		lchrArrBuffer,
		&lchrPtrCadenas)))
	{
	  sprintf(lchrArrSQL,
	  	  "select * from empresanormalizada where ");
	  for(lintContador=0;
	       lchrPtrCadenas[lintContador];
	       lintContador++)
	  {
	     if(lchrPtrCadenas[lintContador+1])
		sprintf(lchrArrPaso,
			"razonsocial like '%%%s%%' or ",
			lchrPtrCadenas[lintContador]);
	      else
		sprintf(lchrArrPaso,
			"razonsocial like '%%%s%%'",
			lchrPtrCadenas[lintContador]);
	  }

	  strcat(lchrArrSQL,lchrArrPaso);
SiscomConsultaBaseDatosSinDatosConexion(
	  lchrArrSQL,
          pSAgsSiscom->chrArrDirIpAD,
          pSAgsSiscom->intPtoComAD,
          &lLCSiscomPro2Reg,
          &lintNRespuesta);
  SiscomAsignaInformacionArgumento("EmpresaSimilar",
                              pSAgsSiscom,
                              lLCSiscomPro2Reg,
                              0,
                              lintNRespuesta);

	}



}
void SQLRegistraEmpresa(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct;
int lintNRegistros;
char lchrArrSQL[1024];
LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRDat;

SiscomObtenInformacionArgumento("SQLEmpresa",
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
for(lLCSiscomPro2SRDat=pSAgsSiscom->LCSiscomPro2SREntrada;
    lLCSiscomPro2SRDat;
    lLCSiscomPro2SRDat=lLCSiscomPro2SRDat->LCSiscomPro2SRSig)
{
sprintf(lchrArrSQL,
	"insert into Empresas values(%s,'%s');",
	SiscomCampoRegistroPrincipal(lLCSiscomPro2SRDat,"IdEmpresa"),
	SiscomCampoRegistroPrincipal(lLCSiscomPro2SRDat,"RazonSocial"));
SiscomAnexaRegistroPro2(
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros,
	  "ComandoSQL,EdoRegistro",
	  lchrArrSQL,
	  "");
}
SiscomAsignaInformacionArgumento("SQLEmpresa",
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);
}
void SQLRegistraEmpresaNormalizada(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct;
LCamposSiscomPro2 *lLCSiscomPro2Normalizada;
int lintNRegistros;
char lchrArrSQL[1024];
SiscomObtenInformacionArgumento("SQLEmpresa",
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
lLCSiscomPro2Normalizada=SiscomArgumentoOperacionPrim("EmpresaNormalizada",pSAgsSiscom);
sprintf(lchrArrSQL,
	"insert into EmpresaNormalizada values(%s,'%s');",
	SiscomObtenDato(lLCSiscomPro2Normalizada,"IdEmpresa"),
	SiscomObtenDato(lLCSiscomPro2Normalizada,"RazonSocial"));
SiscomAnexaRegistroPro2(
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros,
	  "ComandoSQL,EdoRegistro",
	  lchrArrSQL,
	  "");
SiscomAsignaInformacionArgumento("SQLEmpresa",
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);

}
void SQLRegistraContactoEnPersonas(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct;
LCamposSiscomPro2 *lLCSiscomPro2Cont;
int lintNRegistros;
char lchrArrSQL[1024];
SiscomObtenInformacionArgumento("SQLEmpresa",
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
for(lLCSiscomPro2Cont=SiscomSubRegistroPrim(2,pSAgsSiscom->LCSiscomPro2SREntrada);
    lLCSiscomPro2Cont;
    lLCSiscomPro2Cont=lLCSiscomPro2Cont->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"insert into Personas values(%s,'%s','%s','%s');",
	SiscomObtenDato(lLCSiscomPro2Cont,"IdPersona"),
	SiscomObtenDato(lLCSiscomPro2Cont,"Nombre"),
	SiscomObtenDato(lLCSiscomPro2Cont,"APaterno"),
	SiscomObtenDato(lLCSiscomPro2Cont,"AMaterno"));
SiscomAnexaRegistroPro2(
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros,
	  "ComandoSQL,EdoRegistro",
	  lchrArrSQL,
	  "");
}
SiscomAsignaInformacionArgumento("SQLEmpresa",
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);

}
void SQLRegistraContactoEnNormalizadas(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct;
LCamposSiscomPro2 *lLCSiscomPro2Normalizada;
int lintNRegistros;
char lchrArrSQL[1024];
SiscomObtenInformacionArgumento("SQLEmpresa",
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
for(lLCSiscomPro2Normalizada=SiscomArgumentoOperacionPrim("PersonaNormalizada",pSAgsSiscom);
    lLCSiscomPro2Normalizada;
    lLCSiscomPro2Normalizada=lLCSiscomPro2Normalizada->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"insert into personanormalizada values(%s,'%s','%s','%s');",
	SiscomObtenDato(lLCSiscomPro2Normalizada,"IdPersona"),
	SiscomObtenDato(lLCSiscomPro2Normalizada,"Nombre"),
	SiscomObtenDato(lLCSiscomPro2Normalizada,"APaterno"),
	SiscomObtenDato(lLCSiscomPro2Normalizada,"AMaterno"));
SiscomAnexaRegistroPro2(
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros,
	  "ComandoSQL,EdoRegistro",
	  lchrArrSQL,
	  "");
}
SiscomAsignaInformacionArgumento("SQLEmpresa",
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);

}
void SQLRegistraContactoEnContactos(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct=0,
		  *lLCSiscomPro2Cont;

int lintNRegistros;
char lchrArrSQL[1024];
const char *lchrPtrIdEmpresa;
SiscomObtenInformacionArgumento("SQLEmpresa",
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
lchrPtrIdEmpresa=SiscomCampoRegistroPrincipal(
			pSAgsSiscom->LCSiscomPro2SREntrada,
			"IdEmpresa");
for(lLCSiscomPro2Cont=SiscomSubRegistroPrim(2,pSAgsSiscom->LCSiscomPro2SREntrada);
    lLCSiscomPro2Cont;
    lLCSiscomPro2Cont=lLCSiscomPro2Cont->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"insert into ContactosEmpresa values(%s,%s);",
	lchrPtrIdEmpresa,
	SiscomObtenDato(lLCSiscomPro2Cont,"IdPersona"));
SiscomAnexaRegistroPro2(
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros,
	  "ComandoSQL,EdoRegistro",
	  lchrArrSQL,
	  "");
}
SiscomAsignaInformacionArgumento("SQLEmpresa",
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);
}
void SQLRegistraEnClientes(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct;
LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRDat;
int lintNRegistros;
char lchrArrSQL[1024];

for(lLCSiscomPro2SRDat=pSAgsSiscom->LCSiscomPro2SREntrada;
    lLCSiscomPro2SRDat;
    lLCSiscomPro2SRDat=lLCSiscomPro2SRDat->LCSiscomPro2SRSig)
{
if(!strcmp(SiscomCampoRegistroPrincipal(lLCSiscomPro2SRDat,"TipoEmpresa"),
			   "Cliente"))
{
SiscomObtenInformacionArgumento("SQLEmpresa",
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
sprintf(lchrArrSQL,
	"insert into ClientesMoral values(%s);",
	SiscomCampoRegistroPrincipal(lLCSiscomPro2SRDat,"IdEmpresa"));
SiscomAnexaRegistroPro2(
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros,
	  "ComandoSQL,EdoRegistro",
	  lchrArrSQL,
	  "");
SiscomAsignaInformacionArgumento("SQLEmpresa",
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);
}
}
}
void SQLRegistraEnProveedores(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct=0;
LCamposSiscomPro2ConSubReg *lLCSiscomPro2SRDat;
int lintNRegistros;
char lchrArrSQL[1024];
for(lLCSiscomPro2SRDat=pSAgsSiscom->LCSiscomPro2SREntrada;
    lLCSiscomPro2SRDat;
    lLCSiscomPro2SRDat=lLCSiscomPro2SRDat->LCSiscomPro2SRSig)
{
if(!strcmp(SiscomCampoRegistroPrincipal(lLCSiscomPro2SRDat,"TipoEmpresa"),
			   "Proveedor"))
{
SiscomObtenInformacionArgumento("SQLEmpresa",
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
sprintf(lchrArrSQL,
	"insert into Proveedores values(%s);",
	SiscomCampoRegistroPrincipal(lLCSiscomPro2SRDat,"IdEmpresa"));
SiscomAnexaRegistroPro2(
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros,
	  "ComandoSQL,EdoRegistro",
	  lchrArrSQL,
	  "");
SiscomAsignaInformacionArgumento("SQLEmpresa",
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);
}
}
}
void SQLRegistraComunicacionEmpresa(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct=0,
		  *lLCSiscomPro2ComE;

int lintNRegistros;
char lchrArrSQL[1024];
SiscomObtenInformacionArgumento("SQLEmpresa",
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
for(lLCSiscomPro2ComE=SiscomSubRegistroPrim(1,pSAgsSiscom->LCSiscomPro2SREntrada);
    lLCSiscomPro2ComE;
    lLCSiscomPro2ComE=lLCSiscomPro2ComE->SCP2PtrSig)
{
sprintf(lchrArrSQL,
	"insert into ComunicacionPersona values(%s,%s,'%s','%s');",
	SiscomObtenDato(lLCSiscomPro2ComE,"IdEmpresa"),
	SiscomObtenDato(lLCSiscomPro2ComE,"IdMedio"),
	SiscomObtenDato(lLCSiscomPro2ComE,"Dato"),
	SiscomObtenDato(lLCSiscomPro2ComE,"Descripcion"));
SiscomAnexaRegistroPro2(
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros,
	  "ComandoSQL,EdoRegistro",
	  lchrArrSQL,
	  "");
SiscomAsignaInformacionArgumento("SQLEmpresa",
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);
}
}
/*
 * Debido a que si la informacion se toma del control Sepomex 
 * el nombre del campo IdAsentamiento llega en minusculas se
 * programo la siguiente funcion que permite obtener el campo
 * si llega en minusculas o mayusculas
 *
 * Seria mejor, si la funcion SiscomObtenDato, buscara el nombre
 * en puras mayusculas o puras minusculas ?
 */
const char *ObtenIdAsentamiento(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
const char *lchrPtrIdAsentamiento;

lchrPtrIdAsentamiento=SiscomObtenDato(pLCSiscomPro2Dat,"IdAsentamiento");
if(!strcmp(lchrPtrIdAsentamiento,"No Se Encontro El Campo"))
lchrPtrIdAsentamiento=SiscomObtenDato(pLCSiscomPro2Dat,"idasentamiento");
return lchrPtrIdAsentamiento;
}
void SQLRegistraDireccion(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2SQLPrim=0,
		  *lLCSiscomPro2SQLAct=0,
		  *lLCSiscomPro2Dir;
int lintNRegistros;
char lchrArrSQL[1024];
char lchrArrDireccion[1024];
const char *lchrPtrIdEmpresa;

lchrPtrIdEmpresa=SiscomCampoRegistroPrincipal(
			pSAgsSiscom->LCSiscomPro2SREntrada,
			"IdEmpresa");
SiscomObtenInformacionArgumento("SQLEmpresa",
				pSAgsSiscom,
				&lLCSiscomPro2SQLPrim,
				&lLCSiscomPro2SQLAct,
				&lintNRegistros);
for(lLCSiscomPro2Dir=SiscomSubRegistroPrim(0,pSAgsSiscom->LCSiscomPro2SREntrada);
    lLCSiscomPro2Dir;
    lLCSiscomPro2Dir=lLCSiscomPro2Dir->SCP2PtrSig)
{
sprintf(lchrArrDireccion,
	"%s\n%s\n%s",
	SiscomObtenDato(lLCSiscomPro2Dir,"Linea1"),
	SiscomObtenDato(lLCSiscomPro2Dir,"Linea2"),
	SiscomObtenDato(lLCSiscomPro2Dir,"Linea3"));
sprintf(lchrArrSQL,
	"insert into Direcciones2 values('%s','%s');",
	lchrPtrIdEmpresa,
	lchrArrDireccion);
SiscomAnexaRegistroPro2(
	  &lLCSiscomPro2SQLPrim,
	  &lLCSiscomPro2SQLAct,
	  &lintNRegistros,
	  "ComandoSQL,EdoRegistro",
	  lchrArrSQL,
	  "");
}
SiscomAsignaInformacionArgumento("SQLEmpresa",
                              pSAgsSiscom,
                              lLCSiscomPro2SQLPrim,
                              lLCSiscomPro2SQLAct,
                              lintNRegistros);
}

void SQLProveedores(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[1024];

sprintf(lchrArrSQL,
	"select *				\
	 from proveedores inner join 		\
	      empresas using(idempresa)");
EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}
void SQLContactosProveedores(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQL[1024];

sprintf(lchrArrSQL,
	"select b.*				\n\
	 from ContactosEmpresa inner join	\n\
	      personas as b using(idpersona)	\n\
	 where idempresa=%s",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
EjecutaConsultaYResponde(pSAgsSiscom,lchrArrSQL);
}

void SqlContactosEmpresa(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[256];
sprintf(lchrArrSql,
	"select b.*					\n\
	 from   ContactosEmpresa as a inner join 	\n\
	        Personas as b using(idpersona)		\n\
	 where idempresa=%s",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseAsignaArgumento("Personas",
				  lchrArrSql,
				  pSAgsSiscom);
}
void SqlDireccionesEmpresa(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
"select  *				\n\
from direcciones2 			\n\
where idpersona=%s;",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseAsignaArgumento("SqlDireccionesEmpresa",
				  lchrArrSql,
				  pSAgsSiscom);
}
void SqlMediosComunicacionEmpresa(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSql[512];
sprintf(lchrArrSql,
"select idpersona,							\n\
	idmedio,							\n\
	dato,								\n\
	descripcion,							\n\
	medio								\n\
from comunicacionpersona inner join					\n\
     catmediocomunicacion using(idmedio)				\n\
where idpersona=%s",
	 pSAgsSiscom->chrPtrArgConsulta[1]);
SiscomConsultaBaseAsignaArgumento("SqlComunicacionEmpresa",
				  lchrArrSql,
				  pSAgsSiscom);
}
