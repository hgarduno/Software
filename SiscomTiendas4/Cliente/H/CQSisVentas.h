#ifndef __CQSISVENTAS_H__
#define __CQSISVENTAS_H__
#include <SISCOMComunicaciones++.h>
class CQSisLstProdCotiza;
class CQSisProdCotiza;
/*
 * Se debera agregar, el manejo para los productos cotizando 
 *
 *
 */




class CQSisVenta:public SiscomInformacion
{
public:
	CQSisVenta(CQSisProdCotiza *);
};

class CQSisLstVenta:public QPtrList<CQSisVenta>
{
public:
	CQSisLstVenta();
	CQSisLstVenta &operator<<(CQSisVenta *);
};
class CQSisOpVenta:public SiscomOperaciones
{
public:
	CQSisOpVenta(SiscomDatCom *);
	void RegistraVenta(CQSisLstProdCotiza *);
};
#endif
