#ifndef __CQSISPRODCOTIZA3QT_H__
#define __CQSISPRODCOTIZA3QT_H__
#include <SiscomRegistros3.h>
#include <SiscomOperaciones3.h>
class SiscomDatCom;
/*!
 * Manejo de los productos mediante la nueva version <br>
 * de la biblioteca libSiscomDesarrollo3Qt++.so
 *
 */
class CQSisProdCotiza3Qt:public SiscomRegistro3
{
public:
	/*!
	 * Constructor de la clase
	 * \param[in] pSisReg3Producto Producto
	 * \param[in] pSisReg3TipoPrecio Tipo Precio
	 * \param[in] pchrPtrCantidad Cantidad
	 * \param[in] pchrPtrImporte Importe
	 * \param[in] pchrPtrExistencia Existencia
	 * \param[in] pchrPtrExisMinima Existencia Minima
	 */
	CQSisProdCotiza3Qt(SiscomRegistro3 *pSReg3Producto,
			   SiscomRegistro3 *pSReg3TipoPrecio,
			   SiscomRegistro3 *pSReg3Cliente,
			   SiscomRegistro3 *pSReg3FPago,
			   const char *pchrPtrCantidad,
			   const char *pchrPtrPrecio,
			   const char *pchrPtrImporte,
			   const char *pchrPtrExistencia,
			   const char *pchrPtrExisMinima,
			   const char *pchrPtrEdoVenta,
			   const char *pchrPtrEscala,
			   const char *pchrPtrTipoOrden,
			   const char *pchrPtrIva,
			   const char *pchrPtrTotalSinIva,
			   const char *pchrPtrNoRemFactura);
			

};
class CQSisProdCotiza3QtLst:public SiscomRegistro3Lst
{
public:
	CQSisProdCotiza3QtLst();
	const char *Total();
	const char *Iva();
	const char *TotalSinIva();
	void Total(const char *);
	void Iva(const char *);
	void TotalSinIva(const  char *);
	void ActualizaPrecioCantidad(CQSisProdCotiza3QtLst &);
	int operator=(CQSisProdCotiza3QtLst &);
private:
	const char *chrPtrTotal;
	const char *chrPtrIva;
	const char *chrPtrTotalSinIva;
};
/*!
 * Realiza las operaciones de cotizacion de los productos
 *
 */
 
class CQSisOpProductos3Qt:public SiscomOperaciones3
{
public:
	CQSisOpProductos3Qt(SiscomDatCom *);
	void CotizaProductos(CQSisProdCotiza3QtLst *);
	void CotizaProducto(CQSisProdCotiza3Qt *);
	void GeneraIdentificador(CQSisProdCotiza3QtLst *);
private:
	void AsignaIdCotizacion(CQSisProdCotiza3QtLst *,
				CQSisProdCotiza3QtLst *);
};
#endif
