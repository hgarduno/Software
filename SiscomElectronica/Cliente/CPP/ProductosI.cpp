#include <ProductosI.h>
/*! \file ProductosI.cpp
 *
 * Archivo que contiene la informacion de los datos
 * que se utilizaran, en el control de inventarios
 *
 * Autor: Heli Garduno Esquivel
 * Fecha: 2007-05-30
 *
 */

ProductoI::ProductoI(const char *pchrPtrCveProducto,
		       const char *pchrPtrDescripcion,
		       const char *pchrPtrEdoProducto,
		       const char *pchrPtrEdoRegistro,
		       const char *pchrPtrCantidad,
		       const char *pchrPtrInventario,
		       const char *pchrPtrExistencia,
		       const char *pchrPtrPrecio,
		       const char *pchrPtrTotal,
		       const char *pchrPtrExpendio,
		       const char *pchrPtrFechaReg)
{

	SRegistroPro2 <<
	"CveProducto"	<<
	"Descripcion"	<<
	"EdoProducto"	<<
	"EdoRegistro"	<<
	"Cantidad"	<<
	"Inventario"	<<
	"Existencia"	<<
	"Precio"	<<
	"Total"		<<
	"Expendio"	<<
	"FechaReg";
	SRegistrosPro2.PonRegistroPro2(&SRegistroPro2);
	SRegistrosPro2 						<<
	SiscomCampoPro2("CveProducto",pchrPtrCveProducto) 	<<
	SiscomCampoPro2("Descripcion",pchrPtrDescripcion)	<<
	SiscomCampoPro2("EdoProducto",pchrPtrEdoProducto)	<<
	SiscomCampoPro2("EdoRegistro",pchrPtrEdoRegistro)	<<
	SiscomCampoPro2("Cantidad",pchrPtrCantidad)		<<
	SiscomCampoPro2("Inventario",pchrPtrInventario)		<<
	SiscomCampoPro2("Existencia",pchrPtrExistencia)		<<
	SiscomCampoPro2("Precio",pchrPtrPrecio)			<<
	SiscomCampoPro2("Total",pchrPtrTotal)			<<
	SiscomCampoPro2("Expendio",pchrPtrExpendio)		<<
	SiscomCampoPro2("FechaReg",pchrPtrFechaReg);
	SRegistrosPro2.SiscomAnexaRegistro();
}
ProductosI::ProductosI()
{

}
ProductosI &ProductosI::operator<<(ProductoI *pProducto)
{
	append(pProducto);
	return *this;
}
