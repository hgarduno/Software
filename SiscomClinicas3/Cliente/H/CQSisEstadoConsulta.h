#ifndef __CQSISESTADOCONSULTA_H__
#define __CQSISESTADOCONSULTA_H__
#include <SISCOMComunicaciones++.h>

class CQSisLstCotizando;
class CQSisEstadoConsulta:public SiscomInformacion
{
public:
	CQSisEstadoConsulta(const char *,
			    const char *,
			    const char *,
			    const char *);

};
class CQSisLstEstadoConsulta:public QPtrList<CQSisEstadoConsulta>
{
public:
	CQSisLstEstadoConsulta();
	CQSisLstEstadoConsulta &operator<<(CQSisEstadoConsulta *);
};
class CQSisOpEstadoConsulta:public SiscomOperaciones
{
public:
	CQSisOpEstadoConsulta(SiscomDatCom *);
	void EstadoConsulta(CQSisEstadoConsulta *,SiscomRegistrosPro2 **);
	void TerminaConsulta(const char *,CQSisLstCotizando *);
	void MaterialServicioHospitalizacion(const char *,CQSisLstCotizando *);

private:
	void EliminaLista(CQSisLstEstadoConsulta *);
};
#endif
