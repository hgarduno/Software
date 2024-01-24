#ifndef __CQSISCGIMNASTAS_H__
#define __CQSISCGIMNASTAS_H__
#include <SISCOMComunicaciones++.h>
#include <CQSisCompitiendo.h>
class CQSisCompitiendo;
class CQSisCompetencia;
class CQSisCalificacion;
class CQSisAparatoCompetencia;
class CQSisLstLstRonda;
class CQSisLstClase;
class CQSisLstGrupo;

class CQSisGmnCompitiendo:public SiscomInformacion
{
public:
	CQSisGmnCompitiendo(CQSisCompitiendo *);
	CQSisCompitiendo *ObtenCompitiendo();
private:
	CQSisCompitiendo *CQSCompitiendo;

};

class CQSisLstGmnCompitiendo:public QPtrList<CQSisGmnCompitiendo>
{
public:
	CQSisLstGmnCompitiendo();
	CQSisLstGmnCompitiendo &operator<<(CQSisGmnCompitiendo *);

};
class CQSisClaseNivel
{
public:
	CQSisClaseNivel(CQSisClase *,CQSisNivel *);
	CQSisClase *Clase();
	CQSisNivel *Nivel();
	int operator==(CQSisClaseNivel *);
	int operator==(const char *);
private:
	CQSisClase *CQSClase;
	CQSisNivel *CQSNivel;
};
class CQSisLstClaseNivel:public QPtrList<CQSisClaseNivel>
{
public:
	CQSisLstClaseNivel();
	CQSisLstClaseNivel &operator<<(CQSisClaseNivel *);
	int operator[](CQSisClaseNivel *);
	CQSisLstClaseNivel *operator[](const char *);
private:
	CQSisClase *CQSClase;
};
class CQSisLstLstCompitiendo:public QPtrList<CQSisLstCompitiendo>
{
public:
	CQSisLstLstCompitiendo();
	CQSisLstLstCompitiendo &operator<<(CQSisLstCompitiendo *);
	void Clases(CQSisLstClase *);
	void Niveles(CQSisClase *,CQSisLstClaseNivel *);
	void Grupos(CQSisClaseNivel *,CQSisLstGrupo *);

	void Gimnastas(CQSisClaseNivel *,CQSisGrupo *,CQSisLstLstCompitiendo *);
	void Gimnastas(CQSisClaseNivel *,
		       CQSisGrupo *,
		       CQSisAparatoCompetencia *,
		       CQSisLstCompitiendo *);
	void Gimnastas(CQSisClaseNivel *,
		       CQSisGrupo *,
		       CQSisAparatoCompetencia *,
		       CQSisLstLstCompitiendo *);

};
class CQSisOpGmnCompitiendo:public SiscomOperaciones
{
public:
	CQSisOpGmnCompitiendo(SiscomDatCom *);
	void ObtenClasificacionGmn(CQSisCompetencia *,
				   CQSisAparatoCompetencia  *,
				   CQSisLstLstCompitiendo *);
	void ObtenCompetenciaGeneral(CQSisCompetencia *,
				   CQSisLstLstCompitiendo *);
	void ObtenResultadosPorAparato(CQSisCompetencia *,
				   CQSisLstLstCompitiendo *);
	void TablaResultados(CQSisCompetencia *,
				   CQSisLstLstCompitiendo *);
	void CalificaRonda(CQSisCompetencia *,
			    CQSisLstLstRonda *);
private:
	SiscomParametrosConsulta SPConsulta;
private:
	void FormaClasificacion(SiscomRegistrosPro2 *,
				CQSisLstLstCompitiendo *);
	int EsFinClaseNivel(SiscomRegistrosPro2 *);
	int EsFinGimnastaAparato(SiscomRegistrosPro2 *);
	int EsFinDeLaRonda(SiscomRegistrosPro2 *);
	void FormaRondas(SiscomRegistrosPro2 *,CQSisLstLstRonda *);
};
#endif
