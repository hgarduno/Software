#ifndef __CQSISDIRECCIONES_H__
#define __CQSISDIRECCIONES_H__
#include <SISCOMComunicaciones++.h>
class SisDireccion;
/*!
 * Almacena la informacion de la direccion asociada a una persona <br>
 * Los datos de la direccion se almacenaran en SiscomInformacion,  <br>
 * mediante los siguientes nombres:<br>
 *
 * Calle <br>
 * Numero <br>
 * Referencias<br>
 * Asentamiento<br>
 * TipoAsentamiento<br>
 * Estado<br>
 * Municipio<br>
 *
 * Los datos anteriores para el caso del registro de la direccion<br>
 * Mientra para la consulta de una direccion se tienen lo siguiente:<br>
 *
 *
 * 
 *
 */
class CQSisDireccion:public SiscomInformacion
{
public:
	CQSisDireccion(
		const char *,
		const char *,
		const char *,
		const char *,
		const char *,
		const char *,
		const char *);
	CQSisDireccion(const char *,
		       const char *,
		       const char *,
		       const char *,
		       const char *);
};
/*!
 * Manipula una lista de direcciones asociadas a una persona
 */
class CQSisLstDireccion:public QPtrList<CQSisDireccion>
{
public:
	CQSisLstDireccion();
	CQSisLstDireccion &operator<<(CQSisDireccion *);

};
/*!
 * Ejecuta operaciones a la lista de direcciones de una persona <br>
 *
 */
class CQSisOpDireccion:public SiscomOperaciones
{
public:
	CQSisOpDireccion(SiscomDatCom *,const char *);
	CQSisOpDireccion(SiscomDatCom *);
	void DireccionesPersona(const char *,CQSisLstDireccion *);
	void Registra(CQSisDireccion *);
private:
	SiscomParametrosConsulta SPConsulta;
	const char *chrPtrSistemaConsulta;
};

#endif
