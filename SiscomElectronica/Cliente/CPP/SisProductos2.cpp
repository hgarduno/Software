#include <SisProductos2.h>

SisProducto2::SisProducto2(const char *pchrPtrClave,
			     const char *pchrPtrExistencia,
			     const char *pchrPtrPrecio,
			     const char *pchrPtrCantidad)
{

	SiscomAsignaInformacion();

}

void SisProducto2::SiscomFormaRegistro()
{

	SRegistroPro2		<<
	"Clave"			<<
	"Existencia"		<<
	"Precio"		<<
	"Cantidad";
}
void SisProducto2::SiscomAnexaRegistro()
{
	SRegistrosPro2					<<
	SiscomCampoPro2("Clave",chrPtrClave)		<<
	SiscomCampoPro2("Existencia",chrPtrExistencia)	<<
	SiscomCampoPro2("Precio",chrPtrPrecio)		<<
	SiscomCampoPro2("Cantidad",chrPtrCantidad);
}
