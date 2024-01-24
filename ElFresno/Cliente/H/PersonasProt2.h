#ifndef __PERSONASPROT2_H__
#define __PERSONASPROT2_H__
#include <SISCOMComunicaciones++.h>
#include <Personas.h>
class RegConsultaPersona:public SiscomInformacion
{
public:
	RegConsultaPersona(const char *,
			const char *,
			const char *,
			const char *);

};

class RegConsultasPersona:public QPtrList<RegConsultaPersona>
{
public:
	RegConsultasPersona();
	RegConsultasPersona &operator<<(RegConsultaPersona *);

};

class PersonasProt2:public CQ_Personas
{
public:
	PersonasProt2();
	void GeneraRegistros(const SiscomComunicaSrv *);
	operator CQ_Personas *()
	{
		return (CQ_Personas *)this;
	}
private:
	int DireccionValida(SiscomRegistrosPro2);
	void AnexaDirecciones(SiscomRegistrosPro2 &,CQ_Persona *);
	void AnexaTelefonos(SiscomRegistrosPro2 &,CQ_Persona *);
	void AnexaCorreos(SiscomRegistrosPro2 &,CQ_Persona *);
	void AnexaFirma(SiscomRegistrosPro2 &,CQ_Persona *);
};
#endif
