#include <RegistraPersona.h>
#include <ServidorGeneral.h>

				 
void RegistraPersona(SArgsSiscom *pSAgsSiscom)
{
LCamposSiscomPro2 *lLCSiscomPro2Act=0,
		  *lLCSiscomPro2Prim=0;
LCamposSiscomPro2 *lLCSiscomPro2Nor; 
int lintNumRegistros=0;
const char *lchrPtrIdPersona;
if(VerificaNombre(pSAgsSiscom))
{
 InsercionPersonas((lchrPtrIdPersona=SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona")),
 		   pSAgsSiscom->LCSiscomPro2Dat,
 		   &lLCSiscomPro2Prim,
		   &lLCSiscomPro2Act,
		   &lintNumRegistros);
 InsercionPersonaNormalizada(lchrPtrIdPersona,
 			     SiscomArgumentoOperacionPrim("C_Normalizado",pSAgsSiscom),
 			     &lLCSiscomPro2Prim,
			     &lLCSiscomPro2Act,
			     &lintNumRegistros);
SiscomAsignaArgumentoOperacionPrim("I_Gimnasio",lLCSiscomPro2Prim,pSAgsSiscom);
SiscomAsignaArgumentoOperacionAct("I_Gimnasio",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("I_Gimnasio",lintNumRegistros,pSAgsSiscom);
}
else
{
SiscomMensajesLog(gPtrFleArchivoLog,
		  "No Se Puede realizar la insercion, Persona ya registrada");
pSAgsSiscom->intCodigoRetorno=1;
SiscomAnexaRegistroPro2(&pSAgsSiscom->LCSiscomPro2Regreso,
			&pSAgsSiscom->LCSiscomPro2RegAct,
			&pSAgsSiscom->intNumRegRegreso,
			"idgimnasio,			\
			 nombre,			\
			 edovalidacion",
			 "",
			 "",
			 "ContactoRegistrado");

SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,pSAgsSiscom->LCSiscomPro2Regreso);
}
}
int EstaElContactoEnNormalizados(LCamposSiscomPro2 *pLCSiscomPro2Nor)
{
char lchrArrCadena[256];
char *lchrPtrEdoConexion;
char *lchrPtrOperacionRespuesta;
int lintSocket;
int lintNRegRespuesta;
LCamposSiscomPro2 *lLCSiscomPro2Base=0;
	sprintf(lchrArrCadena,
		"select * 			\
		 from personanormalizada	\
		 where nombre='%s' 	and	\
		 	apaterno='%s'	and	\
			amaterno='%s'",
		  SiscomObtenDato(pLCSiscomPro2Nor,"Nombre"),
		  SiscomObtenDato(pLCSiscomPro2Nor,"APaterno"),
		  SiscomObtenDato(pLCSiscomPro2Nor,"AMaterno"));

	SiscomConsultaBaseDeDatos(
			lchrArrCadena,
			gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			&lchrPtrEdoConexion,
			&lintSocket,
			&lintNRegRespuesta,
			&lchrPtrOperacionRespuesta,
			&lLCSiscomPro2Base);
	return lLCSiscomPro2Base ? 0:1;
}
int VerificaNombre(SArgsSiscom *pSAgsSiscom)
{
return EstaElContactoEnNormalizados(SiscomArgumentoOperacionPrim("C_Normalizado",pSAgsSiscom));
}
void InsercionPersonaNormalizada(const char *pchrPtrIdPersona,
				LCamposSiscomPro2 *pLCSiscomPro2Nor,
				 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSQLInserta[256];
sprintf(lchrArrSQLInserta,
  	  "insert into personanormalizada values(%s,'%s','%s','%s');",
	  pchrPtrIdPersona,
	  SiscomObtenDato(pLCSiscomPro2Nor,"Nombre"),
	  SiscomObtenDato(pLCSiscomPro2Nor,"APaterno"),
	  SiscomObtenDato(pLCSiscomPro2Nor,"AMaterno"));

SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQLInserta,
			"");

}
void InsercionPersonas(const char *pchrPtrIdPersona,
				LCamposSiscomPro2 *pLCSiscomPro2Dat,
				 LCamposSiscomPro2 **pLCSiscomPro2Prim,
				 LCamposSiscomPro2 **pLCSiscomPro2Act,
				 int *pintPtrNRegistros)
{
char lchrArrSQLInserta[256];
if(SiscomObtenDato(pLCSiscomPro2Dat,"Nombre")[0] &&
   SiscomObtenDato(pLCSiscomPro2Dat,"APaterno")[0])
{
sprintf(lchrArrSQLInserta,
  	  "insert into personas values(%s,'%s','%s','%s');",
	  pchrPtrIdPersona,
	  SiscomObtenDato(pLCSiscomPro2Dat,"Nombre"),
	  SiscomObtenDato(pLCSiscomPro2Dat,"APaterno"),
	  SiscomObtenDato(pLCSiscomPro2Dat,"AMaterno"));

SiscomAnexaRegistroPro2(pLCSiscomPro2Prim,
			pLCSiscomPro2Act,
			pintPtrNRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQLInserta,
			"");
}
}
