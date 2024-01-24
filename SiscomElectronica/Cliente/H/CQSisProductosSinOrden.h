#ifndef __CQSISPRODUCTOSSINORDEN_H__
#define __CQSISPRODUCTOSSINORDEN_H__
#include <SiscomOperaciones3.h>
class CQSisProductoE3;
class CQSisProductosSinOrden:public SiscomOperaciones3
{
public:
	CQSisProductosSinOrden(SiscomDatCom *);
	void Registra(const char *,CQSisProductoE3 *);

};
#endif
