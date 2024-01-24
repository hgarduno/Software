#ifndef __CQSISCLIENTES_H__
#define __CQSISCLIENTES_H__
#include <SISCOMComunicaciones++.h>
class SisPersona;
class CQSisEmpresa;
class CQSisContacto;
class CQSisCliente:public SiscomInformacion
{
public:
	CQSisCliente();
	CQSisCliente(SisPersona *);
	CQSisCliente(CQSisEmpresa *,CQSisContacto *);
	CQSisCliente(const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *);
	SisPersona *Persona();
	CQSisEmpresa *Empresa();
	CQSisContacto *Contacto();
private:

SisPersona *SPersona;
CQSisEmpresa *CQSEmpresa;
CQSisContacto *CQSContacto;

};

class CQSisLstCliente:public QPtrList<CQSisCliente>
{
public:
	CQSisLstCliente();
	~CQSisLstCliente();
	CQSisLstCliente &operator<<(CQSisCliente *);
	int operator==(const char *);
	CQSisCliente *operator[](const char *);

};



#endif
