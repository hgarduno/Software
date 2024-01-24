#ifndef __INVENTARIODIA_H__
#define __INVENTARIODIA_H__
#include <SISCOMComunicaciones++.h>
#include <Personas.h>
#include <ProductosI.h>

/*! \file InventariosDia.h
 *
 * Archivo que contiene la informacion de los datos
 * que se utilizaran, en el control de los inventarios
 * programados
 *
 * Autor: Heli Garduno Esquivel
 * Fecha: 2007-05-30
 *
 */

/*! \class InventarioDia 
 *  \brief Objeto que contiene la informacion de un producto
 *  	   para el manejo, en el control de inventarios
 *  	   programados
 *  \author Heli Garduno Esquivel
 *  \version 1.0
 *  \date 2007-05-30
 */

class InventarioDia:public SiscomInformacion
{
public:
	/*! Constructor de la clase.
	 * \param pchrPtrFecha Fecha en la que se debera 
	 *  		       realizar el inventario.
	 *  \param pPEmpleado Informacion general del empleado
	 *                    que debera ejecutar el inventario.
	 */
	InventarioDia(const char *pchrPtrFecha,
		      Persona *pPEmpleado);

	/*! Anexa un producto al inventario programado 
	 * \param pProductoI Producto que se anexara al inventario
	 */
	void AnexaProducto(ProductoI *);

	/*! Obten Productos del Inventario 
	 * \param pProductosI Parametro de salida, en el cual se copiaran
	 * 		      los productos del inventario
	 */
 	 void 	ObtenProductos(ProductosI &pProductosI);
private:
	
	ProductosI PProductosI;
};
/*! \class InventariosDia 
 *  \brief Objeto que contiene una lista de inventarios
 *  \author Heli Garduno Esquivel
 *  \version 1.0
 *  \date 2007-05-30
 */

class InventariosDia:public QPtrList<InventarioDia>
{
public:
	/*! Constructor de la lista
	 */
	InventariosDia();
	/*! Operador sobrecargado para agregar nodos a la
	 * lista de inventarios
	 * \param pInventarioDia Nodo a anexar a la lista
	 */
	InventariosDia &operator <<(InventarioDia *pInventarioDia);
};
/*! \class OpInventariosDia 
 *  \brief Objeto que resulve la interaccion con el servidor 
 *         de la aplicacion para resolver las distintas operaciones
 *         que se podran realizar, en la que se involucra la informacion
 *         del control de inventarios
 *  \author Heli Garduno Esquivel
 *  \version 1.0
 *  \date 2007-05-30
 */

class OpInventariosDia:SiscomOperaciones
{
public:
	/*! Constructor de la clase 
	 * \param pSiscomDatCom Datos de comunicacion con el servidor 
	 *                      de la aplicacion
	 */
	OpInventariosDia(SiscomDatCom *pSiscomDatCom);

	/*! Registra la programacion de un inventario 
	 * \param pInventariosD Lista de los inventarios a programar
	 */
	void RegistraInventarios(InventariosDia &pInventariosD);

	/*! Ejecuta la consulta de los inventarios programados por fecha 
	 * \param pchrPtrFechaIni Fecha de inicio, de la consulta
	 * \param pchrPtrFechaFin Fecha fin, de la consulta
	 * \param pInventariosDia Resultado de la consulta
	 */
	void ConsultaInventariosFecha(const char *pchrPtrFechaIni,
				      const char *pchrPtrFechaFin,
				      InventariosDia &pInventariosDia);
	/*! Ejecuta la consulta de inventarios por empleado
	 * \param pPersonas Lista de empleados a consultar
	 * \param pInventariosDia Resultado de la consulta
	 */
	void ConsultaInventariosEmpleados(Personas pPersonas,
					  InventariosDia &pInventariosDia);


};
#endif
