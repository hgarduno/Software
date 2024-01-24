#ifndef __CQSISGIMNASIOS_H__
#define __CQSISGIMNASIOS_H__
#include <SISCOMComunicaciones++.h>
class SisDireccion;
class SisMedCom;
class SisPersona;
class CQSisGimnasio:public SiscomInformacion2
{
public:
	CQSisGimnasio(const char *,
		      const char *);
	CQSisGimnasio(const char *,
		      const char *,
		      const char *);
	void PonDireccion(SisDireccion *);
	void PonTelefono(SisMedCom *);
	void PonContacto(SisPersona *);
	void PonValidaNombre(const char *);
	void PonEsEntrenadorContacto(const char *);
private:
	const char *chrPtrIdGimnasio;
	const char *chrPtrGimnasio;
	const char *chrPtrEdoValidacion;
private:
	void SiscomAnexaRegistro();
	void SiscomFormaRegistro();
};

class CQSisLstGimnasio:public QPtrList<CQSisGimnasio>
{
public:
	CQSisLstGimnasio();
	CQSisLstGimnasio &operator<<(CQSisGimnasio *);
};
class CQSisOpGimnasio:public SiscomOperaciones
{
public:
	CQSisOpGimnasio(SiscomDatCom *);
	void InsertaGimnasio(CQSisGimnasio  *,CQSisLstGimnasio *);
	void GimnasiosRegistrados(CQSisLstGimnasio *);
private:
	CQSisLstGimnasio CQSisLGimnasio;
	SiscomParametrosConsulta SPConsulta;
private:
	void SiscomGeneraRegistrosActualiza(const SiscomComunicaSrv *,
					    SiscomInformacionLst *);
	
	void SiscomGeneraRegistros(const SiscomComunicaSrv *,
					    SiscomInformacionLst *);
	void FormaConsultaGimnasiosRegistrados();
};
#endif
