#ifndef __CQSISOPTIENDAS4_H__
#define __CQSISOPTIENDAS4_H__
#include <SISCOMComunicaciones++.h>
class CQSisFamilia;
class CQSisProducto;
class CQSisPrecio;
class CQSisDatoPrecio;
class CQSisEmpresa;
class CQSisContacto;
class CQSisFormaPago;
class CQSisEmpleado;
class CQSisCliente;
class SisMedCom;
class SisLstMedCom;
class CQSisLstFamilia;
class CQSisLstProducto;
class CQSisLstPrecio;
class CQSisLstDatoPrecio;
class CQSisLstEmpresa;
class CQSisLstContacto;
class CQSisLstFormaPago;
class CQSisLstCliente;
class CQSisLstProdCotiza;
class CQSisLstOrden;
/*!
 * Operaciones generales del Sistema Siscom Tiendas4
 *
 *
 */
class CQSisOpTiendas4:public SiscomOperaciones
{
public:
	CQSisOpTiendas4(SiscomDatCom *);
	~CQSisOpTiendas4();
	void Cliente(CQSisCliente *,SiscomRegistrosPro2 **);
	void Empleado(CQSisEmpleado *,SiscomRegistrosPro2 **);
	void AnexaFamilia(CQSisFamilia *);
	void AnexaProducto(CQSisProducto *);
	void AnexaPrecio(CQSisPrecio *);
	void AnexaEmpresa(CQSisEmpresa *);

	void Familias(CQSisLstFamilia *);
	void Productos(CQSisLstProducto *);
	void Precios(CQSisLstPrecio *);
	void PreciosProducto(CQSisProducto *,
			     CQSisLstDatoPrecio *);
	void Proveedores(CQSisLstEmpresa *);
	void ContactosProveedor(CQSisEmpresa *,CQSisLstContacto *);
	void MediosComunicacion(SisLstMedCom *);
	void FormaPago(CQSisLstFormaPago *);
	void Clientes(CQSisLstCliente *);

	void ActualizaProducto(CQSisProducto *);
	void ActualizaPrecioProducto(CQSisProducto *,
				     CQSisDatoPrecio *);

	void IniciaPrecios(SiscomRegistrosPro2 **);
	void EjecutaDevolucion(CQSisLstProdCotiza *,
			       SiscomRegistrosPro2 **);
	void CalculaTotalADevolver(CQSisLstProdCotiza *,
				   SiscomRegistrosPro2 **);
	void Ordenes(CQSisEmpresa *,
		     const char *,
		     const char *,
		     const char *,
		     CQSisLstOrden *);
	void ExistenciaProductos(CQSisLstProdCotiza *);

private:
	void FormaProductoExistencia(SiscomRegistrosPro2 *,CQSisLstProdCotiza *);
	void FormaOrden(SiscomRegistrosPro2 *,CQSisLstOrden *);
	void FormaFormaPago(SiscomRegistrosPro2 *,CQSisLstFormaPago *);
	void FormaPersonas(SiscomRegistrosPro2 *,CQSisLstContacto *);
	void FormaEmpresas(SiscomRegistrosPro2 *,CQSisLstEmpresa *);
	void FormaFamilias(SiscomRegistrosPro2 *,
			   CQSisLstFamilia *);
	void FormaProductos(SiscomRegistrosPro2 *,
			    CQSisLstProducto *);
	void FormaPrecios(SiscomRegistrosPro2 *,
			  CQSisLstPrecio *);
	void FormaPreciosProducto(SiscomRegistrosPro2 *,
				  CQSisLstDatoPrecio *);
	void FormaClientes(SiscomRegistrosPro2 *,CQSisLstCliente *);
	void FormaMedios(SiscomRegistrosPro2 *,SisLstMedCom *);
	CQSisFormaPago *FormaFormaPagoProtocolo(SiscomRegistrosPro2 *);
	CQSisProducto *FormaProductoProtocolo(SiscomRegistrosPro2 *);
	CQSisPrecio *FormaPrecioProtocolo(SiscomRegistrosPro2 *);
	SisMedCom *FormaMedComProtocolo(SiscomRegistrosPro2 *);
	CQSisEmpresa *FormaEmpresaProtocolo(SiscomRegistrosPro2 *);
	CQSisContacto *FormaPersonaProtocolo(SiscomRegistrosPro2 *);

	void EliminaProductosCotiza(CQSisLstProdCotiza *);

private:
	SiscomParametrosConsulta SPConsulta;
};

#endif
