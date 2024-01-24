#ifndef __COTIZACIONES_H__
#define __COTIZACIONES_H__
#include <Productos.h>
#include <TiposPrecios.h>
class CQOGenericaServidorSiscom;
class ProductoCotizacion
{
	public:
		ProductoCotizacion(Producto *,
				   const char *,
				   const char *,
				   const char *,
				   const char *);
		const char *ObtenCantidad();
		const char *ObtenExistencia();
		const char *ObtenSePuedeVender();
		const char *ObtenImporte();
		const char *ObtenNmbTipoPrecio();
		Producto *ObtenProducto();
		void PonCantidad(const char *);
		void PonExistencia(const char *);
		void PonSePuedeVender(const char *);
		void PonImporte(const char *);
private:
		Producto *P_Producto;
		const char *chrPtrCantidad;
		const char *chrPtrExistencia;
		const char *chrPtrImporte;
		const char *chrPtrSePuedeVender;


};

class CQProductosCotizacion:public QPtrList<ProductoCotizacion>
{
	public:
		CQProductosCotizacion();
		~CQProductosCotizacion();
		const char *ObtenImporteTotal();
		void PonImporteTotal(const char *);
		ProductoCotizacion *operator[](const char *);
	private:
		const char *chrPtrImporteTotal;

};
class CQCtrCotizacion
{
	public:
		enum CtrCotizacion
		{
			Cotiza
		};
		CQCtrCotizacion(CSISCOMDatComunicaciones *,
				CtrCotizacion ,
				const char *,
				const char *,
				const char *,
				CQProductosCotizacion *);
private:
	CQOGenericaServidorSiscom *CQOGSvrSiscom;
        CSISCOMDatComunicaciones *CSisDatCom;
        QStringList QSLRegistro;
	const char *chrPtrParametrosCotizacion;
	int intNumParametrosCotizacion;
private:
	void EjecutaCotizacion(const char *,
			       const char *,
			       const char *,
				CQProductosCotizacion *);
	void AsignaRespuestaCotizacion(CQProductosCotizacion *);
	const char *ObtenPrecio(ProductoCotizacion *);
};
#endif
