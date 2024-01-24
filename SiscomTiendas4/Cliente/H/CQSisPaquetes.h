#ifndef __CQSISPAQUETES_H__
#define __CQSISPAQUETES_H__
#include <SiscomOperaciones3.h>


class SiscomDatCom;

class CQSisPaquete:public SiscomRegistro3
{
public:
	CQSisPaquete(const char *,const char *,const char *);

};
/*!
 * En esta clase 
 *
 */
class CQSisPaqueteProducto:public SiscomRegistro3
{
public:
	CQSisPaqueteProducto(const char *,const char *,const char *);
};
class CQSisOpPaquetes:public SiscomOperaciones3
{
public:
	CQSisOpPaquetes(SiscomDatCom *);
	void RegistraPaquete(const char *,
			     const char *,
			     char *);

	void ProductosAlPaquete(const char *,
				SiscomRegistro3Lst *);
	void Paquetes(SiscomRegistro3Lst *);

	void ProductosDelPaquete(const char *,
				 SiscomRegistro3Lst *);

	void EliminaPaquete(const char *pchrPtrIdPaquete);
	void EliminaProducto(const char *,const char *);
	void AnexarProducto(CQSisPaqueteProducto *);

};
#endif
