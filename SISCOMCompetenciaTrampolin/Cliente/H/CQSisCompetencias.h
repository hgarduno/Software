#ifndef __CQSISCOMPETENCIA_H__
#define __CQSISCOMPETENCIA_H__
#include <SISCOMComunicaciones++.h>

class CQSisCompetencia:public SiscomInformacion
{
public:
	CQSisCompetencia();	
	CQSisCompetencia(const char *,
			 const char *,
			 const char *,
			 const char *);
	void PonFechaIniInscripcion(const char *);
	void PonFechaFinInscripcion(const char *);
	void PonDescripcion(const char *);
	void PonBases(const char *);
private:
	void SiscomFormaRegistro();
	void SiscomAnexaRegistro();
private:
	const char *chrPtrNombre;
	const char *chrPtrFecha;
	const char *chrPtrIdCompetencia;
	const char *chrPtrIdTipoCompetencia;

};

class CQSisLstCompetencia:public QPtrList<CQSisCompetencia>
{
public:
	CQSisLstCompetencia();
	CQSisLstCompetencia &operator<<(CQSisCompetencia *);

};

class CQSisOpCompetencia:public SiscomOperaciones
{
public:
	CQSisOpCompetencia(SiscomDatCom *);
	void InsertaCompetencia(CQSisCompetencia *,SiscomRegistrosPro2 **);
private:
	CQSisLstCompetencia CQSLCompetencia;
};

#endif
