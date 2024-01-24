#include <CQSisCompitiendo.h>
#include <CQSisGimnasios.h>
#include <CQSisGimnastas.h>
#include <CQSisCompetencias.h>
#include <CQSisClase.h>
#include <CQSisNivel.h>
#include <CQSisGrupo.h>
#include <CQSisEntrenadores.h>
#include <CQSisCalificaciones.h>
#include <CQSisAparato.h>
CQSisCompitiendo::CQSisCompitiendo(CQSisCompetencia *pCQSCompetencia,
				   CQSisEntrenador *pCQSGimnasta,
				   CQSisGimnasio *pCQSGimnasio,
				   CQSisClase *pCQSClase,
				   CQSisNivel *pCQSNivel,
				   CQSisGrupo *pCQSGrupo,
				   CQSisEntrenador *pCQSEntrenador,
				   const char *pchrPtrFechaReg):
			CQSCompetencia(pCQSCompetencia),
			CQSGimnasta(pCQSGimnasta),
			CQSGimnasio(pCQSGimnasio),
			CQSClase(pCQSClase),
			CQSNivel(pCQSNivel),
			CQSGrupo(pCQSGrupo),
			CQSEntrenador(pCQSEntrenador),
			chrPtrFechaReg(pchrPtrFechaReg)
{
#ifdef __SISCOMINFORMACION2__
	SiscomAsignaInformacion();
	SiscomAnexaCampos(CQSisCompetencia());
	SiscomAnexaCampos(CQSisGimnasta("","","",""));
	SiscomAnexaCampos(CQSisGimnasio("",""));
	SiscomAnexaCampos(CQSisClase("",""));
	SiscomAnexaCampos(CQSisNivel("","",""));
	SiscomAnexaCampos(CQSisGrupo("","","",""));
	SiscomAnexaCampos(CQSisEntrenador("","","",""));
	SiscomAnexaCampos(CQSisGimnasta("","","",""));
	ColocaInformacion();
#else
	SRegistroPro2 			<<
	"IdCompetencia"			<<
	"IdGimnasta"			<<
	"IdGimnasio"			<<
	"IdClase"			<<
	"IdNivel"			<<
	"IdGrupo"			<<
	"IdEntrenador"			<<
	"FechaReg";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2 										<<		
	SiscomCampoPro2("IdCompetencia",CQSCompetencia->SRegistrosPro2["IdCompetencia"])	<<
	SiscomCampoPro2("IdGimnasta",CQSGimnasta->SRegistrosPro2["IdPersona"])			<<
	SiscomCampoPro2("IdGimnasio",CQSGimnasio->SRegistrosPro2["IdGimnasio"])			<<
	SiscomCampoPro2("IdClase",CQSClase->SRegistrosPro2["IdClase"])				<<
	SiscomCampoPro2("IdNivel",CQSNivel->SRegistrosPro2["IdNivel"])				<<
	SiscomCampoPro2("IdGrupo",CQSGrupo->SRegistrosPro2["IdGrupo"])				<<
	SiscomCampoPro2("IdEntrenador",CQSEntrenador->SRegistrosPro2["IdPersona"])		<<
	SiscomCampoPro2("FechaReg",chrPtrFechaReg);
	SRegistrosPro2.SiscomAnexaRegistro();
#endif
}
#ifdef __SISCOMINFORMACION2__
void CQSisCompitiendo::SiscomFormaRegistro()
{

	SRegistroPro2 			<<
	"FechaReg";

}
void CQSisCompitiendo::SiscomAnexaRegistro()
{
	SRegistrosPro2 					<<
	SiscomCampoPro2("FechaReg",chrPtrFechaReg);
}
void CQSisCompitiendo::ColocaInformacion()
{
SRegistrosPro2.SiscomActualizaCampo("Competencia",CQSCompetencia->SRegistrosPro2["Competencia"]);
/*
 * En este punto para simplificar el proceso de asignacion de cada uno de los
 * campos solo se realizara esta operacion, en los campos que se requieren para 
 * registrar al gimnasta a la competencia 
 *
 */

SRegistrosPro2.SiscomActualizaCampo("IdClase",CQSClase->SRegistrosPro2["IdClase"]);
SRegistrosPro2.SiscomActualizaCampo("IdNivel",CQSNivel->SRegistrosPro2["IdNivel"]);
SRegistrosPro2.SiscomActualizaCampo("IdGrupo",CQSGrupo->SRegistrosPro2["IdGrupo"]);

SiscomImprimeContenidoProtocolo("",gPtrFleArchivoLog,SRegistrosPro2.SiscomObtenRegistros());

}

#endif
int CQSisCompitiendo::operator==(CQSisCompitiendo *pCQSCompitiendo)
{
return *ObtenGimnasta()==pCQSCompitiendo->ObtenGimnasta();
}
int CQSisCompitiendo::operator==(CQSisAparato *pCQSAparato)
{
return *ObtenCalificacion()==pCQSAparato;
}
void CQSisCompitiendo::PonCalificacion(CQSisCalificacion *pCQSCalificacion)
{
	CQSCalificacion=pCQSCalificacion;
}
CQSisCompetencia *CQSisCompitiendo::ObtenCompetencia()
{
	return CQSCompetencia;
}
CQSisEntrenador *CQSisCompitiendo::ObtenGimnasta()
{
	return CQSGimnasta;
}
CQSisGimnasio *CQSisCompitiendo::ObtenGimnasio()
{
	return CQSGimnasio;
}
CQSisClase *CQSisCompitiendo::ObtenClase()
{
	return CQSClase;
}
CQSisNivel *CQSisCompitiendo::ObtenNivel()
{
	return CQSNivel;
}
CQSisGrupo *CQSisCompitiendo::ObtenGrupo()
{
	return CQSGrupo;
}
CQSisEntrenador *CQSisCompitiendo::ObtenEntrenador()
{
	return CQSEntrenador;
}
const char *CQSisCompitiendo::ObtenFechaRegistro()
{
	return chrPtrFechaReg;
}
CQSisCalificacion *CQSisCompitiendo::ObtenCalificacion()
{
	return CQSCalificacion;
}
CQSisLstCompitiendo::CQSisLstCompitiendo()
{
}
CQSisLstCompitiendo &CQSisLstCompitiendo::operator<<(CQSisCompitiendo *pCQSCompitiendo)
{
	append(pCQSCompitiendo);
	return *this;
}
CQSisOpCompitiendo::CQSisOpCompitiendo(SiscomDatCom *pSisDatCom):
			SiscomOperaciones(pSisDatCom)
{

}
void CQSisOpCompitiendo::RegistraGimnasta(CQSisCompitiendo *pCQSCompitiendo,
					  SiscomRegistrosPro2 **pSRegistrosPro2)
{
		CQSLCompitiendo << pCQSCompitiendo;
		SiscomPonParametrosConsulta((SiscomInformacionLst *)&CQSLCompitiendo);
		SiscomActualiza2SubRegistros("RegistraCompetidor",pSRegistrosPro2);
}
void CQSisOpCompitiendo::ActDatCompGimnasta(CQSisCompitiendo *pCQSCompitiendo,
					  SiscomRegistrosPro2 **pSRegistrosPro2)
{
		CQSLCompitiendo << pCQSCompitiendo;
		SiscomPonParametrosConsulta((SiscomInformacionLst *)&CQSLCompitiendo);
		SiscomActualiza2SubRegistros("ActDatCompGimnasta",pSRegistrosPro2);
}
