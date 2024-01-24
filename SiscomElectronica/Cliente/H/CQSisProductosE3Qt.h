#ifndef __CQSISPRODUCTOSE3QT_H__
#define __CQSISPRODUCTOSE3QT_H__
#include <SiscomRegistros3.h>
#include <SiscomOperaciones3.h>
class CQSisProductoE3:public SiscomRegistro3
{
public:
	CQSisProductoE3(SiscomRegistro3 *);
	CQSisProductoE3(const char *pchrPtrCveProducto,
			 const char *pchrPtrDscProducto,
			 const char *pchrPtrIdUnidad,
			 const char *pchrPtrIdFamilia,
			 const char *pchrPtrPrecio,
			 const char *pchrPtrNmbPrecio,
			 const char *pchrPtrCantidad,
			 const char *pchrPtrExistencia,
			 const char *pchrPtrIdCliente,
			 const char *pchrPtrIdExpendio,
			 const char *pchrPtrImporte,
			 const char *pchrPtrSePuedeVender,
			 const char *pchrPtrNumJuegos,
			 const char *pchrPtrIdProveedor,
			 const char *pchrPtrProveedor,
			 const char *pchrPtrNumFactura,
			 const char *pchrPtrFechaPago,
			 const char *pchrPtrEdoRegistro,
			 const char *pchrPtrIdPractica,
			 const char *pchrPtrNmbUnidad,
			 const char *pchrPtrAbreviatura,
			 const char *pchrPtrNmbFamilia,
			 const char *pchrPtrPrecioIVA,
			 const char *pchrPtrClienteFrecuente,
			 const char *pchrPtrPorDescuento,
			 const char *pchrPtrRFC,
			 const char *pchrPtrExistenciaMinima);
};

class CQSisOrdenesElectronica:public SiscomOperaciones3
{
public:
	CQSisOrdenesElectronica(SiscomDatCom *);
	void ProductosOrden(const char *pchrPtrIdExpendio,
			    const char *pchrPtrIdVenta,
			    SiscomRegistro3Lst *);
	void CotizaDispositivos(SiscomRegistro3Lst *);
};
#endif
