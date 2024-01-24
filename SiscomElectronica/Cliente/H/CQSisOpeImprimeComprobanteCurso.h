#ifndef __CQSISOPEIMPRIMECOMPROBANTECURSO_H__
#define __CQSISOPEIMPRIMECOMPROBANTECURSO_H__
#include <SiscomOperaciones3.h>

class CQSisImprimeComprobantePagoCurso;

class CQSisOpeImprimeComprobanteCurso:public SiscomOperaciones3
{
public:
	CQSisOpeImprimeComprobanteCurso(SiscomDatCom *pSisDatCom);
	void ImprimeComprobante(CQSisImprimeComprobantePagoCurso *pCQSCPCurso);

};

#endif
