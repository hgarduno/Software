#ifndef __CQSISTIPOPRECIO_H__
#define __CQSISTIPOPRECIO_H__
#include <SISCOMComunicaciones++.h>

class CQSisTipoPrecio:public SiscomInformacion
{
public:
	CQSisTipoPrecio(const char *,
			const char *,
			const char *);
};
class CQSisLstTipoPrecio:public QPtrList<CQSisTipoPrecio>
{
public:
	CQSisLstTipoPrecio();
	CQSisLstTipoPrecio &operator<<(CQSisTipoPrecio *);
};

class CQSisOpTipoPrecio:public SiscomOperaciones
{
public:
	CQSisOpTipoPrecio(SiscomDatCom *);
	void TipoPrecio(CQSisTipoPrecio *);
	void TipoPrecio(CQSisLstTipoPrecio *);
private:
	SiscomParametrosConsulta SPConsulta;
private:
	void EliminaTiposPrecio(CQSisLstTipoPrecio *);
};
#endif
