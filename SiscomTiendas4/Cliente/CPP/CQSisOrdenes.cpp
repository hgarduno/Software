#include <CQSisOrdenes.h>
CQSisOrden::CQSisOrden(CQSisCliente *pCQSCliente,
		       CQSisFormaPago *pCQSFPago,
		       const char *pchrPtrIdVenta,
		       const char *pchrPtrFecha,
		       const char *pchrPtrImporte):
		   CQSCliente(pCQSCliente),
		   CQSFPago(pCQSFPago)
{
	SRegistroPro2	<<
	"IdVenta"	<<
	"Fecha"		<<
	"Importe";

	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);

	SRegistrosPro2					<<
	SiscomCampoPro2("IdVenta",pchrPtrIdVenta)	<<
	SiscomCampoPro2("Fecha",pchrPtrFecha)		<<
	SiscomCampoPro2("Importe",pchrPtrImporte);
	SRegistrosPro2.SiscomAnexaRegistro();
}

CQSisCliente *CQSisOrden::Cliente()
{
	return CQSCliente;
}
CQSisFormaPago *CQSisOrden::FormaPago()
{
	return CQSFPago;
}
CQSisLstOrden::CQSisLstOrden()
{

}

CQSisLstOrden &CQSisLstOrden::operator<<(CQSisOrden *pCQSOrden)
{
	append(pCQSOrden);
	return *this;
}

		 
