/*! \file ProductosI.cpp
 *
 * Archivo que contiene la informacion de los datos
 * que se utilizaran, en el control de inventarios
 *
 * Autor: Heli Garduno Esquivel
 * Fecha: 2007-05-30
 *
 */


#ifndef __PRODUCTOSI_H__
#define __PRODUCTOSI_H__
#include <qptrlist.h>
#include <SISCOMComunicaciones++.h>
/*! \class ProductoI
 *  \brief Objeto que contiene la informacion de un producto
 *  	   para el manejo, en el control de inventarios
 *  \author Heli Garduno Esquivel
 *  \version 1.0
 *  \date 2007-05-30
 */

class ProductoI:public SiscomInformacion
{
	public:
	/*! 
	 * Constructor de la clase. Inicia el registro 
	 * que se utilizara para interactuar con el 
	 * servidor de la aplicacion.
	 * \param pchrPtrCveProducto Clave 
	 * \param pchrPtrDescripcion Descripcion
	 * \param pchrPtrEdoProducto Estado del producto, este 
	 * 			     parametro servira para in-
	 * 			     dicar si el producto, se ha
	 * 			     eliminado de la lista o esta
	 * 			     activo
	 * \param pchrPtrEdoRegistro Estado del registro, parametro
	 * 			     que le indicara al servidor si
	 * 			     se debe hacer una insercion, 
	 * 			     borrado o actualizacion del 
	 * 			     registro que se envia al servidor
	 * 			     para formar la cadena de SQL.
	 * 			     
	 * \param pchrPtrCantidad Cantidad del producto
	 * \param pchrPtrInventario Cantidad que se cuenta en la 
	 *                          ejecucion del inventario
	 * \param pchrPtrExistencia Existencia del producto, este
	 *                          dato se tomara de la tabla existencias
	 * \param pchrPtrPrecio  Precio al que se vende el producto
	 * \param pchrPtrTotal Nada
	 * \param pchrPtrExpendio Identificador del expendio, en el cual 
	 *                        se encuentra el producto.
	 * \param pchrPtrFechaReg Fecha en la que se anexo al inventario
	 *                        el producto
	 *
	 * 			     
	 */
		ProductoI(const char *pchrPtrCveProducto,
			  const char *pchrPtrDescripcion,
			  const char *pchrPtrEdoProducto,
			  const char *pchrPtrEdoRegistro,
			  const char *pchrPtrCantidad,
			  const char *pchrPtrInventario,
			  const char *pchrPtrExistencia,
			  const char *pchrPtrPrecio,
			  const char *pchrPtrTotal,
			  const char *pchrPtrExpendio,
			  const char *pchrPtrFechaReg);


};
/*! \class ProductosI
 *  \brief Lista de objetos ProductoI
 *  \author Heli Garduno Esquivel
 *  \version 1.0
 *  \date 2007-05-30
 */

class ProductosI:public QPtrList<ProductoI>
{
public:
	/*! Constructor de la lista ProductosI
	 */
	ProductosI();
	/*! Sobre carga del operador << . Con lo cual 
	 * se anexara a la lista de ProductosI un 
	 * objeto ProductoI
	 * \param pProductoI Apuntador, previamente inicializado 
	 * 		     y contine la informacion de un producto
	 * 		     para el control de inventarios
	 */
	ProductosI &operator<<(ProductoI *pProductoI);

};
/*! \class ProductosI
 *  \brief Operaciones que se realizaran, con los productos del inventario
 *  \author Heli Garduno Esquivel
 *  \version 1.0
 *  \date 2007-05-30
 */
class OpProductosI:public SiscomOperaciones
{
public:
	OpProductosI(SiscomDatCom *);

};
#endif
