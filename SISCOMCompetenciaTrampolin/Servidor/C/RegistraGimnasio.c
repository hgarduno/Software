#include <RegistraGimnasio.h>
#include <ServidorGeneral.h>
#include <string.h>
void RegistraGimnasio(SArgsSiscom *pSAgsSiscom)
{
char lchrArrSQLInsercion[256];
LCamposSiscomPro2 *lLCSiscomPro2Prim=SiscomArgumentoOperacionPrim("I_Gimnasio",pSAgsSiscom),
		  *lLCSiscomPro2Act=SiscomArgumentoOperacionAct("I_Gimnasio",pSAgsSiscom);

int lintNumRegistros=SiscomArgumentosNumeroRegistros("I_Gimnasio",pSAgsSiscom);

if(VerificandoNombreGimnasio(pSAgsSiscom))
{
	sprintf(lchrArrSQLInsercion,
		"insert into gimnasio values(%s,'%s');",
		SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasio"),
		SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Gimnasio"));
	SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNumRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQLInsercion,
			"");
	if(!strcmp(SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"EsEntrenador"),
		  "Si"))
	{
	  sprintf(lchrArrSQLInsercion,
	  	  "insert into entrenadores values(%s,%s);",
		  SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdPersona"),
		  SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"IdGimnasio"));
	  SiscomAnexaRegistroPro2(&lLCSiscomPro2Prim,
			&lLCSiscomPro2Act,
			&lintNumRegistros,
			"ComandoSQL,EdoRegistro",
			lchrArrSQLInsercion,
			"");
	}
	
SiscomAsignaArgumentoOperacionAct("I_Gimnasio",lLCSiscomPro2Act,pSAgsSiscom);
SiscomAsignaArgumentoNumeroRegistros("I_Gimnasio",lintNumRegistros,pSAgsSiscom);
}
else
{
	pSAgsSiscom->intCodigoRetorno=1;
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Se Encontraron Gimnasios con el Nombre %s",
			  SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Gimnasio"));
	SiscomImprimeContenidoProtocolo("", gPtrFleArchivoLog, pSAgsSiscom->LCSiscomPro2Regreso);
}

}
int VerificandoNombreGimnasio(SArgsSiscom *pSAgsSiscom)
{
	if(SeVerificaNombreGimnasio(pSAgsSiscom->LCSiscomPro2Dat))
	return VerificaNombreGimnasio(pSAgsSiscom);
	else
	return 1;
}
int SeVerificaNombreGimnasio(LCamposSiscomPro2 *pLCSiscomPro2Dat)
{
	return !strcmp(SiscomObtenDato(pLCSiscomPro2Dat,"ValidaNombre"),"Si");
}

int VerificaNombreGimnasio(SArgsSiscom *pSAgsSiscom)
{
char lchrArrCadena[256];
char *lchrPtrEdoConexion;
char *lchrPtrOperacionRespuesta;
int lintSocket;
int lintNRegRespuesta;
LCamposSiscomPro2 *lLCSiscomPro2Base=0;
char lchrArrCConsulta[1024];
	
	CreaCondicionConsulta(
		  SiscomObtenDato(pSAgsSiscom->LCSiscomPro2Dat,"Gimnasio"),
		  lchrArrCConsulta);
     sprintf(lchrArrCadena,
		"select *, 						\
			'GimnasioRegistrado' as edovalidacion		\
		 from gimnasio %s",
		 lchrArrCConsulta); 

	SiscomMensajesLog(gPtrFleArchivoLog,
			  "%s",
			  lchrArrCadena);
	SiscomConsultaBaseDeDatos(
			lchrArrCadena,
			gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
			gSSiscomConfiguracionSvr.intPtoAccesoDatos,
			&lchrPtrEdoConexion,
			&lintSocket,
			&pSAgsSiscom->intNumRegRegreso,
			&lchrPtrOperacionRespuesta,
			&pSAgsSiscom->LCSiscomPro2Regreso);
	return pSAgsSiscom->LCSiscomPro2Regreso ? 0:1;
}
void CreaCondicionConsulta(const char *pchrPtrGimnasio,
			   char *pchrPtrCondicionSQL)
{
char **lchrPtrRegreso;
char lchrArrBuffer[1024];
char lchrArrPaso[256];
int lintContador;
	sprintf(pchrPtrCondicionSQL,
		"where ");
	if(SiscomAnalizaCadenas(pchrPtrGimnasio,
				' ',
				lchrArrBuffer,
				&lchrPtrRegreso))
	{
	 
	   for(lintContador=0;
	        lchrPtrRegreso[lintContador];
		lintContador++)
	   {
	      if(lchrPtrRegreso[lintContador+1])
	      sprintf(lchrArrPaso,
	      	      "nombre like '%%%s%%' or ",
		      lchrPtrRegreso[lintContador]);
	      else
	      sprintf(lchrArrPaso,
	      	      "nombre like '%%%s%%'",
		      lchrPtrRegreso[lintContador]);
	      strcat(pchrPtrCondicionSQL,lchrArrPaso);
	   }

	}
}
