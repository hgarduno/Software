#ifndef __CQSISEMPLEADOS_H__
#define __CQSISEMPLEADOS_H__
#include <SISCOMComunicaciones++.h>
class SisPersona;
class CQSisEmpleado:public SiscomInformacion
{
public:
	CQSisEmpleado(const char *,
		      const char *,
		      const char *,
		      const char *,
		      const char *,
		      const char *,
		      const char *,
		      const char *,
		      const char *);
	CQSisEmpleado();
	CQSisEmpleado(SisPersona *);
	SisPersona *Persona();
private:
	SisPersona *SPersona;
};

class CQSisLstEmpleado:public QPtrList<CQSisEmpleado>
{
public:
	CQSisLstEmpleado();
	CQSisLstEmpleado &operator<<(CQSisEmpleado *);

};
#endif
