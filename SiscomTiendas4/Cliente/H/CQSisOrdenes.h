#ifndef __CQSISORDENES_H__
#define __CQSISORDENES_H__
#include <SISCOMComunicaciones++.h>
class CQSisCliente;
class CQSisFormaPago;
class CQSisOrden:public SiscomInformacion
{
public:
	CQSisOrden(CQSisCliente *,
		   CQSisFormaPago *,
		   const char *,
		   const char *,
		   const char *);
	CQSisCliente *Cliente();
	CQSisFormaPago *FormaPago();
private:
	CQSisCliente *CQSCliente;
	CQSisFormaPago *CQSFPago;
};
class CQSisLstOrden:public QPtrList<CQSisOrden>
{
public:
	CQSisLstOrden();
	CQSisLstOrden &operator<<(CQSisOrden *);

};
#endif
