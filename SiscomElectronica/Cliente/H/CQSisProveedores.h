#ifndef __CQSISPROVEEDORES_H__
#define __CQSISPROVEEDORES_H__
#include <SiscomOperaciones3.h>

class SiscomDatCom;
class SiscomRegistro3Lst;
class CQSisProveedores:public SiscomOperaciones3
{
public:
	CQSisProveedores(SiscomDatCom *);
	void Proveedores(const char *,SiscomRegistro3Lst *);
};
#endif
