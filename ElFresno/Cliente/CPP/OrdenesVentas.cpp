#include <OrdenesVentas.h>
OrdenVenta::OrdenVenta(const char *pchrPtrIdVenta,
		       const char *pchrPtrFechaHora,
		       const char *pchrPtrImporte):
	chrPtrIdVenta(pchrPtrIdVenta),
	chrPtrFechaHora(pchrPtrFechaHora),
	chrPtrImporte(pchrPtrImporte)
{

}
void OrdenVenta::PonIdVenta(const char *pchrPtrIdVenta)
{
	chrPtrIdVenta=pchrPtrIdVenta;
}
void OrdenVenta::PonFechaHora(const char *pchrPtrFechaHora)
{
	chrPtrFechaHora=pchrPtrFechaHora;
}


void OrdenVenta::PonImporte(const char *pchrPtrImporte)
{
	chrPtrImporte=pchrPtrImporte;
}

const char *OrdenVenta::ObtenIdVenta()
{
	return chrPtrIdVenta;
}


const char *OrdenVenta::ObtenFechaHora()
{
	return chrPtrFechaHora;
}


const char *OrdenVenta::ObtenImporte()
{
	return chrPtrImporte;
}

CQOrdenesVenta::CQOrdenesVenta()
{

}
CQOrdenesVenta CQOrdenesVenta::operator<<(OrdenVenta *pCQOVenta)
{
	append(pCQOVenta);
	return *this;
}




