#ifndef __CQSISPRODCOTIZA_H__
#define __CQSISPRODCOTIZA_H__
#include <SISCOMComunicaciones++.h>
class CQSisProducto;
class CQSisPrecio;
class CQSisEmpresa;
class CQSisEmpleado;
class CQSisCliente;
class CQSisFormaPago;
class CQSisContacto;
class CQSisProdCotiza:public SiscomInformacion
{
public:
	CQSisProdCotiza(
		CQSisProducto *,
		CQSisPrecio *,
		CQSisFormaPago *,
		CQSisEmpresa *,
		CQSisCliente *,
		CQSisContacto *,
		CQSisEmpleado *,
		const char *,
		const char *,
		const char *,
		const char *,
		const char *,
		const char *,
		const char *);

	CQSisProdCotiza(CQSisProducto *,
			CQSisEmpresa *,
			const char *,
			const char *,
			const char *,
			const char *);
	/*
	 * Al inicializar los productos mediante este constructor
	 * se contara con la informacion del producto y la existencia,
	 * cantidad, precio, importe
	 * esto, se hizo para el reporte de existencia y compras 
	 *
	 */
	CQSisProdCotiza(CQSisProducto *,
			const char *,
			const char *,
			const char *,
			const char *,
			const char *);
	~CQSisProdCotiza();
	void Precio(CQSisPrecio *);
	CQSisProducto *Producto();
	CQSisPrecio *Precio();
	CQSisEmpresa *Expendio();
	CQSisCliente *Cliente();
	CQSisEmpleado *Empleado();
	CQSisContacto *Contacto();
	CQSisFormaPago *FormaPago();
private:
	CQSisProducto *CQSProducto;
	CQSisPrecio *CQSPrecio;
	CQSisEmpresa *CQSExpendio;
	CQSisCliente *CQSCliente;
	CQSisEmpleado *CQSEmpleado;
	CQSisFormaPago *CQSFPago;
	CQSisContacto *CQSContacto;
private:
	const char *ObtenIdCliente();
};

class CQSisLstProdCotiza:public QPtrList<CQSisProdCotiza>
{
public:
	CQSisLstProdCotiza();
	~CQSisLstProdCotiza();
	CQSisLstProdCotiza &operator<<(CQSisProdCotiza *);
	const char *TotalOrden();
	void PonTotalOrden(const char *);
	void EliminaProductos(QMemArray<int>);
private:
	const char *chrPtrTotalOrden;

};
class CQSisOpCotiza:public SiscomOperaciones
{
public:
	CQSisOpCotiza(SiscomDatCom *);
	~CQSisOpCotiza();
	void CotizaProducto(CQSisProdCotiza *);
	void CotizaProductos(CQSisLstProdCotiza *);
	void GeneraIdentificador(CQSisLstProdCotiza *);
private:
SiscomParametrosConsulta SPConsulta;
private:
	void AsignaResultados(SiscomRegistrosPro2 *,CQSisProdCotiza *);
	void AsignaResultados(SiscomRegistrosPro2 *,CQSisLstProdCotiza *);
	void AsignaIdentificador(SiscomRegistrosPro2 *,CQSisLstProdCotiza *);
	void Elimina(CQSisLstProdCotiza *);
};
#endif
