#ifndef __CQSISMEDSCOMUNICACION_H__
#define __CQSISMEDSCOMUNICACION_H__
#include <SISCOMComunicaciones++.h>

class SisMedCom;
class SisLstMedCom;
class CQSisOpMedComunicacion:public SiscomOperaciones
{
public:
	CQSisOpMedComunicacion(SiscomDatCom *,const char *);
	CQSisOpMedComunicacion(SiscomDatCom *);
	void MedComunicacion(const char *,const char *,SisLstMedCom *);
	void Registra(SisMedCom *);
private:
	const char *chrPtrSistemaConsulta;
	SiscomParametrosConsulta SPConsulta;
};
#endif
