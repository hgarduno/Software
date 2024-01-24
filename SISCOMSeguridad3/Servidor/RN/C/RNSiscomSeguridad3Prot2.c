#include <RNSiscomSeguridad3Prot2.h>
#include <ServidorGeneral.h>
#include <stdlib.h>

StcConsultaSvrSiscom2 gStcCnsSeguridad3Pro2[]={ 
		{EsConsultaSeguridad3Pro2,FormaConsultaSeguridad3Pro2},
		{EsConsultaPerfilesSeguridad3Pro2,FormaConsultaPerfilesSeguridad3Pro2},
		{EsConsultaUsuariosPerfil,FormaConsultaUsuariosPerfil},
		{EsConsultaValidaFirma,FormaConsultaValidaFirma}
			       };
int gintCnsSeguridad3Pro2=4;
int EsConsultaValidaFirma(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ValidaFirmaAlSistema");	
}
void ValidaPassword(SiscomOperacionesServidor *pSOpServidor)
{
const char *lchrPtrAcceso=!strcmp(SiscomObtenDato(pSOpServidor->LCSiscomPro2,"password"),
				  (char **)pSOpServidor->voidPtrArgumentos[2]) ?
				  "Si" :
				  "No";
	SiscomAsignaDatoCampo("acceso",
			      pSOpServidor->LCSiscomPro2->SCSiscomPro2->intNumCampos,
			      lchrPtrAcceso,
			      pSOpServidor->LCSiscomPro2->SCSiscomPro2);


}
void FormaConsultaValidaFirma(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[2048];

pSOpServidor->voidPtrArgumentos=(void **)pchrPtrEntrada;
 sprintf(lchrArrConsulta,
 	 "select b.*,							\
	  	 c.firma,						\
		 c.password,						\
		 '' as acceso						\
	  from usuarios as a inner join					\
	  	personas as b on a.idusuario=b.idpersona inner join	\
		firmas as c using(idusuario)				\
	  where c.firma='%s'",
	  pchrPtrEntrada[1]);
 SiscomInformacionOperaciones("ConsultaSQL","ConsultasBaseDatos",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL,	\
			 BaseDatos,	\
			 PtoBaseDatos",
			lchrArrConsulta,
			ObtenBaseDatosSeguridad3(),
			"");
pSOpServidor->EjecutaProcesoDespues=ValidaPassword;
}
int EsConsultaUsuariosPerfil(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"UsuariosAplicacionPerfil");	
}
void FormaConsultaUsuariosPerfil(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[2048];

 sprintf(lchrArrConsulta,
 	 "select b.*,							\
	  	 c.firma,						\
		 '' as acceso						\
	  from usuarios as a inner join					\
	  	personas as b on a.idusuario=b.idpersona inner join	\
		firmas as c using(idusuario)				\
	  where idperfil=%s",
	  pchrPtrEntrada[2]);
SiscomLog("%s",lchrArrConsulta);
 SiscomInformacionOperaciones("ConsultaSQL","ConsultasBaseDatos",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL,	\
			 BaseDatos,	\
			 PtoBaseDatos",
			lchrArrConsulta,
			ObtenBaseDatosSeguridad3(),
			"");
}

int EsConsultaSeguridad3Pro2(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"ControlesForma");	
}
void FormaConsultaSeguridad3Pro2(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[2048];

sprintf(lchrArrConsulta,
	"select	idPantalla,						\n\
	        a.idObjeto,						\n\
		idPerfil,						\n\
		a.idPropiedad,						\n\
		NmbPropiedad,						\n\
		ValorPropiedad						\n\
	from	objetosxpantalla as a inner join 			\n\
		propiedades as b on (a.idObjeto=b.IdObjeto and 		\n\
		a.idPropiedad=b.IdPropiedad)				\n\
	where idPantalla= (select idPantalla 				\n\
		   	   from pantalla 				\n\
		   	   where NmbClase='%s' and			\n\
		         	 idAplicacion=(				\n\
				 	select idAplicacion		\n\
			 	       	from aplicaciones		\n\
				       	where NmbAplicacion='%s')	\n\
		   			) and				\n\
       				 idPerfil=%s				\n\
	order by numobjeto,a.idpropiedad",
			pchrPtrEntrada[1],
			pchrPtrEntrada[3],
			pchrPtrEntrada[2]);
 SiscomLog("%s",lchrArrConsulta);
 SiscomInformacionOperaciones("ConsultaSQL","ConsultasBaseDatos",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL,	\
			 BaseDatos,	\
			 PtoBaseDatos",
			lchrArrConsulta,
			ObtenBaseDatosSeguridad3(),
			"");
}

int EsConsultaPerfilesSeguridad3Pro2(char **pchrPtrEntrada)
{
	return !strcmp(pchrPtrEntrada[0],"PerfilesAplicacion");	
}
void FormaConsultaPerfilesSeguridad3Pro2(char **pchrPtrEntrada,
			   SiscomOperacionesServidor *pSOpServidor)
{
char lchrArrConsulta[2048];
		sprintf(lchrArrConsulta,
			"SELECT * 					\
			from perfiles 					\
			where idaplicacion=(select idaplicacion 	\
					    from aplicaciones 		\
					    where nmbaplicacion='%s')",
			pchrPtrEntrada[1]);
 SiscomInformacionOperaciones("ConsultaSQL","ConsultasBaseDatos",pSOpServidor);
 SiscomAnexaRegistroPro2(&pSOpServidor->LCSiscomPro2EPrim,
		         &pSOpServidor->LCSiscomPro2EAct,
			&pSOpServidor->intNRegistros,
			"ConsultaSQL,	\
			 BaseDatos,	\
			 PtoBaseDatos",
			lchrArrConsulta,
			ObtenBaseDatosSeguridad3(),
			"");
SiscomLog("%s",ObtenBaseDatosSeguridad3());	
}
void AnalizaConsultaSeguridad3Pro2(char **pchrPtrEntrada,
			      SiscomOperacionesServidor *pSOpServidor)
{
int lintContador;
	for(lintContador=0;
	    lintContador<gintCnsSeguridad3Pro2;
	    lintContador++)
	   if(gStcCnsSeguridad3Pro2[lintContador].Consulta(pchrPtrEntrada))
	   {
	      gStcCnsSeguridad3Pro2[lintContador].FormaConsulta(pchrPtrEntrada,
	     						  pSOpServidor);
	      return ;
	   }

	

}
void ConsultaSeguridad3Pro2Version2(int pintSocket,
				    int pintNRegistros)
{
SiscomOperacionesServidor lSOpServidor;
char **lchrPtrEntrada=0;

	lSOpServidor.EjecutaProcesoAntes=0;	
	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				      gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				      &lSOpServidor);
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lSOpServidor.LCSiscomPro2Dat);
	SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
					  pintNRegistros,
					  "Parametro",
					  &lchrPtrEntrada);
	AnalizaConsultaSeguridad3Pro2(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);
	close(pintSocket);


}
void ConsultaSeguridad3Pro2(int pintSocket,
		       int pintNRegistros)
{
SiscomOperacionesServidor lSOpServidor;
char **lchrPtrEntrada=0;

	lSOpServidor.EjecutaProcesoAntes=0;	
	SiscomIniciaComunicacionesSrv(gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				      gSSiscomConfiguracionSvr.intPtoAccesoDatos,
				      &lSOpServidor);
	SiscomLeeInformacionProtocolo(pintSocket,
				      pintNRegistros,
				      &lSOpServidor.LCSiscomPro2Dat);
	SiscomCopiaDatosProtocoloCharChar(lSOpServidor.LCSiscomPro2Dat,
					  pintNRegistros,
					  "Parametro",
					  &lchrPtrEntrada);
	AnalizaConsultaSeguridad3Pro2(lchrPtrEntrada,&lSOpServidor);
	SiscomOperacionesServidores(&lSOpServidor);
	SiscomEnviaAlServidor(pintSocket,
			      lSOpServidor.intNRegistrosRes,
			      "ClientesRegistrados",
			      lSOpServidor.LCSiscomPro2);
	close(pintSocket);
}

void FormaCadenaOperacionSqlSeguridad3Pro2(int lintContador,
			     LCamposSiscomPro2 *pLCSiscomPro2,
			     char *pchrPtrCadena)
{

	if(!strcmp(SiscomObtenDato(pLCSiscomPro2,"EdoRegistro"),"Insertar"))
	{
	 sprintf(pchrPtrCadena,
	 	 "insert into Seguridad3Pro2 values(%s,%d,'%s');",
		 SiscomObtenDato(pLCSiscomPro2,"IdEscuela"),
		 SiscomObtenNumeroUnico()+lintContador,
		 SiscomObtenDato(pLCSiscomPro2,"Nombre"));
	}

		   


}
void RegistraSeguridad3Pro2(int pintSocket,
			int pintNRegistros)
{
LCamposSiscomPro2 *lLCSiscomPro2=0;
LCamposSiscomPro2 *lLCSiscomPro2Ins=0,
                  *lLCSiscomPro2InsAct=0;
char lchrArrActualiza[1204];
char *lchrPtrEdoConexion=0;
int     lintSocketAD,
        lintNRegistros=0,
	lintContador;

SiscomLeeInformacionProtocolo(pintSocket,
                                      pintNRegistros,
                                      &lLCSiscomPro2);
  for(lintContador=0;
  	lLCSiscomPro2;
	lLCSiscomPro2=lLCSiscomPro2->SCP2PtrSig,
	lintContador++)
  {
  	 FormaCadenaOperacionSqlSeguridad3Pro2(lintContador,lLCSiscomPro2,lchrArrActualiza); 
	 SiscomAnexaRegistroPro2(&lLCSiscomPro2Ins,
	 			 &lLCSiscomPro2InsAct,
				 &lintNRegistros,
				 "ComandoSQL",
				 lchrArrActualiza);
  }
	SiscomInformacionServidor(gSSiscomConfiguracionSvr.intPtoAccesoDatos,
	                          gSSiscomConfiguracionSvr.chrPtrDirIpAccesoDatos,
				  "Inserciones",
				  lintNRegistros,
				  lLCSiscomPro2Ins,
				  &lchrPtrEdoConexion,
				  &lintSocketAD);
	if(lchrPtrEdoConexion)
	SiscomMensajesLog(gPtrFleArchivoLog,
			  "Error Al Enviar:%s",
	                  lchrPtrEdoConexion);
}
char *ObtenBaseDatosSeguridad3()
{
char *lchrPtrBDSeguridad3=getenv("BDSeguridad3");
	lchrPtrBDSeguridad3=lchrPtrBDSeguridad3 ? lchrPtrBDSeguridad3 : "Seguridad3";
	return lchrPtrBDSeguridad3;
}

