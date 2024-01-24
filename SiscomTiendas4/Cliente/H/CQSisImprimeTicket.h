#ifndef __CQSISIMPRIMETICKET_H__
#define __CQSISIMPRIMETICKET_H__
#include <SISCOMComunicaciones++.h>
class CQSisLstProdCotiza;
class CQSisCliente;
class CQSisOrden;
class CQSisImprimeTicket
{
public:
	CQSisImprimeTicket(CQSisLstProdCotiza *,
			   CQSisCliente *,
			   CQSisOrden *);
	~CQSisImprimeTicket();
private:
	CQSisLstProdCotiza *CQSLPCotiza;
	CQSisCliente *CQSCliente;
	CQSisOrden *CQSOrden;
	FILE *FleArchivo;
	int intSeImprime;
	char chrArrInfATicket[1024];
	char chrArrDatosNegocio[256];
	char chrArrArchivo[256];
private:
	void AbreArchivo();
	void ImprimeDatosNegocio();
	void ImprimeFechaHora();
	void ImprimeNoOrden();
	void ImprimeDetalleOrden();
	void ImprimeTotalOrden();
	void ImprimeTicket();
	void LeeArchivoTicket();
	void ObtenDatosNegocio();
};

#endif
