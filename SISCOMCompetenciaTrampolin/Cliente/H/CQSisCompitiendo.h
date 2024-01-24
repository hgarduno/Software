#ifndef __CQSISCOMPITIENDO_H__
#define __CQSISCOMPITIENDO_H__
#include <SISCOMComunicaciones++.h>

//#define __SISCOMINFORMACION2__

class CQSisCompetencia;
class CQSisGimnasio;
class CQSisGimnasta;
class CQSisClase;
class CQSisGrupo;
class CQSisNivel;
class CQSisGrupo;
class CQSisEntrenador;
class CQSisCalificacion;
class CQSisAparato;

class CQSisLstGrupo;
class CQSisLstNivel;
class CQSisLstClase;
/* 
 * Esta clase se debera enviar con subregistros
 * el subregistro corresponde a los datos de las
 * personas.
 *
 * Para el gimnasta y para el entrenador 
 *
 */
class CQSisCompitiendo:public 
			#ifdef __SISCOMINFORMACION2__
			SiscomInformacion2
			#else
			SiscomInformacion
			#endif
{
public:
	CQSisCompitiendo(CQSisCompetencia *,
			 CQSisEntrenador *,
			 CQSisGimnasio *,
			 CQSisClase *,
			 CQSisNivel *,
			 CQSisGrupo *,
			 CQSisEntrenador *,
			 const char *);
	void PonCalificacion(CQSisCalificacion *);
	CQSisCompetencia *ObtenCompetencia();
	CQSisEntrenador  *ObtenGimnasta();
	CQSisGimnasio *ObtenGimnasio();
	CQSisCalificacion *ObtenCalificacion();
	CQSisClase *ObtenClase();
	CQSisNivel *ObtenNivel();
	CQSisGrupo *ObtenGrupo();
	CQSisEntrenador *ObtenEntrenador();
	const char *ObtenFechaRegistro();
	int operator==(CQSisCompitiendo *);
	int operator==(CQSisAparato *);
private:
	CQSisCompetencia *CQSCompetencia;
	CQSisEntrenador *CQSGimnasta;
	CQSisGimnasio *CQSGimnasio;
	CQSisClase *CQSClase;
	CQSisNivel *CQSNivel;
	CQSisGrupo *CQSGrupo;
	CQSisEntrenador *CQSEntrenador;
	const char *chrPtrFechaReg;
	CQSisCalificacion *CQSCalificacion;

private:
#ifdef __SISCOMINFORMACION2__
	void SiscomFormaRegistro();
	void SiscomAnexaRegistro();
	void ColocaInformacion();
#endif

};
class CQSisLstCompitiendo:public QPtrList<CQSisCompitiendo>
{
public:
	CQSisLstCompitiendo();
	CQSisLstCompitiendo &operator<<(CQSisCompitiendo *);
};
class CQSisOpCompitiendo:public SiscomOperaciones
{
public:
	CQSisOpCompitiendo(SiscomDatCom *);
	void RegistraGimnasta(CQSisCompitiendo *,SiscomRegistrosPro2 **);
	void ActDatCompGimnasta(CQSisCompitiendo *,SiscomRegistrosPro2 **);
private:
	CQSisLstCompitiendo CQSLCompitiendo;
};
#endif

