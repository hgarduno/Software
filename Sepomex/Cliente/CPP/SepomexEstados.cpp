#include <SepomexEstados.h>

SepomexEstado::SepomexEstado(const char *pchrPtrNumEstado,
			       const char *pchrPtrEstado)
{

	SRegistroPro2 <<
	"NumEstado" <<
	"Estado";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					<<
	SiscomCampoPro2("NumEstado",pchrPtrNumEstado)	<<
	SiscomCampoPro2("Estado",pchrPtrEstado);
	SRegistrosPro2.SiscomAnexaRegistro();

}

SepomexEstados::SepomexEstados()
{

}

SepomexEstados &SepomexEstados::operator<<(SepomexEstado *pSEstado)
{
	append(pSEstado);
	return *this;
}

SepomexOpEstados::SepomexOpEstados(SiscomDatCom *pSisDatCom,
				   SiscomParametrosConsulta *pSPConsulta):
		SiscomOperaciones(pSisDatCom,
				 (QPtrList<SiscomInformacion> *)pSPConsulta)
{

}


void SepomexOpEstados::SiscomGeneraRegistros(const SiscomComunicaSrv *pSComunicaSrv,
					     QPtrList<SiscomInformacion> *pQPtrSInformacion)
{
SiscomRegistrosPro2 lSRegistrosPro2((SiscomComunicaSrv *)pSComunicaSrv);
SepomexEstados *lSepEstados=(SepomexEstados *)pQPtrSInformacion;
	for(;
		!lSRegistrosPro2.SiscomEsElUltimoRegistro();
		++lSRegistrosPro2)
		(*lSepEstados) << new SepomexEstado(lSRegistrosPro2["numestado"],
						    lSRegistrosPro2["estado"]);




}
