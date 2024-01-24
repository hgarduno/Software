#ifndef __CQSRONDA_H__
#define __CQSRONDA_H__
#include <SISCOMComunicaciones++.h>
#include <CQSisAparatoCompetencia.h>
class CQSisAparatoCompetencia;
class CQSisLstCompitiendo;
class CQSisCompitiendo;


class CQSisRonda:public SiscomInformacion
{
public:
	CQSisRonda(const char *,
		   const char *,
		   const char *,
		   CQSisAparatoCompetencia *,
		   CQSisLstCompitiendo *);
	CQSisRonda(const char *,
		   const char *,
		   const char *,
		   const char *,
		   const char *);
	CQSisLstCompitiendo *Compitiendo();
	CQSisAparatoCompetencia *Aparato();

private:
	CQSisLstCompitiendo *CQSLCompitiendo;
	CQSisAparatoCompetencia *CQSACompetencia;
private:
	void AnexaGimnastas(const char *,const char *);
};

class CQSisLstRonda:public QPtrList<CQSisRonda>
{
public:
	CQSisLstRonda();
	CQSisLstRonda &operator<<(CQSisRonda *);
	void AnexaAparato(CQSisAparatoCompetencia *);
	CQSisLstAparatoCompetencia &Aparatos();
	const char *IdRonda();
	const char *Nombre();
	int operator==(CQSisLstRonda *);
private:
	CQSisLstAparatoCompetencia CQSLACompetencia;
	const char *chrPtrIdRonda;
	const char *chrPtrNombre;
};
class CQSisLstLstRonda:public QPtrList<CQSisLstRonda>
{
public:
	CQSisLstLstRonda();
	CQSisLstLstRonda &operator<<(CQSisLstRonda *);
	CQSisAparatoCompetencia *AparatoGimnasta(CQSisCompitiendo *);
};
class CQSisOpRonda:public SiscomOperaciones
{
public:
	CQSisOpRonda(SiscomDatCom *);
	void RegistraRondas(CQSisLstRonda *);
};
#endif

