#include <CQSisGimnasios.h>
#include <SisDirecciones.h>
#include <SisPersonas.h>
#include <SisMedioComunicacion.h>

#include <CQSisTrampolinComun.h>
CQSisGimnasio::CQSisGimnasio(const char *pchrPtrIdGimnasio,
			     const char *pchrPtrGimnasio):
			 chrPtrIdGimnasio(pchrPtrIdGimnasio),
			 chrPtrGimnasio(pchrPtrGimnasio),
			 chrPtrEdoValidacion("")

{
	SiscomAsignaInformacion();
	SiscomAnexaCampos(SisDireccion("","","",""));
	SiscomAnexaCampos(SisMedCom());
	SiscomAnexaCampos(SisPersona("","","",""));
}
CQSisGimnasio::CQSisGimnasio(const char *pchrPtrIdGimnasio,
			     const char *pchrPtrGimnasio,
			     const char *pchrPtrEdoValidacion):
			   chrPtrIdGimnasio(pchrPtrIdGimnasio),
			   chrPtrGimnasio(pchrPtrGimnasio),
			   chrPtrEdoValidacion(pchrPtrEdoValidacion)
{
	SiscomAsignaInformacion();
}

void CQSisGimnasio::PonDireccion(SisDireccion *pSisPtrDir)
{
	SRegistrosPro2.SiscomActualizaCampo("Calle",pSisPtrDir->SRegistrosPro2["Calle"]);
	SRegistrosPro2.SiscomActualizaCampo("Numero",pSisPtrDir->SRegistrosPro2["Numero"]);
	SRegistrosPro2.SiscomActualizaCampo("IdAsentamiento",pSisPtrDir->SRegistrosPro2["IdAsentamiento"]);

}
void CQSisGimnasio::PonTelefono(SisMedCom *pSMTelefono)
{
	SRegistrosPro2.SiscomActualizaCampo("Medio","Telefono");
	SRegistrosPro2.SiscomActualizaCampo("Dato",pSMTelefono->SRegistrosPro2["Dato"]);
	SRegistrosPro2.SiscomActualizaCampo(
			"Descripcion",
			pSMTelefono->SRegistrosPro2["Descripcion"]);
}
void CQSisGimnasio::PonContacto(SisPersona *pSisPersona)
{
	SRegistrosPro2.SiscomActualizaCampo("Nombre",pSisPersona->SRegistrosPro2["Nombre"]);
	SRegistrosPro2.SiscomActualizaCampo("APaterno",pSisPersona->SRegistrosPro2["APaterno"]);
	SRegistrosPro2.SiscomActualizaCampo("AMaterno",pSisPersona->SRegistrosPro2["AMaterno"]);
}
void CQSisGimnasio::PonValidaNombre(const char *pchrPtrValidaNombre)
{
	SRegistrosPro2.SiscomActualizaCampo("ValidaNombre",pchrPtrValidaNombre);
}
void CQSisGimnasio::PonEsEntrenadorContacto(const char *pchrPtrEsEntrenador)
{
	SRegistrosPro2.SiscomActualizaCampo("EsEntrenador",pchrPtrEsEntrenador);
}
void CQSisGimnasio::SiscomFormaRegistro()
{
	SRegistroPro2 			<<
	"IdGimnasio"			<<
	"Gimnasio"			<<
	"ValidaNombre"			<<
	"EdoValidacion"			<<
	"EsEntrenador";
}
void CQSisGimnasio::SiscomAnexaRegistro()
{	
	SRegistrosPro2						<<
	SiscomCampoPro2("IdGimnasio",chrPtrIdGimnasio)		<<
	SiscomCampoPro2("Gimnasio",chrPtrGimnasio)		<<
	SiscomCampoPro2("ValidaNombre","Si")			<<
	SiscomCampoPro2("EdoValidacion",chrPtrEdoValidacion)	<<
	SiscomCampoPro2("EsEntrenador","");
}

CQSisLstGimnasio::CQSisLstGimnasio()
{

}
CQSisLstGimnasio &CQSisLstGimnasio::operator<<(CQSisGimnasio *pCQSisGPtrNombre)
{
	append(pCQSisGPtrNombre);
	return *this;
}
CQSisOpGimnasio::CQSisOpGimnasio(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}
void CQSisOpGimnasio::InsertaGimnasio(CQSisGimnasio *pCQSisGPtrGimnasio,
					     CQSisLstGimnasio *pCQSisGLstPtrGimnasio)
{
	CQSisLGimnasio << pCQSisGPtrGimnasio;
	SiscomPonParametrosConsulta((SiscomInformacionLst *)&CQSisLGimnasio);
	SiscomActualiza("RegistraGimnasio",
			(SiscomInformacionLst *)pCQSisGLstPtrGimnasio);
}
void CQSisOpGimnasio::GimnasiosRegistrados(CQSisLstGimnasio *pCQSLGimnasio)
{
	FormaConsultaGimnasiosRegistrados();
	SiscomConsulta("ConsultaGimnasio",
		       (SiscomInformacionLst *)pCQSLGimnasio);

}
void CQSisOpGimnasio::FormaConsultaGimnasiosRegistrados()
{
	SPConsulta		<<
	new SiscomParametroConsulta("GimnasiosRegistrados");

	SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);

}
void CQSisOpGimnasio::SiscomGeneraRegistrosActualiza(
			const SiscomComunicaSrv *pSComunicaSrv,
			SiscomInformacionLst *pSisInfoLstRegreso)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
CQSisLstGimnasio *lCQSLstGimnasio=(CQSisLstGimnasio *)pSisInfoLstRegreso;
	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
	  (*lCQSLstGimnasio) << new CQSisGimnasio(lSRegistrosPro2["idgimnasio"],
	  					  lSRegistrosPro2["nombre"],
	  					  lSRegistrosPro2["edovalidacion"]);
}
void CQSisOpGimnasio::SiscomGeneraRegistros(
			const SiscomComunicaSrv *pSComunicaSrv,
			SiscomInformacionLst *pSisInfoLstRegreso)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
CQSisLstGimnasio *lCQSLstGimnasio=(CQSisLstGimnasio *)pSisInfoLstRegreso;
	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
	  (*lCQSLstGimnasio) << new CQSisGimnasio(lSRegistrosPro2["idgimnasio"],
	  					  lSRegistrosPro2["nombre"]);
}
