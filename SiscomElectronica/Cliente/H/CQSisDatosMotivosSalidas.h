#ifndef __CQSISDATOSMOTIVOSSALIDAS_H__
#define __CQSISDATOSMOTIVOSSALIDAS_H__
#include <SiscomRegistros.h>
class CQSisDatosMotivosSalidas:public SiscomRegistro4
{
public:
	CQSisDatosMotivosSalidas(const char *pchrPtrIdExpendio);
	SiscomRegistro3 *MotivosSalidas(const char *pchrPtrIdExpendio);
};
#endif
