#include <CQSisOperaciones.h>
#include <CQSisEntrenadores.h>
#include <SisDirecciones.h>
CQSisAnexaDireccion::CQSisAnexaDireccion(SisDireccion *pSDireccion,
					 const char *pchrPtrIdGimnasio)
{

	SRegistroPro2		<<
	"IdGimnasio"		<<
	"IdAsentamiento"	<<
	"Calle"			<<
	"Numero"		<<
	"ComoLlegar";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2							<<
	SiscomCampoPro2("IdGimnasio",pchrPtrIdGimnasio)			<<
	SiscomCampoPro2("IdAsentamiento",pSDireccion->SRegistrosPro2["IdAsentamiento"])										<<
	SiscomCampoPro2("Calle",pSDireccion->SRegistrosPro2["Calle"])		<<
	SiscomCampoPro2("Numero",pSDireccion->SRegistrosPro2["Numero"])		<<
	SiscomCampoPro2("ComoLlegar",pSDireccion->SRegistrosPro2["ComoLlegar"]);
	SRegistrosPro2.SiscomAnexaRegistro();
}

CQSisLstAnexaDireccion::CQSisLstAnexaDireccion()
{

}
CQSisLstAnexaDireccion &CQSisLstAnexaDireccion::operator<<(CQSisAnexaDireccion *pCQSADireccion)
{
	append(pCQSADireccion);
	return *this;
}
CQSisAnexaMedio::CQSisAnexaMedio(const char *pchrPtrMedio,
				 const char *pchrPtrDato,
				 const char *pchrPtrDescripcion,
				 const char *pchrPtrIdPersona)
{
	SRegistroPro2			<<
	"IdGimnasio"			<<
	"IdMedio"			<<
	"Medio"				<<
	"IdPersona"			<<
	"Dato"				<<
	"Descripcion";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2						<<
	SiscomCampoPro2("IdGimnasio","0")			<<
	SiscomCampoPro2("IdMedio","MEDCOM")			<<
	SiscomCampoPro2("Medio",pchrPtrMedio)			<<
	SiscomCampoPro2("IdPersona",pchrPtrIdPersona)		<<
	SiscomCampoPro2("Dato",pchrPtrDato)			<<
	SiscomCampoPro2("Descripcion",pchrPtrDescripcion);
	SRegistrosPro2.SiscomAnexaRegistro();

}
CQSisLstAnexaMedio::CQSisLstAnexaMedio()
{

}
CQSisLstAnexaMedio &CQSisLstAnexaMedio::operator<<(CQSisAnexaMedio *pCQSAMedio)
{
	append(pCQSAMedio);
	return *this;
}
CQSisActPersona::CQSisActPersona(const char *pchrPtrNombre,
				 const char *pchrPtrAPaterno,
				 const char *pchrPtrAMaterno,
				 const char *pchrPtrFechaNac,
				 const char *pchrPtrIdPersona)
{
	SRegistroPro2			<<
	"IdPersona"			<<
	"Nombre"			<<
	"APaterno"			<<
	"AMaterno"			<<
	"FechaNac";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					<<
	SiscomCampoPro2("IdPersona",pchrPtrIdPersona)	<<
	SiscomCampoPro2("Nombre",pchrPtrNombre)		<<
	SiscomCampoPro2("APaterno",pchrPtrAPaterno)	<<
	SiscomCampoPro2("AMaterno",pchrPtrAMaterno)	<<
	SiscomCampoPro2("FechaNac",pchrPtrFechaNac);
	SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisLstActPersona::CQSisLstActPersona()
{

}
CQSisLstActPersona &CQSisLstActPersona::operator<<(CQSisActPersona *pCQSAPersona)
{
	append(pCQSAPersona);
	return *this;
}
CQSisOperaciones::CQSisOperaciones(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{


}

void CQSisOperaciones::ActualizaDatosGenerales(
		CQSisEntrenador *pCQSEPersona,
		const char *pchrPtrNombre,
		const char *pchrPtrAPaterno,
		const char *pchrPtrAMaterno,
		const char *pchrPtrFechaNac)
{
CQSisLstActPersona lCQSLAPersona;
SiscomRegistrosPro2 *lSRegistrosPro2;
	lCQSLAPersona	<< new CQSisActPersona(
				pchrPtrNombre,
				pchrPtrAPaterno,
				pchrPtrAMaterno,
				pchrPtrFechaNac,
				pCQSEPersona->SRegistrosPro2["IdPersona"]);

	SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLAPersona);
	SiscomActualiza2SubRegistros("ActualizaGimnasta",&lSRegistrosPro2);
}
void CQSisOperaciones::AnexaMedio(CQSisEntrenador *pCQSEPersona,
				  const char *pchrPtrMedio,
				  const char *pchrPtrDato,
				  const char *pchrPtrDescripcion)
{
CQSisLstAnexaMedio lCQSLAMedio;
SiscomRegistrosPro2 *lSRegistrosPro2;

		lCQSLAMedio	<<	
			 new CQSisAnexaMedio(
			 	pchrPtrMedio,
				pchrPtrDato,
				pchrPtrDescripcion,
				pCQSEPersona->SRegistrosPro2["IdPersona"]);
		SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLAMedio);
		SiscomActualiza2SubRegistros("AnexaMedio",&lSRegistrosPro2);
}
void CQSisOperaciones::AnexaDireccion(
			CQSisEntrenador *pCQSEPersona,
			SisDireccion *pSDireccion)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SisLstDireccion lSLDireccion;
		
			lSLDireccion << pSDireccion;

SiscomPonParametrosConsulta((SiscomInformacionLst *)&lSLDireccion);
SiscomActualiza2SubRegistros("AnexaDireccion",&lSRegistrosPro2);


}
					
