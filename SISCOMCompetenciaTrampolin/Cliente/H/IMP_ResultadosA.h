
#ifndef __IMP_RESULTADOSA_H__
#define __IMP_RESULTADOSA_H__
#include <UIC_H_ResultadosA.h>
#include <CQSisCGimnastas.h>
#include <CQSisClase.h>
#include <CQSisGrupo.h>
class SiscomDatCom;
class CQSisCompetencia;
class CQSisClase;
class CQSisNivel;
class CQSisGrupo;
class CQSisClaseNivel;
class CQSisAparatoCompetencia;
class CQSisLstClaseNivel;

class QResultadosA:public ResultadosA
{
 Q_OBJECT
public:
	QResultadosA(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QResultadosA();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisCompetencia *CQSCompetencia;
	CQSisLstLstCompitiendo CQSLLCompitiendo;
	CQSisLstLstCompitiendo CQSLLCompitiendoAparatos;
	CQSisLstClase CQSLClasesCompetencia;
	CQSisLstClaseNivel CQSLCNivel;
	CQSisLstGrupo CQSLGrupo;
	CQSisClaseNivel *CQSCNivel;
	CQSisClase *CQSClase;
	CQSisGrupo *CQSGrupo;
	CQSisAparatoCompetencia *CQSACompetencia;

private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaNivelesClase();
	void ConsultaGrupos();
	void ConsultaResultadosAparato();
	void ConsultaResultados();
	void ClasesCompetencia();
	void NivelesClase();
	void EliminaTabWidget();
	void MuestraResultados(CQSisLstCompitiendo *);
	void MuestraAparatosCompetencia();

	void ResultadosAparato(CQSisAparatoCompetencia *);
	
private slots:
	void SlotClase(QListBoxItem *);
	void SlotNivel(QListBoxItem *);
	void SlotGrupo(QListBoxItem *);
	void SlotAparatoCompetencia(CQSisAparatoCompetencia *);
};
extern "C" QResultadosA *InstanciaResultadosA(void *,char **,void *,const char *,int);
#endif
