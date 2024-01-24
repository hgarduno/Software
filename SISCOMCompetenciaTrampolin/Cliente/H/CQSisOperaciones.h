#ifndef __CQSISOPERACIONES_H__
#define __CQSISOPERACIOENS_H__
#include <SISCOMComunicaciones++.h>
class SisDireccion;
class CQSisEntrenador;

class CQSisAnexaDireccion:public SiscomInformacion
{
public:
	CQSisAnexaDireccion(SisDireccion *,const char *);
};
class CQSisLstAnexaDireccion:public QPtrList<CQSisAnexaDireccion>
{
public:
	CQSisLstAnexaDireccion();
	CQSisLstAnexaDireccion &operator<<(CQSisAnexaDireccion *);
};
class CQSisActPersona:public SiscomInformacion
{
public:
	CQSisActPersona(const char *,
			const char *,
			const char *,
			const char *,
			const char *);

};

class CQSisAnexaMedio:public SiscomInformacion
{
public:
	CQSisAnexaMedio(const char *,
			const char *,
			const char *,
			const char *);
};
class CQSisLstAnexaMedio:public QPtrList<CQSisAnexaMedio>
{
public:
	CQSisLstAnexaMedio();
	CQSisLstAnexaMedio &operator<<(CQSisAnexaMedio *);
};

class CQSisLstActPersona:public QPtrList<CQSisActPersona>
{
public:
	CQSisLstActPersona();
	CQSisLstActPersona &operator<<(CQSisActPersona *);
};
class CQSisOperaciones:public SiscomOperaciones
{
public:
	CQSisOperaciones(SiscomDatCom *);

	void ActualizaDatosGenerales(CQSisEntrenador *,
				     const char *,
				     const char *,
				     const char *,
				     const char *);
	void AnexaMedio(CQSisEntrenador *,
			const char *,
			const char *,
			const char *);
	void AnexaDireccion(CQSisEntrenador *,
			    SisDireccion *);
private:
	CQSisActPersona *CQSAPersona;
};
#endif
