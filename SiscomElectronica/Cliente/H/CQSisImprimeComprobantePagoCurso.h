#ifndef __CQSISIMPRIMECOMPROBANTEPAGOCURSO_H__
#define __CQSISIMPRIMECOMPROBANTEPAGOCURSO_H__
#include <SiscomRegistros3.h>

class CQSisImprimeComprobantePagoCurso:public SiscomRegistro3
{

public:
	CQSisImprimeComprobantePagoCurso(SiscomRegistro3 *pSisReg3Alumno,
					 SiscomRegistro3 *pSisReg3Curso,
					 SiscomRegistro3 *pSisReg3Costo);

private:
	const char *ComunicacionTelefonica(SiscomRegistro3 *);
};

#endif

