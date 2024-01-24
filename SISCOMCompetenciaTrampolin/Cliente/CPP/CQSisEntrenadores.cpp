#include <CQSisEntrenadores.h>
#include <CQSisGimnasios.h>
CQSisEntrenador::CQSisEntrenador(const char *pchrPtrNombre,
				 const char *pchrPtrAPaterno,
				 const char *pchrPtrAMaterno,
				 const char *pchrPtrIdPersona)/*:
			SisPersona(pchrPtrNombre,
				   pchrPtrAPaterno,
				   pchrPtrAMaterno,
				   pchrPtrIdPersona) */


		
{

	SRegistroPro2				<<
	"IdGimnasio"				<<
	"Gimnasio"				<<
	"ValidaNombre"				<<
	"EdoValidacion"				<<
	"EsEntrenador"				<<
	"IdMedio"				<<
	"Medio"					<<
	"Dato"					<<
	"Descripcion"				<<
	"Nombre"				<<
	"APaterno"				<<
	"AMaterno"				<<
	"IdPersona"				<<
	"FechaNac"				<<
	"Edad";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2 						<< 
	SiscomCampoPro2("IdGimnasio","")			<<
	SiscomCampoPro2("Gimnasio","")				<<
	SiscomCampoPro2("ValidaNombre","")			<<
	SiscomCampoPro2("EdoValidacion","")			<<
	SiscomCampoPro2("EsEntrenador","")			<<
	SiscomCampoPro2("IdMedio","")				<<
	SiscomCampoPro2("Medio","")				<<
	SiscomCampoPro2("Dato","")				<<
	SiscomCampoPro2("Descripcion","")			<<
	SiscomCampoPro2("Nombre",pchrPtrNombre)			<<
	SiscomCampoPro2("APaterno",pchrPtrAPaterno)		<<
	SiscomCampoPro2("AMaterno",pchrPtrAMaterno) 		<<
	SiscomCampoPro2("IdPersona",pchrPtrIdPersona)		<<
	SiscomCampoPro2("FechaNac","")				<<
	SiscomCampoPro2("Edad","");
	SRegistrosPro2.SiscomAnexaRegistro();
}
void CQSisEntrenador::PonFechaNac(const char *pchrPtrFechaNac)
{
	SRegistrosPro2.SiscomActualizaCampo(
				"FechaNac",
				pchrPtrFechaNac);
}
void CQSisEntrenador::PonEdad(const char *pchrPtrEdad)
{
	SRegistrosPro2.SiscomActualizaCampo(
				"Edad",
				pchrPtrEdad);
}
void CQSisEntrenador::PonGimnasio(CQSisGimnasio *pCQSGimnasio)
{
SRegistrosPro2.SiscomActualizaCampo(
			"IdGimnasio",
			pCQSGimnasio->SRegistrosPro2["IdGimnasio"]);
}
int CQSisEntrenador::operator==(CQSisEntrenador *pCQSEntrenador)
{

return !strcmp((*pCQSEntrenador)["IdPersona"],
	       (*this)["IdPersona"]);

}
void CQSisEntrenador::AnexaCorreoElectronico(const char *pchrPtrCorreo)
{
SiscomRegistrosPro2 lSRegistrosPro2;
SiscomRegistroPro2 lSRegistroPro2;
	lSRegistroPro2				<<
	"IdGimnasio"				<<
	"Gimnasio"				<<
	"ValidaNombre"				<<
	"EdoValidacion"				<<
	"EsEntrenador"				<<
	"IdMedio"				<<
	"Medio"					<<
	"Dato"					<<
	"Descripcion"				<<
	"Nombre"				<<
	"APaterno"				<<
	"AMaterno"				<<
	"IdPersona"				<<
	"FechaNac"				<<
	"Edad";
	lSRegistrosPro2.PonRegistroPro2(&lSRegistroPro2);
	lSRegistrosPro2 					<< 
	SiscomCampoPro2("IdGimnasio","")			<<
	SiscomCampoPro2("Gimnasio","")				<<
	SiscomCampoPro2("ValidaNombre","")			<<
	SiscomCampoPro2("EdoValidacion","")			<<
	SiscomCampoPro2("EsEntrenador","")			<<
	SiscomCampoPro2("IdMedio","MEDCOM")			<<
	SiscomCampoPro2("Medio","Correo Electronico")		<<
	SiscomCampoPro2("Dato",pchrPtrCorreo)			<<
	SiscomCampoPro2("Descripcion","")			<<
	SiscomCampoPro2("Nombre","")				<<
	SiscomCampoPro2("APaterno","")				<<
	SiscomCampoPro2("AMaterno","") 				<<
	SiscomCampoPro2("IdPersona","")				<<
	SiscomCampoPro2("FechaNac","")				<<
	SiscomCampoPro2("Edad","");
	lSRegistrosPro2.SiscomAnexaRegistro();
	SRegistrosPro2.SiscomAnexaRegistro(lSRegistrosPro2);

}


/*
 *
 * Esta funcion debe ser invocada al ultimo, ya que anexara un registro
 *
 *
 */

void CQSisEntrenador::AnexaTelefono(const char *pchrPtrTelefono,
				    const char *pchrPtrDescripcion)
				   
{
SiscomRegistrosPro2 lSRegistrosPro2;
SiscomRegistroPro2 lSRegistroPro2;
	lSRegistroPro2				<<
	"IdGimnasio"				<<
	"Gimnasio"				<<
	"ValidaNombre"				<<
	"EdoValidacion"				<<
	"EsEntrenador"				<<
	"IdMedio"				<<
	"Medio"					<<
	"Dato"					<<
	"Descripcion"				<<
	"Nombre"				<<
	"APaterno"				<<
	"AMaterno"				<<
	"IdPersona"				<<
	"FechaNac";
	lSRegistrosPro2.PonRegistroPro2(&lSRegistroPro2);
	lSRegistrosPro2 					<< 
	SiscomCampoPro2("IdGimnasio","")			<<
	SiscomCampoPro2("Gimnasio","")				<<
	SiscomCampoPro2("ValidaNombre","")			<<
	SiscomCampoPro2("EdoValidacion","")			<<
	SiscomCampoPro2("EsEntrenador","")			<<
	SiscomCampoPro2("IdMedio","MEDCOM")			<<
	SiscomCampoPro2("Medio","Telefono")			<<
	SiscomCampoPro2("Dato",pchrPtrTelefono)			<<
	SiscomCampoPro2("Descripcion",pchrPtrDescripcion)	<<
	SiscomCampoPro2("Nombre","")				<<
	SiscomCampoPro2("APaterno","")				<<
	SiscomCampoPro2("AMaterno","") 				<<
	SiscomCampoPro2("IdPersona","")				<<
	SiscomCampoPro2("FechaNac","")				<<
	SiscomCampoPro2("Edad","");
	lSRegistrosPro2.SiscomAnexaRegistro();
	SRegistrosPro2.SiscomAnexaRegistro(lSRegistrosPro2);
}
CQSisLstEntrenador::CQSisLstEntrenador()
{

}

CQSisLstEntrenador &CQSisLstEntrenador::operator<<(CQSisEntrenador *pCQSEntrenador)
{
	append(pCQSEntrenador);
	return *this;
}

CQSisOpEntrenador::CQSisOpEntrenador(SiscomDatCom *pSisDatCom):
			SiscomOperaciones(pSisDatCom)
{


}
void CQSisOpEntrenador::InsertaEntrenador(CQSisEntrenador *pCQSEntrenador,
					  SiscomRegistrosPro2 **pSRegistrosPro2)
{
		CQSLEntrenador << pCQSEntrenador;
		SiscomPonParametrosConsulta((SiscomInformacionLst *)&CQSLEntrenador);
		SiscomActualiza2SubRegistros("RegistraEntrenador",
				pSRegistrosPro2);
}
