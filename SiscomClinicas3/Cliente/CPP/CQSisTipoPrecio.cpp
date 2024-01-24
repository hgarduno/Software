#include <CQSisTipoPrecio.h>
#include <CQSisObjetos.h>
CQSisTipoPrecio::CQSisTipoPrecio(const char *pchrPtrIdPrecio,
				 const char *pchrPtrNombre,
				 const char *pchrPtrDescripcion)
{

SRegistroPro2	<<
"IdPrecio"	<<
"Nombre"		<<
"Descripcion";

SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

SRegistrosPro2 			<<
SiscomCampoPro2("IdPrecio",pchrPtrIdPrecio)	<<
SiscomCampoPro2("Nombre",pchrPtrNombre)		<<
SiscomCampoPro2("Descripcion",pchrPtrDescripcion);
SRegistrosPro2.SiscomAnexaRegistro();

}
CQSisLstTipoPrecio::CQSisLstTipoPrecio()
{

}
CQSisLstTipoPrecio &CQSisLstTipoPrecio::operator<<(CQSisTipoPrecio *pCQSTPrecio)
{
	append(pCQSTPrecio);
	return *this;
}

CQSisOpTipoPrecio::CQSisOpTipoPrecio(SiscomDatCom *pSisDatCom):
		SiscomOperaciones(pSisDatCom)
{

}
void CQSisOpTipoPrecio::TipoPrecio(CQSisTipoPrecio *pCQSTPrecio)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
CQSisLstTipoPrecio lCQSLTPrecio;
	lCQSLTPrecio << pCQSTPrecio;
SiscomPonParametrosConsulta((SiscomInformacionLst *)&lCQSLTPrecio);
SiscomActualiza2SubRegistros("RegistraTipoPrecio",&lSRegistrosPro2);
}
void CQSisOpTipoPrecio::TipoPrecio(CQSisLstTipoPrecio *pCQSLTPrecio)
{
SiscomRegistrosPro2 *lSRegistrosPro2;
SiscomArgumentosConsulta(&SPConsulta,
			 "%s",
			 "TiposPrecio");
EliminaTiposPrecio(pCQSLTPrecio);
SiscomPonParametrosConsulta((SiscomInformacionLst *)&SPConsulta);
SiscomConsulta("ConsultasClinicas3",&lSRegistrosPro2);
CQSisObjetos::TipoPrecios(lSRegistrosPro2,pCQSLTPrecio);
}
void CQSisOpTipoPrecio::EliminaTiposPrecio(CQSisLstTipoPrecio *pCQSLTPrecio)
{
	pCQSLTPrecio->setAutoDelete(true);
	pCQSLTPrecio->clear();
	pCQSLTPrecio->setAutoDelete(false);
}
