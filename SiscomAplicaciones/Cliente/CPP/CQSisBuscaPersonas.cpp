#include <CQSisBuscaPersonas.h>
#include <SisPersonas.h>


CQSisBuscaPersona::CQSisBuscaPersona(
			const char *pchrPtrIdPersona,
			const char *pchrPtrNombre,
			const char *pchrPtrAPaterno,
			const char *pchrPtrAMaterno)
{
SRegistroPro2 		<<
"IdPersona"		<<
"Nombre"		<<
"APaterno"		<<
"AMaterno";

SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

SRegistrosPro2						<<
SiscomCampoPro2("IdPersona",pchrPtrIdPersona)		<<
SiscomCampoPro2("Nombre",pchrPtrNombre)			<<
SiscomCampoPro2("APaterno",pchrPtrAPaterno)		<<
SiscomCampoPro2("AMaterno",pchrPtrAMaterno);
SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisLstBuscaPersona::CQSisLstBuscaPersona()
{

}
CQSisLstBuscaPersona &CQSisLstBuscaPersona::operator<<
			(CQSisBuscaPersona *pCQSBPersona)
{
	append(pCQSBPersona);
	return *this;
}
CQSisOpBuscaPersonas::CQSisOpBuscaPersonas(
			SiscomDatCom  *pSisDatCom,
			CQSisBuscaPersona *pCQSBPersona):
		SiscomOperaciones(pSisDatCom),
		CQSBPersona(pCQSBPersona)
{
CQSisLstBuscaPersona lCQSLBPersona;
lCQSLBPersona << pCQSBPersona;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLBPersona);
SiscomActualiza2SubRegistros("BuscaPersonas",&SRegistrosPro2);

}

void CQSisOpBuscaPersonas::Personas(CQSisLstBuscaPersona *pCQSLBPersona)
{
Elimina(pCQSLBPersona);
for( ;
     !SRegistrosPro2->SiscomEsElUltimoRegistro();
     ++(*SRegistrosPro2))
 (*pCQSLBPersona) << 
 new CQSisBuscaPersona(
 	 (*SRegistrosPro2)["idpersona"],
 	 (*SRegistrosPro2)["nombre"],
 	 (*SRegistrosPro2)["apaterno"],
 	 (*SRegistrosPro2)["amaterno"]);
}


void CQSisOpBuscaPersonas::Elimina(CQSisLstBuscaPersona *pCQSLBPersona)
{
	pCQSLBPersona->setAutoDelete(true);
	pCQSLBPersona->clear();
	pCQSLBPersona->setAutoDelete(false);
}
