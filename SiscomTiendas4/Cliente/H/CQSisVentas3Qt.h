#ifndef __CQSISVENTAS3QT_H__
#define __CQSISVENTAS3QT_H__
#include <SiscomOperaciones3.h>

class SiscomDatCom;
class CQSisProdCotiza3QtLst;

class CQSisOpVentas3Qt:public SiscomOperaciones3
{
public:
	CQSisOpVentas3Qt(SiscomDatCom *);
	void RegistraVenta(CQSisProdCotiza3QtLst *);

	void ProductosPorAproximacion(const char *pchrPtrTexto,
				      SiscomRegistro3Lst *);


};
#endif
