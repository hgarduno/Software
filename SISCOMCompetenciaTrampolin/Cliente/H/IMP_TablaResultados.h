
#ifndef __IMP_TABLARESULTADOS_H__
#define __IMP_TABLARESULTADOS_H__
#include <UIC_H_TablaResultados.h>
#include <CQSisCGimnastas.h>
#include <CQSisAparatoCompetencia.h>
#include <IMP_CalificaGimnasta.h>
class SiscomDatCom;
class CQSisAparato;
class CQSisCompitiendo;
class QTable;
class QTablaResultados:public TablaResultados
{
 Q_OBJECT
public:
	QTablaResultados(SiscomDatCom *,
	    char **,
	    QWidget *pQWParent=0,
	    const char *pchrPtrName=0,
	    WFlags pWFlags=0);
	~QTablaResultados();
private:
	SiscomDatCom *SisDatCom;
	char **chrPtrArgumentos;
	CQSisLstLstCompitiendo CQSLLCompitiendoAparatos;
	CQSisLstLstCompitiendo CQSLLClasificacionAparatos;
	CQSisLstLstCompitiendo CQSLLCompetenciaGeneral;
	CQSisCompetencia *CQSCompetencia;
	CQSisLstAparatoCompetencia CQSLACompetencia;
private:
	void ConectaSlots();
	void IniciaVariables();
	void Consultando();
	void Consulta();
	void Muestra();
	void Muestra01();
	void ConsultaAparatosCompetencia();
	void keyPressEvent(QKeyEvent *);
	void MuestraInformacion(CQSisLstLstCompitiendo *,QTable *);
	void ConsultandoClasificacionAparatos();
	void ConsultaClasificacionAparatos();
	void MuestraClasificacionAparatos(CQSisLstLstCompitiendo *,QTable *);
	void ConsultandoCompetenciaGeneral();
	void ConsultaCompetenciaGeneral();
	void MuestraCompetenciaGeneral(CQSisLstLstCompitiendo *,QTable *);

	void GimnasioCompetidor(CQSisCompitiendo *,QString &);
private slots:
	void SlotCapturaCalificacion(int,int,int,const QPoint &);
};
class CQTableItemCalificacion:public QTableItem
{
public:
	CQTableItemCalificacion(
				CQSisCompitiendo *,
				CQSisAparato *,
				QTable *,
				const QColor &, 
				EditType );
	void Juez(QCalificaGimnasta::Juez);
	void paint(QPainter *,const QColorGroup &,const QRect &,bool );
	CQSisAparato *Aparato();
	CQSisCompitiendo *Compitiendo();
private:
	const QColor QCColor;
	QCalificaGimnasta::Juez QCGJuez;
	CQSisCompitiendo *CQSCompitiendo;
	CQSisAparato *CQSAparato;
};
extern "C" QTablaResultados *InstanciaTablaResultados(void *,char **,void *,const char *,int);
#endif
