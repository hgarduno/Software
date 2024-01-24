#ifndef __VENTAS_H__
#define __VENTAS_H__
#include <qptrlist.h>
#include <qstringlist.h>
class CQProductosCotizacion;
class CQ_Persona;
class Producto;
class Empresa;
class CSISCOMDatComunicaciones;
class CQOGenericaServidorSiscom;



class Venta
{
public:
	Venta(CQProductosCotizacion *,
	      CQ_Persona *,
	      CQ_Persona *,
	      Empresa *);
	void PonProductos(CQProductosCotizacion *);
	void PonCliente(CQ_Persona *);
	CQProductosCotizacion *ObtenProductos();
	CQ_Persona *ObtenCliente();
	CQ_Persona *ObtenVendedor();
	Empresa *ObtenExpendio();
	const char *ObtenEdoRegistro();
private:
	CQProductosCotizacion *CQPProductos;
	CQ_Persona *CQPCliente;
	CQ_Persona *CQPVendedor;
	Empresa *EExpendio;
	const char *chrPtrEdoRegistro;

};
class CQVentas:public QPtrList<Venta>
{
	public:
		CQVentas();

};

class CQCtrVentas
{
public:
	enum CtrVentas
	{
		RegistrarVenta
	};
	CQCtrVentas(CSISCOMDatComunicaciones *,
		    CtrVentas ,
		    Venta *);
private:
	void RegistrarLaVenta(Venta *);
	
private:
	CQOGenericaServidorSiscom *CQOGSvrSiscom;
        CSISCOMDatComunicaciones *CSisDatCom;
        QStringList QSLRegistro;
	const char *chrPtrFormatoVentas;
	int intNumFormatoVentas;


};


#endif
