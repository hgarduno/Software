#include <Perfiles.h>
#include <Personas.h>
#include <TiposPersona.h>
#include <GeneralBibliotecaSeguridad3.h>

CQ_Persona::CQ_Persona(const char *pchrPtrNombre,
			const char *pchrPtrAPaterno,
			const char *pchrPtrAMaterno,
			const char *pchrPtrRFC,
			const char *pchrPtrTipoPersona,
			const char *pchrPtrIdPersona):
		chrPtrNombre(pchrPtrNombre),
		chrPtrAMaterno(pchrPtrAMaterno),
		chrPtrAPaterno(pchrPtrAPaterno),
		chrPtrRFC(pchrPtrRFC),
		chrPtrTipoPersona(pchrPtrTipoPersona),
		chrPtrIdPersona(pchrPtrIdPersona),
		chrPtrEdoRegistro(""),
	        QSPerfilBD(0)	,
		CQFirma(0)

{

}
const char *CQ_Persona::ObtenNombre()
{
	return chrPtrNombre;
}

const char *CQ_Persona::ObtenAPaterno()
{
	return chrPtrAPaterno;
}

const char *CQ_Persona::ObtenAMaterno()
{
	return chrPtrAMaterno;
}
const char *CQ_Persona::ObtenRFC()
{
	return chrPtrRFC;
}
const char *CQ_Persona::ObtenIdUsuarioBDSeguridad3()
{
	return chrPtrIdUsuarioBDSeg3;
}
const char *CQ_Persona::ObtenIdPersona()
{
	return chrPtrIdPersona;
}

const char *CQ_Persona::ObtenEdoRegistro()
{
	return chrPtrEdoRegistro;
}
const CQ_Direcciones &CQ_Persona::ObtenDirecciones()
{
	return CQDirDatos;
}
const CQ_Telefonos &CQ_Persona::ObtenTelefonos()
{
	return CQTelTelefonos;
}
const CQ_Apodos &CQ_Persona::ObtenApodos()
{
	return CQApodos;
}
const CQ_Correos &CQ_Persona::ObtenCorreos()
{
	return CQCoDatos;
}
CQ_Firma *CQ_Persona::ObtenFirma()
{
	return CQFirma;
}
QSiscomPerfilBD *CQ_Persona::ObtenPerfil()
{
	return QSPerfilBD;
}
void CQ_Persona::PonNombre(const char *pchrPtrNombre)
{
	chrPtrNombre=pchrPtrNombre;
}
void CQ_Persona::PonAPaterno(const char *pchrPtrAPaterno)
{
	chrPtrAPaterno=pchrPtrAPaterno;
}
void CQ_Persona::PonAMaterno(const char *pchrPtrAMaterno)
{
	chrPtrAMaterno=pchrPtrAMaterno;
}
void CQ_Persona::PonRFC(const char *pchrPtrRFC)
{
	chrPtrRFC=pchrPtrRFC;
}
void CQ_Persona::PonIdUsuarioBDSeguridad3(const char *pchrPtrIdUsuarioBDSeg3)
{
	chrPtrIdUsuarioBDSeg3=pchrPtrIdUsuarioBDSeg3;
}
void CQ_Persona::PonIdPersona(const char *pchrPtrIdPersona)
{
	chrPtrIdPersona=pchrPtrIdPersona;
}
void CQ_Persona::PonTipoPersona(const char *pchrPtrTipoPersona)
{
	chrPtrTipoPersona=pchrPtrTipoPersona;
}
void CQ_Persona::PonEdoRegistro(const char *pchrPtrEdoRegistro)
{
	chrPtrEdoRegistro=pchrPtrEdoRegistro;
}
void CQ_Persona::PonPerfil(QSiscomPerfilBD *pQSPerfilBD)
{
	QSPerfilBD=pQSPerfilBD;
}

void CQ_Persona::PonFirma(CQ_Firma *pCQFirma)
{
	CQFirma=pCQFirma;
}
void CQ_Persona::AnexaDireccion(CQ_Direccion *pCQDireccion)
{
	CQDirDatos.append(pCQDireccion);	
}
void CQ_Persona::AnexaTelefono(CQ_Telefono *pCQTelefono)
{
	CQTelTelefonos.append(pCQTelefono);
}
void CQ_Persona::AnexaCorreo(CQ_Correo *pCQCorreo)
{
	CQCoDatos.append(pCQCorreo);
}
void CQ_Persona::AnexaApodo(CQ_Apodo *pCQApodo)
{
	CQApodos.append(pCQApodo);
}

CQ_Personas::CQ_Personas()
{

}
const CQ_Personas &CQ_Personas::operator<<(CQ_Persona *pCQPersona)
{
	append(pCQPersona);
}
CQCtrPersonas::CQCtrPersonas(CSISCOMDatComunicaciones *pCSisDatCom,
			    CQCtrPersonas::CtrPersonas pCQCtrOperacion,
			    CQ_Personas *pCQPersonas):
		CSisDatCom(pCSisDatCom)
{
	switch(pCQCtrOperacion)
	{
		case CQCtrPersonas::Registrar:
			RegistraPersonas(pCQPersonas);
		break;
	}

}
CQCtrPersonas::CQCtrPersonas(CSISCOMDatComunicaciones *pCSisDatCom,
			     QStringList pQSLParametros,
			     CQ_Personas *pCQPersonas):
	CSisDatCom(pCSisDatCom)
{
	
		ConsultaLasPersonas(pQSLParametros,pCQPersonas);
		AsignaRespuestaConsulta(pCQPersonas);

}
void CQCtrPersonas::AnexaRegistroVacio()
{
CQOGSvrSiscom->AnexaRegistro(__ParametrosRegistraPersona__,
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "");

}
void CQCtrPersonas::AnalizaRespuesta(CQ_Personas *pCQPersonas)
{

}
void CQCtrPersonas::RegistraPersonas(CQ_Personas *pCQPersonas)
{
	FormaEnvioPersonas(pCQPersonas);
	AnalizaRespuesta(pCQPersonas);
}
void CQCtrPersonas::FormaEnvioPersonas(CQ_Personas *pCQPersonas)
{
CQ_Persona *lCQPersona;
CQ_Direccion *lCQDireccion;
CQ_Telefono *lCQTelefono;
CQ_Correo *lCQCorreo;
CQ_Apodo *lCQApodo;
CQ_Firma *lCQFirma;
QSiscomPerfilBD *lQSPerfilBD;

CQ_Direcciones lCQDirecciones;
CQ_Correos lCQCorreos;
CQ_Telefonos lCQTelefonos;
CQ_Apodos lCQApodos;

      CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
		      				  "libRNSistemaElFresno.so",
						  "RNOperacionesElFresno",
						  __NumParametrosRegistraPersona__);
      CQOGSvrSiscom->AnexaRegistro(__ParametrosRegistraPersona__,
		      		   "RegistraPersonas",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "",
				   "");
	
	for(lCQPersona=pCQPersonas->first();
	    lCQPersona;
	    lCQPersona=pCQPersonas->next())
	{
	  lCQDirecciones=lCQPersona->ObtenDirecciones(); 
	  lCQCorreos=lCQPersona->ObtenCorreos();
	  lCQTelefonos=lCQPersona->ObtenTelefonos();
	  lCQApodos=lCQPersona->ObtenApodos();
	  lCQApodo=lCQApodos.at(0);
	  lQSPerfilBD=lCQPersona->ObtenPerfil();
	  lCQFirma=lCQPersona->ObtenFirma();
	  
	  CQOGSvrSiscom->AnexaRegistro(__ParametrosRegistraPersona__,
		      		       "",
				       lCQPersona->ObtenNombre(),
				       lCQPersona->ObtenAPaterno(),
				       lCQPersona->ObtenAMaterno(),
				       lCQPersona->ObtenRFC(),
				       lCQPersona->ObtenIdPersona(),
				       lQSPerfilBD->ObtenIdPerfil(),
				       lCQPersona->ObtenEdoRegistro(),
				       "",
				       "",
				       "",
				       "",
				       "",
				       "",
				       "",
				       "",
				       "",
				       "",
				       "",
				       "",
				       "",
				       lCQApodo ? lCQApodo->ObtenApodo() : "",
				       "",
				       "",
				       "",
				       lCQFirma ? lCQFirma->ObtenFirma() : "",
				       lQSPerfilBD ? lQSPerfilBD->ObtenIdPerfil() : "" ,
				       lQSPerfilBD ? lQSPerfilBD->ObtenNmbPerfil() : "",
				       lQSPerfilBD ? lQSPerfilBD->ObtenDscPerfil() : "");
	   for(lCQDireccion=lCQDirecciones.first();
	       lCQDireccion;
	       lCQDireccion=lCQDirecciones.next())
	   {
		CQOGSvrSiscom->AnexaRegistro(__ParametrosRegistraPersona__,
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
				 	lCQDireccion->ObtenCalle(),
					lCQDireccion->ObtenNumero(),
					lCQDireccion->ObtenCP(),
					lCQDireccion->ObtenColonia(),
					lCQDireccion->ObtenDelegacion(),
					lCQDireccion->ObtenEstado(),
				        lCQDireccion->ObtenReferencias(),
					lCQDireccion->ObtenEdoRegistro(),
					"",
					"",
					"",
					"",
					"",
					"",
					"",
					"",
					"",
					"",
					"",
					"",
				       "");

	   }
	   AnexaRegistroVacio(); 
	   for(lCQTelefono=lCQTelefonos.first();
	       lCQTelefono;
	       lCQTelefono=lCQTelefonos.next())
		CQOGSvrSiscom->AnexaRegistro(__ParametrosRegistraPersona__,
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
				       lCQTelefono->ObtenTelefono(),
				       lQSPerfilBD->ObtenIdPerfil(),
				       lCQTelefono->ObtenEdoRegistro(),
				       "",
				       "",
				       "",
				       "",
				       "",
				       "",
				       "",
				       "",
				       "",
				       "");

	   AnexaRegistroVacio(); 
	   for(lCQCorreo=lCQCorreos.first();
	       lCQCorreo;
	       lCQCorreo=lCQCorreos.next())
	    CQOGSvrSiscom->AnexaRegistro(__ParametrosRegistraPersona__,
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
				       lCQCorreo->ObtenCorreo(),
				       lCQPersona->ObtenIdPersona(),
				       lCQCorreo->ObtenEdoRegistro(),
					"",
					"",
					"",
					"",
					"",
					"",
					"");
	   /*
		AnexaRegistroVacio();
		for(lCQApodo=lCQApodos.first();
		    lCQApodo;
		    lCQApodo=lCQApodos.next())
		CQOGSvrSiscom->AnexaRegistro(__ParametrosRegistraPersona__,
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
		      		             "",
				       lCQApodo->ObtenApodo(),
				       lCQPersona->ObtenIdPersona(),
				       lCQApodo->ObtenEdoRegistro(),
					"",
					"",
					"",
					"");
		
		*/

	}	
	CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
	chrPtrIdPersona=(const char *)CQOGSvrSiscom->ObtenCampo(0,0);


}
const char *CQCtrPersonas::ObtenIdPersona()
{
	return chrPtrIdPersona;
}
void CQCtrPersonas::ConsultaLasPersonas(QStringList pQSLParametros,
					CQ_Personas *pCQPersonas)
{
const char *lchrPtrFormatoConsulta="%s%s";
int lintNParametros=2;
int lintContador;
	CQOGSvrSiscom=new CQOGenericaServidorSiscom(CSisDatCom,
		      				  "libRNSistemaElFresno.so",
						  "RNOperacionesElFresno",
						   lintNParametros);
	/*	Para esta consulta se pasara en el parametro
	 *	pQSLParametros en la posicion 0, el tipo de consulta
	 *	los cuales podran ser ConsultaXAPaterno, ConsultaXApodo
	 *	y en la posicion 1 de la lista se pasara o el Apellido
	 *	Paterno, o el Apodo
	 */
	
      CQOGSvrSiscom->AnexaRegistro(lchrPtrFormatoConsulta,
		      		   (const char *)pQSLParametros[0],
				   "");
      for(lintContador=1;lintContador<pQSLParametros.size();lintContador++)
      CQOGSvrSiscom->AnexaRegistro(lchrPtrFormatoConsulta,
		      		   "",
				   (const char *)pQSLParametros[lintContador]);
	CQOGSvrSiscom->EjecutaEnvioSvrSISCOM();
        CQOGSvrSiscom->ObtenRespuesta();
}
void CQCtrPersonas::AsignaRespuestaConsulta(CQ_Personas *pCQPersonas)
{
	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	       QSLRegistro.count()==20)
	{
	  AsignaGenerales();
	  AsignaDirecciones();
	  AsignaTelefonos();
	  AsignaCorreos();
	  pCQPersonas->append(CQPersona);
	}

}
void CQCtrPersonas::AsignaGenerales()
{
	CQPersona=new CQ_Persona((const char *)QSLRegistro[2],
				 (const char *)QSLRegistro[3],
				 (const char *)QSLRegistro[4],
				 (const char *)QSLRegistro[5],
				 (const char *)QSLRegistro[1],
				 (const char *)QSLRegistro[0]);	
	CQPersona->AnexaApodo(new CQ_Apodo((const char *)QSLRegistro[0],
					   (const char *)QSLRegistro[8]));
}
void CQCtrPersonas::AsignaDirecciones()
{
	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	      !SISCOMEsElRegistroVacio(QSLRegistro))
	     CQPersona->AnexaDireccion(new CQ_Direccion(
					 (const char *)QSLRegistro[9],
					 (const char *)QSLRegistro[10],
					 (const char *)QSLRegistro[11],
					 (const char *)QSLRegistro[12],
					 (const char *)QSLRegistro[13],
					 (const char *)QSLRegistro[14],
					 (const char *)QSLRegistro[15])
				       );
}


void CQCtrPersonas::AsignaTelefonos()
{
	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	      !SISCOMEsElRegistroVacio(QSLRegistro))
	  	CQPersona->AnexaTelefono(new CQ_Telefono(
						  "",
						  (const char *)QSLRegistro[16]));
}


void CQCtrPersonas::AsignaCorreos()
{

	while(!CQOGSvrSiscom->SiguienteRegistro(QSLRegistro) &&
	      !SISCOMEsElRegistroVacio(QSLRegistro))
	   CQPersona->AnexaCorreo(new CQ_Correo("",
					(const char *)QSLRegistro[17]));
}
CQ_Persona *ObtenDatosUsuarioFirmado(CSISCOMDatComunicaciones *pCSisDatCom)
{
CQ_Personas lCQPRegreso;
CQCtrPersonas lCQCPersonas(pCSisDatCom,
			   QStringList() <<
			   QString("ConsultarPersonas") <<
			   "ConsultaPersonaPorFirma" <<
			   pCSisDatCom->ObtenUsuario() <<
			   "" <<
			   "" <<
			   "" <<
			   "", 
			   &lCQPRegreso);

return lCQPRegreso.at(0);
}
