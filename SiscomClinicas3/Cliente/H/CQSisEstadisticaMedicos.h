#ifndef __CQSISESTADISTICASMEDICOS_H__
#define __CQSISESTADISTICASMEDICOS_H__
#include <SISCOMComunicaciones++.h>

class CQSisEstadisticaMedico:public SiscomInformacion
{
public:
	CQSisEstadisticaMedico();

};
class CQSisLstEstadisticaMedico:public QPtrList<CQSisEstadisticaMedico>
{
public:
	CQSisLstEstadisticaMedico();

};

#endif
