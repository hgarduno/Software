#ifndef __CQSISGRUPO_H__
#define __CQSISGRUPO_H__
#include <SISCOMComunicaciones++.h>

class CQSisGrupo:public SiscomInformacion
{
public:
	CQSisGrupo(const char *,
		   const char *,
		   const char *,
		   const char *,
		   const char *,
		   const char *pchrPtrRangoEdad="");
	int operator==(CQSisGrupo *);
private:
	void SiscomFormaRegistro();
	void SiscomAnexaRegistro();
private:
	const char *chrPtrIdGrupo;
	const char *chrPtrIdTipoCompetencia;
	const char *chrPtrEdadIni;
	const char *chrPtrEdadFin;
	const char *chrPtrGrupo;
	const char *chrPtrRangoEdad;

};

class CQSisLstGrupo:public QPtrList<CQSisGrupo>
{
public:
	CQSisLstGrupo();
	CQSisLstGrupo &operator<<(CQSisGrupo *);
	int operator[](CQSisGrupo *);

};

class CQSisOpGrupo:public SiscomOperaciones
{
public:
	CQSisOpGrupo(SiscomDatCom *);
	void InsertaCompetencia(CQSisGrupo *,SiscomRegistrosPro2 **);
private:
	CQSisLstGrupo CQSLClase;
};

#endif
