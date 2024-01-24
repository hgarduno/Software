#include <Materias.h>

Materia::Materia(const char *pchrPtrIdEscuela,
		 const char *pchrPtrIdMateria,
		 const char *pchrPtrNombre,
		 const char *pchrPtrEdoRegistro)
{
	SRegistroPro2 			<<
	"IdEscuela"			<<
	"IdMateria"			<<
	"Nombre"			<<
	"EdoRegistro";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2						<<
	SiscomCampoPro2("IdEscuela",pchrPtrIdEscuela) 		<<
	SiscomCampoPro2("IdMateria",pchrPtrIdMateria)		<<
	SiscomCampoPro2("Nombre",pchrPtrNombre)			<<
	SiscomCampoPro2("EdoRegistro",pchrPtrEdoRegistro);

	SRegistrosPro2.SiscomAnexaRegistro();
}
Materias::Materias()
{

}
Materias &Materias::operator<<(Materia *pMateria)
{
	append(pMateria);
	return *this;
}
ConsultaMaterias::ConsultaMaterias(SiscomDatCom *pSisDatCom,
				   const char *pchrPtrIdEscuela,
				   Materias &pMaterias):
			SisDatCom(pSisDatCom),
			MMaterias(pMaterias),
			chrPtrIdEscuela(pchrPtrIdEscuela)

{
SiscomParametrosConsulta lSPConsulta;

			lSPConsulta			<<
			new SiscomParametroConsulta(pchrPtrIdEscuela);
SiscomGeneralOperacionesSrv lSGenOp(
				pSisDatCom,
				(QPtrList<SiscomInformacion>*)&lSPConsulta);
			lSGenOp.SiscomEjecutaEnvio("ConsultaMaterias");
			GeneraMaterias((const SiscomComunicaSrv *)lSGenOp,pMaterias);
}
void ConsultaMaterias::GeneraMaterias(const SiscomComunicaSrv *pSComunicaSrv,
				      Materias &pMaterias)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
	  pMaterias <<
	  	new Materia(lSRegistrosPro2["idescuela"],
			    lSRegistrosPro2["idmateria"],
			    lSRegistrosPro2["nombre"]);
	delete pSComunicaSrv;
}
void ConsultaMaterias::RegistraMaterias()
{
SiscomGeneralOperacionesSrv lSGenOp(SisDatCom,
				(QPtrList<SiscomInformacion>*)&MMaterias);
			lSGenOp.SiscomEjecutaEnvio("RegistraMaterias");
}

