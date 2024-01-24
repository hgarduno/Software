#include <CQSisProductos.h>
#include <CQSisFamilias.h>
#include <CQSisPrecios.h>

CQSisProducto::CQSisProducto(CQSisFamilia *pCQSFamilia,
			    const char *pchrPtrIdProducto,
			    const char *pchrPtrClave,
			     const char *pchrPtrDsc):
			  CQSFamilia(pCQSFamilia)
{
	SRegistroPro2		<<
	"IdProducto"		<<
	"Clave"			<<
	"Dsc"			<<
	"IdFamilia";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					<<
	SiscomCampoPro2("IdProducto",pchrPtrIdProducto)	<<
	SiscomCampoPro2("Clave",pchrPtrClave)		<<
	SiscomCampoPro2("Dsc",pchrPtrDsc)		<<
	SiscomCampoPro2("IdFamilia",pCQSFamilia->SRegistrosPro2["IdFamilia"]);
	SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisProducto::CQSisProducto()
{
	SRegistroPro2		<<
	"IdProducto"		<<
	"Clave"			<<
	"Dsc"			<<
	"IdFamilia";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2					<<
	SiscomCampoPro2("IdProducto","")	<<
	SiscomCampoPro2("Clave","")		<<
	SiscomCampoPro2("Dsc","")		<<
	SiscomCampoPro2("IdFamilia","");
	SRegistrosPro2.SiscomAnexaRegistro();
}
CQSisProducto::~CQSisProducto()
{
/*
SiscomLog("");
*/
}
CQSisFamilia *CQSisProducto::ObtenFamilia()
{
	return CQSFamilia;
}
CQSisLstPrecio *CQSisProducto::ObtenPrecios()
{
	return CQSLPrecio;
}
void CQSisProducto::PonPrecios(CQSisLstPrecio *pCQSLPrecio)
{
	CQSLPrecio=pCQSLPrecio;
}
CQSisLstProducto::CQSisLstProducto()
{

	setAutoDelete(true);
}
CQSisLstProducto::~CQSisLstProducto()
{
	clear();
}
CQSisLstProducto &CQSisLstProducto::operator<<(CQSisProducto *pCQSProducto)
{
	append(pCQSProducto);
	return *this;
}

CQSisProducto3Qt::CQSisProducto3Qt(const char *pchrPtrIdFamilia,	
				   const char *pchrPtrIdProducto,
				   const char *pchrPtrClave,
				   const char *pchrPtrDsc)
{

(*this)					<<
new SiscomCampo3("IdProducto",pchrPtrIdProducto) <<
new SiscomCampo3("Clave",pchrPtrClave) <<
new SiscomCampo3("Dsc",pchrPtrDsc) <<
new SiscomCampo3("IdFamilia",pchrPtrIdFamilia) ;

}

CQSisLstProducto3Qt::CQSisLstProducto3Qt()
{

}
