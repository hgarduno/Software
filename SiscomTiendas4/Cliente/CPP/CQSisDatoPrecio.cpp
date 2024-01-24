#include <CQSisDatoPrecio.h>
#include <CQSisPrecios.h>
CQSisDatoPrecio::CQSisDatoPrecio(CQSisPrecio *pCQSPrecio,	
				 const char *pchrPtrValor,
				 const char *pchrPtrCantidad):
			CQSPrecio(pCQSPrecio)
{
	SRegistroPro2			<<
	"Valor"				<<
	"Cantidad";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2			<<
	SiscomCampoPro2("Valor",pchrPtrValor)	<<
	SiscomCampoPro2("Cantidad",pchrPtrCantidad);
	SRegistrosPro2.SiscomAnexaRegistro();
}

CQSisPrecio *CQSisDatoPrecio::ObtenPrecio()
{
	return CQSPrecio;
}
CQSisLstDatoPrecio::CQSisLstDatoPrecio()
{
//	setAutoDelete(true);
}
CQSisLstDatoPrecio::~CQSisLstDatoPrecio()
{
	clear();
}
CQSisLstDatoPrecio &CQSisLstDatoPrecio::operator<<(CQSisDatoPrecio *pCQSDPrecio)
{
	append(pCQSDPrecio);
	return *this;
}
