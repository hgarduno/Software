#ifndef __CQSISPUNTOSELECTRONICA_H__
#define __CQSISPUNTOSELECTRONICA_H__
#include <SiscomOperaciones3.h>
#include <SiscomRegistros4.h>
class SiscomRegistro4;
class SiscomDatCom;
/*
 * Viernes 29 Julio 2011 
 * En esta clase se almacenaran los siguientes 
 * datos 
 * Datos del cliente
 * Puntos del cliente 
 * Promociones a las que tiene derecho con 
 * lo puntos
 *
 */
class CQSisPromocionesCliente;
class CQSisPuntosPromocionCliente:public SiscomRegistro4
{
public:
	CQSisPuntosPromocionCliente();

};

class CQSisOpPuntosElectronica:public SiscomOperaciones3
{
public:
	CQSisOpPuntosElectronica(SiscomDatCom *);
	void PuntosPromocionesCliente(const char *pchrPtrIdExpendio,
					const char *pchrPtrIdCliente,
					const char *pchrPtrNmbCliente,
			   		SiscomRegistro4 *pSisReg4Regreso);
	void ValidaPuntosPromocionesSel(SiscomRegistro3Lst *pSisReg3LstPromciones,
					SiscomRegistro4 *pSisReg4Regreso);
	void TomaPromociones(CQSisPromocionesCliente *);

};

#endif
