#ifndef __COMPRAS_H__
#define __COMPRAS_H__
#include <Cotizaciones.h>
#include <CQSiscomCom.h>
#include <qptrlist.h>
class Empresa;
class Compra
{
public:
	Compra(const char *,
	       const char *,
	       const char *,
	       const char *,
	       Empresa *,
	       Empresa *);
	void AnexaProducto(ProductoCotizacion *);
	void EliminaProducto(int);
	void PonProveedor(Empresa *);
	const CQProductosCotizacion &ObtenProductosCompra();
	Empresa *ObtenProveedor();
	Empresa *ObtenExpendio();
	const char *ObtenFechaPago();
	const char *ObtenFecha();
	const char *ObtenNumFactura();
	const char *ObtenFormaPago();
private:
Empresa *E_Expendio;
Empresa *E_Proveedor;
const char *chrPtrFechaPago;
const char *chrPtrFechaCompra;
const char *chrPtrNumFactura;
const char *chrPtrFormaPago;
CQProductosCotizacion CQProdCotizacion;


};

class CQCompras:public QPtrList<Compra>
{

	public:
		CQCompras();

};

class CQCtrCompras
{
public:
		CQCtrCompras(CSISCOMDatComunicaciones *,
			     QStringList ,
			     CQCompras *);
private:

	CQOGenericaServidorSiscom *CQOGSvrSiscom;
        CSISCOMDatComunicaciones *CSisDatCom;
        QStringList QSLRegistro;
	SISCOMRegistroEnvio SISCOMRegEnvio;
private:
	void IniciaRegistroEnvio();
	void IniciaComunicaciones();
	void EnviaParametrosOperacion(QStringList );
	void EnviaCompras(CQCompras *);
	void EnviaInformacion();
	void AnalizaRespuesta(CQCompras *);
	void AnexaRegistro();
	void AnexaRegistroVacio();
	void EnviaCompras();
};
#endif
