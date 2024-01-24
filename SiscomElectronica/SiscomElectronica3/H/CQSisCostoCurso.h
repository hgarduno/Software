#ifndef __CQSISCOSTOCURSO_H__
#define __CQSISCOSTOCURSO_H__
#include <SiscomRegistros3.h>

class CQSisCostoCurso:public SiscomRegistro3Lst
{
public: 
   CQSisCostoCurso(const char *pchrPtrIdProgramacion,
   		   const char *pchrPtrIdCurso);
   void CostoAlCurso(const char *pchrPtrIdPromocion,
   		     const char *pchrPtrPromocion,
   	             const char *pchrPtrCosto);
private:
	const char *chrPtrIdProgramacion;
	const char *chrPtrIdCurso;
};

#endif
