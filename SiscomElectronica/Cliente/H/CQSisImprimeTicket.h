#ifndef __CQSISIMPRIMETICKET_H__
#define __CQSISIMPRIMETICKET_H__
#include <SiscomRegistros3.h>
#include <SiscomOperaciones3.h>
class ProductosE;
class Persona;
class CQSisPuntosPromocionCliente;
class CQSisImprimeTicket:public SiscomRegistro3Lst 
{
public:
	CQSisImprimeTicket(const char *pchrPtrIdExpedio,
			   const char *pchrPtrOrden,	
			   CQSisPuntosPromocionCliente *,
			   Persona *PCliente,
			   ProductosE *);


private:
	ProductosE *ProdEDatos;
	char chrArrIdOrden[25];
	Persona *pCliente;
	const char *chrPtrIdExpendio;
	CQSisPuntosPromocionCliente *CQSPPCliente;
private:
	void FormaEnvio();
};

class CQSisImprimeTicketOp:SiscomOperaciones3
{
public:
	CQSisImprimeTicketOp(SiscomDatCom *);
	void TicketVenta(CQSisImprimeTicket *);



};
#endif
