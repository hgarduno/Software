#ifndef __CQSISCLIENTES3QT_H__
#define __CQSISCLIENTES3QT_H__
#include <SiscomRegistros3.h>
#include <SiscomOperaciones3.h>

class SiscomDatCom;
class CQSisResponsableVehiculo;
/*!
 * Contiene los datos genearles de una persona, que en el sistema tendra el 
 * tipo de persona Cliente 
 *
 */

class CQSisCliente3Qt:public SiscomRegistro3
{
public:
	CQSisCliente3Qt(const char *pchrPtrIdPersona,
			const char *pchrPtrNombre,
			const char *pchrPtrAPaterno,
			const char *pchrPtrAMaterno);
};	
/*!
 * Contiene la informacion de los clientes <br>
 *
 */
class CQSisCliente3QtLst:public SiscomRegistro3Lst
{
public:
	/*!
	 * Constructor de la clase
	 */
	CQSisCliente3QtLst();
	/*!
	 * Regresa el registro al que corresponde el nombre completo <br>
	 * del cliente
	 * \param[in] pchrPtrCliente Nombre completo del cliente 
	 */
	SiscomRegistro3 *Cliente(const char *pchrPtrCliente);
	int Cliente();
private:
	int intNCliente;

};


class CQSisClienteOp3Qt:public SiscomOperaciones3
{
public:
	CQSisClienteOp3Qt(SiscomDatCom *);
	int RegistraPropietario(CQSisCliente3Qt *);
	int RegistraResponsableVehiculo(CQSisResponsableVehiculo *);
	

};


#endif
