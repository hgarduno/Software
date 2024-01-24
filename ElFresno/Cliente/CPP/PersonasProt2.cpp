#include <PersonasProt2.h>
#include <GeneralBibliotecaSeguridad3.h>

RegConsultaPersona::RegConsultaPersona(const char *pchrPtrNombre,
				       const char *pchrPtrAPaterno,
				       const char *pchrPtrAMaterno,
				       const char *pchrPtrRFC)
{
	SRegistroPro2 		<<
	"Nombre"		<<
	"APaterno"		<<
	"AMaterno"		<<
	"RFC";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2 			<<
	SiscomCampoPro2("Nombre",pchrPtrNombre) <<
	SiscomCampoPro2("APaterno",pchrPtrAPaterno) <<
	SiscomCampoPro2("AMaterno",pchrPtrAMaterno) <<
	SiscomCampoPro2("RFC",pchrPtrRFC);
	SRegistrosPro2.SiscomAnexaRegistro();
}
RegConsultasPersona::RegConsultasPersona()
{

}

RegConsultasPersona &RegConsultasPersona::operator<<(RegConsultaPersona *pRCnsPersona)
{
	append(pRCnsPersona);
	return *this;
}

PersonasProt2::PersonasProt2()
{

}
void PersonasProt2::GeneraRegistros(const SiscomComunicaSrv *pSComunicaSrv)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
CQ_Persona *lCQPersona;
	for(;
	      !lSRegistrosPro2.SiscomEsElUltimoRegistro();
	    ++lSRegistrosPro2)
	 {
	    lCQPersona=new CQ_Persona(lSRegistrosPro2["Nombre"],
	    			     lSRegistrosPro2["APaterno"],
				     lSRegistrosPro2["AMaterno"],
				     lSRegistrosPro2["RFC"],
				     lSRegistrosPro2["TipoPersona"],
				     lSRegistrosPro2["IdPersona"]);
	    AnexaDirecciones(lSRegistrosPro2,lCQPersona);
	    AnexaTelefonos(lSRegistrosPro2,lCQPersona);
	    AnexaCorreos(lSRegistrosPro2,lCQPersona);
	    AnexaFirma(lSRegistrosPro2,lCQPersona);
	    append(lCQPersona);
	 }

}
void PersonasProt2::AnexaDirecciones(SiscomRegistrosPro2 &pSRegistrosPro2,
				     CQ_Persona *pCQPersona)
{
	++pSRegistrosPro2;
	for(;
		!pSRegistrosPro2.SiscomEsElUltimoRegistro() &&
		!strcmp(pSRegistrosPro2["TipoDato"],"Direccion");
	     ++pSRegistrosPro2)
	
		if(DireccionValida(pSRegistrosPro2))
		{
		  pCQPersona->AnexaDireccion(
		  		new CQ_Direccion(
					pSRegistrosPro2["Calle"],
					pSRegistrosPro2["Numero"],
					pSRegistrosPro2["Colonia"],
					pSRegistrosPro2["CP"],
					pSRegistrosPro2["Municipio"],
					pSRegistrosPro2["Estado"],
					pSRegistrosPro2["Referencias"]
					 )
				);
		}
}


void PersonasProt2::AnexaTelefonos(SiscomRegistrosPro2 &pSRegistrosPro2,
				     CQ_Persona *pCQPersona)
{
	for(;
	     !pSRegistrosPro2.SiscomEsElUltimoRegistro() &&
	     !strcmp(pSRegistrosPro2["TipoDato"],"Telefono");
	     ++pSRegistrosPro2)
	 if(pSRegistrosPro2["Telefono"][0])
	  pCQPersona->AnexaTelefono(
	  		new CQ_Telefono(
				"",
				pSRegistrosPro2["Telefono"]
				)
			);
	  				
}


void PersonasProt2::AnexaCorreos(SiscomRegistrosPro2 &pSRegistrosPro2,
				     CQ_Persona *pCQPersona)
{
	for(;
	     !pSRegistrosPro2.SiscomEsElUltimoRegistro() &&
	     !strcmp(pSRegistrosPro2["TipoDato"],"Correos");
	     ++pSRegistrosPro2)
	 if(pSRegistrosPro2["Correos"][0])
	 pCQPersona->AnexaCorreo(
	 		new CQ_Correo(
				"",	
				pSRegistrosPro2["Correo"]
				)
			);
}


void PersonasProt2::AnexaFirma(SiscomRegistrosPro2 &pSRegistrosPro2,
				     CQ_Persona *pCQPersona)
{
	 if(!strcmp(pSRegistrosPro2["TipoDato"],"Firma") &&
	    pSRegistrosPro2["Firma"][0])
	 {
	  pCQPersona->PonFirma(
	  		new CQ_Firma(
				pSRegistrosPro2["Firma"],
				""
				)
			);
	  pCQPersona->PonPerfil(new QSiscomPerfilBD(
	  				"",
					"",
					pSRegistrosPro2["NmbPerfil"],
					pSRegistrosPro2["DscPerfil"]
					)
				);
	  pCQPersona->PonIdUsuarioBDSeguridad3(pSRegistrosPro2["IdUsuarioBDSeguridad3"]);
	 }
}

int PersonasProt2::DireccionValida(SiscomRegistrosPro2 pSRegistrosPro2)
{
	
	return pSRegistrosPro2["Calle"][0] &&
	       pSRegistrosPro2["Numero"][0];
	       

}
