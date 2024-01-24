#ifndef __CQSISRECETAS_H_
#define __CQSISRECETAS_H__
#include <SISCOMComunicaciones++.h>

class CQSisReceta:public SiscomInformacion
{
public:
	CQSisReceta(const char *,
		    const char *,
		    const char *,
		    const char *,
		    const char *);
};

class CQSisLstReceta:public QPtrList<CQSisReceta>
{
public:
	CQSisLstReceta();
	CQSisLstReceta &operator<<(CQSisReceta *);
};

class CQSisOpReceta:public SiscomOperaciones
{
public:
	CQSisOpReceta(SiscomDatCom *);
	void Registra(CQSisReceta *);
	void Actualiza(CQSisReceta *);
	void Receta(const char *,CQSisLstReceta *);
	void Recetas(const char *,CQSisLstReceta *);
private:
	void Elimina(CQSisLstReceta *);
private:
	SiscomParametrosConsulta SPConsulta;
};
#endif
