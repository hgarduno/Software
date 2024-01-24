#ifndef __CQSISEXPEDIENTES_H__
#define __CQSISEXPEDIENTES_H__
#include <SISCOMComunicaciones++.h>

class CQSisPersona;
class CQSisExpediente:public SiscomInformacion
{
public:
	CQSisExpediente(
		const char *,
		const char *,
		const char *);
	CQSisExpediente(CQSisPersona *,
			const char *,
			const char *);
	CQSisPersona *Medico();
public:
	CQSisPersona *CQSMedico;
};

class CQSisLstExpediente:public QPtrList<CQSisExpediente>
{
public:
	CQSisLstExpediente();
	CQSisLstExpediente &operator<<(CQSisExpediente *);
};

class CQSisOpExpediente:public SiscomOperaciones
{
public:
	CQSisOpExpediente(SiscomDatCom *);
	void RegistraConsulta(CQSisExpediente *,SiscomRegistrosPro2 **);
	void ActualizaObservaciones(CQSisExpediente *,SiscomRegistrosPro2 **);
	void ObservacionesConsulta(const char *,CQSisLstExpediente *);
	void Expediente(const char *,CQSisLstExpediente *);
private:
	SiscomParametrosConsulta SPConsulta;
private:
	void Elimina(CQSisLstExpediente *);
};
#endif
