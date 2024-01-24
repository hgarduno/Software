#ifndef __FACTURACION_H__
#define __FACTURACION_H__
#include <CQSiscomCom.h>
#include <OrdenesVentas.h>
#include <Cotizaciones.h>
class CQProductosCotizacion;
class CQ_Persona;

class Factura
{

public:
	Factura();
	Factura(CQProductosCotizacion *,const char *,const char *);
	Factura(CQProductosCotizacion *,
		    CQ_Persona *,
		    const char *); 
	CQProductosCotizacion *ObtenProductos();
	CQ_Persona *ObtenCliente();
	const char *ObtenNumFactura();
	const char *ObtenIva();
	const char *ObtenImporteSinIva();
	void AnexaOrdenVenta(OrdenVenta *);
	const CQOrdenesVenta &ObtenOrdenesVenta();
	void PonIva(const char *);
	void PonImporteSinIva(const char *);
	
private:
	CQProductosCotizacion *CQPCotizacion;
	CQ_Persona *CQPCliente;
	const char *chrPtrNumFactura;
	CQOrdenesVenta CQOVenta;
	const char *chrPtrIva;
	const char *chrPtrImporteSinIva;
};
class CQFacturas:public QPtrList<Factura>
{
public:
	CQFacturas();

};
class CQCtrFacturacion:public SISCOMOperacionesEnvio
{
public:
	CQCtrFacturacion(CSISCOMDatComunicaciones *,
			 QStringList ,
			 CQFacturas *);

private:
	void SISCOMIniciaRegistroEnvio();
        void SISCOMRegistrosEnvio();
        void AnalizaRespuesta();
	void AnexaOrdenes(QStringList );
	void AnexaProductosDeLaFactura(QStringList );
	void AnexaFactura();
private: 
        SISCOMRegistroEnvio SISCOMRegEnvioDat;
	CQFacturas *CQFFacturas;
	CQProductosCotizacion *CQPCotizacionPtr;
	const char *chrPtrIva;
	const char *chrPtrImporteSinIva;

};
#endif
