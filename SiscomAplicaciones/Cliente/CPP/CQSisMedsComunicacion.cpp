#include <CQSisMedsComunicacion.h>
#include <CQSisObjetosAplicaciones.h>
#include <SisMedioComunicacion.h>
CQSisOpMedComunicacion::CQSisOpMedComunicacion(SiscomDatCom *pSisDatCom,
				 const char *pchrPtrSistemaConsulta):
			SiscomOperaciones(pSisDatCom),
			chrPtrSistemaConsulta(pchrPtrSistemaConsulta)
{


}
CQSisOpMedComunicacion::CQSisOpMedComunicacion(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{


}
void CQSisOpMedComunicacion::MedComunicacion(const char *pchrPtrIdPersona,
				const char *pchrPtrIdMedio,
				SisLstMedCom *pSLMCom)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s%s%s",
			 "MediosComunicacionPersona",
			 pchrPtrIdPersona,
			 pchrPtrIdMedio);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta(chrPtrSistemaConsulta,&lSRegistrosPro2);
CQSisObjetosAplicaciones::MediosComunicacion(lSRegistrosPro2,pSLMCom);
}

void CQSisOpMedComunicacion::Registra(SisMedCom *pSMComunicacion)
{
SisLstMedCom lSLMCom;
SiscomRegistrosPro2 *lSRegistrosPro2;
lSLMCom << pSMComunicacion;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lSLMCom);
SiscomActualiza2SubRegistros("RegistraMedioComunicacion",&lSRegistrosPro2);
}
