#ifndef __CQSISCLASE_H__
#define __CQSISCLASE_H__
#include <SISCOMComunicaciones++.h>

class CQSisClase:public SiscomInformacion
{
public:
	CQSisClase(const char *,
		   const char *,
		   const char *);
	int operator==(CQSisClase *);
private:
	void SiscomFormaRegistro();
	void SiscomAnexaRegistro();
private:
	const char *chrPtrIdClase;
	const char *chrPtrIdTipoCompetencia;
	const char *chrPtrClase;

};

class CQSisLstClase:public QPtrList<CQSisClase>
{
public:
	CQSisLstClase();
	CQSisLstClase &operator<<(CQSisClase *);
	int operator[](CQSisClase *);

};

class CQSisOpClase:public SiscomOperaciones
{
public:
	CQSisOpClase(SiscomDatCom *);
	void InsertaCompetencia(CQSisClase *,SiscomRegistrosPro2 **);
private:
	CQSisLstClase CQSLClase;
};

#endif
