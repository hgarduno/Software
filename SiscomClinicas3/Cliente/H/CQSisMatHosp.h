#ifndef __CQSISMATHOSP_H__
#define __CQSISMATHOSP_H__
#include <SISCOMComunicaciones++.h>
class SisUsuarioSeg3;
class CQSisConsulta;
class CQSisPersona;

class CQSisMatHosp:public SiscomInformacion
{
public:
	CQSisMatHosp(CQSisConsulta  *,
		     SisUsuarioSeg3 *,
		     const char *,
		     const char *,
		     const char *,
		     const char *);
	CQSisMatHosp(const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *,
		     const char *);
private:
	CQSisConsulta *CQSConsulta;
	SisUsuarioSeg3 *SUSeg3Firmado;
};

class CQSisLstMatHosp:public QPtrList<CQSisMatHosp>
{
public:
	CQSisLstMatHosp();
	CQSisLstMatHosp &operator<<(CQSisMatHosp *);
};


class CQSisOpMatHosp:public SiscomOperaciones
{
public:
	CQSisOpMatHosp(SiscomDatCom *);
	void MatHosp(CQSisLstMatHosp *);
	void MatHosp(const char *,CQSisLstMatHosp *);
private:
	SiscomParametrosConsulta SPConsulta;
};

#endif
