#include <Personas.h>
Persona::Persona()
{
	SRegistroPro2 		<<
	"Nombre"		<<
	"APaterno"		<<
	"AMaterno"		<<
	"RFC"			<<
	"IdPersona"		<<
	"TipoPersona" 		<<
	"Firma"			<<
	"Password"		<<
	"Departamento"		<<
	"DscTipoPersona"	<<
	"IdAplicacion"		<<
	"EdoFirma";
	
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2				<<
	SiscomCampoPro2("Nombre","")		<<  
	SiscomCampoPro2("APaterno","")		<<  
	SiscomCampoPro2("AMaterno","")		<<  
	SiscomCampoPro2("RFC","")		<<  
	SiscomCampoPro2("IdPersona","")		<<  
	SiscomCampoPro2("TipoPersona","")	<<
	SiscomCampoPro2("Firma","")		<<
	SiscomCampoPro2("Password","")		<<
	SiscomCampoPro2("Departamento","")	<<
	SiscomCampoPro2("DscTipoPersona","")	<<
	SiscomCampoPro2("IdAplicacion","")	<<
	SiscomCampoPro2("EdoFirma","");
	SRegistrosPro2.SiscomAnexaRegistro();
}
Persona::Persona(const char *pchrPtrNombre,
		 const char *pchrPtrAPaterno,
		 const char *pchrPtrAMaterno,
		 const char *pchrPtrRFC,
		 const char *pchrPtrIdPersona,
		 const char *pchrPtrTipoPersona,
		 const char *pchrPtrFirma,
		 const char *pchrPtrPassword,
		 const char *pchrPtrDepartamento,
		 const char *pchrPtrDscTipoPersona,
		 const char *pchrPtrIdAplicacion,
		 const char *pchrPtrEdoFirma)
{
	SRegistroPro2 		<<
	"Nombre"		<<
	"APaterno"		<<
	"AMaterno"		<<
	"RFC"			<<
	"IdPersona"		<<
	"TipoPersona" 		<<
	"Firma"			<<
	"Password"		<<
	"Departamento"		<<
	"DscTipoPersona"	<<
	"IdAplicacion"		<<
	"EdoFirma";
	
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2					<<
	SiscomCampoPro2("Nombre",pchrPtrNombre)		<<  
	SiscomCampoPro2("APaterno",pchrPtrAPaterno)		<<  
	SiscomCampoPro2("AMaterno",pchrPtrAMaterno)		<<  
	SiscomCampoPro2("RFC",pchrPtrRFC)		<<  
	SiscomCampoPro2("IdPersona",pchrPtrIdPersona)		<<  
	SiscomCampoPro2("TipoPersona",pchrPtrTipoPersona)	<<
	SiscomCampoPro2("Firma",pchrPtrFirma)			<<
	SiscomCampoPro2("Password",pchrPtrPassword)		<<
	SiscomCampoPro2("Departamento",pchrPtrDepartamento)	<<
	SiscomCampoPro2("DscTipoPersona",pchrPtrDscTipoPersona) <<
	SiscomCampoPro2("IdAplicacion",pchrPtrIdAplicacion)	<<
	SiscomCampoPro2("EdoFirma",pchrPtrEdoFirma);
	SRegistrosPro2.SiscomAnexaRegistro();
}
void Persona::AnexarMediosComunicacion(MediosComunicacion pMComunicacion)
{
	MComunicacion=pMComunicacion;
}
void Persona::AnexarMedioComunicacion(MedioComunicacion *pMComunicacion)
{
	MComunicacion << pMComunicacion;
}
void Persona::AnexarDireccion(Direccion *pDireccion)
{
	DDirecciones << pDireccion;
}
Persona &Persona::operator<<(MedioComunicacion *pMComunicacion)
{
	MComunicacion << pMComunicacion;
	return *this;
}
Persona &Persona::operator<<(Direccion *pDireccion)
{
	DDirecciones << pDireccion;
	return *this;
}
Persona &Persona::operator>>(MediosComunicacion &pMComunicacion)
{
	pMComunicacion=MComunicacion;
	return *this;
}
Persona &Persona::operator>>(Direcciones &pDirecciones)
{
	pDirecciones=DDirecciones;
	return *this;
}
Personas::Personas()
{

}
Personas &Personas::operator<<(Persona *pPersona)
{
	append(pPersona);

	return *this;

}
ConsultaPersonas::ConsultaPersonas()
{

}
ConsultaPersonas::ConsultaPersonas(SiscomDatCom *pSDatCom,
				   const char *pchrPtrNombre,
				   const char *pchrPtrAPaterno,
				   const char *pchrPtrAMaterno,
				   const char *pchrPtrRFC,
				   const char *pchrPtrIdPersona,
				   const char *pchrPtrTipoPersona,
				   const char *pchrPtrIdExpendio,
				   Personas &pPersonas)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta << 
		new SiscomParametroConsulta(pchrPtrNombre)  	<<
		new SiscomParametroConsulta(pchrPtrAPaterno)  	<<
		new SiscomParametroConsulta(pchrPtrAMaterno)  	<<
		new SiscomParametroConsulta(pchrPtrRFC)  	<<
		new SiscomParametroConsulta(pchrPtrIdPersona)  	<<
		new SiscomParametroConsulta(pchrPtrTipoPersona) <<
		new SiscomParametroConsulta(pchrPtrIdExpendio); 
SiscomGeneralOperacionesSrv lSGenOp(pSDatCom,
				    (QPtrList<SiscomInformacion> *)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaPersonas");
		GeneraPersonas((const SiscomComunicaSrv *)lSGenOp,pPersonas);
}
void ConsultaPersonas::ConsultaUsuariosSeguridad3(SiscomDatCom *pSisDatCom,
						  Personas &pPersonas)
{
SiscomParametrosConsulta lSPConsulta;
	
		lSPConsulta <<
		new SiscomParametroConsulta("FirmasSeguridad3") <<
		new SiscomParametroConsulta(getenv("Aplicacion"));

SiscomGeneralOperacionesSrv lSGenOp(pSisDatCom,
				    (QPtrList<SiscomInformacion> *)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaPersonas");
		GeneraPersonas((const SiscomComunicaSrv *)lSGenOp,pPersonas);


}
Persona *ConsultaPersonas::ObtenDatosFirma(SiscomDatCom *pSisDatCom,
					   const char *pchrPtrFirma)
{
SiscomParametrosConsulta lSPConsulta;
Personas lPersonas;	
		lSPConsulta <<
		new SiscomParametroConsulta("DatosFirma") <<
		new SiscomParametroConsulta(pchrPtrFirma);

SiscomGeneralOperacionesSrv lSGenOp(pSisDatCom,
				    (QPtrList<SiscomInformacion> *)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaPersonas");
		GeneraPersonas((const SiscomComunicaSrv *)lSGenOp,lPersonas);

		return lPersonas.at(0);
}
void ConsultaPersonas::EmpleadosExpendio(SiscomDatCom *pSisDatCom,
					 const char *pchrPtrIdExpendio,
					 Personas &pPersonas)
{
SiscomParametrosConsulta lSPConsulta;
Personas lPersonas;	
		lSPConsulta <<
		new SiscomParametroConsulta("EmpleadosExpendio") <<
		new SiscomParametroConsulta(pchrPtrIdExpendio);

SiscomLog("Buscando los empleados del expendio");
SiscomGeneralOperacionesSrv lSGenOp(pSisDatCom,
				    (QPtrList<SiscomInformacion> *)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaPersonas");
		if(!lSGenOp.EstadoConexion())
		GeneraPersonas((const SiscomComunicaSrv *)lSGenOp,pPersonas);
		else
		SiscomLog("NO Se pudo conectar al servidor");
		


}
Persona *ConsultaPersonas::ValidaFirmaEmpleado(SiscomDatCom *pSisDatCom,
					       const char *pchrPtrAplicacion,
					       const char *pchrPtrIdExpendio,
					       Persona *pEmpleado)
{
SiscomParametrosConsulta lSPConsulta;
Personas lPersonas;	
		lSPConsulta <<
		new SiscomParametroConsulta("ValidaFirmaEmpleado") <<
		new SiscomParametroConsulta(pchrPtrIdExpendio)			<<
		new SiscomParametroConsulta(pEmpleado->SRegistrosPro2["IdPersona"]) <<
		new SiscomParametroConsulta(pEmpleado->SRegistrosPro2["Firma"])     <<
		new SiscomParametroConsulta(pEmpleado->SRegistrosPro2["Password"]) <<
		new SiscomParametroConsulta(pchrPtrAplicacion);

SiscomGeneralOperacionesSrv lSGenOp(pSisDatCom,
				    (QPtrList<SiscomInformacion> *)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("ConsultaPersonas");
		lPersonas << pEmpleado;
		GeneraPersonas((const SiscomComunicaSrv *)lSGenOp,lPersonas);

	return lPersonas.at(1);


}
void ConsultaPersonas::GeneraPersonas(const SiscomComunicaSrv *pSComunicaSrv,
				      Personas &pPersonas)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
	for(;
	     !lSRegistrosPro2.SiscomEsElUltimoRegistro();
	     ++lSRegistrosPro2)
	   pPersonas <<
	             new Persona(lSRegistrosPro2["nombre"],
		     		 lSRegistrosPro2["apaterno"],
				 lSRegistrosPro2["amaterno"],
				 lSRegistrosPro2["rfc"],
				 lSRegistrosPro2["idpersona"],
				 lSRegistrosPro2["tipopersona"],
				 lSRegistrosPro2["firma"],
				 lSRegistrosPro2["password"],
				 "",
				 "",
				 "",
				 lSRegistrosPro2["edofirma"]);
	delete pSComunicaSrv;
}


Persona *ConsultaPersonaRFC(SiscomDatCom *pSisDatCom,
			    const char *pchrPtrRFC)
{
Personas lPersonas;
ConsultaPersonas lCnsPersonas(pSisDatCom,
			      "",
			      "",
			      "",
			      pchrPtrRFC,
			      "",
			      "",
			      "",
			      lPersonas);

	return lPersonas.at(0);	
}
void AsignaEmpleadoExpendio(SiscomDatCom *pSisDatCom,	
			   const char *pchrPtrIdEmpleado,
			   const char *pchrPtrIdExpendio)
{
SiscomParametrosConsulta lSPConsulta;
Personas lPersonas;	
		lSPConsulta <<
		new SiscomParametroConsulta(pchrPtrIdEmpleado) <<
		new SiscomParametroConsulta(pchrPtrIdExpendio);

SiscomGeneralOperacionesSrv lSGenOp(pSisDatCom,
				    (QPtrList<SiscomInformacion> *)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("AsignaEmpleadosExp");


}

RegistroEnvioPersona::RegistroEnvioPersona(Persona *pPersona):
		PPersona(pPersona)
{
	AnexaGenerales();
	AnexaDirecciones();
	AnexaMediosComunicacion();

}
void RegistroEnvioPersona::AnexaGenerales()
{
FormaRegistroEnvio();
SRegistrosPro2									<<
SiscomCampoPro2("Nombre",PPersona->SRegistrosPro2["Nombre"])			<<
SiscomCampoPro2("APaterno",PPersona->SRegistrosPro2["APaterno"])		<<
SiscomCampoPro2("AMaterno",PPersona->SRegistrosPro2["AMaterno"])		<<
SiscomCampoPro2("RFC",PPersona->SRegistrosPro2["RFC"])				<<
SiscomCampoPro2("IdPersona",PPersona->SRegistrosPro2["IdPersona"])		<<
SiscomCampoPro2("TipoPersona",PPersona->SRegistrosPro2["TipoPersona"])		<<
SiscomCampoPro2("DscTipoPersona",PPersona->SRegistrosPro2["DscTipoPersona"])		<<
SiscomCampoPro2("IdAplicacion",PPersona->SRegistrosPro2["IdAplicacion"])		<<
SiscomCampoPro2("Firma",PPersona->SRegistrosPro2["Firma"])			<<
SiscomCampoPro2("Password",PPersona->SRegistrosPro2["Password"])		<<
SiscomCampoPro2("Departamento",PPersona->SRegistrosPro2["Departamento"])	<<
SiscomCampoPro2("Calle","")							<<
SiscomCampoPro2("Numero","")							<<
SiscomCampoPro2("Colonia","")							<<
SiscomCampoPro2("CP","")							<<
SiscomCampoPro2("Municipio","")							<<
SiscomCampoPro2("Estado","")							<<
SiscomCampoPro2("Referencias","")						<<
SiscomCampoPro2("NmbMedioCom","")						<<
SiscomCampoPro2("Medio","");
SRegistrosPro2.SiscomAnexaRegistro();
}
void RegistroEnvioPersona::AnexaDirecciones()
{
Direcciones lDEmpleado;
Direccion *lDireccion;
	(*PPersona) >> lDEmpleado;
	for(lDireccion=lDEmpleado.first();
	    lDireccion;
	    lDireccion=lDEmpleado.next())
	{
SRegistroPro2.SiscomRegistroPro2ReAsigna();
FormaRegistroEnvio();
SRegistrosPro2									<<
SiscomCampoPro2("Nombre","")							<<
SiscomCampoPro2("APaterno","")							<<
SiscomCampoPro2("AMaterno","")							<<
SiscomCampoPro2("RFC","")							<<
SiscomCampoPro2("IdPersona","")							<<
SiscomCampoPro2("TipoPersona","")						<<
SiscomCampoPro2("DscTipoPersona","")						<<
SiscomCampoPro2("IdAplicacion","")						<<
SiscomCampoPro2("Firma","")							<<
SiscomCampoPro2("Password","")							<<
SiscomCampoPro2("Departamento","")						<<
SiscomCampoPro2("Calle",lDireccion->SRegistrosPro2["Calle"])			<<
SiscomCampoPro2("Numero",lDireccion->SRegistrosPro2["Numero"])			<<
SiscomCampoPro2("Colonia",lDireccion->SRegistrosPro2["Colonia"])		<<
SiscomCampoPro2("CP",lDireccion->SRegistrosPro2["CP"])				<<
SiscomCampoPro2("Municipio",lDireccion->SRegistrosPro2["Municipio"])		<<
SiscomCampoPro2("Estado",lDireccion->SRegistrosPro2["Estado"])			<<
SiscomCampoPro2("Referencias",lDireccion->SRegistrosPro2["Referencia"])	<<
SiscomCampoPro2("NmbMedioCom","")						<<
SiscomCampoPro2("Medio","");
SRegistrosPro2.SiscomAnexaRegistro();
	}
}
void RegistroEnvioPersona::AnexaMediosComunicacion()
{
MediosComunicacion lMsComunicacion;
MedioComunicacion *lMComunicacion;
	(*PPersona) >> lMsComunicacion;
	for(lMComunicacion=lMsComunicacion.first();
	    lMComunicacion;
	    lMComunicacion=lMsComunicacion.next())
	{
SRegistroPro2.SiscomRegistroPro2ReAsigna();
FormaRegistroEnvio();
SRegistrosPro2									<<
SiscomCampoPro2("Nombre","")							<<
SiscomCampoPro2("APaterno","")							<<
SiscomCampoPro2("AMaterno","")							<<
SiscomCampoPro2("RFC","")							<<
SiscomCampoPro2("IdPersona","")							<<
SiscomCampoPro2("TipoPersona","")						<<
SiscomCampoPro2("DscTipoPersona","")						<<
SiscomCampoPro2("IdAplicacion","")						<<
SiscomCampoPro2("Firma","")							<<
SiscomCampoPro2("Password","")							<<
SiscomCampoPro2("Departamento","")						<<
SiscomCampoPro2("Calle","")							<<
SiscomCampoPro2("Numero","")							<<
SiscomCampoPro2("Colonia","")							<<
SiscomCampoPro2("CP","")							<<
SiscomCampoPro2("Municipio","")							<<
SiscomCampoPro2("Estado","")							<<
SiscomCampoPro2("Referencias","")						<<
SiscomCampoPro2("NmbMedioCom",lMComunicacion->SRegistrosPro2["NmbMedio"])	<<
SiscomCampoPro2("Medio",lMComunicacion->SRegistrosPro2["Medio"]);
SRegistrosPro2.SiscomAnexaRegistro();
}

}
void RegistroEnvioPersona::FormaRegistroEnvio()
{
	SRegistroPro2 		<<
	"Nombre"		<<
	"APaterno"		<<
	"AMaterno"		<<
	"RFC"			<<
	"IdPersona"		<<
	"TipoPersona" 		<<
	"DscTipoPersona"	<<
	"IdAplicacion"		<<
	"Firma"			<<
	"Password"		<<
	"Departamento"		<<
	"Calle"			<<
	"Numero"		<<
	"Colonia"		<<
	"CP"			<<
	"Municipio"		<<
	"Estado"		<<
	"Referencias"		<<
	"NmbMedioCom"		<<
	"Medio";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
}
RegistrosEnvioPersona::RegistrosEnvioPersona()
{

}
RegistrosEnvioPersona &RegistrosEnvioPersona::operator<<(RegistroEnvioPersona *pREPersona)
{
	append(pREPersona);
	return *this;
}
OpPersonas::OpPersonas(SiscomDatCom *pSisDatCom):
	SisDatCom(pSisDatCom)
{


}
void OpPersonas::RegistrarPersona(Persona *pPersona)
{
RegistrosEnvioPersona lRegsEnvioP;

		lRegsEnvioP << new RegistroEnvioPersona(pPersona);
SiscomGeneralOperacionesSrv lSGenOp(
                                SisDatCom,
				(QPtrList<SiscomInformacion>*)&lRegsEnvioP);
lSGenOp.SiscomEjecutaEnvio2("RegistraPersonas");
}
void OpPersonas::CambiaEstatusFirma(const char *pchrPtrIdExpendio,
				   const char *pchrPtrIdUsuario,
				   const char *pchrPtrEdo)
{
SiscomParametrosConsulta lSPConsulta;

		lSPConsulta << 
		new SiscomParametroConsulta(pchrPtrIdExpendio)  <<
		new SiscomParametroConsulta(pchrPtrIdUsuario)  	<<
		new SiscomParametroConsulta(pchrPtrEdo);
SiscomGeneralOperacionesSrv lSGenOp(SisDatCom,
				    (QPtrList<SiscomInformacion> *)&lSPConsulta);
		lSGenOp.SiscomEjecutaEnvio("CambiaEstadoFirma");


}
