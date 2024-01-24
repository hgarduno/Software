#include <SoporteAplicacionSeguridad.h>

CQAplicaciones::CQAplicaciones(CSISCOMDatComunicaciones *pCSisDatCom,
			       const char *pchrPtrNmbAplicacion):
	     CQOGenericaServidorSiscom(pCSisDatCom,
				       "libRNAltaGenericaSeguridad3SinAD.so",
				       "RNAltaGenericaSinAD",
					2)
{

	AnexaRegistro("%s%s","VerificaAplicacion",pchrPtrNmbAplicacion);
	EjecutaEnvioSvrSISCOM();
	ObtenRespuesta();
         ObtenRegistro(QSLRegistro);
}
CQAplicaciones::CQAplicaciones(CSISCOMDatComunicaciones *pCSisDatCom,
			       const char *pchrPtrIdAplicacion,
			       const char *pchrPtrNmbAplicacion,
			       const char *pchrPtrDscAplicacion,
			       const char *pchrPtrDirArchivosQt):
	     CQOGenericaServidorSiscom(pCSisDatCom,
				       "libRNAltaGenericaSeguridad3.so",
				       "RNAltaGenerica",
					5)
{

	AnexaRegistro("%s%s%s%s%s",
		      "RegistraAplicacion",
		      pchrPtrIdAplicacion,
		      pchrPtrNmbAplicacion,
		      pchrPtrDscAplicacion,
		      pchrPtrDirArchivosQt);
	EjecutaEnvioSvrSISCOM();
}

int CQAplicaciones::LaAplicacionEstaRegistrada()
{

	return QSLRegistro.size()>1;

}

QString CQAplicaciones::ObtenIdAplicacion()
{
	return QSLRegistro[0];	
}
QString CQAplicaciones::ObtenDscAplicacion()
{
	  return QSLRegistro[2];
}
QString CQAplicaciones::ObtenDirArchivosQt()
{
	return QSLRegistro[3];
}
/*
CQPerfiles::CQPerfiles(CSISCOMDatComunicaciones *pCSisDatCom,
		       QSiscomPerfilBD *pQSPerfilBD,
		       const char *pchrPtrIdPerfilRef):
	     CQOGenericaServidorSiscom(pCSisDatCom,
				       "libRNAltaGenericaSeguridad3.so",
				       "RNAltaGenerica",
					6),
		chrPtrIdPerfilRef(pchrPtrIdPerfilRef)
				       
{
	QSLPerfilesBD.append(pQSPerfilBD);
	CreaRegistrosEnvio();
	EjecutaEnvioSvrSISCOM();
}
CQPerfiles::CQPerfiles(CSISCOMDatComunicaciones *pCSisDatCom,
		       const char *pchrPtrIdAplicacion,
		       int ):
	     CQOGenericaServidorSiscom(pCSisDatCom,
				       "libRNConsultaGenericaSeguridad3.so",
				       "RNConsultaGenerica",
					2)
{
	AnexaRegistro("%s%s",
		      "ObtenPerfilesAplicacionConPantallas",
		      pchrPtrIdAplicacion);
	EjecutaEnvioSvrSISCOM();
	ObtenRespuesta();
	GeneraListaPerfiles();

}
		
CQPerfiles::CQPerfiles(CSISCOMDatComunicaciones *pCSisDatCom,
		       const char *pchrPtrIdAplicacion):
	     CQOGenericaServidorSiscom(pCSisDatCom,
				       "libRNConsultaGenericaSeguridad3.so",
				       "RNConsultaGenerica",
					2),
	      chrPtrIdAplicacion(pchrPtrIdAplicacion)
	     	
{
	AnexaRegistro("%s%s",
		      "ObtenPerfilesAplicacion",
		      pchrPtrIdAplicacion);
	EjecutaEnvioSvrSISCOM();
	ObtenRespuesta();
	GeneraListaPerfiles();
}
CQPerfiles::~CQPerfiles()
{
	QSLPerfilesBD.clear();

}
QSiscomPerfilBD *CQPerfiles::operator[](int pintNRegistro)
{
	return QSLPerfilesBD.at(pintNRegistro);
}
void CQPerfiles::CreaRegistroEnvio(QSiscomPerfilBD *pQSPerfilBD)
{
	AnexaRegistro("%s%s%s%s%s%s",
		      "RegistraPerfiles",
		      pQSPerfilBD->ObtenIdPerfil(),
		      pQSPerfilBD->ObtenIdAplicacion(),
		      pQSPerfilBD->ObtenNmbPerfil(),
		      pQSPerfilBD->ObtenDscPerfil(),
		      chrPtrIdPerfilRef);
}
void CQPerfiles::CreaRegistrosEnvio()
{
int lintContador,
    lintNPerfiles=QSLPerfilesBD.count();
	for(lintContador=0;lintContador<lintNPerfiles;lintContador++)
	 CreaRegistroEnvio(QSLPerfilesBD.at(lintContador));

}
void CQPerfiles::GeneraListaPerfiles()
{
QStringList lQSLRegistro;
	while(!SiguienteRegistro(lQSLRegistro) &&
	       lQSLRegistro.size())
	   QSLPerfilesBD.append(new QSiscomPerfilBD((const char *)lQSLRegistro[0],
						      (const char *)lQSLRegistro[1],
						      (const char *)lQSLRegistro[2],
						      (const char *)lQSLRegistro[3]));
}
int CQPerfiles::CuantosPerfiles()
{
	return QSLPerfilesBD.count();
}



*/






int VeSiLasPantallasEstanRegistradas(CSISCOMDatComunicaciones *pCSisDatCom,
				   const char *pchrPtrIdAplicacion)
{
CQOGenericaServidorSiscom lCQOGenSvrSiscom(pCSisDatCom,
					   "libRNConsultaGenericaSeguridad3.so",
					   "RNConsultaGenerica",
					   2);
QStringList lQSLRegistro;
	lCQOGenSvrSiscom.AnexaRegistro("%s%s",
					"VerificaQueEsteRegistradaLaAplicacion",
					pchrPtrIdAplicacion);
	lCQOGenSvrSiscom.EjecutaEnvioSvrSISCOM();
	lCQOGenSvrSiscom.ObtenRespuesta();
	lCQOGenSvrSiscom.ObtenRegistro(lQSLRegistro);
	return lQSLRegistro[0].toInt();	

}
void ObtenPerfilesDeLaAplicacion(CSISCOMDatComunicaciones *pCSisDatCom,
				 const char *pchrPtrIdAplicacion,
				 QSiscomListaPerfilesBD &pQSLPerfilesBD)
{
CQOGenericaServidorSiscom lCQOGenSvrSiscom(pCSisDatCom,
					   "libRNConsultaGenericaSeguridad3.so",
					   "RNConsultaGenerica",
					   2);
QStringList lQSLRegistro;
	lCQOGenSvrSiscom.AnexaRegistro("%s%s",
					"ObtenPerfilesAplicacion",
					pchrPtrIdAplicacion);
	lCQOGenSvrSiscom.EjecutaEnvioSvrSISCOM();
	lCQOGenSvrSiscom.ObtenRespuesta();
	while(!lCQOGenSvrSiscom.SiguienteRegistro(lQSLRegistro))
	{
	  //MuestraContenidoRegistro(lQSLRegistro,"ObtenPerfilesDeLaAplicacion");
	   pQSLPerfilesBD.append(new QSiscomPerfilBD((const char *)lQSLRegistro[0],
						      (const char *)lQSLRegistro[1],
						      (const char *)lQSLRegistro[2],
						      (const char *)lQSLRegistro[3]));
	}
}
CQUsuario::CQUsuario(long plngIdUsuario,
		     long plngIdAplicacion,
		     long plngIdPerfil,
		     const char *pchrPtrNombre,
		     const char *pchrPtrAPaterno,
		     const char *pchrPtrAMaterno):
	     chrPtrNombre(pchrPtrNombre),
	     chrPtrAPaterno(pchrPtrAPaterno),
	     chrPtrAMaterno(pchrPtrAMaterno),
	     idUsuario(plngIdUsuario),
	     idAplicacion(plngIdAplicacion),
	     idPerfil(plngIdPerfil)
{

}

CQUsuario::CQUsuario(long plngIdUsuario,
		     long plngIdAplicacion,
		     long plngIdPerfil,
		     const char *pchrPtrNombre,
		     const char *pchrPtrAPaterno,
		     const char *pchrPtrAMaterno,
		     const char *pchrPtrFirma,
		     const char *pchrPtrPassword):
	     chrPtrNombre(pchrPtrNombre),
	     chrPtrAPaterno(pchrPtrAPaterno),
	     chrPtrAMaterno(pchrPtrAMaterno),
	     idUsuario(plngIdUsuario),
	     idAplicacion(plngIdAplicacion),
	     idPerfil(plngIdPerfil),
	     chrPtrFirma(pchrPtrFirma),
	     chrPtrPassword(pchrPtrPassword)
{

}
CQUsuario::CQUsuario(long plngIdAplicacion,
		     long plngIdPerfil,
		     const char *pchrPtrNombre,
		     const char *pchrPtrAPaterno,
		     const char *pchrPtrAMaterno):
	     chrPtrNombre(pchrPtrNombre),
	     chrPtrAPaterno(pchrPtrAPaterno),
	     chrPtrAMaterno(pchrPtrAMaterno),
	     idAplicacion(plngIdAplicacion),
	     idPerfil(plngIdPerfil)
{

}
		   
const char *CQUsuario::ObtenNombre()
{
	return chrPtrNombre;
}
const char *CQUsuario::ObtenAPaterno()
{
	return chrPtrAPaterno;
}
const char *CQUsuario::ObtenAMaterno()
{
	return chrPtrAMaterno;
}
const char *CQUsuario::ObtenFirma()
{
	return chrPtrFirma ? chrPtrFirma: "";
}
const char *CQUsuario::ObtenPassword()
{
	return chrPtrPassword ? chrPtrPassword : "";
}
const char *CQUsuario::ObtenCPassword()
{
	return chrPtrCPassword ? chrPtrCPassword : "";
}
const char *CQUsuario::ObtenNmbAplicacion()
{

	return chrPtrNmbAplicacion ? chrPtrNmbAplicacion : "";
}
long CQUsuario::ObtenIdUsuario()
{
	return idUsuario;
}
long CQUsuario::ObtenIdAplicacion()
{
	return idAplicacion;
}
long CQUsuario::ObtenIdPerfil()
{
	return idPerfil;
}	
int CQUsuario::operator==(char **pchrPtrDatUsuario)
{


}
CQUsuario CQUsuario::operator=(CQUsuario pCQUsuario)
{
}
int CQUsuario::operator==(QStringList )
{

}
void CQUsuario::PonFirma(const char *pchrPtrFirma)
{
	chrPtrFirma=pchrPtrFirma;
}
void CQUsuario::PonPassword(const char *pchrPtrPassword)
{
	chrPtrPassword=pchrPtrPassword;
}
CQOperacionesUsuario::CQOperacionesUsuario(CSISCOMDatComunicaciones *pCSisDatCom):
				CSisDatCom(pCSisDatCom)
{

}
CQUsuarios::CQUsuarios()
{

}
void CQUsuarios::AnexaUsuario(CQUsuario *pCQUsuario)
{
		QPLUsuarios.append(pCQUsuario);
}
CQUsuario *CQUsuarios::operator[](long plngIdUsuario)
{

}

CQUsuario *CQUsuarios::operator[](int pintNumUsuario)
{
CQUsuario *lCQURegreso;
	printf("Obteniendo el usuario %d\n",pintNumUsuario);
	return (lCQURegreso=QPLUsuarios.at(pintNumUsuario)) ?  lCQURegreso : 0;
}
int CQOperacionesUsuario::RegistraUsuario(const char *pchrPtrAplicacion,
					   CQUsuario *pCQUsuario)
{
CQOGenericaServidorSiscom lCQOGenSvrSiscom(CSisDatCom,
					   "libRNAltaGenericaSeguridad3.so",
                                           "RNAltaGenerica",
					   8);
	 lCQOGenSvrSiscom.AnexaRegistro("%s%s%s%s%s%s%s%s",
					"RegistraUsuarioDeUnaAplicacion",
					"",
					"",
					"",
					"",
					"",
					"",
					"");

	lCQOGenSvrSiscom.AnexaRegistro("%s%s%s%s%s%s%s%s",
					"",
					pCQUsuario->ObtenNmbAplicacion(),
					pCQUsuario->ObtenNombre(),
					pCQUsuario->ObtenAPaterno(),
					pCQUsuario->ObtenAMaterno(),
					pCQUsuario->ObtenFirma(),
					pCQUsuario->ObtenPassword(),
					pCQUsuario->ObtenCPassword());
	lCQOGenSvrSiscom.EjecutaEnvioSvrSISCOM();
	return lCQOGenSvrSiscom.ObtenCampo(0,0).toInt();



}


void CQOperacionesUsuario::RegistraUsuario(CQUsuario *pCQUsuario)
{
CQOGenericaServidorSiscom lCQOGenSvrSiscom(CSisDatCom,
					   "libRNAltaGenericaSeguridad3.so",
                                           "RNAltaGenerica",
					   7);
	 lCQOGenSvrSiscom.AnexaRegistro("%s%s%s%s%s%s%s",
					"RegistraUsuarios",
					"",
					"",
					"",
					"",
					"",
					"");
	AnexaRegistroUsuario(&lCQOGenSvrSiscom,pCQUsuario);
	lCQOGenSvrSiscom.EjecutaEnvioSvrSISCOM();



}
void CQOperacionesUsuario::ConsultaUsuarios(long plngIdAplicacion,
					    long plngIdPerfil,
					    CQUsuarios &pCQUsuarios)
{
CQOGenericaServidorSiscom lCQOGSvrSiscom(CSisDatCom,
				       "libRNConsultaGenericaSeguridad3.so",
				       "RNConsultaGenerica",
					3);
			lCQOGSvrSiscom.AnexaRegistro("%s%l%l",
						     "ConsultaUsuariosXPerfil",
						     plngIdAplicacion,
						     plngIdPerfil);
			lCQOGSvrSiscom.EjecutaEnvioSvrSISCOM();
			lCQOGSvrSiscom.ObtenRespuesta();
			GeneraListaUsuarios(&lCQOGSvrSiscom,pCQUsuarios);
}
void CQOperacionesUsuario::GeneraListaUsuarios(CQOGenericaServidorSiscom *pCQOGSvrSiscom,
					       CQUsuarios &pCQUsuarios)
{
QStringList lQSLRegistro;

			while(!pCQOGSvrSiscom->SiguienteRegistro(lQSLRegistro) &&
			       lQSLRegistro.count()==8)
			{
			   pCQUsuarios.AnexaUsuario(new CQUsuario(lQSLRegistro[0].toLong(),
								  lQSLRegistro[1].toLong(),
								  lQSLRegistro[2].toLong(),
								  strdup((const char *)lQSLRegistro[3]),
								  strdup((const char *)lQSLRegistro[4]),
								  strdup((const char *)lQSLRegistro[5]),
								  strdup((const char *)lQSLRegistro[6]),
								  strdup((const char *)lQSLRegistro[7])));
			}
}
void CQOperacionesUsuario::RegistraFirma(CQUsuario *pCQUsuario)
{
CQOGenericaServidorSiscom lCQOGenSvrSiscom(CSisDatCom,
					   "libRNAltaGenericaSeguridad3.so",
                                           "RNAltaGenerica",
					   4);
int lintContador;
	 lCQOGenSvrSiscom.AnexaRegistro("%s%l%s%s",
					"RegistraFirmas",
					pCQUsuario->ObtenIdUsuario(),
					pCQUsuario->ObtenFirma(),
					pCQUsuario->ObtenPassword());
	lCQOGenSvrSiscom.EjecutaEnvioSvrSISCOM();


}
void CQOperacionesUsuario::RegistraUsuarios(CQUsuarios  *pCQUsuariosDat)
{
CQOGenericaServidorSiscom lCQOGenSvrSiscom(CSisDatCom,
					   "libRNAltaGenericaSeguridad3.so",
                                           "RNAltaGenerica",
					   7);
int lintContador;
CQUsuario *lCQUsuarioDat;
	 lCQOGenSvrSiscom.AnexaRegistro("%s%s%s%s%s%s%s",
					"RegistraUsuarios",
					"",
					"",
					"",
					"",
					"",
					"");

	for(lintContador=0;
	    (lCQUsuarioDat=(*pCQUsuariosDat)[lintContador]);
	    lintContador++)
	 AnexaRegistroUsuario(&lCQOGenSvrSiscom,lCQUsuarioDat);

	lCQOGenSvrSiscom.EjecutaEnvioSvrSISCOM();

}
void  CQOperacionesUsuario::AnexaRegistroUsuario(CQOGenericaServidorSiscom *pCQOGenSvrSiscom,
						 CQUsuario *pCQUsuario)
{
	pCQOGenSvrSiscom->AnexaRegistro("%s%l%l%s%s%s%s",
					"",
					pCQUsuario->ObtenIdAplicacion(),
					pCQUsuario->ObtenIdPerfil(),
					"",
					pCQUsuario->ObtenNombre(),
					pCQUsuario->ObtenAPaterno(),
					pCQUsuario->ObtenAMaterno());
}
