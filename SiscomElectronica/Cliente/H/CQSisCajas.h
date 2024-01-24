#ifndef __CQSISCAJAS_H__
#define __CQSISCAJAS_H__
#include <SiscomRegistros3.h>
#include <SiscomOperaciones3.h>

class CQSisCaja:public SiscomRegistro3
{
public:
	CQSisCaja(const char *pchrPtrIdCaja,
		   const char *pchrPtrDireccionIp,
		   const char *pchrPtrDescripcion,
		   const char *pchrPtrImporte,
		   const char *pchrPtrIdExpendio);
};

class CQSisOpCajas:public SiscomOperaciones3
{
public:
	CQSisOpCajas(SiscomDatCom *);
	void RegistraImporteCaja(CQSisCaja *);
};
#endif
