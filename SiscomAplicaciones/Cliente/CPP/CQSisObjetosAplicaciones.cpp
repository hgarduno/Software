#include <CQSisObjetosAplicaciones.h>
#include <SisMedioComunicacion.h>
#include <CQSisDirecciones.h>
CQSisObjetosAplicaciones::CQSisObjetosAplicaciones()
{


}

CQSisDireccion *CQSisObjetosAplicaciones::Direccion(
			SiscomRegistrosPro2 *pSRegistrosPro2)
{

return new CQSisDireccion(
		(*pSRegistrosPro2)["calle"],
		(*pSRegistrosPro2)["numero"],
		(*pSRegistrosPro2)["referencias"],
		(*pSRegistrosPro2)["asentamiento"],
		(*pSRegistrosPro2)["tipoasentamiento"],
		(*pSRegistrosPro2)["estado"],
		(*pSRegistrosPro2)["municipio"]);
}

void CQSisObjetosAplicaciones::Direcciones(
			SiscomRegistrosPro2 *pSRegistrosPro2,
			CQSisLstDireccion *pCQSLDireccion)
{
for(;
     !pSRegistrosPro2->SiscomEsElUltimoRegistro();
     ++(*pSRegistrosPro2))
  (*pCQSLDireccion) << Direccion(pSRegistrosPro2);

}
/*
 *	
 *	const char *pchrPtrIdMedio,
 *	const char *pchrPtrMedio,
 *	const char *pchrPtrDato,
 *	const char *pchrPtrDescripcion,
 *	const char *pchrPtrIdPersona)
 *
 *
 */
SisMedCom *CQSisObjetosAplicaciones::MedioComunicacion(
				SiscomRegistrosPro2 *pSRegistrosPro2)
{
return new SisMedCom(
		(*pSRegistrosPro2)["idmedio"],
		(*pSRegistrosPro2)["medio"],
		(*pSRegistrosPro2)["dato"],
		(*pSRegistrosPro2)["descripcion"],
		(*pSRegistrosPro2)["idpersona"]);
}

void CQSisObjetosAplicaciones::MediosComunicacion(
				SiscomRegistrosPro2 *pSRegistrosPro2,
				SisLstMedCom *pSLMCom)
{
for(;
	!pSRegistrosPro2->SiscomEsElUltimoRegistro();
    ++(*pSRegistrosPro2))
  (*pSLMCom) << MedioComunicacion(pSRegistrosPro2);
}
