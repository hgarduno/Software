#ifndef __SIS3QTPRODUCTOS_H__
#define __SIS3QTPRODUCTOS_H__
#include <SiscomRegistros3.h>
/*!
 * \brief Almacena la informacion del producto <br>
 */

class Sis3QtProducto:public SiscomRegistro3
{
public:
	/*!
	 * \brief Constructor de la clase 
	 * \param[in] pchrPtrCveProducto Clave del producto
	 * \param[in] pchrPtrDscProducto Descripcion
	 * \param[in] pchrPtrUnidad Unidad
	 * \param[in] pchrPtrIdFamilia IdFamilia
	 * \param[in] pchrPtrFamilia
	 */
	Sis3QtProducto(const char *pchrPtrCveProducto,
		       const char *pchrPtrDscProducto,
		       const char *pchrPtrUnidad,
		       const char *pchrPtrIdFamilia,
		       const char *pchrPtrFamilia);

};

#endif
