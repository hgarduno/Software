#ifndef __CQSISCOMPRAS_H__
#define __CQSISCOMPRAS_H__
#include <SISCOMComunicaciones++.h>
class CQSisProducto;
class CQSisEmpresa;
class CQSisContacto;
class CQSisFormaPago;
class CQSisFamilia;
class CQSisCompra:public SiscomInformacion
{
public:
	CQSisCompra(CQSisProducto *,
		    CQSisEmpresa *,
		    CQSisContacto *,
		    CQSisFormaPago *,
		    const char *,
		    const char *,
		    const char *,
		    const char *,
		    const char *,
		    const char *);
	CQSisProducto *Producto();
	CQSisEmpresa *Proveedor();
	CQSisContacto *Contacto();
	CQSisFormaPago *FormaPago();
private:
	CQSisProducto *CQSProducto;
	CQSisEmpresa *CQSEmpresa;
	CQSisContacto *CQSContacto;
	CQSisFormaPago *CQSFPago;
};
class CQSisLstCompra:public QPtrList<CQSisCompra>
{
public:
	CQSisLstCompra();
	~CQSisLstCompra();
	CQSisLstCompra&operator<<(CQSisCompra*);
};

class CQSisOpCompras:public SiscomOperaciones
{
public:
	CQSisOpCompras(SiscomDatCom *);
	~CQSisOpCompras();
	void Registra(CQSisLstCompra *);
	void UltimaCompraProducto(CQSisEmpresa *,
				  CQSisProducto *,
				  CQSisLstCompra *);
	void Compras(CQSisEmpresa *,
		     const char *,
		     const char *,
		     CQSisLstCompra *);
	void DetalleCompra(CQSisEmpresa *,
			   CQSisCompra *,
			   CQSisLstCompra *);
			   
			
private:
	SiscomParametrosConsulta SPConsulta;
private:
	void FormaUltimaCompraProducto(SiscomRegistrosPro2 *,CQSisLstCompra *);
	
};
#endif
