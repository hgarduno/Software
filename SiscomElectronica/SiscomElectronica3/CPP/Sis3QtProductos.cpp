#include <Sis3QtProductos.h>
Sis3QtProducto::Sis3QtProducto(const char *pchrPtrCveProducto,
				const char *pchrPtrDscProducto,
				const char *pchrPtrUnidad,
				const char *pchrPtrIdFamilia,
				const char *pchrPtrFamilia)
{

	(*this)			<<
	new SiscomCampo3("CveProducto",pchrPtrCveProducto)	<<
	new SiscomCampo3("DscProducto",pchrPtrDscProducto)	<<
	new SiscomCampo3("Unidad",pchrPtrUnidad)		<<
	new SiscomCampo3("IdFamilia",pchrPtrIdFamilia)		<<
	new SiscomCampo3("Familia",pchrPtrFamilia);
}
