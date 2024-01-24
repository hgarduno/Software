
#ifndef __IMP_RESULTADOS_H__
#define __IMP_RESULTADOS_H__
#include <UIC_H_Resultados.h>
#include <CQSisCGimnastas.h>
#include <QResCompetencia.h>
class SiscomDatCom;
class CQSisCompetencia;
class QResultados:public Resultados
{
 Q_OBJECT
public:
	QResultados(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QResultados();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstLstCompitiendo CQSLLCompitiendo;
	CQSisLstLstCompitiendo CQSLLCompitiendoAparatos;
	CQSisCompetencia *CQSCompetencia;
	QResCompetenciaLst QRCompetenciaL;	
	QResCompetenciaLst QRCompetenciaLAparatos;	
private:
	void ConectaSlots();
	void IniciaVariables();
	void ConsultaResultados();
	void MuestraResultados();
	void ConsultaResultadosAparato();
	void MuestraResultadosAparato();
	
	void LimpiaTabWidget();
	void LimpiaTabWidgetAparatos();
	void LimpiaControles();
	void ResultadosAparatos(FILE *);

private slots:
	void SlotCompetencia(CQSisCompetencia *);
	void SlotGrupo(QIconViewItem *);
	void SlotGrupoAparato(QIconViewItem *);
	void SlotArchivoImpresion();
};
extern "C" QResultados *InstanciaResultados(void *,char **,void *,const char *,int);
#endif
